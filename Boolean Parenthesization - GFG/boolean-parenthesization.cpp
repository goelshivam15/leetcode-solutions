//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    // int f(int i , int j,int istrue, string s,vector<vector<vector<int>>>&dp){
        
    //     int mod = 1003;
    //     if(i>j){
    //         return 0;
    //     }
        
    //     if(i==j){
    //         if(istrue){
    //             return s[i]=='T';
    //         }
    //         else{
    //             return s[i]=='F';
    //         }
    //     }
        
    //     if(dp[i][j][istrue]!=-1){
    //         return dp[i][j][istrue];
    //     }
        
        
    //     int ways = 0;
    //     for(int index = i+1;index<=j-1;index = index+2){
    //         int lf = f(i,index-1,0,s,dp);
    //         int lt = f(i, index-1,1,s,dp);
    //         int rt = f(index+1,j,1,s,dp);
    //         int rf = f(index+1,j,0,s,dp);
            
    //         if(s[index]=='&'){
    //             if(istrue){
    //                 ways += (lt*rt)%mod;
    //             }
    //             else{
    //                 ways += ((rf*lt)%mod + (rt*lf)%mod)%mod;
    //             }
    //         }
    //         else if(s[index]=='|'){
    //             if(istrue){
    //                 ways += ((lt*rt)%mod + (lf*rt)%mod + (lt*rf)%mod)%mod;
    //             }
    //             else{
    //                 ways += (lf*rf)%mod;
    //             }
    //         }
    //         else{
    //             if(istrue){
    //                 ways += ((lf*rt)%mod + (lt*rf)%mod)%mod;
    //             }
    //             else{
    //                 ways += ((lf*rf)%mod + (rt*lt)%mod)%mod;
    //             }
    //         }
    //     }
        
    //     return dp[i][j][istrue]= ways;
    // }
    int f(int i, int j, int isTrue, string &exp, vector<vector<vector<long long>>> &dp) {
        int mod = 1003;
    
    if (i > j) return 0;
    
    if (i == j) {
        if (isTrue == 1) return exp[i] == 'T';
        else return exp[i] == 'F';
    }

    if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
    long long ways = 0;
    for (int ind = i + 1; ind <= j - 1; ind += 2) {
        long long lT = f(i, ind - 1, 1, exp, dp);
        long long lF = f(i, ind - 1, 0, exp, dp);
        long long  rT = f(ind + 1, j, 1, exp, dp);
        long long rF = f(ind + 1, j, 0, exp, dp);

        if (exp[ind] == '&') {
            if (isTrue) ways = (ways + (lT * rT) % mod) % mod;
            else ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lF * rF) % mod) % mod;
        }
        else if (exp[ind] == '|') {
            if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lT * rT) % mod) % mod;
            else ways = (ways + (lF * rF) % mod) % mod;
        }
        else {
            if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod) % mod;
            else ways = (ways + (lF * rF) % mod + (lT * rT) % mod) % mod;
        }
    }
    return dp[i][j][isTrue] = ways;
}
    int countWays(int n, string exp){
        // code here
        
        vector<vector<vector<long long>>> dp(n,vector<vector<long long>> (n,vector<long long>(2,-1)));
        return f(0,exp.length()-1,1,exp,dp);
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends