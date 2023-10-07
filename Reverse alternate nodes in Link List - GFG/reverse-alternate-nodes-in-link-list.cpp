//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}


// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/
class Solution
{
    public:
    Node* reverse(Node* head) {
        Node*p = head, *q = NULL, *r = NULL;
        while(p) {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        return q;
    }
    void rearrange(struct Node *head)
    {
        Node *even = head;
        Node *odd = head->next? head->next : NULL;
        if(!odd) return ;
        
        
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
        Node *rev = reverse(odd);
        e_cur->next = rev;
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}

// } Driver Code Ends