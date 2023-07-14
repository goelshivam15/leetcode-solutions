//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    bool valid(string &s){

    stack<char> st;
    for(int i =0;i<s.length();i++){
        if(s[i]=='('){
            st.push(s[i]);
        }
        else{
            if(st.empty()){
                return false;
            }
            else{
                if(st.top()=='('){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
    }

    if(st.empty()){
        return true;
    }
    return false;

}
    void printParenthesis(int ind,vector<string> &v,int n,int open,int close,string &s){
        if(ind == n){ // base case
            v.push_back(s); // we add final string to vector v
            return; // we return back the control to function
        }

        if(open > 0 && ind != n-1){ // we take "("
            s += "("; // adding "(" to string s
            printParenthesis(ind+1,v,n,open-1,close,s); // recursive function call
            s.pop_back(); // we have to take out "(" before returning the control to prev function. 
        }
        
        if(close > 0 && open < close){
            s += ")";
            printParenthesis(ind+1,v,n,open,close-1,s);
            s.pop_back();
        }

        return ;
       
    }
    vector<string> AllParenthesis(int n) 
    {
        
        vector<string> v;
        int open = n-1;
        int close = n;
        n *= 2;
        string s = "(";
        
        printParenthesis(1,v,n,open,close,s);

        return v;
        // Your code goes here 
    }
};

//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends