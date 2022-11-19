//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int n){
        // code here
        vector<long long int> ans;
        map<long long int,long long int> mp;
        
        for(long long int i =0;i<n;i++){
            
            mp[Arr[i]]++;
            
        }
        
        
        for(auto it : mp){
            if(it.second%2 !=0){
                ans.push_back(it.first);
            }
        }
        
        if(ans[0]<ans[1]) swap(ans[0],ans[1]);
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
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends