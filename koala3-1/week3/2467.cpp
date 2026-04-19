#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    vector<int> arr;
    cin >> n;
    for(int i = 0; i < n; i++){
        int tmp;
        cin>>tmp;
        arr.push_back(tmp);
    }
    int s = 0 , e = n - 1;
    int min_s = -1, min_e = -1;
    int diff = INT_MAX;

    while(s < e){
        int sum = arr[s] + arr[e];
        if(sum == 0){
            cout << arr[s] << ' ' << arr[e];
            return 0;
        }
        if(abs(sum)<diff){
            diff = abs(sum);
            min_s = s;
            min_e = e;
        }
        if(sum < 0){
            s++;
        } else {
            e--;
        }
    }
    
    cout << arr[min_s] << ' ' << arr[min_e];
    return 0;


}