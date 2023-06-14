
#include <iostream>
using namespace std;
int main()
{
    int n;
    int ketqua=0;
    cin>>n;
    if(n/100==0){
        int hangchuc=n/10;
        int hangdonvi=n-hangchuc*10;
        if(hangdonvi!=0) ketqua=1000+(hangdonvi-1)*100+hangchuc;
        if(hangdonvi==0) ketqua=1000+(hangchuc-1)*100;
    }
    else if(n/1000==0){
        int hangtram=n/100;
        int hangchuc=(n-hangtram*100)/10;
        int hangdonvi= n-hangtram*100-hangchuc*10;
        if(hangchuc+1<hangdonvi||hangdonvi==0) ketqua=(hangchuc+1)*1000+900+hangdonvi;
        if(hangdonvi>0) ketqua= 1000+ (hangdonvi-1)*100+(hangchuc+1)*10+9;
    }
    else{
        int hangngan=n/1000;
        int hangtram=(n-hangngan*1000)/100;
        int hangchuc=(n-hangngan*1000-hangtram*100)/10;
        int hangdonvi= n-hangngan*1000-hangtram*100-hangchuc*10;
        if(hangtram==0) ketqua=1900+(hangdonvi+1)*10+9;
        if(hangdonvi<hangtram && hangdonvi==0&&hangtram!=0) ketqua= (hangdonvi+1)*1000+900+(hangtram+1)*10+9;
        if(hangdonvi<hangtram && hangdonvi!=0&&hangtram!=0) ketqua= (hangdonvi+1)*1000+900+(hangtram+1)*10+9;
        if(hangdonvi>=hangtram&& hangdonvi!=0&&hangtram!=0) ketqua= (hangtram+1)*1000+900+(hangdonvi+1)*10+9;
    }
    cout<<ketqua;


}
