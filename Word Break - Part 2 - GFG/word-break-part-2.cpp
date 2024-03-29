//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
void f(int ind, string &s, string temp, vector<string>& ans, set<string>& mp) {
        if(ind == s.length()) {
            temp.pop_back(); 
            ans.push_back(temp);
            return;
        }
        
        string cur = "";
        for(int i = ind; i < s.length(); i++) {
            cur.push_back(s[i]);
            if(mp.find(cur) != mp.end()) {
                f(i+1, s, temp + cur + " ", ans, mp);
            }
        }
    }
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
         vector<string> ans;
        set<string> mp (dict.begin(), dict.end());
        f(0, s, "", ans, mp);
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends