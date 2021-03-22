
#include <string>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include "Direction.hpp"
#include "Board.hpp"

using ariel::Direction;
using namespace std;

namespace ariel{
    Board::Board(){}
    
    string Board::read(unsigned int row,unsigned int column, Direction direction,unsigned int len){
        return "read";
    }

    void Board::post(unsigned int row,unsigned int colum,Direction direction,string str){
        cout<< "post" <<endl;
    }

    void Board::show(){
        cout<< "show" <<endl;
    }
}
