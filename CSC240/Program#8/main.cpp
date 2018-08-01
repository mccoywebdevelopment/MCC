#include <iostream>
void intro();
char* userInput();
int findCharacter(char *input,char key);
using namespace std;
/*Christopher McCoy, this program is designed to read a line of code and then count
how many times a user-specified character appears in the text.*/
int main()
{
    char key;
    char *input;
    char again,redo;
    int counter;
    do
    {

        intro();
        input=userInput();


        do
        {
            cout<<endl<<"Please enter a character you want to count how many times it appears "<<endl;
            cout<<"in the line of text you entered."<<endl;
            cin>>key;

            counter=findCharacter(input,key);
            cout<<"The character '"<<key<<"' appears "<<counter<<" times."<<endl;

            cout<<"Do you want to look for another character (y/n)?"<<endl;
            do
            {
                cin>>again;
                if(again != 'y' && again !='n')
                {
                    cout<<"Please enter (y/n)."<<endl;
                }
            }while(again != 'y' && again !='n');

        }while(again=='y');

        cout<<"Do you want to start over (y/n)?"<<endl;
        do
        {
            cin>>redo;
            if(redo != 'y' && redo !='n')
            {
                cout<<"Please enter (y/n)."<<endl;
            }
        }while(redo != 'y' && redo !='n');
        cin.get();//get rid of the rest.

    }while(redo=='y');


}
void intro()
{
    cout<<"This program is designed to read a line of code and then count how "<<endl;
    cout<<"many times a user-specified character appears in the text."<<endl;
    cout << "Please enter a line of text you want to test on." << endl;

}
char* userInput()
{
    char c;
    char *input = new char[81];
    c=cin.get();
    char *start=input;
    while(c!='\n')
    {
        if(c!= ' ' && c!= '\t')
        {
            *input=c;
            input++;
            c=cin.get();

        }
        else{
            c=cin.get();
        }

    }
    *input='\0';
    int length;
    length=input-start;
    input=start;

    char *newArray=new char[length+1];
    start=newArray;
    while(*input!='\0')
    {
        *newArray=*input;
        newArray++; input++;
    }
    newArray=start;

    delete input;
    return newArray; //shift back to start
}
int findCharacter(char *input,char key)
{

    int counter=0;
    while(*input!='\0')
    {
        if(*input==key)
        {
            ++counter;
        }
        input++;
    }
    return counter;
}

