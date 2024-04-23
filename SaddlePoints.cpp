/* In a two-dimensional array of dimension n × m, 
   all elements of which are different, 
   you need to find those elements that are both minimal in their row and maximal in their column. */

#include <iostream>

using namespace std;

int arr[101][101];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    for (int k = 0; k < n; ++k) {
        int mn = arr[k][0];
        for (int j = 1; j < m; j++) {
            if (arr[k][j] < mn) {
                mn = arr[k][j];
            }
        }
        arr[k][m] = mn;
    }
    for (int k = 0; k < m; ++k) {
        int mx = arr[0][k];
        for (int i = 1; i < n; i++) {
            if (arr[i][k] > mx) {
                mx = arr[i][k];
            }
        }
        arr[n][k] = mx;
    }

    bool is_any = false;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (arr[i][j] == arr[i][m] && arr[i][j] == arr[n][j]) {
                cout << i + 1 << ' ' << j + 1 << endl;
                is_any = true;
            }
        }
    }

    if (!is_any)
        cout << 0;

    return 0;
}