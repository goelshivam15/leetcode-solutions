//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    
	    int n = pat.length();
	    int m = txt.length();
	    int cnt =0;
	    if(m<n){
	        return 0;
	    }
	 
	   vector<int> text(26,0);
	   vector<int> pattern(26,0);
	    for(int i =0;i<n;i++){
	        pattern[pat[i]-'a']++;
	        text[txt[i]-'a']++;
	    }
	    
	    if(text==pattern){
	        cnt++;
	    }
	   for(int j = n;j<m;j++){
	       text[txt[j-n]-'a']--;
	       text[txt[j]-'a']++;
	       if(text==pattern){
	           cnt++;
	       }
	   }
	   return cnt;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends