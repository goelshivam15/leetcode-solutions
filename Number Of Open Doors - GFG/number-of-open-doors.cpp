//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int noOfOpenDoors(long long n) {
        // code here
        
        long long i =1;
        int ans =-1;
        long long j = n;
        while(i<=j){
            long long mid = i+(j-i)/2;
            if(mid<=(n/mid)){
                ans = mid;
                i = mid+1;
            }
            else{
                j = mid-1;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.noOfOpenDoors(N) << endl;
    }
    return 0;
}
// } Driver Code Ends