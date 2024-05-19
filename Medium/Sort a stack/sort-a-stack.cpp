//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
// } Driver Code Ends

 
/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

void insertatright(stack<int> &s , int data){
    if(s.empty()){
        s.push(data);
    }
    else{
        if(data>=s.top()){
            s.push(data);   
        }
        else{
            int d=s.top();
            s.pop();
            insertatright(s,data);
            s.push(d);
        }
    }
}

void sorts(stack<int> &s){
    if(s.empty()){
        return;
    }
    else{
        int d=s.top();
        s.pop();
        sorts(s);
        insertatright(s,d);
    }
}
/* The below method sorts the stack s 
you are required to complete the below method */
void SortedStack :: sort()
{
   //Your code here
    
    sorts(s);
}