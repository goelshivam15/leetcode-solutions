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
    Node* divide(int N, Node *head){
        // code here
        
        vector<int> even;
        vector<int> odd;
        Node* temp = head;
        while(temp!=NULL){
            if(temp->data%2!=0){
                odd.push_back(temp->data);
                temp = temp->next;
                
            }
            else{
                even.push_back(temp->data);
                temp = temp->next;
            }
        }
        Node* tmp = new Node(-1);
        Node* curr = tmp;
        
        for(int i =0;i<even.size();i++){
            Node* e = new Node(even[i]);
            curr->next = e;
            curr= curr->next;
            
        }
        for(int i =0;i<odd.size();i++){
            Node* o = new Node(odd[i]);
            curr->next = o;
            curr= curr->next;
            
        }
        curr->next =NULL;
        return (tmp->next);
        
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