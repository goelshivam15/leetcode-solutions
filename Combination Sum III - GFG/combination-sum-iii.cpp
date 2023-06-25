//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  
  
  void f(int i , int k , int n , set<vector<int>>&st,vector<int>&temp,vector<vector<int>>&ans){
      
     if(!k||!n){
            if(!k&&!n) ans.push_back(temp);
            return;
        }
      
      for(int num =i;num<=9;num++){
          if(i>n){
              return ;
          }
          temp.push_back(num);
          f(num+1,k-1,n-num,st,temp,ans);
          temp.pop_back();
      }
      
      
  }
    vector<vector<int>> combinationSum(int k, int n) {
        // code here
        set<vector<int>> st;
        vector<vector<int>> ans;
        int sum = 0;
        vector<int> temp;
        
        f(1,k,n,st,temp,ans);
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K >> N;

        Solution obj;
        vector<vector<int>> ans = obj.combinationSum(K, N);
        sort(ans.begin(), ans.end());
        for (auto &arr : ans) {
            for (auto it : arr) cout << it << ' ';
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends