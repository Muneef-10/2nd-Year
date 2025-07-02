//We have to maximize the noumber of task.

#include<bits./stdc++.h>
using namespace std;
int main()
{
    int n,a,b;
    cout<<"Enter number of task: ";
    cin>>n;
    vector<pair<int,int>> task;

    cout<<"Enter time taken by task then deadline:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>a>>b;
        task.push_back({b,a});
    }
    //1- deadline  2-time taken
    sort(task.begin(),task.end());
    int time=0;

    priority_queue<pair<int,int>, vector<pair<int,int>>> pq; //max
    pq.push(task[0]);
    time=time+pq.top().second;
    
    for (int i = 1; i < n; i++)
    {
        if(time+task[i].second < task[i].first)  //
        {
            pq.push(task[i]);
            time+=pq.top().second;
        }
        else if(pq.size() && pq.top().second>task[i].second) //pq.size() means queue not empty
        {
            time-=pq.top().second;
            pq.pop();
            pq.push(task[i]);
            time+=pq.top().second;
        }
    }
    
    cout<<pq.size();

    
    return 0;
}