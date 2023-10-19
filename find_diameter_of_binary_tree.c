#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define MAXQUEUE 10000

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node * create_new(int d)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    
    if(new == NULL) {
        return NULL;
    }
    new->data = d;
    new->left = NULL;
    new->right = NULL;
    
    return new;
}


struct node *create_tree(int tree[], int n, int i) {
    if (i < n && tree[i] != -1) {
        struct node *root = create_new(tree[i]);
        
        root->left = create_tree(tree, n, 2*i + 1);
        root->right = create_tree(tree, n, 2*i + 2);

        return root;
    }
    return NULL;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int find_height(struct node *root)
{
    if (root == NULL || root->data == -1) {
        return 0;
    }

    int left_height = find_height(root->left);
    int right_height = find_height(root->right);

    return (1 + max(left_height, right_height));
}

int find_diameter(struct node *root)
{
    
    if(root == NULL || root->data == -1) {
        return 0;
    }
    int left_height = find_height(root->left);
    int right_height = find_height(root->right);
    
    int left_diameter = find_diameter(root->left);
    int right_diameter = find_diameter(root->right);
    
    int max_diameter = max(left_height + right_height + 1, max(left_diameter, right_diameter));
    
    return max_diameter;
}

int main()
{
    struct node *root = NULL;

    int n, i;
    
    scanf("%d", &n);
    
    int tree[n];
    
    for(i=0; i<n; i++) {
        scanf("%d", &tree[i]);
    }
    
    root = create_tree(tree, n, 0);
    
    int diameter = find_diameter(root);
    
    printf("%d\n", diameter);
}
