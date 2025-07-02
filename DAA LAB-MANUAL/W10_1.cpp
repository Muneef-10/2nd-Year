#include<iostream> 
#include<vector> 
#include<algorithm> 
using namespace std; 
int MaxActivity(vector<pair<int,int>>&activity){ 
    sort(activity.begin(), activity.end(), [](const pair<int,int>& a, const pair<int,int>& b){ 
        return a.second < b.second; 
    }); 
    int count=1; 
    int currEndTime=activity[0].second; 
    for(int i=1;i<activity.size();i++){ 
        if(activity[i].first>=currEndTime){ 
            count++; 
            currEndTime=activity[i].second; 
        } 
    } 
    return count; 
} 
int main(){ 
    int n; 
    cout<<"Enter total no. of activity:"; 
    cin>>n; 
    vector<pair<int,int>>activity(n);  
    int start,end; 
    cout<<"Enter start & end time:"<<endl; 
    for(int i=0;i<n;i++){ 
        cin>>start>>end; 
        activity[i]={start,end}; 
    } 
    cout<<"Maximum actitvity can perform:"<<MaxActivity(activity)<<endl;
    cout<<"\n*******************************************************************************"<<endl;
    cout<<"Program Prepared & Executed by:Muneef Khan,  Class Roll no.: 43,  Section A-1"<<endl;
    cout<<"*******************************************************************************\n"<<endl;
 
    return 0; 
}