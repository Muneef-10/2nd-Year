#include<iostream>
using namespace std;
class Student
{
    private:
        int scores[5];
    public:
        void input()
        {
           
            for (int i = 0; i < 5; i++)
            {
                cin>>scores[i];
            }            
        }
        int total()
        {
            int sum=0;
            for (int i = 0; i < 5; i++)
            {
                sum=sum+scores[i];
            }
            return sum;
        }
};
int main()
{
    int n;
    cout<<"Enter number of students: ";
    cin>>n;
    Student s1[n];
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter 5 subjects marks of student "<<i+1<<":"<<endl;
        s1[i].input();
    }
    int max=0;
    for (int i = 0; i < n; i++)
    {
        if(s1[i].total()>s1[0].total()) max++;
    }
    cout<<max<<" students score more than Anna";
    
    return 0;
}