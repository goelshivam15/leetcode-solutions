//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{


	public:
	int findMaxSubarraySum(long long arr[], int n, long long k)
	{
	    // Your code goes here
	    int ans = 0;
	    int i =0;
	    int j = 0;
	    long long sum =0;
	    while(j<n){
	        sum += arr[j];
	        while(sum>k){
	            
	           sum -= arr[i];
	           i++;
	            
	        }
	        
	        ans = max(ans,(int)sum);
	        j++;
	    }
	    
	    return ans;
	}  

		 

};
	  



//{ Driver Code Starts.

int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
    	 int n;
        cin>>n;
        
        long long a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];
        
        long long sum;
        cin >> sum;
        

        Solution ob;
		cout << ob.findMaxSubarraySum(a, n, sum);
        
	    cout << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends