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
    int maxDepth(TreeNode* root) {
        int max_depth = 0, cur_depth = 0;
        Traversal(root, cur_depth, max_depth);
        return max_depth;
    }
    void Traversal(TreeNode* root, int cur_depth, int& max_depth) {
        if (!root) {
            if (cur_depth > max_depth)
                max_depth = cur_depth;
            return;
        }
        Traversal(root->left, cur_depth + 1, max_depth);
        Traversal(root->right, cur_depth + 1, max_depth);
    }
};
int main() {
    Solution S;
    TreeNode* root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    auto res = S.maxDepth(root);
    cout << res << endl;
    return 0;
}