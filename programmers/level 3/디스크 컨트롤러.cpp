#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int len = jobs.size();
    sort(jobs.begin(), jobs.end());
    int time = 0;
    
    while(jobs.size() >= 1 || !pq.empty()){
        bool flag = 0;
        if(!pq.empty()){//큐 처리
            int proc_time = pq.top().first;
            int req_time = pq.top().second;
            pq.pop();
            time += proc_time;
            answer += (time - req_time);
        }
        while(jobs.size() >= 1 && jobs[0][0] <= time){//작업 추가
            pq.push({jobs[0][1], jobs[0][0]});
            jobs.erase(jobs.begin());
            flag = 1;
        }
        if(pq.empty() && !flag){//큐가 비어있고 추가할 작업도 없으면 시간 증가
            time++;
        }
    }
    answer /= len;
    return answer;
}