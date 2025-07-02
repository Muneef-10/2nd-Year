#include<bits/stdc++.h>
using namespace std;
class Hotel
{
    private:
        int rno;
        string type;
        float price;
        bool aval;
    public:
    Hotel(int rno,string type,float price,bool aval)
    {
        this->rno=rno;
        this->aval=aval;
        this->price=price;
        this->type=type;
    }
    void display()
    {
        cout<<"\nRoom No.: "<<rno<<"\nType: "<<type<<"\nPrice: $"<<price<<"\nAvalaiblility status: ";
        if(aval) cout<<"Available\n";
        else cout<<"Booked\n";
    }
    void bookroom()
    {
        if(aval)
        {
            aval=false;
            cout<<"Room No.: "<<rno<<" has successfully booked"<<endl;
        }
        else
        {
            cout<<"Room has already booked, book another room"<<endl;
        }
    }
    void cancelroom()
    {
        if(!aval)
        {
            aval=true;
            cout<<"Room No.: "<<rno<<" is available now"<<endl;
        }
        else
        {
            cout<<"Room is already available, not booked yet!"<<endl;
        }
    }
    void avlroom()
    {
        if(aval)
        {
            cout<<rno<<" is available"<<endl;
        }
    }
};
int main()
{
    Hotel *h1[5]={new Hotel(101,"Single",2500,true),
                  new Hotel(102,"Single",2800,true),
                  new Hotel(103,"Double",3600,true),
                  new Hotel(104,"Single",2300,false),
                  new Hotel(105,"Double",3700,true)};
    int choice,Rno;
    do
    {
        cout<<"\nPress [1] to check room details"<<endl;
        cout<<"Press [2] to book a room"<<endl;
        cout<<"Press [3] to cancel room booking"<<endl;
        cout<<"Press [4] to check available room"<<endl;
        cout<<"Press [0] for exit"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 0:
            cout<<"Exit..."<<endl;
            for (int i = 0; i < 5; i++)
            {
                delete h1[i];
            }
            break;
            case 1:
                for (int i = 0; i < 5; i++)
                {
                    h1[i]->display();
                }
                break;
            case 2:
                cout<<"Enter room no.: ";
                cin>>Rno;
                if(Rno>=101 && Rno<=105)
                {
                    h1[Rno-101]->bookroom();
                }
                else cout<<"Invalid room no."<<endl;
                
                break;
            case 3:
                cout<<"Enter room no.: ";
                cin>>Rno;
                if(Rno>=101 && Rno<=105)
                {
                    h1[Rno-101]->cancelroom();
                }
                else cout<<"Invalid room no."<<endl;
                
                break;
            case 4:
                for (int i = 0; i < 5; i++)
                {
                    h1[i]->avlroom();
                }
                break;
                
        }

    } while (choice!=0);
    
    return 0;
}