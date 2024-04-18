//Implementation of Brute force pattern matching algorithm or naive pattern matching algorithm in c++
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> match(string sentence, string pattern)
{
    vector<int> positions;
    for (int i = 0; i < sentence.length() - pattern.length() + 1; i++)
    {
        bool matched = true;
        for (int j = 0; j < pattern.length(); j++)
        {
            if (sentence[i + j] != pattern[j])
            {
                matched = false;
                break;
            }
        }
        if (matched)
        {
            positions.push_back(i);
        }
    }
    return positions;
}

int main()
{
    string sentence, pattern;
    cout << "Enter the string : ";
    getline(cin,sentence);

    cout << "Enter the pattern : ";
    getline(cin,pattern);

    vector<int> positions = match(sentence, pattern);

    if (positions.empty())
    {
        cout << "Pattern not Present in the String";
    }
    else
    {
        cout << "Pattern found at indices : ";
        for (int pos : positions)
        {
            cout << pos << " ";
        }
    }
    return 0;
}
