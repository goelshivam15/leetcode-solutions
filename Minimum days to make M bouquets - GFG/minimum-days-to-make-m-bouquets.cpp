//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  bool possible(vector<int>&bloom , int mid , int m , int k){
      int cnt =0;
      int temp = 0;
      for(int i =0;i<bloom.size();i++){
          if(bloom[i]<=mid){
              cnt++;
          }
          else{
              temp += (cnt/k);
              cnt =0;
          }
      }
      
      temp += (cnt/k);
      
      return temp>=m ;
  }
    int solve(int m, int k, vector<int> &bloom){
      // Code here
      
      int mini = *min_element(bloom.begin(),bloom.end());
      
      int maxi = *max_element(bloom.begin(),bloom.end());
      int ans = -1;
      
      long long value = m*1LL * k*1LL;
      if(value>bloom.size()){
          return -1;
      }
      
      int low = mini;
      int high = maxi;
      while(low<=high){
          int mid = (low+high)/2;
          
          if(possible(bloom,mid,m,k)){
              
              high = mid-1;
          }
          else{
              low = mid+1;
          }
      }
      
      return low;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, k;
    cin >> m >> k;
    string s;
    getline(cin, s);
    getline(cin, s);
    int n = s.length();
    int num = 0;
    bool f = 0;
    vector<int> bloomDay;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == ' ')
      {
        if (!f)
          continue;
        bloomDay.push_back(num);
        num = 0;
        f = 0;
      }
      else
      {
        num = (num * 10) + (s[i] - '0');
        f = 1;
      }
    }
    if (f)
    {
      bloomDay.push_back(num);
    }
    Solution obj;
    cout<<obj.solve(m, k, bloomDay)<<endl;
    }
    return 0;
}
// } Driver Code Ends