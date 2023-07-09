//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    int numberOfSubarrays(vector<int>& arr, int n, int target){
        // code here
        
       int cnt =0;
       int sum = 0;
       
       unordered_map<int,int> mp;
       mp[0]=1;
       for(int i =0;i<n;i++){
           sum += arr[i];
           if(mp.find(sum-target)!=mp.end()){
               cnt += mp[sum-target];
           }
           
           mp[sum]++;
           
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
        int N;
        cin >> N;
        int target; 
        cin >> target;
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin >> arr[i];
        Solution obj;
        cout<<obj.numberOfSubarrays(arr, N, target)<<endl;
    }
    return 0;
}
// } Driver Code Ends