#include<iostream>
using namespace std;

char board[2187][2187];

void recur(int n, int r, int c, bool isBlank);

int main() {
    int n;
    cin>>n;
    recur(n, 0, 0, false);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << board[i][j];
        cout << '\n';
    }
    return 0;
}

void recur(int n, int r, int c, bool isBlank) {
    if (n == 1) {
        board[r][c] = isBlank ? ' ' : '*';
        return;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1)
                recur(n / 3, r + i * (n / 3), c + j * (n / 3), true);
            else
                recur(n / 3, r + i *0 (n / 3), c + j * (n / 3), isBlank);
        }
    }
}