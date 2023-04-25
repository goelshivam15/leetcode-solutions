//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    int f(int i , int j , vector<vector<int>>&triangle,vector<vector<int>>&dp){
        int n = triangle.size();
        if(i==n-1){
            return triangle[n-1][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int down = triangle[i][j]+f(i+1,j,triangle,dp);
        int dg = triangle[i][j]+f(i+1,j+1,triangle,dp);
        
        return dp[i][j]= min(down,dg);
    }
    int minimizeSum(int n, vector<vector<int>>& triangle) {
        // Code here
        vector<vector<int>> dp(n,vector<int>(n,0));
        
        for(int j = 0;j<n;j++){
            dp[n-1][j]= triangle[n-1][j];
        }
        
        for(int i = n-2;i>=0;i--){
            for(int j = i;j>=0;j--){
                int up = triangle[i][j]+ dp[i+1][j];
                int dg = triangle[i][j]+ dp[i+1][j+1];
                
                dp[i][j]= min(up,dg);
            }
        }
        
        return dp[0][0];
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> triangle;

        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j <= i; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            triangle.push_back(temp);
        }
        Solution obj;
        cout << obj.minimizeSum(n, triangle) << "\n";
    }
    return 0;
}
// } Driver Code Ends