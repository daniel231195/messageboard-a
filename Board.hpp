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

        void post(unsigned int row,unsigned int colum,Direction direction,string str);
        string read(unsigned int row,unsigned int colum,Direction direction,unsigned int len);
        void show();

    };
    

}