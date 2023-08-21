//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    string convertToRoman(int num) {
        // code here
         map<string,int> mp;

        mp["I"] = 1;
        mp["V"]=5;
        mp["X"]= 10;
        mp["L"] = 50;
        mp["C"]= 100;
        mp["D"] = 500;
        mp["M"] = 1000;
        mp["IV"] = 4;
        mp["IX"] = 9;
         mp["XL"] = 40;
        mp["XC"] = 90;
         mp["CD"] = 400;
        mp["CM"] = 900;
        string ans = "";
        while(num>0){
            int val = 0;

            for(auto it : mp){
                if(it.second<=num){

                    val = max(val,it.second);

                }
            }
            for(auto it : mp){
                if(it.second==val){
                    ans += it.first;
                    break;
                }
            }
            num -= val;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		Solution ob;
    	cout << ob.convertToRoman(N) << endl;
	}
	return 0;
}
// } Driver Code Ends