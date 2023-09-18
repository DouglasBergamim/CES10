#include <iostream>
#include <vector>
#include <cctype>

std:: vector<char> read_vector(std:: istream&);
bool ispalindrome (std:: vector<char>, int, int);

int main() {
        auto v = read_vector(std::cin);
        for(int i = 0; i < v.size(); ++i){
            std:: cout << v[i];
        }
}

std:: vector<char> read_vector(std:: istream& is){
    std:: vector<char> word;
    for(char x; is >> x; ){
        if(isspace(x)){
            break;
        }
        word.push_back(x);
    }
    return word;
}

bool ispalindrome (std:: vector<char> word, int from, int  to) {
    if (from >= to) {
        return true;
    }

    if (word[from] != word[to]) {
        return false;
    }

    else {
        ++from;
        --to;
        return ispalindrome(word, from, to);
    }
}