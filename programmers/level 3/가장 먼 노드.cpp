//BFS
#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<int> connect[20001];
    bool visit[20001] = {0};
    int dist[20001];
    for(int i=0; i<edge.size(); i++){
        connect[edge[i][0]].push_back(edge[i][1]);
        connect[edge[i][1]].push_back(edge[i][0]);
    }
    int max_dist = 0;
    queue<pair<int, int>> q;
    visit[1] = 1;
    q.push({1, 0});
    dist[1] = 0;
    while(!q.empty()){
        int cur = q.front().first;
        int d = q.front().second;
        if(max_dist < d) max_dist = d;
        q.pop();
        for(int i=0; i<connect[cur].size(); i++){
            int nxt = connect[cur][i];
            if(visit[nxt] == 0){
                visit[nxt] = 1;
                q.push({nxt, d + 1});
                dist[nxt] = d + 1;
            }
        }
    }
    
    for(int i=1; i<=n; i++){
        if(max_dist == dist[i]){
            answer++;
        }
    }
    
    return answer;
}