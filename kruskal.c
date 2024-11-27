#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int parent[MAX];
int v, i, j, cost[MAX][MAX], edgecount, count = 1, mincost = 0, c, rno, cno, v1, v2, k;

// Function to find the parent of a vertex
int find(int i) { 
    return parent[i]; 
}

// Function to unite two components
int uni(int i, int j) {
    if (i != j) {
        parent[j] = i; 
        for (k = 1; k <= v; ++k) {
            if (parent[k] == j) {
                parent[k] = i;
            }
        }
        return 1; 
    }
    return 0; 
}

int main() {
    // Input the number of vertices
    printf("Enter the total number of vertices: ");
    scanf("%d", &v);

    // Initialize the parent array (for union-find)
    for (i = 1; i <= v; i++)
        parent[i] = i;

    // Get the edge weight matrix from the user
    printf("Enter the cost adjacency matrix (enter 0 if no edge exists):\n");
    for (i = 1; i <= v; i++) {
        for (j = i + 1; j <= v; j++) {
            printf("Cost[%d][%d]: ", i, j);
            scanf("%d", &cost[i][j]);
            cost[j][i] = cost[i][j]; // Ensure symmetry

            // Mark absence of an edge with a high value (999)
            if (cost[i][j] == 0) {
                cost[i][j] = 999;
                cost[j][i] = 999;
            }
        }
    }

    edgecount = v - 1; // Number of edges required for the MST

    // Kruskal's algorithm
    while (count <= edgecount) {
        c = 999; // Initialize minimum cost to a high value

        // Find the smallest edge
        for (i = 1; i <= v; i++) {
            for (j = 1; j <= v; j++) {
                if (cost[i][j] < c) {
                    c = cost[i][j];
                    v1 = rno = i;
                    v2 = cno = j;
                }
            }
        }

        // Check if the selected edge forms a cycle
        rno = find(rno);  
        cno = find(cno);  
        if (uni(rno, cno)) {
            printf("Edge %d: (%d -> %d) with cost: %d\n", count++, v1, v2, c);
            mincost += c; // Add the cost of the edge to the total cost
        }

        // Mark the selected edge as used
        cost[v1][v2] = cost[v2][v1] = 999;
    }

    // Output the minimum cost of the MST
    printf("\nMinimum cost of the spanning tree: %d\n", mincost);

    return 0;
}


