#include<iostream>
using namespace std;
class Student
{
    private:
        string name;
        int rno;
        string course;
        float marks;
    public:
        Student(string name,int rno,string course,float marks)
        {
            this->name=name;
            this->rno=rno;
            this->marks=marks;
            this->course=course;
        }
        void display()
        {
            cout<<"\nName: "<<name<<endl;
            cout<<"Roll no.: "<<rno<<endl;
            cout<<"Course: "<<course<<endl;
            cout<<"Marks: "<<marks<<endl;
        }
        bool dltstudent(int dltrno)
        {
            if(rno==dltrno) return true;
            else return false;            
        }
        float getmarks()
        {
            return marks;
        }
        string getname()
        {
            return name;
        }
    
};
int main()
{
    int studentcount=0,choice;
    Student *s[50];
    do
    {
        cout<<"\nPress [1] for add a student data"<<endl;
        cout<<"Press [2] for delete a student data"<<endl;
        cout<<"Press [3] to view all students data"<<endl;
        cout<<"Press [4] to calculate average marks of all students"<<endl;
        cout<<"Press [5] to display highest marks of all students"<<endl;
        cout<<"Press [0] for exit"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 0:
                cout<<"Exit.."<<endl;
                break;
            case 1:
            {
                int rno;
                string name;
                string course;
                float marks;
                
                cout<<"Enter name: ";
                cin>>name;
                cout<<"Enter roll no.: ";
                cin>>rno;
                cout<<"Enter marks: ";
                cin>>marks;
                cout<<"Enter course: ";
                cin>>course;
                s[studentcount]=new Student(name,rno,course,marks);
                studentcount++;
                break;
            }
            case 2:
                {
                    int dltrno,flag=1;
                    cout<<"Enter roll no. of that student: ";
                    cin>>dltrno;
                    
                    for (int i = 0; i < studentcount; i++)
                    {
                        if(s[i]->dltstudent(dltrno))
                        {
                            delete s[i];
                            for (int j = i; j < studentcount-1; j++)
                            {
                                s[j]=s[j+1];
                            }
                            studentcount--;
                            cout<<"Student record deleted successfully"<<endl;
                            flag=0;
                            break;
                        }
                    }
                    if(flag==1) cout<<"No record found"<<endl;
                    break;
                }
            case 3:
                if(studentcount==0) cout<<"No details of any student is present"<<endl;
                else{
                for (int i = 0; i < studentcount; i++)
                {
                    s[i]->display();
                }
                }
                break;
            case 4:
            {
                float sum=0;
                for (int i = 0; i < studentcount; i++)
                {
                    sum=sum+s[i]->getmarks();
                }
                sum=sum/studentcount;
                cout<<"Average marks is: "<<sum<<endl;
                break;
            }
            case 5:
            {
                int max=0,j=0;
                for (int i = 0; i < studentcount; i++)
                {
                    if(max<s[i]->getmarks())
                    {
                        max=s[i]->getmarks();
                        j=i;
                    }
                }
                cout<<"Maximum marks of student is '"<<max<<"' and student name is '"<<s[j]->getname()<<"'"<<endl;
            }


        }
        

    } while (choice !=0);
    
    
    
    

    return 0;
}