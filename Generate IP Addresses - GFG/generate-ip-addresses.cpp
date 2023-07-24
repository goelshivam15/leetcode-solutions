//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  
   void dfs(int i, int cnt, string &s, string t, vector<string> & ans) {
        if(i == s.size() && cnt == 4) {
            t.pop_back();
            ans.push_back(t);
            return;
        }
        if(cnt > 4) return;
        for(int j=i; j<min(i + 3, (int)s.size()); j++) {
            if(stoi(s.substr(i, j - i + 1)) <= 255 && (i == j || s[i] != '0')) {
                dfs(j + 1, cnt + 1, s, t + s.substr(i, j - i + 1) + ".", ans);
            }
        }
    }
    vector<string> genIp(string &s) {
        // Your code here
         vector<string> ans;
        if(s.size() > 12) return ans;

        dfs(0, 0, s, "", ans);
        return ans;
    }

};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        /*generating naively*/
        Solution obj;
        vector<string> str = obj.genIp(s);
        sort(str.begin(), str.end());
        if(str.size()==0)
            cout << -1 << "\n";
        else{
            for (auto &u : str) {
                cout << u << "\n";
            }
        }
    }
}
// } Driver Code Ends