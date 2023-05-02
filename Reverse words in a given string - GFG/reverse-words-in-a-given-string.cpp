//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        // code here 
        
        string ans = "";
        for(int i =s.length()-1;i>=0;i--){
            
          if(s[i]=='.'){
              continue;
          }
          else{
              string temp = "";
              while(i>=0 && s[i]!='.'){
                  temp += s[i];
                  i--;
                   
              }
              reverse(temp.begin(),temp.end());
              ans += temp;
              ans += ".";
              
          }
        }
        
        ans.pop_back();
        return ans;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends