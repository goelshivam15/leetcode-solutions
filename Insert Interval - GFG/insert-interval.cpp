//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<vector<int>> insertNewEvent(int n, vector<vector<int>> &intervals, vector<int> &newevent) {
        // code here
        
        vector<vector<int>> ans;
        
        int start = newevent[0];
        
        int pos = 0;
        
        for(int i =0;i<intervals.size();i++){
            if(intervals[i][0]>start){
                pos = i;
                ans.push_back(newevent);
                break;
                
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
        ans.push_back(newevent);
        
        for(int i = pos;i<intervals.size();i++){
            ans.push_back(intervals[i]);
        }
        
        vector<vector<int>> newans;
        vector<int> temp = ans[0];
        for(int i =1;i<ans.size();i++){
            if(ans[i][0]<=temp[1]){
                
                temp[1] = max(temp[1],ans[i][1]);
                
            }
            else{
               newans.push_back(temp);
               temp = ans[i];
            }
        }
        newans.push_back(temp);
        return newans;
        
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> intervals(N,vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0]>>intervals[i][1];
        }
        vector<int> newEvent(2);
        cin>>newEvent[0]>>newEvent[1];
        
        Solution obj;
        vector<vector<int>> ans = obj.insertNewEvent(N, intervals,newEvent);
        cout<<"[";
        for(int i=0;i<ans.size();i++){
            cout<<"["<<ans[i][0]<<','<<ans[i][1]<<']';
            if(i!=(ans.size()-1)) cout<<",";
        }
        cout<<"]"<<endl;
    }
    return 0;
}
// } Driver Code Ends