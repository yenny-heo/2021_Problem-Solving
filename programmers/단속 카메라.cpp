//Greedy Algorithm
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end());
    int start = routes[0][0];
    int end = routes[0][1];
    answer++;
    for(int i=1; i<routes.size(); i++){
        if(start < routes[i][0]){
            start = routes[i][0];
        }
        if(end > routes[i][1]){
            end = routes[i][1];
        }
        //겹치는 부분이 없는 경우
        if(end < routes[i][0]){
            end = routes[i][1];
            answer++;
        }
    }
    return answer;
}