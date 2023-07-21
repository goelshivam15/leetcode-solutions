//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
int f(int i , int j , vector<int>&nums,vector<vector<int>>&dp){
    if(i>j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int maxi = INT_MIN;
    for(int index =i;index<=j;index++){

        int cost = nums[i-1]*nums[index]*nums[j+1] + f(i,index-1,nums,dp) + f(index+1,j,nums,dp);
        maxi = max(maxi,cost);

    }

    return dp[i][j]= maxi;
}
    int maxCoins(int n, vector<int> &nums) {
        // code here
        
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return f(1,n,nums,dp);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution obj;
        cout << obj.maxCoins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends