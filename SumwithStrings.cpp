/* Given two "long" non-negative integers. You need to find the result of their addition. 
Use strings as the data type for storing numbers.*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> ans;

int main() {
    string first, second;
    cin >> first >> second;
    int summ;

    reverse(first.begin(), first.end());
    reverse(second.begin(), second.end());

    int ovrflw = 0;
    for (int i = 0; i < max(first.size(), second.size()); ++i) {
        int a = 0, b = 0;
        if (i < first.size())
            a = first[i] - '0';
        if (i < second.size())
            b = second[i] - '0';

        int res = a + b + ovrflw;
        if (res >= 10) {
            ovrflw = 1;
            res -= 10;
        }
        else {
            ovrflw = 0;
        }
        ans.push_back(res);
    }

    if (ovrflw)
        ans.push_back(ovrflw);

    reverse(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i];

    return 0;
}