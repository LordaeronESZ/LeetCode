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
    void Func(TreeNode* root, vector<int>& res) {
        if (!root)
            return;
        res.push_back(root->val);
        Func(root->left, res);
        Func(root->right, res);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        Func(root, res);
        return res;
    }
};
int main() {
    TreeNode* root = new TreeNode(1, nullptr, new TreeNode(2, new TreeNode(3), nullptr));
    Solution S;
    vector<int> res = S.preorderTraversal(root);
    for (auto r : res)
        cout << r << " ";
    return 0;
}