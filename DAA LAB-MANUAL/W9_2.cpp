#include<iostream> 
#include<vector> 
#include<algorithm> 
using namespace std; 
 
float MaxValue(vector<int> value, vector<int> weight, int w) { 
 
    vector<pair<float,int>> vec(value.size());  
    for(int i = 0; i < value.size(); i++) { 
        vec[i] = make_pair((float)value[i] / (float)weight[i], weight[i]); 
    } 
 
    sort(vec.rbegin(), vec.rend()); 
 
    float totalprice = 0; 
    for(int i = 0; i < vec.size(); i++) { 
        if(w >= vec[i].second) { 
            totalprice += vec[i].second * vec[i].first; 
            w -= vec[i].second; 
        } else {  
            totalprice += w * vec[i].first; 
            break; 
        } 
    } 
 
    return totalprice; 
} 
 
int main() { 
    int n; 
    cout<<"Enter total item:"<<endl; 
    cin>>n; 
    vector<int>value; 
    vector<int>weight; 
    int val,wt; 
    cout<<"Enter value,weight:"<<endl; 
    for(int i=0;i<n;i++){ 
        cin>>val>>wt; 
        value.push_back(val); 
        weight.push_back(wt); 
    } 
    int w; 
    cout<<"Enter capacity of knapsack:"<<endl; 
    cin>>w; 
    float res = MaxValue(value, weight, w); 
    cout << "Maximum value for " << w << " is: " << res << endl; 
    cout<<"\n*******************************************************************************"<<endl;
    cout<<"Program Prepared & Executed by:Muneef Khan,  Class Roll no.: 43,  Section A-1"<<endl;
    cout<<"*******************************************************************************\n"<<endl;

    return 0; 
} 