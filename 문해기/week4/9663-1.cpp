#include<iostream>
using namespace std;

int bord[16]={0};
int ans = 0;
int n;

void n_queen(int cnt);
inline bool check(int cnt);
int main(){
    cin>>n;
    n_queen(0);
    cout<<ans;

}
void n_queen(int cnt){
    if(cnt == n){
        ++ans;
        return;
    }
    for(int i=0;i<n;i++){
        bord[cnt]=i;
        if(check(cnt)) n_queen(cnt+1);
    }
}
inline bool check(int cnt){
    for(int i=0;i<cnt;i++){
        if(bord[cnt]==bord[i]||abs(bord[i]-bord[cnt])==(cnt-i)) return false;
    }
    return true;
}