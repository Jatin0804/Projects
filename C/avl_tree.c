#include<stdio.h>
#include<stdlib.h>

struct node
{
  int key;
  struct node* left;
  struct node* right;
  int height;
};

int max(int a,int b)
{
  return (a>b)?a:b;
}

int height(struct node* h)
{
  if(h==NULL)
    return 0;

  return h->height;
}

struct node *newnode(int key)
{
  struct node *Node=(struct node*)malloc(sizeof(struct node));
  Node->key=key;
  Node->left=NULL;
  Node->right=NULL;
  Node->height=1;
  return Node;
}

struct node *rightrotate(struct node* y)
{
  struct node *x=y->left;
  struct node *t2=x->right;

  x->right=y;
  y->left=t2;

  y->height=max(height(y->left),height(y->right))+1;
  x->height=max(height(x->left),height(x->right))+1;

  return x;
}

struct node *leftrotate(struct node* x)
{
  struct node *y=x->right;
  struct node *t2=y->left;

  y->left=x;
  x->right=t2;

  y->height=max(height(y->left),height(y->right))+1;
  x->height=max(height(x->left),height(x->right))+1;

  return x;
}

int getbalance(struct node* n)
{
  if(n==NULL)
    return 0;

  return height(n->left)-height(n->right);
}

struct node *insert(struct node* n,int key)
{
  if(n==NULL)
    return (newnode(key));

  if(key < n->key)
    n->left=insert(n->left,key);
  else if(key > n->key)
    n->right=insert(n->right,key);
  else
    return n;

  n->height=1+max(height(n->left),height(n->right));

  int balance=getbalance(n);
  if(balance > 1 && key < n->left->key)
    return rightrotate(n);

  if(balance < -1  && key > n->right->key)
    return leftrotate(n);

  if(balance > 1 && key > n->left->key)
  {
    n->left = leftrotate(n->left);
    return rightrotate(n);
  }

  if(balance < -1 && key < n->left->key)
  {
    n->right = rightrotate(n->right);
    return leftrotate(n);
  }

  return n;
}

struct node* minValue(struct node* n)
{
  struct node* current=n;

  while(current->left != NULL)
    current=current->left;

  return current;
}

struct node* delete(struct node* root,int key)
{
  if(root==NULL)
    return root;

  if(key < root->key)
    root->left=delete(root->left,key);
  else if(key > root->key)
    root->right=delete(root->right,key);
  else
  {
    if((root->left==NULL) || (root->right==NULL))
    {
      struct node* temp=root->left ? root->left : root->right;

    if(temp==NULL)
    {
      temp=root;
      root=NULL;
    }
    else
    {
      *root=*temp;
    }
    free(temp);
  }
  else
  {
    struct node* temp=minValue(root->right);

    root->key=temp->key;

    root->right=delete(root->right,temp->key);

  }
  }

  if(root==NULL)
    return root;

  root->height=1+max(height(root->left),height(root->right));

  int balance=getbalance(root);
  if(balance > 1 && getbalance(root->left) >= 0)
    return rightrotate(root);

  if(balance > 1 && getbalance(root->left) < 0)
  {
    root->left=leftrotate(root->left);
    return rightrotate(root);
  }

  if(balance < -1 && getbalance(root->right) <= 0)
    return leftrotate(root);

  if(balance < -1 && getbalance(root->right) > 0)
  {
    root->right=rightrotate(root->right);
    return leftrotate(root);
  }

return root;
}

void printpre(struct node* root)
{
  if(root != NULL)
  {
    printf("%d",root->key);
    printpre(root->left);
    printpre(root->right);
  }
}

int main()
{
  struct node* root=NULL;

  root=insert(root,2);
  root=insert(root,1);
  root=insert(root,7);
  root=insert(root,4);
  root=insert(root,5);
  root=insert(root,3);
  root=insert(root,8);

  printpre(root);

  root=delete(root,3);

  printf("\nAfter deletion : ");
  printpre(root);

  return 0;
}
