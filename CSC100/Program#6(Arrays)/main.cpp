#include <iostream>
#include <fstream>
#include <math.h>
#include <cmath>
using namespace std;
void LoadData_File(int Days[],double HighTemp[],double RecordTemp[]
                       ,double YearRecordTemp [],double Humidity[], int &nRow);
void LoadData_Key(int Days[],double HighTemp[],double RecordTemp[]
                       ,double YearRecordTemp [],double Humidity[], int &nRow);
void Display_Data(int Days[],double HighTemp[],double RecordTemp[]
                       ,double YearRecordTemp [],double Humidity[], int nRow);
void Title_Options(void);
void RecordHigh_Year(int Days[],double RecordTemp[],double YearRecordTemp [],
                      int nRow);
int find_index(int Days[],int nRow,double value);
void Compute_Heat_Index(int Days[],double HighTemp[],double Humidity[],int nRow,
                       double HeatIndex[]);
void Heat_Index(int Days[],double HighTemp[],double RecordTemp[]
                       ,double YearRecordTemp [],double Humidity[], int nRow);
int Selected_Fields();
void Avg_Max_Range(double HighTemp[],double RecordTemp[],int Field
                   ,double Humidity[],int nRow);
double Compute_Average(double Array[],int nRow);
double Compute_Minimum(double Array[],int nRow);
double Compute_Maxiumum(double Array[],int nRow);
double Compute_Range(double Maximum,double Minimum);
void Difference_Field(int Days[],double HighTemp[],double RecordTemp[],int Field
                   ,double Humidity[],int nRow);
double Compute_Difference(int Days[],double Field[],int nRow,int& Day_one
                        ,int& Day_two,double& Largest);

void Chart_Summary(int Data[],double HighTemp[],double RecordTemp[],int Field
                   ,double Humidity[],int nRow);
void Chart_Summary_Bar(double Field[],int nRow,int Data[]);
int choice_table();
void Data_Summary_Table(double Field[],int nRow,int Data[]);
int main()
{
    int loadType,nRow,option,quit;
    int Days[365];
    double HighTemp[365];
    double RecordTemp[365];
    double YearRecordTemp[365];
    double Humidity[365];
    int Data[11];

    cout<<endl<<endl;
    cout<< "Welcome to McCoy's weather recorder!" << endl<<endl;
    cout<< "Do you want to enter the weather data into";
    cout<<" a file or a keyboard?"<<endl;
    cout<<"(Enter 1 for key board. Enter 2 for file.)";



    do
    {
        cin>>loadType;
        if (!(loadType==1 || loadType==2))
        {
            cout<<"Wrong Input."<<endl;
            cout<<"(Enter 1 for key board. Enter 2 for file.)";
        }
    }while(!(loadType==1 || loadType==2));
do
{
    if (loadType==1)
    {
        LoadData_Key(Days,HighTemp,RecordTemp,YearRecordTemp,Humidity,nRow);
    }
    else
    {
       LoadData_File(Days,HighTemp,RecordTemp,YearRecordTemp,Humidity,nRow);
    }


    Title_Options();

    cin>>option;

    if(option==1)
    {
       Display_Data(Days,HighTemp,RecordTemp,YearRecordTemp,Humidity,nRow);
    }
    else if(option==2)
    {
        RecordHigh_Year(Days,RecordTemp,YearRecordTemp,nRow);
    }
    else if(option==3)
    {
        Heat_Index(Days,HighTemp,RecordTemp,YearRecordTemp,Humidity,nRow);
    }
    else if(option==4)
    {
        int Field;
        Field=Selected_Fields();
        Avg_Max_Range(HighTemp,RecordTemp,Field,Humidity,nRow);
    }
    else if(option==5)
    {
        int Field;
        Field=Selected_Fields();
        Difference_Field(Days,HighTemp,RecordTemp,Field,Humidity,nRow);
    }
    else if(option==6)
    {
        int Field;
        Field=Selected_Fields();
        Chart_Summary(Data,HighTemp,RecordTemp,Field,Humidity,nRow);
    }
    else if(option==7)
    {
        cout<<"Do you want to enter the data again or quit the program."<<endl;
        cout<<"(Press 1 to repeat.) \t (Press 2 to quit.)";
        cin>>quit;
    }
    else
    {
        do
        {
            cout<<"Wrong input please enter it again.";
            cin>>option;

        }while(!(option==1 || option==2 || option==3 || option==4 ||
                 option ==5 || option ==6 || option ==7));
    }

}
while(quit !=2);
    return 0;
}

    void LoadData_File(int Days[],double HighTemp[],double RecordTemp[]
                       ,double YearRecordTemp [],double Humidity[], int &nRow)
    {
        char filename[81];
        int ix;
        fstream infile;

        cout<<"Enter the file name."<<endl;
        //cin>>filename;

         infile.open("c:\\temp\\sample.txt", ios::in);
         //infile.open(filename,ios::in);

        ix=0;
        do
        {
            infile>>Days[ix];
            infile>>HighTemp[ix];
            infile>>RecordTemp[ix];
            infile>>YearRecordTemp[ix];
            infile>>Humidity[ix];
            ++ix;
        }
        while(Days[ix-1] != 0);

        nRow=ix-1;

        infile.close();
    }

    void LoadData_Key(int Days[],double HighTemp[],double RecordTemp[]
                       ,double YearRecordTemp [],double Humidity[], int &nRow)
    {
        int ix;
        cout<<"Enter the days.(NOTE: Enter 0 when finished)"<<endl;
        ix=0;
        do
        {
            cin>>Days[ix];
            ix++;
        }while(Days[ix-1] !=0);

        cout<<"Enter the Record High temperature in degrees."<<endl;
        ix=0;
        do
        {
            cin>>HighTemp[ix];
            ix++;
        }while(HighTemp[ix-1] !=0);

        cout<<"Enter the record high temperature of the year."<<endl;
        ix=0;
        do
        {
            cin>>RecordTemp[ix];
            ix++;
        }while(RecordTemp[ix-1] !=0);

        cout<<"Enter the relative humidity as a percent."<<endl;
        ix=0;
        do
        {
            cin>>Humidity[ix];
            ix++;
        }while(Humidity[ix-1] !=0);

        nRow=ix-1;

    }

void Title_Options()
{

    cout<<endl;
    cout<<"Select one one of the following options."<<endl<<endl;
    cout<<"(1) Display the data in the file."<<endl;
    cout<<"(2) Display the record high temperature and the year it was ";
    cout<<"recorded for a given day."<<endl;
    cout<<"(3) Display the heat index for each day."<<endl;
    cout<<"(4) Display the average, the maximum, the minimum, and the range";
    cout<<" of one field."<<endl;
    cout<<"(5) Display the largest difference between two consecutive values";
    cout<<" in one field."<<endl;
    cout<<"(6) Display a chart summarizing the distributions of the values";
    cout<<" in one field."<<endl;
    cout<<"(7) Stop analyzing this collection of data."<<endl;
}
void Display_Data(int Days[],double HighTemp[],double RecordTemp[]
                       ,double YearRecordTemp [],double Humidity[], int nRow)
{
    int ix;
    cout<<"Days:    High Temp:  Record High Temp:   Year:   Relative Humidity:  "<<endl;

    for(ix=0;ix<nRow;++ix)
    {
        cout<<Days[ix]<<"\t"<<HighTemp[ix]<<"\t"<<RecordTemp[ix]<<"\t";
        cout<<YearRecordTemp[ix]<<"\t"<<Humidity[ix]<<"\t"<<endl; //Fix!
    }

}
void RecordHigh_Year(int Days[],double RecordTemp[],double YearRecordTemp [],
                      int nRow)
{
    int value,index;
    cout<<endl<<"Enter the day of the year to receive the record high";
    cout<<" temperature.";

        do
        {
        cin>>value;
        index=find_index(Days,nRow,value);
            if(index==-1)
            {
                cout<<"The day you entered was not found."<<endl;
            }
        }while(index==-1);

        cout<<endl<<"From the data base..."<<endl;
        cout<<"Record High Temperature of Day "<<value<<" was:";
        cout<<RecordTemp[index]<<endl;
        cout<<"The year the data was collected:"<<YearRecordTemp[index]<<endl;



}
int find_index(int Days[],int nRow,double value)
{
    int ix;

    for(ix=0;ix<nRow;++ix)
    {
        if(Days[ix]==value)
            return ix;
    }
        return -1;

}
void Heat_Index(int Days[],double HighTemp[],double RecordTemp[]
                       ,double YearRecordTemp [],double Humidity[], int nRow)
{
    double HeatIndex[365];
    int ix;
    Compute_Heat_Index(Days,HighTemp,Humidity,nRow,HeatIndex);

    cout<<"Days:        High Temp:      Relative Humidity:      Heat Index: ";
    cout<<endl;

    for(ix=0;ix<nRow;++ix)
    {
        cout<<Days[ix]<<"\t"<<HighTemp[ix]<<"\t"<<Humidity[ix]<<"\t";
        cout<<HeatIndex[ix];
        cout<<endl;
    }
}
void Compute_Heat_Index(int Days[],double HighTemp[],double Humidity[],int nRow,
                       double HeatIndex[])
{

    int ix;

    for(ix=0;ix<nRow;++ix)
    {
        HeatIndex[ix]=-42.379+(2.04901523*HighTemp[ix])+
        (10.14333127*Humidity[ix])-(.22475541*HighTemp[ix]*Humidity[ix])-
        (.00683783*pow(HighTemp[ix],2))-(.05481717*pow(Humidity[ix],2))+
        (.00122874*pow(HighTemp[ix],2)*Humidity[ix])+
        (.00085282*HighTemp[ix]*pow(Humidity[ix],2))-
        (.00000199*pow(HighTemp[ix],2)*pow(Humidity[ix],2));

        if(Humidity[ix]<13 && HighTemp[ix]<112 && HighTemp[ix]>80)
        {
            HeatIndex[ix]=HeatIndex[ix]-((13-Humidity[ix])/4)*
            sqrt((17-abs(HighTemp[ix]-95))/17);
        }
        else if(Humidity[ix]>85 && HighTemp[ix]<87 && HighTemp[ix]>80)
        {
            HeatIndex[ix]=HeatIndex[ix]+((Humidity[ix]-85)*
            ((87-HighTemp[ix])/5));
        }
    }
}
int Selected_Fields()
{
    int Field;
    cout<<"Fields:"<<"High Temperature,Record High Temperature,Humidity."<<endl;
    cout<<"Which field do you want to display?"<<endl;
    cout<<"(1)High Temperature (2)Record High Temperature (3)Humidity";
    do
    {
        cin>>Field;
        if(!(Field==1 || Field==2 || Field==3))
        {
            cout<<"Wrong input please try again.";
        }
    }while(!(Field==1 || Field==2 || Field==3));

    return Field;
}


double Compute_Average(double Array[],int nRow)
{
    int ix;
    double Average,sum;

    sum=0;
    for(ix=0;ix<nRow;++ix)
    {
        sum=sum+Array[ix];

    }
    if(nRow != 0)
    {
        Average=sum/nRow;
    }
    else
    {
        Average=0.0;
    }
    return Average;
}
void Avg_Max_Range(double HighTemp[],double RecordTemp[],int Field
                   ,double Humidity[],int nRow)
{
    double Average,Smallest,Largest,Range;
  if (Field==1)
  {
      Average=Compute_Average(HighTemp,nRow);
      Smallest=Compute_Minimum(HighTemp,nRow);
      Largest=Compute_Maxiumum(HighTemp,nRow);

  }
  else if (Field==2)
  {
      Average=Compute_Average(RecordTemp,nRow);
      Smallest=Compute_Minimum(RecordTemp,nRow);
      Largest=Compute_Maxiumum(RecordTemp,nRow);
  }
  else
  {
      Average=Compute_Average(Humidity,nRow);
      Smallest=Compute_Minimum(Humidity,nRow);
      Largest=Compute_Maxiumum(Humidity,nRow);

  }

    Range=Compute_Range(Largest,Smallest);

    cout<<"The average is:"<<Average<<endl;
    cout<<"The smallest is:"<<Smallest<<endl;
    cout<<"The Largest is:"<<Largest<<endl;
    cout<<"The Range is:"<<Range<<endl;

}
double Compute_Minimum(double Array[],int nRow)
{
    int ix;
    double smallest;

    smallest=Array[0];
    for(ix=1;ix<nRow;++ix)
    {
        if(smallest>Array[ix])
        {
            smallest=Array[ix];
        }
    }
    return smallest;
}
double Compute_Maxiumum(double Array[],int nRow)
{
    int ix;
    double Maxiumum;
    Maxiumum=Array[0];
    for(ix=1;ix<nRow;++ix)
    {
        if(Array[ix]>Maxiumum)
        {
            Maxiumum=Array[ix];
        }
    }
    return Maxiumum;
}
double Compute_Range(double Maximum,double Minimum)
{
    double Range;
    Range=Maximum-Minimum;
    return Range;
}
void Difference_Field(int Days[],double HighTemp[],double RecordTemp[],int Field
                   ,double Humidity[],int nRow)
{
    double Largest_Diff;
    int FirstDay,SecondDay;
    if (Field==1)
    {
        Compute_Difference(Days,HighTemp,nRow,FirstDay,SecondDay,Largest_Diff);
    }
    else if(Field==2)
    {
        Compute_Difference(Days,RecordTemp,nRow,FirstDay,SecondDay,
                           Largest_Diff);
    }
    else
    {
        Compute_Difference(Days,Humidity,nRow,FirstDay,SecondDay,Largest_Diff);
    }
    cout<<endl;
    cout<<"The largest difference between two second days of the given field";
    cout<<" is: "<<Largest_Diff<<endl;
    cout<<"Happened between Day "<<SecondDay<<" and Day "<<FirstDay<<endl;
}
double Compute_Difference(int Days[],double Field[],int nRow,int& Day_one
                        ,int& Day_two,double& Largest)
{
    int ix;
    double Difference;
    Largest=0;


    for(ix=1;ix<nRow;++ix)
    {

        Difference=abs(Field[ix]-Field[ix-1]);

        if(Difference>Largest)
        {
            Largest=Difference;

            Day_two=Days[ix];
            Day_one=Days[ix-1];
        }

    }

}
void Chart_Summary(int Data[],double HighTemp[],double RecordTemp[],int Field
                   ,double Humidity[],int nRow)
{
    int choice;

    if(Field==1)
    {
        choice=choice_table();
        if(choice==1)
        {
            Data_Summary_Table(HighTemp,nRow,Data);
        }
        else
        {
            Chart_Summary_Bar(HighTemp,nRow,Data);
        }
    }
    else if(Field==2)
    {
        choice=choice_table();
        if(choice==1)
        {
            Data_Summary_Table(RecordTemp,nRow,Data);
        }
        else
        {
            Chart_Summary_Bar(RecordTemp,nRow,Data);
        }
    }
    else
    {
        choice=choice_table();
        if(choice==1)
        {
            Data_Summary_Table(Humidity,nRow,Data);
        }
        else
        {
            Chart_Summary_Bar(Humidity,nRow,Data);
        }
    }






}
void Data_Summary_Table(double Field[],int nRow,int Data[])
{
    int ix,index;

    for(ix=0;ix<nRow;++ix)
    {
        index=Field[ix]/10;
        index=index*10;
        index=index/10;
         if(Field[ix]<0)
        {
            Data[index]=0;
        }
        else if(index>10)
        {
            Data[10]=Data[10]+1;
        }
        else
        {
        Data[index]=Data[index]+1;
        }
        cout<<Data[ix]<<endl;

    }


    cout<<"Data[10]:"<<Data[10];
    cout<<endl;
    cout<<"Here is a table of the resulting counts..."<<endl<<endl;
    cout<<"Decade\tcount"<<endl;

    for(ix=0;ix<10;++ix)
    {

        cout<<ix*10<<"\t"<<Data[ix]<<endl;



    }
    cout<<"100+"<<"\t"<<Data[10];
}
void Chart_Summary_Bar(double Field[],int nRow,int Data[])
{
    int ix,index,ixx;
    cout<<endl<<endl;
    cout<<"Here is a simple horizontal bar chart summarizing the same results:";
    cout<<endl<<endl;

   for(ix=0;ix<nRow;++ix)
    {

        index=Field[ix]/10;

        cout<<"Index:"<<index<<endl;
        if(Field[ix]<0)
        {
            Data[index]=0;
        }
        else if(index>10)
        {
            Data[10]=Data[10]+1;
        }
        else
        {
        Data[index]=Data[index]+1;
        }

    }
    cout<<"Data[10]:"<<Data[10]<<endl;
    for(ix=1;ix<11;++ix)
    {
        cout<<ix*10<<"\t";

        for(ixx=0;ixx<Data[ix];++ixx)
            {
                cout<<"*";
            }
        cout<<endl;
    }

}
int choice_table()
{
    int choice;
    cout<<"Do you want a table or a bar graph?"<<endl;
    cout<<"(1)Table (2)Bar";


    do
    {
        cin>>choice;
        if (!(choice==1 || choice==2))
        {
            cout<<"Wrong Input."<<endl;
            cout<<"(Enter 1 for table. Enter 2 for bar.)";
        }
    }while(!(choice==1 || choice==2));

    return choice;
}




