//Christopher McCoy this program is an example of OOP in c++.
// The NBA player class is primarily responsible for updating the number of
// points scored by two players.
#include <iostream>
using namespace std;
void stropy(char *dest,char *source);
int strlen(char *s);
char* userInput();


class NBA_Player
{
    char *_name;
    int _numGames;
    int _points;
public:
    NBA_Player(char *name);
    void destructor();
    void displaySummary();
    char *getName();
    int getNumGames();
    int getPoints();
    double AVG_Points();
    void points_mutator(int points);
    int compare_AVG(NBA_Player *player2);
};

void updateGame(NBA_Player *one,NBA_Player *two);

int main()
{
    char *name1,*name2;
    int userOptions;
    cout<<"Please enter the name for the first player."<<endl;
    name1=userInput();
    NBA_Player *userOne=new NBA_Player(name1);

    cout<<"Please enter the name for the second player."<<endl;
    name2=userInput();

    NBA_Player *userTwo=new NBA_Player(name2);

    do
    {
        cout<<"Enter one of the following:"<<endl;
        do
        {
            cout<<"(1) Update data for each player for game: "<<userOne->getNumGames()+1<<endl;
            cout<<"(2) Quit the program."<<endl;
            cin>>userOptions;
            if(userOptions != 1 && userOptions!= 2)
            {
                cout<<"Please enter 1 or 2."<<endl;
            }
            if(userOptions==1)
            {
                updateGame(userOne,userTwo);
            }

        }while(userOptions != 1 && userOptions!= 2);

    }while(userOptions!=2);
    userOne->destructor();
    userTwo->destructor();
    cout<<"Goodbye."<<endl;
}
//NBA_Player methods============================================================
NBA_Player::NBA_Player(char *name)
{
    _name= new char[ strlen(name)+1];
    stropy(_name,name);
    _name=name;
    _numGames=0;
    _points=0;
}
void NBA_Player::destructor()
{
    delete _name;
}
void NBA_Player::displaySummary()
{
    cout<<"Name:"<<_name<<endl;
    cout<<"Games:"<<_numGames<<endl;
    cout<<"Points:"<<_points<<endl;
}
char *NBA_Player::getName()
{
    char *name=new char [strlen(_name)+1];
    stropy(name,_name);
    return name;
}
int NBA_Player::getNumGames()
{
    return _numGames;
}
int NBA_Player::getPoints()
{
    return _points;
}
double NBA_Player::AVG_Points()
{
    double AVG;
    if(_numGames==0)
    {
        return 0;
    }
    else
    {
        AVG=_points/_numGames;
        return AVG;
    }
}
void NBA_Player::points_mutator(int points)
{
    _numGames=_numGames+1;
    _points=_points+points;
}
int NBA_Player::compare_AVG(NBA_Player *player2)
{
    if(AVG_Points()> player2->AVG_Points())
    {
        return 1;
    }
    return 0;
}
//Sub-Programs==================================================================
int strlen(char *s)
{
    char *start;
    start=s;
    while(*s != '\0') ++s;
    return (s-start);
}
void stropy(char *dest,char *source)
{
    while(*source!= '\0')
    {
        *dest=*source;
        ++dest;++source;
    }
    *dest='\0';
}
void updateGame(NBA_Player *one,NBA_Player *two)
{
    int points;

    cout<<"Please enter the number of points scored by: "<<one->getName()<<endl;
    cin>>points;
    one->points_mutator(points);

    cout<<"Please enter the number of points scored by: "<<two->getName()<<endl;
    cin>>points;
    two->points_mutator(points);

    cout<<"Summary:"<<endl;
    one->displaySummary();
    cout<<endl;
    two->displaySummary();

    if(one->compare_AVG(two))
    {
        cout<<"Player: "<<one->getName()<<" has a higher average."<<endl<<endl;
    }
    else
    {
        cout<<"AVG Points: "<<two->getName()<<" has a higher average."<<endl<<endl;
    }
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

















