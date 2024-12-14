#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* createNode(int val){
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

TreeNode* insert(TreeNode* root, int val){
    if(root == NULL){
        return createNode(val);
    }
    if(val < root->val){
        root->left = insert(root->left, val);
    }else{
        root->right = insert(root->right, val);
    }
    return root;
}

void inorder(TreeNode* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

int main(){
    int n;
    printf("\nEnter number of nodes : ");
    scanf("%d", &n);
    TreeNode* root = NULL;
    printf("\nEnter %d node values :\n",n);
    for(int i=0;i<n;i++){
        int val;
        scanf("%d", &val);
        root = insert(root, val);
    }
    inorder(root);
    return 0;
}