//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/

    int f(int i , int j , string pattern , string str){
        if(i==0 && j==0){
            return 1;
        }
        
        
        if(i==0 && j>0){
            return 0;
        }
        
        if(i>0 && j==0){
            for(int k = 1;k<=i;k++){
                if(pattern[k-1]!='*'){
                    return 0;
                }
                
            }
            
            return 1;
        }
        
        
        if(pattern[i-1]==str[j-1] || pattern[i-1]=='?'){
            return f(i-1,j-1,pattern,str);
        }
        
        else if(pattern[i-1]=='*'){
            return f(i-1,j,pattern,str) or f(i,j-1,pattern,str);
        }
        else{
            return 0;
        }
    }
    int wildCard(string pattern,string str)
    {
        
        
        int n = pattern.length();
        int m = str.length();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        dp[0][0] = 1;
        
        for(int j = 1;j<=m;j++){
            dp[0][j]= 0;
        }
        
        
        for(int i =1;i<=n;i++){
            int flag = 1;
            for(int ii = 1;ii<=i;ii++){
                if(pattern[ii-1]!='*'){
                    flag = 0;
                    break;
                }
            }
            
            dp[i][0]= flag;
        }
        
        
        
        for(int i =1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                
                if(pattern[i-1]==str[j-1] || pattern[i-1]=='?'){
                    dp[i][j]= dp[i-1][j-1];
                }
                
                else if(pattern[i-1]=='*'){
                    dp[i][j]= (dp[i-1][j] or dp[i][j-1]);
                }
                else{
                    dp[i][j]=  0;
                }
                
            }
        }
        
        return dp[n][m];
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends