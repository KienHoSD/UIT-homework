
#include <bits/stdc++.h>
#include <fstream>
using  namespace std;
ifstream fi("filein.txt");
ofstream fo("result.txt");
struct toado{
    double x,y;
};
bool sortByX(toado &a, toado& b){
    return a.x<b.x;
}
double chieudaivector(toado diemdau, toado diemcuoi){
    return abs((diemdau.x-diemcuoi.x)*(diemdau.x-diemcuoi.x)+(diemdau.y-diemcuoi.y)*(diemdau.y-diemcuoi.y));
}
void truyvet(vector<toado> nguoi,int n,int fw,int d){
    vector<toado> nguoif1;
    vector<toado> nguoiconlaif1=nguoi;
    int demf1=0,demf2=0;
    for(int i=0,diemxoaj=0;i<n;i++,diemxoaj++){

            //cout<<chieudaivector(nguoi[i],nguoi[fw-1])<<endl;
            double temp=chieudaivector(nguoi[i],nguoi[fw-1]);
            if(temp<=double(d)*double(d)){
                //fo<<nguoi[i].x<<" "<<nguoi[i].y<<endl; in so diem bi f1
                demf1++;
                nguoif1.push_back(nguoi[i]);
                nguoiconlaif1.erase (nguoiconlaif1.begin() + diemxoaj);
                diemxoaj--;
            }

    }
    //fo<<endl;
    vector<toado> nguoif2;
    for(toado i:nguoiconlaif1){
        int dem=0;
        for(toado j:nguoif1){
            double temp=chieudaivector(i,j);
            if(temp<=double(d)*double(d)){
                nguoif2.push_back(i);
                break;
            }
            else if(dem==demf1-1) {
                //fo<<i.x<<" "<<i.y<<endl; in so diem con lai
            }
            dem++;
        }
    }
    //fo<<endl;
    //for(toado t:nguoiconlaif2) fo<<t.x<<" "<<t.y<<endl;

    for(toado t:nguoif2){
        demf2++;
        fo<<t.x<<" "<<t.y<<endl; //in so diem bi f2
    }

    std::sort(&nguoif2[0],&nguoif2[demf2],sortByX);
    //std::sort(&nguoif1[0],&nguoif1[demf1],sortByX);
    fo<<endl;
    //demf2=0;
    int tempx=NULL,tempy=NULL;
    for(toado t:nguoif2){
        if(tempx==t.x&&tempy==t.y){
            demf2--;

            //fo<<t.x<<" "<<t.y<<endl;
        }
        tempx=t.x,tempy=t.y;
    }
    //demf1=0;
    //tempx=NULL,tempy=NULL;
    //for(toado t:nguoif1)
        //if(t.x==nguoi[fw-1].x&&t.y==nguoi[fw-1].y)
            //demf1--;
            //cout<<t.x<<" "<<t.y<<endl;

    fo<<demf1-1<<" ";
    fo<<demf2;
}
int main(){
    int n,fw,d;
    fi>>n>>fw>>d;
    vector<toado> nguoi(n);
    for(int i=0;i<n;i++)
        fi>>nguoi[i].x>>nguoi[i].y;
    truyvet(nguoi,n,fw,d);
}
