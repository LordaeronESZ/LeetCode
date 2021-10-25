#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
//π˛œ£≤È’“
//class Solution {
//public:
//    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
//        unordered_map<ListNode*, bool> listMap;
//        while (headA) {
//            listMap[headA] = true;
//            headA = headA->next;
//        }
//        while (headB) {
//            if (listMap.find(headB) != listMap.end())
//                return headB;
//            headB = headB->next;
//        }
//        return nullptr;
//    }
//};
//À´÷∏’Î
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (!headA || !headB) {
            return nullptr;
        }
        ListNode* pA = headA, * pB = headB;
        while (pA != pB) {
            pA = pA == nullptr ? headB : pA->next;
            pB = pB == nullptr ? headA : pB->next;
        }
        return pA;
    }
};
int main() {
    Solution S;
    ListNode* a1 = new ListNode(4);
    ListNode* a2 = new ListNode(1);
    ListNode* a3 = new ListNode(8);
    ListNode* a4 = new ListNode(4);
    ListNode* a5 = new ListNode(5);
    a1->next = a2;
    a2->next = a3;
    a3->next = a4;
    a4->next = a5;
    ListNode* b1 = new ListNode(5);
    ListNode* b2 = new ListNode(0);
    ListNode* b3 = new ListNode(1);
    b1->next = b2;
    b2->next = b3;
    b3->next = a3;
    auto res = S.getIntersectionNode(a1, b1);
    cout << res->val << endl;
    return 0;
}