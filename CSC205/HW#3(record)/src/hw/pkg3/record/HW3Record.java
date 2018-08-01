
package hw.pkg3.record;

import java.util.Scanner;
class specs 
{
    public double height;
    public double width;
}
public class HW3Record 
{
public static Scanner kb=new Scanner(System.in);
   
    public static void main(String[] args)
    {
        double diagonal,aspect;
        specs dim;
        System.out.println("Please enter the diagonal(inches).");
        diagonal=kb.nextDouble();
        System.out.println("Please enter the aspect ratio.");
        aspect=kb.nextDouble();
        dim=Compute_dimensions(diagonal,aspect);
        System.out.print("height:");
        System.out.println(dim.height);
        System.out.print("width:");
        System.out.println(dim.width);
      
    }
    public static specs Compute_dimensions(double diagonal,double aspect)
    {
        specs dim= new specs();
        dim.height=Math.sqrt((Math.pow(diagonal,2)/(1+Math.pow(aspect,2))));
        dim.width= aspect*dim.height;
        return dim;
    }
}

