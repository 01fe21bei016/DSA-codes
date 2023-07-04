#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100

struct Node
{
    int vertex;
    struct Node* next;
};

struct Graph
{
    int numNodes;
    struct Node* adjList[MAX_NODES];
};

struct Node* createNode(int v)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Graph* graph, int src, int dest)
{
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

void bfs(struct Graph* graph, int startNode)
{
    //bool visited[MAX_NODES] = { false };
    int queue[MAX_NODES];
    int front = 0, rear = 0;

    queue[rear++] = startNode;
    visited[startNode] = true;

    while (front != rear)
    {
        int currentNode = queue[front++];
        printf("%d ", currentNode);

        struct Node* neighbor = graph->adjList[currentNode];
        while (neighbor != NULL)
        {
            int neighborVertex = neighbor->vertex;
            if (!visited[neighborVertex])
            {
                queue[rear++] = neighborVertex;
                visited[neighborVertex] = true;
            }
            neighbor = neighbor->next;
        }
    }
}

int main()
{
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &graph->numNodes);
    for (int i = 0; i < graph->numNodes; i++)
    {
        graph->adjList[i] = NULL;
    }

    int numEdges;
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    for (int i = 0; i < numEdges; i++)
    {
        int src, dest;
        printf("Enter the source and destination of edge %d: ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    int startNode;
    printf("Enter the starting node for BFS: ");
    scanf("%d", &startNode);

    printf("BFS traversal starting from node %d: ", startNode);
    bfs(graph, startNode);

    return 0;
}

//geeksforgeeks

/*#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

// This struct represents a directed graph using
// adjacency list representation
typedef struct Graph_t
{

    int V;
    bool adj[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Constructor
Graph* Graph_create(int V)
{
    Graph* g = malloc(sizeof(Graph));
    g->V = V;

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            g->adj[i][j] = false;
        }
    }

    return g;
}

// Destructor
void Graph_destroy(Graph* g)
{
     free(g);
}

// Function to add an edge to graph
void Graph_addEdge(Graph* g, int v, int w)
{
    // Add w to v’s list.
    g->adj[v][w] = true;
}

// Prints BFS traversal from a given source s
void Graph_BFS(Graph* g, int s)
{
    // Mark all the vertices as not visited
    bool visited[MAX_VERTICES];
    for (int i = 0; i < g->V; i++)
    {
        visited[i] = false;
    }

    // Create a queue for BFS
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue[rear++] = s;

    while (front != rear)
    {

        // Dequeue a vertex from queue and print it
        s = queue[front++];
        printf("%d ", s);

        // Get all adjacent vertices of the dequeued
        // vertex s.
        // If an adjacent has not been visited,
        // then mark it visited and enqueue it
        for (int adjacent = 0; adjacent < g->V;
             adjacent++) {
            if (g->adj[s][adjacent] && !visited[adjacent]) {
                visited[adjacent] = true;
                queue[rear++] = adjacent;
            }
        }
    }
}

// Driver code
int main()
{
    // Create a graph
    Graph* g = Graph_create(4);
    Graph_addEdge(g, 0, 1);
    Graph_addEdge(g, 0, 2);
    Graph_addEdge(g, 1, 2);
    Graph_addEdge(g, 2, 0);
    Graph_addEdge(g, 2, 3);
    Graph_addEdge(g, 3, 3);

    printf("Following is Breadth First Traversal "
           "(starting from vertex 2) \n");
    Graph_BFS(g, 2);
    Graph_destroy(g);

    return 0;
}
*/

//dfs

#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

struct stack
{
    int data[SIZE];
    int top;
};

void push(struct stack *sptr,int el);
int pop(struct stack *sptr);
void DFS(int i);

int main()
{
    DFS(2);
    return 0;
}



void push(struct stack *sptr,int el)
{
    if(sptr->top==SIZE-1)
    {
        printf("overflow\n");
    }
    else{
        sptr->top++;
        sptr->data[sptr->top]=el;
    }
}

int pop(struct stack *sptr)
{
    int el;
    if(sptr->top==-1)
    {
        printf("underflow\n");
    }
    else{
        el=sptr->data[sptr->top];
        sptr->top--;
    }
    return el;
}

int visited[7]={0,0,0,0,0,0,0};
int A[7][7]=
{
{0,1,1,1,0,0,0},
{1,0,0,0,0,0,0},
{1,0,0,0,0,0,0},
{1,0,0,0,1,1,1},
{0,0,0,1,0,0,0},
{0,0,0,1,0,1,1},
{0,1,1,0,0,0,0}
};

void DFS(int i)
{
    struct stack s;
    struct stack *sptr;
    sptr=&s;
    sptr->top=-1;
    push(sptr,i);
    i=pop(sptr);
    printf("%d ",i);
    visited[i]=1;
    for(int j=0;j<7;j++)
    {
        if(A[i][j]==1 && !visited[j])
        {
            DFS(Nj);
        }
    }
}

//bfs



#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Queue implementation
struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

void initQueue(struct Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isEmpty(struct Queue* queue) {
    return queue->front == -1;
}

void enqueue(struct Queue* queue, int value) {
    if (queue->rear == MAX_SIZE - 1) {
        printf("Queue is full\n");
        return;
    }
    if (queue->front == -1)
        queue->front = 0;
    queue->items[++queue->rear] = value;
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        exit(EXIT_FAILURE);
    }
    int item = queue->items[queue->front];
    if (queue->front == queue->rear)
        queue->front = queue->rear = -1;
    else
        queue->front++;
    return item;
}

// Graph representation using adjacency matrix
struct Graph {
    int adjacencyMatrix[MAX_SIZE][MAX_SIZE];
    int numVertices;
};

struct Graph* createGraph(int numVertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    // Initialize adjacency matrix with zeros
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }

    return graph;
}

void BFS(struct Graph* graph, int startVertex) {
    struct Queue* queue = malloc(sizeof(struct Queue));
    initQueue(queue);

    int numVertices = graph->numVertices;
    int* visited = calloc(numVertices, sizeof(int));

    enqueue(queue, startVertex);
    visited[startVertex] = 1;

    while (!isEmpty(queue)) {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        for (int i = 0; i < numVertices; ++i) {
            if (graph->adjacencyMatrix[currentVertex][i] && !visited[i]) {
                enqueue(queue, i);
                visited[i] = 1;
            }
        }
    }

    free(queue);
    free(visited);
}

int main() {
    int numVertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    struct Graph* graph = createGraph(numVertices);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            scanf("%d", &graph->adjacencyMatrix[i][j]);
        }
    }

    int startVertex;
    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    printf("BFS Traversal: ");
    BFS(graph, startVertex);

    return 0;
}


