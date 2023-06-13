//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  
  
  bool istwo(int n ){
      if(n<0){
          return false;
      }
      
      
      return n && (!(n&(n-1)));
  }
    int findPosition(int n) {
        // code here
        
        if(istwo(n)){
            return log2(n)+1;
        }
        
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}
// } Driver Code Ends