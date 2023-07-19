//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
  string f(int n ){
    if(n==1){
        return "1";
    }

    string temp = f(n-1);
    string ans = "";
    int i =0;
    while(i<temp.length()){
        int j = i;
        int cnt = 0;
        while(j<temp.length() && temp[j]==temp[i]){
           cnt++;
           j++;

        }
    
        char ch  = cnt + '0';
        ans.push_back(ch);
        ans.push_back(temp[i]);
        i=j;

    }

    return ans;

}
    string lookandsay(int n) {
        // code here
        return f(n);
    }   
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution obj;
        cout<<obj.lookandsay(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends