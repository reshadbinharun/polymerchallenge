//
//  main.cpp
//  Sheet
//
//  Created by Md Reshad Bin Harun on 6/12/18.
//  Copyright © 2018 Md Reshad Bin Harun. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;
//Cell Class stores value
class Cell{
private:
    string num;
public:
    //constructor
    Cell(string);
    string get_val();
};

class Sheet{
public:
    Sheet(int col_num, int row_num);
    void print();
    bool set_val(char col, int row, string);
    int get_col_num();
    int get_row_num();
private:
    int col_num;
    int row_num;
    vector<vector<Cell>> sheet;
};
int Sheet::get_col_num() {
    return col_num;
}
string Cell::get_val(){
    return num;
}


//Helper functions:
bool isValidCell(char col, int row, Sheet &s);
//allows checking of each cell to see if the cell contains a valid entry
//dereferences otehr cell references recursively
bool isValidCell(char col, int row, Sheet &s){
    if (col - 'A' <= s.get_col_num() && row < s.get_row_num()){
        string curr = s[row][col-'A'];
        if (curr == "....") return true; //empty
        else if (curr[0] >=0 && curr[0] <= 9){ //number
            return true;
        }
        else if (curr[0]>'A' && curr[0]<'Z'){ //reference to another cell
            char col_curr = curr[0];
            int row_curr = atoi(curr.substr(1).c_str());
            if (col_curr == col && row_curr == row) return false; //self reference
            return isValidCell(col_curr, row_curr, s);
        }
    }
    return false;
}


//IMPLEMENTATIONS
Sheet::Sheet(int col, int row){
    col_num = 0;
    row_num = 0;
    Cell temp("....");
    for (int i = 0; i < row; i++){
        vector<Cell> temp_vec;
        for (int j = 0; j < col_num; j++){
            temp_vec.push_back(temp);
            col_num++;
        }
        sheet.push_back(temp_vec);
        row_num++;
    }
}

bool Sheet::set_val(char col, int row, string val){
    if (isValidCell(col, row, *this)) {
        sheet[row][col-'A'] = val;
        return true;
    }
    return false;
}

void Sheet::print(){
    for (int i = 0; i < row_num; i++){
        for (int j = 0; j < col_num; j++){
            cout << sheet[i][j].get_val() << " ";
        }
        cout << endl;
    }
}
int main(int argc, const char * argv[]) {

    return 0;
}
