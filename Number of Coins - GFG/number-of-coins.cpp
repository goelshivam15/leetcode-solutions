//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	
	int f(int index , int coins[] ,int m , int v,vector<vector<int>> &dp){
	    
	    if(index==0){
	        if(v%coins[index]==0){
	            return v/coins[index];
	        }
	        else{
	            return 1e9;
	        }
	    }
	    
	    if(dp[index][v]!=-1){
	        return dp[index][v];
	    }
	    
	    
	    int nottake = f(index-1,coins,m,v,dp);
	    int take = INT_MAX;
	    if(coins[index]<=v){
	        take = 1+f(index,coins,m,v-coins[index],dp);
	    }
	    
	    
	    return dp[index][v]= min(take,nottake);
	    
	}
	int minCoins(int coins[], int m, int v) 
	{ 
	    // Your code goes here
	    vector<vector<int>> dp(m,vector<int>(v+1,-1));
	    int ans = f(m-1,coins,m,v,dp);
	    
	    if(ans>=1e9){
	        return -1;
	    }
	    
	    return ans;
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends