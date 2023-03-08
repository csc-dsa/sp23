#include "sudoku.h"
#include <sstream>
#include <fstream>
#include <iostream>

Sudoku::Sudoku() {

}

Sudoku::~Sudoku() {

}

Sudoku::Sudoku(std::string f_name) {
    // Generate a board from the give file
}

bool Sudoku::solve() {

    return false;
}

// If this is an empty space & the given number does not exist in the same
// row, column, or box then it will return true.
bool Sudoku::is_valid(unsigned int row, unsigned int col, int num){
    return (this->board)[row][col] == 0
            && !check_row(row, num)
            && !check_col(col, num)
            && !check_box(row - row % 3, col - col % 3, num);
}

bool Sudoku::check_row(unsigned int row, unsigned int num){

    return false;
}

bool Sudoku::check_col(unsigned int col, unsigned int num){

    return false;
}

bool Sudoku::check_box(unsigned int boxStartRow, unsigned int boxStartCol, unsigned int num){

    return false;
}

void Sudoku::display_board(){
    for (unsigned int i = 0; i < this->BOARD_SIZE; i++) {
        for (unsigned int j = 0; j < this->BOARD_SIZE; j++){
            std::cout << (this->board)[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main(int argc, char * argv[])
{
    std::string f_name(argv[1]);

    Sudoku s(f_name);

    s.solve();

    s.display_board();

    return 0;
}
