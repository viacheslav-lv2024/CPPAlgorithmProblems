/* Given a line that is a paragraph in the text. 
The text must be formatted so that the length of each line does not exceed the number m,
do not break the words.*/

#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

vector<char> word;

int main()
{
    int n;
    cin >> n;

    char curr;
    scanf("%c", &curr);

    int cnt_str = 0;

    while (scanf("%c", &curr)) {
        if (curr == ' ' || curr == '\n') {
            if (cnt_str == 0) {
                for (int i = 0; i < word.size(); ++i)
                    cout << word[i];

                cnt_str += word.size();
            }
            else if (cnt_str + 1 + word.size() <= n) {
                cout << ' ';
                for (int i = 0; i < word.size(); ++i)
                    cout << word[i];

                cnt_str += 1 + word.size();
            }
            else {
                cout << '\n';
                for (int i = 0; i < word.size(); ++i)
                    cout << word[i];

                cnt_str = word.size();
            }

            while (!word.empty())
                word.pop_back();

            if (curr == '\n')
                break;
        }
        else {
            word.push_back(curr);
        }
    }

    return 0;
}