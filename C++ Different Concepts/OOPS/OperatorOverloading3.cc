//unary
#include<iostream>
using namespace std;
class Test
{
    private:
        int num;
    public:
    Test()
    {
        num=0;
    }
    void operator ++()
    {
        ++num;
    }
    void operator ++(int)
    {
        ++num;
    }
    void display()
    {
        cout<<num<<endl;
    }
};
int main()
{
    Test t1;
    ++t1;
    t1.display();

    t1++;
    t1.display();
    return 0;
}