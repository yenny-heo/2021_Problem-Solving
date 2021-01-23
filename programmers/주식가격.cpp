#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    for(int i=0; i<prices.size(); i++){
        int cnt = 0;
        bool flag = false;
        for(int j = i+1; j<prices.size(); j++){
            cnt++;
            if(prices[i] > prices[j]){
                answer.push_back(cnt);
                flag = true;
                break;
            }
        }
        if(!flag){
            answer.push_back(prices.size() - i - 1);
        }        
    }
    return answer;
}