//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string s)
{
    // your code here
    int l =0;
    int r =0;
    int maxlength = INT_MIN;
    int arr[256]={0};
    while(r<s.length()){
        arr[s[r]]++;
        while(arr[s[r]]>1){
            arr[s[l]]--;
            l++;
        }
        
        maxlength = max(maxlength,r-l+1);
        r++;
    }
    
    return maxlength;
}