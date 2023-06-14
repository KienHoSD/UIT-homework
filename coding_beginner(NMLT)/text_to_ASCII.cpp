#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main()
{
    char firstLetter,secondLetter;
    int numberAscii;
    cin>>firstLetter>>secondLetter>>numberAscii;
    cout<<"Ma ASCII cua ky tu '"<<firstLetter<<"', '"<<secondLetter<<"' lan luot la "<< int(firstLetter)<<" va "<<int(secondLetter)<<endl;
    cout<<"Khoang cach giua hai ky tu '"<<firstLetter<< "', '"<<secondLetter<<"' la "<<abs(int(firstLetter)-int(secondLetter))<<endl;
    cout<<"Dang viet hoa cua ky tu '"<<firstLetter<<"' la '"<< char(firstLetter-32)<<"'"<<endl;
    cout<<numberAscii<< " la ma ASCII cua ky tu '" <<char(numberAscii)<<"'";
}
