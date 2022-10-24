#include <iostream>
#include <algorithm>

using namespace std;

long long capital_gain_counter(int arr[], int first, int last){
    //base case
    if (last - first <= 1)
        return 0;
    //assume solutions for two sub-arrays
    int mid = first + (last - first) / 2;
    long long count = capital_gain_counter(arr, first, mid) + capital_gain_counter(arr, mid, last);
    //how to combine?
    for (int i = first, j = mid; i < mid; i++){ // stop the loop of the first half
        while(arr[i] >= arr[j] && j < last){ // stop the loop for the second half
            j++;
        }
        count += (last - j);
    }
    //sorting sub-arrays
    inplace_merge(arr + first, arr + mid, arr + last);
    return count;
}

// first half: [first, mid) [0-3)
//[100, 7, 19, 34, 1000, 45, 78] mid = 3
// [7, 19, 100]  <  [34, 45, 78, 1000]
// i(2) = 100
// first half < mid

int main(){
    int cap = 0; //how many elements that u can store
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
    cout << capital_gain_counter(arr, 0, current_size) << endl;
    delete [] arr;
    return 0;
}


