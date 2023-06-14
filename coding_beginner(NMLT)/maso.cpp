#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin >> s;
	vector<int> cnt(26);
	uint64_t tot = 0;
	uint64_t flag = 0;
	for(char c:s) {
		cnt[c-'a']++;
		tot++;
		if(cnt[c-'a']>1)
		flag = 1;
	}
	uint64_t ans = 0;
	for(int i:cnt)
	ans += (tot-i)*i;
	cout << ans/2 + flag;
}
