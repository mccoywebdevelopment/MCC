#include <iostream>
#include <math.h>
#include <time.h>
#include <stdlib.h>
using namespace std;
//line 92 fix use do while also for Warrior moves.

//Engineer
void get_coordinatesXY(double& Xone,double& Yone);
double computeDistance(double Xone,double Xtwo,double Yone,double Ytwo);
double computeHorizontalAngle(double x1,double x2,double y1, double y2);
double Compute_Distance_object_traveled(double velocity,double elevation);
void compute_Destination(double Distance, double x1, double y1,
    double HorizontalAngle,double &DestionationX,double &DestionationY);

//Service Rep
void get_coordinatesXY(double& Xone,double& Yone);
void DisplayMenu(void);
void Distance_Between_2Pt (void);
void Horizontal_Angle (void);
void Distance_Traveled (void);
void Destination_of_object (void);
void Basic_Calculations(void);
void Target_Practice(void);
void Hunt_The_Wumpus(void);

//Extra Subprograms
double VelocityInput();
void gameMenu(void);
void Wumpus_Rules(void);
void Grenade_Throw(double WarriorX, double WarriorY,
                   double WumpusX,double WumpusY);
void WarriorsMove(int WarriorX,int WarriorY,int &WarriorXout,int &WarriorYout);
void WumpusRandomMove(int WumpusX,int WumpusY,int &WumpusXout,int &WumpusYout);
void ifstatemenet_WumpusGame(int WarriorX,int WarriorY,int WumpusX,int WumpusY,
                             int Botomless_PitX,int Botomless_PitY,
                             int batteryNum,int game,int BatteryX,int BatteryY,
                             int &game_out,int &batteryNum_out);

