//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> f( int n , int a[]){
        stack<int> s;
        vector<int> ans(n);
        s.push(-1);
        for(int i =0;i<n;i++){
            int curr = a[i];
            while(s.top()>=curr){
                s.pop();
            }
            ans[i]=s.top();
            s.push(curr);
        }
        
        return ans;
    }
    vector<int> leftSmaller(int n, int a[]){
        // code here
        
        vector<int> v(n);
        
        v = f(n,a);
        return v;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        vector<int> ans = ob.leftSmaller(n, a);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends