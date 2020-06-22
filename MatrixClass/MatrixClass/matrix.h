//
//  matrix.h
//  MatrixClass
//
//  Created by manuel.martin on 09/04/2020.
//  Copyright © 2020 manuel.martin. All rights reserved.
//
#include <vector>

using namespace std;

class Matrix{

    private:
        // size_type is used to specify the data type
        // of the variable pointed. Esta variable asegura que
        // rows o columns pueden almacenar el máximo valor de float
        // posible.
        vector< vector<float> > grid;
        vector<float>::size_type rows;
        vector<float>::size_type columns;
        
    public:
        Matrix(); // Empty constructor
        Matrix(vector<vector<float>>);
        
        void setGrid(vector<vector<float>>);
        
        vector<vector<float>> getGrid();
        vector<float>::size_type getRows();
        vector<float>::size_type getColumns();
        
        void matrix_print();
        Matrix matrix_addition(Matrix);
        Matrix matrix_transpose();
        
};
