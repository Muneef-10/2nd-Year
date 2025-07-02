// int* arr = new int[5];   Dynamic array  VECTOR is also a dynamic array
#include<iostream>
using namespace std;
class Vector
{
public:
    int size;
    int capacity;
    int* arr;
    Vector()
    {
        size = 0;
        capacity = 1;
        arr = new int[1];// dynamic array
    }
    void add(int ele)
    {
        if(size==capacity)
        {
            capacity *= 2;
            int* arr2 = new int[capacity];
            for (int i = 0; i < size; i++)
            {
                arr2[i] = arr[i];
            }
            arr = arr2;
        }
        arr[size++] = ele;
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl; 
    }
    int get(int idx)
    {
        if(size==0)  
        {
            cout<<"Array is empty";
            return -1;
        }
        if(idx>=size || idx<0) 
        {
            cout<<"Invalid Index"<<endl;
            return -1;
        }
        else  return arr[idx];
    }
    void remove()
    {
        if(size==0)  
        {
            cout<<"Array is empty"<<endl;
        }
        else
        size--;
    }
};
int main()
{
    Vector v;
    cout<<"Initial Capacity: "<<v.capacity<<" "<<"Initial Size: "<<v.size<<endl;
    v.remove();

    v.add(10);
    v.print();
    cout<<"Capacity: "<<v.capacity<<" "<<"Size: "<<v.size<<endl;

    v.add(15);
    v.print();
    cout<<"Capacity: "<<v.capacity<<" "<<"Size: "<<v.size<<endl;

    v.remove();
    v.print();
    cout<<"Capacity: "<<v.capacity<<" "<<"Size: "<<v.size<<endl;

    v.add(20);
    v.print();
    cout<<"Capacity: "<<v.capacity<<" "<<"Size: "<<v.size<<endl;

    v.add(30);
    v.print();
    cout<<"Capacity: "<<v.capacity<<" "<<"Size: "<<v.size<<endl;

    v.remove();
    v.print();
    cout<<"Capacity: "<<v.capacity<<" "<<"Size: "<<v.size<<endl;

    v.add(40);
    v.print();
    cout<<"Capacity: "<<v.capacity<<" "<<"Size: "<<v.size<<endl;

    v.add(50);
    v.print();
    cout<<"Capacity: "<<v.capacity<<" "<<"Size: "<<v.size<<endl;

    v.add(60);
    v.print();
    cout<<"Capacity: "<<v.capacity<<" "<<"Size: "<<v.size<<endl;

    v.add(70);
    v.print();
    cout<<"Capacity: "<<v.capacity<<" "<<"Size: "<<v.size<<endl;


    cout<<"Number at index 5: "<<v.get(5)<<endl;
}