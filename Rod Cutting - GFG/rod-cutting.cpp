//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    
    int f(int index , int n , int price[],vector<vector<int>>&dp){
        if(index==0){
            return n*price[0];
        }
        if(dp[index][n]!=-1){
            return dp[index][n];
        }
        
        int take = INT_MIN;
        int rodlength= index+1;
        if(rodlength<=n){
            take = price[index]+f(index,n-rodlength,price,dp);
        }
        
        int nottake = f(index-1,n,price,dp);
        
        return dp[index][n]= max(take,nottake);
    }
    int cutRod(int price[], int n) {
        //code here
        
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return f(n-1,n,price,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends