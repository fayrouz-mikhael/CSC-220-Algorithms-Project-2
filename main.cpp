// Name : Fayrouz Mikhael

#include <iostream>

#define BLOCKSIZE 256

typedef int object_t;
typedef int key_t;
typedef struct tr_n_t { key_t        key;
    struct tr_n_t  *left;
    struct tr_n_t *right;
    int           height;
} tree_node_t;


int count_keys(tree_node_t *tree, key_t a, key_t b){
    
    if (tree -> height == 0 ){
        
        if ((tree->key < a)&& (tree->key > b))
            return 0;
        else if ((tree->key >= a)&& (tree->key <= b))
            return 1;
        else
            return 0;
    }
    
    else{
        
        if (tree->key < a)
            return count_keys(tree->right,a,b);
        if (tree->key > b)
            return count_keys(tree->left,a,b);
        else
            return (count_keys(tree->right,a,b) + count_keys(tree->left,a,b));
        
    }
    
}

