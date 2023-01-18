//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int f(int index1, int index2, int x , int y , string s1 , string s2,vector<vector<int>>&dp){
        if(index1==x || index2==y){
            return 0;
        }
        
        if(dp[index1][index2]!=-1){
            return dp[index1][index2];
        }
        
        int take = INT_MIN;
        if(s1[index1]==s2[index2]){
            take = 1+f(index1+1,index2+1,x,y,s1,s2,dp);
        }
        
        int nottake = max(f(index1+1,index2,x,y,s1,s2,dp),f(index1,index2+1,x,y,s1,s2,dp));
        
        
        return dp[index1][index2]= max(take , nottake);
    }
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        vector<vector<int>> dp(x,vector<int>(y,-1));
        return f(0,0,x,y,s1,s2,dp);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends