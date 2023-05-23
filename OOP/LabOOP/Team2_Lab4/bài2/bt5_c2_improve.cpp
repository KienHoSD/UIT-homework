#include <bits/stdc++.h>
using namespace std;

const string END_OF_SENTENCE = ".!?";
const string NOT_WORD_PUNCT = ",;:()[]{}/\\\"";


/*
DOCUMENTATIONs:

*/

vector<string> split(const string &str, const string delimiter) {
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
string replace(string source, string old_str, string new_str){
    size_t pos = source.find(old_str);
    size_t last_pos = 0;
    while (pos != string::npos){
        source.replace(pos, old_str.length(), new_str);
        last_pos = pos + new_str.length();
        pos = source.find(old_str, last_pos);
    }
    return source;
}
bool string_in_vector(string item, vector<string> arr){
    auto it = find(arr.begin(), arr.end(), item);
    if (it!= arr.end())
        return true;
    else
        return false;
}
bool char_in_string(char item, string arr){
    auto it = find(arr.begin(), arr.end(), item);
    if (it!= arr.end())
        return true;
    else
        return false;
}
class Paragraph {
    private:
        string content;
        vector<vector<string>> words; // this->words vector is 2D string vector that: First dimension is sentence, second dimension is word in sentence. 
    public:
        Paragraph(string content = ""){
            this->content = content;
        }
        Paragraph read_file(string file_place = "./paragraph.txt"){
            ifstream fin(file_place);
            getline(fin, this->content);
            fin.close();
            return *this;
        }
        Paragraph write_file(string file_place = "./paragraph.txt"){
            ofstream fout(file_place);
            fout << this->content;
            fout.close();
            return *this;
        }
        string get_content(){
            return this->content;
        }
        Paragraph set_content(string data){
            this->content = data;
            return *this;
        }
        // This function split this->content to fit into vector. Given that, sentence ends with ".", "!", "?", and words separate each other with " ".
        Paragraph splitContent(){
            string temp = this->content;
            // Keep "!", "?" and "." at last of sentence, so we can use it to rebuild sentence later
            for (char c: END_OF_SENTENCE)
                temp = replace(temp, string(1, c) + " ", " " + string(1,c) + ". "); // For example, temp=replace(temp, "? ", " ?. ")
            // Make some "";:()[]{}/ + backslash" thing removed
            for (char c: NOT_WORD_PUNCT)
                temp = replace(temp, string(1, c), " "); // For example, temp = replace(temp, ",", " ")
            // just " " and "." delimeter to split
            // Remove unncessary "." at last of temp
            temp = temp.substr(0, temp.length()-1);
            vector<string> sentences = split(temp, ". ");
            for (string sentence: sentences){
                vector<string> temp = split(sentence, " ");
                if (temp[0]!=".") // Not include sentence that just has "."
                    words.push_back(split(sentence, " "));
            }
            return *this;
        }
        // As function named, count number of sentences in a paragraph (aka, find number of element in first dimension of this->words)
        int countNumberOfSentences() const {
            return words.size();
        }
        // As function named, count number of words in "index" sentence (aka, find number of element in second dimension at specific index of this->words)
        int countNumberOfWordsInSentence(int index) const{
            if (0 <= index and index < words.size()){
                return words[index].size()-1;
            }
            else
                return -1;
        }
        // As function named, find most occurrence words in paragraph (aka, find element that has max freq. (if there are more than 1 element that has same max freq., list all into return vector) in all elements in this->words).
        vector<string> findMostOccurrenceWordsInParagraph() const {
            unordered_map<string, int> freq;
            for (vector<string> sentence : words) {
                for (string word : sentence) {
                    // Not include "!" and "?"
                    if (!char_in_string(word[0], END_OF_SENTENCE)){
                        transform(word.begin(), word.end(), word.begin(), ::tolower); // convert word to lowercase
                        freq[word]++;
                    }
                }
            }
            vector<string> most_frequent_words;
            int max_freq = 0;
            for (auto it : freq) {
                if (it.second > max_freq) {
                    most_frequent_words.clear();
                    most_frequent_words.push_back(it.first);
                    max_freq = it.second;
                } else if (it.second == max_freq) {
                    most_frequent_words.push_back(it.first);
                }
            }
            return most_frequent_words;
        }
        // As function mentioned, sort words in "index" sentence with ascendant alphabet order (aka, sort vector of string in second dimension at specific index of this->words with ascendant order and some kind of custom function)
        vector<string> sortWordsInSentence(int index) const {
            vector<string> sorted_words = words[index];
            sort(sorted_words.begin(), sorted_words.end()-1, [](const string& a, const string& b) {
                string lower_a = a;
                string lower_b = b;
                transform(lower_a.begin(), lower_a.end(), lower_a.begin(), ::tolower);
                transform(lower_b.begin(), lower_b.end(), lower_b.begin(), ::tolower);
                return lower_a < lower_b;
            });
            return sorted_words;
        }
        Paragraph get_result() const{
            Paragraph res;
            stringstream ss;
            int count = countNumberOfSentences();
            ss << "So cau trong doan van: " << count << "\n";
            for (int i=0; i<count; i++)
                ss << "So tu trong cau " << i+1 << ": " << countNumberOfWordsInSentence(i) << "\n";
            vector<string> mostOccur = findMostOccurrenceWordsInParagraph();
            ss << (mostOccur.size()==1?"Tu ":"Cac tu ") << "xuat hien nhieu nhat trong doan van: ";
            for (int i=0; i<mostOccur.size(); i++){
                if (i != mostOccur.size()-1)
                    ss << mostOccur[i] << ", ";
                else
                    ss << mostOccur[i];
            }
            ss << "\nDoan van sau khi sap xep:\n";
            for (int i=0; i<count; i++){
                vector<string> sorted_sen = sortWordsInSentence(i);
                for (int j=0; j<sorted_sen.size(); j++){
                    ss << sorted_sen[j] << (j==sorted_sen.size()-2?"":" ");
                }
            }
            res.content = ss.str();
            return res;
        }
};

int main(){
    //Paragraph p("Look, outsider! Hello, outsider... Hello? Hello, again? Nice to meet you, outsider!");
    Paragraph p = Paragraph().read_file("./paragraph.txt");
    p.splitContent().get_result().write_file("./result.txt");
    return 0;
}