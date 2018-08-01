/* Chris McCoy's interest calculator This program is designed to predict the
growth of a bank account due to compounded interest.*/
#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

int main()
{
   double annualcharge,threshold,balance,Rate,PeriodicRate;
   double interest,FirstInterest,goal;
   int comNum,compound,option,num,i,days;
   char table,redo;

    cout<<"Welcome to the bank's predicted growth calculator."<<endl;
    cout<<"Can you please enter the annual processing."<<endl<<endl;
do
{
    cin>>annualcharge;
    cout<<endl;
    if (annualcharge<0)
    {
        cout<<"Please enter a positive value."<<endl<<endl;
    }
}
while(annualcharge<0);

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
    cin>>balance;
    cout<<endl;
        if(balance<0)
        {
            cout<<"Please enter a positive value."<<endl<<endl;
        }
    }
    while(balance<0);

    cout<<"Enter the annual interest rate as a percentage."<<endl<<endl;
    do
    {
    cin>>Rate;

    cout<<endl;
        if(Rate<0)
        {
            cout<<"Please enter a positive value."<<endl<<endl;
        }
    }
    while(Rate<0);

    Rate=Rate/100;

    cout<<"Enter period at which interest is compounded"<<endl;
    cout<<"Press (1) for yearly"<<endl;
    cout<<"Press (2) for monthly"<<endl;
    cout<<"Press (3) for daily"<<endl;
    do
    {
        cin>>compound;
        cout<<endl;
            if(compound==1)
            {
                comNum=1;
            }
            else if(compound==2)
            {
                comNum=12;
            }
            else if(compound==3)
            {
                comNum=365;
            }
            else
            {
                cout<<"Please use the correct input."<<endl;
                cout<<"Press (1) for yearly"<<endl;
                cout<<"Press (2) for monthly"<<endl;
                cout<<"Press (3) for daily"<<endl;
            }
    }
    while(!(compound==1 || compound==2 || compound==3));


    cout<<"comNum: "<<comNum<<" Rate: "<<Rate<<endl<<endl;
    cout<<"Select one of the two options."<<endl;
    cout<<"Press (1) To calculate how much money you will have after";
    cout<<" X amount of time"<<endl;
    cout<<"Press (2) To calculate how long it will take until you will get";
    cout<<" X amount of money"<<endl;
cout<<"periodic charge:"<<annualcharge/comNum<<endl;
PeriodicRate=Rate/comNum;
Rate=Rate*100;

do
{
    cin>>option;
    if(option==1)
    {
           if(comNum==1)
           {
            cout<<"Enter how many year(s) you want to";
            cout<<" compound your investment.";
            cin>>num;
            cout<<endl<<endl;
            printf("Initial Balance         $%1.2f\n",balance);
            printf("Annual Interest rate    %1.0f %%\n",Rate);
            printf("Compounding Period      Yearly\n");
            printf("Time                   %2.0i year(s)\n",num);
            do
            {
            cout<<"Do you want a table?(y/n)";

            cin>>table;
            cout<<endl;

                if(table=='y')
                {
                   printf("Year                 Balance\n");

                for (i=1;i<=num;++i)
                {
                   interest=balance*PeriodicRate;
                   balance=interest+balance;

                    if(balance<threshold)
                    {
                    balance=balance-(annualcharge/comNum);
                    }
                    printf("%3i     %19.2f\n",i,balance);
                    }
                }
               else if(table=='n')
               {
                   for (i=1;i<=num;++i)
                   {
                   interest=balance*PeriodicRate;
                   balance=interest+balance;

                        if(balance<threshold)
                        {
                        balance=balance-(annualcharge/comNum);
                        }
                   }
               printf("After %1i year(s) you will have $%1.2f\n",num,balance);
                }
               else
               {
                cout<<"Please enter (y/n)"<<endl;
                cin>>table;
               }
            }
               while(!(table=='y'||table=='n'));
            }
    else if(comNum==12)
           {
            cout<<"Enter how many month(s) you want to";
            cout<<" compound your investment."<<endl;

            cin>>num;

            printf("Initial Balance         $%1.2f\n",balance);
            printf("Annual Interest rate    %1.0f %%\n",Rate);
            printf("Compounding Period      monthly\n");
            printf("Time                   %2.0i month(s)\n",num);
            do
            {
            cout<<"Do you want a table?(y/n)"<<endl;

            cin>>table;

                if(table=='y')
                {
                   printf("Month(s)              Balance\n");;

                for (i=1;i<=num;++i)
                {
                   interest=balance*PeriodicRate;
                   balance=interest+balance;

                    if(balance<threshold)
                    {
                    balance=balance-(annualcharge/comNum);
                    }
                    printf("%3i     %19.2f\n",i,balance);
                    }
                }
               else if(table=='n')
               {
                   for (i=1;i<=num;++i)
                   {
                   interest=balance*PeriodicRate;
                   balance=interest+balance;

                        if(balance<threshold)
                        {
                        balance=balance-(annualcharge/comNum);
                        }
                   }
               printf("After %1i month(s) you will have $%1.2f\n",num,balance);
                }
               else
               {
                cout<<"Please enter (y/n)"<<endl;
                cin>>table;
               }
            }
            while(!(table=='y'||table=='n'));
            }
           else if(comNum==365)
           {
            cout<<"Enter how many day(s) you want to";
            cout<<" compound your investment."<<endl;

            cin>>num;

            printf("Initial Balance         $%1.2f\n",balance);
            printf("Annual Interest rate    %1.0f %%\n",Rate);
            printf("Compounding Period      daily\n");
            printf("Time                   %3.0i day(s)\n",num);
            do
            {
            cout<<"Do you want a table?(y/n)"<<endl;

            cin>>table;

                if(table=='y')
                {
                   printf("Day(s)                 Balance\n");

                for (i=1;i<=num;++i)
                {
                   interest=balance*PeriodicRate;
                   balance=interest+balance;

                    if(balance<threshold)
                    {
                    balance=balance-(annualcharge/comNum);
                    }
                    printf("%3i     %19.2f\n",i,balance);
                    }
                }
               else if(table=='n')
               {
                   for (i=1;i<=num;++i)
                   {
                   interest=balance*PeriodicRate;
                   balance=interest+balance;

                        if(balance<threshold)
                        {
                        balance=balance-(annualcharge/comNum);
                        }
                   }
               printf("After %1i day(s) you will have $%1.2f\n",num,balance);
                }
               else
               {
                cout<<"Please enter (y/n)"<<endl;
                cin>>table;
               }
            }
               while(!(table=='y'||table=='n'));

    }
    cout<<"Do you want to do it all over again?"<<endl;
    cin>>redo;
    }
    else if(option==2)
    {
        if(comNum==1)
           {
            cout<<"Enter the goal balance."<<endl;
            cin>>goal;

            cout<<endl;
            printf("Initial Balance         $%1.2f\n",balance);
            printf("Annual Interest rate    %1.0f %%\n",Rate);
            printf("Compounding Period      Yearly\n");
            printf("Goal Balance            $%1.2f\n",goal);

            do
            {
            cout<<"Do you want a table?(y/n)";

            cin>>table;
            cout<<endl;

                if(table=='y')
                {
                   printf("Year                 Balance\n");
                num=0;
                do
                {
                   interest=balance*PeriodicRate;
                   balance=interest+balance;

                   num=num+1;

                    if(balance<threshold)
                    {
                    balance=balance-(annualcharge/comNum);
                    }
                    printf("%2.0i     %19.2f\n",num ,balance);
                    }
                    while(balance<goal);
                printf("After %1i year(s) you will have $%1.2f\n",num,balance);
                }
               else if(table=='n')
               {
                   num=0;
                   do
                   {
                   interest=balance*PeriodicRate;
                   balance=interest+balance;

                        if(balance<threshold)
                        {
                        balance=balance-(annualcharge/comNum);
                        }

                   num=num+1;
                   }
                   while(balance<=goal);
               printf("After %1i year(s) you will have $%1.2f\n",num,balance);
                }
               else
               {
                cout<<"Please enter (y/n)"<<endl;
                cin>>table;
               }
            }
               while(!(table=='y'||table=='n'));
           }
           else if(comNum==12)
           {
            cout<<"Enter the goal balance."<<endl;
            cin>>goal;

            cout<<endl;
            printf("Initial Balance         $%1.2f\n",balance);
            printf("Annual Interest rate    %1.0f %%\n",Rate);
            printf("Compounding Period      Monthly\n");
            printf("Goal Balance            $%1.2f\n",goal);

            do
            {
            cout<<"Do you want a table?(y/n)";

            cin>>table;
            cout<<endl;

                if(table=='y')
                {
                   printf("Month(s)                 Balance\n");
                num=0;
                do
                {
                   interest=balance*PeriodicRate;
                   balance=interest+balance;

                   num=num+1;

                    if(balance<threshold)
                    {
                    balance=balance-(annualcharge/comNum);
                    }
                    printf("%2.0i     %19.2f\n",num ,balance);
                    }
                    while(balance<goal);
                printf("After %1i month(s) you will have $%1.2f\n",num,balance);
                }
               else if(table=='n')
               {
                   num=0;
                   do
                   {
                   interest=balance*PeriodicRate;
                   balance=interest+balance;

                        if(balance<threshold)
                        {
                        balance=balance-(annualcharge/comNum);
                        }

                   num=num+1;
                   }
                   while(balance<=goal);
               printf("After %1i month(s) you will have $%1.2f\n",num,balance);
                }
               else
               {
                cout<<"Please enter (y/n)"<<endl;
                cin>>table;
               }
            }
               while(!(table=='y'||table=='n'));
           }
           else if(comNum==365)
           {
            cout<<"Enter the goal balance."<<endl;
            cin>>goal;

            cout<<endl;
            printf("Initial Balance         $%1.2f\n",balance);
            printf("Annual Interest rate    %1.0f %%\n",Rate);
            printf("Compounding Period      Daily\n");
            printf("Goal Balance            $%1.2f\n",goal);

            do
            {
            cout<<"Do you want a table?(y/n)";

            cin>>table;
            cout<<endl;

                if(table=='y')
                {
                   printf("Day(s)                 Balance\n");
                num=0;
                do
                {
                   interest=balance*PeriodicRate;
                   balance=interest+balance;

                   num=num+1;

                    if(balance<threshold)
                    {
                    balance=balance-(annualcharge/comNum);
                    }
                    printf("%2.0i     %19.2f\n",num ,balance);
                    }
                    while(balance<goal);
                printf("After %1i day(s) you will have $%1.2f\n",num,balance);
                }
               else if(table=='n')
               {
                   num=0;
                   do
                   {
                   interest=balance*PeriodicRate;
                   balance=interest+balance;

                        if(balance<threshold)
                        {
                        balance=balance-(annualcharge/comNum);
                        }

                   num=num+1;
                   }
                   while(balance<=goal);
               printf("After %1i day(s) you will have $%1.2f\n",num,balance);
                }
               else
               {
                cout<<"Please enter (y/n)"<<endl;
                cin>>table;
               }
            }
               while(!(table=='y'||table=='n'));
           }
    cout<<"Do you want to do it all over again?"<<endl;
    cin>>redo;
    }




    else
    {
        cout<<"Please select one or two.";
    }

}
while(!(option==1 || option==2));
if(!(redo=='n'))
{
    do
    {
    cout<<"Please select (y/n)"<<endl;
    cin>>redo;
    }while(!(redo=='y'||redo=='n'));

}
}while(!(redo=='n'));
return 0;
}


















