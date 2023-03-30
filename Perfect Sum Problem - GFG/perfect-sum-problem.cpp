//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	
	int f(int index , int arr[] , int n , int sum,vector<vector<int>>&dp){
	    int mod = (int)1e9+7;
	   if(index==0){
	       if(sum==0 && arr[0]==0){
	           return 2;
	       }
	       if(sum==0 || arr[0]==sum){
	           return 1;
	       }
	       return 0;
	   }
	   
	   if(dp[index][sum]!=-1){
	       return dp[index][sum];
	   }
	    
	    int nottake = f(index-1,arr,n,sum,dp);
	    int take =0;
	    if(arr[index]<=sum){
	        take = f(index-1,arr,n,sum-arr[index],dp);
	    }
	    
	    return dp[index][sum]=(take+nottake)%mod;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        int mod = 1e9+7;
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return f(n-1,arr,n,sum,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends