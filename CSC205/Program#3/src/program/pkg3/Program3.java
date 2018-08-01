
package program.pkg3;

/*Chris McCoy, This program is designed to process twitter data then the user 
can display the data, enter a key field such as a name to displays the fields 
that matches their input, and displays a histogram of the number of twitter 
followers.*/

import java.util.Scanner;
import java.io.*;

class Twitter_Data
{
    public String name;
    public String work;
    public double followers;
    public double wealth;
};
class calc
{
    public double smallest;
    public double biggest;
    public int decade;
    public double range;
    
};
public class Program3 {

   public static Scanner kb=new Scanner(System.in);
    public static void main(String[] args) {
        
    Twitter_Data[] tweet = new Twitter_Data[100];
        int num,option;
        num= loaddata (tweet);
        
        do
        {
            display_options();
            do
            {
                option=kb.nextInt();
                if(option !=1 && option!=2 && option!=3 && option!=4)
                {
                    System.out.println("Please enter 1,2,3 or 4.");
                }
            }while(option!=1 && option!=2 && option!=3 && option!=4);
            
            if(option==1)
            {
                display_data(tweet,num);
            }
            else if(option==2)
            {
                Selected_Record(tweet,num);
            }
            else if(option==3)
            {
                calc test=new calc();
                test=Compute_decade(tweet,num);
                histogram(tweet,num,test);
            }
            
        }while(option != 4);
        
    }   
    
    public static int loaddata(Twitter_Data [] tweet)
    {
        //System.out.println("Enter file name.");
        //String file=kb.next();
        int ix=0;
        try
        {
           File file =new File("C:\\Users\\ASUS\\Documents\\TwitterData.txt");
           
           
           Scanner inFile =new Scanner(file);
           do
           {
               tweet[ix]=new Twitter_Data();
               tweet[ix].name=inFile.next();
               tweet[ix].work=inFile.next();
               tweet[ix].followers=inFile.nextDouble();
               tweet[ix].wealth=inFile.nextDouble();
               ++ix;
           }while(!tweet[ix-1].name.equals("EOF")); 
        }
        catch (IOException ioe)
        {
            System.out.println("File access error.");
            ix=0;
        }
        ix=ix-1;
        return ix;
    }
    public static void display_options()
    {
        System.out.println("Choose one of the following options.");
        System.out.println("(1)Display data.");
        System.out.println("(2)Enter a name of a twitter profile "
                + "to display all fields of the name entered. ");
        System.out.println("(3)Display a histogram that reveals how "
                + "much each person is worth.");
        System.out.println("(4)Quit the program.");
    }
    public static void display_data(Twitter_Data [] tweet,int num)
    {
        int ix;
        String p,w,f,m;
        char load;
        p="profile";
        w="profession";
        f="followers";
        m="net worth(dollars)";
        System.out.println("\n \n");
        System.out.printf("    %-20s   %-20s   %-12s        %-20s \n",p,w,f,m);
        int ten=10;
        for(ix=0;ix<num;++ix)
        {
            if(ix>=ten)
            {
                System.out.println("Do you want the rest of the data(y/n)?");
                do
                {
                    load=kb.next().charAt(0);
                    if(load !='y' && load !='n')
                    {
                        System.out.println("Please enter (y/n).");
                    }
                }while(load !='y' && load !='n');
                if(load=='y')
                {
                    ten=ten+10;
                }
                else
                {
                    return;
                }
            }
            System.out.printf("%2d. %-20s   %-20s   %10.2f      %15.2f \n"
                    ,ix+1,tweet[ix].name,tweet[ix].work,tweet[ix].followers,
                    tweet[ix].wealth); 
            
        }
    }
    public static void Selected_Record(Twitter_Data [] tweet,int num)
    {
        String field;
        System.out.println("Please enter a name. ");
        field=kb.next();
        int match=0;
        int count;
        count =1;
        
        
        boolean Found;
        Found=false;
        for(int ix=0;ix<num && !Found;++ix)
        {
            if(tweet[ix].name.equals(field))
            {
                Found=true;
                System.out.printf("%2d. %-20s   %-20s   %10.2f      %15.2f \n"
                    ,count,tweet[ix].name,tweet[ix].work,tweet[ix].followers,
                    tweet[ix].wealth); 
            }
        }
        if(!Found)
        {
            System.out.println("No match.\n\n");
        }
        
    }
    public static void histogram(Twitter_Data[] tweet,int num,calc vars)
    {
        int [] array = new int [10];
        
        System.out.println("decade      :     count");
        int index;
        
        for(int ix=0;ix<10;++ix)
        {
            array[ix]=0;
        }
        
        int number;
        number = (int)vars.smallest;
        
         for(int count=0;count<num;++count)
            {
                index= (int)(Math.floor(tweet[count].followers
                    -vars.smallest)/vars.decade);
               
                
                    array[index]++;
                
                
            }
        for(int ix=0;ix<10;++ix)
        {
            System.out.print(number);
            number=number+vars.decade;
            System.out.print("           ");
            
         
            System.out.print(array[ix]);
            
            if(array[ix]>0)
            {
                System.out.print("     ");
                for(int ixx=0;ixx<array[ix];++ixx)
                {
                    System.out.print("*");
                }
            }
           
            System.out.println("");
        } 
    }
    public static calc Compute_decade(Twitter_Data[] tweet,int num)
    {
        calc vars=new calc();
        
        vars.smallest=tweet[0].followers;
        for(int ix=1;ix<num;++ix)
        {
            if(vars.smallest>tweet[ix].followers)
            {
                vars.smallest=tweet[ix].followers;
            }
        }
        vars.biggest=tweet[0].followers;
        for(int ixx=1;ixx<num;++ixx)
        {
            if(vars.biggest<tweet[ixx].followers)
            {
                vars.biggest=tweet[ixx].followers;
            }
        }
        vars.range=vars.biggest-vars.smallest;
        vars.decade = (int) (Math.ceil( vars.range / 10.0 ));
        return vars;
    }
    
    
}
        
    
    

