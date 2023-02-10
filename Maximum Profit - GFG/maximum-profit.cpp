//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int f(int index, int buy, int k , int n , int a[],vector<vector<vector<int>>>&dp){
        
        if(index==n){
            return 0;
        }
        if(k==0){
            return 0;
        }
        if(dp[index][buy][k]!=-1){
            return dp[index][buy][k];
        }
        
        int profit = INT_MIN;
        if(buy==1){
            profit = max(-a[index]+f(index+1,0,k,n,a,dp),f(index+1,1,k,n,a,dp));
        }
        else{
            profit = max(a[index]+f(index+1,1,k-1,n,a,dp),f(index+1,0,k,n,a,dp));
            
            
        }
        
        return dp[index][buy][k]= profit;
        
    }
    int maxProfit(int k, int n, int a[]) {
        // code here
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return f(0,1,k,n,a,dp);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends