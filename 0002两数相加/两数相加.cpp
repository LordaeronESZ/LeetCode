#include<iostream>
#include<vector>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* headNode = nullptr;
        ListNode* pathNode = nullptr;
        int c = 0;
        while (l1 && l2)
        {
            int sum = l1->val + l2->val + c;
            c = sum / 10;
            if (!headNode) {
                pathNode = new ListNode(sum % 10);
                headNode = pathNode;
            }
            else {
                pathNode->next = new ListNode(sum % 10);
                pathNode = pathNode->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1)
        {
            int sum = l1->val + c;
            c = sum / 10;
            pathNode->next = new ListNode(sum % 10);
            pathNode = pathNode->next;
            l1 = l1->next;
        }
        while (l2)
        {
            int sum = l2->val + c;
            c = sum / 10;
            pathNode->next = new ListNode(sum % 10);
            pathNode = pathNode->next;
            l2 = l2->next;
        }
        if(c)
            pathNode->next = new ListNode(c);
        return headNode;
    }
};
int main() {
    // ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    // ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
    //ListNode* l1 = new ListNode(0);
    //ListNode* l2 = new ListNode(0);
    ListNode* l1 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9,
        new ListNode(9, new ListNode(9)))))));
    ListNode* l2 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9))));
    Solution S;
    ListNode* l3 = S.addTwoNumbers(l1, l2);
    while (l3) {
        cout << l3->val << " ";
        l3 = l3->next;
    }
    return 0;
}