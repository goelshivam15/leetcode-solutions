//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    static const int mod = 1e8;
    int f(int n ,vector<int>&dp){
        if(n==0){
            return 1;
        }
        
        if(n==1){
            return 1;
        }
        
        if(n==2){
           
            return 2;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        
        int ans =0;
        ans = (f(n-1,dp)%mod+f(n-2,dp)%mod)%mod;
        return dp[n]= ans;
    }
    int fillingBucket(int n) {
        // code here
        vector<int> dp(n+1,-1);
        return f(n,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends