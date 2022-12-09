//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long findMinSum(vector<int> &a,vector<int> &b,int n){
        
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int i =0;
        int j =0;
        long long sum =0;
        while(i<n && j <n){
            sum += abs(a[i]-b[j]);
            i++;
            j++;
        }
        return sum;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> A(N),B(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        for(int i=0;i<N;i++){
            cin>>B[i];
        }
        Solution ob;
        cout<<ob.findMinSum(A,B,N)<<endl;
    }
}
// } Driver Code Ends