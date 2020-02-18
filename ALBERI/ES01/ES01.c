#include <stdio.h>
#include <stdlib.h>

struct tree_node
{
    struct tree_node *left;
    struct tree_node *right;
    int key;
    int data;
};

struct tree_node * find_by_key(struct tree_node *tree, int key);
void in_order_view(struct tree_node* tree);
void insert (struct tree_node **tree, struct tree_node* new);
struct tree_node* create(int indice, int data);

int main(int argc, char const *argv[]){
    /* code */
    struct tree_node *tree;
    int n = 0;
    int indice = 0;
    int dato = 0;
    tree = NULL;
    do{
        printf("Inserire -1 per uscire : ");
        scanf("%d", &n);
        if(n>=0){
            printf("Inserire l'indice : ");
            scanf("%d", &indice);
            printf("Inserire il dato : ");
            scanf("%d", &dato);
            insert(&tree ,create(indice , dato));
        }
    }while(n>=0);
    in_order_view(tree);
    return 0;
}

struct tree_node* create(int indice, int data){
    struct tree_node* t = (struct tree_node*) malloc(sizeof(struct tree_node));
    t->data=data;
    t->key=indice;
    t->left=NULL;
    t->right=NULL;
    return t;
}

struct tree_node * find_by_key(struct tree_node *tree, int key){
  if (tree == NULL) {
    return NULL;
  }else{
    if (key > tree->key) {
      return find_by_key(tree->left, key);
    }else{
      if (key < tree->key) {
        return find_by_key(tree->right, key);
      }else{
        return tree;
      }
    }
  }
}

void in_order_view(struct tree_node* tree){
  if (tree != NULL) {
    in_order_view(tree->left);
    printf("Key %d, value %d\n", tree->key, tree->data);
    in_order_view(tree->right);
  }
}

void insert (struct tree_node **tree, struct tree_node* new){
  if (*tree == NULL) {
    *tree = new;
    (*tree)->left = NULL;
    (*tree)->right = NULL;
  }else{
    if (new->key < (*tree)->key) {
      insert(&(*tree)->left, new);
    }else{
      if (new->key > (*tree)->key) {
        insert(&(*tree)->right, new);
      }else{
        printf("Chiave duplicata!! \n");
      }
    }
  }
}