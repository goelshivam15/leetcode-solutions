//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int f(int index, int n , int k , vector<int>&arr,vector<int>&dp){
        if(index==n){
            return 0;
        }
        
        if(dp[index]!=-1){
            return dp[index];
        }
        int maxi = INT_MIN;
        int maxans = INT_MIN;
        int len =0;
        for(int j = index;j<min(index+k,n);j++){
            len++;
            maxi = max(maxi,arr[j]);
            int sum = (len*maxi)+f(j+1,n,k,arr,dp);
            maxans = max(maxans,sum);
        }
        
        return dp[index]=maxans;
    }
    int solve(int n, int k, vector<int>& arr){
        // Code here
        vector<int> dp(n,-1);
        return f(0,n,k,arr,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            int x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        cout<<obj.solve(n,k,arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends