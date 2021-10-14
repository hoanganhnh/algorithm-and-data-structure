#include <bits/stdc++.h>

using namespace std;

int n, c[20][20], x[20], check[20], s, bestConfig[20];
long long res = 1e18, cmin = 1e18;

void init() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
            if (c[i][j] < cmin && c[i][j] != 0) cmin = c[i][j];
        }
    }
}

void output() { //@note: way active
    cout << "(";
    for (int i = 1; i <= n; i++) {
        cout << bestConfig[i] << ", ";
    }
    cout << bestConfig[1]<< ")" << endl;
}

void Try(int i) {
    for (int j = 2; j <= n; j++) {
        if (!check[j]) {
            check[j] = 1;
            x[i] = j;
            s += c[x[i - 1]][j];

            if (i == n) {
                if (s + c[j][1] < res) {
                    res = s + c[j][1];
                    for (int k = 1; k <= n; k++) {
                        bestConfig[k] = x[k];
                    }
                }
            } else if (s + (n - i + 1)*cmin < res) {
                Try(i + 1);
            }

            s -= c[x[i - 1]][j];
            check[j] = 0;
        }
    }
}

int main() {
    init();
    x[1] = 1;
    Try(2);
    output();
    cout << res << endl;
}