#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

#define INF 9999999

int dist[201][201];

void floydWarshall(int n){
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                    dist[j][i] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    //초기화
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i == j){
                dist[i][j] = 0;
            }
            else{
                dist[i][j] = INF;
            }
        }
    }
    
    for(int i=0; i<fares.size(); i++){
        dist[fares[i][0]][fares[i][1]] = fares[i][2];
        dist[fares[i][1]][fares[i][0]] = fares[i][2];
    }
    
    floydWarshall(n);
    
    for(int i=1; i<=n; i++){
        //i: A와 B가 합승을 끝내는 지점
        if(dist[s][i] + dist[i][a] + dist[i][b] < answer){
            answer = dist[s][i] + dist[i][a] + dist[i][b];
        }
    }
    return answer;
}