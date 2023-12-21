#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct _node
{
  int key;
  int degree;
  struct _node* left;
  struct _node* right;
  struct _node* parent;
  struct _node* child;
  bool mark;
  bool visited;
}Node;

typedef struct fibonacci_heap
{
  int n;
  Node *min;
  int phi;
  int degree;
}fib_heap;

fib_heap *make_fib_heap();
void insertion(fib_heap *h,Node *new,int val);
Node *extract_min(fib_heap *h);
void consolidate(fib_heap *h);
void fib_heap_link(fib_heap *h,Node *y,Node *x);
Node *find_min_node(fib_heap *x);
void decrease_key(fib_heap *h,Node *node,int key);
void cut(fib_heap *h,Node *node_to_be_decrease,Node *parent_node);
void cascading_cut(fib_heap *h,Node *parent_node);
void delete_node(fib_heap *h,int dec_key);

fib_heap *make_fib_heap()
{
  fib_heap *h;
  h=(fib_heap*)malloc(sizeof(fib_heap));
  h->n=0;
  h->min=NULL;
  h->phi=0;
  h->degree=0;
  return h;
}

void print_heap(Node *n)
{
  Node *x;
  for(x=n;;x=x->right)
  {
    if(x->child==NULL)
    {
      printf("Node with no child (%d) \n",x->key);
    }
    else
    {
      printf("Node (%d) with child (%d) \n",x->key,x->child->key);
      print_heap(x->child);
    }
    if(x->right==n)
    {
      break;
    }
  }
}

void insertion(fib_heap *h,Node *new,int val)
{
  new=(Node*)malloc(sizeof(Node));
  new->key=val;
  new->degree=0;
  new->mark=false;
  new->parent=NULL;
  new->child=NULL;
  new->visited=false;
  new->left=new;
  new->right=new;
  if(h->min==NULL)
  {
    h->min=new;
  }
  else
  {
  h->min->left->right=new;
  new->right=h->min;
  new->left=h->min->left;
  h->min->left=new;
  if(new->key < h->min->key)
  {
    h->min=new;
  }
  }
  (h->n)++;
}

//Find min Node
Node *find_min_node(fib_heap *h)
{
  if(h==NULL)
  {
    printf("\n Fibonacci heap not yet created. \n");
    return NULL;
  }
  else
  {
    return h->min;
  }
}

//Union Operation
fib_heap *unionheap(fib_heap *h1,fib_heap *h2)
{
  fib_heap *hnew;
  hnew=make_fib_heap();
  hnew->min=h1->min;

  Node *temp1,*temp2;
  temp1=hnew->min->right;
  temp2=h2->min->left;

  hnew->min->right->left=h2->min->left;
  hnew->min->right=h2->min;
  h2->min->left=hnew->min;
  temp2->right=temp1;

  if((h1->min == NULL)||(h2->min != NULL && h2->min->key < h1->min->key))
  {
    hnew->min=h2->min;
  }
  hnew->n=h1->n+h2->n;

  return hnew;
}

int cal_degree(int n)
{
  int count=0;

  while(n>0)
  {
    n=n/2;
    count++;
  }
  return count;
}

void consolidate(fib_heap *h)
{
  int degree,i,d;
  degree=cal_degree(h->n);
  Node *A[degree],*x,*y,*z;

  for(i=0;i<=degree;i++)
  {
    A[i]=NULL;
  }
  x=h->min;

  do{
    d=x->degree;
    while(A[d] != NULL)
    {
      y=A[d];
      if(x->key > y-> key)
      {
        Node *exchange_help;
        exchange_help=x;
        x=y;
        y=exchange_help;
      }
      if(y==h->min)
       h->min = x;

      fib_heap_link(h,y,x);
      if(y->right==x)
       h->min=x;

      A[d]=NULL;
      d++;
    }
    A[d]=x;
    x=x->right;
  }while(x != h->min);

  h->min=NULL;
  for(i=0;i<degree;i++)
  {
    if(A[i] != NULL)
    {
      A[i]->left=A[i];
      A[i]->right=A[i];
      if(h->min == NULL)
      {
        h->min=A[i];
      }
      else
      {
        h->min->left->right=A[i];
        A[i]->right=h->min;
        A[i]->left=h->min->left;
        h->min->left=A[i];
        if(A[i]->key < h->min->key)
        {
          h->min=A[i];
        }
      }
      if(h->min==NULL)
      {
        h->min=A[i];
      }
      else if(A[i]->key < h->min->key)
      {
        h->min=A[i];
      }
    }
  }
}

// Linking
void fib_heap_link(fib_heap *h, Node *y, Node *x) {
  y->right->left = y->left;
  y->left->right = y->right;

  if (x->right == x)
    h->min = x;

  y->left = y;
  y->right = y;
  y->parent = x;

  if (x->child == NULL) {
    x->child = y;
  }
  y->right = x->child;
  y->left = x->child->left;
  x->child->left->right = y;
  x->child->left = y;
  if ((y->key) < (x->child->key))
    x->child = y;

  (x->degree)++;
}

// Extract min
Node *extract_min(fib_heap *h) {
  if (h->min == NULL)
    printf("\n The heap is empty");
  else
  {
    Node *temp = h->min;
    Node *pntr;
    pntr = temp;
    Node *x = NULL;
    if (temp->child != NULL)
    {
      x = temp->child;
      do
      {
        pntr = x->right;
        (h->min->left)->right = x;
        x->right = h->min;
        x->left = h->min->left;
        h->min->left = x;
        if (x->key < h->min->key)
          h->min = x;
        x->parent = NULL;
        x = pntr;
      } while (pntr != temp->child);
    }

    (temp->left)->right = temp->right;
    (temp->right)->left = temp->left;
    h->min = temp->right;

    if (temp == temp->right && temp->child == NULL)
      h->min = NULL;
    else
    {
      h->min = temp->right;
      consolidate(h);
    }
    h->n = h->n - 1;
    return temp;
  }
  return h->min;
}

void cut(fib_heap *h, Node *node_to_be_decrease, Node *parent_node) {
  Node *temp_parent_check;

  if (node_to_be_decrease == node_to_be_decrease->right)
    parent_node->child = NULL;

  node_to_be_decrease->left->right = node_to_be_decrease->right;
  node_to_be_decrease->right->left = node_to_be_decrease->left;
  if (node_to_be_decrease == parent_node->child)
    parent_node->child = node_to_be_decrease->right;
  (parent_node->degree)--;

  node_to_be_decrease->left = node_to_be_decrease;
  node_to_be_decrease->right = node_to_be_decrease;
  h->min->left->right = node_to_be_decrease;
  node_to_be_decrease->right = h->min;
  node_to_be_decrease->left = h->min->left;
  h->min->left = node_to_be_decrease;

  node_to_be_decrease->parent = NULL;
  node_to_be_decrease->mark = false;
}

void cascading_cut(fib_heap *h, Node *parent_node)
{
  Node *aux;
  aux = parent_node->parent;
  if (aux != NULL)
  {
    if (parent_node->mark == false)
    {
      parent_node->mark = true;
    }
     else
    {
      cut(h, parent_node, aux);
      cascading_cut(h, aux);
    }
  }
}

void decrease_key(fib_heap *h, Node *node_to_be_decrease, int new_key)
{
  Node *parent_node;
  if (h == NULL)
  {
    printf("\n FIbonacci heap not created ");
    return;
  }
  if (node_to_be_decrease == NULL)
  {
    printf("Node is not in the heap");
  }

  else
  {
    if (node_to_be_decrease->key < new_key)
    {
      printf("\n Invalid new key for decrease key operation \n ");
    }
    else
    {
      node_to_be_decrease->key = new_key;
      parent_node = node_to_be_decrease->parent;
      if ((parent_node != NULL) && (node_to_be_decrease->key < parent_node->key))
      {
        printf("\n cut called");
        cut(h, node_to_be_decrease, parent_node);
        printf("\n cascading cut called");
        cascading_cut(h, parent_node);
      }
      if (node_to_be_decrease->key < h->min->key)
      {
        h->min = node_to_be_decrease;
      }
    }
  }
}

void *find_node(fib_heap *h, Node *n, int key, int new_key)
{
  Node *find_use = n;
  Node *f = NULL;
  find_use->visited = true;
  if (find_use->key == key)
  {
    find_use->visited = false;
    f = find_use;
    decrease_key(h, f, new_key);
  }
  if (find_use->child != NULL)
  {
    find_node(h, find_use->child, key, new_key);
  }
  if ((find_use->right->visited != true))
  {
    find_node(h, find_use->right, key, new_key);
  }

  find_use->visited = false;
}

fib_heap *insertion_procedure() {
  fib_heap *temp;
  int no_of_nodes, ele, i;
  Node *new_node;
  temp = (fib_heap *)malloc(sizeof(fib_heap));
  temp = NULL;
  if (temp == NULL)
  {
    temp = make_fib_heap();
  }
  printf(" \n enter number of nodes to be insert = ");
  scanf("%d", &no_of_nodes);
  for (i = 1; i <= no_of_nodes; i++)
  {
    printf("\n node %d and its key value = ", i);
    scanf("%d", &ele);
    insertion(temp, new_node, ele);
  }
  return temp;
}

void delete_Node(fib_heap *h, int dec_key)
{
  Node *p = NULL;
  find_node(h, h->min, dec_key, -5000);
  p = extract_min(h);
  if (p != NULL)
    printf("\n Node deleted");
  else
    printf("\n Node not deleted:some error");
}

int main(int argc, char **argv)
{
  Node *new_node, *min_node, *extracted_min, *node_to_be_decrease, *find_use;
  fib_heap *heap, *h1, *h2;
  int operation_no, new_key, dec_key, ele, i, no_of_nodes;
  heap = (fib_heap *)malloc(sizeof(fib_heap));
  heap = NULL;
  while (1)
  {
    printf(" \n Operations \n 1. Create Fibonacci heap \n "
    "2. Insert nodes into fibonacci heap \n 3. Find min \n "
    "4. Union \n 5. Extract min \n 6. Decrease key \n "
    "7. Delete node \n 8. print heap \n 9. exit \n");
    printf(" Enter operation no = ");
    scanf("%d", &operation_no);

    switch (operation_no)
    {
      case 1: heap = make_fib_heap();
              break;

      case 2:
        if (heap == NULL)
        {
          heap = make_fib_heap();
        }
        printf(" Enter number of nodes to be insert = ");
        scanf("%d", &no_of_nodes);
        for (i = 1; i <= no_of_nodes; i++)
        {
          printf("\n Node %d and its key value = ", i);
          scanf("%d", &ele);
          insertion(heap, new_node, ele);
        }
        break;

      case 3:
        min_node = find_min_node(heap);
        if (min_node == NULL)
          printf("No minimum value");
        else
          printf("\n min value = %d", min_node->key);
        break;

      case 4:
        if (heap == NULL)
        {
          printf("\n no FIbonacci heap created \n ");
          break;
        }
        h1 = insertion_procedure();
        heap = unionheap(heap, h1);
        printf("Unified Heap:\n");
        print_heap(heap->min);
        break;

      case 5:
          if (heap == NULL)
            printf("Empty Fibonacci heap");
          else
          {
            extracted_min = extract_min(heap);
            printf("\n min value = %d", extracted_min->key);
            printf("\n Updated heap: \n");
            print_heap(heap->min);
          }
          break;

      case 6:
          if (heap == NULL)
            printf("Fibonacci heap is empty");
          else
          {
            printf(" \n node to be decreased = ");
            scanf("%d", &dec_key);
            printf(" \n enter the new key = ");
            scanf("%d", &new_key);
            find_use = heap->min;
            find_node(heap, find_use, dec_key, new_key);
            printf("\n Key decreased- Corresponding heap:\n");
            print_heap(heap->min);
          }

      case 7:
            if (heap == NULL)
              printf("Fibonacci heap is empty");
            else
            {
              printf(" \n Enter node key to be deleted = ");
              scanf("%d", &dec_key);
              delete_Node(heap, dec_key);
              printf("\n Node Deleted- Corresponding heap:\n");
              print_heap(heap->min);
              break;
            }

      case 8:
            print_heap(heap->min);
            break;

      case 9:
            free(new_node);
            free(heap);
            exit(0);

      default:  printf("Invalid choice ");
    }
  }
}
