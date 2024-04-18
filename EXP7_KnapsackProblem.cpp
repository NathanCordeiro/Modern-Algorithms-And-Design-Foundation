// 0/1 Knapsack problem using dynamic programming implemented in c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void KNAPSACK(int n, int cap, vector<pair<int, int>>& items) {
    vector<vector<int>> k(n + 1, vector<int>(cap + 1, 0));

    // Build table k[][] in bottom up manner
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= cap; j++) {
            if (i == 0 || j == 0) {
                k[i][j] = 0;
            } else if (items[i].second <= j) {
                k[i][j] = max(items[i].first + k[i-1][j-items[i].second], k[i-1][j]);
            } else {
                k[i][j] = k[i-1][j];
            }
        }
    }

    // Display the maximum profit
    cout << "Maximum profit is: " << k[n][cap] << endl;

    // Trace the items included in the knapsack
    int i = n, j = cap;
    cout << "Items included in the knapsack:" << endl;
    while (i > 0 && j > 0) {
        if (k[i][j] != k[i-1][j]) {
            cout << "Item " << i << " with weight " << items[i].second << " and profit " << items[i].first << endl;
            j -= items[i].second;
            i -= 1;
        } else {
            i -= 1;
        }
    }
}

int main() {
    int n, cap;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter knapsack capacity: ";
    cin >> cap;
    vector<pair<int, int>> items(n + 1);

    cout << "Enter profits and weights of items as (profit, weight):" << endl;
    for (int i = 1; i <= n; i++) {
        cin >> items[i].first >> items[i].second;
    }

    KNAPSACK(n, cap, items);

    return 0;
}
