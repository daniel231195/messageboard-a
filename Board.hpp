#include "Direction.hpp"
using ariel::Direction;
#include <string>
using namespace std;


namespace ariel{

    class Board
    {
    private:
        /* data */
    public:
        Board(/* args */);

        void post( int row, int colum,Direction direction,string str);
        string read( int row, int colum,Direction direction, int len);
        void show();

    };
    

}