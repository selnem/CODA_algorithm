#include<iostream>

using namespace std;

bool station[101]={0};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N,M;
    const char*ans[2]={"Local","Express"};
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int tmp;
        cin>>tmp;
        station[tmp]=true;
    }
    int S,E;
    cin>>S>>E;
    cout<<ans[(station[S]&&station[E])];

    return 0;
}