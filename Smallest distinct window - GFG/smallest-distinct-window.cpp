//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here  
        set<char> st;
        for(int i =0;i<str.size();i++){
            st.insert(str[i]);
        }
        int n = st.size();
        unordered_map<char,int> mp;
        int i =0;
        int j =0;
        int ans = str.size();
        while(i<str.size()){
            mp[str[i]]++;
            if(mp.size()==n){
                
                while(mp[str[j]]>1){
                    
                    mp[str[j++]]--;
                    
                }
                ans = min(ans,i-j+1);
                
            }
            i++;
            
        }
        return ans;
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