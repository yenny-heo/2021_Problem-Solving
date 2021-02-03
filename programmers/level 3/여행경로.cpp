//DFS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> answer;
bool result_flag = 0;

void DFS(string cur, vector<string> ans, vector<bool> visit, vector<vector<string>> tickets){
    ans.push_back(cur);
    for(int i=0; i<tickets.size(); i++){
        if(tickets[i][0] == cur && visit[i] == 0){
            string nxt = tickets[i][1];
            visit[i] = 1;
            DFS(nxt, ans, visit, tickets);
            visit[i] = 0;
        }
    }
    bool flag = 0;
    if(!result_flag){
        for(int i=0; i<visit.size(); i++){
            if(!visit[i]){
                flag = 1;
                break;
            }
        }
        if(!flag){
            result_flag = 1;
            answer = ans;
            return;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<bool> visit;
    for(int i=0; i<tickets.size(); i++){
        visit.push_back(false);
    }
    
    sort(tickets.begin(), tickets.end());
    
    vector<string> a;
    DFS("ICN", a, visit, tickets);
    
    return answer;
}
