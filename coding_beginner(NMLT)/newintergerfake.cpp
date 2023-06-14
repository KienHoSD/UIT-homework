#include <iostream>
#include <string>
using namespace std;
int main(){
    string dongchuso;
    int i,tong=0;
    int j=0;
    int g=0;
    int e=0;
    getline(cin,dongchuso);
    string finalNumber;
    string dongchusodefault=dongchuso;
    finalNumber=dongchusodefault;
    for(j=0;j<=dongchusodefault.length()-1;j++){
        for(g=0;g<=dongchuso.length()-1;g++){
            if(g!=j)
                tong+=dongchuso[g]-'0';
        }
        for(i=1;i<=9;i++){
            if(dongchusodefault[j]!=char(i)+'0'&&(tong+i)%3==0){
                dongchuso[j]=char(i)+'0';
                for(e=0;e<=dongchuso.length()-1;e++){
                    if(dongchuso[e]-'0'>finalNumber[e]-'0'){
                        finalNumber=dongchuso;
                        break;
                    }
                    else if(e==dongchusodefault.length()-1&&dongchuso[e]-'0'<finalNumber[e]-'0')
                    {
                        finalNumber=dongchuso;
                        break;
                    }
                    else if (dongchuso[e]-'0'<finalNumber[e]-'0'){
                        break;
                    }
                }
            }
        }
        dongchuso=dongchusodefault;
        tong=0;
    }
    cout<<finalNumber;
}
