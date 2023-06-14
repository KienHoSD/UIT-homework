#include <bits/stdc++.h>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;std::cin>>N;
    std::string s = std::to_string(N);
    reverse(s.begin(),s.end());
	do { std::cout<<stoi(s)<<"\n";
    } while (std::prev_permutation(s.begin(), s.end()));
}
