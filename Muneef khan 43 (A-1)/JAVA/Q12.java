/*Write a java program to calculate the area of a rectangle, a square and a circle. Create an abstract class 'Shape' with three abstract methods namely rectangleArea() taking two parameters, squareArea() and circleArea() taking one parameter each. Now create another class ‘Area’ containing all the three methods rectangleArea(),squareArea() and circleArea() for printing the area of rectangle, square and circle respectively. Create an object of class Area and call all the three methods.*/
import java.util.*; 
abstract class Shape
{
    abstract double rectangleArea(double length,double breadth); 
    abstract double squareArea(double side); 
    abstract double circleArea(double radius); 
} 
class Area extends Shape
{
    double rectangleArea(double length,double breadth){
        return length*breadth;
    }
    double squareArea(double side){
        return side*side;
    }
    double circleArea(double radius){
        return Math.PI*radius*radius;
    }
}

class ShapeDemo
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in); 
        Shape obj=new Area(); 
 
        System.out.print("Enter length of rectangle: "); 
        double length=sc.nextDouble(); 
        System.out.print("Enter breadth of rectangle: "); 
        double breadth=sc.nextDouble(); 
        System.out.println("Rectangle Area: "+obj.rectangleArea(length, breadth)); 
 
        System.out.print("Enter side of square: "); 
        double side=sc.nextDouble(); 
        System.out.println("Square Area: "+obj.squareArea(side)); 
 
        System.out.print("Enter radius of circle: "); 
        double radius=sc.nextDouble(); 
        System.out.println("Square Area: "+obj.circleArea(radius)); 
        sc.close();
        System.out.println("\n*************************************************************");
		System.out.println("Program Prepared & Executed by:Muneef Khan,  CLass Roll no.: 43");
		System.out.println("*************************************************************");
    }
}