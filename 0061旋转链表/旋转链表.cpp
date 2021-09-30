#include<vector> 
#include <iostream>
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
	ListNode* rotateRight(ListNode* head, int k) {
		if (!head)
			return head;
		int count = 1;
		ListNode* pNode = head;
		while (pNode->next) {
			pNode = pNode->next;
			count++;
		}
		pNode->next = head;
		k = k % count;
		pNode = head;
		for (int i = 0; i < count - k - 1; i++)
			pNode = pNode->next;
		head = pNode->next;
		pNode->next = nullptr;
		return head;
	}
};
int main() {
	Solution S;
	ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
	ListNode* head2 = new ListNode(3);
	auto res = S.rotateRight(head, 3);
	while (res) {
		cout << res->val << " ";
		res = res->next;
	}
	return 0;
}