/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
strlen
strcat
string
strcmp
strcpy
memmove
strstr
###End banned keyword*/

#include <iostream>
#include <string.h>
using namespace std;
#define MAX 255

int myStrcmp(char s1[], char s2[]);

int main()
{
	char s1[MAX], s2[MAX];
	cin.getline(s1,MAX);
	cin.getline(s2,MAX);
	int kt = myStrcmp(s1, s2);
	cout << kt << endl;
	return 0;
}
//###INSERT CODE HERE -
int myStrcmp(char s1[],char s2[]){
    //if(s1.size()>254||s2.size()>254) return 0;
    for(int i=0;s2[i]||s1[i];i++){
        if(s1[i]>s2[i]) return 1;
        else if(s1[i]<s2[i]) return -1;
    }
    return 0;
}
