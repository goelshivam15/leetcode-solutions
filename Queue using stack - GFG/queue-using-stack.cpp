//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Queue {
    stack<int> input, output;
public:


    void insertatbottom(stack<int>&output, int x){
        
        if(output.empty()){
            output.push(x);
            return ;
        }
        
        int a = output.top();
        output.pop();
        insertatbottom(output,x);
        output.push(a);
    }

    void enqueue(int x) {
        
        insertatbottom(output,x);
        
        
    }

    int dequeue() {
      if(output.size()==0){
          return -1;
      }
      
      
      int temp = output.top();
      output.pop();
      return temp;
       
     
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Queue ob;

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            ob.enqueue(a);
        }
        else if(QueryType==2)
        {
            cout<<ob.dequeue()<<" ";

        }
        }
    cout<<endl;
    }
}

// } Driver Code Ends