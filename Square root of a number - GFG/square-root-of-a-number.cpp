//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        // Your code goes here   
        long long i =1;
        long long j = x;
        int ans = -1;
        while(i<=j){
            
            long long mid = (i+j)/2;
            if(mid*mid<=x){
                ans = mid;
                i = mid+1;
            }
            else{
                j = mid-1;
            }
            
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends