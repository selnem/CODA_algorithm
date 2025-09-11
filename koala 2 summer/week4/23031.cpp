#include<iostream>
#include<vector>
using namespace std;

int N;
const int dx[8]={0,-1,-1,-1,0,1,1,1};
const int dy[8]={1,1,0,-1,-1,-1,0,1};
char safeZone[16][16]={0};
bool inRange(int r,int c);
void turnOn(int r,int c);
class Zom{
    private:
        int x,y;
        int dir=0;
    public:
        Zom(int r,int c){
            x=c;
            y=r;
        }
        void move(){
            int nx=x+dx[dir],ny=y+dy[dir];
            if(inRange(ny,nx)){
                x=nx,y=ny;
            }
            else{
                dir=(dir+4)%8;
            }
        }
        pair<int,int> getLocation(){
            return make_pair(x,y);
        }
};

vector<Zom> zombis;

class Ahri{
    private:
        int x=1,y=1;
        int dir=0;
        bool isSafe=true;
        void zomMove();
        bool withZom(int x,int y);
    public:
        bool move(string &cmd);
};

    
int main(){
    const char *ans[2]={"Phew...","Aaaaaah!"};
    string cmd;
    cin>>N;
    cin>>cmd;
    char tmp;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>tmp;
            if(tmp=='S') safeZone[i][j]=tmp;
            else if(tmp=='Z') zombis.push_back(Zom(i,j));
        }
    }
    Ahri ahri;
    cout<<ans[ahri.move(cmd)];

}
bool Ahri::move(string &cmd){
    int nx;
    int ny;   
    for(char it:cmd){
        switch(it){
            case 'F':
                nx=x+dx[dir];
                ny=y+dy[dir];
                if (inRange(ny,nx)) x=nx,y=ny;
                if (safeZone[y][x]){
                    if(safeZone[y][x]=='S'){
                        turnOn(y,x);
                    } 
                    break;
                } 
                if (withZom(x,y)) return true;
                break;
            case 'L':
                dir=(dir+6)%8;
                break;
            case 'R':
                dir=(dir+2)%8;
                break;
        }
        zomMove();
        if(safeZone[y][x]) continue;
        if(withZom(x,y)) return true;
    }
    return false;
}

void Ahri::zomMove(){
    for(auto &it:zombis){
        it.move();
    }
}
bool Ahri::withZom(int x,int y){
    bool isWith=false;
    for(auto &it:zombis){
        if(make_pair(x,y)==it.getLocation()){
            return true;
        }
    }
    return false;
}
void turnOn(int r,int c){
    for(int i=0;i<8;i++){
        int nr=r+dy[i];
        int nc=c+dx[i];
        if(!inRange(nr,nc)||safeZone[nr][nc]=='S') continue;
        
        safeZone[nr][nc]='s';
    }
}

bool inRange(int r,int c){
    return 1<=r&&r<=N&&1<=c&&c<=N;
}
