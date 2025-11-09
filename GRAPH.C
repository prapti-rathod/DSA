#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;
int n; // number of vertices

int main() {
	int i, j, start, choice;

	printf("Enter number of vertices: ");
	scanf("%d", &n);

	printf("Enter adjacency matrix (%d x %d):\n", n, n);
	for (i = 0; i < n; i++) {
    	for (j = 0; j < n; j++) {
        	scanf("%d", &adj[i][j]);
    	}
	}

	printf("Enter starting vertex (0 to %d): ", n - 1);
	scanf("%d", &start);

	while (1) {
    	printf("\n--- Graph Traversal Menu ---\n");
    	printf("1. Breadth First Search (BFS)\n");
    	printf("2. Depth First Search (DFS)\n");
    	printf("3. Exit\n");
    	printf("Enter your choice: ");
    	scanf("%d", &choice);

    	if (choice == 1) {
        	// Reset visited array
        	for (i = 0; i < n; i++) visited[i] = 0;
        	front = rear = -1;

        	// BFS
        	printf("BFS Traversal: ");
        	visited[start] = 1;
        	queue[++rear] = start;

        	while (front != rear) {
            	front++;
            	int v = queue[front];
            	printf("%d ", v);

            	for (i = 0; i < n; i++) {
                	if (adj[v][i] == 1 && visited[i] == 0) {
                    	queue[++rear] = i;
                    	visited[i] = 1;
                	}
            	}
        	}
        	printf("\n");
    	}

    	else if (choice == 2) {
        	// Reset visited array
        	for (i = 0; i < n; i++) visited[i] = 0;

        	// DFS (using stack manually)
        	int stack[MAX];
        	int top = -1;
        	int v = start;
        	printf("DFS Traversal: ");
        	visited[v] = 1;
        	printf("%d ", v);
        	stack[++top] = v;

        	while (top != -1) {
            	v = stack[top];
            	int found = 0;
            	for (i = 0; i < n; i++) {
                	if (adj[v][i] == 1 && visited[i] == 0) {
                    	printf("%d ", i);
                    	visited[i] = 1;
                    	stack[++top] = i;
                    	found = 1;
                    	break;
                	}
            	}
            	if (!found) top--;
        	}
        	printf("\n");
    	}

    	else if (choice == 3) {
        	printf("Exiting program...\n");
        	break;
    	}

    	else {
        	printf("Invalid choice. Try again.\n");
    	}
	}

	return 0;
}
