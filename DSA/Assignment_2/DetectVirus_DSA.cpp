#include <iostream>
#include <string>
int main(){
    std::string S,T;
    std::getline(std::cin,S);
    std::getline(std::cin,T);
    int Tlength= T.length();
    int Slength= S.length();
    bool alreadyprintYes = false;
    for(int i =0;i<Slength;i++){
        size_t found = S.find(T);
        if(!alreadyprintYes&&found== std::string::npos){
            std::cout<<"NO";
            break;
        }
        if (found != std::string::npos){
            if(!alreadyprintYes) {
                std::cout<<"YES\n";
                alreadyprintYes=true;
            }
            std::cout <<found +1<< " ";
            for(int j=found;j<found+Tlength;j++)
                S[j]=' ';
        }
    }
}
