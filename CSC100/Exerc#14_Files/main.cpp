#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream infile;
    int ID[100];
    float score[100];
    int ix;
    cout<< "Opening the file..."<<endl;
    infile.open("c:\\temp\\sample.txt", ios::in);

    cout<<"ID\tScores"<<endl;

    ix=0;
    infile>>ID[ix]>>score[ix];

    while(ID[ix] !=0)
    {
       cout<<ID[ix]<<"\t"<<score[ix]<<endl;

       ++ix;
       infile>>ID[ix]>>score[ix];
    }

    cout<<"Closing the file..."<<endl;
    infile.close();

    cout<<"All done...."<<endl;

    return 0;
}
