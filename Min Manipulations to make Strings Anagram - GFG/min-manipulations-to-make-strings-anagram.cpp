//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int minManipulation (int n, string s1, string s2);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string s1; cin >> s1;
        string s2; cin >> s2;

        cout << minManipulation (n, s1, s2) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends


int minManipulation (int n, string s, string t)
{
    // your code here
     map<char,int> mp1;
       map<char,int> mp2;
       for(auto ch : s){
           mp1[ch]++;
       }
       for(auto ch : t){
           mp2[ch]++;
       }

       int cnt =0;
       int plus = 0;
       int minus =0;
       for(auto it : mp1){
           if(it.second>mp2[it.first]){
               plus += it.second-mp2[it.first];
           }

       }
       for(auto it : mp2){
           if(it.second>mp1[it.first]){
               minus += it.second-mp1[it.first];
           }
       }
       if(minus==plus){
           return minus;
       }
       return -1;
}