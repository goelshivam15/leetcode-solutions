//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  int f(int index, vector<int>&a,vector<int>&dp){
      if(index>=a.size()){
          return 0;
      }
      
      if(index==a.size()-1){
          return a[index];
      }
      
      if(dp[index]!=-1){
          return dp[index];
      }
      
      
      int op1 = a[index]+a[index+1]+f(index+3,a,dp);
      int op2 = a[index]+f(index+2,a,dp);
      int op3 = f(index+1,a,dp);
      
      return dp[index]= max(op1,max(op2,op3));
  }
  int findMaxSum(vector<int>& a){
      //Code Here
      vector<int> dp(a.size(),-1);
      return f(0,a,dp);
  }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        int ans = ob.findMaxSum(a);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends