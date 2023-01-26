//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int middle(int a, int b, int c){
        //code here//Position this line where user code will be pasted.
        int maxi = max(a,max(b,c));
        int mini = min(a,min(b,c));
        int ans =0;
        if(a>mini && a<maxi){
            ans = a;
        }
        else if(b>mini && b<maxi){
            ans = b;
            
        }else{
            ans = c;
        }
        
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
        int A,B,C;
        cin>>A>>B>>C;
        Solution ob;
        cout<<ob.middle(A,B,C) <<"\n";
    }
    return 0;
}
// } Driver Code Ends