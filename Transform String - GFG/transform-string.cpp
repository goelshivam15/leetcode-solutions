//{ Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    
    int transform (string a, string b)
    {
        //code here.
        int n = a.length();
        int m = b.length();
        if(n!=m){
            return -1;
        }
        int count[256]={0};
        for(int i =0;i<n;i++){
            count[a[i]]++;
        }
        
        for(int i =0;i<n;i++){
            count[b[i]]--;
        }
        for(int i =0;i<256;i++){
            if(count[i]){
                return -1;
            }
        }
        
           int res = 0;
        for (int i = n - 1, j = n - 1; i >= 0;) {
            
            while (i >= 0 && a[i] != b[j]) {
                i--;
                res++;
            }
            
            if (i >= 0) {
                i--;
                j--;
            }
        }
        return res;
        
    }
};


//{ Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}
// } Driver Code Ends