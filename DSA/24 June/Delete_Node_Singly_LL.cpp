class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        if (x==1) {
            Node*temp=head;
            head=head->next;
            delete temp;
            return head;
        }
        Node* current=head;
        for (int i=1; i<x-1 && current!=NULL; i++) {
            current=current->next;
        }
        if (current!=NULL && current->next!=NULL) {
            Node* temp=current->next;
            current->next=temp->next;
            delete temp;
        }

        return head;
    }
};
