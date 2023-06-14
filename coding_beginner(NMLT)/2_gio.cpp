#include <bits/stdc++.h>
using namespace std;
int main()
{
    int defaultTime=7200;
    int response,addingHours,addingMinutes,addingSeconds;
    cout<<"Thoi gian hien tai la: "<<defaultTime/60/60<<" gio "<<defaultTime/60-defaultTime/60/60*60<<" phut "<<defaultTime-defaultTime/60*60<<" giay\n";
    cout<<"Ban muon them hay bot thoi gian?\nThem an 2 \nBot an 1 \n";
    while (true){
    cin>>response;
    if (response == 0)
        break;
    else if (response==2){
        cout<<"Them bao nhieu gio? ";
        cin>>addingHours;
        defaultTime += addingHours*3600;
        cout<<"Them bao nhieu phut? ";
        cin>>addingMinutes;
        defaultTime += addingMinutes*60;
        cout<<"Them bao nhieu giay? ";
        cin>>addingSeconds;
        defaultTime += addingSeconds;
    }
    else if(response == 1) {
        cout<<"bot bao nhieu gio? ";
        cin>>addingHours;
        defaultTime -= addingHours*3600;
        cout<<"bot bao nhieu phut? ";
        cin>>addingMinutes;
        defaultTime -= addingMinutes*60;
        cout<<"bot bao nhieu giay? ";
        cin>>addingSeconds;
        defaultTime -= addingSeconds;
    }
    cout<<"Thoi gian hien tai la: "<<defaultTime/60/60<<" gio "<<defaultTime/60-defaultTime/60/60*60<<" phut "<<defaultTime-defaultTime/60*60<<" giay\n";
    cout<<"Ban muon them hay bot thoi gian? ";
    }
    return 0;
}
