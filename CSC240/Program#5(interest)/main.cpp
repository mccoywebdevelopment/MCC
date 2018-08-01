/* Chris McCoy's interest calculator This program is designed to predict the
growth of a bank account.*/
#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

int computeLength(double threshold,int goal,double balance,
                  double annualInterest,int table,
                  double  annualCharge,int &time,double &newBalance);
double computeFinalBalance(double threshold,int length,double balance,double rate,
                           int table, double  annualCharge);

int main()
{
    double threshold,initialBalance,annualInterest,newBalance,
    annualCharge,newBalanceTwo;
    char same_calc_redo,restart;
    int length,period,option,goal,time,table;

    cout<<"Welcome to the bank's predicted growth calculator."<<endl;
    do
    {

        cout<<"Can you please enter the annual processing charge."<<endl<<endl;
        do
        {
            cin>>annualCharge;
            cout<<endl;
            if (annualCharge<0)
            {
                cout<<"Please enter a positive value."<<endl<<endl;
            }
        }
        while(annualCharge<0);

        cout<<"Please enter the threshold"<<endl<<endl;
        do
        {
            cin>>threshold;
            cout<<endl;
            if(threshold<0)
            {
                cout<<"Please enter a positive value."<<endl<<endl;
            }
        }
        while(threshold<0);

        do
        {
        cout<<"Enter the initial balance"<<endl<<endl;
        do
        {
        cin>>initialBalance;
        cout<<endl;
            if(initialBalance<0)
            {
                cout<<"Please enter a positive value."<<endl<<endl;
            }
        }
        while(initialBalance<0);

        cout<<"Enter the annual interest rate as a percentage(0-100%)."<<endl<<endl;
        do
        {
            cin>>annualInterest;

            cout<<endl;

            if(annualInterest<0)
            {
                cout<<"Please enter a positive value."<<endl<<endl;
            }
        }
        while(annualInterest<0);

        annualInterest=annualInterest/100;

        cout<<"Select one of the two options."<<endl;
        cout<<"Press (1) To calculate how much money you will have after";
        cout<<" X amount of time"<<endl;
        cout<<"Press (2) To calculate how long it will take until you will get";
        cout<<" X amount of money"<<endl;

        do
        {
            cin>>option;
            if(option !=1 && option!=2)
            {
                cout<<"Please enter 1 or 2."<<endl;
            }

        }while(option !=1 && option!=2);

        cout<<"Do you want a table?"<<endl;
        cout<<"(1) YES."<<endl;
        cout<<"(2) NO."<<endl;

        do
        {
            cin>>table;
            if(table != 1 && table != 2)
            {
                cout<<"Invalid input please pick 1 or 2."<<endl;
            }

        }while(table != 1 && table != 2);

        if(option==1)
        {
            cout<<"Please enter how long you want to compound your investment.";

            do
            {
                cin>>length;
                if(length<1)
                {
                    cout<<"Please enter a value greater than zero."<<endl;
                }
            }while(length<1);

            cout<<"annualInterest:"<<endl;
            cout<< annualInterest<<endl;

            newBalance=computeFinalBalance(threshold,length,initialBalance,
                                           annualInterest,table,
                                            annualCharge);

            if(table!=1)
            {
                cout<<length<<"                    "<<newBalance<<endl;
            }


        }
        else{
            cout<<"Please enter the goal amount you want to achieve."<<endl;

            do
            {
                cin>>goal;
                if(goal<=0)
                {
                    cout<<"Please enter a value greater than zero."<<endl;
                }
            }while(goal<=0);

            if(table==1)
            {
                cout<<"Years:               Amount:"<<endl;
            }

            computeLength(threshold,goal,initialBalance,annualInterest,
                               table, annualCharge,time,newBalanceTwo);
            if(table!=1)
            {
                cout<<"You will reach $";
                cout<<newBalanceTwo;
                cout<<" by ";
                cout<<time;
            }
        }
        cout<<endl<<"Want to do another calculation?(same processing charge and threshold)"<<endl;
        cout<<"(y/n)"<<endl;

        do
        {
            cin>>same_calc_redo;

            if(same_calc_redo!='y' && same_calc_redo!='n')
            {
                cout<<"Please enter (y/n)"<<endl;
            }
        }while(same_calc_redo!='y' && same_calc_redo!='n');

    }while(same_calc_redo=='y');

    cout<<"Do you want to try a different processing charge and threshold? (y/n)"<<endl;

    do
    {
        cin>>restart;
        if(restart!='y' && restart!='n')
        {
            cout<<"Please enter (y/n)."<<endl;
        }
    }while(restart!='y' && restart!='n');

}while(restart=='y');










}

double computeFinalBalance(double threshold,int length,double balance,double rate,
                           int table, double  annualCharge)
{
    int i;
    double interest;
    cout<<"Time:                    Money:"<<endl;
    for(i=1;i<=length;++i)
    {
        interest=balance*rate;
        balance=interest+balance;

        if(balance<threshold)
        {
            balance=balance-annualCharge;
        }
        if(table==1)
        {
            cout<<i;
            cout<<"                  "<<balance<<endl;

        }
    }
    return balance;                                                          //Fix delete this

}

int computeLength(double threshold,int goal,double balance,
                  double annualInterest,int table,
                  double  annualCharge,int &time,double &newBalance)
{
    newBalance=balance;
    double interest;
    time=0;
    do
    {
        interest=newBalance*annualInterest;
        newBalance=interest+newBalance;
        time=time+1;
        if(newBalance<threshold)
        {
            newBalance=newBalance- annualCharge;
        }

        if(table==1)
        {
            cout<<time<<"                   "<<newBalance<<endl;
        }
    }while(newBalance<goal);

}





















