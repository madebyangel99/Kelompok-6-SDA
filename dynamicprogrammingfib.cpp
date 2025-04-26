#include <iostream>
#include <vector>

using namespace std;

int deretfibonacci(int n) {
    vector<int> fib(n + 1, 0);
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib[n];
}

int main() {
    int n;
    cout << "Masukkan posisi (n) untuk menemukan angka Fibonacci (berdasarkan indeks): ";
    cin >> n;

    cout << "Fibonacci("<< n <<") = " << deretfibonacci(n) << endl;

    return 0;
}





