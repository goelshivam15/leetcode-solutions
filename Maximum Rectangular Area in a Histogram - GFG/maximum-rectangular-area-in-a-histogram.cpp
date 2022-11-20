//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    vector<long long> prevsmallerelement(long long arr[],int n){
        
        vector<long long> ans(n);
        stack<long long> s;

        s.push(-1);
        for(long long i =0;i<n;i++){
            long long  curr = arr[i];
            while(s.top()!=-1 && arr[s.top()]>=curr){
                s.pop();

            }
            ans[i]=s.top();
            s.push(i);
        }

        return ans;
    }
    vector<long long> nextsmallerelement(long long arr[],int n){
        
        vector<long long> ans(n);
        stack<long long> s;

        s.push(-1);
        for(long long i =n-1;i>=0;i--){
            long long curr = arr[i];
            while(s.top()!=-1 && arr[s.top()]>=curr){
                s.pop();

            }
            ans[i]=s.top();
            s.push(i);
        }

        return ans;
    }
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        

        vector<long long> prev(n);
        vector<long long> next(n);
        prev = prevsmallerelement(arr,n);
        next =  nextsmallerelement(arr,n);
        long long area = INT_MIN;


        for(long long i =0;i<n;i++){

            long long length = arr[i];
            if(next[i]==-1){
                next[i]=n;
            }

            long long width = next[i]-prev[i]-1;
            long long newarea = length*width;
            area = max(area,newarea);
        }

        return area;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends