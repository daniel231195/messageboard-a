#include "doctest.h"
#include <string>

#include <algorithm>
#include "Direction.hpp"
#include "Board.hpp"

using ariel::Direction;
using namespace std;

ariel::Board board;

TEST_CASE("good post & read"){
    // original post , simple test (4)
    board.post(2,4,Direction::Horizontal ,"daniel");
    CHECK(board.read(2,4,Direction::Horizontal,6)=="daniel");
   
    board.post(1,2,Direction::Horizontal ,"abc");
    CHECK(board.read(1,2,Direction::Horizontal,3)=="abc");

    board.post(3,10,Direction::Vertical ,"as");
    CHECK(board.read(3,10,Direction::Vertical,2)=="as");

    board.post(6,2,Direction::Vertical ,"daniel");
    CHECK(board.read(6,2,Direction::Vertical,6)=="daniel");

    //do not exist (2)
    CHECK(board.read(45,99,Direction::Horizontal,1)=="_");
    CHECK(board.read(35,77,Direction::Vertical,1)=="_");

    // change post and check that has changed (2)
    board.post(2,4,Direction::Horizontal ,"left");
    CHECK(board.read(2,4,Direction::Horizontal,4)=="left");

    board.post(6,2,Direction::Vertical ,"sela");
    CHECK(board.read(6,2,Direction::Vertical,4)=="sela");

}
TEST_CASE("bad post & read"){
//Reading the whole word (4)
    board.post(1,10,Direction::Vertical ,"as");
    CHECK(board.read(1,10,Direction::Vertical,2)=="a");
    CHECK(board.read(1,10,Direction::Vertical,1)=="a");
    
    board.post(1,4,Direction::Horizontal ,"abcg");
    CHECK(board.read(1,4,Direction::Horizontal,4)=="abc");
    CHECK(board.read(1,4,Direction::Horizontal,3)=="abc");


//Reading the correct length (2)

    CHECK(board.read(1,3,Direction::Horizontal,6)=="abcg");
    CHECK(board.read(1,10,Direction::Vertical,5)=="asd");

//Reading the change (4)
    board.post(1,1,Direction::Horizontal ,"a");
    board.post(1,1,Direction::Horizontal ,"xsd");
    CHECK(board.read(1,1,Direction::Horizontal,3)=="a");
    CHECK(board.read(1,1,Direction::Horizontal,1)=="a");

    board.post(5,10,Direction::Vertical ,"as");
    board.post(5,10,Direction::Vertical ,"k");
    CHECK(board.read(5,10,Direction::Vertical,2)=="as");
    CHECK(board.read(5,10,Direction::Vertical,1)=="as");

//Incorrect reading (2)
    board.post(99,99,Direction::Horizontal ,"a");
    CHECK(board.read(99,99,Direction::Vertical,1)=="a");  
    board.post(99,99,Direction::Vertical ,"a");
    CHECK(board.read(99,99,Direction::Horizontal,1)=="a");
    
}

TEST_CASE("Invalid input"){ // (12)
    CHECK_THROWS(board.post(-1,10,Direction::Vertical ,"as"));
    CHECK_THROWS(board.post( 1,-10,Direction::Vertical ,"as"));
    CHECK_THROWS(board.post(-1,1,Direction::Horizontal ,"a"));
    CHECK_THROWS(board.post(1,-1,Direction::Horizontal ,"a"));
    CHECK_THROWS(board.post( -1,-10,Direction::Vertical ,"as"));
    CHECK_THROWS(board.post(-1,-1,Direction::Horizontal ,"a"));

    CHECK_THROWS(board.read( 2,-1,Direction::Horizontal ,1));
    CHECK_THROWS(board.read(-1,2,Direction::Horizontal ,1));
    CHECK_THROWS(board.read( 2,-1,Direction::Vertical ,1));
    CHECK_THROWS(board.read(-1,2,Direction::Vertical ,1));
    
    //len check
    CHECK_THROWS(board.read(1,2,Direction::Horizontal ,-1));
    CHECK_THROWS(board.read(1,2,Direction::Horizontal ,0));
}