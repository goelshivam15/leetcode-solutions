//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int solve(int index , int w , int wt[], int val[], int n,vector<vector<int>>&dp){
        if(index==n){
            return 0;
        }
        if(dp[index][w]!=-1){
            return dp[index][w];
        }
        
        
        int take = INT_MIN;
        if(wt[index]<=w){
            take = val[index]+solve(index+1,w-wt[index],wt,val,n,dp);
        }
        int nottake = solve(index+1,w,wt,val,n,dp);
        
        return dp[index][w]=max(take,nottake);
    }
    int knapSack(int w, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n,vector<int>(w+1,-1));
       return solve(0,w,wt,val,n,dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends