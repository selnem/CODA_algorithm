#include<iostream>
#include<vector>
using namespace std;
int arr[26][200001]={0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string line;
    int n;
    cin >> line;
    cin >> n;

    for(int i = 1; i <= line.size() ; i++){
        arr[line[i-1] - 'a'][i] = 1;
    }
    for(int i = 0; i < 26; i++){
        for(int j = 1; j <= line.size(); j++){
            arr[i][j] += arr[i][j - 1];
        }
    }
    for(int i = 0; i < n; i++){
        char a;
        int l,r;
        cin >> a >> l >> r;
        cout << arr[a - 'a'][r + 1] - arr[a - 'a'][l] << '\n';
    }

    return 0;
}