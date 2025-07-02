import java.io.*;
import java.util.*;

public class ObjectSerialization 
{
    public static void main(String argd[]) throws IOException,ClassNotFoundException
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        FileOutputStream fos = new FileOutputStream("empfile"); // it create a blank file
        ObjectOutputStream oos = new ObjectOutputStream(fos);//for write
        System.out.println("Writing object into a File(i.e. serialization) ");
        System.out.println("Enter how many objects: ");
        int n=Integer.parseInt(br.readLine());

        for(int i=0;i<n;i++)
        {
            Employ e1=Employ.getData();
            oos.writeObject(e1);
        }
        oos.close();
        fos.close();
        System.out.println("Reading object from File(i.e.De-serialization) ");
        FileInputStream fis = new FileInputStream("empfile");
        ObjectInputStream ois = new ObjectInputStream(fis);
        try
        {
            Employ e;
            while( (e = (Employ) ois.readObject())!=null)
                e.display();
        }
        catch(EOFException ee)
        {
            System.out.println("End of file Reached...");
        }
        finally
        {
            ois.close();
            fis.close();
        }
    }
}

class Employ implements Serializable
{
    private int id;
    private String name;
    private float sal;
    private Date doj;
    Employ(int i, String n, float s, Date d)
    {
        id=i;
        name=n;
        sal=s;
        doj=d;
    }
    void display()
    {
        System.out.println(id + "\t" + name + "\t" + sal + "\t" + doj);
    }
    static Employ getData() throws IOException
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter employ id: ");
        int id=Integer.parseInt(br.readLine());
        System.out.print("Enter employ name: ");
        String name = br.readLine();
        System.out.print("Enter employ salary: ");
        float sal = Float.parseFloat(br.readLine());
        Date d=new Date();
        Employ e=new Employ(id, name, sal, d);
        return e;

    }

}