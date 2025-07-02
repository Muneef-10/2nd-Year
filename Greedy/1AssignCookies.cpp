#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> greed={1,5,3,3,4};
    vector<int> cookie={4,2,1,2,1,3};

    sort(greed.begin(),greed.end());
    sort(cookie.begin(),cookie.end());

    int left=0,right=0;
    int n=greed.size(), m=cookie.size();
    while(left < n && right < m)
    {
        if(cookie[right] >= greed[left])
        {
            left++;
            right++;
        }
        else
            right++;

    }
    cout<<"Number of children :"<<left;
    
    return 0;
}
/*//{ Driver Code Starts
// Driver code
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution 

{
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        vector<pair<int,int>> jobs;
        int profitcount=0,count=0,maxdeadline=-1;
        
        int n=deadline.size();
        for(int i=0;i<n;i++)
            jobs.push_back({profit[i],deadline[i]});
        
        
        for(int i=0;i<n;i++)
            maxdeadline=max(maxdeadline,jobs[i].second);
            
        sort(jobs.rbegin(),jobs.rend());
        vector<bool> hash(maxdeadline+1,false);
        
        for(int i=0;i<n;i++)
        {
            for(int j=jobs[i].second;i>0;i--)
            {
                if(hash[j]==false)
                {
                    hash[j]=true;
                    count++;
                    profitcount+=jobs[i].first;
                    break;
                }
            }
        }
        return {count,profitcount};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> deadlines, profits;
        string temp;
        getline(cin, temp);
        int x;
        istringstream ss1(temp);
        while (ss1 >> x)
            deadlines.push_back(x);

        getline(cin, temp);
        istringstream ss2(temp);
        while (ss2 >> x)
            profits.push_back(x);

        Solution obj;
        vector<int> ans = obj.jobSequencing(deadlines, profits);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends*/