//{ Driver Code Starts
//Initial Template for CPP

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long maxTripletProduct(long long nums[], int n)
    {
    	// Complete the function
    	
        long long  neg =0;
        long long  maxi = -1e9;
        sort(nums,nums+n);
        for(int i =0;i<n;i++){
            if(nums[i]<0){
                neg++;
            }
        }

        if(neg<=1){
            maxi = max(maxi,nums[n-1]*nums[n-2]*nums[n-3]);
        }
        else{
            maxi = max(nums[0]*nums[1]*nums[n-1],nums[n-1]*nums[n-2]*nums[n-3]);
        }

        return maxi;
        


    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    cin>>n; long long arr[n];
	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    Solution ob;
	    cout <<ob.maxTripletProduct(arr, n);
	    cout<<"\n";
	}
    return 0;
}
// } Driver Code Ends