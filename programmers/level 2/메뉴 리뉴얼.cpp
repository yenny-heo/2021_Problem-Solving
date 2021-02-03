#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
map<string, int> m;

void select(string order, string selected_order, int idx, int cnt, int num){
    if(cnt == num){
        //메뉴 추가
        if(m.find(selected_order) == m.end()){
            m.insert({selected_order, 1});
        }
        else{
            m[selected_order]++;
        }
    }
    else{
        for(int i=idx; i<order.length(); i++){
            string new_order = selected_order;
            new_order.append(1, order[i]);
            select(order, new_order, i+1, cnt+1, num);
        }
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(int i=0; i<orders.size(); i++){
        sort(orders[i].begin(), orders[i].end());
    }
    
    for(int i=0; i<course.size(); i++){
        for(int j=0; j<orders.size(); j++){
            select(orders[j], "", 0, 0, course[i]);
        }
    }
    
    for(int i=0; i<course.size(); i++){
        int len = course[i];
        int max = 0;
        for(auto iter = m.begin(); iter != m.end(); iter++){
            if(iter->first.length() == len && iter->second > max){
                max = iter->second;
            }
        }
        if(max >= 2){
            for(auto iter = m.begin(); iter != m.end(); iter++){
                if(iter->first.length() == len && iter->second == max){
                    answer.push_back(iter->first);
                }
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}