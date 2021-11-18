#include<iostream>
#include<cmath>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

};
class Solution {
private:
    int res = 0;
public:
    int findTilt(TreeNode* root) {
        deepTraversal(root);
        return res;
    }
    int deepTraversal(TreeNode* node) {
        if (!node)
            return 0;
        int leftNum = deepTraversal(node->left);
        int rightNum = deepTraversal(node->right);
        res += abs(leftNum - rightNum);
        return leftNum + rightNum + node->val;
    }
};
int main() {
    Solution S;
    TreeNode* root = new TreeNode(4, new TreeNode(2, new TreeNode(3), new TreeNode(5)), new TreeNode(9, nullptr, new TreeNode(7)));
    auto res = S.findTilt(root);
    cout << res << endl;
    return 0;
}