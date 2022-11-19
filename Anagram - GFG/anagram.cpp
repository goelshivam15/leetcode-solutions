//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        
        // Your code here
        if(a.length() != b.length()){
            return false;
        }
        
        unordered_map<char, int> ma,mb;
        for(int i =0;i<a.length();i++){
            ma[a[i]]++;
            mb[b[i]]++;
        }
        
        
        for(auto it : a){
            if(ma[it] != mb[it]){
                return false;
            }
        }
        
        return true;
        
    }

};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends