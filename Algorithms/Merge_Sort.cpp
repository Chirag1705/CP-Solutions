#include<bits/stdc++.h>
using namespace std;

int cnt = 0;
void merge(vector<int>&arr, int mid, int low, int high) {
    int var1 = mid - low + 1;
    int var2 = high - mid;

    vector<int>arr1(var1), arr2(var2);

    for (int i = 0; i < var1; i++) {
        arr1[i] = arr[low + i];
    }
    sort(arr1.begin(), arr1.end());
    for (int i = 0; i < var2; i++) {
        arr2[i] = arr[mid + 1 + i];
    }
    sort(arr2.begin(), arr2.end());
    int i = 0, j = 0, k = low;

    while (i < var1 and j < var2) {
        if (arr1[i] <= arr2[j]) {
            arr[k] = arr1[i];
            i++;
        }
        else {
            cnt += (var1-i);
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < var1) {
        arr[k] = arr1[i];
        i++;
        k++;
    }

    while (j < var2) {
        arr[k] = arr2[j];
        j++;
        k++;
    }
}

void mergesort(vector<int>&arr, int low, int high) {
    if (low < high) {

        int mid = low + (high - low) / 2;

        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);

        merge(arr, mid, low, high);
    }
}

int main() {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    int n;
    cin >> n;

    vector<int>arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    mergesort(arr, 0, n - 1);

    for (auto i : arr) {
        cout << i << " ";
    }
    cout << "\n";
    cout << cnt;
    return 0;
}