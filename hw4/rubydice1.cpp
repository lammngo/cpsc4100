//
// Created by lolita kim on 10/27/22.
//

/*
let f(i) = the minimum number of dices that Jerry will bring home after spending D money at index i
Base case: f(0) = 0 //at index 0, D = 0 => #dices = 0
Final result/Goal: f(n-1) //assume the vector size is n, n-1 is the last index of the vector

Solve: f(i) = min(f(i), 1-f(i - dices[j])) //dices: vector of dices
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int minimum_dices(vector<int> &dices, int &amount)
{
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++)
    {
        for (int j = 0; j < dices.size(); j++) // go to last index
        {
            if (dices[j] <= i)
            {
                dp[i] = min(dp[i], 1 + dp[i - dices[j]]);
            }
        }
    }
    return dp[amount];
}

// void parse_string(string &line, vector<int> &v)
// {
//     const string delimiter = " ";
//     size_t pos;
//     size_t first = 0;
//     string token;

//     while ((pos = line.find(delimiter, first)) != string::npos)
//     {
//         token = line.substr(first, pos - first);
//         v.push_back(stoi(token));
//         first = pos + 1;
//     }
//     token = line.substr(first, pos - first);
//     v.push_back(stoi(token));
// }

int main()
{
    int size;
    int amount;

    cin >> size;
    cin >> amount;

    vector<int> dices(size);

    for (int i = 0; i < size; i++)
    {
        cin >> dices[i];
    }
    // int line_num = 0;

    // for (string line; getline(cin, line); line_num++)
    // {
    //     if (line_num == 0)
    //     { // size of an array
    //         parse_string(line, firstLine);
    //         dice.reserve(firstLine[0]);
    //     }
    //     else
    //     {
    //         parse_string(line, dice);
    //     }
    // }
    cout << minimum_dices(dices, amount) << endl;
    return 0;
}
