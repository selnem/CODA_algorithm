#include<iostream>
#include<vector>
using namespace std;
const int dx[10]={0,-1,0,1,-1,0,1,-1,0,1};
const int dy[10]={0,1,1,1,0,0,0,-1,-1,-1};
int R,C;
pair<int,int> jongSu;
int cnt=0;

bool in_range(int i,int j);
bool jongSuMove(int dir,vector<pair<int,int> > &robots);
bool robotMove(vector<pair<int,int> > &robots);
void make_map(vector<pair<int,int> > &robots);
void loseprn();
int main(){
    vector<pair<int,int> >Robots;
    string cmds;
    char tmp;
    cin>>R>>C;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>tmp;
            if(tmp=='R'){
                Robots.push_back(make_pair(i,j));
            }
            else if(tmp=='I'){
                jongSu.first=i;
                jongSu.second=j;
            }
        }
    }
    cin>>cmds;
    for(auto c:cmds){
        if(jongSuMove(c-'0',Robots)){
            loseprn();
            return 0;
        }
    }
    make_map(Robots);
    return 0;

}   

bool in_range(int i, int j){
    return 0<=i&&i<R&&0<=j&&j<C;
}
bool robotMove(vector<pair<int,int> > &robots){
    vector<vector<int> > nextMap(R,vector<int>(C,0));
    vector<pair<int,int> >nextRobots;
    for(auto &k:robots){
        int r=k.first;
        int c=k.second;
        for(int i=9;i>=1;i--){
            int dr=k.first+dy[i];
            int dc=k.second+dx[i];
            if(i==5){
                continue;
            }
            if(!in_range(dr,dc)){
                continue;
            }
            if(jongSu.first==dr&&jongSu.second==dc){
                return true;
            }
            if((abs(jongSu.first-r)+abs(jongSu.second-c))>=(abs(jongSu.first-dr)+abs(jongSu.second-dc))){
                r=dr;
                c=dc;
            }
        }
        nextMap[r][c]++;
    }
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(nextMap[i][j]==1){
                nextRobots.push_back(make_pair(i,j));
            }
        }
    }
    robots.clear();
    robots=nextRobots;
    return false;
}
bool jongSuMove(int dir,vector<pair<int,int> > &robots){
    cnt++;
    jongSu.first+=dy[dir];
    jongSu.second+=dx[dir];
    for(auto &r : robots){
        if(jongSu.first == r.first && jongSu.second == r.second)
            return true;
    }
    if(robotMove(robots)){
        return true;
    }
    return false;
    
}
void make_map(vector<pair<int,int> > &robots){
    vector< vector<char> > tmp_map(R,vector<char>(C,'.'));
    for(auto k:robots){
        tmp_map[k.first][k.second]='R';
    }
    tmp_map[jongSu.first][jongSu.second]='I';
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cout<<tmp_map[i][j];
        }
        cout<<'\n';
    }
}
void loseprn(){
    cout<<"kraj "<<cnt;
}