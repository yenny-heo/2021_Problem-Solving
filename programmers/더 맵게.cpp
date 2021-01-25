#include <string>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    for(int i=0; i<scoville.size(); i++){
        pq.push(scoville[i]);
    }
    
    while(pq.top() < K){
        answer++;
        int first = pq.top();
        pq.pop();
        if(pq.empty()){
            return -1;
        }
        int second = pq.top();
        pq.pop();
        
        int mix = first + (second * 2);
        pq.push(mix);
    }
    return answer;
}