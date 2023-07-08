//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int characterReplacement(string s, int k) {
        // code here
        int i =0;
        int j = 0;
        int ans = 0;
        unordered_map<char,int> mp;
        int maxcount =0;
        while(j<s.length()){
            mp[s[j]]++;
            maxcount = max(maxcount,mp[s[j]]);
            while(j-i+1 - maxcount > k){
                mp[s[i]]--;
                i++;
            }

            ans = max(ans,j-i+1);
            j++;
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
        cout << obj.characterReplacement(S, K) << endl;
    }
    return 0;
}
// } Driver Code Ends