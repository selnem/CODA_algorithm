#include<iostream>
#include<stack>
using namespace std;

typedef pair<int,int> PP;

int main(){ 
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int ans=0;
    int n;
    cin>>n;
    stack<PP> st;
    for(int i=0; i<n;i++){
        int check,a,t;
        cin>>check;
        if(check) {
            cin>> a>>t;
            st.push({a,t});
        }
        if(st.empty()) continue;
        PP &tmp=st.top();
        tmp.second--;
        if(tmp.second==0){
            ans+=tmp.first;
            st.pop();
        } 
    }
    cout<<ans;

    return 0;
}