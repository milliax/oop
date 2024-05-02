#include "BinarySearchTree.h"

TreeNode* BinarySearchTree::getRoot() { return this->root; }

void BinarySearchTree::insert(TreeNode* node) {
    // Insert the node to the binary search tree
    // if the tree is empty, the node will be the root

    if (root == nullptr) {
        root = node;
        return;
    }

    TreeNode* current = root;

    bool inserted = false;

    while (!inserted) {
        if (current->val > node->val) {
            if (current->left == nullptr) {
                current->left = node;
                inserted = true;
            } else {
                current = current->left;
            }
        } else {
            if (current->right == nullptr) {
                current->right = node;
                inserted = true;
            } else {
                current = current->right;
            }
        }
    }
}

void BinarySearchTree::preorder(TreeNode* root) {
    // Use the preorder method to traverse the binary search tree
    // 遍歷順序是：根、左子樹、右子樹。根排在前面。

    if (root != nullptr) {
        cout << root->val << " ";

        if (root->left != nullptr) {
            preorder(root->left);
        }
        if (root->right != nullptr) {
            preorder(root->right);
        }
    }
}

void BinarySearchTree::inorder(TreeNode* root) {
    // Use the inorder method to traverse the binary search tree
    // 遍歷順序是：左子樹、根、右子樹。根排在中間。

    if (root != nullptr) {
        if (root->left != nullptr) {
            inorder(root->left);
        }

        cout << root->val << " ";

        if (root->right != nullptr) {
            inorder(root->right);
        }
    }
}

void BinarySearchTree::postorder(TreeNode* root) {
    // Use the postorder method to traverse the binary search tree
    // 遍歷順序是：左子樹、右子樹、根。根排在後面。

    if (root != nullptr) {
        if (root->left != nullptr) {
            postorder(root->left);
        }

        if (root->right != nullptr) {
            postorder(root->right);
        }

        cout << root->val << " ";
    }
}

// void BinarySearchTree::print_tree(TreeNode* root) {
//     if(root == nullptr) return;
//     cout << "Root: "<< root->val;
//     if(root->left != nullptr) {
//         cout << " Left: " << root->left->val;
//     }
//     if(root->right != nullptr) {
//         cout << " Right: " << root->right->val;
//     }
//     cout << endl;

//     print_tree(root->left);
//     print_tree(root->right);
// }