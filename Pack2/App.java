package Pack2;
public class App
{
    public String str1="I am a public member";
    void printFromClass()
    {
        System.out.println("Within Class: "+str1);
    }
    public static void main(String[] args) 
    {
        App obj=new App();
        obj.printFromClass();
        System.out.println("Within Class: "+obj.str1);
        
        App2 obj2=new App2();
        obj2.printFromOutsideClass();
    }
}
class App2
{
    void printFromOutsideClass()
    {
        App obj= new App();
        System.out.println("Outside class: "+obj.str1);
    }
}