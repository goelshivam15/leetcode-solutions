//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node *compute(Node *head)
    {
        // your code goes here
        Node* temp = head;
        vector<int> v;
        
        while(temp!=NULL){
            v.push_back(temp->data);
            temp = temp->next;
            
            
        }
        vector<int> ans;
        int n = v.size();
        int maxi = v[n-1];
        ans.push_back(maxi);
        for(int i = n-2;i>=0;i--){
            if(v[i]>=maxi){
                maxi = v[i];
                ans.push_back(maxi);
            }
        }
        
        reverse(ans.begin(),ans.end());
        
        
        Node* nhead = new Node(-1);
        temp = nhead;
        for(int i =0;i<ans.size();i++){
            Node* curr = new Node(ans[i]);
            temp->next = curr;
            temp = curr;
        }
        
        
        return nhead->next;
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends