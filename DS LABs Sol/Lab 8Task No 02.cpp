#include <iostream>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
int findLevel(TreeNode* root, int key, int level)
{
    if (root == nullptr)
    {
        return 0;
    }
    if (root->data == key)
    {
        return level;
    }
    int leftLevel = findLevel(root->left, key, level + 1);

    if (leftLevel != 0)
    { 
        return leftLevel;
    }
    return findLevel(root->right, key, level + 1);
}

bool isSibling(TreeNode* root, int a, int b)
{
    if (root == nullptr)
    {
        return false;
    }
    if (root->left == nullptr || root->right == nullptr)
    {
        return false;
    }
    return ((root->left->data == a && root->right->data == b) || (root->left->data == b && root->right->data == a) ||
        isSibling(root->left, a, b) || isSibling(root->right, a, b));
}

bool areCousins(TreeNode* root, int x, int y)
{
    if (root == nullptr)
    {
        return false;
    }
    return ((findLevel(root, x, 1) == findLevel(root, y, 1)) && !isSibling(root, x, y));
}




int main() 
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    int x = 7;
    int y = 5;

    if (areCousins(root, x, y))
    {
        cout << "Nodes " << x << " and " << y << " are cousins." << endl;
    }
    else
    {
        cout << "Nodes " << x << " and " << y << " are not cousins." << endl;
    }

    return 0;
}
