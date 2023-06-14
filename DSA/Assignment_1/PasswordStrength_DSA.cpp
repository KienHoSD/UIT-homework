#include <iostream>
#include <string>
bool co_chu_cai_hoa(const std::string& password, int len) {
    for (int i = 0; i < len; i++) if (int(password[i]) >= 65 && int(password[i]) <= 90) return 1;
    return 0;
}
int dem_chu_cai_hoa(const std::string& password, int len) {
    int dem = 0;
    for (int i = 0; i < len; i++) if (int(password[i]) >= 65 && int(password[i]) <= 90) dem++;
    return dem;
}
bool co_special_char(const std::string& password, int len) {
    for (int i = 0; i < len; i++) if (int(password[i]) == 126 ||int(password[i]) == 94 || int(password[i]) == 95 || int(password[i]) == 63 || int(password[i]) == 64|| int(password[i]) == 42 || int(password[i]) == 33 || (int(password[i]) >= 35 && int(password[i]) <= 38)) return 1;
    return 0;
}
bool co_abandon_special_char(const std::string& password, int len) {
    for (int i = 0; i < len; i++)
        if(int(password[i]) == 32 || int(password[i]) == 44 || int(password[i]) == 46 || int(password[i]) == 47 || int(password[i]) == 92)
            return 1;
    return 0;
}
int so_special_char(const std::string& password, int len){
    int dem = 0;
    for (int i = 0; i < len; i++)
        if (int(password[i]) == 126 || int(password[i]) == 94 ||int(password[i]) == 95  || int(password[i]) == 63 || int(password[i]) == 64|| int(password[i]) == 42 || int(password[i]) == 33 || (int(password[i]) >= 35 && int(password[i]) <= 38))
            dem++;
    return dem;
}
bool co_number(const std::string& password, int len) {
    for (int i = 0; i < len; i++) if (int(password[i]) >= 48 && int(password[i]) <= 57) return 1;
    return 0;
}
int so_number(const std::string& password, int len) {
    int dem = 0;
    for (int i = 0; i < len; i++) if (int(password[i]) >= 48 && int(password[i]) <= 57) dem++;
    return dem;
}
bool all_char(const std::string& password, int len) {
    bool True=1;
    for (int i = 0; i < len; i++) if (int(password[i]) < 97 || int(password[i])>122) {
        True=0;
        break;
    }
    return True;
}
bool all_number(const std::string& password, int len) {
    bool True=1;
    for (int i = 0; i < len; i++) if (int(password[i]) < 48 || int(password[i])>57) {
        True=0;
        break;
    }
    return True;
}

int main() {
    int baseScore = 40;
    int bonus_Excess = 3;
    int bonus_Upper = 4;
    int bonus_Numbers = 5;
    int bonus_Symbols = 5;
    std::string password;
    getline(std::cin,password);
    int len = password.length();
    if (co_abandon_special_char(password, len) || len<8) {
        std::cout << "KhongHopLe"; return 0;
    }
    int number_Excess = len - 8;
    int number_Upper = dem_chu_cai_hoa(password, len);
    int number_Numbers = so_number(password, len);
    int number_Symbols = so_special_char(password, len);
    int bonus_Combo=(co_chu_cai_hoa(password,len)+co_special_char(password,len)+co_number(password,len));
    if (bonus_Combo==2) bonus_Combo=15;
    else if(bonus_Combo==3) bonus_Combo=25;
    int bonus_FlatLower = 0;
    int bonus_FlatNumber = 0;
    if(all_char(password,len)) bonus_FlatLower=-15;
    if(all_number(password,len)) bonus_FlatNumber=-15;
    int score =baseScore + (number_Excess*bonus_Excess) + (number_Upper*bonus_Upper) + (number_Numbers*bonus_Numbers) + (number_Symbols*bonus_Symbols) +bonus_Combo + bonus_FlatLower + bonus_FlatNumber;
    if(score>=50&&score<75) std::cout<<"Vua";
    else if(score>=75&&score<100) std::cout<<"Manh";
    else if(score>=100) std::cout<<"RatManh";
    else std::cout<<"Yeu";
}
