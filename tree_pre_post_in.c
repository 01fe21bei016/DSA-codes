/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!");
        exit(1);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node in a binary tree
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    }
    else
        {
        if (data <= root->data)
         {
            root->left = insertNode(root->left, data);
         }
    else
        {
            root->right = insertNode(root->right, data);
        }
        }
    return root;
}

// Function to traverse the binary tree in pre-order
void traversePreOrder(struct Node* root,FILE * fp1)
{


    if (root != NULL) {
        fprintf(fp1,"%d ", root->data);
        traversePreOrder(root->left,fp1);
        traversePreOrder(root->right,fp1);
    }
}

// Function to traverse the binary tree in post-order
void traversePostOrder(struct Node* root,FILE * fp1) {
    if (root != NULL) {
        traversePostOrder(root->left,fp1);
        traversePostOrder(root->right,fp1);
        fprintf(fp1,"%d ", root->data);
    }
}
// Function to traverse the binary tree in-order
void traverseInOrder(struct Node* root,FILE * fp1)
{
    if (root != NULL) {
        traverseInOrder(root->left,fp1);
        fprintf(fp1,"%d ", root->data);
        traverseInOrder(root->right,fp1);
    }
}




int main() {
    struct Node* root = NULL;
    FILE * fp1;
    clock_t start,end;
    double total;
    int choice, value;
    srand(time(NULL));

    while (1) {
        printf("1. Insert Node\n");
        printf("2. Traverse In-Order\n");
        printf("3. Traverse Pre-Order\n");
        printf("4. Traverse Post-Order\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:

                fp1=fopen("array.txt","a");




                value = rand() % 100;
                root = insertNode(root, value);
                fprintf(fp1,"Node (%d) inserted successfully.\n", value);
                break;
            case 2:
                fprintf(fp1,"\n In-Order traversal: ");
                start=clock();
                traverseInOrder(root,fp1);
                printf("\n");
                end=clock();
                total=(double)(end-start)/CLOCKS_PER_SEC;
                printf("\n");
                printf("In_order:%f\n ",total);
                break;
            case 3:
                fprintf(fp1,"\n Pre-Order traversal: ");
                start=clock();
                traversePreOrder(root,fp1);
                printf("\n");
                end=clock();
                total=(double)(end-start)/CLOCKS_PER_SEC;
                printf("\n");
                printf("Pre_order:%f\n ",total);

                break;
            case 4:
                fprintf(fp1,"\n Post-Order traversal: ");
                start=clock();
                traversePostOrder(root,fp1);
                printf("\n");
                end=clock();
                total=(double)(end-start)/CLOCKS_PER_SEC;
                printf("\n");
                printf("postorder:%f\n ",total);

                break;
            case 5:
                printf(fp1,"Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
     total=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\n");
    printf("selection_sort timing:%f\n ",total);

    return 0;
}*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!");
        exit(1);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node in a binary tree
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    }
    else {
        if (data <= root->data) {
            root->left = insertNode(root->left, data);
        }
        else {
            root->right = insertNode(root->right, data);
        }
    }
    return root;
}

// Function to traverse the binary tree in pre-order
void traversePreOrder(struct Node* root, FILE* fp1)
{
    if (root != NULL)
    {
        fprintf(fp1, "%d ", root->data);
        traversePreOrder(root->left, fp1);
        traversePreOrder(root->right, fp1);
    }
}

// Function to traverse the binary tree in post-order
void traversePostOrder(struct Node* root, FILE* fp1)
{
    if (root != NULL)
    {
        traversePostOrder(root->left, fp1);
        traversePostOrder(root->right, fp1);
        fprintf(fp1, "%d ", root->data);
    }
}

// Function to traverse the binary tree in-order
void traverseInOrder(struct Node* root, FILE* fp1)
 {
    if (root != NULL)
    {
        traverseInOrder(root->left, fp1);
        fprintf(fp1, "%d ", root->data);
        traverseInOrder(root->right, fp1);
    }
}

int main() {
    struct Node* root = NULL;
    FILE* fp_random = fopen("random.txt", "w");
    FILE* fp_inorder = fopen("inorder.txt", "w");
    FILE* fp_preorder = fopen("preorder.txt", "w");
    FILE* fp_postorder = fopen("postorder.txt", "w");

    clock_t start, end;
    double total;
    int choice, value;
    srand(time(NULL));

    while (1) {
        printf("1. Insert Node\n");
        printf("2. Traverse In-Order\n");
        printf("3. Traverse Pre-Order\n");
        printf("4. Traverse Post-Order\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                value = rand() % 100;
                root = insertNode(root, value);
                fprintf(fp_random, "%d\n", value);
                printf("Node (%d) inserted successfully.\n", value);
                break;
            case 2:
                printf("\n In-Order traversal: ");
                start = clock();
                traverseInOrder(root, fp_inorder);
                printf("\n");
                end = clock();
                total = (double)(end - start)*(1) / CLOCKS_PER_SEC;
                fprintf(fp_inorder,"\nIn_order: %f\n", total);
                break;
            case 3:
                printf("\n Pre-Order traversal: ");
                start = clock();
                traversePreOrder(root, fp_preorder);
                printf("\n");
                end = clock();
                total = (double)(end - start) / CLOCKS_PER_SEC;
                fprintf(fp_preorder,"\nPre_order: %f\n", total);
                break;
            case 4:
                printf("\n Post-Order traversal: ");
                start = clock();
                traversePostOrder(root, fp_postorder);
                printf("\n");
                end = clock();
                total = (double)(end - start) / CLOCKS_PER_SEC;
                fprintf(fp_postorder,"\nPost_order: %f\n", total);
                break;
            case 5:
                printf("Exiting program...\n");
                fclose(fp_random);
                fclose(fp_inorder);
                fclose(fp_preorder);
                fclose(fp_postorder);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

