#include <bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

// check if leaf node or not
bool isLeaf(TreeNode<int> *root)
{
    if (root->left == nullptr && root->right == nullptr)
    {
        return 1;
    }

    return 0;
}

// left order traversal
void Left_boundary(TreeNode<int> *root, vector<int> &ans)
{
    // current node;
    TreeNode<int> *current_Node = root->left;

    while (current_Node)
    {
        if (!isLeaf(current_Node))
        {
            ans.push_back(current_Node->data);
        }

        // check for left and right
        if (current_Node->left)
        {
            current_Node = current_Node->left;
        }
        else
        {
            current_Node = current_Node->right;
        }
    }
}

// leaf -->inorder traversal
void add_leaves(TreeNode<int> *root, vector<int> &ans)
{

    if (isLeaf(root))
    {
        ans.push_back(root->data);
        return;
    }

    // left
    if (root->left)
        add_leaves(root->left, ans);

    // right
    if (root->right)
        add_leaves(root->right, ans);
}

// right boundary in reverse
void right_reverse(TreeNode<int> *root, vector<int> &ans)
{

    TreeNode<int> *curr = root->right;

    vector<int> temp;

    while (curr)
    {
        if (!isLeaf(curr))
        {
            temp.push_back(curr->data);
        }

        if (curr->right)
            curr = curr->right;

        else
            curr = curr->left;
    }

    for (int i = temp.size() - 1; i >= 0; i--)
    {
        ans.push_back(temp[i]);
    }
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
    vector<int> ans;

    // base case
    if (root == nullptr)
    {
        return ans;
    }

    // check if root is leaf or not, if not push it in the ans
    if (!isLeaf(root))
    {
        ans.push_back(root->data);
    }

    // left boundary
    Left_boundary(root, ans);

    // leaves
    add_leaves(root, ans);

    // right in reverse ordr
    right_reverse(root, ans);

    // return final vector ans;
    return ans;
}