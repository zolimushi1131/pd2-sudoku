#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>

using namespace std;

class Sudoku
{
    public:
        Sudoku();
        void readIn();
        void print();
        void transform();
        void giveQuestion();
        void change();
        void changeNum(int a, int b);
        void changeRow(int a,int b);
        void changeCol(int a, int b);
        void rotate(int n);
        void flip(int n);
        bool checkSudoku(int i);
        bool checkQuestion();
        bool checkAns(int arr_[]);
        bool checkUnity(int arr[]);
        bool checkRow(int num);
        bool checkCol(int num);
        bool checkCell(int num);
        int Fillin(int num, int st);
        void solve();
        bool solveSudoku();
        int getZero(int num);
        void setElement(int index, int value);
        int getElement(int index);
        static const int sudokuSize=81;
    private:
    int map_[sudokuSize];
    int answerNum;
    int Answer[sudokuSize];
};
