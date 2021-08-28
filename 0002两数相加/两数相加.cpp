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
        ListNode* l3 = new ListNode();
        ListNode* tempNode = &(*l3);
        int c = 0;
        while (l1->next && l2->next) {
            int tempVal = l1->val + l2->val;
            if (tempVal >= 10) {
                tempVal -= 10;
                c = 1;
            }
            else {
                c = 0;
            }
            if (l3 == tempNode)
                tempNode->val = tempVal;
            else
                tempNode->val = tempVal + c;
            tempNode->next = new ListNode();
            tempNode = tempNode->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1->next) {
            tempNode->next = new ListNode(l1->val + c);
            c = 0;
            tempNode = tempNode->next;
            l1 = l1->next;
        }
        while (l2->next) {
            tempNode->next = new ListNode(l2->val + c);
            c = 0;
            tempNode = tempNode->next;
            l2 = l2->next;
        }
        return l3;
    }
};
int main() {
    int temp;
    ListNode* l1 = new ListNode();
    ListNode* rootNode1 = &(*l1);
    ListNode* l2 = new ListNode();
    ListNode* rootNode2 = &(*l2);
    while (cin >> temp)
    {
        l1 = new ListNode(temp);
        l1 = l1->next;
        if (cin.get() == '\n')
            break;
    }
    while (cin >> temp)
    {
        l2 = new ListNode(temp);
        l2 = l2->next;
        if (cin.get() == '\n')
            break;
    }
    Solution S;
    ListNode* l3 = S.addTwoNumbers(rootNode1, rootNode2);
    while (l3->next) {
        cout << l3->val << " ";
        l3 = l3->next;
    }
    cout << endl;
    return 0;
}