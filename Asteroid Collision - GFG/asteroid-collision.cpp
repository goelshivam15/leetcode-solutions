//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int n, vector<int> &asteroids) {
        // code here
        
        vector<int> ans;
        stack<int> st;
        
       for(int i =0;i<n;i++){
           if(asteroids[i]<0 && st.size()==0){
               ans.push_back(asteroids[i]);
           }
           else if(asteroids[i]>0){
               st.push(asteroids[i]);
               
           }
           else if(asteroids[i]<0 && st.size()!=0){
               while(!st.empty()){
                   if(st.top()>abs(asteroids[i])){
                       break;
                   }
                   else if(st.top()==abs(asteroids[i])){
                       st.pop();
                       break;
                   }
                   else{
                       st.pop();
                       if(st.size()==0){
                           ans.push_back(asteroids[i]);
                       }
                   }
               }
           }
       }
       vector<int> out;
       while(!st.empty()){
           out.push_back(st.top());
           st.pop();
           
       }
       
       reverse(out.begin(),out.end());
       for(int i =0;i<out.size();i++){
           
           ans.push_back(out[i]);
           
       }
       
       return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends