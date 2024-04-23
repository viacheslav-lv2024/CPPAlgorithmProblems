/* Given a chessboard of size n×n. 
  Find the number of possible different arrangements n
  queens on this board. In this case, no two queens should “beat” each other. 
  Two formations are considered different if there is a square such that in the first formation there is a queen on it, 
  but in the second there is not. */

#include <iostream>
#include <vector>

using namespace std;
int n;
vector<int> s;
vector<int> d1;
vector<int> d2;
/*vector<int> r;
r[j] = i - el in arr[i][j] <- Queen

if (d1[i - j + n - 1]) {
  continue;
}
if (d2[i + j]) {
  continue;
}
*/
int rec(int j) {
    if (j == n) {
        return 1;
    }

    int cnt = 0;

    for (int i = 0; i < n; ++i) {
        if (s[i]) {
            continue;
        }
        if (d1[i - j + n - 1]) {
            continue;
        }
        if (d2[i + j]) {
            continue;
        }
        s[i] = 1;
        d1[i - j + n - 1] = 1;
        d2[i + j] = 1;

        cnt += rec(j + 1);

        s[i] = 0;
        d1[i - j + n - 1] = 0;
        d2[i + j] = 0;
    }

    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    s.resize(n, 0);
    d1.resize(2 * n - 1, 0);
    d2.resize(2 * n - 1, 0);

    int ans = rec(0);
    cout << ans;
    return 0;
}