#include <bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Lets create an ans vector
    vector<int> ans;

    // check for the base case
    if (root == NULL)
    {
        return ans;
    }

    // create a queue to store the elements and pop
    queue<BinaryTreeNode<int> *> q;

    // lets push the root in the queue
    q.push(root);

    // lets initialize an direction flag
    bool left_to_right = true;

    while (!q.empty())
    {
        // operate each level at a time
        int size = q.size();

        // temp vector to store the levels
        vector<int> temp(size);

        for (int i = 0; i < size; i++)
        {
            BinaryTreeNode<int> *front_element = q.front();

            // pop from the queue
            q.pop();

            // check for the directions
            int index = left_to_right ? i : (size - i - 1);

            temp[index] = front_element->data;

            // check for the left and right child and insert in the queue
            if (front_element->left != NULL)
            {
                q.push(front_element->left);
            }

            if (front_element->right != NULL)
            {
                q.push(front_element->right);
            }
        }

        // store the temp in ans
        for (auto it : temp)
        {
            ans.push_back(it);
        }

        // reverse the direction
        left_to_right = !left_to_right;
    }

    return ans;
}
