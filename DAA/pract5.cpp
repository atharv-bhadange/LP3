#include <bits/stdc++.h>
#include <iostream>

using namespace std;
using namespace std::chrono;

int partition(vector<int>& arr, int low, int high) {
    int i = low-1;

    int pivot = arr[high];

    for(int j=low; j<high; j++) {
        if(arr[j] <= pivot)
        {
            i++;
            swap(arr[j], arr[i]);
        }
    }

    swap(arr[i+1], arr[high]);

    return i+1;
}

void deterSort(vector<int>& arr, int low, int high) {
    if(low < high) {
        int p = partition(arr, low, high);

        deterSort(arr, low, p-1);
        deterSort(arr, p+1, high);
    }
}

int randPartition(vector<int>& arr, int low, int high) {
    int p = low + rand() % (high-low+1);
    swap(arr[high], arr[p]);

    return partition(arr, low, high);
}

void randSort(vector<int>& arr, int low, int high) {
    if(low < high) {
        int p = randPartition(arr, low, high);

        randSort(arr, low, p-1);
        randSort(arr, p+1, high);
    }
}

void analyzeTime(void (*sortFun)(vector<int>&, int, int), vector<int>& arr) {
    auto start = high_resolution_clock::now();

    sortFun(arr, 0, arr.size()-1);

    auto end = high_resolution_clock::now();

    auto diff = duration_cast<nanoseconds>(end - start);

    cout<<diff.count()<<endl;
}

int main() {
    int size = 10;
    vector<int> arr(size);

    for(int i=0; i<size; i++) {
        arr[i] = rand() % 200;
        cout<<arr[i]<<" ";
    }

    cout<<endl;

    vector<int> arr2 = arr;

    analyzeTime(deterSort, arr);

    for(int i=0; i<size; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    analyzeTime(randSort, arr2);

    for(int i=0; i<size; i++) {
        cout<<arr2[i]<<" ";
    }
}
