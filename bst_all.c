#include <stdio.h>
#include<stdlib.h>
// Structure of the node
typedef struct treeNode {
    int data;
    struct treeNode* left;
    struct treeNode* right;
} treeNode;

// Utility function to print
// the inorder traversal of the BST.
void inorder(treeNode* root)
{
    if (root != NULL) {
        inorder(root->left);
        printf(" %d ",root->data);
        inorder(root->right);
    }
}

// Utility function to insert
// nodes into our BST
treeNode* insert(treeNode* root, int key)
{
    // Check if tree is empty
    if (root == NULL) {
        treeNode* temp;
        temp = (treeNode*)malloc(sizeof(treeNode));
        temp->data = key;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    if (key < root->data) {

        // if the key to be inserted
        // is lesser than the root,
        // insert into the left subtree,
        // and recursively call
        // the insert function with the
        // root->left as the new root.
        root->left = insert(root->left, key);
    }
    else {

        // if the key to be inserted
        // is greater than the root,
        // insert into the right subtree,
        // and recursively call
        // the insert function with the
        // root->right as the new root.
        root->right = insert(root->right, key);
    }
    return root;
}

// Iterative Function to delete
// 'key' from the BST.
treeNode* deleteIterative(treeNode* root, int key)
{
    treeNode* curr = root;
    treeNode* prev = NULL;

    // Check if the key is actually
    // present in the BST.
    // the variable prev points to
    // the parent of the key to be deleted.
    while (curr != NULL && curr->data != key) {
        prev = curr;
        if (key < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }

    if (curr == NULL) {
        printf("Key %d  not found in the provided BST.\n",root->data);
        return root;
    }

    // Check if the node to be
    // deleted has atmost one child.
    if (curr->left == NULL
        || curr->right == NULL) {

        // newCurr will replace
        // the node to be deleted.
        treeNode* newCurr;

        // if the left child does not exist.
        if (curr->left == NULL)
            newCurr = curr->right;
        else
            newCurr = curr->left;

        // check if the node to
        // be deleted is the root.
        if (prev == NULL)
            return newCurr;

        // check if the node to be deleted
        // is prev's left or right child
        // and then replace this with newCurr
        if (curr == prev->left)
            prev->left = newCurr;
        else
            prev->right = newCurr;

        // free memory of the
        // node to be deleted.
        free(curr);
    }

    // node to be deleted has
    // two children.
    else {
        treeNode* p = NULL;
        treeNode* temp;

        // Compute the inorder successor
        temp = curr->right;
        while (temp->left != NULL) {
            p = temp;
            temp = temp->left;
        }

        // check if the parent of the inorder
        // successor is the root or not.
        // if it isn't, then make the
        // left child of its parent equal to the
        // inorder successor's right child.
        if (p != NULL)
            p->left = temp->right;

        // if the inorder successor was the
        // root, then make the right child
        // of the node to be deleted equal
        // to the right child of the inorder
        // successor.
        else
            curr->right = temp->right;

        curr->data = temp->data;
        free(temp);
    }
    return root;
}

// Driver Code
int main()
{
    /*
         10
        /  \
       7    15
      / \   / \
      5  8 11 18

    */
    treeNode* root = NULL;
    root = insert(root, 10);
    root = insert(root, 7);
    root = insert(root, 5);
    root = insert(root, 8);
    root = insert(root, 15);
    root = insert(root, 11);
    root = insert(root, 18);

    printf("Inorder traversal of original BST:");
    inorder(root);
    printf("\n");

    // delete node with data value 11 (leaf)
    root = deleteIterative(root, 11);
    printf("\nDeletion of 11\n");
    printf("Inorder traversal post deletion:");
    inorder(root);
    printf("\n");

    // delete node with data value 15
    // (internal node with one child)
    root = deleteIterative(root, 15);
    printf("\nDeletion of 15\n");
    printf("Inorder traversal post deletion:");
    inorder(root);
    printf("\n");

    // delete node with data value 10
    // (root, two children)
    root = deleteIterative(root, 10);
    printf("\nDeletion of 10\n");
    printf("Inorder traversal post deletion:");
    inorder(root);
	printf("\n");
    return 0;
}
