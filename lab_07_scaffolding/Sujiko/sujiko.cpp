#include "sujiko.h"

Sujiko::Sujiko() {

}

Sujiko::Sujiko(std::string fname) {
    // Read 4 sum values from file
    // Read file & create board
}

Sujiko::~Sujiko() {

}

bool Sujiko::solve(unsigned int cell){
    // If we placed a number succesfully on every cell, we did it!

    return false;
}

void Sujiko::display_board(){
    for (unsigned int i = 0; i < this->BOARD_SIZE; i++) {
        for (unsigned int j = 0; j < this->BOARD_SIZE; j++){
            std::cout << this->board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main(int argc, char * argv[])
{
    Sujiko s(argv[1]);

    s.solve(0);

    s.display_board();

    return 0;
}
