#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    string origin = "";
    int len = name.length();
    for(int i=0; i<len; i++){
        origin += "A";
    }
    int cursor = 0;
    
    while(1){
        int cursor_min_gap = 9999999;
        int next_idx = -1;
        for(int i=0; i<len; i++){
            if(name[i] != origin[i]){
                int right_cursor = (i - cursor < 0) ? len + i - cursor : i - cursor;
                int left_cursor = (cursor - i < 0) ? len + cursor - i : cursor - i;
                int cursor_gap = (right_cursor > left_cursor) ? left_cursor : right_cursor;
                if(cursor_gap < cursor_min_gap) {
                    cursor_min_gap = cursor_gap;
                    next_idx = i;
                }
            }
        }
        //수정할 게 없을 때
        if(next_idx == -1) break;
        
        //커서 이동
        cursor = next_idx;
        answer += cursor_min_gap;
        origin[next_idx] = name[next_idx];
        int gap = name[next_idx] - 'A';
        if(gap > 26 - gap){
            gap = 26 - gap;
        }
        answer += gap;
    }
    
    return answer;
}