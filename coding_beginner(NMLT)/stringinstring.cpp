
#include <iostream>
#include <string>
using namespace std;
#define MAX 255

int myStrlen(char s[]);
bool myStrcat(char s1[], char s2[]);

int main(){
	char s1[MAX], s2[MAX];
	cin.getline(s1,MAX);
	cin.getline(s2,MAX);
	bool kt = myStrcat(s1, s2);
}
int myStrlen(char s[]){
    int dem=0;
    for(int i=0;s[i];i++)
        dem++;
    return dem;
}
void XoaKhoangTrang(char s1[]) {
	int i, j;
	int len = myStrlen(s1);
	for (i = 0; i < len; i++) {
		if (s1[0] == ' ') {
			for (i = 0; i < (len - 1); i++) s1[i] = s1[i + 1];
			s1[i] = '\0';
			len--;
			i = -1;
			continue;
		}
		if (s1[i] == ' ' && s1[i + 1] == ' ') {
			for (j = i; j < (len - 1); j++) s1[j] = s1[j + 1];
			s1[j] = '\0';
			len--;
			i--;
		}
	}
}
bool myStrcat(char s1[MAX], char s2[MAX]){
    int dodai2str=myStrlen(s1)+myStrlen(s2)+1;
    s1[myStrlen(s1)]=' ';
    if(dodai2str>254) return false;

    XoaKhoangTrang(s1);
    XoaKhoangTrang(s2);
    for(int i=0;i<myStrlen(s1);i++) cout<<s1[i];
    cout<<" ";
    for(int i=0;i<myStrlen(s2);i++) cout<<s2;
    for(int i=0;i<7;i++) cout<<s1[i];
    return true;
}

