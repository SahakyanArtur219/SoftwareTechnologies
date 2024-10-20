#include <iostream>

struct Node {
    int data;
    Node* next;
};

void add(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = nullptr;

    if (*head_ref == nullptr) {
        *head_ref = new_node;
        return;
    }

    Node* last = *head_ref;
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = new_node;
}

Node* plusLists(Node* head1, Node* head2) {
    Node* result = nullptr;
    Node* temp, * prev = nullptr;
    int carry = 0, sum;

    while (head1 != nullptr || head2 != nullptr) {
        sum = carry + (head1 ? head1->data : 0) + (head2 ? head2->data : 0);
        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;
        temp = new Node();
        temp->data = sum;
        temp->next = nullptr;

        if (result == nullptr)
            result = temp;
        else
            prev->next = temp;

        prev = temp;

        if (head1) head1 = head1->next;
        if (head2) head2 = head2->next;
    }

    if (carry > 0) {
        temp = new Node();
        temp->data = carry;
        temp->next = nullptr;
        prev->next = temp;
    }

    return result;
}

void printList(Node* node) {
    while (node != nullptr) {
        std::cout << node->data << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

int main() {

    Node* head1 = nullptr;
    Node* head2 = nullptr;

    add(&head1, 2);
    add(&head1, 4);
    add(&head1, 3);

    add(&head2, 5);
    add(&head2, 6);
    add(&head2, 9);

    Node* result = plusLists(head1, head2);

    std::cout << "Result linked list: ";
    printList(result);

}
