//
//  matrix.cpp
//  MatrixClass
//
//  Created by manuel.martin on 09/04/2020.
//  Copyright © 2020 manuel.martin. All rights reserved.
//

#include <iostream>
#include "matrix.h"
#include <string>

using namespace std;

Matrix::Matrix(){
    vector<vector <float>> default_grid(10, vector<float>(10, 0.5));
    grid = default_grid;
    rows = grid.size();
    columns = grid[0].size();
};

Matrix::Matrix(vector<vector<float>> x){
    grid = x;
    rows = x.size();
    columns = x[0].size();
};

void Matrix::setGrid(vector<vector<float>> x){
    grid = x;
};

vector<vector <float>> Matrix::getGrid(){
    return grid;
};

vector<float>::size_type  Matrix::getRows(){
    return rows;
};

vector<float>::size_type Matrix::getColumns(){
    return columns;
};

void Matrix::matrix_print(){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            cout << "Column: ";
            cout << to_string(i) + "Row: ";
            cout << j << endl;
            cout << grid[i][j] << endl;
        }
    }
};

Matrix Matrix::matrix_addition(Matrix other){
    // Check that sizes are equal
    if ((rows != other.getRows()) || (columns != other.getColumns())){
        throw std::invalid_argument("Both matrices should have the same sizes");
    }
    
    vector<vector<float>> new_matrix(rows, vector<float>(columns, 0));
    
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            new_matrix[i][j] = grid[i][j] + other.grid[i][j];
        }
    }
    return Matrix(new_matrix);
}
