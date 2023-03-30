//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countSubstring(string s)
    {
        // code here
        int count=0;
        int n = s.length();
        for(int i =0;i<n;i++){
            string temp ="";
            int lower =0;
            int upper=0;
            for(int j =i;j<n;j++){
                
                if(s[j]>='a' && s[j]<='z'){
                    lower++;
                    
                }
                else{
                    upper++;
                }
                
                if(lower==upper){
                    count++;
                }
            }
        }
        return count;
        
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
        cout<<obj.countSubstring(S)<<endl;
    }
}  
// } Driver Code Ends