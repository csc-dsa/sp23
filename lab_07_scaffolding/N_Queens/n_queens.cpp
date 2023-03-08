#include "n_queens.h"

NQueens::NQueens(){
    this->board_size = 0;
    this->board = nullptr;
}

NQueens::~NQueens(){
    delete this->board;
}

NQueens::NQueens(unsigned int n){
    this->board_size = n;

    board = new std::vector<std::vector<unsigned int >>(n, std::vector<unsigned int>(n));
}

bool NQueens::solve_rec(int col){
    //If all queens are placed then return true


    // Attempt to place a Queen in every row in this
    // column, one at a time.

        // Can the Queen safely be placed here?

            // Place the Queen


            // Recursively move to the next column
            // If it returns 1, then a Queen was succesfully
            // placed on that column as well


            // If we did not return in the above statement,
            // we need to remove the queen from the current column
            // and place it on the next row
            // Backgtrack


    // If the queen cannot be placed in any row in this column
    return false;
}

bool NQueens::is_valid_row(unsigned int row, unsigned int col){
    int i, j;

    /* Check this row on left side */
    for (i = 0; i < col; i++)
        if ((*this->board)[row][i]) { return false; }

    /* Check upper diagonal on left side */
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if ((*this->board)[i][j]) { return false; }

    /* Check lower diagonal on left side */
    for (i = row, j = col; j >= 0 && i < this->board_size; i++, j--)
        if ((*this->board)[i][j]) { return false; }

    return true;
}

void NQueens::display_board(){
    for (unsigned int i = 0; i < this->board_size; i++) {
        for (unsigned int j = 0; j < this->board_size; j++){
            std::cout << (*this->board)[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main(int argc, char*argv[])
{
    unsigned int n = std::stoi(argv[1]);

    NQueens Q(n);

    Q.solve_rec(0);

    Q.display_board();

    return 0;
}
