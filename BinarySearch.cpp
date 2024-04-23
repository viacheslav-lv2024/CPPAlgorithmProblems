#include <iostream>
#include <vector>
using namespace std;

bool checker(int m, int k, vector<int>& arr) {
    return arr[m] < k;
}

int bs(int l, int r, int k, vector<int>& arr) {
    if (r - l <= 1) {
        return r;
    }

    int m = l + (r - l) / 2;
    if (checker(m, k, arr)) {
        return bs(m, r, k, arr);
    }
    else {
        return bs(l, m, k, arr);
    }
}

int main() {
    int k, n;
    cin >> k >> n;

    vector<int> arr(n + 1);
    for (int i = 1; i < n + 1; ++i) {
        cin >> arr[i];
    }

    arr[0] = arr[1] - 1;

    int ans = 0;
    if (arr[1] <= k && k <= arr[n])
        ans = bs(0, n, k, arr);

    if (arr[ans] != k)
        ans = 0;
    cout << ans;
    return 0;
}