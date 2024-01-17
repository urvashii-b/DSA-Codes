#include<bits/stdc++.h>
using namespace std;

// Web Browser is one important application of Linked List.

// 1. Singly Linked Lists: In a singly linked list, each node points to the next node in the sequence. Traversal is straightforward but limited to moving in one direction, from the head to the tail.
// ex: 245(head) -> 455 -> 8(tail) -> null

class Node{
public: // access modifier
    int data; // the data value
    Node* next; // the pointer to the next value
    // constructor
    Node (int data1, Node* next1){
        data=data1;  // Initialize data with the provided value
        next=next1;  // Initialize next with the provided
    }
    Node (int data1){
        data=data1;  // Initialize data with the provided value
        next=nullptr;  // Initialize next as null since it's the end of the list
    }
};

// I) convert array OR list to linked list - O(N)
/*
1. head should point to the first element of the array
place a mover
keep creating temporary nodes with arr[i]th values
point mover->next to temp and change mover's position to temp by mover = temp
do this until all the array elements are placed in the linkedlist
return the head
*/
Node* constructLL(vector<int>& arr) { 
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

// II) length of the linked list - O(N)
/*
place a temp pointer at the head and a count variable initialised to 0
traverse the whole list and keep increasing the count by 1 for each node
return count
*/
int lengthOfLinkedList(Node* head){   
    Node* temp=head;
    int cnt=0;
    while(temp!=NULL){
        temp=temp->next;
        cnt++;
    }
    return cnt;
} 

// III) search for an element - worst: O(N), best: O(1)
/*
make a temp pointer pointing to the head
while traversing the whole list check each element with the desired value
if equal then element found.. return 1
else return 0
*/
int checkifPresent(Node* head, int desiredElement) { 
    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==desiredElement){
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}

// IV) print
/*
traverse using head and keep printing head values until list is empty
*/
void printLL(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
} 

// V) delete first - O(1)
/*

*/
Node* deleteHead(Node* head){
    if(head==NULL) return head;
    Node* temp = head;
    head=head->next;
    delete temp;
    return head;
} 

// delete last - O(n)
Node* deleteTail(Node* head){
    if(head==NULL || head->next==NULL) return head;
    Node* temp = head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
} 

// delete kth - worst: O(N), best: O(1)
Node* deleteK(Node* head, int k){
    if(head==NULL) return head;
    if(k==1){ //head
        Node* temp = head;
        head=head->next;
        delete temp;
        return head;
    }
    int cnt = 0;
    Node* temp = head;
    Node* prev = NULL;
    while(temp!=NULL){
        cnt++;
        if(cnt==k){
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

// delete element
Node* deleteEl(Node* head, int el){
    if(head==NULL) return head;
    if(head->data==el){ //head
        Node* temp = head;
        head=head->next;
        delete temp;
        return head;
    }
    Node* temp = head;
    Node* prev = NULL;
    while(temp!=NULL){
        if(temp->data==el){
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node* insertHead(int val, Node* head){
    Node* temp = new Node(val,head);
    return temp;
    // return new Node(val,head);
}

Node* insertTail(int val, Node* head){
    if(head==NULL) return new Node(val);
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* newNode = new Node(val);
    temp->next = newNode;
    return head;
} 

Node* insertK(Node* head,int k, int el){
    if(head==NULL){
        if(k==1){
            return new Node(el);
        }
        else{
            return head;
        }
    }
    if(k==1){return new Node(el,head);}
    int cnt = 0;
    Node* temp = head;
    while(temp!=NULL){
        cnt++;
        if(cnt==(k-1)){
            Node* newNode = new Node(el);
            newNode->next=temp->next;
            temp->next=newNode;
            break;
        }
        temp=temp->next;
    }
    return head;
}

Node* insertBeforeValue(Node* head, int el, int val){
    if(head==NULL){
        return NULL;
    }
    if(head->data==val){
        return new Node(el,head);
    }
    Node* temp = head;
    while(temp!=NULL){
        if(temp->next->data == val){
            Node* newNode = new Node(el,temp->next);
            temp->next=newNode;
            break;
        }
        temp=temp->next;
    }
    return head;
}

Node* insertAfterValue(Node* head, int el, int val){
    if(head==NULL){
        return NULL;
    }
    if(head->data==val){
        Node* newNode = new Node(el,head->next);
        head->next = newNode;
        return head;
    }
    // 23 45 78 9 10 to insert 5 after 9
    Node* temp = head;
    while(temp!=NULL){
        if(temp->data==val){
            Node* newNode = new Node(el);
            newNode->next=temp->next;
            temp->next = newNode;
            break;
        }
        temp=temp->next;
    }
    return head;
}

int main(){
    vector<int> arr={2,5,8,7,9,15,22};
    Node* head=constructLL(arr);
    head = deleteHead(head); // {5,8,7,9,15,22}
    head = deleteTail(head); // {5,8,7,9,15}
    head = deleteK(head,3); // {5,8,9,15}
    head = deleteEl(head,8); // {5,9,15}
    head = insertHead(2,head); // {2,5,9,15}
    head = insertTail(27,head); // {2,5,9,15,27}
    head = insertK(head,6,69); //{2 5 9 15 27 69}
    head = insertBeforeValue(head,73,69); //{2 5 9 15 27 73 69}
    head = insertAfterValue(head,299,2); //{2 299 5 9 15 27 73 69}
    printLL(head);
    /*
    Node* head= new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);

    cout<<y<<'\n'; // returns the memory value
    cout<<y->data<<'\n'; // returns the data stored at that memory point
    delete y;
    
    vector<int> arr = {2, 5, 8, 7};
    // Create a Node 'x' with the first element of the vector and a null next reference
    Node x = Node(arr[0], nullptr);
    // Create a pointer 'y' pointing to the Node 'x'
    Node* y = &x;
    // Print the memory address of the Node 'x' using the pointer 'y'
    cout << y << '\n';
    
    cout << checkifPresent(head, 22) <<endl; // returns 0 as it is not present
    */
    return 0;

}


