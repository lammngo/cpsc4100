//
// Created by lolita kim on 10/4/22.
//
#include <iostream>
#include <algorithm>

using namespace std;

int max_capital_gain(int arr[], int first, int last){
    //base case
    if (last - first <= 1)
        return 0;
    //combine two sub-arrays
    int mid = first + (last - first)/2;
    int capital_max = max(max_capital_gain(arr, first, mid), max_capital_gain(arr, mid, last));
    int minVal = arr[0];
    int maxVal = arr[mid];
    for(int i = first; i < mid; i++){
        minVal = min(arr[i], minVal);
    }
    for(int j = mid; j < last; j++){
        maxVal = max(arr[j], maxVal);
    }
    return max(capital_max, (maxVal - minVal));
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
    cout << max_capital_gain(arr, 0, current_size) << endl;
    delete [] arr;
    return 0;
}
