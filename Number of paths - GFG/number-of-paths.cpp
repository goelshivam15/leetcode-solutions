//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends

long long f(int i , int j , int m ,int n,vector<vector<long long >>&dp ){
    if(i==0 && j==0){
        return 1;
    }
    if(i<0 || j<0){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    
    int up = f(i-1,j,m,n,dp);
    int left = f(i,j-1,m,n,dp);
    
    return dp[i][j]= up+left;
}

long long  numberOfPaths(int m, int n)
{
    // Code Here
    vector<vector<long long>> dp(m,vector<long long>(n,-1));
    return f(m-1,n-1,m,n,dp);
}

//{ Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>m>>n;
	    cout << numberOfPaths(m, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends