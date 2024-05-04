// 0/1 Knapsack problem using dynamic programming implemented in c++
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void knapsack(int n, int cap, int p[], int w[])
{

    int k[n+1][cap+1];

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=cap; j++)
        {
            if(i==0 || j==0)
                k[i][j] = 0;
            else if(j<w[i])
                k[i][j] = k[i-1][j];
            else
                k[i][j] = max(k[i-1][j-w[i]] + p[i], k[i-1][j]);
        }
    }

    // Displaying the item-weight table

    cout << "\nItem-Weight Table:\n";
    cout << "     ";

    for (int j = 0; j <= cap; ++j)
    {
        cout << j << "    ";
    }
    cout << "\n";

    for (int i = 0; i <= n; ++i)
    {
        cout << i << "    ";
        for (int j = 0; j <= cap; ++j)
        {
            cout << k[i][j] << "    ";
        }
        cout << "\n";
    }

    // Solution vector

    vector<int> solution;
    vector<int> binaryVector(n + 1, 0); // Initialize binary vector with zeros
    int i = n, j = cap;

    while (i > 0 && j > 0)
    {
        if (k[i][j] != k[i - 1][j])
        {
            solution.push_back(i);
            binaryVector[i] = 1; // Set corresponding item in binary vector to 1
            j -= w[i];
            i--;
        }
        else
        {
            i--;
        }
    }

    // Displaying the solution vector

    cout << "\nSolution Vector:\n";
    cout << " [ ";

    for (int i = solution.size() - 1; i >= 0; --i)
    {
        cout << solution[i] << " ";
    }
    cout << "]\n";


    // Displaying the binary vector

    cout << "Binary Vector:\n";
    cout << " [ ";
    for (int i = 1; i <= n; ++i)
    {
        cout << binaryVector[i] << " ";
    }

    cout << "]\n";
}


int main()
{

    int n, cap;
    cout<<"Enter the number of items: ";
    cin>>n;
    cout<<"Enter the capacity of the bag: ";
    cin>>cap;

    int p[n+1], w[n+1];

    for(int i=1; i<=n; i++)
    {
        cout<<"Enter the weight and profit of item "<<i<<": \n";
        cout<<"Weight: ";
        cin>>w[i];
        cout<<"Profit: ";
        cin>>p[i];
        cout<<endl;
    }

    knapsack(n, cap, p, w);

    return 0;

}
