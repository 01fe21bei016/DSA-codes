/*#include <stdio.h>
int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapsack(int capacity, int weights[], int values[], int n)
{
    int knapsackMatrix[n + 1][capacity + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= capacity; j++)
         {
            if (i == 0 || j == 0)
                knapsackMatrix[i][j] = 0;
            else if (weights[i - 1] <= j)
                knapsackMatrix[i][j] = max(values[i - 1] + knapsackMatrix[i - 1][j - weights[i - 1]],knapsackMatrix[i - 1][j]);
            else
                knapsackMatrix[i][j] = knapsackMatrix[i - 1][j];
        }
    }

    return knapsackMatrix[n][capacity];
}

int main()
 {
    int capacity, n;
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    printf("Enter the number of items: ");
    scanf("%d", &n);
    int weights[n], values[n];
    printf("Enter the weights and values of the items:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Item %d:\n", i + 1);
        printf("Weight: ");
        scanf("%d", &weights[i]);
        printf("Value: ");
        scanf("%d", &values[i]);
    }
    int maxValue = knapsack(capacity, weights, values, n);
    printf("The maximum value that can be achieved is: %d\n", maxValue);

    return 0;
}*/






#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int capacity, int weights[], int values[], int n) {
    int knapsackMatrix[n + 1][capacity + 1];

    // Initialize the first row and column of the matrix with zeros
    for (int i = 0; i <= n; i++)
        knapsackMatrix[i][0] = 0;
    for (int j = 0; j <= capacity; j++)
        knapsackMatrix[0][j] = 0;

    // Fill the knapsack matrix using dynamic programming
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= capacity; j++) {
            if (weights[i - 1] <= j)
                knapsackMatrix[i][j] = max(values[i - 1] + knapsackMatrix[i - 1][j - weights[i - 1]],
                                           knapsackMatrix[i - 1][j]);
            else
                knapsackMatrix[i][j] = knapsackMatrix[i - 1][j];
        }
    }

    return knapsackMatrix[n][capacity];
}

int main() {
    int capacity, n;

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    printf("Enter the number of items: ");
    scanf("%d", &n);

    int weights[n], values[n];

    printf("Enter the weights and values of the items:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d:\n", i + 1);
        printf("Weight: ");
        scanf("%d", &weights[i]);
        printf("Value: ");
        scanf("%d", &values[i]);
    }

    int maxValue = knapsack(capacity, weights, values, n);
    printf("The maximum value that can be achieved is: %d\n", maxValue);

    return 0;
}
