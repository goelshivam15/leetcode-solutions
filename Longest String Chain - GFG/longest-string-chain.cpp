//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  bool check(string &a, string &b){
    if(a.length()!=b.length()+1){
        return false;
    }

    int first = 0;
    int second = 0;
    while(first<a.length()){
        if(a[first]!=b[second]){
            first++;
        }
        else{
            first++;
            second++;
        }
    }

    if(first==a.size() && second==b.size()) return true;
    return false;
}

static bool cmp(string & a, string &b){
    return a.size()<b.size();
}
    int longestChain(int n, vector<string>& words) {
        // Code here
          
        sort(words.begin(),words.end(),cmp);

        vector<int> dp(n,1);

        for(int i=0;i<n;i++){
            for(int prev = 0;prev<=i;prev++){
                if(check(words[i],words[prev]) && 1+dp[prev]>dp[i]){
                    dp[i] = 1+ dp[prev];
                }
            }
        }

        int maxi = 0;
        for(int i =0;i<n;i++){
            maxi = max(maxi,dp[i]);
        }

        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> words(N);
        for (int i = 0; i < N; i++) {
            cin >> words[i];
        }
        Solution obj;
        cout << obj.longestChain(N, words) << "\n";
    }
    return 0;
}
// } Driver Code Ends