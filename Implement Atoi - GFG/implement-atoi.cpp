//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
  
    /*You are required to complete this method */
    bool isnum(char ch){
        if(ch=='0' ||ch=='1' || ch=='2' || ch=='3' || ch=='4' || ch=='5' || ch=='6' || ch=='7' || ch=='8' || ch=='9'){
            return true;
        }
        return false;
    }
    int atoi(string str) {
        //Your code here
        int ten = 1;
        int cnt = 0;
        int temp = 0;
        int n = str.length();
        for(int i = n-1;i>=0;i--){
            if(isnum(str[i])){
                temp += (str[i]-'0')*ten;
                ten = ten*10;
                
            }
           else if(str[i]=='-' && i==0){
               temp = -temp;
           }
            else{
                return -1;
            }
        }
        
        return temp;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends