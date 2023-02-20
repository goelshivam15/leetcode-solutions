//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    public:
    
    bool f(int i , int j, string wild , string pattern){
        if(i<0 && j<0){
            return true;
        }
        
        if(i<0 && j>=0){
            return false;
        }
        
        if(i>=0 && j<0){
            for(int k =0;k<i;k++){
                if(wild[k]!='*'){
                    return false;
                }
            }
            
            return true;
        }
        
        
        if(wild[i]==pattern[j] || wild[i]=='?'){
            return f(i-1,j-1,wild,pattern);
        }
        else if(wild[i]=='*'){
            return f(i-1,j,wild,pattern) or f(i,j-1,wild,pattern);
        }
        else{
            return false;
        }
    }
    bool match(string wild, string pattern)
    {
        // code here
        
        return f(wild.size()-1,pattern.size()-1,wild,pattern);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        if(ob.match(wild, pattern))
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends