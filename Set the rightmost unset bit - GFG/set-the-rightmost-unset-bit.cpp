//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    int setBit(int n)
    {
        // Write Your Code here
       
       int pos = 0;
       int temp =-1;
       int a = n;
       while(n>0){
          if(!(n&1)){
              temp = pos;
              break;
          }
          else{
              pos++;
              n= n>>1;
          }
       }
       
       if(temp==-1){
           return a;
       }
       else{
           return a + pow(2,pos);
       }
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        int ans = ob.setBit(N);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends