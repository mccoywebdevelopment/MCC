
#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
bool timeToShutOffEngines(double velocity,double finalHeight,
                          double currentHeight,double percent);
double absForAddition(double val_1,double val_2);
double absForDifference(double val_1,double val_2);
bool print(double mass,double acceleration,double burnRate,double velocity,
           double height,int i,bool &print1,bool &Return);
double getForce(double mass,double acceleration);
void calculateBurnRate(double mass,double &force,double &acceleration,
                       double &burnRate);
double calculateChangeInMass(double burnRate,double priorMass,double time);
double calculateChangeInVel(double acceleration,double deltaTime);
double calculateTimeDesignatedAlt(double initialHeight,double finalHeight,
                                  double initialVel,double finalVel,
                                  double acceleration);
double calculateChangeInHeight(double initialHeight,double initialVel,
                       double acceleration,double deltaTime);
void engineCutOff(double &velocity,double &height,double deltaT);
void burnEngines(double &height,double &velocity,double &acceleration,
                 double deltaT,double &mass,double &burnRate,double &force);
void calculateHoverGoal(double current_height,double lower_height,
                      double higher_hight,double &hoverCount,
                      int desiredTime,bool &countAchieved,double deltaT);
void phaseI(double &height,double &mass,double &acceleration,double &burnRate,
            double &force,double &deltaT,double &velocity,double &desiredHeight,
            double percent,
            bool &completed);
void phaseII(double &height,double &mass,double &acceleration,double &burnRate,
            double &force,double &deltaT,double &velocity,double &desiredHeight,
            double percent,double hoverRange,int hoverGoalCount,
            bool &completed,double &timeHovered,double orgAcc,
            bool completedPhaseI);
void phaseIII(double &height,double &mass,double &acceleration,double &burnRate,
            double &force,double &deltaT,double &velocity,double &desiredHeight,
            double percent,double hoverRange,int hoverGoalCount,
            double &timeHovered,double orgAcc,bool &completedPhaseIII,bool &start);
void calculations(double &mass,double &acceleration,double desiredHeight,double
                  &timeHovered,bool &rocketReturned);
bool timeToTurnOnEngines(double velocity,double finalHeight,double
                          currentHeight,double percent,double currentTime,double acceleration);

//fix calc burnrate
const double gravity=10.0;
const double velNozzle=2000.0;
const double initial_fuel_weight=1000.0;
const double max_acceleration =100.0;
const int min_launch_time=20;//2.0 seconds
const double max_landing_speed =-3.0;
const double delta_t=0.1;
const double max_landing_velocity=-3.0;
const double nozzle_velocity=2000.0;
const double hover_count_goal=50;

//Desired Height: 1466
//ID: 90 Acceleration: 100 Mass:759.048Height: 1512.5
int main()
{

    double burnRate,velocity,force,acceleration,mass;
    acceleration=20;
    mass=2000;
    double timeElapse,excTime,height,deltaT,hoverRange,orgAcc;
    int hoverGoalCount=5;
    int maxLoopCount=10000;
    double desiredHeight=1500;
    double timeHovered=0;
    orgAcc=acceleration;
    hoverRange=5;
    velocity=0;
    height=0;

    bool completedPhaseI=false;
    bool completedPhaseII=false;
    bool completedPhaseIII=false;
    bool print1=false;
    bool Return=false;
    bool start=false;
    deltaT=0.1;
    double percent=1.1;
    double time=0;
    for(int i=0;i<=maxLoopCount;++i)
    {
        if(height<0 && completedPhaseIII)
        {
            i=maxLoopCount;
        }
        else
        {
            if(height>=desiredHeight && height<=(desiredHeight+hoverRange))
        {
            timeHovered=timeHovered+0.1;
        }
        if(height<0 || Return==true){i=maxLoopCount;}

        phaseI(height,mass,acceleration,burnRate,force,deltaT,velocity,
               desiredHeight,percent,
               completedPhaseI);

        if(completedPhaseI==true && height<desiredHeight &&
           completedPhaseII==false)
        {
            phaseII(height,mass,acceleration,burnRate,force,deltaT,velocity,
                    desiredHeight,percent,hoverRange,hoverGoalCount,
                    completedPhaseII,timeHovered,orgAcc,completedPhaseI);
        }
        if(completedPhaseII)
        {
            phaseIII(height,mass,acceleration,burnRate,force,deltaT,velocity,
                     desiredHeight,percent,hoverRange,hoverGoalCount,
                     timeHovered,orgAcc,completedPhaseIII,start);

        }
        print(mass,acceleration,burnRate,velocity,height,i,print1,Return);
        }
    }
    cout<<"time: "<<timeHovered<<endl;
    if(completedPhaseIII)
    {
        cout<<"You landed!"<<endl;
    }
    else
    {
        cout<<"You crashed."<<endl;
    }
    //cout<<"End of program."<<endl;
    cout<<"Press anything to continue."<<endl;
    cin>>mass;
}
void phaseIII(double &height,double &mass,double &acceleration,double &burnRate,
            double &force,double &deltaT,double &velocity,double &desiredHeight,
            double percent,double hoverRange,int hoverGoalCount,
            double &timeHovered,double orgAcc,bool &completedPhaseIII,bool &start)
{
        double time=0;
        if(height<=0 && velocity>-3 && velocity<3)
        {
            completedPhaseIII=true;
        }
        if(timeToTurnOnEngines(velocity,0,height,10,time,acceleration)==true /*|| start==true*/)
        {
            acceleration=orgAcc;
            burnEngines(height,velocity,acceleration,deltaT,mass,burnRate,force);
            //start=true;
        }
        else if(start==false)
        {
            engineCutOff(velocity,height,deltaT);
            acceleration=-10;
        }
        time=time+0.1;
}

void phaseII(double &height,double &mass,double &acceleration,double &burnRate,
            double &force,double &deltaT,double &velocity,double &desiredHeight,
            double percent,double hoverRange,int hoverGoalCount,
            bool &completed,double &timeHovered,double orgAcc,bool completedPhaseI)
{
        if(timeHovered>=hoverGoalCount)
        {
            completed=true;
        }
        acceleration=orgAcc;
        percent=3;
        phaseI(height,mass,acceleration,burnRate,force,deltaT,velocity,
               desiredHeight,percent
           ,completedPhaseI);
}

void phaseI(double &height,double &mass,double &acceleration,double &burnRate,
            double &force,double &deltaT,double &velocity,double &desiredHeight,
            double percent,
            bool &completed)
{
    if(height>0 && velocity<=0 || height>=desiredHeight)
    {
        completed=true;
    }
    if(timeToShutOffEngines(velocity,desiredHeight,height,percent) ||
       height>=desiredHeight)
    {
        engineCutOff(velocity,height,deltaT);
        acceleration=-10;

    }
    else{
        burnEngines(height,velocity,acceleration,deltaT,mass,burnRate,force);
    }
}
double getForce(double mass,double acceleration)
{
    double force;
    force=mass*acceleration;
    return force;
}
void calculateBurnRate(double mass,double &force,double &acceleration,
                       double &burnRate)
{
   force=getForce(mass,acceleration);
   burnRate=force/velNozzle;
}
double calculateChangeInMass(double burnRate,double priorMass,double time)
{
    double newMass,burnedMass;
    burnedMass=burnRate*time;
    newMass=-1*burnedMass;
    return newMass;

}
double calculateChangeInVel(double acceleration,double deltaTime)
{
    double velocity;
    velocity=acceleration*deltaTime;
    return velocity;
}
double calculateChangeInHeight(double initialHeight,double initialVel,
                       double acceleration,double deltaTime)
{
    double finalHeight;
    finalHeight=(initialVel*deltaTime)+
    (.5*acceleration*pow(deltaTime,2));
    return finalHeight;
}
void engineCutOff(double &velocity,double &height,double deltaT)
{
    double acceleration;
    acceleration=-10;
    height=height+calculateChangeInHeight(height,velocity,acceleration,deltaT);
    velocity=velocity+calculateChangeInVel(acceleration,deltaT);

}
void burnEngines(double &height,double &velocity,double &acceleration,double
                 deltaT,double &mass,double &burnRate,double &force)
{
        height=height+calculateChangeInHeight(height,velocity,acceleration,
                                              deltaT);
        calculateBurnRate(mass,force,acceleration,burnRate);
        mass=mass+calculateChangeInMass(burnRate,mass,deltaT);
        velocity=velocity+calculateChangeInVel(acceleration,deltaT);
}
bool print(double mass,double acceleration,double burnRate,double velocity,
           double height,int i,bool &print1,bool &Return)
{
    char cont;
    Return=false;
    printf("time:%5.1f sec        mass:%5.2f kg       "
                 "acceleration: %5.2f m/s^2       burn rate: %5.2f kg/sec     "
                 "velocity: %5.2f m/s     height: %5.2f m",(i*.1),mass,
                 acceleration,burnRate,velocity,height);
    if(velocity<0 && print1!=true)
    {
        cout<<"********************";
        cout<<"Do you want to continue (Y/N)? ";
        cin>>cont;
        if(cont=='n')
        {
            Return=true;
        }
        print1=true;
    }
        cout<<"\n";
}
bool timeToShutOffEngines(double velocity,double finalHeight,double
                          currentHeight,double percent)
{
    //1/2*v^2=g(hf-hi_
    double wantedVel,percentDifference;
    wantedVel=sqrt(2*10*(finalHeight-currentHeight));
    percentDifference=
    absForDifference(velocity,wantedVel)/absForAddition(velocity,wantedVel);
    percentDifference=percentDifference*100;
    if(percentDifference<=percent)
    {
        return true;
    }
    return false;

}
bool timeToTurnOnEngines(double velocity,double finalHeight,double
                          currentHeight,double percent,double currentTime,double acceleration)
{
    double changeInHeight,percentDifference;
    changeInHeight=absForDifference(0,currentHeight);
    double wantedVel;

    wantedVel=sqrt(2*10*changeInHeight);
    wantedVel=wantedVel*-1;

    percentDifference=
    absForDifference(velocity,wantedVel)/absForAddition(velocity,wantedVel);
    percentDifference=percentDifference*100;

    if(percentDifference<=percent /*&& velocity<0*/)
    {
        return true;
    }
    return false;


}

double absForDifference(double val_1,double val_2)
{
    double result;
    result=val_1-val_2;
    if(result<0)
    {
        result=result*-1;
    }
    return result;
}
double absForAddition(double val_1,double val_2)
{
    double result;
    result=val_1+val_2;
    if(result<0)
    {
        result=result*-1;
    }
    return result;
}
void calculateHoverGoal(double current_height,double lower_height,
                      double higher_hight,double &hoverCount,
                      int desiredTime,bool &countAchieved,double deltaT)
{
    if(current_height<higher_hight && current_height>lower_height)
    {
        hoverCount=hoverCount+deltaT;
    }
    if(hoverCount>=desiredTime)
    {
        countAchieved=true;
    }
    else{
        countAchieved=false;
    }
}





