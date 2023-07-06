//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:


int f(int n , int r,vector<vector<int>>&dp){
    
    int mod = 1e9+7;
    if(r>n){
        return 0;
    }
    
    if(r==n){
        return 1;
    }
    if(r==0){
        return 1;
    }
    if(dp[n][r]!=-1){
        return dp[n][r];
    }
    
    int ans = f(n-1,r,dp) + f(n-1,r-1,dp);
    
    
    
    return dp[n][r] = ans%mod;
}
    int nCr(int n, int r){
        // code here
        
        vector<vector<int>> dp(n+1,vector<int>(r+1,-1));
        
        return f(n,r,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends