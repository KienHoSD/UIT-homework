#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <unordered_map>
using namespace std;
map<string,int> nhap_ma_tran(vector<priority_queue<int,vector<int>,greater<int>>>& matran,int sodinh,int socanh){
    map<string,int> hash_word_to_index;
    string word;
    // hash word to index
    for(int i=0;i<sodinh;i++){
        cin>>word;
        hash_word_to_index[word]=i;
    }
    string word1,word2;
    // making a list of priority queue with least is top
    for(int i=0;i<socanh;i++){
        cin>>word1>>word2;
        matran[hash_word_to_index[word1]].push(hash_word_to_index[word2]);
    }
    return hash_word_to_index;
}
void DFS(const vector<priority_queue<int,vector<int>,greater<int>>>& matran, map<string,int>& hash_word_to_index, int sodinh,int socanh){
    // create hash_index_to_word from hash_word_to_index
    map<int,string> hash_index_to_word;
    for(auto it=hash_word_to_index.begin();it!=hash_word_to_index.end();it++)
        hash_index_to_word[it->second]=it->first;
    // start to finding path by DFS m's times
    int m_lan_tim_duong;cin>>m_lan_tim_duong;
    for(int i=0;i<m_lan_tim_duong;i++){
        // Create needed variable
        vector<priority_queue<int,vector<int>,greater<int>>> matrantemp = matran;
        unordered_map<int,int> previous_of_key_map;
        vector<bool> dinh_da_xet(sodinh);
        stack<int> dang_xet_stack;
        int dang_xet_index;
        string word1,word2;
        bool found_word2=false;
        // Input the path to find
        cin>>word1>>word2;
        // ACTIVATE SPACE MODE  
        dang_xet_stack.push(hash_word_to_index[word1]);
        while(!dang_xet_stack.empty()){
            dang_xet_index=dang_xet_stack.top();
			dinh_da_xet[dang_xet_index]=true;
            dang_xet_stack.pop();
            // taking all side of a start point dang_xet_index then 
            // if found word2 stop
            // else still finding until the stack is empty
            while(!matrantemp[dang_xet_index].empty()){
                if(dinh_da_xet[matrantemp[dang_xet_index].top()]==false){
                    dang_xet_stack.push(matrantemp[dang_xet_index].top());
                    previous_of_key_map.insert({matrantemp[dang_xet_index].top(),dang_xet_index});
                    if(dang_xet_stack.top()==hash_word_to_index[word2]){
                        found_word2=true;
                        break;                    
                    } 
                }
                matrantemp[dang_xet_index].pop();
            }
            if(found_word2) break;
        }
        // if word2 not found print no_path
        if(!found_word2) cout<<"no_path\n";
        // else print the path 
        else{
            int index_of_reverse_word2=hash_word_to_index[word2];
            stack<int> answer;
            answer.push(index_of_reverse_word2);
            while(previous_of_key_map.count(index_of_reverse_word2)){
                answer.push(previous_of_key_map[index_of_reverse_word2]);
                index_of_reverse_word2=previous_of_key_map[index_of_reverse_word2];
            }
            while(!answer.empty()){
                cout<<hash_index_to_word[answer.top()]<<" ";
                answer.pop();
            }
            cout<<endl;
        }
    }
}
int main(){
    int sodinh,socanh;cin>>sodinh>>socanh;
    // it's a vector of descending int;
    vector<priority_queue<int,vector<int>,greater<int>>> matran(sodinh);
    map<string,int> hash_word_to_index;
    hash_word_to_index = nhap_ma_tran(matran,sodinh,socanh);
    DFS(matran,hash_word_to_index,sodinh,socanh);
}