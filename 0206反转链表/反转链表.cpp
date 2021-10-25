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
	ListNode* reverseList(ListNode* head) {
		if (!head)
			return nullptr;
		ListNode* dummy = new ListNode(-1, head);
		ListNode* beg = dummy->next;
		ListNode* end = beg->next;
		while (beg->next) {
			//摘掉结点end
			if(beg->next)
				beg->next = beg->next->next;
			//将节点end添加到表头
			end->next = dummy->next;
			dummy->next = end;
			//end指向next
			end = beg->next;
		}
		return dummy->next;
	}
};
int main() {
	Solution S;
	ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
	auto res = S.reverseList(head);
	while (res) {
		cout << res->val << " ";
		res = res->next;
	}
	return 0;
}