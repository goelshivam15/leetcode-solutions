//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int f(int index , int arr[] ,int n ){
        if(index==0){
            return arr[0];
        }
        
        if(index<0){
            return 0;
        }
        
        int take = arr[index]+f(index-2,arr,n);
        int nottake = f(index-1,arr,n);
        
        return max(take,nottake);
    }
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        vector<int> dp(n,0);
        
        dp[0]= arr[0];
        for(int i =1;i<n;i++){
            int nottake = dp[i-1];
            int take = arr[i];
            if(i>1){
                take += dp[i-2];
            }
            
            dp[i]= max(take,nottake);
        }
        
        return dp[n-1];
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
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends