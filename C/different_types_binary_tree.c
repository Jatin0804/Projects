#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>

struct node
{
  int item;
  struct node *left,*right;
};

struct node *createNewNode(int k)
{
  struct node* Node=(struct node*)malloc(sizeof(struct node));
  Node->item=k;
  Node->right=Node->left=NULL;
  return Node;
}

// Checking if a binary tree is a full binary tree
bool isFullBinary(struct node* root)
{
  if(root==NULL)
    return true;

  if(root->left==NULL && root->right==NULL)
    return true;

  if((root->left) && (root->right))
    return (isFullBinary(root->left)  &&  isFullBinary(root->right));

  return false;
}

int depth(struct node* node)
{
  int d=0;
  while(node!=NULL)
  {
    d++;
    node=node->left;
  }
  return d;
}

// Check if the tree is perfect
bool is_perfect(struct node* root,int d,int level)
{
  if(root==NULL)
    return true;

  if(root->left==NULL && root->right==NULL)
    return (d=level+1);

  if(root->left==NULL || root->right==NULL)
    return false;

    return is_perfect(root->left, d, level + 1) && is_perfect(root->right, d, level + 1);
}

//Wrapper function
bool is_Perfect(struct node* root)
{
  int d=depth(root);
  return is_perfect(root,d,0);
}
//Count number of nodes.
int countNodes(struct node* root)
{
  if(root==NULL)
    return (0);

  return (1+countNodes(root->left)+countNodes(root->right));
}

//check if tree is a complete tree
bool isComplete(struct node* root,int index,int numberNodes)
{
  if(root==NULL)
    return true;

  if(index >= numberNodes)
    return false;

  return (isComplete(root->left,2*index+1,numberNodes) && isComplete(root->right,2*index+2,numberNodes));
}

bool is_complete(struct node* root)
{
  int node_count=countNodes(root);
  int index=0;
  return isComplete(root,index,node_count);
}

bool checkheights(struct node* root,int* height)
{
  int leftH=0,rightH=0;
  int l=0,r=0;

  if(root==NULL)
  {
    *height=0;
    return 1;
  }

  l=checkheights(root->left,&leftH);
  r=checkheights(root->right,&rightH);

  *height=(leftH > rightH ? leftH : rightH)+1;

  if((leftH - rightH >= 2) || (rightH - leftH >= 2))
    return 0;
  else
    return 1 && r;
}

bool checkHeight(struct node* root)
{
  int height=0;
  return checkheights(root,&height);
}

int main() {
  struct node *root = NULL;
  root = createNewNode(1);
  root->left = createNewNode(2);
  root->right = createNewNode(3);

  root->left->left = createNewNode(4);
  root->left->right = createNewNode(5);
  root->left->right->left = createNewNode(6);
  root->left->right->right = createNewNode(7);
  //root->right->left=createNewNode(6);

  printf("For Nodes : \n");
  printf(" At root = 1 \n"
         " root->left = 2 \n root->right = 3 \n"
         " root->left->left = 4 \n root->left->right = 5 \n"
         " root->left->right->left = 6 \n root->left->right->right = 7\n\n");
  if (isFullBinary(root))
    printf("The tree is a full binary tree\n");
  else
    printf("The tree is not a full binary tree\n");

  if (is_Perfect(root))
      printf("The tree is a perfect binary tree\n");
  else
      printf("The tree is not a perfect binary tree\n");

  if (is_complete(root))
      printf("The tree is a complete binary tree\n");
  else
      printf("The tree is not a complete binary tree\n");

  if (checkHeight(root))
    printf("The tree is balanced");
  else
    printf("The tree is not balanced");
}
