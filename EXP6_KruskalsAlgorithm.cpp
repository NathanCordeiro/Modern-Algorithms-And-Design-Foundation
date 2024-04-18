//Kruskal's Algorithm minimum cost spanning tree using greedy approach in c++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void heapify(vector<pair<int, pair<int, int>>>& heap, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left].first < heap[smallest].first)
        smallest = left;

    if (right < n && heap[right].first < heap[smallest].first)
        smallest = right;

    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        heapify(heap, n, smallest);
    }
}

int find(int v, vector<int>& parent) {
    if (parent[v] == -1)
        return v;
    return find(parent[v], parent);
}

void unionSets(int x, int y, vector<int>& parent) {
    int xset = find(x, parent);
    int yset = find(y, parent);
    if (xset != yset) {
        parent[xset] = yset;
    }
}

double kruskalMST(vector<pair<int, pair<int, int>>>& edges, int n, vector<pair<int, int>>& t) {
    vector<int> parent(n, -1);
    sort(edges.begin(), edges.end()); // Sorting edges by increasing weight

    int edgeCount = 0;
    double minCost = 0.0;

    for (auto edge : edges) {
        int u = edge.second.first;
        int v = edge.second.second;
        int w = edge.first;

        int set_u = find(u, parent);
        int set_v = find(v, parent);

        if (set_u != set_v) {
            t.push_back({u, v});
            minCost += w;
            unionSets(set_u, set_v, parent);
            edgeCount++;
            if (edgeCount == n - 1) break;
        }
    }

    return minCost;
}

int main() {
    int n, e;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> e;

    vector<pair<int, pair<int, int>>> edges;
    cout << "Enter each edge in the format (weight, end1, end2):" << endl;
    for (int i = 0; i < e; i++) {
        int end1, end2, w;
        cin >> w >> end1 >> end2;
        edges.push_back({w, {end1, end2}});
    }

    vector<pair<int, int>> mst;
    double cost = kruskalMST(edges, n, mst);

    cout << "Edges in the MST:" << endl;
    for (auto& edge : mst) {
        cout << edge.first << " -- " << edge.second << " = ";
        for (auto& e : edges) {
            if (e.second == edge) {
                cout << e.first;
                break;
            }
        }
        cout << endl;
    }
    cout << "Minimum Cost of MST: " << cost << endl;

    return 0;
}
