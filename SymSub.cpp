/* Implement a binary operation on sets - symmetric difference. 
Its result is those elements of two sets that belong to exactly one of the sets (but do not belong to their intersection). */

#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    // freopen("test1.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    set<int> s1, s2;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int curr;
        cin >> curr;
        s1.insert(curr);
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int curr;
        cin >> curr;
        s2.insert(curr);
    }

    set<int> s3;

    set<int>::iterator it;
    for (it = s1.begin(); it != s1.end(); ++it) {
        if (!s2.count(*it))
            s3.insert(*it);
    }
    for (it = s2.begin(); it != s2.end(); ++it) {
        if (!s1.count(*it))
            s3.insert(*it);
    }

    cout << s3.size() << endl;
    for (it = s3.begin(); it != s3.end(); ++it) {
        cout << *it << ' ';
    }
    return 0;
}