/* Based on the entered values n, m
  (1 ≤ n ≤ 20, 1 ≤ m ≤ 20) fill an array of dimension n × m numbers from 1 to mn,
  arranging them in a horizontal “snake”. */

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int arr[20][20];

int main()
{
    int n, m;
    cin >> n >> m;

    int counter = 0;
    while (counter < n * m) {
        int i = (counter / m);
        if (i % 2) {
            int j = m - 1;
            while (j >= 0)
                arr[i][j--] = 1 + counter++;
        }
        else {
            int j = 0;
            while (j < m)
                arr[i][j++] = 1 + counter++;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cout << arr[i][j] << ' ';
        cout << endl;
    }

    return 0;
}