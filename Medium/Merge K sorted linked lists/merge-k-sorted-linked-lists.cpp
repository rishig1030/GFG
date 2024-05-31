//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

// } Driver Code Ends
/*Linked list Node structure

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

class Solution{
    
  public:
    //Function to merge K sorted linked list.
    Node* mergeLL(Node *arr[],int k,int i){
        if(i!=k){
            Node* temp1 = arr[i];
            Node* temp2= mergeLL(arr,k,i+1);
            Node* head = NULL;
            Node* temp = head;
            while(temp1 && temp2){
                if(temp1->data < temp2->data){
                    if(!head){
                        head=temp1;
                        temp = temp1;
                    }
                    else{
                        temp->next= temp1;
                        temp = temp1;
                    }
                    temp1= temp1->next;
                }
                else{
                    if(!head){
                        head = temp2;
                        temp = temp2;
                    }
                    else{
                        temp->next= temp2;
                        temp= temp2;
                    }
                    temp2= temp2->next;
                }
            }
            while(temp1){
                if(!head){
                        head=temp1;
                        temp = temp1;
                    }
                    else{
                        temp->next= temp1;
                        temp = temp1;
                    }
                    temp1= temp1->next;
            }
            while(temp2){
                if(!head){
                        head = temp2;
                        temp = temp2;
                    }
                    else{
                        temp->next= temp2;
                        temp= temp2;
                    }
                    temp2= temp2->next;
            }
            return head;
        }
       
        else return NULL;
    }
    Node * mergeKLists(Node *arr[], int K)
    {
           // Your code here
        return mergeLL(arr,K,0);
    }
};



//{ Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}

// } Driver Code Ends