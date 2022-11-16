#include <iostream>
#include <vector>
#include <string>

using namespace std;

int LDS(vector<int> &nums_chain)
{
    vector<int> lds(nums_chain.size(), 1); // base case
    for (int i = 1; i < nums_chain.size(); i++)
    {
        for (int j = 0; j <= i - 1; j++)
        {
            if (nums_chain[i] < nums_chain[j])
            {
                lds[i] = max(lds[i], 1 + lds[j]);
            }
        }
    }
    return *max_element(lds.begin(), lds.end());
}

int main()
{
    int size;

    cin >> size;

    vector<int> dices(size);

    for (int i = 0; i < size; i++)
    {
        cin >> dices[i];
    }
    // int line_num = 0;

    // for (string line; getline(cin, line); line_num++)
    // {
    //     if (line_num == 0)
    //     {
    //         dices.reserve(stoi(line));
    //     }
    //     const string delimiter = " ";
    //     size_t pos;
    //     size_t first = 0;
    //     string token;

    //     while ((pos = line.find(delimiter, first)) != string::npos)
    //     {
    //         token = line.substr(first, pos - first);
    //         dices.push_back(stoi(token));
    //         first = pos + 1;
    //     }
    //     token = line.substr(first, pos - first);
    //     dices.push_back(stoi(token));
    // }
    cout << LDS(dices) << endl;
    return 0;
}
