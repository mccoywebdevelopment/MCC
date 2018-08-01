#include <iostream>

using namespace std;
struct BankAccount
{
    char Name[100]; //Needs array because it's a string.
    double Amount;
    int Week ;

};
int main()
{
   BankAccount Data[3];
   int ix,Count;
   char more;
   ix=0;

   do
    {
   cout<<"Enter the Name of the account."<<endl;
   cin>>Data[ix].Name;

   cout<<"Enter the amount of the bank account."<<endl;
   cin>>Data[ix].Amount;

   cout<<"Enter the week the money was stored."<<endl;
   cin>>Data[ix].Week;

   cout<<endl<<"*** Bank Account ***"<<endl<<endl;
   cout<<"Name/Amount/Week"<<endl;
   ++ix;

   cout<<"More inputs (y/n)?";
   cin>>more;
    }
   while(more=='y');
   Count=ix;
   for(ix=0;ix<Count;++ix)
   {
   cout<<Data[ix].Name<<"\t";
   cout<<Data[ix].Amount<<"\t";
   cout<<Data[ix].Week<<endl;
    }
    return 0;
}

void LoadData(BankAccount Data[],int &Count)
{
    int ix;
    char more;
    ix=0;
}
