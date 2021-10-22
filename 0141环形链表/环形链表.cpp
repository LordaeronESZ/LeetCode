#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    bool hasCycle(ListNode* head) {
        while (head) {
            if (head->val != INT32_MAX)
                head->val = INT32_MAX;
            else
                return true;
            head = head->next;
        }
        return false;
    }
};
int main() {
    Solution S;
    ListNode* head = new ListNode(3);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(0);
    ListNode* fourth = new ListNode(4);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = second;
    auto res = S.hasCycle(head);
    cout << res << endl; 
    return 0;
}