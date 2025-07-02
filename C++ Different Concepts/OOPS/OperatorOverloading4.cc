#include<iostream>
using namespace std;
class Test
{
    private:
        int num;
    public:
    Test()
    {}
        Test(int n)
        {
            num=n;
        } 
    Test operator+(Test t)
    {
        return this->num+t.num;
    }   
    void display()
    {
        cout<<num;
    }
};
int main()
{
    Test t1(5);
    Test t2(10);
    Test t3;
    t3=t1+t2;
    t3.display();

    return 0;
}