#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    int q = s / n;
    int r = s % n;
    if(q == 0){
        answer.push_back(-1);
        return answer;
    }
    
    for(int i=0; i<n; i++){
        answer.push_back(q);
    }
    for(int i=0; i<r; i++){
        answer[i]++;
    }
    sort(answer.begin(), answer.end());
    return answer;
}