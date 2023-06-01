//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  
  int f(int index , vector<int>&a){
      int n = a.size();
      if(index>=n){
          return 0;
      }
      
     int op1 = a[index]+a[index+1]+f(index+3,a);
     int op2 = a[index]+f(index+2,a);
     int op3 = f(index+1,a);
     
     return max(op1,max(op2,op3));
  }
  int findMaxSum(vector<int>& a){
      //Code Here
      int n = a.size();
      vector<int> dp(n,0);
      
      dp[n-1]=a[n-1];
      
      for(int i = n-2;i>=0;i--){
          int op1 = a[i]+a[i+1];
          if(i+3<n){
              op1 += dp[i+3];
          }
          
          int op2 = a[i];
          if(i+2<n){
              op2 += dp[i+2];
          }
          
         int op3 = dp[i+1];
          
          dp[i]= max(op1,max(op2,op3));
          
      }
      
      return dp[0];
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