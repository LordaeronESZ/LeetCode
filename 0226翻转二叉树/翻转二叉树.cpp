#include<iostream>
#include<vector>
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
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
            return nullptr;
        auto rTree = root->right;
        root->right = invertTree(root->left);
        root->left = invertTree(rTree);
        return root;
    }
};
void printTree(TreeNode* root) {
    if (!root)
        return;
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}
int main() {
    Solution S;
    TreeNode* root = new TreeNode(4, new TreeNode(2, new TreeNode(1), new TreeNode(3)), new TreeNode(7, new TreeNode(6), new TreeNode(9)));
    auto res = S.invertTree(root);
    printTree(res);
    return 0;
}