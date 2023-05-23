#include<iostream>
#include<string>
using namespace std;

class Candidate{
private:
    int id;
    string name;
    string dob;
    float math, literature, english;
public:
    friend class TestCandidate;
    void input(Candidate &a){
        cout<<"Enter candidate id: ";
        cin>>a.id;
        cout<<"Enter candidate name: ";
        cin.ignore();
        getline(cin,a.name);
        cout<<"Enter date of birth (dd/mm/yyyy): ";
        getline(cin,a.dob);
        cout<<"Enter math score: ";
        cin>>a.math;
        cout<<"Enter literature score: ";
        cin>>a.literature;
        cout<<"Enter english score: ";
        cin>>a.english;
    }
    void output(const Candidate &a){
        cout<<"Candidate id: "<<a.id<<endl;
        cout<<"Candidate name: "<<a.name<<endl;
        cout<<"Date of birth: "<<a.dob<<endl;
        cout<<"Math score: "<<a.math<<endl;
        cout<<"Literature score: "<<a.literature<<endl;
        cout<<"English score: "<<a.english<<endl;
    }
    float getTotalScore(Candidate a){
        return a.math + a.literature + a.english;
    }
};
class TestCandidate{
public:
    TestCandidate(){
        int n;
        cout<<"Enter the number of candidates: ";
        cin>>n;
        Candidate *list = new Candidate[n];
        for(int i=0;i<n;i++){
            cout<<"\nEnter candidate "<<i+1<<" information:\n";
            this->input(list[i]);
        }

        cout<<"\nThe list of candidates with total score greater than 15:\n";
        for(int i=0;i<n;i++){
            if(this->getTotalScore(list[i]) > 15){
                this->output(list[i]);
            }
        }
    }
};
int main(){
    TestCandidate test;
}
