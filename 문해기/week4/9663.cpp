#include<iostream>
using namespace std;
int ans=0;
void N_Queen(int n,int *bord,int cnt=0);
bool can_place(int *bord,int n);
int main(){
    int n;
    cin>>n;
    int *c_bord=new int [n];
    N_Queen(n,c_bord);
    cout<<ans;
    delete[] c_bord;
    return 0;
}

void N_Queen(int n,int *bord,int cnt){
    if(cnt==n){
        ++ans;
        return;
    }
    for(int i=0;i<n;i++){
        bord[cnt]=i;
        if(can_place(bord,cnt)){
            N_Queen(n,bord,cnt+1);
        }
    }
    return;
}
bool can_place(int *bord,int n){
    for(int i=0;i<n;i++){
        if(bord[i]==bord[n]||abs(bord[n]-bord[i])==(n-i)){
            return false;
        }
    }
    return true;
}