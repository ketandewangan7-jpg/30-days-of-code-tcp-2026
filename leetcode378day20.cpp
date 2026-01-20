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
    Node* oddEvenList(Node* head) {
        if (head == NULL || head->next == NULL) return head;

        Node* odd = head;
        Node* even = head->next;
        Node* evenHead = even;

        while (even != NULL && even->next != NULL) {
            odd->next = odd->next->next;
            even->next = even->next->next;

            odd = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};
