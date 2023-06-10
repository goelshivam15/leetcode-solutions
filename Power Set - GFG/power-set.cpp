//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	
	
	    void f(int index , vector<string>&ans , string s,string temp){
	        if(index==s.length()){
	            if(temp!=""){
	                ans.push_back(temp);
	                
	            }
	            
	            return ;
	        }
	        
	        
	        f(index+1,ans,s,temp);
	        char ch = s[index];
	        temp.push_back(ch);
	        f(index+1,ans,s,temp);
	       
	        
	    }
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    
		    vector<string> ans;
		    string temp = "";
		    
		    
		    f(0,ans,s,temp);
		    sort(ans.begin(),ans.end());
		    return ans;
		    
		    
		    
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends