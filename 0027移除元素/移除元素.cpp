#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
		int last = int(nums.size()) - 1;
		int index = 0;
		while (index <= last)
		{
			if (nums[index] == val) {
				swap(nums[index], nums[last]);
				last--;
			}
			else {
				index++;
			}
		}
		return last + 1;
    }
};
int main() {
	vector<int> nums = { 0,1,2,2,3,0,4,2 };
	//vector<int> nums = { 3,2,2,3 };
	int val = 2;
	Solution S;
	int last = S.removeElement(nums, val);
	for (int i = 0; i < last; i++)
		cout << nums[i] << " ";
	return 0;
}