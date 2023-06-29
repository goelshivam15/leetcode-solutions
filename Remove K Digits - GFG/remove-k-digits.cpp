//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string num, int k) {
         int n = num.length();

        if(n<=k){
            return "0";
        }
        if(k==0){
            return num;
        }

        string ans = "";

        stack<char> st;
       int i =0;
       while(i<n){
           if(st.empty()){
               st.push(num[i]);
               i++;
               continue;
           }
           while(k>0 && !st.empty()){
                   if(st.top()>num[i]){
                       st.pop();
                       k--;
                   }
                   else{
                       break;
                   }
            }
            st.push(num[i]);
            i++;       
           
       }

       while(k--){
           st.pop();

       }
       while(!st.empty()){
           ans.push_back(st.top());
           st.pop();
       }

       reverse(ans.begin(),ans.end());
       while(!ans.empty() && ans[0]=='0'){
           ans.erase(ans.begin());
       }

       if(ans.empty()){
           return "0";
       }
       return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends