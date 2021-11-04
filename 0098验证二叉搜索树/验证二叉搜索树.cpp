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
    bool isValidBST(TreeNode* root) {
        vector<int> vec;
        inorderTraversal(vec, root);
        for (size_t i = 1; i < vec.size(); i++) {
            if (vec[i] <= vec[i - 1])
                return false;
        }
        return true;
    }
    void inorderTraversal(vector<int>& vec, TreeNode* root) {
        if (!root)
            return;
        inorderTraversal(vec, root->left);
        vec.emplace_back(root->val);
        inorderTraversal(vec, root->right);
    }
};
int main() {
    Solution S;
    TreeNode* root = new TreeNode(2, new TreeNode(2), new TreeNode(2));
    auto res = S.isValidBST(root);
    cout << res << endl;
    return 0;
}