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
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root)
            return nullptr;
        TreeNode* res;
        if (val == root->val)
            res = root;
        else if (val < root->val)
            res = searchBST(root->left, val);
        else
            res = searchBST(root->right, val);
        return res;
    }
};
int main() {
    Solution S;
    TreeNode* root = new TreeNode(4, new TreeNode(2, new TreeNode(1), new TreeNode(3)), new TreeNode(7));
    int val = 2;
    auto res = S.searchBST(root, val);
    cout << res->val << endl;
    return 0;
}