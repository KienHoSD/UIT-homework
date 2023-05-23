#include<iostream>
#include<string>
using namespace std;
// khởi tạo lớp Candidate
class Candidate {
private:
    int id; // MSSV, id
    string name; // Họ và tên
    string dob; // Ngày sinh
    float math, literature, english; // điểm 3 môn toán, văn, anh
public:
    // Hàm nhập
    void input() {
        cout << "Enter candidate id: ";
        cin >> id;
        cout << "Enter candidate name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter date of birth (dd/mm/yyyy): ";
        getline(cin, dob);
        while (true){
            cout << "Enter math score: ";
            cin >> math;
            cout << "Enter literature score: ";
            cin >> literature;
            cout << "Enter english score: ";
            cin >> english;
            if (math<=10&&math>=0&&english<=10&&english>=0&&literature<=10&&literature>=0) break;
            cout << "Invalid entry score!\nRetry input valid score\n";
        }
        
    }
    // Hàm xuất
    void output() {
        cout << "Candidate id: " << id << endl;
        cout << "Candidate name: " << name << endl;
        cout << "Date of birth: " << dob << endl;
        cout << "Math score: " << math << endl;
        cout << "Literature score: " << literature << endl;
        cout << "English score: " << english << endl;
    }
    // Hàm lấy tổng điểm 3 môn
    float getTotalScore() {
        return math + literature + english;
    }
};
class TestCandidate {
public:
    static void run(){
        int n; 
        cout << "Enter the number of candidates: ";
        cin >> n; // Nhập số ứng viên Candidate cần xét
        Candidate* list = new Candidate[n]; // Khởi tạo mảng động n phần tử kiểu lớp Candidate
        // Nhập thông tin của n phần tử kiểu lớp Candidate
        for (int i = 0; i < n; i++) { 
            cout << "\nEnter candidate " << i + 1 << " information:\n";
            list[i].input();
        }
        cout << "\nThe list of candidates with total score greater than 15:\n";
        // Xuất thông tin của các Candidate có tổng số điểm 3 môn lớn hơn 15
        for (int i = 0; i < n; i++) { 
            if (list[i].getTotalScore() > 15) {
                list[i].output();
                cout << endl;
            }
        }
    }
};
int main() {
    TestCandidate::run();
    return 0;
}
