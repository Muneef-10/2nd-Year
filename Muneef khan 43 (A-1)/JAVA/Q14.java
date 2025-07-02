/*Write a java program to create an interface that consists of a method to display volume () as an abstract method and redefine this method in the derived classes to suit their requirements. Create classes called Cone, Hemisphere and Cylinder that implements the interface. Using these three classes, design a program that will accept dimensions of a cone, cylinder and hemisphere interactively and display the volumes. Volume of cone = (1/3)πr2h Volume of hemisphere = (2/3)πr3 Volume of cylinder = πr2h  */

import java.util.*; 
interface Volume{ 
    void displayVolume(); 
} 
 
class Cone implements Volume
{ 
    double radius,height; 
    Cone(double radius,double height){ 
        this.radius = radius; 
        this.height = height; 
    } 
    public void displayVolume() { 
        double volume=(1.0/3)*Math.PI*radius*radius*height; 
        System.out.println("Volume of Cone: " + volume); 
    } 
} 
 
class Hemisphere implements Volume
{ 
    double radius;  
    Hemisphere(double radius){ 
        this.radius = radius; 
    } 
    public void displayVolume() { 
        double volume=(2.0/3)*Math.PI*radius*radius*radius; 
        System.out.println("Volume of Hemisphere: " + volume); 
    } 
} 
 
class Cylinder implements Volume
{ 
    double radius,height; 
    Cylinder(double radius,double height){
        this.radius = radius; 
        this.height = height; 
    } 
    public void displayVolume() { 
        double volume=Math.PI*radius*radius*height; 
        System.out.println("Volume of Cylinder: " + volume); 
    } 
} 
 
class VolumeDemo
{ 
    public static void main(String[] args) 
    { 
        Scanner sc=new Scanner(System.in); 
 
        System.out.println("Enter radius of cone: "); 
        double coneRadius=sc.nextDouble(); 
        System.out.println("Enter height of cone: "); 
        double coneHeight=sc.nextDouble(); 
        Volume cone=new Cone(coneRadius,coneHeight); 
        cone.displayVolume(); 
 
        System.out.println("Enter radius of hemisphere: "); 
        double hemiRadius=sc.nextDouble(); 
        Volume hemi=new Hemisphere(hemiRadius); 
        hemi.displayVolume(); 
 
        System.out.println("Enter radius of cylinder: "); 
        double cylinderRadius=sc.nextDouble(); 
        System.out.println("Enter height of cylinder: "); 
        double cylinderHeight=sc.nextDouble(); 
        Volume cylinder=new Cylinder(cylinderRadius,cylinderHeight); 
        cylinder.displayVolume();
        
        sc.close();
        System.out.println("\n*************************************************************");
		System.out.println("Program Prepared & Executed by:Muneef Khan,  CLass Roll no.: 43");
		System.out.println("*************************************************************");
    }
}