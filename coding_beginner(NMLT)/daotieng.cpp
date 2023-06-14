
#include <iostream>
#include <string.h>
using namespace std;
#define MAX 300

int myStrcmp(char s1[], char s2[]);
int myStrlen(char s[], int k);
void myStrcpy(char s[], int vt, char s1[], int k);
void mySubstr(char s[], int b, int count, char ss[]);
bool myStrcat(char s1[], char s2[]);
void StringReverse(char st[]);

int main()
{
	char s[MAX];
	cin.getline(s,MAX);
	if (myStrcmp(s, "") == 0)
		cout << "Chuoi rong." << endl;
	else
	{
		StringReverse(s);
		cout << s << endl;
	}
	return 0;
}

int myStrlen(char s[], int k){
    int dem=0;
    for(int i=0;s[i];i++)
        dem++;
    return dem;
}
int myStrcmp(char s1[], char s2[]){
    if(myStrlen(s1,0)==0)
        return 0;
    return 1;
}
void StringReverse(char s1[]){
    int dodais1=myStrlen(s1,0);
    char s2[MAX];
    int vitris2=-1;
    int vitriI=0;
    for(int i=0;s1[i];i++){
        if(s1[i]==' '){
            int j=i-1,g=vitris2+1;
            for(int j=i-1,g=vitris2+1;j>vitris2;j--,g++)
                s2[g]=s1[j];
            vitris2=i;
        }
        vitriI=i;
    }
    for(int j=vitriI,g=vitris2+1;j>vitris2;j--,g++)
        s2[g]=s1[j];
    for(int i=0;s1[i];i++)
        if(s1[i]!=' ')
            s1[i]=s2[i];
}