int main()
{
    int Menu;
    cout<<"Welcome to the ultimate game arcade we have a variety"<<endl;
    cout<<" of games!"<<endl<<"Each game has a different objective";
    cout<<" hope you have fun!"<<endl;
    do
    {
        gameMenu();
        cin>>Menu;
        cout<<endl;
        if(Menu==1)
        {
            Basic_Calculations();
        }
        else if(Menu==2)
        {
            Target_Practice();
        }
        else if(Menu==3)
        {
            Hunt_The_Wumpus();
        }
        else if(Menu==5)
        {
            cout<<"GoodBye."<<endl;

        }
        else
        {
            cout<<"Please enter 1-5"<<endl;
        }
    }while(!(Menu==5));
}
void gameMenu(void)
{
    cout<<endl;
    cout<<"Choose one from the following options..."<<endl;
    cout<<"(1) Basic Calculations"<<endl;
    cout<<"(2) Target Practice"<<endl;
    cout<<"(3) Hunt the Wumpus"<<endl;
    cout<<"(4) Your game"<<endl;
    cout<<"(5) Exit the program";
}
void Basic_Calculations(void)
{
    int Menu;

    cout<<"This program is designed to do the following options"<<endl;
    cout<<" find the distance between two pts, find the horizontal"<<endl;
    cout<<" angle between two pts,find the distance the object"<<endl;
    cout<<" travels,and find the destination pt the object traveled."<<endl;



    do
    {
        DisplayMenu();
        cin>>Menu;

        if(Menu==1)
        {
            Distance_Between_2Pt();
        }
        else if(Menu==2)
        {
            Horizontal_Angle();
        }
        else if(Menu==3)
        {
            Distance_Traveled();
        }
        else if (Menu==4)
        {
            Destination_of_object();
        }
        else if(Menu==5)
        {
            cout<<"GoodBye."<<endl;

        }
        else
        {
            cout<<"Please enter 1-5"<<endl;
        }
    }
    while(Menu!=5);





}
void Target_Practice(void)
{
    char game;
    int skill,radius,num,won;
    double mortarX,mortarY,targetX,targetY,Horizontal,velocity,Angle,
        DestX,DestY,elevation,mortarEndX,mortarEndY,distance,MortarDist;

    mortarX=2500;
    mortarY=0;
    srand(time(NULL));
    targetX=rand()%5000;
    targetY=rand()%5000;
    num=0;
    won=0;

    do
    {
    cout<<"Select the difficulty you want to play with."<<endl;
    cout<<"Easy(1) Medium(2) Hard(3)";
    do
    {
        cin>>skill;
        if (skill==1)
        {
            radius=100;
        }
        else if(skill==2)
        {
            radius=25;
        }
        else if(skill==3)
        {
        radius=5;
        }
        else
        {
            cout<<"Please select (1,2,3)."<<endl;
        }
    }while(!(skill==1 || skill==2 || skill==3));

    cout<<endl;

    cout<<"It's mortar shooting time!"<<endl;
    cout<<"Target's coordinates ("<<targetX<<","<<targetY<<")"<<endl;
    cout<<endl<<endl;

    cout<<"Enter the horizontal angle of the barrel(degrees)";
    cin>>Horizontal;

        do
        {
            if(Horizontal>180 || Horizontal<0)
            {
                cout<<"Please enter a number between 0 to 180 degrees.";
                cin>>Horizontal;
            }
        }
        while(Horizontal>180 || Horizontal<0);

        cout<<endl;
        cout<<"Enter the elevation angle of the barrel(degrees).";
        cin>>elevation;

        do
        {
            if(elevation>=90 || elevation<=0)
            {
                cout<<"Please enter a number between 0 to 90 degrees.";
                cin>>elevation;
            }
        }
        while(elevation>=90 || elevation<=0);

        cout<<endl;

        velocity=VelocityInput();
        distance=Compute_Distance_object_traveled(velocity,elevation);
        compute_Destination(distance,mortarX,mortarY,Horizontal,mortarEndX
                        ,mortarEndY);

        cout<<endl;
        cout<<"The mortar landed at ("<<mortarEndX<<","<<mortarEndY<<")"<<endl;
        cout<<endl;

        MortarDist=computeDistance(targetX,mortarEndX,targetY,mortarEndY);


        if (MortarDist <= radius)
        {
            cout<<"BOOM!"<<endl;
            won=won+1;
        }
        else
        {
            Angle=computeHorizontalAngle(targetX,mortarEndX,targetY,mortarEndY); //CHECK THIS!!!

            cout<<"Target:"<<"("<<targetX<<","<<targetY<<")"<<endl<<endl;
            cout<<"     You missed it by this much..."<<endl;
            cout<<"     Distance:"<<MortarDist<<endl;
            cout<<"     Angle:"<<Angle<<endl;
        }

        num=num+1;

        cout<<endl<<"Do you want to blast some more?(y/n)";

        do
        {
            cin>>game;
            cout<<endl;
            if(!(game=='y'||game=='n'))
            {
                cout<<"Please enter (y/n)";//FIX THIS!!!!!
            }
        }
        while(!(game=='y'||game=='n'));

    }
    while(game=='y');

    cout<<endl<<"Games played:"<<num<<endl;
    cout<<"Games won:"<<won<<endl<<endl;
}

void Hunt_The_Wumpus(void)
{
    int WarriorX,WarriorY,WumpusX,WumpusY,Botomless_PitX,Botomless_PitY,
    BatteryX,BatteryY,batteryNum,dist_Warrior_WumpusX, dist_Warrior_WumpusY,
    dist_Warrior_PitX,dist_Warrior_PitY,game,action,room,Angle,again;
do
{

    batteryNum=3; //start of the game
    game=0;

    Wumpus_Rules();

    srand(time(NULL));         //100 limit & 0 for both x&y values
    WarriorX=rand()%9;
    WarriorY=rand()%9;
    WarriorX=(WarriorX*10)+5;
    WarriorY=(WarriorY*10)+5;

    WumpusX=rand()%9;
    WumpusY=rand()%9;
    WumpusX=(WumpusX*10)+5;
    WumpusY=(WumpusY*10)+5;

    Botomless_PitX=rand()%9;
    Botomless_PitY=rand()%9;
    Botomless_PitX=(Botomless_PitX*10)+5;
    Botomless_PitY=(Botomless_PitY*10)+5;

    BatteryX=rand()%9;
    BatteryY=rand()%9;
    BatteryX=(BatteryX*10)+5;
    BatteryY=(BatteryY*10)+5;



        do
        {
        cout<<endl;
        cout<<endl;
        cout<<"Warrior's Location: ("<<WarriorX<<","<<WarriorY<<")"<<endl;
        cout<<endl;

        ifstatemenet_WumpusGame(WarriorX,WarriorY,WumpusX,WumpusY,Botomless_PitX
                                ,Botomless_PitY,batteryNum,game,BatteryX,
                                BatteryY,game,batteryNum);


//Check batteryNum & game
        WumpusRandomMove(WumpusX,WumpusY,WumpusX,WumpusY);
        if(game!=1)
        {
            cout<<endl;
            cout<<"Choose one of the following actions (Press 1-5)"<<endl;
            cout<<"(1)Move to an adjacent room,(2)fire a grenade,(3)use";
            cout<<" the Wumpus Compass,"<<endl<<"(4)do nothing,or(5) quit";
            cout<<" the game"<<endl;
            do
            {
                cin>>action;   //Add user checker!!!

                if (action==1)
                {
                    WarriorsMove(WarriorX,WarriorY,WarriorX,WarriorY);

                }
                else if(action==2)
                {

                    Grenade_Throw(WarriorX,WarriorY,WumpusX,WumpusY);
                }
                else if (action==3)
                {
                    if (batteryNum>0)
                    {
                        Angle=computeHorizontalAngle(WumpusX,WarriorX,
                                               WumpusY,WarriorY);
                        cout<<"The Wumpus is "<<Angle<<"Degrees from me."<<endl;
                        cout<<endl;
                        batteryNum=batteryNum-1;

                    }
                    else
                    {
                        cout<<"The Wumpus compass doesnt work."<<endl;
                    }
                }
                else if (action==4)
                {
                    cout<<"zzzzzz"<<endl;
                }
                else if (action == 5)
                {
                    cout<<"GoodBye."<<endl;
                    game=1;
                }
                else
                {
                    cout<<"Please select 1-5"<<endl;
                }
            }
                while(action==1 && action ==2 && action ==3
                       && action==4 && action==5);
            }
        }while(game!=1);
        do
        {
            cout<<"Do you want to play again?(y/n)"<<endl;
            cin>>again;
            if(again=='y' && again !='n') //fix
            {
                cout<<"Please press y or n"<<endl;
            }
        }while(again!='y' && again !='n');

}while (again == 'y');


}

double computeDistance(double Xone,double Xtwo,double Yone,double Ytwo)
{
    double distance2Pt;

    distance2Pt=sqrt(pow(Xtwo - Xone,2)+pow(Ytwo-Yone,2));
    return distance2Pt;
}

double computeHorizontalAngle(double x1,double x2,double y1, double y2)
{
    double HorizontalAngle,dx,dy,AngleDeg;
    const double pie =3.14159;
    dx=x2-x1;
    dy=y2-y1;

        if(dx>0)
        {
            HorizontalAngle=atan(dy/dx);
        }
        else if(dx<0)
        {
            HorizontalAngle=atan(dy/dx)+pie;
        }
        else if (dx==0 && dy >=0)
        {
            HorizontalAngle=pie/2.0;
        }
        else
        {
            HorizontalAngle=-1*pie/2.0;
        }
  AngleDeg=HorizontalAngle*180.0/pie;
  return AngleDeg;
}
double Compute_Distance_object_traveled(double velocity,double elevation)
{
    const double pie=3.14159;
    const double gravity=32.172;
    const double FtperMile=5280;
    const double SecPerHr=3600;
    double elevAngleRad,velocityFt,Distance;

    elevAngleRad=elevation*pie/180.0;
    velocityFt=velocity*FtperMile/SecPerHr;
    Distance=pow(velocityFt,2)*sin(2*elevAngleRad)/gravity;
    return Distance;

}
void compute_Destination(double Distance, double x1, double y1,
            double HorizontalAngle,double &DestionationX,double &DestionationY)
{
  const double pie=3.14159;
  double HorizontalAngleRad,distanceX,distanceY;
  HorizontalAngleRad=HorizontalAngle*pie/180.0;
  distanceX=Distance*cos(HorizontalAngleRad);
  distanceY=Distance*sin(HorizontalAngleRad);
  DestionationX= x1+distanceX;
  DestionationY= y1+distanceY;
}
void get_coordinatesXY(double& Xone,double& Yone)
{
    cout<<"Enter the x coordinate (in feet).";
    cin>>Xone;

    cout<<"Enter the y coordinate (in feet).";
    cin>>Yone;
}
void DisplayMenu(void)
{
    cout<<endl;
    cout<<"Choose one from the following options..."<<endl;
    cout<<"(1) Compute the distance between two points"<<endl;
    cout<<"(2) Compute the horizontal angle"<<endl;
    cout<<"(3) Compute the Horizontal distance the object travels"<<endl;
    cout<<"(4) Compute the destination the object travels to"<<endl;
    cout<<"(5) Exit the program"<<endl;
}

void Distance_Between_2Pt (void)
{
    double Xone,Yone,Xtwo,Ytwo,Distance;
    cout<<"Welcome to the distance between two points calculator."<<endl;
    get_coordinatesXY(Xone,Yone);

    cout<<endl;
    cout<<"okay now..."<<endl;

    get_coordinatesXY(Xtwo,Ytwo);
    Distance=computeDistance(Xone,Xtwo,Yone,Ytwo);

    cout<<"The distance between these two points is "<<Distance<<"."<<endl;
}
void Horizontal_Angle (void)
{
    double Xone,Yone,Xtwo,Ytwo,Angle;
    cout<<"Welcome to the horizontal angle calculator."<<endl;

        get_coordinatesXY(Xone,Yone);
        cout<<endl;
        cout<<"okay now now enter the details for the second pt."<<endl;
        get_coordinatesXY(Xtwo,Ytwo);
        Angle=computeHorizontalAngle(Xone,Xtwo,Yone,Ytwo);

    cout<<"The horizontal angle is "<<Angle<<endl;
}
void Distance_Traveled (void)
{
    double Xone,Yone,Xtwo,Ytwo,elevation,velocity,distance;
    cout<<"This will compute the horizontal distance the object traveled in"
    " Feet."<<endl;
    velocity=VelocityInput();
    get_coordinatesXY(Xone,Yone);
    cout<<endl;
            do
            {
                cout<<endl<<"What is the elevation angle(in Degrees)?"<<endl;
                cin>>elevation;
                    if(elevation<=0 || elevation>=90)
                    {
                        cout<<"Please enter a number between 0-90."<<endl;
                    }
            }
            while(elevation<=0 || elevation>=90);

    distance=Compute_Distance_object_traveled(velocity,elevation);
    cout<<"The horizontal distance is "<<distance<<"."<<endl;



}
void Destination_of_object (void)
{
    double Distance,Xone,Yone,DestX,DestY,elevation;
    cout<<"Welcome to destination calculator"<<endl;
    cout<<"What is the distance traveled (in feet)?"<<endl;
        do
        {
            cin>>Distance;

            if(Distance<0)
            {
                cout<<"Distance must be greater than zero."<<endl;
            }
        }
        while(Distance<0);

    get_coordinatesXY(Xone,Yone);
        do
        {
            cout<<endl<<"What is the angle of elevation?(degrees)"<<endl;
            cin>>elevation;
            if(elevation<=0 || elevation>=90)
            {
                cout<<"Please enter a number between 0-90 degrees."<<endl;
            }
        }
        while(elevation<=0 || elevation>=90);

    compute_Destination(Distance,Xone,Yone,elevation,DestX,DestY);
    cout<<"The destination is ("<<DestX<<","<<DestY<<")"<<endl;

}
double VelocityInput()
{
    double velocity;
do
{
    cout<<"Please enter the velocity.(miles per hour).";
    cin>>velocity;
    if (velocity<0)
    {
        cout<<"Please enter a positive velocity."<<endl;
    }
}
while(velocity<0);
return velocity;
}

void Wumpus_Rules(void)
{
    cout<<"Welcome to the game Hunt the Wumpus!"<<endl;
    cout<<"Wumpus is target; a beast that eats "<<endl;
    cout<<"you if you ever end up in the same room."<<endl;
    cout<<"Hunt the Wumpus by using a hand grenade HOORAh!"<<endl;
    cout<<"You have a wumpus compass that tells you what direction"<<endl;
    cout<<"the Wumpus is located. But the compass is limited to"<<endl;
    cout<<"three turns. There is a battery located in one of the rooms"<<endl;
    cout<<"if you enter that room you get three more turns to use the"<<endl;
    cout<<"compass. There are a total 100 rooms (10x10 grid of rooms)"<<endl;
    cout<<"You the Warrior you can only move to "<<endl;
    cout<<"a room that is adjacent to you."<<endl;
    cout<<"Be careful moving around the maze because one room"<<endl;
    cout<<"has a bottomless pit if you enter that room you LOSE"<<endl;
    cout<<"if the wumpus enters the bottomless pit you WIN"<<endl;
    cout<<"HINT: if the you are adjacent to the wumpus the screen"<<endl;
    cout<<"Will say: I smell something funny."<<endl;

}

void ifstatemenet_WumpusGame(int WarriorX,int WarriorY,int WumpusX,int WumpusY,
                             int Botomless_PitX,int Botomless_PitY,
                             int batteryNum,int game,int BatteryX,int BatteryY,
                             int &game_out,int &batteryNum_out)
{
        int dist_Warrior_WumpusX,dist_Warrior_WumpusY,dist_Warrior_PitX,
        dist_Warrior_PitY;

        dist_Warrior_WumpusX=WarriorX-WumpusX;
        dist_Warrior_WumpusY=WarriorY-WumpusY;

        if (dist_Warrior_WumpusX<0)
        {
            dist_Warrior_WumpusX=dist_Warrior_WumpusX*-1;
        }
        if (dist_Warrior_WumpusY<0)
        {
            dist_Warrior_WumpusY=dist_Warrior_WumpusY*-1;
        }

        dist_Warrior_PitX=WarriorX-Botomless_PitX;
        dist_Warrior_PitY=WarriorY-Botomless_PitY;
        if (dist_Warrior_PitX<0)
        {
            dist_Warrior_PitX=dist_Warrior_PitX*-1;
        }
        if(dist_Warrior_PitY<0)
        {
            dist_Warrior_PitY=dist_Warrior_PitY*-1;
        }

        if (WarriorX==Botomless_PitX && WarriorY==Botomless_PitY
        && WumpusX==Botomless_PitX && WumpusY==Botomless_PitY )
        {
            cout<<endl;
            cout<<"You and the Wumpus fell in the bottomless pit at the same";
            cout<<endl<<"time"<<endl<<" it's a DRAW!"<<endl;
            game_out=1;
        }
        else if(WarriorX==WumpusX && WarriorY==WumpusY)
        {
            cout<<endl;
            cout<<"The Wumpus ate you!"<<endl;
            cout<<"     GAME OVER."<<endl;
            game_out=1;
        }
         else if (WarriorX==Botomless_PitX && WarriorY==Botomless_PitY)
        {
            cout<<endl;
            cout<<"You fell in the bottomless pit."<<endl;
            cout<<"     GAME OVER."<<endl;
            game_out=1;
        }
        else if (WumpusX==Botomless_PitX && WumpusY==Botomless_PitY)
        {
            cout<<endl;
            cout<<"The Wumpus fell in the bottomless pit.";
            cout<<"     You WON!"<<endl;
            game_out=1;
        }
        else
        {
            if (WarriorX==BatteryX && WarriorY==BatteryY)
            {
                cout<<endl;
                cout<<"You found the battery pack for the compass!"<<endl;
                cout<<"You get three added turns to use the compass."<<endl;
                batteryNum_out=batteryNum_out+3;
            }
            if(WarriorX==WumpusX && dist_Warrior_WumpusY<11 || WarriorY==WumpusY
            && dist_Warrior_WumpusX<11)
            {
                cout<<endl;
                cout<<"I smell something funny."<<endl;
            }
            if (WarriorX==Botomless_PitX && dist_Warrior_PitY<11 ||
                WarriorY==Botomless_PitY && dist_Warrior_PitX<11)
            {
                cout<<endl;
                cout<<"I feel a draft."<<endl;
            }
        }
    /*cout<<"Warrior"<<endl;
    cout<<WarriorX<<endl;
    cout<<WarriorY<<endl;
    cout<<"Wumpus"<<endl;
    cout<<WumpusX<<endl;
    cout<<WumpusY<<endl;
    cout<<"Compass bat"<<endl;
    cout<<BatteryX<<endl;
    cout<<BatteryY<<endl;
    cout<<"Bottomless Pit"<<endl;
    cout<<Botomless_PitX<<endl;
    cout<<Botomless_PitY<<endl;
    cout<<"DistanceXWumpusX"<<endl;
    cout<<dist_Warrior_WumpusX<<endl;
    cout<<"DistanceYWumpusY"<<endl;
    cout<<dist_Warrior_WumpusY<<endl;
    cout<<"DistanceXPitX"<<endl;
    cout<<dist_Warrior_PitX<<endl;
    cout<<"DistanceYPitY"<<endl;
    cout<<dist_Warrior_PitY<<endl; */

}
void WumpusRandomMove(int WumpusX,int WumpusY,int &WumpusXout,int &WumpusYout)
{
    do
    {
    int Wumpus_move;
    srand(time(NULL));
    Wumpus_move=rand()%5 + 1;

        if(Wumpus_move==1)
        {
            WumpusYout=WumpusY+10;
        }
        else if(Wumpus_move==2)
        {
            WumpusYout=WumpusY-10;
        }
        else if(Wumpus_move==3)
        {
            WumpusXout=WumpusX+10;
        }
        else if(Wumpus_move==4)
        {
            WumpusXout=WumpusX-10;
        }
        else
        {
            WumpusXout=WumpusX;
            WumpusYout=WumpusY;
        }
    }while(WumpusXout>100 || WumpusYout>100 || WumpusXout<0 || WumpusYout<0);

}
void WarriorsMove(int WarriorX,int WarriorY,int &WarriorXout,int &WarriorYout)
{
    char Warrior_move;
        do
        {
        cout<<"Press (w) to move to the North room,(a) to the West";
        cout<<" room,(d) to the East room,"<<endl<<"(s)to the South";
        cout<<" room."<<endl;
        cin>>Warrior_move;

        if(WarriorXout<0 || WarriorYout<0 || WarriorXout>100 || WarriorYout>100)
        {
            WarriorXout=WarriorX;
            WarriorYout=WarriorY;
        }

        if(Warrior_move=='w')
        {
            WarriorYout=WarriorY+10;
        }
        else if(Warrior_move=='s')
        {
            WarriorYout=WarriorY-10;
        }
        else if(Warrior_move=='d')
        {
            WarriorXout=WarriorX+10;
        }
        else if(Warrior_move=='a')
        {
            WarriorXout=WarriorX-10;
        }
        else
        {
            do
            {
            cout<<"Please select one of the following."<<endl;
            cout<<"Press (w) to move to the North room,(a) to the West";
            cout<<" room,(d) to the East room,"<<endl<<"(s)to the South";
            cout<<" room."<<endl;

            cin>>Warrior_move;

            }
            while(!(Warrior_move=='w' || Warrior_move=='s'
                || Warrior_move=='d' || Warrior_move=='a'));

        }

        if (WarriorXout<0 || WarriorYout<0 || WarriorXout>100 || WarriorYout>100)
        {
            cout<<"You hit the wall please select again."<<endl;

        }

        }
        while(WarriorXout<0 || WarriorYout<0 || WarriorXout>100 || WarriorYout>100);
}

void Grenade_Throw(double WarriorX, double WarriorY,
                   double WumpusX,double WumpusY)
{
    double Horizontal,elevation,velocity,GrenadeX,GrenadeY,Grenade_Dist,
    distance, Angle;
    cout<<"Enter the horizontal angle of the barrel(degrees)";
    cin>>Horizontal;

        do
        {
            if(Horizontal<0 || Horizontal>360)
            {
                cout<<"Please enter a number between 0 to 360 degrees.";
                cin>>Horizontal;
            }
        }
        while(Horizontal<0 || Horizontal>360);

        cout<<endl;
        cout<<"Enter the elevation angle of the barrel(degrees).";
        cin>>elevation;

        do
        {
            if(elevation>=90 || elevation<=0)
            {
                cout<<"Please enter a number between 0 to 90 degrees.";
                cin>>elevation;
            }
        }
        while(elevation>=90 || elevation<=0);

        cout<<endl;

        velocity=VelocityInput();
        distance=Compute_Distance_object_traveled(velocity,elevation);
        compute_Destination(distance,WarriorX,WarriorY,Horizontal,GrenadeX
                        ,GrenadeY);

        cout<<endl;
        cout<<"The grenade landed at ("<<GrenadeX<<","<<GrenadeY<<")"<<endl;
        cout<<endl;

        Grenade_Dist=computeDistance(WumpusX,GrenadeX,WumpusY,GrenadeY);


        if (Grenade_Dist < 10)
        {
            cout<<endl;
            cout<<"You Killed the Wumpus!"<<endl;

        }
        else
        {


            cout<<"     You missed it by this much..."<<endl;
            cout<<"     Distance:"<<Grenade_Dist<<endl;

        }
}


