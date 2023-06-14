#include <iostream>
#include <algorithm>
using namespace std;
bool is_special_year(int year){
    if(year%3328==0) return true;
    return false;
}
bool is_leap_year(int y) {
  return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
}
int no_of_days(int month, int year) {
  switch (month) {
  case 1:
  case 3:
  case 5:
  case 7:
  case 8:
  case 10:
  case 12:
    return 31;
    break;

  case 4:
  case 6:
  case 9:
  case 11:
    return 30;
    break;

  case 2:
    if (is_special_year(year) == 1)
      return 30;
    else if(is_leap_year(year)== 1)
      return 29;
    else
      return 28;
    break;
  default:
    break;
  }
  return 0;
}
void sortString(string &str)
{
   sort(str.begin(), str.end());
}
int main(){
    string year,month,day;
    cin>>year>>month>>day;
    string date=year+month+day;
    sortString(date);
    int demngay=0;
    do{
        int nam=stoi(date.substr(0,4));
        int thang=stoi(date.substr(4,2));
        int ngay = stoi(date.substr(6,2));
        if (nam==0||nam>9999||thang==0||thang>12||ngay==0||ngay>no_of_days(thang,nam)) continue;
        demngay++;
    } while(next_permutation(date.begin(),date.end()));
    cout<<demngay<<endl;
    date=year+month+day;
    sortString(date);
    do{
        int nam=stoi(date.substr(0,4));
        int thang=stoi(date.substr(4,2));
        int ngay = stoi(date.substr(6,2));
        if (nam==0||nam>9999||thang==0||thang>12||ngay==0||ngay>no_of_days(thang,nam)) continue;
        cout<<date.substr(0,4)+" "+date.substr(4,2)+" "+date.substr(6,2)<<endl;
    } while(next_permutation(date.begin(),date.end()));
}
