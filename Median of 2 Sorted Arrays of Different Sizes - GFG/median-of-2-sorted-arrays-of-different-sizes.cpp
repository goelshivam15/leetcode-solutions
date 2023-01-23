//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    void f(vector<int>&array1, vector<int>&array2,vector<double>&ans){
        int m = array1.size();
        int n = array2.size();
        
        int i =0;
        int j = 0;
        int k =0;
        while(i<m && j<n){
            if(array1[i]>array2[j]){
                ans[k++]=array2[j++];
            }
            else{
                ans[k++]=array1[i++];
            }
        }
        
        
        while(i<m){
            ans[k++]=array1[i++];
        }
        
        while(j<n){
            ans[k++]=array2[j++];
        }
        
        
    }
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        // Your code goes here
        int m = array1.size();
        int n = array2.size();
        vector<double> ans(m+n);
        
        f(array1,array2,ans);
        
        int a = ans.size();
        
        if(a%2!=0){
            return ans[a/2];
        }
        
        
        double b = ans[a/2-1];
        double c = ans[a/2];
        
        return (b+c)/2;
        
    
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends