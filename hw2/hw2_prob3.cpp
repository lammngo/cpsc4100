//
// Created by lolita kim on 10/5/22.
//
#include <iostream>
#include <algorithm>

typedef long long LL;
using namespace std;

LL minSubArrayHelper(int arr[], int first, int last)
{
    if (last - first < 1)
        return 0;

    if (last - first == 1)
        return arr[first];

    int _mid   = first + (last - first) / 2;
    auto _min1 = minSubArrayHelper(arr, first, _mid);
    auto _min2 = minSubArrayHelper(arr, _mid, last);

    LL _min = min(_min1, _min2);

    LL _sum          = 0;
    LL _min_left_sum = numeric_limits<LL>::max();
    for (int _left = _mid - 1; _left >= first; --_left)
    {
        _sum += arr[_left];
        _min_left_sum = min(_min_left_sum, _sum);
    }

    _sum                       = 0;
    LL _min_right_sum = numeric_limits<LL>::max();
    for (int _right = _mid; _right < last; ++_right)
    {
        _sum += arr[_right];
        _min_right_sum = min(_min_right_sum, _sum);
    }

    return min((_min_left_sum + _min_right_sum), _min);
}

LL maxSubArrayHelper(int arr[], int first, int last)
{
    if (last - first < 1)
        return 0;

    if (last - first == 1)
        return arr[first];

    int _mid   = first + (last - first) / 2;
    auto _max1 = maxSubArrayHelper(arr, first, _mid);
    auto _max2 = maxSubArrayHelper(arr, _mid, last);

    LL _max = max(_max1, _max2);

    LL _sum          = 0;
    LL _max_left_sum = numeric_limits<LL>::min();
    for (int _left = _mid - 1; _left >= first; --_left)
    {
        _sum += arr[_left];
        _max_left_sum = max(_max_left_sum, _sum);
    }

    _sum                       = 0;
    LL _max_right_sum = numeric_limits<LL>::min();
    for (int _right = _mid; _right < last; ++_right)
    {
        _sum += arr[_right];
        _max_right_sum = max(_max_right_sum, _sum);
    }

    return max((_max_left_sum + _max_right_sum), _max);
}

LL maxSubArraySumCircular(int arr[], int n)
{
    LL maxSum = maxSubArrayHelper(arr, 0, n);
    LL minSum = minSubArrayHelper(arr, 0, n);

    LL sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    if (sum == minSum)
        return maxSum;

    return max(maxSum, (sum - minSum));
}
int main(){
    int cap = 0;
    int current_size = 0;
    int *arr;
    int line_num = 0;

    for(string line; getline(cin, line); line_num++){
        if(line_num == 0){ //size of an array
            cap = stoi(line);
            arr = new int[cap];
        }
        else{
            const string delimiter = " ";
            int first = 0;
            int end = 0;
            while((end = line.find(delimiter, first)) != string::npos){
                string token = line.substr(first, end - first);
                arr[current_size] = stoi(token);
                current_size++;
                first = end + 1;
            }
            string token = line.substr(first, end - first);
            arr[current_size] = stoi(token);
            current_size++;
        }
    }
    cout << maxSubArraySumCircular(arr, current_size) << endl;
    delete [] arr;
    return 0;
}

