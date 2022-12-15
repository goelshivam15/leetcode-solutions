//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(int index, int n , int arr[], int target,vector<vector<int>>&dp){
        if(index==n){
            return 0;
        }
        
        if(target==0){
            return 1;
        }
        if(dp[index][target]!=-1){
            return dp[index][target];
        }
        
        bool take = false;
        if(target>=arr[index]){
            take = f(index+1,n,arr,target-arr[index],dp);
        }
        bool nottake = f(index+1,n,arr,target,dp);
        return dp[index][target]= take | nottake;
        
    }
    int equalPartition(int n, int arr[])
    {
        // code here
        int sum =0;
        for(int i =0;i<n;i++){
            sum += arr[i];
        }
        
        if(sum&1){
            return 0;
        }
        else{
            vector<vector<int>> dp(n,vector<int>(sum/2+1,-1));
            return f(0,n,arr,sum/2,dp);
        }
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