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
	bool isPalindrome(ListNode* head) {
		vector<int> vec;
		while (head) {
			vec.emplace_back(head->val);
			head = head->next;
		}
		for (size_t p = 0, q = vec.size() - 1; p < q; p++, q--) {
			if (vec[p] != vec[q])
				return false;
		}
		return true;
	}
};
int main() {
	Solution S;
	ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(2, new ListNode(1)))));
	auto res = S.isPalindrome(head);
	cout << res << endl;
	return 0;
}