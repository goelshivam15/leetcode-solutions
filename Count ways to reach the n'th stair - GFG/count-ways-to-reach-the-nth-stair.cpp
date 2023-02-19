//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    
    public:
    
    
    
    //Function to count number of ways to reach the nth stair.
    int f(int n ,vector<int>&dp){
        int mod = 1e9+7;
        if(n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }
        
        if(dp[n]!=-1){
            return dp[n];
        }
        
        
        dp[n]= (f(n-1,dp)%mod+f(n-2,dp)%mod)%mod;
        return dp[n];
    }
    int countWays(int n)
    {
        // your code here
        vector<int> dp(n+1,-1);
        return f(n,dp);
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends