#include<iostream>
using namespace std;


class Hong{
    private:
        int x_pos=50;
        int y_pos=50;
        int dir=0;
        const int dx[4]={0,-1,0,1};
        const int dy[4]={1,0,-1,0};
        int min_x=50;
        int min_y=50;
        int max_x=50;
        int max_y=50;
        bool mapp[101][101]={0};
        char makker[2]={'#','.'};
    public:
        Hong(){
            mapp[y_pos][x_pos]=true;
        }
       void move(char c);
       void map_prn(); 
};
void Hong::move(char c){
    switch(c){
        case 'R':
            dir=(dir+1)%4;
            break;
        case 'L':
            dir=(dir+3)%4;
            break;
        case 'F':
            x_pos+=dx[dir];
            y_pos+=dy[dir];
            mapp[y_pos][x_pos]=true;
            min_x=min(min_x,x_pos);
            min_y=min(min_y,y_pos);
            max_x=max(max_x,x_pos);
            max_y=max(max_y,y_pos);
            break;
    }
}
void Hong::map_prn(){
    for(int i=min_y;i<=max_y;i++){
        for(int j=min_x;j<=max_x;j++){
            cout<<makker[mapp[i][j]];
        }
        cout<<'\n';
    }
}
int main(){
    int n;
    char cmd;
    Hong hong;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>cmd;
        hong.move(cmd);
    }
    hong.map_prn();
    return 0;
}