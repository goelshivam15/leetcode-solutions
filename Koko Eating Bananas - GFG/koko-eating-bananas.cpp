//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  
  int f(vector<int>&piles , int hours){
      int cnt =0;
      int n = piles.size();
      for(int i =0;i<n;i++){
          cnt += ceil((double)piles[i]/(double)hours);
      }
      
      return cnt;
  }
    int Solve(int n, vector<int>& piles, int h) {
        // Code here
        
        int maxi = *max_element(piles.begin(),piles.end());
        int ans = INT_MAX;
        int low = 1;
        int high = maxi;
        while(low<=high){
            int mid = (low+high)/2;
            int cnt = f(piles,mid);
            if(cnt<=h){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
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
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends