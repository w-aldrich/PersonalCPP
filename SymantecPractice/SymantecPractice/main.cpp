//
//  main.cpp
//  SymantecPractice
//
//  Created by William Aldrich on 10/11/18.
//  Copyright © 2018 William Aldrich. All rights reserved.
//

#include <iostream>
#include <vector>

long long rowSumOddNumbers(unsigned n){
    //your code here
    int start = n * n -n+1;
    int end = n * n + n-1;
    long sum = 0;
    for(int i = start; i <= end; i+=2) {
        sum += i;
    }
    return sum;
}

long sumTwoSmallestNumbers(std::vector<int> numbers)
{
    long smallest = numbers[0];
    long second = numbers[1];
    if(second < smallest) {
        long temp = smallest;
        smallest = second;
        second = temp;
    }
    for(int i = 2; i < numbers.size(); i++) {
        if(numbers[i] < smallest) {
            long temp = smallest;
            smallest = numbers[i];
            second = temp;
        } else if (numbers[i] < second) {
            second = numbers[i];
        }
    }
    return smallest + second;
}

bool checkCol(char **board, const int currentRow, const int currentCol, const int rowCheck, const int colCheck) {
    return board[currentRow + rowCheck][currentCol + colCheck] == 'o';
}

int count(char **board, const int currentRow, const int currentCol, const int rows, const int cols) {
    
    bool firstCol = currentCol == 0;
    bool lastCol = currentCol == cols;
    bool firstRow = currentRow == 0;
    bool lastRow = currentRow == rows;
    int count = 0;
    // check top
    if(!firstRow) {
        // check up one
        if(checkCol(board, currentRow, currentCol, -1, 0)) {
            count += 1;
        }
        // check left one up one
        if(!firstCol) {
            if(checkCol(board, currentRow, currentCol, -1, -1)) {
                count += 1;
            }
        }
        // check right one up one
        if(!lastCol) {
            if (checkCol(board, currentRow, currentCol, -1, 1)) {
                count += 1;
            }
        }
        
    }
    
    // check left one
    if(!firstCol) {
        if(checkCol(board, currentRow, currentCol, 0, -1)) {
            count += 1;
        }
    }
    // check right one
    if(!lastCol) {
        if (checkCol(board, currentRow, currentCol, 0, 1)) {
            count += 1;
        }
    }
    //check bottom
    if(!lastRow) {
        // check down one
        if(checkCol(board, currentRow, currentCol, 1, 0)) {
            count += 1;
        }
        // check left one down one
        if(!firstCol) {
            if(checkCol(board, currentRow, currentCol, 1, -1)) {
                count += 1;
            }
        }
        // check right one down one
        if(!lastCol) {
            if (checkCol(board, currentRow, currentCol, 1, 1)) {
                count += 1;
            }
        }
    }
    
    std::cout << count;
    return count;
}

void compute_number_mines(char **board, const int rows, const int cols)
{
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; i++) {
            if(board[i][j] == 'R') {
                board[i][j] = count(board, i, j, rows, cols);
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
//    std::cout << "Hello, World!\n";
//    long blah = rowSumOddNumbers(42);
//    std::cout << blah << std::endl;
    
//    std::vector<int> numbers = { 5, 8, 12, 19, 22 };
//    std::vector<int> num2 = {1417941716, 43647678, 1899473111, 1224981293, 12718241};
//    long actual = sumTwoSmallestNumbers(num2);
    
    char **array;
    array = new char *[5];
    for(int i = 0; i <5; i++)
        array[i] = new char[5];
    
    // static init & copy to dynamic matrix
    char mat1[5][5] = {{' ',' ','o','o',' '},
        {' ','o',' ','D',' '},
        {' ','D','R',' ',' '},
        {' ',' ','o','o',' '},
        {' ',' ',' ',' ','o'}};
    
    compute_number_mines(array, 5, 5);
//    std::cout << actual << std::endl;
    return 0;
}
