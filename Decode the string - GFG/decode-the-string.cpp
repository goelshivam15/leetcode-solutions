//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        // code here
         string ans = "";
        stack<char> st;
        for(int i =0;i<s.length();i++){
            if(s[i]==']'){
                string temp1 = "";
                while(st.top()!='['){
                    temp1 += st.top();
                    st.pop();
                }
                reverse(temp1.begin(),temp1.end());
                st.pop();
                string temp2 = "";
                while(!st.empty() && (st.top()>='0' && st.top()<='9')){
                    temp2 += st.top();
                    st.pop();
                }
                reverse(temp2.begin(),temp2.end());
                int num = stoi(temp2);
                string shivam = "";

                for(int i =1;i<=num;i++){
                    shivam += temp1;
                }
                // ans += shivam;
                for(auto ch : shivam){
                    st.push(ch);
                }
            }
            else{
                st.push(s[i]);
            }
        }

        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends