#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    //phase 1
    for(int i=0; i<new_id.length(); i++){
        if(new_id[i] >= 'A' && new_id[i] <= 'Z'){
            new_id[i] = new_id[i] - 'A' + 'a';
        }
    }
    //phase 2
    for(int i=0; i<new_id.length(); i++){
        if((new_id[i] >= 'a' && new_id[i] <= 'z') ||
          (new_id[i] >= '0' && new_id[i] <= '9') ||
          new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.'){
            
        }
        else{
            new_id.erase(i, 1);
            i--;
        }
    }
    //phase 3
    for(int i=0; i<new_id.length(); i++){
        int j = 0;
        while(new_id[i+j] == '.'){
            j++;
        }
        if(j >= 2){
            new_id.replace(i, j, ".");
        }
    }
    
    //phase 4
    if(new_id[0] == '.') new_id.erase(0, 1);
    if(new_id[new_id.length()-1] == '.') new_id.erase(new_id.length()-1, 1);
    
    //phase 5
    if(new_id.length() == 0) new_id += "a";
    
    //phase 6
    if(new_id.length() >= 16){
        new_id.erase(15, new_id.length() - 15);
    }
    if(new_id[new_id.length()-1] == '.') new_id.erase(new_id.length()-1, 1);
    
    //phase 7
    char last = new_id[new_id.length() - 1];
    if(new_id.length() <= 2) new_id.append(3 - new_id.length(),last);
    
    answer = new_id;
    return answer;
}