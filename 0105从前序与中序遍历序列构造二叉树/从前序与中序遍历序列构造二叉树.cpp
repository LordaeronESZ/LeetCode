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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return recursionCreate({ 0,preorder.size() - 1 }, { 0,inorder.size() - 1 }, preorder, inorder);
    }
    TreeNode* recursionCreate(pair<int, int> pre, pair<int, int> in, vector<int>& preorder, vector<int>& inorder) {
        if (pre.first > pre.second || in.first > in.second)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[pre.first]);
        int pos = in.first;
        while (pos <= in.second && inorder[pos] != preorder[pre.first])
            pos++;
        int leftNum = pos - in.first;
        root->left = recursionCreate({ pre.first + 1,pre.first + leftNum }, { in.first,pos - 1 }, preorder, inorder);
        root->right = recursionCreate({ pre.first + leftNum + 1,pre.second }, { pos + 1,in.second }, preorder, inorder);
        return root;
    }
};
void preorderTraversal(TreeNode* root) {
    if (!root)
        return;
    cout << root->val << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
int main() {
    Solution S;
    vector<int> preorder = { 3,9,20,15,7 };
    vector<int> inorder = { 9,3,15,20,7 };
    auto res = S.buildTree(preorder, inorder);
    preorderTraversal(res);
    return 0;
}