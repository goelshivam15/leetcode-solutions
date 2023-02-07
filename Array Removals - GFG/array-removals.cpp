//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int f(int i , int j , vector<int>&arr, int k,vector<vector<int>>&dp){
        if(i>j){
            return 0;
        }
        
        if(arr[j]-arr[i]<=k){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(arr[j]-arr[i]>k){
            dp[i][j]= 1+min(f(i+1,j,arr,k,dp),f(i,j-1,arr,k,dp));
        }
        
        return dp[i][j];
    }
    int removals(vector<int>& arr, int k){
        //Code here
        
        sort(arr.begin(),arr.end());
        vector<vector<int>> dp(arr.size(),vector<int>(arr.size(),-1));
        return f(0,arr.size()-1,arr,k,dp);
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution ob;
        int ans = ob.removals(arr,k);
        
        cout<<ans<<endl;
    }
}



// } Driver Code Ends