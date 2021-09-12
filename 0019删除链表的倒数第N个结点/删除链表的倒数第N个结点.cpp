#include<iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* path = head;
        int list_length = 0;
        //计算链表长度
        while (path) {
            list_length++;
            path = path->next;
        }
        //若删除头节点
        if (list_length == n) {
            head = head->next;
            return head;
        }
        path = head;
        for (int i = 1; i < list_length - n; i++)
            path = path->next;
        path->next = path->next->next;
        return head;
    }
};
int main() {
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    ListNode* head2 = new ListNode(1);
    ListNode* head3 = new ListNode(1, new ListNode(2));
    Solution S;
    ListNode* res = S.removeNthFromEnd(head2, 1);
    while (res) {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}