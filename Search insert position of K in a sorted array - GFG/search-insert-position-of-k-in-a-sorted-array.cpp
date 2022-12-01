//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int searchInsertK(vector<int>arr, int n, int k)
    {
        // code here
        sort(arr.begin(),arr.end());
        int i =0;
        int j = arr.size()-1;
        int mid = (i+j)/2;
        while(i<=j){
            
            if(arr[mid]==k){
                return mid;
            }
            else if(arr[mid]>k){
                j = mid-1;
            }
            else{
                i++;
            }
            
            mid= (i+j)/2;
        }
        
        if(arr[mid]<k){
            return mid+1;
        }
        else{
            return mid;
        }
        
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
        vector<int>Arr(N);
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.searchInsertK(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends