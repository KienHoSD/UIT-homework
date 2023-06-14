#include<iostream>
bool check_day(int day, int month,int year){
    if((month==1||month==3||month==5||month==7||month==8||month==10||month==12)&&day>0&&day<=31) return true; // thang 1 3 5 7 8 10 12
    else if((month==4||month==6||month==9||month==11)&&day>0&&day<=30) return true; // thang 4 6 9 11
    else if(month==2&&day>0&&day<=28) return true; // thang 2
    else if(month==2&&year%4==0&&year%100!=0&&day<=29) return true; //nam nhuan
    return false;
}
void print_day(int day,int month,int year) {std::cout<<day<<"/"<<month<<"/"<<year;}
void print_thenextday(int day,int month,int year){
    if(check_day(day+1,month,year))
        print_day(day+1,month,year);
    else{
        if(check_day(1,month+1,year)) print_day(1,month+1,year);
        else print_day(1,1,year+1);
    }
}
int main(){
    int day,month,year;
    std::cout<<"Nhap ngay :";
    while (true){
        std::cin>>day>>month>>year;
        if(check_day(day,month,year)){
            std::cout<<"Ngay tiep theo la :";print_thenextday(day,month,year);
            break;
        }
        std::cout<<"Ngay khong hop le, hay nhap lai :";
    }
}
