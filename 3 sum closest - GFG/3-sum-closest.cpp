//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int closest3Sum(int nums[], int n, int target)
    {
        // code here
         int diff = INT_MAX;
        sort(nums,nums+n);
        int ans = 0;
        for(int i =0;i<n-2;i++){
            int j = i+1;
            int k = n-1;
            while(j<k){
                int curr_sum = nums[i] + nums[j] + nums[k];
                if(curr_sum==target){
                    return target;
                }
                if(abs(curr_sum-target)<diff){
                    diff = abs(curr_sum-target);
                    ans = curr_sum;
                }
                if(curr_sum>target){
                    k--;
                }
                else if(curr_sum<target){
                    j++;
                }
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
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int X;
        cin>>X;
        Solution obj;
        cout<<obj.closest3Sum(Arr, N, X)<<endl;
    }
    return 0;
}
// } Driver Code Ends