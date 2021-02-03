#include <string>
#include <vector>
#include <queue>
#include <map>
#include <utility>

using namespace std;

bool check(string a, string b){
    int diff = 0;
    for(int i=0; i<a.length(); i++){
        if(a[i] != b[i]){
            diff++;
        }
    }
    if(diff == 1) return 1;
    else return 0;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    map<string, int> m;
    for(int i=0; i<words.size(); i++){
        m.insert({words[i], 0});
    }
    queue<pair<string, int>> q;
    q.push({begin, 0});
    m[begin] = 1;
    while(!q.empty()){
        string cur = q.front().first;
        int dist = q.front().second;
        q.pop();
        if(cur == target){
            answer = dist;
            break;
        }
        for(auto i=m.begin(); i!=m.end(); i++){
            string nxt = i->first;
            bool chk = check(cur, nxt);
            if(chk && i->second == 0){
                q.push({nxt, dist+1});
                m[nxt] = 1;
            }
        }
    }
    if(answer == 0) return 0;
    return answer;
}