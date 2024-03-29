//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    
    struct Node* add(struct Node* first , struct Node* second){
        
      int carry =0;
      struct Node* nroot = new Node(-1);
          struct Node* temp = nroot;
      while(first!=NULL || second!=NULL || carry!=0){
          int val1 =0;
          if(first!=NULL){
              
              val1 = first->data;
              
          }
          int val2 =0;
          if(second!=NULL){
              val2 = second->data;
          }
          
          int sum = val1+val2 + carry;
          int digit = sum%10;
          
          struct Node* curr = new Node(digit);
          temp->next = curr;
          temp = curr;
          
          carry = sum/10;
          if(first!=NULL)
            first = first->next;
          if(second!=NULL)
            second = second ->next;
          
          
      }
      
      return nroot->next;
    }
    
    struct Node* reverse(struct Node* root){
        if(root==NULL){
            return NULL;
        }
        
        struct Node* prev =  NULL;
        struct Node* curr = root;
        while(curr!=NULL){
            struct Node* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        
        return prev;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        
        first = reverse(first);
        second = reverse(second);
        struct Node* ans = add(first,second);
        
        ans = reverse(ans);
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
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends