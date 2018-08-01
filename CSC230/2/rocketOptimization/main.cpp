
#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
bool timeToShutOffEngines(double velocity,double finalHeight,double currentHeight,double percent);
double absForAddition(double val_1,double val_2);
double absForDifference(double val_1,double val_2);
bool print(double mass,double acceleration,double burnRate,double velocity,
           double height,int i,bool print1);
void getForce(double mass,double &force,double &acceleration);
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
void reset(double &acceleration,double &mass,double &velocity,
           double &height,int &i);

class object
{
    public:
        int _id;
        double _score;
        double _mass;
        double _velocity;
        double _height;
        double _acceleration;
        double _percent;
    object()
    {
        _id=0;
        _percent=0;
        _mass=0;
        _acceleration=0;
        _score=0;
        _velocity=0;
        _height=0;
    }
    void upDate(int id,double score,double mass,double velocity,double height,double
           acceleration,double percent)
    {
        _id=id;
        _mass=mass;
        _score=score;
        _velocity=velocity;
        _height=height;
        _acceleration=acceleration;
        _percent=percent;
    }
    int getId()
    {
        return _id;
    }
    double getScore()
    {
        return _score;
    }
    double getMass()
    {
        return _mass;
    }
    double getVelocity()
    {
        return _velocity;
    }
    double getHeight()
    {
        return _height;
    }
    double getAcceleration()
    {
        return _acceleration;
    }
    double getPercent()
    {
        return _percent;
    }
};

double gravity=10;
int main()
{
    double burnRate,mass,acceleration,velocity,desiredHeight,force,
    height,deltaT;
    desiredHeight=500;
    for(int ix=500;ix<=1500;++ix)
    {

        int time;
        acceleration=10;
        velocity=0;
        height=0;
        mass=1000;

        object test[100];
        //test[0].upDate(1,2,3,4,5,6,7);
        double orgPercent,percent;
        orgPercent=0.1;
        percent=orgPercent;

        int id;
        id=1;
        int i=0;
        for(int i=0;i<=2000000;++i)
        {
            if(acceleration>100)
            {
                i=2000000;
            }

            if(i==0)
            {
                deltaT=0;
            }
            else{
                deltaT=0.1;
            }

            if(timeToShutOffEngines(velocity,desiredHeight,height,percent))
            {
                test[id].upDate(id,1,mass,velocity,height,acceleration,percent);
                id++;
                reset(acceleration,mass,velocity,height,i);
                percent=orgPercent;
            }
            else if(height>desiredHeight+10)
            {

                percent=percent+1;
                if(percent>10)
                {
                    //test[id].upDate(id,-1,mass,velocity,height,acceleration,percent);
                    //id++;
                    percent=orgPercent;
                }
                test[id].upDate(id,-1,mass,velocity,height,acceleration,percent);
                id++;
                reset(acceleration,mass,velocity,height,i);
            }
            burnEngines(height,velocity,acceleration,deltaT,mass,burnRate,force);
        }
        object smallestMass;
        smallestMass.upDate(test[1].getId(),test[1].getScore(),test[1].getMass(),
                            test[1].getVelocity(),test[1].getHeight(),
                            test[1].getAcceleration(),test[1].getPercent());
        for(i=1;i<=id;++i)
        {

            if(test[i].getMass()<smallestMass.getMass() && test[i].getId()!=0)
            {
                smallestMass.upDate(test[i].getId(),test[i].getScore(),test[i].getMass(),
                    test[i].getVelocity(),test[i].getHeight(),
                    test[i].getAcceleration(),test[i].getPercent());
            }
        }
        cout<<"Desired Height: "<<desiredHeight<<endl;
        cout<<" ID: "<<smallestMass.getId()<<" Acceleration: "<<
        smallestMass.getAcceleration()<<" Mass: "<<smallestMass.getMass()<<
        " Height: "<<smallestMass.getHeight()<<" Percent: "<<smallestMass.getPercent()<<endl;
        desiredHeight++;
    }
    cout<<"End of program."<<endl;
    return 0;
}
void reset(double &acceleration,double &mass,double &velocity,
           double &height,int &i)
{
    i=0;
    velocity=0;
    height=0;
    mass=1000;
    acceleration++;
}
void getForce(double mass,double &force,double &acceleration)
{

    force=mass*acceleration;
}
void calculateBurnRate(double mass,double &force,double &acceleration,
                       double &burnRate)//need to calculate a new burnRate when acceleration is less than 10.
{
   getForce(mass,force,acceleration);
   burnRate=force/2000;
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
double calculateTimeDesignatedAlt(double initialHeight,double finalHeight,
                                  double initialVel,double finalVel,
                                  double acceleration)
{
    double time;
    time=sqrt((finalHeight-initialHeight)/(.5*acceleration));
    return time;

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
        height=height+calculateChangeInHeight(height,velocity,acceleration,deltaT);
        calculateBurnRate(mass,force,acceleration,burnRate);
        mass=mass+calculateChangeInMass(burnRate,mass,deltaT);
        velocity=velocity+calculateChangeInVel(acceleration,deltaT);
}
bool timeToShutOffEngines(double velocity,double finalHeight,double currentHeight,double percent)
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





