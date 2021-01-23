#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int snail[1000][1000];
    int max = 0;
    for(int i=1; i<=n; i++){
        max += i;
    }
    
    int x = 0, y = 0;
    int num = 1;
    snail[0][0] = 1;
    
    for(int i=n-1; i>0;){
        for(int a=0; a<i; a++, x++){
            snail[x][y] = num;
            num++;
        }
        if(i != n-1) i--;
        if(i == 0) snail[x][y] = num;
        for(int a=0; a<i; a++, y++){
            snail[x][y] = num;
            num++;
        }
        i--;
        if(i == 0) snail[x][y] = num;
        for(int a=0; a<i; a++, x--, y--){
            snail[x][y] = num;
            num++;
        }
        i--;
        if(i == 0) snail[x][y] = num;
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            answer.push_back(snail[i][j]);
        }
    }
    return answer;
}