//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    void f(int index, vector<string>&ans , string s){
    	    if(index==s.size()){
    	        ans.push_back(s);
    	        return ;
    	    }
    	    
    	    for(int i =index;i<s.size();i++){
    	        swap(s[index],s[i]);
    	        f(index+1,ans,s);
    	        swap(s[index],s[i]);
    	    }
	    }
		vector<string>find_permutation(string s)
		{
		    // Code here there
		    vector<string> ans;
		    f(0,ans,s);
		    set<string> st;
		    for(int i =0;i<ans.size();i++){
		        st.insert(ans[i]);
		    }
		    vector<string> finalans;
		    for(auto it : st){
		        finalans.push_back(it);
		    }
		    
		    return finalans;
		    
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends