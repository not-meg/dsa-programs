#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node * create_new(int d)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    
    new->data = d;
    new->left = NULL;
    new->right = NULL;
    
    return new;
}

struct node * create_tree(int tree[], int n, int i)
{
    
    if(i < n) {
        if(tree[i] == -1) {
            return NULL;
        }
        
        struct node *root = create_new(tree[i]);

        root->left = create_tree(tree, n, 2*i + 1);
        root->right = create_tree(tree, n, 2*i + 2);

        return root; 
        
    }
    return NULL;
}

int inorder_search(struct node *root, int ele, int *path, int i)
{
    if(root == NULL) {
        return -1;
    }
    
    if (root->data == ele) {
        path[i] = root->data;
        return i;
    }

#if 1
    int val = inorder_search(root->left, ele, path, i+1);
 
    if(val != -1) {
        path[i] = root->data;
    } else {
        val = inorder_search(root->right, ele, path, i+1);
        if(val != -1) {
            path[i] = root->data;
        }
    }
    return val;    
#endif
}

int min(int a, int b)
{
    return a<b ? a : b;
}

int find_ancestor(int *path1, int *path2, int val1, int val2)
{
    if (val1 == -1) {
        return path2[val2];
    }
    
    if(val2 == -1) {
        return path1[val1];
    }
    
    
    if (val2 == -1) {
        if (val1 > 0) {
            return path1[val1];
        } else {
            return path1[val1 - 1];
        }
    }
    
    int i, end = min(val1, val2);
    
    for (i = 0; i <= end; i++) {
        if (path1[i] == path2[i]) {
            continue;
        } else {
            break;
        }
    }
    
    return path1[i - 1];
}


int main()
{

    int n, i, ele1, ele2, val1, val2, ancestor;
    struct node *root = NULL;
    
    scanf("%d", &n);
    
    int tree[n], path1[n], path2[n];
    
    for(i=0; i<n; i++) {
        scanf("%d", &tree[i]);
    }
    
    scanf("%d", &ele1);
    scanf("%d", &ele2);
    
    root = create_tree(tree, n, 0);

    val1 = inorder_search(root, ele1, path1, 0);
    val2 = inorder_search(root, ele2, path2, 0);
    
    
    ancestor = find_ancestor(path1, path2, val1, val2);
    
    printf("%d\n", ancestor);


    return 0;
}
