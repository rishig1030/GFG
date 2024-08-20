//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        map<Node*,Node*> parent_node;
        queue<Node*> q;
        q.push(root);
        Node* target_node=NULL;
        // mark parent node of all the node
        while(!q.empty()){
            Node* node = q.front();
            q.pop();
            if(node->data == target) target_node = node;
            if(node->left) {
                q.push(node->left);
                parent_node[node->left] = node;
            }
            if(node->right) {
                q.push(node->right);
                parent_node[node->right] = node;
            }
        }
        
        if(target_node==NULL) return 0;
        // traverse again bfs 
        // each traversal the time will increase by 1
        queue<Node*> traverse;
        unordered_map<Node*,int> visited;
        int time_min = 0;
        traverse.push(target_node);
        visited[target_node] = 1;
        while(!traverse.empty()){
            int size = traverse.size();
            int fl = 0;
            // all the element should be convered at once because each node will burn its adjacent in 1 time only
            for(int i=0;i<size;i++){
                Node* n1 = traverse.front();
                traverse.pop();
                if(n1->left && visited[n1->left]==0){
                    fl = 1;
                    visited[n1->left] = 1;
                    traverse.push(n1->left);
                }
                if(n1->right && visited[n1->right]==0){
                    fl = 1;
                    traverse.push(n1->right);
                    visited[n1->right] = 1;
                }
                if(parent_node[n1] && visited[parent_node[n1]]==0){
                    fl = 1;
                    traverse.push(parent_node[n1]);
                    visited[parent_node[n1]] = 1;
                }
            }
            if(fl) time_min++;
        }
        
        return time_min;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends