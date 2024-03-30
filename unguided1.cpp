#include <iostream>
using namespace std;

void selection_sort(double arr[], int length) {
    int i, j, minIndex;
    double temp;
    for (i = 0; i < length - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < length; j++) {
            if (arr[j] > arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

void print_array(double a[], int length) {
    for(int i = 0; i < length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main() {
    int length = 10;
    double a[] = {3.8, 2.9, 3.3, 4.0, 2.4, 3.6, 4.9, 4.6, 5.5, 5.6};
    cout << "IPS sebelum sorting: " << endl;
    print_array(a, length);
    selection_sort(a, length);
    cout << "\nIPS setelah sorting: " << endl;
    print_array(a, length);
    return 0;
}
