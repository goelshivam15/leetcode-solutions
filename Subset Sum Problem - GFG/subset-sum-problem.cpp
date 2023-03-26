//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

bool f(int index , vector<int>arr , int sum){
    if(sum==0){
        return true;
    }
    if(index==0){
        return arr[0]==sum;
    }
    
    bool nottake = f(index-1,arr,sum);
    bool take = false;
    if(arr[index]<=sum){
        take = f(index-1,arr,sum-arr[index]);
    }
    
    return take | nottake;
}
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        vector<vector<bool>> dp(arr.size(),vector<bool>(sum+1,0));
        for(int i =0;i<n;i++){
            dp[i][0]= true;
        }
        
        dp[0][arr[0]]= true;
        
        for(int index =1 ;index<n;index++){
            for(int target =1 ;target<=sum;target++){
                bool nottake = dp[index-1][target];
                bool take = false;
                if(arr[index]<=target){
                    take = dp[index-1][target-arr[index]];
                }
                
                dp[index][target]= take or nottake;
            }
        }
        
        return dp[n-1][sum];
    }
    
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends