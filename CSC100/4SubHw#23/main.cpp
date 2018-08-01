#include <iostream>
#include <math.h>
using namespace std;
void greeting(void);
double UserInputs(double &radius, double &crossSect);
double computeVolume(double radius,double crossSect);
double Display(double volume);
int main()
{
    double radius,crossSec,volume;
    greeting();
    UserInputs(radius,crossSec);
    computeVolume(radius,crossSec);
    volume=computeVolume(radius,crossSec);
    Display(volume);
    return 0;
}
void greeting(void)
{
    cout << "Compute Ring Volume"<<endl;
}
double UserInputs(double &radius, double &crossSect)
{

    do
    {
    cout<<"Enter the radius.";
    cin>>radius;
    }while(radius<0);
    do
    {
    cout<<endl<<"Enter the cross section.";
    cin>>crossSect;
    }while(crossSect<0);
}
double computeVolume(double radius,double crossSect)
{
    const double pie=3.142;
    double volume;
    volume=2*pow(pie,2)*radius*pow(crossSect,2);
    return volume;
}
double Display(double volume)
{
    cout<<"The Volume is "<<volume<<endl;
}
