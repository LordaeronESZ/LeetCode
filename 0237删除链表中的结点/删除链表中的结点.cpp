#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) { }  
};
class Solution {
public:
    void deleteNode(ListNode* node) {
        auto next = node->next;
        *node = *next;
    }
};
int main() {
    Solution S;
    vector<int> vec = { 4,5,1,9 };
    ListNode* head = new ListNode(-1);
    ListNode* path = head;
    ListNode* node = nullptr;
    for (size_t i = 0; i < vec.size(); i++) {
        path->next = new ListNode(vec[i]);
        path = path->next;
        if (i == 1)
            node = path;
    }
    S.deleteNode(node);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}