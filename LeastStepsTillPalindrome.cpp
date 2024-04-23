/* A word is called a palindrome if it is read the same both from left to right and from right to left. 
You need to determine what is the smallest number of letters that must be added to the input word on the right 
for it to become a palindrome. */

#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

string raw;
vector<char> rev;

int main()
{
    getline(cin, raw);
    for (int i = raw.size() - 1; i >= 0; --i) {
        rev.push_back(raw[i]);
    }

    int j = raw.size() - 1;
    for (int i = 0; i <= j; ++i) {
        if (raw[i] == raw[j]) {
            bool is_ok = true;
            for (int q = i, l = 0; q <= i + (j - i + 1) / 2; ++q, ++l) {
                if (raw[q] != rev[l])
                    is_ok = false;
            }
            if (is_ok) {
                cout << i;
                break;
            }
        }
    }

    return 0;
}