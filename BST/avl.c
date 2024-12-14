#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    int height;
} TreeNode;

TreeNode* createNode(int val){
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int max(int a, int b){return (a>b)?a:b;}

int getHeight(TreeNode* root){
    if(root==NULL)
        return 0;
    return root->height;
}

int BFactor(TreeNode* root){
    if(root==NULL)
        return 0;
    return getHeight(root->left) - getHeight(root->right);
}

TreeNode* leftRotate(TreeNode* root){
    TreeNode* temp1 = root->right;
    TreeNode* temp2 = temp1->left;

    temp1->left = root;
    root->right = temp2;

    root->height = 1 + max(getHeight(root->left),getHeight(root->right));
    temp1->height = 1 + max(getHeight(temp1->left),getHeight(temp1->right));

    return temp1;
}

TreeNode* rightRotate(TreeNode* root){
    TreeNode* temp1 = root->left;
    TreeNode* temp2 = temp1->right;

    temp1->right = root;
    root->left = temp2;

    root->height = 1 + max(getHeight(root->left),getHeight(root->right));
    temp1->height = 1 + max(getHeight(temp1->left),getHeight(temp1->right));

    return temp1;
}

TreeNode* insert(TreeNode* root,int val){
    if(root==NULL){
        return createNode(val);
    }
    if(val < root->val)
        root->left = insert(root->left,val);
    else
        root->right = insert(root->right, val);

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int bal = BFactor(root);

    if(bal > 1){
        if(val > root->left->val){
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        else{
            return rightRotate(root);
        }
    }

    if(bal < -1){
        if(val > root->right->val){
            return leftRotate(root);
        }
        else{
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }

    return root;
}

void input(TreeNode** root,int n){
    for(int i=0;i<n;i++){
        int temp;
        scanf("%d",&temp);
        *root = insert(*root,temp);
    }
}

void level(TreeNode* root, int l){
    if(root==NULL){
        printf("* ");
        return;
    }
    if(l==0)
        printf("%d ",root->val);
    else{
        level(root->left,l-1);
        level(root->right,l-1);
    }
}

void bfs(TreeNode* root){
    printf("BFS:\n");
    for(int i=0;i<root->height;i++){
        level(root,i);
        printf("\n");
    }
}

void output(TreeNode* root){
    if(root==NULL)
        return;
    output(root->left);
    printf("%d ",root->val);
    output(root->right);
}

int main(){
    int n;
    printf("\nEnter number of nodes : ");
    scanf("%d",&n);
    TreeNode* root = NULL;
    input(&root,n);
    printf("\nInorder : ");
    output(root);
    bfs(root);
    return 0;
}