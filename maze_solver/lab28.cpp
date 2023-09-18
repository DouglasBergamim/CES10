#include <iostream>

int maze_lenght(std::istream&);
int** read_maze(std::istream&, int);
bool solve_maze(int**, int, int, int);
void destroy_matrix(int**, int);

int main(){    
    int n = maze_lenght(std::cin);
    int** maze = read_maze(std::cin, n);
    solve_maze(maze, n-1, n-1, n);
    destroy_matrix(maze, n);   
}

int maze_lenght(std::istream& is){
    int n;
    is >> n;
    return n;
}

int** read_maze(std::istream& is, int n){
    int** maze = new int*[n];
    for(int i = 0; i < n; ++i){
        maze[i] = new int[n];
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            is >> maze[i][j];
        }
    }
    return maze;
}

bool solve_maze(int** maze, int x, int y, int lenght){
    if(x == 0 and y == 0){
        std::cout << x << " " << y << '\n';
        return true;
    }

    maze[x][y] = 1;
    if((y-1) >= 0 and maze[x][y-1] == 0){
        if(solve_maze(maze, x, y-1, lenght)){
            std::cout << x << " " << y << '\n';
            return true;
        }
    }    
    if((x-1) >= 0 and maze[x-1][y] == 0){
        if(solve_maze(maze, x-1, y, lenght)){
            std::cout << x << " " << y << '\n';
            return true;   
        }
    }
    if((y+1) < lenght and maze[x][y+1] == 0){
        if(solve_maze(maze, x, y + 1, lenght)){
            std::cout << x << " " << y << '\n';
            return true;        
        }
    }
    if((x+1) < lenght and maze[x+1][y] == 0){
        if(solve_maze(maze, x+1, y, lenght)){
            std::cout << x << " " << y << '\n';
            return true;       
        }
    }
    return false;
}

void write_maze(int** maze, int lenght){
    for(int i = 0; i < lenght; ++i){
        for(int j = 0; j < lenght; ++j){
            std::cout << maze[i][j];
        }
    std::cout << '\n';
    }
}  

void destroy_matrix(int** matrix, int lenght){
    for(int i = 0; i < lenght; ++i){
        delete[] matrix[i];
    }
    delete[] matrix;
}