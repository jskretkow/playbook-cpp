#pragma once

#include <memory>
#include <optional>
#include <utility>
#include <algorithm>
#include <iostream>

namespace sudoku
{

static constexpr int BOARD_SIZE{9};
static constexpr int BOX_SIZE{3};
static constexpr std::array<int, sudoku::BOARD_SIZE> BOARD_VALUES {1, 2, 3, 4, 5, 6, 7, 8, 9};

using Grid = std::array<std::array<int, BOARD_SIZE>, BOARD_SIZE>;

}

namespace tests
{


sudoku::Grid sampleBoard {{
        {0, 0, 5, 9, 1, 0, 3, 0, 8},
        {0, 0, 9, 4, 0, 3, 0, 6, 0},
        {0, 2, 7, 5, 0, 0, 1, 0, 0},
        {0, 3, 0, 0, 0, 0, 2, 0, 1},
        {0, 0, 0, 8, 2, 0, 0, 0, 7},
        {0, 0, 6, 0, 0, 7, 0, 0, 4},
        {0, 0, 0, 0, 8, 0, 0, 0, 0},
        {6, 4, 0, 1, 5, 0, 7, 0, 0},
        {8, 9, 0, 0, 0, 0, 4, 2, 0}
    }};
}

class SudokuSolver
{
    /*
     * Sample sudoku solver in naive way :
     * Recursion + 3 rules to be fullfilled
     * Unique within:
     *     - row
     *     - column
     *     - 3x3 box
     */

    sudoku::Grid grid{0};

public:

    SudokuSolver()
        : grid{tests::sampleBoard}
    {
        std::cout <<"Sudoku Solver BOARD:\n\n";
        showBoard();
    }

    void showBoard()
    {
        for (auto& row : grid){
            for (auto& column : row)
            {
                std::cout << column <<" ";
            }
            std::cout << std::endl;
        }
    }

    bool sudokuRulesPassed(int row, int column, int valueToFill)
    {
        return
            (not isAlreadyInRow(row, valueToFill)) &&
            (not isAlreadyInColumn(column, valueToFill)) &&
            (not isPresentInBox(row - row % sudoku::BOX_SIZE , column - column % sudoku::BOX_SIZE, valueToFill));
    }

    bool solve()
    {
        auto [row, column] = getNextEmpty();

        if (!row)
        {
            std::cout<< "\nSudoku solved! After solving:\n";
            showBoard();
            return true;
        }

        for (auto value : sudoku::BOARD_VALUES)
        {
            if (sudokuRulesPassed(row.value(), column.value(), value))
            {
                grid[row.value()][column.value()] = value;
                if (solve())
                    return true;

                grid[row.value()][column.value()] = 0;
            }
        }
        return false;
    }

private:
    std::pair<std::optional<int>, std::optional<int>>  getNextEmpty()
    {
        for (auto row = 0 ; row < sudoku::BOARD_SIZE ;  ++row)
            for (auto column = 0 ; column < sudoku::BOARD_SIZE ;  ++column)
                if (grid[row][column] == 0)
                    return {row, column};

        return {};
    }

    bool isAlreadyInColumn(const int column, const int value)
    {
        for (const auto& row : grid)
            if (row[column] == value)
                return true;
        return false;
    }

    bool isAlreadyInRow(int checkRow, int value)
    {
        const auto& row = grid.at(checkRow);
        return std::find(row.begin(), row.end(), value) != row.end();
    }

    bool isPresentInBox(int startRow, int startColumn, int value)
    {
        for (auto row = 0; row < sudoku::BOX_SIZE; ++row)
            for (auto column = 0; column < sudoku::BOX_SIZE; ++column)
                if (grid[row + startRow][column + startColumn] == value)
                    return true;
        return false;
    }
};
