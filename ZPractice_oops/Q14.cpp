#include<iostream>
using namespace std;
class Score
{
    private:
    int score;
    public:
    Score()
    {
        score=0;
    }
    Score(int n)
    {
        score=n;
    }
    Score operator++()
    {
        score=score+10;
        return *this;
    }
    Score operator++(int)
    {
        Score tmp=*this;
        score=score+10;
        return tmp;
    }
    void display()
    {
        cout<<score<<endl;
    }
};
int main()
{
    Score s1;
    s1.display();
    cout<<"After pre-Increment: ";
    ++s1;
    s1.display();

    s1++;
    cout<<"After post-Increment: ";
    s1.display();
    return 0;
}