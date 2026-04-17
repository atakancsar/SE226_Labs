#include <iostream>
#include <cmath>
#include <regex>
using namespace std;

double series(int n, double r) {
    if (n == 0) {
        return 1.0;
    }
    
    double r_val = 1.0;
    for (int i = 0; i < n; i++) {
        r_val *= r;
    }
    
    return r_val + series(n - 1, r);
}

int main() {
    int n;
    double r;

    cout << "Enter n: ";
    cin >> n;
    
    cout << "Enter r: ";
    cin >> r;
    
    cout << series(n, r) << endl;
    
    return 0;
}
