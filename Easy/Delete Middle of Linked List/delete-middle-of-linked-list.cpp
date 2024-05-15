//{ Driver Code Starts
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



// } Driver Code Ends
/* Link list Node:

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

// Deletes middle of linked list and returns head of the modified list
class Solution{
    public:
    Node* deleteMid(Node* head)
    {
        // Your Code Here
        int count=0;
        Node* current= head;
        while(current != NULL){
            current=current->next;
            count++;
        }
        if(count ==1 || count ==0){
            return NULL;
        }
        
        else if(count%2 == 0){
            count = count/2  ;
            current = head;
            Node* previous= head;
            while(count--){
                previous = current;
                current= current->next;
            }
            previous->next= current->next;
            current->next= NULL;
            delete current;
            return head;
        }
        else{
            count = count/2;
            current=head;
            Node* previous = head;
            while(count--){
                previous = current ;
                current= current->next;
            }
            previous->next= current->next;
            current->next=NULL;
            delete current;
            return head;
        }
    }
};

//{ Driver Code Starts.



void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
} 
int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		int data;
		cin>>data;
		struct Node *head = new Node(data);
		struct Node *tail = head;
		for (int i = 0; i < n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
		}
		Solution obj;
		head = obj.deleteMid(head);
		printList(head); 
	}
	return 0; 
} 



// } Driver Code Ends