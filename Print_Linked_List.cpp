class Solution {
  public:
    // Function to display the elements of a linked list in same line
    void printList(Node *head) {
        Node* temp = head;
        while(temp != nullptr){
            cout<<temp -> data<< " ";
            temp = temp -> next;
            
        }
    }
};
