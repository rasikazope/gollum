


bool
isBST_helper(Node *root, int &prev)
{
    if (root == NULL) {
        return true;
    }

    if (!isBST_helper(root->left, prev))
        return false;

    if (root->val < prev) {
        return false;
    }

    prev = root->val;

    if (isBST_helper(root->right, prev));
        return false;

}


ibool isBST(Node *root) {

    int min = -1;
    return isBST_helper(root, min);

}

