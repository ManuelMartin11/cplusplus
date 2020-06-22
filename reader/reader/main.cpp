//
//  main.cpp
//  reader
//
//  Created by manuel.martin on 06/04/2020.
//  Copyright © 2020 manuel.martin. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    
    string line;
    stringstream ss;
    
    vector<vector<float>> matrix;
    vector<float> row;
    
    float i;
    
    ifstream matrixfile("matrix.txt");
    
    if (matrixfile.is_open()){
        while (getline (matrixfile, line)){
            
            // parse the text line with a stringstream
            // clear the string stream to hold the next line
            ss.clear();
            ss.str("");
            ss.str(line);
            row.clear();
            
            // parse each line and push to the end of the row vector
            // the ss variable holds a line of text
            // ss >> i puts the next character into the i variable.
            // the >> syntax is like cin >> some_value or cout << some_value
            // ss >> i is false when the end of the line is reached
            
            while (ss >> i){
                row.push_back(i);
                if (ss.peek() == ',' || ss.peek() == ' '){
                    ss.ignore();
                }
            }
            matrix.push_back(row);
        }
    }
    matrixfile.close();
    
    for (int row = 0; row < matrix.size(); row++){
        for (int column=0; column < matrix[row].size(); column++){
            cout << matrix[row][column] << " ";
        }
        cout << endl;
    }
    return 0;
}
