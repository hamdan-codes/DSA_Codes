#include<stdio.h> 
#include<stdlib.h> 
#include<stdbool.h> 
  
/*  Tree node structure */
struct Node 
{ 
    int key; 
    struct Node *left, *right; 
}; 
  
/* Helper function that allocates a new node with the 
   given key and NULL left and right pointer. */
struct Node *newNode(int k) 
{ 
    struct Node *node = (struct Node*)malloc(sizeof(struct Node)); 
    node->key = k; 
    node->right = node->left = NULL; 
    return node; 
} 
  
/* This function counts the number of nodes in a binary tree */
unsigned int countNodes(struct Node* root) 
{ 
    if (root == NULL) 
        return (0); 
    return (1 + countNodes(root->left) + countNodes(root->right)); 
} 
  
/* This function checks if the binary tree is complete or not */
bool isComplete (struct Node* root,int index, int number_nodes) 
{ 
    // An empty tree is complete 
    if (root == NULL) 
        return (true); 
  
    // If index assigned to current node is more than 
    // number of nodes in tree, then tree is not complete 
    if (index >= number_nodes) 
        return (false); 
  
    // Recur for left and right subtrees 
    return (isComplete(root->left, 2*index + 1, number_nodes) && isComplete(root->right, 2*index + 2, number_nodes)); 
} 
  
// Driver program 
int main() 
{ 
    // Le us create tree in the last diagram above 
    struct Node* root = NULL; 
    root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->right = newNode(6); 
    root->right->left = newNode(8); 
    int node_count = countNodes(root); 
    int index = 0; 
  
    if (isComplete(root, index, node_count)) 
        printf("The Binary Tree is complete\n"); 
    else
        printf("The Binary Tree is not complete\n"); 
    return (0); 
}
