#include<iostream>
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
    int res;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        res = 1;
        searchTree(root);
        return res - 1;
    }
    int searchTree(TreeNode* node) {
        if (!node)
            return 0;
        int l = searchTree(node->left);
        int r = searchTree(node->right);
        res = max(res, l + r + 1);
        return max(l, r) + 1;
    }
};
int main() {
    Solution S;
    TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3));
    auto res = S.diameterOfBinaryTree(root);
    cout << res << endl;
    return 0;
}