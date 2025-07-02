/*Write a java program to implement abstract class and abstract method with following details: Create a abstract Base Class Temperature Data members: double temp; Method members: void setTempData(double) abstact void changeTemp() Sub Class Fahrenheit (subclass of Temperature) Data members: double ctemp; method member: Override abstract method changeTemp() to convert Fahrenheit temperature into degree Celsius by using formula C=5/9*(F-32) and display converted temperature Sub Class Celsius (subclass of Temperature) Data member: double ftemp; Method member: Override abstract method changeTemp() to convert degree Celsius into Fahrenheit temperature by using formula F=9/5*c+32 and display converted temperature  */
import java.util.*; 
abstract class Temperature
{ 
    double temp; 
    void setTempData(double temp){ 
        this.temp = temp; 
    } 
    abstract void changeTemp(); 
} 
class Farenheit extends Temperature{ 
    double ctemp; 
    void changeTemp()
    { 
        ctemp=(5.0/9)*(temp-32); 
        System.out.println("Temperature in Celsius: " + ctemp); 
    } 
}
class Celsius extends Temperature
{
    double ftemp;
    void changeTemp(){ 
        ftemp=(9.0/5)*temp+32; 
        System.out.println("Temperature in Farenheit: " + ftemp); 
    } 
} 
class TemperatureDemo
{ 
    public static void main(String[] args)
    { 
        Scanner sc=new Scanner(System.in); 
        System.out.println("Enter temperature in Farenheit: "); 
        double farenheit=sc.nextDouble(); 
        Temperature tf=new Farenheit(); 
        tf.setTempData(farenheit); 
        tf.changeTemp(); 
        System.out.println("Enter temperature in Celsius: "); 
        double celsius=sc.nextDouble(); 
        Temperature tc=new Celsius(); 
        tc.setTempData(celsius); 
        tc.changeTemp();
        sc.close();
        System.out.println("\n*************************************************************");
		System.out.println("Program Prepared & Executed by:Muneef Khan,  CLass Roll no.: 43");
		System.out.println("*************************************************************");
}
}