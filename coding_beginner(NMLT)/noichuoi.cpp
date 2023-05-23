#include <iostream>
#include <string>
using namespace std;
#define MAX 255

int myStrlen(char s[]);
bool myStrcat(char s1[], char s2[]);

int main()
{
	char s1[MAX], s2[MAX];
	cin.getline(s1,MAX);
	cin.getline(s2,MAX);
	bool kt = myStrcat(s1, s2);

if (kt == false || myStrlen(s2) > 254 || myStrlen(s1) > 254)
        cout << "Khong noi duoc. Khong du bo nho.";
    else cout << s1;
	    return 0;
}
int myStrlen(char s[]) {
	uint64_t dem = 0;
	uint64_t i = 0;
	while (s[i] != '\0') {
		dem++;i++;
	}
	return dem;
}
void removespace(char s1[]) {
	int i, j;
	int len = myStrlen(s1);
	for (i = 0; i < len; i++) {
		if (s1[0] == ' ') {
			for (i = 0; i < (len - 1); i++)
			    s1[i] = s1[i + 1];
			s1[i] = '\0';
			len--;i--;
			continue;
		}
		if (s1[i] == ' ' && s1[i + 1] == ' ') {
			for (j = i; j < (len - 1); j++)
			    s1[j] = s1[j + 1];
			s1[j] = '\0';
			len--;i--;
		}
	}
}
bool myStrcat(char s1[], char s2[]) {
	for (int i = 0;; i++) {
		if (s1[i] == '\0') {
			s1[i] = 0;
			break;
		}
	}
	int so1 = 0;
	while (s1[so1])
		so1++;
	for (int i = 0;; i++) {
		if (s2[i] == '\0') {
			s2[i] = 0;
			break;
		}
	}
	int so2 = 0;
	while (s2[so2]) {
		s1[so1] = s2[so2];
		so1++;so2++;
	}
	s1[so1] = '\0';
	removespace(s1);
	if (so1 > 254) return false;
	return true;
}
