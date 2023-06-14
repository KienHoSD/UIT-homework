#include <bits/stdc++.h>
using namespace std;
typedef string bignum_str;
void input(bignum_str &number)
{
    cin >> number;
}

void output(bignum_str number)
{
    cout << number;
}
void equal_length(bignum_str &a, bignum_str &b)
{
    while (a.size() < b.size())
        a = '0' + a;
    while (b.size() < a.size())
        b = '0' + b;
}

int compare(bignum_str a, bignum_str b)
{
    equal_length(a, b);

    if (a < b) // Có thể là a <= b.
        return -1;
    if (a > b) // Có thể là a >= b.
        return 1;

    return 0;
}
bignum_str add(bignum_str a, bignum_str b)
{
    equal_length(a, b);

    int carry = 0;
    bignum_str res;
    for (int i = a.size() - 1; i >= 0; --i)
    {
        // Cộng hai chữ số cùng hàng và thêm biến nhớ từ hàng bên phải dồn lên.
        int d = (a[i] - '0') + (b[i] - '0') + carry;

        carry = d / 10; // Biến nhớ bằng kết quả hàng trước chia 10.
        res = (char)(d % 10 + '0') + res; // Viết chữ số cuối của kết quả.
    }

    if (carry)
        res = '1' + res;

    return res;
}
int main(){
    int t; cin>>t;
    string ketqua;
    int chieudai;
    string ketquafinal;
    char e;
    int i;
    for(i=1;i<=t;i++){
        input(ketqua);
        while(true){
            chieudai=ketqua.length();
            if(chieudai>=2||ketqua!="1"){
                e=ketqua[chieudai-1];
                if(e=='1')add(ketqua,"9");
                else if(e=='2')ketqua=add(ketqua,"8");
                else if(e=='3')ketqua=add(ketqua,"27");
                else if(e=='4')ketqua=add(ketqua,"16");
                else if(e=='5')ketqua=add(ketqua,"5");
                else if(e=='6')ketqua=add(ketqua,"24");
                else if(e=='7')ketqua=add(ketqua,"63");
                else if(e=='8')ketqua=add(ketqua,"32");
                else if(e=='9')ketqua=add(ketqua,"91");
                ketqua.pop_back();
            }
            else if(ketqua!="1"&&ketqua!="3"&&ketqua!="7"&&ketqua!="9"){
                if(ketqua=="2")ketqua=add(ketqua,"8");
                else if(ketqua=="4")ketqua=add(ketqua,"16");
                else if(ketqua=="5")ketqua=add(ketqua,"5");
                else if(ketqua=="6")ketqua=add(ketqua,"24");
                else if(ketqua=="8")ketqua=add(ketqua,"32");
                ketqua.pop_back();
            }

            if(ketqua=="1" ||ketqua=="3" || ketqua=="7" || ketqua=="9"){
                ketquafinal+=ketqua+"\n";
                break;
            }
        }
        if(i%5==0){
            cout<<ketquafinal;
            ketquafinal="";
        }
    }
    if((i%5)-1!=0){
        cout<<ketquafinal;
        ketquafinal="";
    }
}
