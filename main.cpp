#include <iostream>
#include <vector>
#include <algorithm>

int main()
{

    std::vector<std::vector<char>> game{{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

    std::cout << "=====\n";
    for (std::vector<char> const& line : game) {
        std::cout << "|";
        for (char symbol : line) {
            std::cout << symbol;
        }
        std::cout << "|\n";
    }
    std::cout << "=====\n";

    bool stop{false};
    char curr_move{'X'};

    
    while(!stop) {
        size_t x_coord{3}, y_coord{3};

        bool coordinates_correct{false};
        while (!coordinates_correct) {
            std::cout << "Enter coordinates of " << curr_move << std::endl;
            std::cin >> x_coord >> y_coord;
            if (x_coord > 2 || y_coord > 2) {
                std::cerr << "Wrong coordinates, try again\n";
            }
            else if (game[x_coord][y_coord] != ' ') {
                std::cerr << "This place is already taken, try again\n";
            }
            else {
                coordinates_correct = true;
            }
        }

        game[x_coord][y_coord] = curr_move;

        std::cout << "=====\n";
        for (std::vector<char> const& line : game) {
            std::cout << "|";
            for (char symbol : line) {
                std::cout << symbol;
            }
            std::cout << "|\n";
        }
        std::cout << "=====\n";

        for (std::vector<char> const& line : game) {
            std::string win_line(3, curr_move);
            if (std::equal(std::begin(win_line), std::end(win_line), std::begin(line))) {
                std::cout << curr_move << " win\n";
                stop = true;
            }
        }

        for (size_t j{0}; j < game.size() - 1; ++j) {
            bool all_col_equal{true};
            for (size_t i{0}; i < game[0].size(); ++i) {
                all_col_equal = all_col_equal && (game[i][j] == game[i][j + 1] && game[i][j] == curr_move);
            }
            if (all_col_equal) {
                std::cout << curr_move << " win\n";
                stop = true;
            }
        }

        bool all_diag_equal{true};
        for (size_t ij{0}; ij < game.size() - 1; ++ij) {
            all_diag_equal = all_diag_equal && (game[ij][ij] == game[ij + 1][ij + 1] && game[ij][ij] == curr_move);
        }
        if (all_diag_equal) {
            std::cout << curr_move << " win\n";
            stop = true;
        }

        curr_move = curr_move == 'X' ? 'O' : 'X';
    }
}