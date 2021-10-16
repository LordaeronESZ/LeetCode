#include<iostream>
#include<vector>
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* pre = new ListNode(-1, head);
        ListNode* path = pre;
        while (path->next && path->next->next) {
            if (path->next->val == path->next->next->val) {
                int temp = path->next->val;
                while (path->next && path->next->val == temp)
                    path->next = path->next->next;
            }
            else {
                path = path->next;
            }
        }
        return pre->next;
    }
};
int main() {
    Solution S;
    vector<int> vec = { 1,2,3,3,4,4,5 };
    ListNode* head = new ListNode(vec.front());
    ListNode* pre = head;
    for (auto it = vec.cbegin() + 1; it < vec.cend(); it++) {
        head->next = new ListNode(*it);
        head = head->next;
    }
    auto res = S.deleteDuplicates(pre);
    while (res) {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}