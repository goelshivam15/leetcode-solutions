//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  
  int f(int index , int price[] , int n){
      if(index==0){
          return n*price[0];
      }
      
      
      
      int nottake = f(index-1,price,n);
      int take = INT_MIN;
      if(index+1<=n){
          take = price[index] + f(index,price,n-index-1);
      }
      
      return max(take,nottake);
  }
    int cutRod(int price[], int n) {
        //code here
        
        vector<vector<int>> dp(n,vector<int>(n+1,0));
        
        
        for(int len = 0;len<=n;len++){
            dp[0][len] = price[0]*len;
        }
        
        
        for(int index = 1;index<n;index++){
            for(int len = 0;len<=n;len++){
                int nottake = dp[index-1][len];
                int take = INT_MIN;
                if(index+1<=len){
                    take = price[index]+dp[index][len-index-1];
                }
                
                
                dp[index][len] = max(take,nottake);
            }
        }
        
        
        return dp[n-1][n];
        
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