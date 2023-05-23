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

};
class TestCandidate{
public:
    TestCandidate(){
        int n;
        cout<<"Enter the number of candidates: ";
        cin>>n;
        candidates = new Candidate[n]; // Allocate array of Candidate objects
        for(int i=0;i<n;i++){
            cout<<"\nEnter candidate "<<i+1<<" information:\n";
            this->input(candidates[i]);
        }

        cout<<"\nThe list of candidates with total score greater than 15:\n";
        for(int i=0;i<n;i++){
            if(this->getTotalScore(candidates[i]) > 15){
                this->output(candidates[i]);
            }
        }
    }
    ~TestCandidate(){
        delete[] candidates; // Deallocate array of Candidate objects
    }
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

    Candidate *candidates; // Pointer to array of Candidate objects

};

int main(){
    TestCandidate test;
    Candidate *list = test.candidates; // Get pointer to array of Candidate objects
    int n;
    cout<<"Enter the number of candidates: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"\nCandidate "<<i+1<<" information:\n";
        test.output(list[i]);
    }
    return 0;
}
