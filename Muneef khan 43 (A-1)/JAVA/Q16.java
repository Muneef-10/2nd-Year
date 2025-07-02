import java.util.Scanner; 
 
class WrongEmployeeDetailsException extends RuntimeException 
{ 
    String err; 
    WrongEmployeeDetailsException(String err) { 
        this.err = err; 
    } 
 
    @Override 
    public String toString() { 
        return err; 
    } 
} 
 
class Employee 
{ 
    int empId, deptId; 
    String name; 
 
    Employee(String name, int empId, int deptId) { 
        this.name = name; 
        this.empId = empId; 
        this.deptId = deptId; 
    } 
 
    void printDetails() { 
        System.out.println("Name: " + name + "\nEmployee ID: " + empId + "\nDepartment ID: " + deptId); 
    } 
 
    public static void main(String[] args) { 
        Scanner sc = new Scanner(System.in); 
        System.out.print("Enter Employee Name: "); 
        String name = sc.nextLine(); 
        System.out.print("Enter Employee ID (2001 - 5001): "); 
        int empId = sc.nextInt(); 

        System.out.print("Enter Department ID (1 - 5): "); 
        int deptId = sc.nextInt(); 
 
        try { 
            if (name.charAt(0) < 'A' || name.charAt(0) > 'Z') { 
                throw new WrongEmployeeDetailsException("First letter of name must be capital"); 
            } else if (empId < 2001 || empId > 5001) { 
                throw new WrongEmployeeDetailsException("Emp id must be b/w 2001-5001"); 
            } else if (deptId < 1 || deptId > 5) { 
                throw new WrongEmployeeDetailsException("Dept id must be b/w 1-5"); 
            } else { 
                Employee e1 = new Employee(name, empId, deptId); 
                e1.printDetails(); 
            } 
        } catch (WrongEmployeeDetailsException e) { 
            System.out.println("Error: " + e); 
        } 
 
        sc.close();
        System.out.println("\n*************************************************************");
        System.out.println("Program Prepared & Executed by:Muneef Khan,  CLass Roll no.: 43");
        System.out.println("*************************************************************");

    } 
}