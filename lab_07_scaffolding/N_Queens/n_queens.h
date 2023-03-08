#include <vector>
#include <iostream>

class NQueens{
    private:
        unsigned int board_size;
        std::vector<std::vector<unsigned int> > * board;
        bool is_valid_row(unsigned int row, unsigned int col);
    public:
        NQueens();
        NQueens(unsigned int n);
        ~NQueens();
        bool solve_rec(int col);
        void display_board();
};
