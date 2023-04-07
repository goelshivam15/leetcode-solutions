//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int n)
    {
        // your code here
        string ans = arr[0];
        int mini = arr[0].length();
        for(int i =0;i<n;i++){
            
            int j =0;
            while(j<arr[i].length() && arr[i][j]==ans[j]){
                j++;
            }
            
            mini = min(mini,j);
        }
        
       string temp = ans.substr(0,mini);
       if(temp==""){
           return "-1";
       }
       
       return temp;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends