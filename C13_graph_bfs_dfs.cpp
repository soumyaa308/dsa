Represent a given graph using adjacency matrix/list to perform DFS and using adjacency list to perform BFS. 
Use the map of the area around the college as the graph. Identify the prominent land marks as nodes and 
perform DFS and BFS on that.
*/


#include <iostream>
#include <stdlib.h>
using namespace std;

int cost[10][10], i, j, k, n, qu[10], front, rear, v, visit[10], visited[10];
int stk[10], top, visit1[10], visited1[10];

int main()
{
    int m;
    cout << "Enter number of vertices : ";
    cin >> n;
    cout << "Enter number of edges : ";
    cin >> m;
    
    cout << "\nEDGES :\n";
    for (k = 1; k <= m; k++)
    {
        cin >> i >> j;
        cost[i][j] = 1;
        cost[j][i] = 1;
    }
    
    //display function
    cout << "The adjacency matrix of the graph is : " << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << " " << cost[i][j];
        }
        cout << endl;
    }
    
    cout << "Enter initial vertex : ";
    cin >> v;
    cout << "The BFS of the Graph is\n";
    cout << v<<endl;
    visited[v] = 1;
    k = 1;
    while (k < n)
    {
        for (j = 1; j <= n; j++)
            if (cost[v][j] != 0 && visited[j] != 1 && visit[j] != 1)
            {
                visit[j] = 1;
                qu[rear++] = j;
            }
        v = qu[front++];
        cout << v << " ";
        k++;
        visit[v] = 0;
        visited[v] = 1;
    }
    
    cout <<endl<<"Enter initial vertex : ";
    cin >> v;
    cout << "The DFS of the Graph is\n";
    cout << v<<endl;
    visited[v] = 1;
    k = 1;
    while (k < n)
    {
        for (j = n; j >= 1; j--)
            if (cost[v][j] != 0 && visited1[j] != 1 && visit1[j] != 1)
            {
                visit1[j] = 1;
                stk[top] = j;
                top++;
            }
        v = stk[--top];
        cout << v << " ";
        k++;
        visit1[v] = 0;
        visited1[v] = 1;
    }

    return 0;
}

This C++ code demonstrates the Breadth-First Search (BFS) and Depth-First Search (DFS) algorithms for a graph represented as an adjacency matrix.

Here's a breakdown of the code:

Input:
The user inputs the number of vertices (n) and the number of edges (m).
The user then inputs the edges, where each edge is represented by a pair of vertices.
Adjacency Matrix:
The code constructs an adjacency matrix cost[][] based on the input edges.
If there is an edge between vertices i and j, cost[i][j] and cost[j][i] are set to 1 (assuming an unweighted graph).
Breadth-First Search (BFS):
The user inputs the initial vertex v for BFS.
The BFS algorithm is applied to traverse the graph from the initial vertex v.
BFS explores all vertices reachable from v in a level-wise manner.
Visited vertices are marked as visited[], and a queue qu[] is used to keep track of vertices to visit next.
Depth-First Search (DFS):
Similar to BFS, the user inputs the initial vertex v for DFS.
The DFS algorithm is applied to traverse the graph from the initial vertex v.
DFS explores as far as possible along each branch before backtracking.
Visited vertices are marked as visited1[], and a stack stk[] is used to keep track of vertices to visit next.
Output:
The BFS traversal sequence and DFS traversal sequence are printed.
