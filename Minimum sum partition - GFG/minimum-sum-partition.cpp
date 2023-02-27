//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    
	    int totsum =0;
	    for(int i =0;i<n;i++){
	        totsum += arr[i];
	    }
	    
	    int k = totsum ;
	    
	    vector<bool> prev(k+1,0);
	    vector<bool> curr(k+1,0);
	    
	    
	    prev[0]= true;
	    curr[0]= true;
	    
	    
	    for(int i =0;i<n;i++){
	        prev[0]= true;
	    }
	    
	     if(arr[0]<=k) prev[arr[0]] = true;
	    for(int i =1;i<n;i++){
	        for(int target = 1;target<=k;target++){
	            bool nottake = prev[target];
	            bool take = false;
	            if(arr[i]<=target){
	                take = prev[target-arr[i]];
	            }
	            
	            
	            curr[target] = take or nottake;
	        }
	        
	        prev = curr;
	    }
	    
	    int mini = 1e9;
	    for(int s1 =0;s1<=totsum/2;s1++){
	        if(prev[s1]==true){
	            mini = min(mini,abs((totsum-s1)-s1));
	        }
	    }
	    
	    return mini;
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
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends