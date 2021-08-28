#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode();
        ListNode* headNode = res;
        while (l1->next && l2->next) {
            if (l1->val < l2->val) {
                headNode->next = l1;
                headNode = headNode->next;
                l1 = l1->next;
            }
            else {
                headNode->next = l2;
                headNode = headNode->next;
                l2 = l2->next;
            }
        }
        while (l1) {
            headNode->next = l1;
            headNode = headNode->next;
            l1 = l1->next;
        }
        while (l2) {
            headNode->next = l2;
            headNode = headNode->next;
            l2 = l2->next;
        }
        return res->next;
    }
};
int main() {
    Solution S;
    ListNode* l1 = new ListNode(1, new ListNode(2, new ListNode(4, new ListNode())));
    ListNode* l2 = new ListNode(1, new ListNode(3, new ListNode(4, new ListNode())));
    ListNode* res = S.mergeTwoLists(l1, l2);
    while (res->next)
    {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}
