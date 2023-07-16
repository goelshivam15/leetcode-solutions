//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    
    public:
    priority_queue<int> maxheap;
priority_queue<int, vector<int> , greater<int>> minheap;
    //Function to insert heap.
    void insertHeap(int &num)
    {
         if(maxheap.size()==0 || num<=maxheap.top()){
            maxheap.push(num);
        }
        else{
            minheap.push(num);
        }
        balanceHeaps();
        
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        if(maxheap.size()+1<minheap.size()){
            maxheap.push(minheap.top());
            minheap.pop();

        }
        
        else if(maxheap.size()>minheap.size()+1){
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        
    }
    
    //Function to return Median.
    double getMedian()
    {
         if(maxheap.size()==minheap.size()){
            return (maxheap.top()+minheap.top())/2.0;
        }
        else if(maxheap.size()>minheap.size()){
            return maxheap.top();
        }
        else{
            return minheap.top();
        }
        
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends