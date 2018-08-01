
package hw.pkg8;

class link
{
public Object data;
public link next; 
}
class set
{
private link _head;

public set()
{
    _head=null;
}
public boolean isEmpty()
{
    return (_head==null);
}
public boolean memberTest(Object item)
{

    if (item instanceOf set)
    {
        return true;
    }
    else
    {
        return false;
    }

}
public void insert(Object item)
{
    link add=new link();
    add.data=item;
    add.next=_head;
    _head=add;  
}
public Object delete()
{
    if(_head==null)
        return null;
    Object save=_head.data;
    _head=_head.next;
    return save;

}
public String toString()
{
    link finger;
    String s="";
    finger=_head;
    while (finger!=null)
    {
        s=s+finger.data;
        finger=finger.next;
    }
    return s;
}
}
public class Hw8 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
    }
    
}
