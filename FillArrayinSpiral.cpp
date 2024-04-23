/* Based on the entered values n, m
  (1 ≤ n ≤ 20, 1 ≤ m ≤ 20) fill an array of dimension n × m numbers from 1 to mn, 
  arranging them in a clockwise spiral. */

#include <iostream>

using namespace std;

int arr[20][20];

int main()
{
    int n, m;
    cin >> n >> m;

    int counter = 1;
    int i = 0, j = 0;
    while (counter <= m * n) {
        for (; j < m && arr[i][j] == 0; ++j)
            arr[i][j] = counter++;
        --j;
        ++i;
        for (; i < n && arr[i][j] == 0; ++i)
            arr[i][j] = counter++;
        --i;
        --j;
        for (; j >= 0 && arr[i][j] == 0; --j)
            arr[i][j] = counter++;
        ++j;
        --i;
        for (; i >= 0 && arr[i][j] == 0; --i)
            arr[i][j] = counter++;
        ++i;
        ++j;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (arr[i][j] < 10)
                cout << ' ';
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}