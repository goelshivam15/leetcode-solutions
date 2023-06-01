//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    
    
    int f(int index , int w , int wt[] , int val[] , int n){
        if(index==0){
            if(wt[0]<=w){
                return val[0];
            }
            else{
                return 0;
            }
        }
        
        int nottake = f(index-1,w,wt,val,n);
        int take = INT_MIN;
        if(wt[index]<=w){
            take = val[index]+ f(index-1,w-wt[index],wt,val,n);
        }
        
        
        return max(take,nottake);
    }
    int knapSack(int w, int wt[], int val[], int n) 
    { 
       // Your code here
       
      vwe
       
       for(int i = wt[0];i<=w;i++){
           dp[0][i]= val[0];
       }
       
       
       for(int index = 1;index<n;index++){
           for(int tar = 0;tar<=w;tar++){
               int nottake = dp[index-1][tar];
               
               int take = INT_MIN;
               if(wt[index]<=tar){
                   take = val[index]+dp[index-1][tar-wt[index]];
               }
               
               
               dp[index][tar]= max(take,nottake);
           }
       }
       
       
       return dp[n-1][w];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends