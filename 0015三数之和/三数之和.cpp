#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());
		if (nums.size() < 3)
			return res;
		for (auto i = 0; i <= nums.size() - 3; i++)
		{
			if (nums[i] > 0)
				return res;
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			int j = i + 1, k = nums.size() - 1;
			while (j < k) {
				if (nums[j] + nums[k] == -nums[i]) {
					vector<int> temp = { nums[i],nums[j],nums[k] };
					res.push_back(temp);
					//不存在此元素则加入
					//if(find(res.begin(),res.end(),temp) == res.end())
					//	res.push_back(temp);
					while (j < k && nums[j] == nums[j + 1])
						j++;
					while (j < k && nums[k] == nums[k - 1])
						k--;
					j++;
					k--;
				}
				else if (nums[j] + nums[k] < -nums[i])
					j++;
				else
					k--;
			}
		}
		return res;
    }
};
int main() {
	Solution S;
	vector<int> nums;
	nums = { -1,0,1,2,-1,-4 };
	vector<vector<int>> res = S.threeSum(nums);
	for (auto i = 0; i < res.size(); i++)
	{
		cout << res[i][0] << " " << res[i][1] << " " << res[i][2] << endl;
	}
	return 0;
}