//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

long long int no_of_subarrays(int n, vector<int> &arr) {
    // Write your code here.
    long long int  ans  = 0;
    long long int i =0;
    long long int j =0;
    while(j<arr.size()){
        if(arr[j]==0){
            ans += j-i+1;
            j++;
        }
        else{
            j = j+1;
            i = j;
        }
    }
    
    return ans;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << no_of_subarrays(n, arr) << endl;
    }
}

// } Driver Code Ends