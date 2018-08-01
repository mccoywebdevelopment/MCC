/*Chris McCoy, this program is designed to predict the growth
  of a bank account due to compound interest.
 */
package program.pkg2;
import java.util.Scanner;
public class Program2 {
public static Scanner kb=new Scanner(System.in);
    
    public static void main(String[] args) {
        
    
    double Annual_charge,Threshold,Initial_Balance,Annual_Interest,
    Period_Interest_Rate,Periodic_charge,New_balance;
    int Period,option,length,goal,time;
    char userchoice,Same_calc_redo,restart;
    boolean table;


    System.out.println("Hello, this program is designed\n to predict  the growth"
            + " of a bank account.\n");
    do
    {
        
        System.out.println("Please enter the annual processing charge.");
        
        do
        {
            
            Annual_charge=kb.nextDouble();
            
            if(Annual_charge<=0)
            {
                System.out.println("Please enter a positive number.");
            }
            
        }while(Annual_charge <= 0);

                        
        System.out.println("Please enter the threshold amount.");
        
        do
        {
            Threshold=kb.nextDouble();
           
            if (Threshold <=0)
            {
                System.out.println("Please enter a positive number.");
              
            }
            
        }while(Threshold<=0);
        
        
        do
        {
            System.out.println("Enter the initial account balance.");
            
            do
            {
                Initial_Balance=kb.nextDouble();
                
                if(Initial_Balance<=0)
                {
                    System.out.println("Please enter a positive number.");
                }
                
            }while(Initial_Balance<=0);

           
            
            System.out.println("Enter the annual interest rate."
                    + "(expressed as 0-100 %)");
            
            
            do
            {
                Annual_Interest=kb.nextDouble();
                
                if(Annual_Interest<=0)
                {
                    System.out.println("Please enter a positive number.");
                }
            
            }while(Annual_Interest<=0);

            Annual_Interest=Annual_Interest/100;

            
            
            System.out.println("Enter the period at which interest is"
                    + " compounded.");
            System.out.println("Press 1 for daily.");
            System.out.println("Press 2 for monthly.");
            System.out.println("Press 3 for yearly.");

            
            
            do
            {
                Period=kb.nextInt();
                
                if(Period<1 || Period>3)
                {
                    System.out.println("Please enter 1,2, or 3.");
                }
            
            }while(Period<1 || Period>3);

           
            if(Period==1)
            {
                Period_Interest_Rate=Annual_Interest/365;
                
                Periodic_charge=Annual_charge/365;
            }
            else if(Period==2)
            {
                Period_Interest_Rate=Annual_Interest/12;
                
                Periodic_charge=Annual_charge/12;
            }
            else
            {
                Period_Interest_Rate=Annual_Interest;
                
                Periodic_charge=Annual_charge;
            }

           
            System.out.println("Please pick one of the following options."); 
            System.out.println("(1) Enter the length of the investment to "
                    + "calculate the"
                    + " final balance.");
            
            System.out.println("(2) Enter a goal balance to calculate how"
                    + " long it will "
                    + "take to reach that goal amount.");
            
            do
            {
                option=kb.nextInt();
                
                if(option != 1 && option != 2)
                {
                    System.out.println("Wrong input please enter 1 or 2.");
                }
                
            }while(option != 1 && option != 2);

            
            
            System.out.println("Do you want a table ?");
            System.out.println("(y) YES.");
            System.out.println("(n) NO.");

            do
            {
            userchoice=kb.next().charAt(0);
            
                if(userchoice != 'y' && userchoice != 'n')
                {
                    System.out.println("Wrong input please enter y or n.");
                }
                
            }while(userchoice != 'y' && userchoice != 'n');

            table=(userchoice=='y');
            
      

            if(option==1)
            {
                System.out.print("Please enter how long you want to compound "
                        + "your invesment");
                
                if(Period==1)
                {
                    System.out.println("(days)");
                }
                else if(Period==2)
                {
                    System.out.println("(months)");
                }
                else
                {
                System.out.println("(years)");
                }
                
                
                do
                {
                    length=kb.nextInt();
                    if(length<0)
                    {
                        System.out.println("Please enter a value greater"
                                + " than 0.");
                    }
               
                }while(length<0);
                
                
                System.out.print("Periodic_charge:");
                System.out.println(Periodic_charge);
               
                
                New_balance=Compute_final_balance(Threshold,length,
                        Initial_Balance,
                        Period_Interest_Rate,table,Periodic_charge);
                
                if(!table)
    
                {
        
                    System.out.print(length);
        
                    System.out.print("                    ");
       
                    System.out.println(New_balance);
    
                }
            }
            else
            {
               System.out.println("Please enter the goal amount you want"
                       + " to achieve.");
               do
               {
                    goal=kb.nextInt();
                    if(goal<=0)
                    {
                        System.out.println("Please enter a value greater "
                                + "than 0.");
                    }
               }while(goal<=0);
               
              
               time=Compute_length(Threshold,goal,Initial_Balance,
                        Period_Interest_Rate,table,Periodic_charge);
               
                 if(!table)
            
               {
            
                   System.out.print("You will reach $");
            
                   System.out.print(goal);
            
                   System.out.print(" by ");
            
                   System.out.print(time);
           
               }
               
               if(Period==1)
                {
                    System.out.println(" day.");
                }
               
               else if(Period==2)
               {
                
                   System.out.println(" months.");
               }   
            
               else
               {
                   
                System.out.println(" years.");
               }

            }
           
            
            
            System.out.println("Want to do another calculation?"
                    + "(same processing charge"
                    + "and threshold)");
            System.out.println("(y/n)");
           
            
            do
            {
                Same_calc_redo=kb.next().charAt(0);
               
                if(Same_calc_redo!= 'y' && Same_calc_redo!='n')
                {
                    System.out.println("Please enter (y/n).");
                }
           
            }while(Same_calc_redo!= 'y' && Same_calc_redo!='n');
            
        }while(Same_calc_redo=='y');
        
        System.out.println("Do want to try a different processing "
                + "charge and threshold? (y/n)");
        do
        {
            restart=kb.next().charAt(0);
            if(restart!='y' && restart!='n')
            {
                System.out.println("Please enter (y/n).");
            }
        
        }while(restart!='y' && restart!='n');
        
        
    }while(restart=='y');
    }
    public static double Compute_final_balance(double Threshold,int length,
            double balance,double Period_Interest_Rate,boolean Table,
            double Periodic_charge)
    {
    int i;
    double interest;
    System.out.println("Time:                   Money:");//<--5tabs
    for (i=1;i<=length;++i)
    {
        interest=balance*Period_Interest_Rate;
        balance=interest+balance;

        if(balance<Threshold)
        {
            balance=balance-Periodic_charge;
        }
        if(Table)
        {
            System.out.print(i);
            System.out.print("                  ");
            System.out.println(balance);
        }

     }
    
       return balance; 
    }
   
    public static int Compute_length(double Threshold,int goal,double balance,
            double Period_Interest_Rate,boolean Table,
            double Periodic_charge)
    
    {
        int time;
        double interest;
        time=0;
        do
        {
            interest=balance*Period_Interest_Rate;
            balance=interest+balance;
            time=time+1;
            if(balance<Threshold)
            {
                balance=balance-Periodic_charge;
            }


            if(Table)
            {
                System.out.print(time);
                System.out.print("                  ");
                System.out.println(balance);
            }
        }while(balance<goal);

    

        return time;
    }
    
    
}


    
