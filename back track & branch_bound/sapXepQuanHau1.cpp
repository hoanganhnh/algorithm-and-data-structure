#include <iostream>

using namespace std;

int X[100], n, count = 0;
bool cot[100], cheoXuoi[100], cheoNguoc[100];

void init() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cot[i] = true;
    }

    for (int i = 1; i < 2*n; i++) {
        cheoXuoi[i] = true;
        cheoNguoc[i] = true;
    }
}

void output() {
    count++;
    for (int i = 1; i <= n; i++) {
        cout << X[i] << " ";
    }
    cout << endl;
}

void Try(int i) {
    for (int j = 1; j <= n; j++) {
        if (cot[j] && cheoXuoi[i-j+n] && cheoNguoc[i+j-1]) {
            X[i] = j;//ta đặt được quân hậu hàng i vào vột j
            cot[j] = false;
            cheoXuoi[i-j+n] = false;
            cheoNguoc[i+j-1] = false;
            if (i == n) {
                count++;
            } else {
                Try(i + 1);
            }
            cot[j] = true;
            cheoXuoi[i-j+n] = true;
            cheoNguoc[i+j-1] = true;
        }
    }
}

int main() {
    int test;
    cin >> test;
    while(test-- ) {
        init();
        Try(1);
        cout << count;
        cout << endl;
    }
}