//dijkstra's algorithm single source shortest path using greedy approach in c++
#include<iostream>
#include<string> // Include string header for using string datatype
#include<climits> // Include climits header for using INT_MAX
#define INF INT_MAX // Use INT_MAX for infinity
#define max 100
using namespace std;

int min_distance(int dist[], bool status[], int n) {
    int min = INF, value = 0; // Initialize min to INF
    for(int i = 0; i < n; i++) {
        if(dist[i] < min && !status[i]) { // Use !status[i] instead of status[i] != true
            min = dist[i];
            value = i;
        }
    }
    return value;
}

void dijkstra(int source, int n, int cost[max][max]) {
    int dist[n], u;
    bool status[n];
    string path[n];
    for(int i = 0; i < n; i++) {
        dist[i] = INF;
        status[i] = false;
        path[i] = to_string(source);
    }

    dist[source] = 0;
    for(u = 0; u < n; u++) {
        u = min_distance(dist, status, n);
        status[u] = true;
        for(int j = 0; j < n; j++) {
            if(!status[j] && cost[u][j] && dist[j] > dist[u] + cost[u][j]) {
                dist[j] = dist[u] + cost[u][j];
                path[j] = path[u] + "->" + to_string(j);
            }
        }
    }

    for(int i = 0; i < n; i++) {
        if(i != source && dist[i] == INF) {
            path[i] = "Does not exist";
        }
    }

    cout << "Source\t\t" << "Destination\t\t" << "Cost\t\t" << "Path\t" << endl;
    for(int i = 0; i < n; i++) {
        cout << " " << source << "\t\t   " << i << "\t\t\t" << dist[i] << "\t\t" << path[i] << endl;
    }
}

int main() {
    int cost[max][max], n, source;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the cost matrix (" << n << "x" << n << "): \n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    cout << "Enter the source vertex: ";
    cin >> source;
    dijkstra(source, n, cost);
    return 0;
}





/// INCASE to_string() does not work in college systems
/// `to_string()` is part of #include<string> but is only available for c++ 11 onwards
/*
#include <iostream>
#include <sstream> // For std::ostringstream

int main() {
    int arr[] = {1, 2, 3, 4, 5}; // Example integer array
    int size = sizeof(arr) / sizeof(arr[0]); // Get the size of the array
    std::string str = "";

    for (int i = 0; i < size; ++i) {
        std::ostringstream oss;
        oss << " -> " << arr[i]; // Concatenate "->" with the integer value
        str = str + oss.str(); // Convert the stream to a string
        std::cout << str << std::endl; // Output the result
    }

    return 0;
}
*/
