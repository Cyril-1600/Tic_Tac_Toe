#include <iostream>
#include "TicTacToe.h"

using namespace std;

int main() {
    TicTacToe test;
    do {
        test.O();
        if ( test.win() || test.draw() ){
//            cout << "test1" << endl;
            break;
        }
        test.X();
    } while ( !test.win() && !test.draw() );

    return 0;
}
