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
    bool isSymmetric(TreeNode* root) {
        vector<int> preVector;
        vector<int> postVector;
        preOrderTraversal(root, preVector);
        postOrderTraversal(root, postVector);
        auto it1 = preVector.cbegin(), it2 = postVector.cbegin();
        while (it1 != preVector.cend() && it2 != postVector.cend()) {
            if (*it1 != *it2)
                return false;
            it1++;
            it2++;
        }
        return true;
    }
    void preOrderTraversal(TreeNode* root, vector<int>& preVector) {
        if (!root) {
            preVector.emplace_back(-1);
            return;
        }
        preVector.emplace_back(root->val);
        preOrderTraversal(root->left, preVector);
        preOrderTraversal(root->right, preVector);
    }
    void postOrderTraversal(TreeNode* root, vector<int>& postVector) {
        if (!root) {
            postVector.emplace_back(-1);
            return;
        }
        postVector.emplace_back(root->val);
        postOrderTraversal(root->right, postVector);
        postOrderTraversal(root->left, postVector);
    }
};
int main() {
      Solution S;
      TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(2), new TreeNode(2)), new TreeNode(2, nullptr, new TreeNode(2)));
      auto res = S.isSymmetric(root);
      cout << res << endl;
      return 0;
}