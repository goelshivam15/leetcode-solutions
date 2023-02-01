//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(int prev, int index, int n , int a[],vector<vector<int>>&dp){
        
        if(index==n){
            return 0;
        }
        if(dp[prev+1][index]!=-1){
            return dp[prev+1][index];
        }
        
        int take = INT_MIN;
        if(prev==-1 || abs(a[prev]-a[index])==1){
            take = 1+f(index, index+1,n,a,dp);
        }
        
        int nottake = f(prev,index+1,n,a,dp);
        
        return dp[prev+1][index]=max(take,nottake);
        
    }
    int longestSubsequence(int n, int a[])
    {
        // code here
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(-1,0,n,a,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}
// } Driver Code Ends