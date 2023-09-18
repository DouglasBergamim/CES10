#include <iostream>
#include <string>
#include <sstream>

char** create_matrix(int, std::string);
void write_matrix(char**&, int, std::string);
std::string read_string(std::istream&);
int get_s(std::string);
std::string get_number(std::string);
void write_vertical(char**&, int, int, int);
void write_horizontal(char**&, int, int, int);
char** write_number(char**&, int, char, int);
void made_display(char**&, std::string, int);
int number_size(std::string);
void destroy_matrix(char**, int);


int main(){ 

    std::string comand = read_string(std::cin);
    int s = get_s(comand);
    std::string number = get_number(comand);
    char** matrix = create_matrix(s, number);
    made_display(matrix, number, s);
    write_matrix(matrix, s, number);
    destroy_matrix(matrix, s);
    
}


char** create_matrix(int s, std::string number){
   char** matrix = new char*[2*s+3];
   for(int i = 0; i < 2*s + 3; ++i){
        matrix[i] = new char[number.size()*(s +2)];
   }
    for(int i = 0; i < 2*s + 3; ++ i){
        for(int j = 0; j < number_size(number)*(s + 2); ++j){
            matrix[i][j]= '.';
        }
    }
    return matrix;
}


void write_matrix(char**& matrix, int s, std::string number){
    for(int i = 0; i < 2*s + 3; ++ i){
        for(int j = 0; j < number_size(number)*(s + 2); ++j){
            std:: cout << matrix[i][j];
        }
        std::cout << '\n';    
    }    
}

void write_horizontal(char**& matrix, int s, int colum_number, int row_number){
    for(int j = 1; j < s + 1; ++j){
        matrix[row_number -  1][colum_number - 1 + j]= '-';
    }
}

void write_vertical(char**& matrix, int s, int colum_number, int row_number){
    for(int i = 0; i < s; ++i){
        matrix[row_number + i - 1][colum_number - 1] = '|';
    }
}

char** write_number(char**& matrix, int s, char algarism, int first_colum){
    switch(algarism){
    case '0':
        write_horizontal(matrix, s, first_colum, 1);
        write_horizontal(matrix, s, first_colum, 2*s + 3);
        write_vertical(matrix, s, first_colum, 2);
        write_vertical(matrix, s, first_colum +s+1, 2);
        write_vertical(matrix, s, first_colum, s+3);
        write_vertical(matrix, s,first_colum + s + 1, s + 3);
        break;
    case '1':
        write_vertical(matrix, s, first_colum +s+1, 2);
        write_vertical(matrix, s,first_colum + s + 1, s + 3);
         break;
    case '2':
        write_horizontal(matrix, s, first_colum, 1);
        write_horizontal(matrix, s, first_colum, s +2);
        write_horizontal(matrix, s, first_colum, 2*s + 3);
        write_vertical(matrix, s, first_colum +s+1, 2);
        write_vertical(matrix, s, first_colum, s+3);
        break;
    case '3': 
        write_horizontal(matrix, s,first_colum, 1);
        write_horizontal(matrix, s,first_colum, s +2);
        write_horizontal(matrix, s,first_colum, 2*s + 3);
        write_vertical(matrix, s,first_colum +s +1, 2);
        write_vertical(matrix, s, first_colum +s + 1, s + 3);
        break;
    case '4':    
        write_horizontal(matrix, s, first_colum, s +2);
        write_vertical(matrix, s, first_colum, 2);
        write_vertical(matrix, s, first_colum +s+1, 2);
        write_vertical(matrix, s,first_colum + s + 1, s + 3);
        break;
    case '5':
        write_horizontal(matrix, s, first_colum, 1);
        write_horizontal(matrix, s, first_colum, s +2);
        write_horizontal(matrix, s, first_colum, 2*s + 3);
        write_vertical(matrix, s, first_colum, 2);
        write_vertical(matrix, s,first_colum + s + 1, s + 3);        
        break;
    case '6':
        write_horizontal(matrix, s, first_colum, 1);
        write_horizontal(matrix, s, first_colum, s +2);
        write_horizontal(matrix, s, first_colum, 2*s + 3);
        write_vertical(matrix, s, first_colum, 2);
        write_vertical(matrix, s, first_colum, s+3);
        write_vertical(matrix, s,first_colum + s + 1, s + 3);        
        break;
    case '7':
        write_horizontal(matrix, s, first_colum, 1);
        write_vertical(matrix, s, first_colum +s+1, 2);
        write_vertical(matrix, s,first_colum + s + 1, s + 3);        break;
    case '8':
        write_horizontal(matrix, s, first_colum, 1);
        write_horizontal(matrix, s, first_colum, s +2);
        write_horizontal(matrix, s, first_colum, 2*s + 3);
        write_vertical(matrix, s, first_colum, 2);
        write_vertical(matrix, s, first_colum +s+1, 2);
        write_vertical(matrix, s, first_colum, s+3);
        write_vertical(matrix, s,first_colum + s + 1, s + 3);
        break;
    case '9':
        write_horizontal(matrix, s, first_colum, 1);
        write_horizontal(matrix, s, first_colum, s +2);
        write_horizontal(matrix, s, first_colum, 2*s + 3);
        write_vertical(matrix, s, first_colum, 2);
        write_vertical(matrix, s, first_colum +s+1, 2);
        write_vertical(matrix, s,first_colum + s + 1, s + 3);
        break;
    }
    return matrix;
}

std::string read_string(std::istream& is){
    std:: string line;
    std:: getline(is, line);
    return line;
}

int get_s(std::string line){
    std::stringstream ss{line};
    int s;
    ss >> s;
    return s;
}

std::string get_number(std::string line){
    std::stringstream ss{line};
    int s;
    ss >> s;
    std::string number;
    ss.seekg(1, std::ios::cur);
    ss >> number;

    while(number[0] =='0'){
        number.erase(number.begin());     
    }
   
    return number;
}

int number_size(std::string number){
    if(number ==""){
        return 0;
    }

    number.erase(number.begin());
    return  1+ number_size(number);
}

void made_display(char**& matrix, std::string number, int s){
    for(int i = 0; i < number_size(number); ++i){
        write_number(matrix, s, number[i], 1 + i*(s+2));
    }
}

void destroy_matrix(char** matrix, int s){
    for(int i = 0; i < 2*s+3; ++i){
        delete[] matrix[i];
    }
        delete[] matrix; 
}