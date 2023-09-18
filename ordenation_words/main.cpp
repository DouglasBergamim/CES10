#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

std::vector<std:: string> read_words(std:: istream&);
std:: vector<std::string> ordenationwords(std::vector<std::string>&, int);
std:: string lowercase(std:: string);
void write_list(std:: vector<std::string>&, std::ostream& = std::cout);

int main(){
    auto list = read_words(std:: cin);
    auto ordened_list = ordenationwords(list, list.size());
    write_list(ordened_list, std::cout);  
}

std::vector<std::string> read_words(std:: istream& is){
    std:: vector<std::string> list;
    for(std:: string word; is >> word;){
        list.push_back(word);
    }
    return list;
}

std::string lowercase(std:: string string){//coloca toda a string para letras minusculas
    std::string lowercase_string = "";
    for(char c : string){
        lowercase_string += std::tolower(c);
    }
    return lowercase_string;
}

std:: vector<std::string> ordenationwords(std::vector<std::string>& list, int n){
    if(n <= 1){
        return list;
    }

    else{
        for(int i = 0; i < n - 1; ++i){
            if(lowercase(list[i]) > lowercase(list[i+1])) {
                std::swap(list[i],list[i+1]);
            }
        }
    }     
    return ordenationwords(list, n-1);        
}

void write_list(std::vector<std::string>& list, std::ostream& os){
    for(auto elem : list){
        os << elem << '\n';
    }
}