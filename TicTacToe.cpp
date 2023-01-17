//
// Created by Cyril Wu on 2022/12/27.
//
/* 因為一個井字遊戲有三種的勝利情況
 * 1) 直的三個
 * 2) 橫的三個
 * 3) 正斜三個
 * 4) 負斜三個
 * 所以需要依照不同的狀況來執行不同的 DFS
 */

#include "TicTacToe.h"

int DFS( vector<vector<char>> &vec, int x, int y, int xAdd, int yAdd, char chr, int cnt, vector<vector<bool>> isVisited ){
//    cout << "test2" << endl;
    if ( x < 0 || x > 2 || y < 0 || y > 2 ) // 超過範圍就 return 0
        return cnt;
    if ( !isVisited[x][y] ) {
        isVisited[x][y] = true;
    }
    else if ( isVisited[x][y] ){
        return cnt;
    }
    if ( vec[x][y] != chr  ) // 遇到空白也 return 0
        return cnt;
    if ( vec[x][y] == chr ){
        cnt++;
    }
    cnt = DFS( vec, x + xAdd, y + yAdd, xAdd, yAdd, chr, cnt, isVisited );
    cnt = DFS( vec, x - xAdd, y - yAdd, xAdd, yAdd, chr, cnt, isVisited );
//    cout << "cnt: " << cnt << endl;
    return cnt;
}

bool TicTacToe::win() {
    for ( int i = 0; i < vec.size(); i++ ){
        for ( int j = 0; j < vec[i].size(); j++ ){
            if ( vec[i][j] == 'X' || vec[i][j] == 'O' ){
                bool res = ( DFS( vec, i, j, 1, 0, vec[i][j], 0, isVisited ) == 3 ||
                        DFS( vec, i, j, 0, 1, vec[i][j], 0, isVisited ) == 3 ||
                        DFS( vec, i, j, 1, 1, vec[i][j], 0, isVisited ) == 3 ||
                        DFS( vec, i, j, 1, -1, vec[i][j], 0, isVisited ) == 3
                        );
                if ( res ){
                    string temp;
                    temp += vec[i][j];
                    cout << temp + " is winner, game is over" << endl;
                    return res;
                }
            }
        }
    }
}

bool TicTacToe::draw() {
    bool isDraw = true;
    for ( int i = 0; i < vec.size(); i++ ){
        for ( int j = 0; j < vec[i].size(); j++ ){
            if ( vec[i][j] == ' ' ){
                isDraw = false;
            }
        }
    }
    if ( isDraw )
        cout << "is draw, game is over" << endl;
    return isDraw;
}