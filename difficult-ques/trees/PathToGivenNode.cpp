#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool f(TreeNode *root, vector<int> &ans, int x)
{
    if (!root)
        return false;
    ans.push_back(root->val);

    if (root->val == x)
        return true;

    if (f(root->left, ans, x) || f(root->right, ans, x))
        return true;
    ans.pop_back();
    return false;
}
vector<int> solve(TreeNode *A, int B)
{
    vector<int> ans;
    if (A == nullptr)
        return ans;
    f(A, ans, B);
    return ans;
}
