//문자열 처리
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> pages_url;//나의 url
vector<int> base_score;//기본 점수
vector<int> link_to_cnt;//외부 링크 개수
vector<int> link_from[20];//나를 가리키는 페이지 번호들
vector<double> link_score;//링크 점수
vector<double> matching_score;//매칭 점수

void add_link(int idx, string link){
    //외부 링크 개수 추가
    link_to_cnt[idx]++;
    //해당 링크 가리키는 페이지 번호 추가
    for(int i=0; i<pages_url.size(); i++){
        if(pages_url[i] == link){
            link_from[i].push_back(idx);
        }
    }
}

string to_lower(string a){
    for(int i=0; i<a.length(); i++){
        if(a[i] >= 'A' && a[i] <= 'Z'){
            a[i] = a[i] - 'A' + 'a';
        }
    }
    return a;
}
void find_word(int idx, string pure, string word){
    pure = to_lower(pure);
    word = to_lower(word);
    int find_idx = 0;
    while(1){
        find_idx = pure.find(word, find_idx);
        if(find_idx == -1) break;
        //단어 앞뒤가 알파벳이 아닌 경우만 기본점수에 반영
        if((pure[find_idx - 1] < 'a' || pure[find_idx - 1] > 'z')
           && (pure[find_idx + word.length()] < 'a' || pure[find_idx + word.length()] > 'z')){
            base_score[idx]++;
        } 
        find_idx += word.length();
    }
}
void body_parser(int idx, string body, string word){
    int start = 0;
    int end = 0;
    string pure = "";
    while(1){
        end = body.find("<a", start);
        pure += body.substr(start, end - start);
        if(end == -1) break;
        //외부 링크
        int link_start = body.find("href=\"", end) + 6;
        int link_end = body.find("\">", link_start);
        string link = body.substr(link_start, link_end - link_start);
        add_link(idx, link);
        
        start = body.find("</a>", end) + 4;
    }
    
    find_word(idx, pure, word);
}

void head_parser(string head){
    int meta_start = 0;
    int meta_end = 0;
    string url = "";
    while(1){
        meta_start = head.find("<meta", meta_end);
        if(meta_start == -1) break;
        meta_start += 5;
        meta_end = head.find("/>", meta_start);
        string meta = head.substr(meta_start, meta_end - meta_start);
        
        int url_start = meta.find("content=\"");
        if(url_start == -1) continue;
        url_start += 9;
        int url_end = meta.find("\"", url_start);
        url = meta.substr(url_start, url_end - url_start);
    }
    pages_url.push_back(url);
}

int solution(string word, vector<string> pages) {
    int answer = 0;
    
    for(int i=0; i<pages.size(); i++){
        base_score.push_back(0);
        link_to_cnt.push_back(0);
    }
    
    for(int i=0; i<pages.size(); i++){
        //head 분리
        int head_start = pages[i].find("<head>") + 6;
        int head_end = pages[i].find("</head>");
        string head = pages[i].substr(head_start, head_end-head_start);
        
        head_parser(head);
    }
    
    for(int i=0; i<pages.size(); i++){
        //body 분리
        int body_start = pages[i].find("<body>") + 6;
        int body_end = pages[i].find("</body>");
        string body = pages[i].substr(body_start, body_end-body_start);
        
        body_parser(i, body, word);
    }
    
    //링크 점수, 매칭 점수 계산
    for(int i=0; i<pages.size(); i++){
        double ls = 0;
        for(int j=0; j<link_from[i].size(); j++){
            int idx = link_from[i][j];
            ls += (double)base_score[idx] / (double)link_to_cnt[idx];
        }
        link_score.push_back(ls);
        matching_score.push_back((double)ls + (double)base_score[i]);
    }
    
    double max_score = 0;
    for(int i=0; i<matching_score.size(); i++){
        if(max_score < matching_score[i]){
            max_score = matching_score[i];
            answer = i;
        }
    }
    
    return answer;
}