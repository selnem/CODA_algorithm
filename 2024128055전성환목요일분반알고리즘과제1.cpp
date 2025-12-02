#include<iostream>
#include<vector>
using namespace std;

//오른쪽 또는 위로 음직임
const int dx[2]={1,0};
const int dy[2]={0,1};

vector<vector<bool>> mapp(5,vector<bool>(5,false)); // 장애물 맵

int DP[5][5]={0}; // 메모라이즈 배열

inline bool inRange(int x,int y); // 범위 벗어나는지 확인

int DP_DFS(int x,int y); // TopDown 방식으로 경로탐색

int main(){
    int x,y; //장애물 좌표 선언
    for(int i=0;i<2;i++){
        cin>>x>>y;
        mapp[y][x]=true; //맵에 장매물 기록
    }
    cout<<DP_DFS(0,0);//0,0에서 시작
    return 0;
}

int DP_DFS(int x,int y){
    if(x==4&&y==4){ //4,4도착시 성공1
        return 1;
    }
    if(!inRange(x,y)){ // 범위벗어나면 재귀탈출
        return 0;
    }
    if(mapp[y][x]){ //만약 장애믈 만났을시 탈출
        return 0;
    }

    int &dp=DP[y][x];

    if(dp){//계산(방문)한적 있다면 
        return dp;
    }
    for(int i=0;i<2;i++){ //자신의 오른쪽 그리고 위방향의 경우의 수 더함
        dp+=DP_DFS(x+dx[i],y+dy[i]);
    }
    return dp;

}
inline bool inRange(int x,int y){//배열 범위 체크 
    return 0<=x&&x<5&&0<=y&&y<5;
}