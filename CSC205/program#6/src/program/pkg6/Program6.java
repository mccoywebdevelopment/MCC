
package program.pkg6;
import java.util.Scanner;

class link
{
    public Object data;
    public link next;
    
}


class list
{
    private int size;
    private link head;
    private link tail;
    
    public list()
    {
        head=null;
        size=0;
    }
    public void insert(Object item,int pos)
    {
        if(pos<=size+1 && pos>0)
        {
            if(head==null)
            {
                link add=new link();
                add.data=item;
                add.next=head;
                head=add;
                tail=add;
                size++; 
            }
            else if(pos==size+1)
            {
                insertOnBack(item);
            }
            else if(pos < size)
            {
                boolean found=false;
                link finger=head;
                link prev=head;

                for(int i=1;i<=size || !found ;++i)
                {
                    if(i==pos)
                    {
                        found=true;
                        link add=new link();
                        add.data=item;
                        prev.next=add;
                        add.next=finger;
                        size++;
                    }
                    else
                    {
                        prev=finger;
                        finger=finger.next;
                    }
                }
            }
        }
        
    }
    public void insertOnBack(Object item)
    {
        if(head==null)
        {
            link add=new link();
            add.data=item;
            add.next=head;
            head=add;
            tail=add;
            size++; 
        }
        else 
        {
            link add=new link();
            add.data=item;
            add.next=null;
            tail.next=add;                                                      //don't do! add=tail.next;
            tail=add;
            size++;
        }
    }
    public void deleteRange(int beg,int end)
    {
        if(end-beg>=0 && beg>0 && end<=size)
        {
            boolean found=false;
            link front=head;
            link back=head;
            link prev=head;
            link finger=head;
            
            if(beg==1 && end==size)
            {
                head=null;
                size=0;
            }
            else if(beg==1)
            {
                for(int i=1;i<=size &&!found;++i)
                {
                    if(i==end)
                    {
                        back=finger.next;
                        head=back;
                        found=true;
                    }
                    finger=finger.next;
                }
                size=size-(end-beg+1);
            }
            else if(end==size)
            {
                for(int i=1;i<=size &&!found;++i)
                {
                    if(i==beg)
                    {
                        tail=prev;
                        prev.next=null;
                        found=true;
                    }
                    else
                    {
                        prev=finger;
                        finger=finger.next;
                    }
                }
                size=size-(end-beg+1);
            }
            else
            {
                for(int i=1;i<=size &&!found;++i)
                {
                    if(i==beg)
                    {
                        front=prev;
                        finger=head;
                        
                        for(int ix=1;ix<=size && !found;++ix)
                        {
                            if(ix==end)
                            {
                                back=finger.next;
                                front.next=back;                                 //maybe
                                found=true;
                            }
                            else
                            {
                                finger=finger.next;
                            }
                        }
                    }
                    else
                    {
                        prev=finger;
                        finger=finger.next;
                    }
                }
                size=size-(end-beg+1);
            }
            
           
        }
    }
    public void deleteItem(Object item)                                         //fix prev
    {
        link prev=head;
        link finger=head;
        boolean match=false;
        if(head==null)
        {
            return;
        }
        
        while(finger !=null)
        {
            if(finger.data.equals(item))
            {
                --size;
                if(finger==head)
                {
                    head=finger.next;
                }
                else if(finger==tail)
                {
                    prev.next=null;
                    tail=prev;
                }
                else
                {
                    prev.next=finger.next;
                    match=true;
                }
            }
            
            if(!match)
            {
                prev=finger;
            }
          
            finger=finger.next;
            match=false;
            
        }
                
      
        
      
    }
    public Object retrieveItem(int pos)                                           //finish!
    {
        Object item=null;
        if(pos>0 && pos<=size)
        {
           
            link finger=head;
           
            for(int i=1;i<=size;++i)
            {
                item=finger.data;
                if(pos==i)
                {
                    return item;
                }
                finger=finger.next;
            }
            
        }
        return item;
    }
    public list findItem(Object item)
    {
        list find=new list();
        link finger=head;
        for(int i=1;i<=size;++i)
        {
            if(finger.data.equals(item))
            {
                find.insertOnBack(i);
            }
            finger=finger.next;
        }
        return find;
    }
    public int getSize()
    {
        return size;
    }
    
    public String toString()
    {
        String s="";
        s=s+"\nhead:";
        for(link i=head;i!=null;i=i.next)
        {
            s=s+"\n"+i.data;
        }
        s=s+"\n:tail";
        return s;
    }
}


public class Program6 {

    public static Scanner kb=new Scanner(System.in);
    public static void main(String[] args) {
        int list,options;
        char again;
        
        list string=new list();
        list inventory=new list();
        list inventory2=new list();
        
        do
        {
            listOption();
            do
            {
                list=kb.nextInt();
                if(list<1 || list>4)
                {
                    System.out.println("Please enter 1,2,3 or 4.");
                }
            }while(list<1 || list>4);
            
            if(list!=4)
            {
                do
                {   
                    if(list==1)
                    {
                        menuString();
                        do
                        {
                            options=kb.nextInt();
                            if(options<1 || options>11)
                            {
                                System.out.println("Please enter a number between "
                                        + "1 and 11."
                                        + "(includes)");
                            }
                        }while(options<1 || options>11);
                    }
                    else
                    {
                        menuInventory();
                        do
                        {
                            options=kb.nextInt();
                            if(options<1 || options>12)
                            {
                                System.out.println("Please enter a number between "
                                        + "1 and 12."
                                        + "(includes)");
                            }
                        }while(options<1 || options>12);
                    }
                    if(options==11)
                    {
                        list=4;
                    }
                   
                    if(options!=11 && options !=9)
                    {
                         if(list==1)
                        {
                            testToolString(string,options);
                        }
                        else if(list==2)
                        {
                            String name;
                            double cost;
                            Object value;
                            int position;
                            if(options==1)
                            {
                                System.out.println("Please enter the item's name.");
                                name=kb.next();
                                
                                System.out.println("Please enter how much the item cost.");
                                cost=kb.nextDouble();
                               
                                System.out.println("Please enter the position you want to insert"
                                        + " the item at.");
                                position=kb.nextInt();
                                
                                inventoryItem item=new inventoryItem(name,cost);
                                
                                inventory.insert(item, position);
                                
                            }
                             else if(options==2)
                            {
                                System.out.println("Please enter the item's name.");
                                name=kb.next();
                                
                                System.out.println("Please enter how much the item cost.");
                                cost=kb.nextDouble();
                                
                                inventoryItem item=new inventoryItem(name,cost);
                                
                                inventory.insertOnBack(item);
                            }
                            else if(options==3)
                            {
                                int beg,end;
                                System.out.println("Please enter the number for the beginning of "
                                        + "the range.");
                                do
                                {
                                    beg=kb.nextInt();
                                    if(beg<0)
                                    {
                                        System.out.println("Please enter a positive number.");
                                    }
                                }while(beg<0);

                                System.out.println("Please enter the number for the end of the "
                                        + "range.");
                                do
                                {
                                    end=kb.nextInt();
                                    if(end<=beg || beg>inventory.getSize())
                                    {
                                        System.out.println("Please enter a positive number that's "
                                                + "greater than the beginning number and is "
                                                + "less than or equal to the size of the list.");
                                    }
                                }while(end<=beg || beg>inventory.getSize());
                                inventory.deleteRange(beg, end);
                            }
                            else if(options==4)
                            {
                                System.out.println("Enter a name of the item you"
                                        + " wish to delete.");
                                name=kb.next();

                                inventory.deleteItem(name);
                            }
                            else if(options==5)                                    //check                    
                            {

                                System.out.println("Please enter the position "
                                        + "you wish to retrieve"
                                        + " the item.");
                                do
                                {
                                    position=kb.nextInt();
                                    if(position<1 || position>inventory.getSize())
                                    {
                                        System.out.println("Please enter a "
                                                + "number greater than zero"
                                                + " or number less than or equal"
                                                + " to the size of the"
                                                + " list.");
                                    }
                                }while(position<1 || position>inventory.getSize());
                                value=inventory.retrieveItem(position);
                                if(value==null)
                                {
                                    System.out.println("The list is empty.");
                                }
                                else
                                {
                                    System.out.print("contents:");
                                    System.out.println(value);

                                }
                            }
                            else if(options==6)
                            {
                                list temp=new list();
                                System.out.println("Please enter an object you want to find (String).");
                                name=kb.next();
                                temp=inventory.findItem(name);
                                System.out.print("Locations of where the item is located,");
                                System.out.println(temp);
                            }
                            else if (options==7)
                            {
                                System.out.println(inventory.getSize());
                            }
                            else if(options==8)
                            {
                                double total;
                                total=computeTotalValue(inventory);
                                System.out.print("Value:");
                                System.out.println(total);
                            }
                            else if(options==10)
                            {
                                System.out.println(inventory);
                            }
                            else 
                            {
                                int size=inventory.getSize();
                                inventory.deleteRange(1, size);
                            }
        
                        }
                        else
                        {
                            String name;
                            double cost;
                            Object value;
                            int position;
                            if(options==1)
                            {
                                System.out.println("Please enter the item's name.");
                                name=kb.next();
                                
                                System.out.println("Please enter how much the item cost.");
                                cost=kb.nextDouble();
                               
                                System.out.println("Please enter the position you want to insert"
                                        + " the item at.");
                                position=kb.nextInt();
                                
                                inventoryItem item=new inventoryItem(name,cost);
                                
                                inventory2.insert(item, position);
                                
                            }
                             else if(options==2)
                            {
                                System.out.println("Please enter the item's name.");
                                name=kb.next();
                                
                                System.out.println("Please enter how much the item cost.");
                                cost=kb.nextDouble();
                                
                                inventoryItem item=new inventoryItem(name,cost);
                                
                                inventory2.insertOnBack(item);
                            }
                            else if(options==3)
                            {
                                int beg,end;
                                System.out.println("Please enter the number for the beginning of "
                                        + "the range.");
                                do
                                {
                                    beg=kb.nextInt();
                                    if(beg<0)
                                    {
                                        System.out.println("Please enter a positive number.");
                                    }
                                }while(beg<0);

                                System.out.println("Please enter the number for the end of the "
                                        + "range.");
                                do
                                {
                                    end=kb.nextInt();
                                    if(end<=beg || beg>inventory2.getSize())
                                    {
                                        System.out.println("Please enter a positive number that's "
                                                + "greater than the beginning number and is "
                                                + "less than or equal to the size of the list.");
                                    }
                                }while(end<=beg || beg>inventory.getSize());
                                inventory2.deleteRange(beg, end);
                            }
                            else if(options==4)
                            {
                                System.out.println("Enter a name of the item you"
                                        + " wish to delete.");
                                name=kb.next();

                                inventory2.deleteItem(name);
                            }
                            else if(options==5)                                    //check                    
                            {

                                System.out.println("Please enter the position "
                                        + "you wish to retrieve"
                                        + " the item.");
                                do
                                {
                                    position=kb.nextInt();
                                    if(position<1 || position>inventory2.getSize())
                                    {
                                        System.out.println("Please enter a "
                                                + "number greater than zero"
                                                + " or number less than or equal"
                                                + " to the size of the"
                                                + " list.");
                                    }
                                }while(position<1 || position>inventory2.getSize());
                                value=inventory2.retrieveItem(position);
                                if(value==null)
                                {
                                    System.out.println("The list is empty.");
                                }
                                else
                                {
                                    System.out.print("contents:");
                                    System.out.println(value);

                                }
                            }
                            else if(options==6)
                            {
                                list temp=new list();
                                System.out.println("Please enter an object you want to find (String).");
                                name=kb.next();
                                temp=inventory2.findItem(name);
                                System.out.print("Locations of where the item is located,");
                                System.out.println(temp);
                            }
                            else if (options==7)
                            {
                                System.out.println(inventory2.getSize());
                            }
                            else if(options==8)
                            {
                                double total;
                                total=computeTotalValue(inventory2);
                                System.out.print("Value:");
                                System.out.println(total);
                            }
                            else if(options==10)
                            {
                                System.out.println(inventory2);
                            }
                            else 
                            {
                                int size=inventory2.getSize();
                                inventory2.deleteRange(1, size);
                            }
                        }
                    }
                    
                }while( list!=4 && options!=9);
            }
            
        }while(list !=4);
        
    }


    public static void menuInventory()
    {
        System.out.println("Please select one of the following...");
        System.out.println("(1)insert a given.\n(2)insert an item on the end.\n"
                + "(3)delete range.\n(4)delete item.\n(5)retrieve item.\n(6)"
                + "find item.\n(7)get size of list.\n(8)compute the total value"
                + " of all items.\n(9)pick a different"
                + " list.\n(10)return a string "
                + "summarizing the contents of the list.\n(11)quit\n(12)create "
                + "an empty list."); 
                        
    }
    public static void menuString()
    {
     System.out.println("Please select one of the following...");
        System.out.println("(1)insert a given.\n(2)insert an item on the end.\n"
                + "(3)delete range.\n(4)delete item.\n(5)retrieve item.\n(6)"
                + "find item.\n(7)get size of list.\n(8)return a string "
                + "summarizing the contents of the list.\n(9)pick a different"
                + " list.\n(10)create an empty list.\n(11)quit"); 
    }
    public static void listOption()
    {
        System.out.println("Please pick one of the following list.");
        System.out.println("(1)String list\n(2)Inventory item list1.\n(3)"
                + "Inventory item list2\n(4)Quit");
    }
    public static boolean redo()
    {
        char again;
        boolean redo=true;
        System.out.println("Do you want to try again?(y/n)");
        do
        {
            again=kb.next().charAt(0);
            if(again!='y' && again!='n')
            {
                System.out.println("Please enter (y/n).");
            }
        }while(again!='y' && again!='n');
        if(again=='n')
        {
            redo=false;
        }
        return redo;
    }
    
    public static void testToolString(list test,int option)
    {
        Object item;
        int position;
        if(option==1)
        {
            System.out.println("Please enter the item's name.");
            item=kb.next();
            System.out.println("Please enter the position you want to insert"
                    + " the item at.");
            position=kb.nextInt();
     
            test.insert(item, position);
            
        }
        else if(option==2)
        {
            System.out.println("Please enter the item's name.");
            item=kb.next();
            test.insertOnBack(item);
        }
        else if(option==3)
        {
            int beg,end;
            System.out.println("Please enter the number for the beginning of "
                    + "the range.");
            do
            {
                beg=kb.nextInt();
                if(beg<0)
                {
                    System.out.println("Please enter a positive number.");
                }
            }while(beg<0);
            
            System.out.println("Please enter the number for the end of the "
                    + "range.");
            do
            {
                end=kb.nextInt();
                if(end<=beg || beg>test.getSize())
                {
                    System.out.println("Please enter a positive number that's "
                            + "greater than the beginning number and is "
                            + "less than or equal to the size of the list.");
                }
            }while(end<=beg || beg>test.getSize());
            test.deleteRange(beg, end);
        }
        else if(option==4)
        {
            String name;
            System.out.println("Enter a name of the item you wish to delete.");
            name=kb.next();
            
            test.deleteItem(name);
        }
        else if(option==5)
        {
            
            System.out.println("Please enter the position you wish to retrieve"
                    + " the item.");
            do
            {
                position=kb.nextInt();
                if(position<1 || position>test.getSize())
                {
                    System.out.println("Please enter a number greater than zero"
                            + " or number less than or equal to the size of the"
                            + " list.");
                }
            }while(position<1 || position>test.getSize());
            item=test.retrieveItem(position);
            if(item==null)
            {
                System.out.println("The list is empty.");
            }
            else
            {
                System.out.print("contents:");
                System.out.println(item);
                
            }
        }
        else if(option==6)
        {
            list temp=new list();
            System.out.println("Please enter an object you want to find (String).");
            item=kb.next();
            temp=test.findItem(item);
            System.out.print("Locations of where the item is located,");
            System.out.println(temp);
        }
        else if (option==7)
        {
            System.out.println(test.getSize());
        }
        else if(option==8)
        {
            System.out.println(test.toString());
        }
        else
        {
            int size=test.getSize();
            test.deleteRange(1, size);
        }
        
        
    }
    public static double computeTotalValue(list other)
    {
        double total=0;
       
        for(int i=1;i<=other.getSize();i++)
        {
            Object A=other.retrieveItem(i);
            
            if(A instanceof inventoryItem)
            {
                inventoryItem temp=(inventoryItem) A;
                total=total+temp.getCost();
            }
        }
        return total;
    }
      
    
}


class inventoryItem
{
    private String _name;
    private int _quantity;
    private double _cost;
    
    public inventoryItem(String name,double cost)                                           //getcost not in here
    {
        _name=name;
        _cost=cost;
        _quantity++;
    }
    public boolean equals(Object other)
    {
        if(other instanceof inventoryItem)
        {
            inventoryItem otherName=(inventoryItem) other;
            return(_name.equals(otherName._name));
        }
        else
        {
            return false;
        }
    }
    public String getName()
    {
        return _name;
    }
    public double getCost()
    {
        return _cost;
    }
    public int getQuantity()
    {
        return _quantity;
    }
    public String toString()
    {
        String s="";
        s=s+"\nname:"+_name+"\ncost:"+_cost;
        return s;
    }
            
}

