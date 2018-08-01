package program.pkg7;
import java.util.Scanner;
import java.util.*;
import java.util.Random;

interface keyComparable
{

    public int keyCompareTo(keyComparable other);

    public String toStringKey();
    
}
class table
{
    private treeNode _root;
    
    public table()
    {
        _root=null;
    }
    public keyComparable search(keyComparable key)
    {
        return search(_root,key);
    }
    private keyComparable search(treeNode myRoot,keyComparable key)
    {
        if(myRoot==null)
        {
            return null;
        }
        else
        {
            int comp=key.keyCompareTo(myRoot.data);
            if(comp==0)
            {
                return myRoot.data;
            }
            else if(comp<0)
            {
                return search(myRoot.left,key);
            }
            else
            {
                return search(myRoot.right,key);
            }
        }
    }
    public void insert(keyComparable item)
    {
        _root=insertRoot(_root,item);
    }
    private treeNode insertRoot(treeNode myRoot,keyComparable item)
    {
        if(myRoot==null)
        {
            myRoot=new treeNode();
            myRoot.data=item;
            myRoot.left=myRoot.right=null;
            return myRoot;
        }
        else
        {
            int comp=item.keyCompareTo(myRoot.data);
            
            if(comp<0)
            {
                myRoot.left=insertRoot(myRoot.left,item);
            }
            else if(comp>0)
            {
                myRoot.right=insertRoot(myRoot.right,item);
            }
            return myRoot;
        }
        
    }
    private treeNode getLeast(treeNode myRoot)
    {
        treeNode result;
        if(myRoot.left==null)
        {
            result=myRoot;
            myRoot=null;
            return result;
        }
        else
        {
            return getLeast(myRoot.left);
        }
    }
    private treeNode getMax(treeNode myRoot)
    {
        treeNode result;
        if(myRoot.right==null)
        {
            result=myRoot;
            myRoot=null;
            return result;
        }
        else
        {
            return getMax(myRoot.right);
        }
    }
    public treeNode delete(keyComparable key)
    {
        return delete(_root,key);
    }
    private treeNode delete(treeNode myRoot,keyComparable key)
    {  
        if(myRoot==null)
        {
            return null;
        }
        int comp=key.keyCompareTo(myRoot.data);
        if(comp==0)
        {
            if(myRoot.left==null && myRoot.right==null)
            {
                return null;
            }
            else if(myRoot.left==null&&myRoot.right!=null)
            {
                return myRoot.right;
            }
            else if(myRoot.right==null&&myRoot.left!=null)
            {
                return myRoot.left;
            }
            else
            {
                treeNode replace=getMax(myRoot.left);
                myRoot.data=replace.data;
                myRoot.left=delete(myRoot.left,replace.data);
                return myRoot;
            }   
        }
        else if(comp<0)
        {
            
            myRoot.left= delete(myRoot.left,key);
            return myRoot;
            
        }
        else
        {   
           
            myRoot.right= delete(myRoot.right,key);
            return myRoot;
            
        }  
    }
    public double getLevelAVG()
    {
       
        double result=0;
        if(getSize() == 0)
        {
            return 0;
        }
        else
        {
            result=(double)sumOfLevels(_root,1)/getSize();
            //System.out.println(sumOfLevels(_root,1));
        }
        return result;
        
    }
    private int sumOfLevels(treeNode myRoot,int level)
    {
        int result=0;
        if(myRoot ==null)
        {
            return 0;
        }
        else
        {
            result=result+level;
            result=result+sumOfLevels(myRoot.right,level+1);
            result=result+sumOfLevels(myRoot.left,level+1);
        }
        return result;
    }
    public int getSize()
    {
        return sizeRoot(_root);
    }
    private int sizeRoot(treeNode myRoot)
    {
        if(myRoot==null)
        {
            return 0;
        }
        else
        {
            return 1+sizeRoot(myRoot.left)+sizeRoot(myRoot.right);
        }
    }
    public int getHeight()
    {
        return height(_root);
    }
    private int height(treeNode myRoot)                                         //check
    {
        if(myRoot==null)
        {
            return 0;
        }
       return (1+Math.max(height(myRoot.left),height(myRoot.right)));
    }
    public String showTree()
    {
        
        return showTree(_root,0);
        
    }
    private String showTree(treeNode myRoot,int myLevel)
    {
        String s="";
        //s=s+"       level:"+myLevel+"\n";
        if(myRoot!=null)
        {
            s=s+showTree(myRoot.right,myLevel+1);
            for(int i=0;i<myLevel;++i)
            {
                s=s+"\t";
            }
            s=s+myRoot.data.toStringKey()+"\n";
            myLevel=0;
            s=s+showTree(myRoot.left,myLevel+1);
            s=s+"\n";
        }
        
        return s;
    }
    private String toString(treeNode myRoot)
    {
        String s="";
        if(myRoot!=null)
        {
            s=s+toString(myRoot.left);
            s=s+myRoot.data.toString();
            s=s+toString(myRoot.right);
        }
        return s;
    }
    public String toString()
    {
        String s="";
        s=s+toString(_root);
        
        return s;
    }
    
    
}
class treeNode 
{
    public keyComparable data;
    public treeNode left;
    public treeNode right;
}

class nbaPlayer extends nbaPlayerKey implements keyComparable
{
   private String _name;
   private double _scoringAVG;
   
   public nbaPlayer(String name,double scoringAVG,int jerseyNumber,
           String teamName)
   {
       super(jerseyNumber,teamName);
       _name=name;
       _scoringAVG=scoringAVG;
   }
   public String getName()
   {
       return _name;
   }
   public double getScoringAVG()
   {
       return _scoringAVG;
   }
   public String toString()
   {
       String s="";
       s=s+super.toString();
       s=s+_name+"  ";
       s=s+_scoringAVG+"\n";
       return s;
   }
   
}
class nbaPlayerKey implements keyComparable
{
    private int _jerseyNumber;
    private String _teamName;
    
    nbaPlayerKey(int number,String name)
    {
        _jerseyNumber=number;
        _teamName=name;
    }
    public int getJerseyNumber()
    {
        return _jerseyNumber;
    }
    public String getTeamName()
    {
        return _teamName;
    }
    public int keyCompareTo(keyComparable other)
    {
        if(other instanceof nbaPlayerKey)
        {
            nbaPlayerKey key=(nbaPlayerKey) other;
            
            if(key.getJerseyNumber()<_jerseyNumber)                             //if 0 compare team name.
            {
                return 1;
            }
            else if(key.getJerseyNumber()>_jerseyNumber)
            {
                return -1;
            }
            else
            {
                int result=_teamName.compareTo(key.getTeamName());            //check to see if its right.
                return result;
            }
        }
        
        return 0;
            
    }
    public String toStringKey()
    {
        String s="";
        s=s+_jerseyNumber+"  "+_teamName.substring(0,3)+"\n";
        return s;
    }
    public String toString()
    {
        String s="";
        s=s+_jerseyNumber+"  "+_teamName.substring(0,3)+"\n";
        return s;
    }
   
}
class keyComparableNumber implements keyComparable
{
    private int _number;
    
    public keyComparableNumber(int number)
    {
        _number=number;
    }
    public int getKeyComparableNumber()
    {
        return _number;
    }
    public int keyCompareTo(keyComparable other)
    {
        if(other instanceof keyComparableNumber)
        {
            keyComparableNumber key=(keyComparableNumber) other;
            
            if(key.getKeyComparableNumber()<_number)                             //if 0 compare team name.
            {
                return 1;
            }
            else if(key.getKeyComparableNumber()>_number)
            {
                return -1;
            }
        }
        else
        {
            return 0; 
        }
            return 0;
    }
    public String toStringKey()
    {
        String s="";
        s=s+_number;
        return s;
    }
}
public class Program7 {
    
    
   public static Scanner kb=new Scanner(System.in);
    public static void main(String[] args)
    {
        int option;
        do
        {
            System.out.println("Please select one of the following options.");
            System.out.println("1. test the tools of a binary search tree.");
            System.out.println("2. create several tables to calculate the worst case retrieval time");
            System.out.println("3. quit the program");
            option=kb.nextInt();
            
            if(option<1 || option >3)
            {
                System.out.println("Please enter 1,2 or 3.");
            }
            
            if(option==1)
            {
                optionOne();
            }
            else if(option==2)
            {
                optionTwo();
            }
        }while(option !=3 || option<1 || option >3 );
    }
    public static void optionTwo()
    {
        int number=16;
        Random generator=new Random();
        int height=0;
        double AVGlevel=0;
        for(int i=16;i<=32768;i=i*2)
        {
            
            for(int ix=0;ix<10;++ix)
            {
                table tree=new table();
                for(int ixx=0;ixx<i;ixx++)
                {
                    int temp=generator.nextInt();
                    keyComparableNumber num= new keyComparableNumber(temp);
                    tree.insert(num);
                }
                if(height<tree.getHeight())
                {
                    height=tree.getHeight();
                }
                //System.out.println(AVGlevel);
                AVGlevel=AVGlevel+tree.getLevelAVG();
                
               
            }
            
        AVGlevel=AVGlevel/10.0;
        System.out.print("The worst case performance:");
        System.out.println(height);
        System.out.print("The expected case performance:");
        System.out.println(AVGlevel);
        System.out.print("Size:");
        System.out.println(i);
        }
        
        
    
    }
    public static void optionOne() {
       int option;
       table tree=new table();
       do
       {
           System.out.println("Please select one of the following options...");
           System.out.println("1.  insert an item in the table.");
           System.out.println("2.  delete an item in the table.");
           System.out.println("3.  search an item in the table.");
           System.out.println("4.  get height of the tree..");
           System.out.println("5.  get size of the number of nodes.");
           System.out.println("6.  get the average level of nodes.");
           System.out.println("7.  display the contents of the tree in tree form.");
           System.out.println("8.  display the contents in order by their keys.");
           System.out.println("9.  initialize an empty table.");
           System.out.println("10. quit program.");
           System.out.println("11.Random player generator.");

           option=kb.nextInt();
           if(option<1 || option>11)
           {
               System.out.println("Please enter a number between one and eleven.");
           }

           if(option==1)
           {
               
               String teamName,name;
               int number;
               double score;
               System.out.println("Please enter the jersey number.");
               number=kb.nextInt();
               System.out.println("Please enter the scoring avg for that player.");
               score=kb.nextDouble();
               System.out.println("Please enter the team name.");
               teamName=kb.next();
               System.out.println("Please enter the name of the player.");
               name=kb.next();
               nbaPlayer player=new nbaPlayer(name,score,number,teamName);
               tree.insert(player); 
           }
           else if(option==2)
           {
               treeNode result=null;
               String teamName;
               int jerseyNumber;
               System.out.println("Please enter the name of team you wish to "
                       + "delete.");
               teamName=kb.next();
               System.out.println("Enter the jersey number of the player.");
               jerseyNumber=kb.nextInt();
               nbaPlayerKey key=new nbaPlayerKey(jerseyNumber,teamName);
               result=tree.delete(key);
               
           }
           else if(option==3)
           {
               String teamName;
               keyComparable result;
               int number;
               System.out.println("Please enter the jersey number.");
               number=kb.nextInt();
               System.out.println("Please enter the team name.");
               teamName=kb.next();
               nbaPlayerKey key=new nbaPlayerKey(number,teamName);
               result=tree.search(key);
               if(result==null )
               {
                   System.out.println("No match.");
               }
               else
               {
                   System.out.println("FOUND MATCH!");
                   System.out.println(result.toString());
               }
           }
           else if(option==4)
           {
               System.out.println(tree.getHeight());
           }
           else if(option==5)
           {
               System.out.println(tree.getSize());
           }
           else if (option==6)
           {
               System.out.println(tree.getLevelAVG());
           }
           else if(option==7)
           {
               System.out.println("\n\n");
               System.out.println(tree.showTree());
           }
           else if(option==8)
           {
               System.out.println(tree.toString());
           }
           else if (option==9)
           {
               table tree1=new table();
               tree=tree1;
           }
           else if(option==11)
           {
               randPlayer(tree);
           }
       }while(option!=10);
        
    }
    public static void randPlayer(table tree)
    {
        int num,jersey;
        double score;
        String team, name;
        
        System.out.println("Enter the team name.");
        team=kb.next();
        System.out.println("Enter the number of players.");
        num=kb.nextInt();
        Random rand = new Random();
        
        for(int i=0;i<num;++i)
        {
            jersey=rand.nextInt(135) + 1;
            score=rand.nextInt(345) + 1;
            name=returnString();
            nbaPlayer player=new nbaPlayer(name,score,jersey,team);
            tree.insert(player); 
            System.out.println(jersey);
            System.out.println(score);
            System.out.println(name);
            System.out.println(team);
             
        } 
    }
    public static String returnString()
    {
        String name;
        int num;
        Random rand = new Random();
        String[] name1 = { "Kr", "Ca", "Ra", "Mrok", "Cru",
         "Ray", "Bre", "Zed", "Drak", "Mor", "Jag", "Mer", "Jar", "Mjol",
         "Zork", "Mad", "Cry", "Zur", "Creo", "Azak", "Azur", "Rei", "Cro",
         "Mar", "Luk" };
        String[] name2 = { "air", "ir", "mi", "sor", "mee", "clo",
         "red", "cra", "ark", "arc", "miri", "lori", "cres", "mur", "zer",
         "marac", "zoir", "slamar", "salmar", "urak" };
        String[] name3 = { "d", "ed", "ark", "arc", "es", "er", "der",
         "tron", "med", "ure", "zur", "cred", "mur" };
   
         int pick=rand.nextInt(3) + 1;
         if(pick==1)
         {
             num=rand.nextInt(name1.length-1)+1;
             return name1[num];
         }
         else if(pick==2)
         {
             num=rand.nextInt(name2.length-1)+1;
             return name2[num];
         }
         else{
             num=rand.nextInt(name3.length-1)+1;
             return name3[num];
         }
         
    }
   

}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              