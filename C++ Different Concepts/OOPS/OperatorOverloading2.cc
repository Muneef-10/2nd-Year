#include<iostream>
using namespace std;
class Test 
{
    private:
        int num;
        int n;
    public:
    Test(){
        num=5;
        n=0;
    }
    Test operator +(Test t)
    {
        Test result;
        result.n=this->num+t.num;
        return result;
    }
    void display()
    {
        cout<<n;
    }
};
int main()
{
    Test t1,t2,t3;
    t3=t1+t2;
    t3.display();
    return 0;
}