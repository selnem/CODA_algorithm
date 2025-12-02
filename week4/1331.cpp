#include<iostream>
#include<string>
using namespace std;

const int dx[]={2,2,-2,-2,1,1,-1,-1};
const int dy[]={1,-1,1,-1,2,-2,2,-2};

bool visBord[7][7]={0};
string lastChar;
string firstChar;

inline bool inRange(const string &a);
bool isValid(const string &befor,const string &after);
int main(){
    string tmp;
    cin>>tmp;
    firstChar=tmp;
    lastChar=tmp;
    visBord[tmp[0]-'A'][tmp[1]-'1'] = true;
    for(int i=0;i<35;i++){
        cin>>tmp;
        if(!isValid(lastChar,tmp)){
            cout << "Invalid";
            return 0;
        }
        lastChar=tmp;
    }
    int dx = abs(lastChar[0] - firstChar[0]);
    int dy = abs(lastChar[1] - firstChar[1]);
    if ((dx == 2 && dy == 1) || (dx == 1 && dy == 2))
        cout << "Valid";
    else
        cout << "Invalid";

    return 0; 
}
inline bool inRange(const string &a){
    return 'A'<=a[0]&&a[0]<='F'&&'1'<=a[1]&&a[1]<='6';
}
bool isValid(const string &befor,const string &after){
    for(int i=0;i<8;i++){
        char nx=befor[0]+dx[i];
        char ny=befor[1]+dy[i];
        string nStr;
        nStr.push_back(nx);
        nStr.push_back(ny);
        if(!inRange(nStr)) continue;
        if(nx==after[0]&&ny==after[1]){
            if(visBord[nx-'A'][ny-'1']) return false;
            else{
                visBord[nx-'A'][ny-'1']=true;
                return true;
            }
        }
    }
    return false;
}
