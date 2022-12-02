//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long f(int n , int k,vector<int>&dp){
        
        int mod = 1e9+7;
        if(n==1){
            return k;
        }
        
        if(n==2){
            return k + k*(k-1);
            
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        
        int ans =0;
        
        ans= (((f(n-1,k,dp)%mod)*((k-1)%mod))%mod + ((f(n-2,k,dp)%mod)*((k-1)%mod))%mod)%mod;
        return dp[n]=ans;
        
        
    }
    long long countWays(int n, int k){
        // code here
        vector<int> dp(n+1,-1);
        return f(n,k,dp);
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends