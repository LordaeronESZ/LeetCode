#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int best_result = 0;
        while (i < j) {
            int result = (j - i) * min(height[i], height[j]);
            best_result = max(best_result, result);
            if (height[i] < height[j])
                i++;
            else
                j--;
        }
        return best_result;
    }
};
int main() {
    int temp;
    vector<int> height;
    while (cin >> temp)
    {
        height.push_back(temp);
        if (cin.get() == '\n')
            break;
    }
    Solution S;
    int result = S.maxArea(height);
    cout << result << endl;
    return 0;
}