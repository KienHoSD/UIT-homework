#include <bits/stdc++.h>
using namespace std;
int MaxGCD(int64_t a[], int n)
{

     // returns max GCD after removing an element


	// Prefix and Suffix arrays
	int64_t Prefix[n + 2];
	int64_t Suffix[n + 2];
	int i;

	// Single state dynamic programming relation to store gcd of first i elements
	// from left in Prefix[i]


	Prefix[1] = a[0];
	for (i = 2; i <= n; i += 1) {
		Prefix[i] = __gcd(Prefix[i - 1], a[i - 1]);
	}

	// Initializing Suffix array
	Suffix[n] = a[n - 1];

	// Single state dynamic programming relation
	// for storing gcd of all the elements having
	// greater than or equal to i in Suffix[i]
	for (i = n - 1; i >= 1; i--) {
		Suffix[i] = __gcd(Suffix[i + 1], a[i - 1]);
	}

	// If first or last element of
	// the array has to be removed
	int64_t ans = max(Suffix[2], Prefix[n - 1]);

	// If any other element is replaced
	for (i = 2; i < n; i += 1)
        ans= max(ans, __gcd(Prefix[i - 1], Suffix[i + 1]));
	// Return the maximized gcd

	return ans;
}
int64_t UCLN(int64_t A, int64_t B) {
    if (B == 0)
        return A;
    return UCLN(B, A%B);
}
int main(){
    int64_t a[100001];
    int n;
    cin>>n;
    int i=0;
    int64_t temp1=0,temp2=0,vitri=0,Max=0,tempUCLN=0;
    for(i=1;i<=n;i++) cin>>a[i];
    for(i=1;i<=n-1;i++){
        cout<<i<<endl;
        temp1=(a[i]<a[i+1])?a[i+1]-a[i]:a[i]-a[i+1];
        tempUCLN=UCLN(a[i],a[i+1]);
        if(tempUCLN>Max) Max=tempUCLN;
        if(temp1!=0){
            temp2=(a[i]>temp1)?(a[i]%temp1):(temp1%a[i]);
            if(temp2!=0) {
                vitri=i;
                break;
            }
        }
    }
    cout<<vitri<<endl;
    a[vitri]=0;
    int64_t ketqua= MaxGCD(a,n);
    cout<<vitri<<" "<<ketqua;
}
