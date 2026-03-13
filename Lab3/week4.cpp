#include <algorithm>
#include <iostream>
using namespace std;

void swapValues(int *p1, int *p2) {
  int temp = *p1;
  *p1 = *p2;
  *p2 = temp;
}

void printArray(int *arr, int size) {
  for (int a = 0; a < size; a++) {
    cout << arr[a] << " ";
  }
  cout << endl;
}

int findMax(int *arr, int size) {
  int max = arr[0];
  for (int a = 1; a < size; a++) {
    if (arr[a] > max) {
      max = arr[a];
    }
  }
  return max;
}

void reverseArray(int *arr, int size) {
  int left = 0;
  int right = size - 1;
  int temp;
  while (left < right) {
    temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;

    left += 1;
    right -= 1;
  }
}

int *createArray(int size) {
  int *arr = new int[size];
  return arr;
}

void deleteArray(int *arr) { delete[] arr; }

int main() {
  int a1 = 20;
  int a2 = 10;
  swapValues(&a1, &a2);

  int arr[10] = {1, 24, 5, 42, 325, 14, 14, 12, 4, 235};
  int size = 6;
  reverseArray(arr, size);
  printArray(arr, size);
  int maxValue = findMax(arr, size);
  cout << maxValue;
  cout << endl;

  int *arrAddress = createArray(size);
  cout << "Dynamic array created at address: " << arrAddress << endl;

  deleteArray(arrAddress);

  return 0;
}
