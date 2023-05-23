#include <iostream>
using namespace std;
int main(){
    char a[10][10];
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++)
            cin>>a[i][j];
    }
    for(int i=1;i<=9;i++){  //hang doc
        for(int j=1;j<=9;j++) // hang ngang
            if(a[i][j]=='X'){
                for(int e=1;e<=9;e++) //check hang doc
                    if(a[i][e]=='X'&&e!=j) //neu hang doc co chua 2 X thi break
                        break;

            }
        }
    }

}
