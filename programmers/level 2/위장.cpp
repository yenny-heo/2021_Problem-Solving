//해시, 경우의 수
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map <string, vector<string>> m;
    for(int i=0; i<clothes.size(); i++){
        string name = clothes[i][0];
        string kind = clothes[i][1];
        
        if(m.find(kind) == m.end()){
            m[kind] = vector<string> {name};
        }
        else m[kind].push_back(name);
    }
    for(auto i=m.begin(); i!=m.end(); i++){
        answer *= i->second.size() + 1;
    }
    answer -= 1;
    return answer;
}