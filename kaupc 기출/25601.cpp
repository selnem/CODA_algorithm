#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;
map< string,vector<string> > Tre;
int N;
bool canCasting(const string & parent,const string &child);
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    for(int i=0;i<N-1;i++){
        string parent;
        string child;
        cin>>child>>parent;
        Tre[parent].push_back(child);
    }
    string A,B;
    cin>>A>>B;
    cout<<(int)(canCasting(A,B)||canCasting(B,A));
    return 0;
}
bool canCasting(const string & parent,const string &child){
    if (parent==child) return true;
    bool isChild=false;
    for(auto &iter:Tre[parent]){
        isChild=isChild||canCasting(iter,child);
        if (isChild) return true;
    }
    return isChild;
}
