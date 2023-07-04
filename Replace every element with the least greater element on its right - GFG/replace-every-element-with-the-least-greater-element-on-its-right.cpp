//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++

class Node{
    public:
    
    int data;
    Node* left;
    Node* right;
    
    Node(int d){
        data = d;
        left=NULL;
        right=NULL;
    }
    
};

class Solution{
    public:
    
    Node* insert(Node* root , int& val , int& suc){
        if(root==NULL){
            return new Node(val);
            
        }
        
        if(val>=root->data){
            
            root->right = insert(root->right,val,suc);
            
            
        }
        else{
            suc = root->data;
            root->left = insert(root->left,val,suc);
        }
        
        return root;
    }
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        
        vector<int> ans;
        
        Node* root = NULL;
        
        
        for(int i = n-1;i>=0;i--){
            int suc = -1;
            
            root = insert(root,arr[i],suc);
            
            ans.push_back(suc);
            
            
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findLeastGreater(arr, n);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout <<endl;
	}
	return 0;
}

// } Driver Code Ends