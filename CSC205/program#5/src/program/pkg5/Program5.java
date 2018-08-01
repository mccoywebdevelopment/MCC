
package program.pkg5;
import java.util.*;
import java.util.Scanner;

class team
{
    private ArrayList<player> _players;
    private manager _manager;
    private int _numBatters;
    private int _numPitchers;
    
    public team(manager givenManager)
    {
        _numBatters=0;
        _numPitchers=0;
        _manager=givenManager;
        _players=new ArrayList<player>();
    }
    public int getNumberBatters()
    {
        return _numBatters;
    }
    public int getNumberPitchers()
    {
        return _numPitchers;
    }
    public manager getManager()
    {
        return _manager;
    }
    public player getSpecificPlayer(String name)
    {
        for(int i=0;i<_players.size();++i)
        {
            if(name.equals(_players.get(i).getName()))
            {
                return _players.get(i);
            }
        }
        return null;
    }
    public int getNumberOfPlayers()
    {
        return _players.size();
    }
    public void addPlayer(player p)
    {
        if(p instanceof batter)
        {
            _numBatters=_numBatters+1;
        }
        else
        {
            _numPitchers=_numPitchers+1;
        }
        _players.add(p);
        
    }
    public void deletePlayer(String given)
    {
        
        for(int i=0;i<_players.size();++i)
        {
            if(given.equals(_players.get(i).getName()))
            {
                _players.remove(_players.get(i));
                
                if(_players.get(i) instanceof batter)
                {
                    _numBatters=_numBatters-1;
                }
                else
                {
                    _numPitchers=_numPitchers-1;
                }
            }
        }
        
       
    }
    public void replaceManager(manager newManager)
    {
        _manager=newManager;
    }
    public double computeBattingAVG()
    {
        int hits=0;
        int bats=0;
        for ( player p : _players )
        {
            hits=hits+p.getHits();
            bats=bats+p.getNumBats();
        }
        if (bats==0)
        {
            return 0;
        }
        return ((double)hits/bats);
        
    }
    public int computeHomeRuns()
    {
        int runs=0;
        for(player p: _players)
        {
            runs=runs+p.getHomeRuns();
        }
        return runs;
    }
    public double computeERA()
    {
        int earnedRuns=0;
        double innings=0;
        for(player p: _players)
        {
            earnedRuns=earnedRuns+p.getEarnedRuns();
            innings=innings+p.getInnings();
        }
        if(innings==0)
        {
            return 0;
        }
        return ((earnedRuns/innings)*9);
            
    }
    public int computeStrikeOuts()
    {
        int strike=0;
        for(player p:_players)
        {
            strike=strike+p.getStrikeOuts();
        }
        return strike;
    }
    public double computeSalary()
    {
        double salary=0;
        for(player p:_players)
        {
            salary=salary+p.getSalary();
        }
        salary=salary+_manager.getSalary();
        return salary;
    }
    public double computeTeamValue()
    {
       double value=0;
       int players;
       for(player p:_players)
       {
           value=value+p.getValue();
       }
       players=_numBatters+_numPitchers;
       if(players>0)
       {
           return (value/players);
       }
       return 0;
    }
    public String toString()
    {
        String s="";
        s=s+_manager.toString();
        s=s+"\n\n";
        s=s+"\nnumBatters"+_numBatters+"\nnumPitchers"+_numPitchers;
        s=s+"\n\n";
        for(int ix=0;ix<_players.size();++ix)
        {
            s=s+"\nplayers"+_players.get(ix);
        }
        return s;
        
    }
}


class manager extends employee
{
    private int _careerWins;
    private int _careerGames;
    
    public manager(String name,double salary,int years,int careerWins,
            int careerGames)
    {
        super(name,salary,years);
        _careerWins=careerWins;
        _careerGames=careerGames;
    }
    public int getCareerWins()
    {
        return _careerWins;
    }
    public int getCareerGames()
    {
        return _careerGames;
    }
    public double computeTeamWinningAVG()
    {
        return((double)_careerWins/_careerGames);
    }
    public String toString()
    {
        String s=super.toString();
        s=s+"\ncareerWins"+_careerWins+"\ncareerGames"+_careerGames;
        return s;
    }
}


abstract class employee 
{
    private String _name; //player inheriets these three data members
    private double _salary;
    private int _years;
    
   public employee(String name,double salary,int years)
    {
        _name=name;
        _salary=salary;
        _years=years;
    }
   public String getName()
   {
       return _name;
   }
   public double getSalary()
   {
       return _salary;
   }
   public int getYears()
   {
       return _years;
   }
   public String toString()
   {
       String s="";
       s=s+"\n\nname"+_name+"\nsalary"+_salary+"\nyears"+_years;
       return s;
   }
           
}


abstract class player extends employee
{
    private int _games;
   
    public player(String name,double salary,int years,int games)
    {
        super(name,salary,years);
        _games=games;
    }
    public int getGames()
    {
        return _games;
    }
    public int getHits()
    {
        return 0;
    }
    public int getNumBats()
    {
        return 0;
    }
    public double getInnings()
    {
        return 0;
    }
    public int getHomeRuns()
    {
        return 0;
    }
    public int getEarnedRuns()
    {
        return 0;
    }
    public int getStrikeOuts()
    {
        return 0;
    }
    abstract double getValue();
    public String toString()
    {
        String s=super.toString();
        s=s+"\ngames"+_games;
        return s;
    }
    
}

  
class pitcher extends player
{
   private double _innings;
   private int _earnedRuns;
   private int _strikeOuts;
   
   public pitcher(double innings,int earnedRuns,int strikeOuts,String name,
           double salary,int years,int games)
   {
       super(name,salary,years,games);
       _innings=innings;
       _earnedRuns=earnedRuns;
       _strikeOuts=strikeOuts;
   }
   public double getInnings()
   {
       return _innings;
   }
   public int getEarnedRuns()
   {
       return _earnedRuns;
   }
   public int getStrikeOuts()
   {
       return _strikeOuts;
   }
   public double ERA()
   {
       return (9*_earnedRuns/_innings);
   }
   public double getValue()
   {
       return (((ERA()-2)/3)+(_strikeOuts-200)/200);
   }
    public String toString()
    {
        String s=super.toString();
        s=s+"\ninnings"+_innings+"\nearnedRuns"+_earnedRuns+"\nstrikeOuts"
                +_strikeOuts;
        return s;
    }
           
}


class batter extends player
{
    private int _numBats;
    private int _numHits;
    private int _numHomeRuns;
    
    public batter(String name,double salary,int years,int games,int numBats,
            int numHits,int numHomeRuns)
    {
        super(name,salary,years,games);
        _numBats=numBats;
        _numHits=numHits;
        _numHomeRuns=numHomeRuns;
    }
    public int getNumBats()
    {
        return _numBats;
    }
    public int getNumHits()
    {
        return _numHits;
    }
    public int getNumHomeRuns()
    {
        return _numHomeRuns;
    }
    public double computeBattingAvg()
    {
        return ((double)_numHits/_numBats);
    }
    public double getValue()
    {
        return (((computeBattingAvg()-0.3)/0.3)+(_numHomeRuns-40)/40);
    }
    public String toString()
    {
        String s=super.toString();
        s=s+"\nnumBats"+_numBats+"\nnumHits"+_numHits+"\nnumHomeRuns"
                +_numHomeRuns;
        return s;
    }
}


public class Program5 {

    public static Scanner kb=new Scanner(System.in);
    public static void main(String[] args) {
        String name="Chris";
        double salary=40;
        int years=20;
        int careerWins=2;
        int careerGames=3;
        manager manage=new manager(name,salary,years,careerWins,careerGames);
        
        pitcher pitcher1=new pitcher(3,4,5,"john",2102,6,5);
        pitcher pitcher2=new pitcher(9,5,28,"brad",2902,7,5);
        batter batter1=new batter("joe",2568,5,34,345,456,23);
        batter batter2=new batter("don",2588,5,38,5345,496,93);
        
        team team1=new team(manage);
        team team2=new team(manage);
        
        team2.addPlayer(pitcher1);
        team2.addPlayer(pitcher2);
        team2.addPlayer(batter1);
        team2.addPlayer(batter2);
        
        int pick;
        int option;
        
        do
        {
            
            System.out.println("Pick a team that you want tinker around"
                    + " with...");
            do
            {
                System.out.println("(1) The Oreo's players:0\n(2) Captain Crunchers"
                    + " two pitcher, two batters\n(3) Quit ");
                pick=kb.nextInt();
                
                if(pick<1 || pick>3)
                {
                    System.out.println("Please enter 1,2 or 3.");
                }
            }while(pick<1 || pick>3);
            
            if(pick!=3)
            {
                if(pick==1)
                {
                    System.out.println("You need a team manager.");
                    toggleOptions(team1,8);
                }
                do
                {   do
                    {
                        menu();

                        option=kb.nextInt();
                        if(option<1 || option>17)
                        {
                            System.out.println("please enter a number between 1 and 17.");
                        }

                    }while(option<1 || option>17);
                    
                if(option==17)
                    {
                        pick=3;
                    }
                    else
                    {
                        if(pick==1)
                        {
                            toggleOptions(team1,option);
                        }
                        if(pick==2)
                        {
                            toggleOptions(team2,option);
                        }
                    }

                }while(option !=16 && option!=17);
            }
            
        }while(pick !=3 );
        
        System.out.println("GoodBye.");
    }
    public static void menu()
    {
         System.out.println("Pick one of the following options...");
                System.out.println("(1)get number of batters.\n(2)get number of "
                        + "pitchers.\n(3)get manager.\n(4)get specific player.\n(5)"
                        + "get number of players.\n(6)add player.\n(7)delete "
                        + "player.\n(8)replace manager.\n(9)compute batting AVG.\n"
                        + "(10)compute homeruns.\n(11)compute ERA.\n(12)compute "
                        + "strike outs.\n(13)compute salary.\n(14)compute team "
                        + "value.\n(15)return a string that summerises everything."
                        + "\n(16)switch teams.\n(17)quit.");
    }
    public static void toggleOptions(team Team,int option)
    {
        if(option==1)
        {
            System.out.println(Team.getNumberBatters());
        }
        else if(option==2)
        {
            System.out.println(Team.getNumberPitchers());
        }
        else if(option==3)
        {
            System.out.println(Team.getManager());                              //check
        }
        else if (option==4)
        {
            String p;
            System.out.println("Enter the name of the player.");
            p=kb.next();
            Team.getSpecificPlayer(p);
        }
        else if (option ==5)
        {
            System.out.println(Team.getNumberOfPlayers());
        }
        else if (option==6)
        {
            int position,years,earnedRuns,strike,games,bats,hits,homeRuns;
            String name;
            double salary,innings;
            
            System.out.println("Enter the name of the player.");
            name=kb.next();
            
            System.out.println("Enter salary of player.");
            salary=kb.nextDouble();
            
            System.out.println("The # of years the player has played.");
            years=kb.nextInt();
            
            System.out.print("Enter the number of games the player has"
                    + " played.");
            games=kb.nextInt();
            
            do
            {
                System.out.println("Select position:");
                System.out.println("(1)pitcher\n(2)batter");
                
                position=kb.nextInt();
                
                if(position !=1 && position !=2)
                {
                    System.out.println("Select 1 or 2.");
                }

            }while(position !=1 && position !=2);
            
            if(position==1)
            {
                System.out.println("Enter the # of innings the pitcher"
                        + " has played");
                innings=kb.nextDouble();
                
                System.out.println("Enter the # of earned runs of the"
                        + " pitcher.");
                earnedRuns=kb.nextInt();
                
                System.out.println("Enter the # of strike outs the pitcher "
                        + "has.");
                strike=kb.nextInt();
                
                pitcher p=new pitcher(innings,earnedRuns,strike,name,salary,
                        years,games);
                Team.addPlayer(p);
                
            }
            else{
                System.out.println("Enter the # of bats the batter"
                        + " has bat");
                bats=kb.nextInt();
                
                System.out.println("Enter the # of home runs of the"
                        + " batter.");
                homeRuns=kb.nextInt();
                
                System.out.println("Enter the # of hits the batter "
                        + "has.");
                hits=kb.nextInt();
                
                batter b=new batter(name,salary,years,games,bats,hits,homeRuns);
                Team.addPlayer(b);
            }
        
        }
        else if(option==7)
        {
            String name;
            System.out.println("Enter the name of the player you wish to"
                    + " remove.");
            name=kb.next();
            Team.deletePlayer(name);
        }
        else if(option==8)
        {
            String name;
            double salary;
            int years,careerWins,careerGames;
            
            System.out.println("Enter the name of the new manager.");
            name=kb.next();
            
            System.out.println("Enter the salary");
            salary=kb.nextDouble();
            
            System.out.println("Enter the years");
            years=kb.nextInt();
            
            System.out.println("Enter the career wins");
            careerWins=kb.nextInt();
            
            System.out.println("Enter career games");
            careerGames=kb.nextInt();
            
            manager manage=new manager(name,salary,years,careerWins,
                    careerGames);
                  
            Team.replaceManager(manage);
        }
        else if(option==9)
        {
            System.out.println(Team.computeBattingAVG());
        }
        else if(option==10)
        {
            System.out.println(Team.computeHomeRuns());
        }
        else if(option==11)
        {
            System.out.println(Team.computeERA());
        }
        else if(option==12)
        {
            System.out.println(Team.computeStrikeOuts());
        }
        else if(option==13)
        {
            System.out.println(Team.computeSalary());
        }
        else if(option==14)
        {
            System.out.print(Team.computeTeamValue());
        }
        else if(option==15)
        {
            System.out.println(Team.toString());
        }
        else
        {
            
        }
    }
            
    
}
