class zz 
{
    int rollno;
    String name;
    String city;

    zz(int rollno, String name, String city)
    {
        this.rollno=rollno;   
        this.name=name;   
        this.city=city;   
    }
    public String toString()
    {
        return name+" "+rollno+" "+city;
    }
    public static void main(String[] args) {
        zz s1=new zz(25,"ABCD","DELHI");
        zz s2=new zz(45,"EFGH","DEHRADUN");
        System.out.println(s1);
        System.out.println(s2);
    }

}