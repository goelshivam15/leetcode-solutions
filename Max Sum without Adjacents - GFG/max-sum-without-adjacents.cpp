//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int f(int index , int *arr , int n){
	    if(index<0){
	        return 0;

	    }
	    if(index==0){
	        return 0;
	    }
	    
	    int nottake = f(index-1,arr,n);
	    int take = arr[index]+f(index-2,arr,n);
	    
	    return max(take,nottake);
	    
	    
	}
	int findMaxSum(int *arr, int n) {
	    // code here
	    
	    vector<int> dp(n,0);
	    int prev
	    for(int i =1;i<n;i++){
	        int  nottake = dp[i-1];
	        int take = arr[i];
	        if(i>1){
	            take += dp[i-2];
	        }
	        
	        dp[i] = max(take,nottake);
	    }
	    
	    
	    return dp[n-1];
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends