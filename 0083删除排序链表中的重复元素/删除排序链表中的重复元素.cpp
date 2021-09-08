#include<iostream>
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)
            return head;
        ListNode* path = head;
        while (path->next) {
            if (path->val == path->next->val)
                path->next = path->next->next;
            else
                path = path->next;
        }
        return head;
    }
};
int main() {
    Solution S;
    ListNode* head = new ListNode(1, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3)))));
    ListNode* head2 = new ListNode();
    ListNode* res = S.deleteDuplicates(head2);
    while (res) {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}