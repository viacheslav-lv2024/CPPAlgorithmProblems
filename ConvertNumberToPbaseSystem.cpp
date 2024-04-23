#include <iostream>
#include <vector>
using namespace std;
vector<int> new_n;

string tentox(int number, int base) {
    if (base > number) {
        char n = number + '0';
        return string(1, n);
    }
    char x = number % base + '0';
    return tentox(number / base, base) + string(1, x);
}

int main() {
    int base, number10, count = 0;
    cin >> base >> number10;
    cout << number10 << "(10)" << '=' << tentox(number10, base) << '(' << base << ')';
    return 0;
}