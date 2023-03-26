//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &arr, int n ) {
        //code here
        
        long long int cnt=0;
        long long int i =0;
        long long int sum =0;
        unordered_map<long long int,long long int> mp;
        while(i<n){
            
            sum += arr[i];
            if(sum==0){
                cnt++;
            }
            
            if(mp.find(sum)!=mp.end()){
                cnt += mp[sum];
            }
            
            
            mp[sum]++;
            i++;
            
            
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<long long int> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}
// } Driver Code Ends