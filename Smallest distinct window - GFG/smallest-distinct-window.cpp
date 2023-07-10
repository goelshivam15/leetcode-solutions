//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here   
        
        int mini = INT_MAX;
        unordered_set<char> st(str.begin(),str.end());
        unordered_map<char,int> mp;
        int cnt = st.size();
        int i =0;
        int j =0;
        for(auto ch : str){
            mp[str[j]]++;
            while(mp.size()==cnt){
                mini = min(mini,j-i+1);
                
                mp[str[i]]--;
                if(mp[str[i]]==0){
                    mp.erase(str[i]);
                }
                
                i++;
            }
            
            j++;
            
            
            
            
        }
        
        return mini;
        
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends