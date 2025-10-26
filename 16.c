#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct Node {
    int vertex;
    struct Node* next;
};
struct Graph {
    int numVertices;
    struct Node** adjLists;
    int* visited;
};
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    if (graph == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    graph->numVertices = vertices;
    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));
    graph->visited = (int*)malloc(vertices * sizeof(int));
    if (graph->adjLists == NULL || graph->visited == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}
void addEdge(struct Graph* graph, int src, int dest) {
    if (src >= graph->numVertices || dest >= graph->numVertices || src < 0 || dest < 0) {
        printf("Invalid vertex indices: %d, %d\n", src, dest);
        return;
    }
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}
void BFS(struct Graph* graph, int startVertex) {
    if (startVertex >= graph->numVertices || startVertex < 0) {
        printf("Invalid start vertex: %d\n", startVertex);
        return;
    }
    int queue[MAX], front = 0, rear = 0;
    int visited[MAX] = {0};
    queue[rear++] = startVertex;
    visited[startVertex] = 1;
    printf("BFS Traversal: ");
    while (front != rear) {
        int current = queue[front++];
        printf("%d ", current);
        struct Node* temp = graph->adjLists[current];
        while (temp) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) {
                queue[rear++] = adjVertex;
                visited[adjVertex] = 1;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}
void DFSUtil(struct Graph* graph, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    struct Node* temp = graph->adjLists[vertex];
    while (temp) {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex])
            DFSUtil(graph, adjVertex, visited);
        temp = temp->next;
    }
}
void DFS(struct Graph* graph, int startVertex) {
    if (startVertex >= graph->numVertices || startVertex < 0) {
        printf("Invalid start vertex: %d\n", startVertex);
        return;
    }
    int visited[MAX] = {0};
    printf("DFS Traversal: ");
    DFSUtil(graph, startVertex, visited);
    printf("\n");
}
void displayGraph(struct Graph* graph) {
    printf("\nAdjacency List of Graph:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%d: ", i);
        struct Node* temp = graph->adjLists[i];
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
int main() {
    int vertices, edges, src, dest, start;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    struct Graph* graph = createGraph(vertices);
    printf("Enter edges (source destination):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }
    displayGraph(graph);
    printf("Enter starting vertex for traversal: ");
    scanf("%d", &start);
    BFS(graph, start);
    DFS(graph, start);
    return 0;
}