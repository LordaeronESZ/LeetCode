#include<iostream>
#include<string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
private:
    string dfs(TreeNode* root) {
        string res;
        if (root->left && root->right)
            res = to_string(root->val) + "(" + dfs(root->left) + ")" + "(" + dfs(root->right) + ")";
        else if (root->left)
            res = to_string(root->val) + "(" + dfs(root->left) + ")";
        else if (root->right)
            res = to_string(root->val) + "()" + "(" + dfs(root->right) + ")";
        else
            res = to_string(root->val);
        return res;
    }
public:
    string tree2str(TreeNode* root) {
        auto res = dfs(root);
        return res;
    }
};
int main() {
    Solution S;
    TreeNode* thir1 = new TreeNode(4);
    TreeNode* sec1 = new TreeNode(2, thir1, nullptr);
    TreeNode* sec2 = new TreeNode(3);
    TreeNode* root = new TreeNode(1, sec1, sec2);
    auto res = S.tree2str(root);
    cout << res << endl;
    return 0;
}