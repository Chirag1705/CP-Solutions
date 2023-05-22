#include<bits/stdc++.h>
using namespace std;

int cnt = 0;

int rpart(vector<int>&arr, int low, int high) {
    int tmp = rand() % (high - low + 1) + low;
    // cout << tmp << " ";
    swap(arr[tmp], arr[low]);
    int pi_ele = arr[low];
    int var = low;

    for (int j = low + 1; j <= high; j++) {
        cnt++;
        if (arr[j] < pi_ele) {
            var++;
            swap(arr[var], arr[j]);
        }
    }

    swap(arr[var], arr[low]);
    return (var);
}

void quicksort(vector<int>&arr, int low, int high) {

    if (low < high) {
        int pivot = rpart(arr, low, high);

        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }

}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    vector<int>arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int low = 0;
    int high = n - 1;

    quicksort(arr, low, high);

    for (auto i : arr) {
        cout << i << " ";
    }

    cout << "\n";
    cout << cnt << "\n";

    return 0;
}