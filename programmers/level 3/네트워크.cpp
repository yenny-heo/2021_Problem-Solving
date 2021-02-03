#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

bool visit[201];

int find(int n){
    for(int i=0; i<n; i++){
       if(visit[i] == 0){
           return i;
       }
    }
    return -1;
}

void bfs(int start, int n, vector<vector<int>> computers){
    queue<int> q;
    q.push(start);
    visit[start] = 1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i=0; i<computers[cur].size(); i++){
            if(computers[cur][i] == 1){//가는 길이 있는 경우
                int nxt = i;
                if(visit[nxt] == 0){
                    visit[nxt] = 1;
                    q.push(nxt);
                }
            }
        }
    }
    
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    while(1){
        int start = find(n);
        if(start == -1) break;
        bfs(start, n, computers);
        answer++;
    }
    
    return answer;
}