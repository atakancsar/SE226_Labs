#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // Task 1
    int num;
    cout << "Please enter a positive integer greater than 9: ";
    cin >> num;
    int step = 0;
    
    cout << num;
    while (num >= 10) {
        int temp_sum = 0;
        int temp_num = num;
        while (temp_num > 0) {
            temp_sum += temp_num % 10;
            temp_num /= 10;
        }
        num = temp_sum;
        cout << " -> " << num;
        step++;
    }
    cout << "\nFinal value: " << num << "\n";
    cout << "Total steps: " << step << "\n";
    
    // Task 2
    int n;
    cout << "Please enter a number between 10 and 100: ";
    cin >> n;
    while (n < 10 || n > 100) {
        cout << "Invalid input. Please enter a number between 10 and 100: ";
        cin >> n;
    }
    
    int fizz_count = 0, buzz_count = 0, fizzbuzz_count = 0;
    
    for (int i = 1; i <= n; i++) {
        if (i % 7 == 0) {
            cout << "(" << i << " is skipped)\n";
            continue;
        }
        
        if (i % 15 == 0) {
            cout << "FizzBuzz\n";
            fizzbuzz_count++;
        } else if (i % 3 == 0) {
            cout << "Fizz\n";
            fizz_count++;
        } else if (i % 5 == 0) {
            cout << "Buzz\n";
            buzz_count++;
        } else {
            cout << i << "\n";
        }
    }
    
    cout << "--- Summary ---\n";
    cout << "Fizz count : " << fizz_count << "\n";
    cout << "Buzz count : " << buzz_count << "\n";
    cout << "FizzBuzz count: " << fizzbuzz_count << "\n";
    
    // Task 3
    int n3;
    cout << "Please enter a number between 3 and 9: ";
    cin >> n3;
    
    for (int i = 1; i < 2 * n3; i++) {
        int k = n3 - abs(n3 - i);
        for (int j = 1; j <= k; j++) {
            cout << j;
        }
        cout << "\n";
    }
    
    return 0;
}