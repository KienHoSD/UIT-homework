#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
using namespace std;
string DauCuoiCau = "!.?";
string DauKhongLaTu = ",;:()[]{}/\\\"";
vector<string> tachchu(const string& str, const string delimiter) {
    vector<string> tokens;
    string::size_type start = 0;
    string::size_type end = 0;
    while ((end = str.find(delimiter, start)) != string::npos) {
        string token = str.substr(start, end - start);
        if (!token.empty()) {
            tokens.push_back(token);
        }
        start = end + 1;
    }
    string last_token = str.substr(start);
    if (!last_token.empty()) {
        tokens.push_back(last_token);
    }
    return tokens;
}
string thaythe(string source, string old_str, string new_str) {
    size_t pos = source.find(old_str);
    size_t last_pos = 0;
    while (pos != string::npos) {
        source.replace(pos, old_str.length(), new_str);
        last_pos = pos + new_str.length();
        pos = source.find(old_str, last_pos);
    }
    return source;
}
class ThongKeVanBan {
private:
    vector <string> DoanVan;
    vector <string> SoTu;
    vector <string> SoCau;
    vector <int> SoLuongCau;
    vector <int> SoLuongTu;
    vector <string> MostFrequentWord;
    vector <string> SortParagraph;
public:
    ThongKeVanBan();
    void DocSoLuongCau();
    void DocSoLuongTuTrongCau();
    void TuXuatHienNhieuNhat();
    void SapXepDoanVan();
    void XuatFileVanBan();
};
bool Cmp(pair<string, int>& a, pair<string, int>& b) {
    return a.second > b.second;
}
ThongKeVanBan::ThongKeVanBan() {
    // Đọc 1 đoạn văn bản
    ifstream file;
    file.open("test.txt");
    string line;
    string tu;
    //Tách đoạn văn
    while (getline(file, line)) {
        if (line.empty()) break;
        stringstream ss(line);
        while (getline(ss, line, '\n')) {
            DoanVan.push_back(line);
        }
    }
    //Đọc văn bản xong tách thành từng câu:
    vector <string> temp;
    for (int i = 0; i < DoanVan.size(); i++) {
        string test = DoanVan[i] + " .";
        for (char x : DauCuoiCau) test = thaythe(test, string(1, x) + " ", " " + string(1, x) + ". ");
        for (char y : DauKhongLaTu) test = thaythe(test, string(1, y), " ");
        SoCau = tachchu(test, ". ");
        SoCau.pop_back();
        for (string chu : SoCau) {
            stringstream xx(chu);
            string tu;
            while (xx >> tu) if (!ispunct(tu[0])) SoTu.push_back(tu);
        }
    }
}
void ThongKeVanBan::DocSoLuongCau() {
    SoLuongCau.push_back(SoCau.size());
}
void ThongKeVanBan::DocSoLuongTuTrongCau() {
    // Đếm số lượng từ có trong một câu trong một đoạn văn bản
    int WordCount = 0;
    for (int i = 0; i < SoCau.size(); i++) {
        string temp = SoCau[i];
        stringstream ss(temp);
        string WordInSentence;
        while (ss >> WordInSentence) {
            if (!ispunct(WordInSentence[0])) WordCount++;
        }
        SoLuongTu.push_back(WordCount);
        WordCount = 0;
    }
}
void ThongKeVanBan::TuXuatHienNhieuNhat() {
    // Tìm từ xuất hiện nhiều nhất có trong đoạn văn
    vector <string> WordInParagraph;
    string paragraph;
    for (int i = 0; i < SoTu.size(); i++) paragraph += SoTu[i] + " "; // Hợp các từ thành đoạn văn
    stringstream ss(paragraph);
    string TuTrongDoan;
    //Vòng lặp để tách từ ra sau đó biến các từ thành các từ thường
    while (ss >> TuTrongDoan) {
        if (!ispunct(TuTrongDoan[0])) {
            transform(TuTrongDoan.begin(), TuTrongDoan.end(), TuTrongDoan.begin(), ::tolower);
            WordInParagraph.push_back(TuTrongDoan);
        }
    }
    map<string, int> A;
    for (int i = 0; i < WordInParagraph.size(); i++) A[WordInParagraph[i]]++;
    // Sau đó sắp xếp lại theo tần số xuất hiện giảm dần
    vector<pair<string, int>> B;
    for (auto i : A) B.push_back(i);
    sort(B.begin(), B.end(), Cmp);
    int Max = B[0].second;
    string t = B[0].first;
    for (int i = 1; i < B.size(); i++) {
        if (B[i].second == Max) {
            t = t + ", " + B[i].first;
        }
        else {
            MostFrequentWord.push_back(t);
            break;
        }
    }
    WordInParagraph.clear();
    A.clear(); B.clear();
}
void ThongKeVanBan::SapXepDoanVan() {
    string sortedsentence = "";
    vector <string> WordInSentence;
    for (int i = 0; i < SoCau.size(); i++) {
        // Tách từng câu ra thành từng từ trong câu và đưa vào mảng vector để sort theo từ điển
        string tempo = SoCau[i];
        stringstream b(tempo);
        string TuTrong1Cau;
        while (b >> TuTrong1Cau) {
            if (!ispunct(TuTrong1Cau[0])) {
                transform(TuTrong1Cau.begin(), TuTrong1Cau.end(), TuTrong1Cau.begin(), ::tolower);
                WordInSentence.push_back(TuTrong1Cau);
            }
        }
        // Sort theo từ điển xong thì sẽ viết hoa chữ cái đầu của từ đầu tiên trong mảng và thêm dấu chấm vào cuối câu
        sort(WordInSentence.begin(), WordInSentence.end());
        WordInSentence[0].at(0) = toupper(WordInSentence[0].at(0));
        WordInSentence.back() += '.';
        for (int x = 0; x < WordInSentence.size(); x++) sortedsentence += WordInSentence[x] + ' ';
        WordInSentence.clear();
    }
    SortParagraph.push_back(sortedsentence);
}
void ThongKeVanBan::XuatFileVanBan() {
    ofstream output("result.txt");
    for (int i = 0; i < DoanVan.size(); i++) {
        output << "So luong cau: " << SoLuongCau[i] << endl;
        for (int j = 0; j < SoLuongCau[i]; j++) {
            output << "So luong tu cau thu " << j+1 << " : " << SoLuongTu[j] << endl;
        }
        SoLuongTu.erase(SoLuongTu.begin(), SoLuongTu.begin() + SoLuongCau[i]);
        output << "Cac tu xuat hien nhieu nhat: " << MostFrequentWord[i] << endl;
        output << "Doan van sau khi duoc sap xep: " << endl;
        output << SortParagraph[i] << endl;
    }
}
int main()
{
    ThongKeVanBan A;
    A.DocSoLuongCau();
    A.DocSoLuongTuTrongCau();
    A.TuXuatHienNhieuNhat();
    A.SapXepDoanVan();
    A.XuatFileVanBan();
    return 0;
}
