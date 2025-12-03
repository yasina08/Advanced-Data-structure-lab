#include <stdio.h>

#define MAX 100

int parent[MAX];
int rankArr[MAX];   // Rank array for union by rank

// Function to create 'n' disjoint sets
void makeSet(int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;      // each element is its own parent
        rankArr[i] = 0;     // initial rank is 0
    }
}

// Find operation with path compression
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);   // path compression
    return parent[x];
}

// Union operation by rank
void unionSet(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX == rootY)
        return; // already in same set

    // attach smaller rank tree under larger rank tree
    if (rankArr[rootX] < rankArr[rootY]) {
        parent[rootX] = rootY;
    }
    else if (rankArr[rootX] > rankArr[rootY]) {
        parent[rootY] = rootX;
    }
    else {
        parent[rootY] = rootX;
        rankArr[rootX]++;   // increase rank of new root
    }
}

int main() {
    int n = 6;

    // Step 1: Create disjoint sets
    makeSet(n);

    // Step 2: Perform union operations
    unionSet(1, 2);
    unionSet(2, 3);
    unionSet(4, 5);

    // Step 3: Find operations
    printf("Find(3) = %d\n", find(3));
    printf("Find(5) = %d\n", find(5));

    // Step 4: Check whether two elements belong to same set
    if (find(1) == find(3))
        printf("1 and 3 are in the same set\n");
    else
        printf("1 and 3 are NOT in the same set\n");

    if (find(1) == find(5))
        printf("1 and 5 are in the same set\n");
    else
        printf("1 and 5 are NOT in the same set\n");

    return 0;
}
