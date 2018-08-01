/*Christopher McCoy, this program calculates the total volume of the number of
oblate spheroids the user inputs*/
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int num;
    const double pie=3.1415926535897932;
    double majorAxis,minorAxis;
    double total=0;

    cout << "Hello, this program will give you the total volume of the" << endl;
    cout<< "oblate spheroids you enter."<<endl;

    cout<<endl<<"Enter the number of spheroids you want to calculate."<<endl;
    do
    {
        cin>>num;
        if(num<=0)
        {
            cout<<"Please enter a positive number."<<endl;
        }
    }while(num<=0);

    for(int i=1;i<=num;++i)
    {
        cout<<endl<<"Please enter the major axis in feet for sphere number "
        <<i<<"."<<endl;
        do
        {
            cin>>majorAxis;
            if(majorAxis<=0)
            {
                cout<<"Please enter a positive number."<<endl;
            }
        }while(majorAxis<=0);

        cout<<endl<<"Please enter the minor axis in feet for sphere number "
        <<i<<"."<<endl;
        do
        {
            cin>>minorAxis;
            if(minorAxis<=0)
            {
                cout<<"Please enter a positive number."<<endl;
            }
        }while(minorAxis<=0);

        total=total+(4.0/3.0*pie*majorAxis*pow(minorAxis,2));


    }
    cout<<endl<<"The total volume of all the spheres is: "<<total<<" cubic feet."<<endl;
    cout<<endl<<"Goodbye."<<endl;
    return 0;
}
