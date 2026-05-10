//Slip14-b

#include <stdio.h>

int graph[10][10], visited[10], queue[10];
int n, front = -1, rear = -1;

// DFS Function
void DFS(int vertex)
{
    int i;

    printf("%d ", vertex);
    visited[vertex] = 1;

    for(i = 0; i < n; i++)
    {
        if(graph[vertex][i] == 1 && !visited[i])
        {
            DFS(i);
        }
    }
}

// Queue Functions for BFS
void enqueue(int vertex)
{
    if(front == -1)
        front = 0;

    queue[++rear] = vertex;
}

int dequeue()
{
    return queue[front++];
}

// BFS Function
void BFS(int start)
{
    int i, vertex;

    enqueue(start);
    visited[start] = 1;

    while(front <= rear)
    {
        vertex = dequeue();

        printf("%d ", vertex);

        for(i = 0; i < n; i++)
        {
            if(graph[vertex][i] == 1 && !visited[i])
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Input adjacency matrix
    printf("Enter adjacency matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    // DFS Traversal
    for(i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    printf("\nDFS Traversal:\n");
    DFS(start);

    // BFS Traversal
    for(i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    front = rear = -1;

    printf("\n\nBFS Traversal:\n");
    BFS(start);

    // Time Complexity
    printf("\n\nTime Complexity of DFS = O(V + E)");
    printf("\nTime Complexity of BFS = O(V + E)\n");

    return 0;
}

/*Enter number of vertices: 4

Enter adjacency matrix:
0 1 1 0
1 0 1 1
1 1 0 0
0 1 0 0

Enter starting vertex: 0

DFS Traversal:
0 1 2 3

BFS Traversal:
0 1 2 3

Time Complexity of DFS = O(V + E)
Time Complexity of BFS = O(V + E)  */