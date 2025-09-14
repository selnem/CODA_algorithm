#include<iostream>
#include<map>
#include<vector>
using namespace std;
vector<int> arr;
map<int,int> mp;

bool first_cmd();
void second_cmd();
void ans();
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N,Q;
    cin>>N>>Q;
    int tmp;
    arr.push_back(0);
    while(N--){
        cin>>tmp;
        arr.push_back(tmp);
        mp[tmp]++;
    }
    while(Q--){
        ans();
    }
    return 0;
}

bool first_cmd(){
    int num;
    cin>>num;
    if(arr.size()==2) return false;
    if(num==0){
        return mp[0]>0;
    }
    for(auto &[val,cnt]:mp){
        if(val==0) continue;
        if(num%val) continue;
        int divN=num/val;
        if(divN==val){
            if(cnt>=2) return true;
            else continue;
        }
        else if(mp.find(divN)!=mp.end()) return true;
    }
    return false;
}

void second_cmd(){
    int idx;
    cin>>idx;
    mp[arr[idx]]--;
    if(mp[arr[idx]]==0) mp.erase(arr[idx]);
    arr[idx]=0;
    mp[0]++;
}

void ans(){
    int qNum;
    cin>>qNum;
    switch(qNum){
        case 1:
            cout<<(int)first_cmd()<<'\n';
            break;
        case 2:
            second_cmd();
            break;
        default:
            cout<<"error"<<'\n';
            break;
    }
}