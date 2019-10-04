/*
Program to implement graph traversal algorithms:
1. Depth First search
2. Breadth First search
3. Topological sort on DAG using DFS
*/

#include<stdio.h>
#include<stdlib.h>
#define N 100

typedef struct node {
    int vertex;
    struct node *next;
}node;

node* adj[N];
int vis[N], queue[N], stack[N], idx, topo[N], indeg[N];

node* newNode(int v) {
    node* n = (node*) malloc (sizeof(node));
    n -> vertex = v;
    n -> next = NULL;
    return n;
}

void init() {
    for (int i = 0; i < N; i++) {
        vis[i] = 0;
        queue[i] = -1;
        stack[i] = 0;
        idx = 0;
        topo[i] = -1;
        indeg[i]=0;
    }
}

void addEdge(int a, int b) {
    if (adj[a] == NULL) {
        adj[a] = newNode(b);
    }
    else {
        node* n = adj[a];
        while (n -> next != NULL) {
            n = n-> next;
        }
        n -> next = newNode(b);
    }
}

void dfs (int s) {
    if (vis[s]) return;
    vis[s] = 1;
    node* n = adj[s];
    while (n != NULL) {
        dfs(n->vertex);
        n = n -> next;
    }
    stack[idx++] = s;
}

void bfs (int s) {
    int i = 0, idx = 0;
    queue[i] = s;
    while (queue[i] != -1) {
        vis[queue[i]] = 1;
        printf("%d ", queue[i]);
        node* n = adj[queue[i]];
        while (n != NULL) {
            if (!vis[n->vertex]) {
                vis[n->vertex] = 1;
                queue[++idx] = n -> vertex;
            }
            n = n -> next;
        }
        i++;
    }
}

void topological_sort() {
    init();
    for (int i = 0; i < N; i++) {
        if (adj[i] == NULL) continue;
        if (!vis[i])
            dfs(i);
    }
    for (int i = N-1; i >= 0; i--) {
        if (stack[i]==0) continue;
        printf("%d ", stack[i]);
    }
}

void topological_sort2() {
    init();
    for (int i = 0; i < N; i++) {
        if (adj[i] == NULL) continue;
        node* n = adj[i];
        while (n != NULL) {
            if (indeg[n->vertex] == -1) indeg[n->vertex] = 0;
            indeg[n->vertex]++;
            n = n->next;
        }
    }
    for (int i = 0; i < N; i++) {
        if (adj[i]==NULL) continue;
        if (indeg[i] == 0) topo[idx++] = i;
    }
    for (int i = 0; i < N; i++) {
        if (topo[i]==-1) break;
        if (vis[topo[i]]) continue;
        printf("%d ", topo[i]);
        vis[topo[i]] = 1;
        node* n = adj[topo[i]];
        while (n != NULL) {
            indeg[n->vertex]--;
            if (indeg[n->vertex] == 0)
            {
                topo[idx++] = n->vertex;
            }
            n = n->next;
        }
    }
}

int main () {
    int m;
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    printf("Enter the edges: \n");
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        addEdge(a, b);
    }
    printf("Enter the starting node of DFS/BFS: ");
    int n;
    scanf("%d", &n);
    if (adj[n] == NULL) {
        printf("The node %d does not exist in the graph", n);
        return 0;
    }
    printf("DFS Traversal: ");
    init(); dfs(n);
    for (int i = N-1; i >= 0; i--) {
        if (stack[i]==0) continue;
        printf("%d ", stack[i]);
    }
    printf("\n");
    printf("BFS Traversal: ");
    init(); bfs(n);
    printf("\n");
    printf("Topological Sort: ");
    topological_sort();
    //topological_sort2();
}
