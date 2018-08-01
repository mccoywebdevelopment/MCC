
package program.pkg4;

import java.util.Scanner;
import java.util.Random;

class Stack
{
    private Deque _stack;
    
    public Stack()
    {
        _stack=new Deque();        
    }
    public void push(Object p)
    {
        _stack.insertOnBack(p);
    }
    public Object pop()
    {
        return _stack.deleteFromBack();
    }
    public boolean isEmpty()
    {
        return _stack.isEmpty();
    }
     public String toString()
    {
        return _stack.toString();
    }
    public String toStore()
    {
        return _stack.toStore();
    }
            
}
class Queue
{
    private Deque _queue;
    
    public Queue()
    {
        _queue=new Deque();
    }
    public void insert(Object q)
    {
        _queue.insertOnFront(q);
    }
    public Object delete()
    {
        return _queue.deleteFromBack();
    }
    public boolean isEmpty()
    {
        return _queue.isEmpty();
    }
    public String toString()
    {
        return _queue.toString();
    }
    public String toStore()
    {
        return _queue.toStore();
    }
}
class customer
{
    private int _id;
    private String _name;
    
    public customer(String name, int id)
    {
        _name=name;
        _id=id;
    }
    public int get_ID()
    {
        return _id;
    }
    public String get_name()
    {
        return _name;
    }       
    public String toString()
    {
        return "Customer - name = " +_name + "ID" +_id;
    }
    
}
class Deque
{
    private Object [] _deque;
    private int _Size;
    private static final int ALLOC=100;
    private int front;
    private int back;
    
    public Deque()
    {
        _deque=new Object [ALLOC];
        front=(int) (Math.ceil(ALLOC/2));
        back=front+1;
        _Size=0;
    }
    public void insertOnFront(Object f) //FIXXX the error on phone
    {
         //System.out.println("Front1:"+front);
        
         if (_Size==_deque.length-1)                                             
        {

            Object[] newdeq=new Object[_deque.length*2];
            if(front<back)
            {
                for(int ix=front+1;ix<back;++ix)
                {
                    newdeq[ix]=_deque[ix];
                }

            }
            else
            {
                for(int ix=front+1;ix<_deque.length;++ix)
                {
                    newdeq[ix]=_deque[ix];
                }

                for(int ix=0;ix<back;++ix)
                {
                    newdeq[ix]=_deque[ix];
                }
            }
            _deque=newdeq;
        }
        //System.out.println("Front2:"+front);
        
        if(front<0)
        {
            _deque[_deque.length-1]=f; 
            front=_deque.length-2;
            
        }
        else
        {
            _deque[front]=f;
            front=front-1;
        }
        _Size=_Size+1;
        //System.out.println("Front3:"+front);
    }
    
    public void insertOnBack(Object b)
    {
        if (_Size==_deque.length)                                             
        {

            Object[] newdeq=new Object[_deque.length*2];
            if(front<back)
            {
                for(int ix=front+1;ix<back;++ix)
                {
                    newdeq[ix]=_deque[ix];
                }

            }
            else
            {
                for(int ix=front+1;ix<_deque.length;++ix)
                {
                    newdeq[ix]=_deque[ix];
                }

                for(int ix=0;ix<back;++ix)
                {
                    newdeq[ix]=_deque[ix];
                }
            }
            _deque=newdeq;
        }
        
        if(back==_deque.length-1)
        {
            _deque[0]=b;
            back=1;
            
        }
        else
        {
            _deque[back]=b;
            back=back+1;
        }
        _Size=_Size+1;
    }
    
    public Object deleteFromFront()
    {
        if(isEmpty())
        {
            return null;
        }
        
        Object getDelete=_deque[front+1];
        _deque[front+1]=null;
        front=front+1;
        _Size=_Size-1;
        return getDelete;
        
    }
    
    public Object deleteFromBack ()
    {
        if(isEmpty())
        {
            return null;
        }
        
        Object getDelete=_deque[back-1];
        _deque[back-1]=null;
        back=back-1;
        _Size=_Size-1;
        return getDelete;
    }
    
    public boolean isEmpty()
    {
        return(_Size==0);
    }
   
    public String toString()     //FIXXXX!!!!!!!!
    {
        String s="";
        
        s=s+"\n--front--\n";
        if(front<back)
        {
            for(int ix=front+1;ix<back;++ix)
            {
                s=s+""+_deque[ix]+"\n";
            }
               
        }
        else
        {
            for(int ix=front+1;ix<_deque.length;++ix)
            {
                s=s+""+_deque[ix]+"\n";
            }
  
            for(int ix=0;ix<back;++ix)
            {
                s=s+""+_deque[ix]+"\n";
            }
        }
        s=s+"\n--back--\n";
        return s;
    }
    
    public String toStore()
    {
        String s="";
        s=s+"Front:";
        for(int ix=0;ix<_deque.length;++ix)
        {
            s=s+""+"Index["+ix+"]"+_deque[ix]+"\n";
        }
        s=s+"Back";
        return s;
    }  
}
class StarWarsHero
{
    
    private String _name;	
    private String _type;   
    private double _height;   
    private int _brains;
    private int _darkSide;
    private int _jediPowers;
    private int _battleSkills;
    private int _forceFactor;
 
    public StarWarsHero(String name, String type, double height,
              int brains, int darkSide, int jediPowers,
              int battleSkills, int forceFactor )
    { 
        _name = name;
        _type = type;
       _height = height;
       _brains = brains;
        _darkSide = darkSide;
        _jediPowers = jediPowers;
       _battleSkills = battleSkills;
        _forceFactor = forceFactor;
    }
    public String getName()
    {    
        return _name;
    }
    public String getType()
    {      
        return _type;  
    }
    public double getHeight()
    {      
        return _height; 
    }
    public int getBrains()
    {
        return _brains;
    }
    public int getDarkSide()
    {
        return _darkSide;
    }

    public int getJediPowers()
    {
        return _jediPowers;
    }

    public int getBattleSkills()
    {
        return _battleSkills;
    }

    public int getForceFactor()
    {
        return _forceFactor;
    }
  
    public String toString()
    {
        return "[" + _name + " : " + _type + "]\n" + 
        "(a) Height: " + _height + " (b) Brains: " + _brains + "\n" +
        "(c) Dark Side: " + _darkSide + " (d) Jedi Powers: " + 
                _jediPowers + "\n" +
        "(e) Battle Skills: " + _battleSkills + " (f) Fear Factor: "
                + _forceFactor + "\n";
    }
}
class cardSize
{
    public int player1Size=0;
    public int player2Size=0;
}
class StarWarsHeroArray //creates the cards
{
    private StarWarsHero[] _cards;

    public StarWarsHeroArray()
    {
        _cards = new StarWarsHero[]
        {   
// name, type, height, brains, darkSide, jediPowers, battleSkills, forceFactor
            new StarWarsHero("Anakin Skywalker", "Jedi",          1.85, 15, 18,
                    75, 55, 4),
            new StarWarsHero("Commander Cody",   "Republic",      1.83, 12, 20,
                    2, 39, 1),
            new StarWarsHero("Count Dooku",      "Separatist",    1.93, 18, 21,
                    70, 55, 2),

            new StarWarsHero("Darth Maul",       "SithLord",      1.75,  9, 24,
                    80, 48, 1),
            new StarWarsHero("General Grievous", "Separatist",    2.16, 17, 20,
                    50, 60, 1),
            new StarWarsHero("Ki-Adi-Mundi",     "Jedi",          1.98, 17,  3,
                    85, 46, 3),

            new StarWarsHero("Jango Fett",       "BountyHunter",  1.83, 11, 20,
                    17, 49, 1),
            new StarWarsHero("Kit Fisto",        "Jedi",          1.96, 13,  4,
                    81, 44, 2),
            new StarWarsHero("Lama Su",          "Hamindan",      2.29, 13,  5,
                    1, 12, 1),

            new StarWarsHero("Mace Windu",       "Jedi",          1.88, 18,  2,
                    95, 55, 3),
            new StarWarsHero("Mas Amedda",       "Republic",      1.96, 10,  9, 
                    1, 14, 3),
            new StarWarsHero("Poggle the Lesser","Separatist",    1.75,  8, 14,
                    1,  9, 2),

            new StarWarsHero("Qui-Gon Jinn",     "Jedi",          1.93, 19,  2,
                    65, 41, 1),
            new StarWarsHero("Senator Amidala",  "Republic",      1.65, 17,  2,
                    30, 40, 2),
            new StarWarsHero("Tarfful",          "Wookee",        2.34,  8,  6,
                    10, 52, 1),

            new StarWarsHero("Boba Fett",        "BountyHunter",  1.83, 11, 20,
                    17, 49, 4),
            new StarWarsHero("C-3PO",            "Droid",         1.67, 19,  0,
                    0,  8, 6),
            new StarWarsHero("Chewbacca",        "RebelAlliance", 2.28, 12,  5,
                    10, 55, 4),

            new StarWarsHero("Darth Vader",      "GalacticEmpire",2.03, 16, 22,
                    82, 55, 4),
            new StarWarsHero("Emperor Palatine", "Empire",        1.73, 14, 25,
                    95, 25, 5),
            new StarWarsHero("Greedo",           "BountyHunter",  1.73,  8, 18,
                    2, 30, 2),
			
            new StarWarsHero("Han Solo",         "RebelAlliance", 1.83, 13,  6,
                    4, 50, 3),
            new StarWarsHero("Jaba the Hutt",    "Criminal",      1.75, 13, 20,
                    0, 10, 3),
            new StarWarsHero("Lando Calrissian", "RebelAlliance", 1.78, 15,  8,
                    6, 48, 2),

            new StarWarsHero("Luke Skywalker",   "Jedi",          1.72, 15,  4,
                    90, 43, 4),
            new StarWarsHero("Mon Mothma",       "RebelAlliance", 1.7,  18,  0,
                    30, 20, 2),
            new StarWarsHero("Obi-Wan Kenobi",   "Jedi",          1.75, 18,  1,
                    80, 26, 6),

            new StarWarsHero("Leia Organa",      "RebelAlliance", 1.52, 17,  1,
                    50, 38, 4),
            new StarWarsHero("R2-D2",            "Droid",         1.09, 14,  0,
                    0, 14, 6),
            new StarWarsHero("Wicket W Warrick", "Ewok",          0.8,  14,  2,
                    20,  1, 1)            
        };
    }

    public StarWarsHero[] getCards()
    {
        return _cards;
    }

}

    public class Program4 {
        
    public static Scanner kb=new Scanner(System.in);
    public static void main(String[] args)
    {
        Random rand = new Random();
        
        int choice;
        do
        {
            do
            {
                menu();
                choice=kb.nextInt();
                if(choice<1 || choice>3)
                {
                    System.out.println("Wrong input please select 1,2,or 3.");
                }

            }while(choice<1 || choice>3);


            if(choice==1)
            {
                option1();
            }
            else if(choice==2)
            {
                Top_trump();
            }
            else
            {
                System.out.println("Goodbye.");
            }
        }while(choice !=3);
    }
    public static void option1()
     {
            String s;
            char again;
            int option,selected;

            Stack stest=new Stack();
            Queue qtest=new Queue();
            customer ctest=new customer("Fred",123);
            Deque dtest=new Deque();


            do
            {
                System.out.println("Select one of thefollowing to manipulate\n(1)"
                        + " Deque of customers\n(2) Queue of Stings\n"
                        + "(3) Stack of Integers\n(4) Exit to main menu.");
                do
                {
                    selected=kb.nextInt();
                    if(selected<1 || selected>4)
                    {
                        System.out.println("Please enter 1,2 or 3.\n");
                    }

                }while(selected<1 || selected>4);

                if(selected !=4)
                {        
                    System.out.println("Please select one of the following "
                            + "actions to "
                    + "manipulate it. ");
                }


                if(selected==1)
                {
                    do
                    {
                        display_options_deque();
                        option=kb.nextInt();
                        if(option<1 || option>9)
                        {
                            System.out.println("\nInvalid input please "
                               + "select one of the following.\n");
                        }
                    }while(option<1 || option>9);

                    toggle_options_customers(option,ctest,dtest);
                }
                else if(selected==2)
                {
                    do
                    {
                        display_options_queue();
                        option=kb.nextInt();
                        if(option<1 || option>7)
                        {
                            System.out.println("\nInvalid input please "
                               + "select one of the following.\n");
                        }
                    }while(option<1 || option>7);

                    toggle_options_queue(option,qtest);

                }
                else if(selected==3)
                {
                    do
                    {
                        display_options_stack();
                        option=kb.nextInt();
                        if(option<1 || option>7)
                        {
                            System.out.println("\nInvalid input please "
                               + "select one of the following.\n");
                        }
                    }while(option<1 || option>7);

                    toggle_options_stack(option,stest);
                }
            }while(selected!=4);

        }
    public static void display_options_deque()
    {
        System.out.println("(1) Insert on front \n(2) Insert on back\n"
                + "(3) Delete from front\n(4) Delete from back\n"
                + "(5) Ask if the deque is empty\n(6) Return a string "
                + "summerizing the contents of the deque(from front to back)\n"
                + "(7) Display the entire contents of the deque (array index 0 to"
                + " length-1)\n(8) Construct a new deque.\n(9)To quite");

    }
    public static void display_options_queue()
    {
        System.out.println("(1) Insert String \n(2) Delete String\n"            
                + "(3) Ask if the deque is empty\n(4) Return a string "
                + "summerizing the contents of the queue(from front to back)\n"
                + "(5) Display the entire contents of the queue (array index 0 to"
                + " length-1)\n(6) construct a new queue.\n(7) To quite");
    }
    public static void display_options_stack()
    {
         System.out.println("(1) Insert number \n(2) Delete number\n"            
                + "(3) Ask if the stack is empty\n(4) Return a string "
                + "summerizing the contents of the stack(from top to last)\n"
                + "(5) Display the entire contents of the stack (array index 0 to"
                + " length-1)\n(6) construct a new stack. \n(7) To quite");
    }
    public static void toggle_options_customers(int option,customer ctest,
            Deque dtest)
        {
            boolean redo;
            if(option==1)
            {
                do
                {
                    System.out.println("Enter the name of the customer.");
                    String name=kb.next();
                    System.out.println("Enter the ID of the customer.");
                    int id=kb.nextInt();
                    ctest=new customer(name,id);
                    dtest.insertOnFront(ctest);
                    //System.out.println(dtest);
                    redo=Redo();
                }while(redo);
            }
            else if(option==2)
            {
                do
                {
                    System.out.println("Enter the name of the customer.");
                    String name=kb.next();
                    System.out.println("Enter the ID of the customer.");
                    int id=kb.nextInt();
                    ctest=new customer(name,id);
                    dtest.insertOnBack(ctest);
                    System.out.println(dtest);
                    redo=Redo();
                }while(redo);
            }
            else if(option==3)
            {
                do
                {
                   customer temp;

                   temp=(customer)dtest.deleteFromFront();
                   if(temp==null)
                   {
                       System.out.println("It's empty.");
                   }
                   else
                   {

                        System.out.println(temp.get_ID());
                   }

                   redo=Redo(); 
                }while(redo);
            }
            else if(option==4)
            {
                do
                {
                   Object temp;
                   temp=dtest.deleteFromBack();
                   if(temp==null)
                   {
                       System.out.println("It's empty.");
                   }
                   redo=Redo(); 
                }while(redo);
            }
            else if(option==5)
            {
                if(dtest.isEmpty())
                {
                    System.out.println("It's empty.");
                }
                else
                {
                    System.out.println("It's not empty.");
                }

            }
            else if(option==6)
            {
                System.out.println(dtest);
            }
            else if (option==7)
            {
                System.out.println(dtest.toStore());
            }
            else if(option==8)
            {
                while(!dtest.isEmpty())
                {
                    dtest.deleteFromBack();
                }

            }
            else
            {

            }
        }
    public static boolean Redo()
    {
        char again;
        boolean redo;
        System.out.println("\n\n Want to try again (y/n)?");
        do
        {
            again=kb.next().charAt(0);              
            if(again!= 'y' && again !='n')
                System.out.println("Please enter (y/n).");
        }while(again!= 'y' && again !='n');
        redo=(again=='y');
        return redo;
       
    }
    public static void menu()
    {
        System.out.println("Please select one of the following options.");
        System.out.println("(1) Test the tools\n(2) Play \"Top Trump\"\n"
                + "(3)Quit\n\nPlease select from one of the options above.");
    }
    public static void Top_trump()
    {   boolean redo=true;
        do
        {
        boolean win=true;
        Random rand = new Random();
        Queue deck=new Queue();
        
        StarWarsHeroArray array=new StarWarsHeroArray();
        StarWarsHero[] tlist=array.getCards();
        
        Queue player1=new Queue();
        Queue player2=new Queue();
        
        Queue tie=new Queue();
        StarWarsHero card1;
        
        StarWarsHero card2;
        cardSize size=new cardSize();
        
        char pick;
        char quit='n';
        StarWarsHero temp;
        int index1,index2;
       
        for(int i=0;i<tlist.length;++i)
        {
               index1=rand.nextInt(tlist.length-1)+1;
               temp=(StarWarsHero) tlist[index1];
               index2=rand.nextInt(tlist.length-1)+1;
               tlist[index1]=tlist[index2];
               tlist[index2]=temp;
        } 
        
        for(int i=0;i<tlist.length;++i)
        {
            deck.insert(tlist[i]);
        }
        
         while (!deck.isEmpty())
        {
            player1.insert(deck.delete());
            size.player1Size=size.player1Size+1;
            
            if (!deck.isEmpty()) 
            {
              player2.insert(deck.delete());
              size.player2Size=size.player2Size+1;
            }
                
        }
        
        while(size.player1Size>0 && size.player2Size>0 && quit=='n')
        {
            card1=(StarWarsHero)player1.delete();
            size.player1Size=size.player1Size-1;

            card2=(StarWarsHero)player2.delete();
            size.player2Size=size.player2Size-1;
            
            System.out.println("\n\n\nYour topmost card is:");
            System.out.println(card1);
            
            if(win)
            {
                pick=userPick(card1);
            }
            else
            {
                System.out.println("You lost so the other player get "
                         + "to pick the category.");
              
                pick=player2Turn();
            }
            
            win=playerTurn(pick,card1,card2,player1,player2,tie,size,win);
            if(size.player1Size<1 || size.player2Size<1)
            {
                redo=gameOver(size);
            }
        }
        }while(redo);
        System.out.println("Goodbye.");
  
    } 
    public static void toggle_options_stack(int option,Stack stest)
    {
        boolean redo;
        if(option==1)
        {
            do
            {
                System.out.println("Enter a number.");
                int n=kb.nextInt();
                stest.push(n);
                redo=Redo();
            }while(redo);
        }
        else if(option==2)
        {
            Object temp;
            temp=stest.pop();
               if(temp==null)
               {
                   System.out.println("It's empty.");
               }
               else
               System.out.println(temp);
        }
        else if(option==3)
        {
             if(stest.isEmpty())
            {
                System.out.println("It's empty.");
            }
             else
             {
                 System.out.println("It's not empty.");
             }
        }
        else if(option==4)
        {
            System.out.println(stest.toString());
        }
        else if(option==5)
        {
            System.out.println(stest.toStore());
        }
        else if(option==6)
        {
            while(!stest.isEmpty())
            {
                stest.pop();
            }
        }
       
        
    }
    
    public static void toggle_options_queue(int option,Queue stest)
    {
        boolean redo;
        if(option==1)
        {
            do
            {
                System.out.println("Enter a string.");
                String n=kb.next();
                stest.insert(n);
                redo=Redo();
            }while(redo);
        }
        else if(option==2)
        {
            Object temp;
            temp=stest.delete();
               if(temp==null)
               {
                   System.out.println("It's empty.");
               }
               else
               System.out.println(temp);
        }
        else if(option==3)
        {
             if(stest.isEmpty())
            {
                System.out.println("It's empty.");
            }
             else
             {
                 System.out.println("It's not empty.");
             }
        }
        else if(option==4)
        {
            System.out.println(stest.toString());
        }
        else if(option==5)
        {
            System.out.println(stest.toStore());                              //Ask if this is right
        }
        else if(option==6)
        {
            while(!stest.isEmpty())
            {
                stest.delete();
            }
        }
    }
    public static char player2Turn()
    {    
        Random rand = new Random();
        char c;
        c=(char)('a'+rand.nextInt(6));
        return c;
    }
    public static boolean playerTurn(char pick,StarWarsHero card1,StarWarsHero 
            card2,Queue player1,Queue player2,Queue tie,cardSize size,boolean win)
    {
        double power1D,power2D;
        int power1;
        int power2;
        
         if(pick=='a')
        {
            System.out.println("Opponent's Height:");
            System.out.println(card2.getHeight());
            power1D=card1.getHeight();
            power2D=card2.getHeight();
            if(power1D<power2D)
            {
                power1=0;
                power2=1;
            }
            else if(power1D>power2D)
            {
                power1=1;
                power2=0;
            }
            else
            {
                power1=0;
                power2=0;
            }
        }
        else if(pick=='b')
        {
            System.out.println("Opponent's Brains:");
            System.out.println(card2.getBrains());
            power1=card1.getBrains();
            power2=card2.getBrains();
        }
        else if(pick=='c')
        {
            System.out.println("Opponent's Dark Side:");
            System.out.println(card2.getDarkSide());
            power1=card1.getDarkSide();
            power2=card2.getDarkSide();
        }
        else if(pick=='d')
        {
            System.out.println("Opponent's Jedi Powers:");
            System.out.println(card2.getJediPowers());
            power1=card1.getJediPowers();
            power2=card2.getJediPowers();
        }
        else if(pick=='e')
        {
           System.out.println("Opponent's Battle Skills:");
           System.out.println(card2.getBattleSkills());
           power1=card1.getBattleSkills();
           power2=card2.getBattleSkills();
        }
        else
        {
           System.out.println("Opponent's Fear Factor:");
           System.out.println(card2.getForceFactor());
           power1=card1.getForceFactor();
           power2=card2.getForceFactor();
        }
         
         if(power1<power2)
         {
             System.out.println("You lost.");
             player2.insert(card1);
             player2.insert(card2);
             size.player1Size=size.player1Size-1;
             size.player2Size=size.player2Size+2;
             if(!tie.isEmpty())
             {
                 Object temp;
                 System.out.println("Your opponent won the tie.");
                 while(!tie.isEmpty())
                 {
                    temp=tie.delete();
                    player2.insert(temp);
                    size.player2Size=size.player2Size+1;
                 }
             }
             return win=false;
         }
         else if(power1>power2)
         {
            System.out.println("You won.");
            player1.insert(card1);
            player1.insert(card2);
            size.player1Size=size.player1Size+2;
            size.player2Size=size.player2Size-1;
             if(!tie.isEmpty())
             {
                 Object temp;
                 System.out.println("You won the tie.");
                 while(!tie.isEmpty())
                 {
                    temp=tie.delete();
                    player1.insert(temp);
                    size.player1Size=size.player1Size+1;
                 }
             }
            return win=true;
         }
         else
         {
            System.out.println("It's a Tie!");
            if(size.player1Size>0 && size.player2Size>0)
            {
            
            tie.insert(card1);
            tie.insert(card2);

            card1=(StarWarsHero)player1.delete();
            size.player1Size=size.player1Size-1;
            
            card2=(StarWarsHero)player2.delete();
            size.player2Size=size.player2Size-1;
            }
            
         }
         return win;
         
    }
    public static char userPick(StarWarsHero card1)
    {
        char pick;
        System.out.println("Please select a category.");
        do
        {
            pick=kb.next().charAt(0); 
            if(pick!='a' && pick!='b' && pick!='c' && 
                    pick!='d' && pick!='e' && pick!='f')
            {
                System.out.println("Please select the correct input "
                        + "hint: abcd..");
            }
        }while(pick!='a' && pick!='b' && pick!='c' && 
                    pick!='d' && pick!='e' && pick!='f');
        return pick;
    }
    public static char quit()
    {
        char quit;
        System.out.println("Do you want to quite(y/n)?");
        do
        {
            quit=kb.next().charAt(0);              
            if(quit!= 'y' && quit !='n')
                System.out.println("Please enter (y/n).");
        }while(quit!= 'y' && quit !='n');
        return quit;
        
    }
    public static boolean gameOver(cardSize size)
    {
        boolean redo;
        if(size.player1Size>size.player2Size)
        {
            System.out.println("You won the game!");
        }
        else if(size.player2Size>size.player1Size)
        {
            System.out.println("You lost the game.");
        }
        else
        {
            System.out.println("What the there's a tie?");
        }
        
        return redo=Redo();
    }     
}
    