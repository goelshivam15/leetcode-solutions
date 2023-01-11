//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(int i , int j , int n , int m , vector<vector<int>>&M,vector<vector<int>>&dp){
        
        if(i<0 || i==n || j==m){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int right = M[i][j]+f(i,j+1,n,m,M,dp);
        int updg = M[i][j]+f(i-1,j+1,n,m,M,dp);
        int downdg = M[i][j]+f(i+1,j+1,n,m,M,dp);
        return dp[i][j]= max(right,max(updg,downdg));
    }
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        int maxi = -1e9;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i =0;i<n;i++){
            maxi = max(maxi,f(i,0,n,m,M,dp));
        }
        
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends