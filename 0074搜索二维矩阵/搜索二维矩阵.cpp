#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
		for (size_t i = 0; i < matrix.size(); i++)
		{
			if (target >= matrix[i].front() && target <= matrix[i].back()) {
				size_t first = 0, last = matrix[i].size() - 1;
				while (first <= last) {
					size_t mid = (first + last) / 2;
					if (target == matrix[i][mid])
						return true;
					else if (target > matrix[i][mid])
						first = mid + 1;
					else
						last = mid - 1;
				}
				return false;
			}
		}
		return false;
    }
};
int main() {
	Solution S;
	vector<vector<int>> matrix = { {1,3,5,7},{10,11,16,20},{23,30,34,60} };
	int target = 3;
	auto res = S.searchMatrix(matrix, target);
	cout << res << endl;
	return 0;
}