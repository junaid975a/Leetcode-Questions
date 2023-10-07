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
/*
  Pairwise swap a linked list
  The input list will have at least one element
  node is defined as

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}*head;
*/
class Solution
{
    public:
    Node* pairWiseSwap(struct Node* head) 
    {
        Node *even = head;
        Node *odd = head->next? head->next : NULL;
        if(!odd) return head;
        
        
        Node *e_cur = even;
        Node *o_cur = odd;
        Node *temp = odd->next;
        
        even->next = NULL;
        odd->next = NULL;
        int ok = 1;
        while(temp) {
            if(ok) {
                e_cur->next = temp;
                e_cur = temp;
                temp = temp->next;
                e_cur->next = NULL;
            } else{
                o_cur->next = temp;
                o_cur = temp;
                temp = temp->next;
                o_cur->next = NULL;
            }
            
            ok = 1-ok;
        }
        Node* ans = NULL;
        ok = 1;
        while(even || odd) {
            if(ok) {
                if(ans == NULL) {
                    ans = odd;
                    temp = ans;
                    odd = odd->next;
                }
                else if(odd){
                    temp->next = odd;
                    temp = odd;
                    odd = odd->next;
                }
            } else if(even){
                temp->next = even;
                temp = even;
                even = even->next;
            }
            ok = 1-ok;
        }
        return ans;
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
		map<Node*, int> mp;
		mp[head] = head->data;
		for (int i = 0; i<n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
			mp[tail] = tail->data;
		}
		struct Node *failure = new Node(-1);
		Solution ob;
		head = ob.pairWiseSwap(head);
		int flag = 0;
		struct Node *temp = head;
		while(temp){
		    if(mp[temp] != temp->data){
		        flag = 1;
		        break;
		    }
		    temp = temp->next;
		}
		if(flag)
		    printList(failure);
		else
		    printList(head);
	}
	return 0; 
}

// } Driver Code Ends