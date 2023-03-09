#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL) return true;
        if (head->next == NULL) return true;
        ListNode *slow = head;
        ListNode *prev = NULL; 
        ListNode *next = NULL; 
        ListNode *fast = head;
        int even = 1;
        while (fast!= NULL){
            if (fast->next == NULL) {
                even = 0;
                break;
            }
            fast = fast->next->next;
            next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        ListNode *first = prev;
        ListNode *second = even ? slow : slow->next; 
        bool res = true;
        while (first != NULL) {
            if (first->val != second->val) res = false;
            first = first->next;
            second = second->next;
        }
        return res;
    }
};