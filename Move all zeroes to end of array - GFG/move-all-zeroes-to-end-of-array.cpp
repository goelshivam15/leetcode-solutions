//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	void pushZerosToEnd(int arr[], int n) {
	    // code 
	    int cnt =0;
	    vector<int> temp;
	    for(int i =0;i<n;i++){
	        if(arr[i]!=0){
	            temp.push_back(arr[i]);
	        }
	        else{
	            cnt++;
	        }
	        
	    }
	    
	    int i =0;
	    int a = n-cnt;
	    while(i<a){
	        arr[i]= temp[i];
	        i++;
	    }
	    
	    while(cnt!=0 && i<n){
	        arr[i]=0;
	        i++;
	        cnt--;
	    }
	    
	    
	    
	}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.pushZerosToEnd(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends