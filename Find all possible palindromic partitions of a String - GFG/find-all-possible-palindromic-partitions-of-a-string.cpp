//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
   void partitionHelper(int idx, string s, vector<string>& temp, vector<vector<string>>& ans) {
        if (idx == s.size()) {
            ans.push_back(temp);
            return;
        }
        for (int i = idx; i < s.size(); i++) {
            if (palindrome(s, idx, i) == true) {
                temp.push_back(s.substr(idx, i-idx+1));
                partitionHelper(i+1, s, temp, ans);
                temp.pop_back();
            }
        }
    }

    bool palindrome(string s, int start, int end) {
        while (start <= end) {
            if (s[start] != s[end])
                return false;
            start++;
            end--;    
        }
        return true;
    }
    vector<vector<string>> allPalindromicPerms(string s) {
        // code here
         vector<vector<string>> ans;
        vector<string> temp;
        partitionHelper(0, s, temp, ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends