#include <stdlib.h>
#include <stdio.h>

struct bin_tree {
    int data;
    struct bin_tree* right, * left;
};
typedef struct bin_tree node;

void insert(node** tree, int val)
{
    node* temp = NULL;
    if (!(*tree))
    {
        temp = (node*)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }

    if (val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if (val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }
}

void print_preorder(node* tree)
{
    if (tree)
    {
        printf("%d\n", tree->data);
        print_preorder(tree->left);
        print_preorder(tree->right);
    }
}

void print_inorder(node* tree)
{
    if (tree)
    {
        print_inorder(tree->left);
        printf("%d\n", tree->data);
        print_inorder(tree->right);
    }
}

void print_postorder(node* tree)
{
    if (tree)
    {
        print_postorder(tree->left);
        print_postorder(tree->right);
        printf("%d\n", tree->data);
    }
}

void deltree(node* tree)
{
    if (tree)
    {
        deltree(tree->left);
        deltree(tree->right);
        free(tree);
    }
}

node* search(node** tree, int val)
{
    if (!(*tree))
    {
        return NULL;
    }

    if (val < (*tree)->data)
    {
        search(&((*tree)->left), val);
    }
    else if (val > (*tree)->data)
    {
        search(&((*tree)->right), val);
    }
    else if (val == (*tree)->data)
    {
        return *tree;
    }
}

void deleteNode(node** tree, int val)
{
    if (!(*tree))
    {
        return;
    }

    if (val < (*tree)->data)
    {
        deleteNode(&((*tree)->left), val);
    }
    else if (val > (*tree)->data)
    {
        deleteNode(&((*tree)->right), val);
    }
    else
    {
        // Node to be deleted found

        // Case 1: No children (leaf node)
        if ((*tree)->left == NULL && (*tree)->right == NULL)
        {
            free(*tree);
            *tree = NULL;
        }
        // Case 2: One child
        else if ((*tree)->left == NULL)
        {
            node* temp = *tree;
            *tree = (*tree)->right;
            free(temp);
        }
        else if ((*tree)->right == NULL)
        {
            node* temp = *tree;
            *tree = (*tree)->left;
            free(temp);
        }
        // Case 3: Two children
        else
        {
            // Find the minimum value node in the right subtree
            node* minValueNode = (*tree)->right;
            while (minValueNode->left != NULL)
            {
                minValueNode = minValueNode->left;
            }

            // Replace the value of the node to be deleted with the value of the minimum value node
            (*tree)->data = minValueNode->data;

            // Recursively delete the minimum value node from the right subtree
            deleteNode(&((*tree)->right), minValueNode->data);
        }
    }
}

int main()
{
    node* root;
    node* tmp;
    int userInput;

    root = NULL;
    /* Inserting nodes into tree */
    while (1)
    {
        printf("Enter a value (-1 to exit): ");
        scanf("%d", &userInput);

        if (userInput == -1)
            break;

        insert(&root, userInput);
    }

    /* Printing nodes of tree */
    printf("Pre Order Display\n");
    print_preorder(root);

    printf("In Order Display\n");
    print_inorder(root);

    printf("Post Order Display\n");
    print_postorder(root);

    /* Search node in tree */
    printf("Enter a value to search: ");
    scanf("%d", &userInput);

    tmp = search(&root, userInput);
    if (tmp)
    {
        printf("Searched node = %d\n", tmp->data);
    }
    else
    {
        printf("Data not found in tree.\n");
    }

    /* Delete a node from the tree */
    printf("Enter a value to delete: ");
    scanf("%d", &userInput);

    deleteNode(&root, userInput);

    /* Print the tree after deletion */
    printf("In Order Display after deletion\n");
    print_inorder(root);

    /* Deleting all nodes of tree */
    deltree(root);

    return 0;
}


