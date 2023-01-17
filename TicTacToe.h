//
// Created by Cyril Wu on 2022/12/26.
//

/*
 * 一個 OOXX 的遊戲需要什麼呢
 * 1) 一個 3 * 3 的方格
 * 2) 每一格可以塗上 O 或 X，因此塗過的地方不能再塗
 * 3) 每一次結束後需要判斷某直的或橫的或斜的有連一直線的獲勝
 * 4) 互相輪流 O 跟 X
 */

#ifndef TIC_TAC_TOE_TICTACTOE_H
#define TIC_TAC_TOE_TICTACTOE_H

#include <iostream>
#include <vector>
#include <display>

using namespace std;

class TicTacToe{
public:
    void O (){
        int x, y;
        cout << "Please input a number x, y from 0 to 2 for O: " << endl;
        cout << "x: ";
        cin >> x;
        cout << "y: ";
        cin >> y;
        if ( x < 0 || x > 2 || y < 0 || y > 2 ){
            cout << "Your input is not in the range" << endl;
            O();
        }
        else if ( vec[x][y] == 'X' || vec[x][y] == 'O' ){
            cout << "The loction is not empty" << endl;
            O();
        }
        else if ( vec[x][y] != 'X' && vec[x][y] != 'O' ){
            vec[x][y] = 'O';
            display( vec );
        }
    }

    void X (){
        int x, y;
        cout << "Please input a number x, y from 0 to 2 for X: " << endl;
        cout << "x: ";
        cin >> x;
        cout << "y: ";
        cin >> y;
        if ( x < 0 || x > 2 || y < 0 || y > 2 ){
            cout << "Your input is not in the range" << endl;
            X();
        }
        else if ( vec[x][y] == 'X' || vec[x][y] == 'O' ){
            cout << "The loction is not empty" << endl;
            X();
        }
        else if ( vec[x][y] != 'X' && vec[x][y] != 'O' ){
            vec[x][y] = 'X';
            display( vec );
        }
    }
    bool win();
    bool draw();
private:
    vector<vector<char>> vec{ 3, vector<char>( 3, ' ' ) };
    vector<vector<bool>> isVisited{ 3, vector<bool>(3, false) };
};

#endif //TIC_TAC_TOE_TICTACTOE_H
