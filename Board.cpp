
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
    
    string Board::read( int row, int column, Direction direction, int len){
        return "read";
    }

    void Board::post( int row, int colum,Direction direction,string str){
        cout<< "post" <<endl;
    }

    void Board::show(){
        cout<< "show" <<endl;
    }
}
