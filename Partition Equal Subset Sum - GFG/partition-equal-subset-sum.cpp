//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(int index, int arr[], int sum,vector<vector<int>>&dp){
        if(index==0){
            if(arr[index]==sum){
                return 1;
            }
            else{
                return 0;
            }
        }
        
        if(dp[index][sum]!=-1){
            return dp[index][sum];
        }
        
        int take = false;
        if(arr[index]<=sum){
            take = f(index-1,arr,sum-arr[index],dp);
        }
        
        int nottake = f(index-1,arr,sum,dp);
        
        return dp[index][sum]= take or nottake;
    }
    int equalPartition(int n, int arr[])
    {
        // code here
        int tsum =0;
        for(int i=0;i<n;i++){
            
            tsum+=arr[i];
            
        }
        
        if(tsum&1){
            return 0;
        }
        
        int sum = tsum/2;
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return f(n-1,arr,sum,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends