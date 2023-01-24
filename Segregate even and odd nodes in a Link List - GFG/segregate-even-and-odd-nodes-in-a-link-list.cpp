//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int n, Node *head){
        // code here
        
        vector<int> even;
        vector<int> odd;
        Node* temp = head;
        while(temp!=NULL){
            if(temp->data&1){
                odd.push_back(temp->data);
            }
            else{
                even.push_back(temp->data);
            }
            
            temp = temp->next;
        }
        
        
        Node * nhead = new Node(-1);
        Node* tmp = nhead;
        for(int i =0;i<even.size();i++){
            Node* curr = new Node(even[i]);
            tmp->next = curr;
            tmp = curr;
        }
        
        for(int i = 0;i<odd.size();i++){
            Node* curr = new Node(odd[i]);
            tmp->next = curr;
            tmp = curr;
        }
        
        
        return nhead->next;
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends