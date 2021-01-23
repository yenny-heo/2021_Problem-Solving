 #include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <utility>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 0;
    
    int size = truck_weights.size();
    
    deque<pair<int, int>> in_bridge;//다리에 있는 트력 큐
    deque<int> arrive;//도착한 트럭 큐
    
    int idx = 0;
    int weight_sum = 0;
    
    while(arrive.size() != size){
        time++;
        //다리를 건너는 트럭들 이동
        for(int i=0; i<in_bridge.size(); i++){
            in_bridge[i].second--;
        }
        //도착한 트럭
        for(int i=0; i<in_bridge.size(); i++){
            if(in_bridge[0].second <= 0){
                arrive.push_back(in_bridge[0].first);
                weight_sum -= in_bridge[0].first;//무게 차감
                in_bridge.pop_front();
            }
            else break;
        }
        //트럭 새로 추가
        if(idx < size && weight >= truck_weights[idx] + weight_sum){
            in_bridge.push_back({truck_weights[idx], bridge_length});
            weight_sum += truck_weights[idx];//무게 추가
            idx++;
        }
        
    }    
    return time;
}