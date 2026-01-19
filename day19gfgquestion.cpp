#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
public:
    int add(Node* temp) {
        if (temp == NULL) return 1;

        int carry = add(temp->next);
        temp->data += carry;

        if (temp->data < 10) return 0;

        temp->data = 0;
        return 1;
    }

    Node* addOne(Node* head) {
        int carry = add(head);

        if (carry == 1) {
            Node* newNode = new Node(1);
            newNode->next = head;
            head = newNode;
        }
        return head;
    }
};
