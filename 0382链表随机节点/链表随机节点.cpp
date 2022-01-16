#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
private:
    vector<int> listVector;
public:
    Solution(ListNode* head) {
        while (head) {
            listVector.emplace_back(head->val);
            head = head->next;
        }
    }
    int getRandom() {
        int n = listVector.size();
        int indexRan = rand() % n;
        return listVector[indexRan];
    }
};
int main() {
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3)));
    Solution S(head);
    for (int i = 0; i < 10; i++) {
        auto res = S.getRandom();
        cout << res << endl;
    }
    return 0;
}