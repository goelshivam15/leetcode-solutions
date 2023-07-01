//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

void heapify(vector<int>&arr, int index , int n){
    
    
    int largest = index;
    int l = 2*index+1;
    int r = 2*index+2;
    if(l<n && arr[l]>arr[largest]){
        largest = l;
    }
    if(r<n && arr[r]>arr[largest]){
        largest = r;
    }
    
    if(largest != index){
        swap(arr[largest],arr[index]);
        heapify(arr,largest,n);
    }
}
    void convertMinToMaxHeap(vector<int> &arr, int n){
        
        
        for(int i = n/2-1;i>=0;i--){
            heapify(arr,i,n);
        }
    
    }
    
};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        obj.convertMinToMaxHeap(vec,n);
        for(int i = 0;i<n;i++) cout << vec[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends