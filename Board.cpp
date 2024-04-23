/* The first line of the input contains n
  — number of lines and m
  — the number of columns in a two-dimensional array. In subsequent n
  written on m lines
  numbers, each of which is either 0 or 1. The numbers are separated by spaces. 
  You need to display the number of objects consisting of ones. 
  If two ones are vertically or horizontally neighbors, then they belong to the same object. */

#include <iostream>
#include <vector>
using namespace std;

vector< vector<int> > arr;
vector< vector<bool> > used;
/*
4 7
1 0 1 1 1 0 1
1 0 0 1 0 1 1
1 1 0 1 0 0 1
0 1 1 0 1 1 1
*/

void dfs(int i, int j) {
    if (arr[i][j] == 0)
        return;

    used[i][j] = true;

    if (i > 0 && !used[i - 1][j]) {
        dfs(i - 1, j);
    }
    if (i < used.size() - 1 && !used[i + 1][j]) {
        dfs(i + 1, j);
    }
    if (j > 0 && !used[i][j - 1]) {
        dfs(i, j - 1);
    }
    if (j < used[i].size() - 1 && !used[i][j + 1]) {
        dfs(i, j + 1);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    arr.resize(n, vector<int>(m));
    used.resize(n, vector<bool>(m, false));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (arr[i][j] != 0 && !used[i][j]) {
                ++ans;
                dfs(i, j);
            }
        }
    }
    cout << ans;
    return 0;
}