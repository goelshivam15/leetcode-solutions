//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int f(int index, int arr[],int n , int k,vector<int>&dp){
        if(index<=0){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        
        int take = INT_MIN;
        if(arr[index]-arr[index-1]<k){
            take = arr[index]+arr[index-1]+f(index-2,arr,n,k,dp);
        }
        
        int nottake = f(index-1,arr,n,k,dp);
        return dp[index]= max(take,nottake);
    }
    int maxSumPairWithDifferenceLessThanK(int arr[], int n, int k)
    {
        // Your code goes here   
        sort(arr,arr+n);
        vector<int> dp(n,-1);
        return f(n-1,arr,n,k,dp);
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++)
		cin>>arr[i];

		int K;
		cin>>K;
        Solution ob;
		cout<<ob.maxSumPairWithDifferenceLessThanK(arr,N,K)<<endl;
	}
	return 0;
}

// } Driver Code Ends