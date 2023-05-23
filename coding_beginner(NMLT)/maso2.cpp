#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define int ll
void solve()
{
	// cout << "Case #" << ++Google_Test << ": ";
	string s;
	cin >> s;
	vector<int> cnt(26);
	uint64_t tot = 0;
	uint64_t flag = 0;
	for(char c:s)
	{
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
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//Test
	solve();
	return 0;
}
