#include<iostream>
using namespace std;
class Stack
{
    private:
        int top;
        int arr[5];

    public:
        Stack()
        {
            top=-1;
            for (int i = 0; i < 5; i++)
            {
                arr[i]=0;
            }
        }

    bool IsEmpty()
    {
        if(top==-1)
            return true;
        else
            return false;
    }

    bool IsFull()
    {
        if(top==4)
            return true;
        else
            return false;
    }

    void push(int val)
    {
        if(IsFull()) 
            cout<<"Stack is Full"<<endl;
        else
        {
            top++;
            arr[top]=val;
        }
    }

    int pop()
    {
        if(IsEmpty())
        {
            cout<<"Stack is Empty"<<endl;
            return 0;
        }
        else
        {
            int popVal=arr[top];
            arr[top]=0;
            top--;
            return popVal;
        }
    }

    int count()
    {
        return(top+1); 
    }
    int peek(int pos)
    {
        if(IsEmpty())
        {
            cout<<"Stack is empty"<<endl;
            return 0;
        }
        else 
        {
            return arr[pos];
        }
    }

    void change(int pos, int val)
    {
        arr[pos]=val;
        cout<<"Value changed at location "<<pos<<endl;
    }
    
    void display()
    {
        cout<<"All values in the stack are:"<<endl;
        for (int i = 4; i >=0; i--)
        {
            cout<<arr[i]<<endl;
        }
        
    }
};
int main()
{
    Stack s1;
    int option, position, value;
    do
    {
        cout<<"Press [1] for push"<<endl;
        cout<<"Press [2] for pop"<<endl;
        cout<<"Press [3] to check stack is empty or not"<<endl;
        cout<<"Press [4] to check stack is full or not"<<endl;
        cout<<"Press [5] for peek"<<endl;
        cout<<"Press [6] for count"<<endl;
        cout<<"Press [7] for change"<<endl;
        cout<<"Press [8] for display"<<endl;
        cout<<"Press [0] for exit"<<endl;

        cin>>option;
        switch (option)
        {
        case 1:
            cout<<"Enter an item to push in the stack";
            cin>>value;
            s1.push(value);
            break;
        case 2:
            cout<<"Popped value: "<<s1.pop()<<endl;
            break;
        case 3:
            if(s1.IsEmpty())
                cout<<"Stack is empty"<<endl;
            else
                cout<<"Stack is not empty"<<endl;
            break;
        case 4:
            if(s1.IsFull())
                cout<<"Stack is full"<<endl;
            else
                cout<<"Stack is not full"<<endl;
            break;
        case 5:
            cout<<"Enter position of item you want to peek"<<endl;
            cin>>position;
            cout<<"Position: "<<position<<"is "<<s1.peek(position)<<endl;
            break;
        case 6:
            cout<<"Number of item in stack is "<<s1.count()<<endl;
            break;
        case 7:
            cout<<"Enter position"<<endl;
            cin>>position;
            cout<<endl;
            cout<<"Enter value: ";
            cin>>value;
            s1.change(position,value);
            break;
        case 8:
            s1.display();
            break;
        
        default:
            cout<<"Invalid input,try again"<<endl;
            break;
        }

    } while (option!=0);
    


    return 0;
}