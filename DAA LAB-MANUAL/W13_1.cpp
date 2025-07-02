#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main(){
    int n;
    cout<<"Enter no: of character:";
    cin>>n;
    vector<char>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    map<char,int>map;
    for(auto it:arr){
        map[it]++;
    }
    for(auto it:map){
        cout<<it.first<<" "<<it.second<<endl;
    }
    cout<<"\n*******************************************************************************"<<endl;
    cout<<"Program Prepared & Executed by:Muneef Khan,  Class Roll no.: 43,  Section A-1"<<endl;
    cout<<"*******************************************************************************\n"<<endl;

    return 0;
}
