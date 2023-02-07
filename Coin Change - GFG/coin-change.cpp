//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int f(int index, int coins[],int n ,int sum,vector<vector<long long int>>&dp){
        
        if(index==0){
            if(sum%coins[index]==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        
        if(dp[index][sum]!=-1){
            return dp[index][sum];
        }
        
        long long int take = 0;
        if(coins[index]<=sum){
            take = f(index,coins,n,sum-coins[index],dp);
        }
        long long int nottake = f(index-1,coins,n,sum,dp);
        return dp[index][sum]= take + nottake;
        
    }
    long long int count(int coins[], int n, int sum) {


        // code here.
        vector<vector<long long int>> dp(n,vector<long long int>(sum+1,-1));
        return f(n-1,coins,n,sum,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends