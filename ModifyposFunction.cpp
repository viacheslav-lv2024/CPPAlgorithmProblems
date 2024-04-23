/* Write a modification of the pos function that finds all occurrences of the desired substring in a given string. 
The first line contains the original string, the next line contains the substring. 
As an answer, print in ascending order all such numbers i, that starting from ith character, 
some occurrence of the substring in the original string begins. */

#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

void pos(string& origin, string& dist) {
    bool is_any = false;

    for (int i = 0; i < origin.size(); ++i) {
        if (origin[i] == dist[0]) {
            bool is_in = true;

            for (int j = 0; j < dist.size(); ++j)
                if (dist[j] != origin[i + j])
                    is_in = false;

            if (is_in) {
                is_any = true;
                cout << i + 1 << ' ';
            }
        }
    }

    if (!is_any)
        cout << 0;

    return;
}

int main()
{
    string origin, dist;
    cin >> origin >> dist;

    pos(origin, dist);

    return 0;
}