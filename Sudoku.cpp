#include"Sudoku.h"
    Sudoku::Sudoku()
    {
        for(int i=0;i<81;i++)
        {
            map_[i]=0;
        }
        answerNum=0;
    }
    void Sudoku:: readIn()
    {
          for(int i = 0;i<81;++i)
          {
              cin>>map_[i];
          }

    }
    void Sudoku:: print()
    {
        for(int i=0;i<81;i++)
        {
            cout<<Answer[i];
            if(i%9==8) cout<<"\n";
            else cout<<" ";
        }
    }
    void Sudoku:: transform()
    {
        change();
        for(int i=0;i<81;i++)
        {
            cout<<map_[i];
            if(i%9==8) cout<<"\n";
            else cout<<" ";
        }

    }
    void Sudoku:: giveQuestion()
    {
        int sudokuQ[81]={0, 0, 5, 3, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 2, 0, 0, 7, 0, 0, 1, 0, 5, 0, 0, 4, 0, 0, 0, 0, 5, 3, 0, 0, 0, 1, 0, 0, 7, 0, 0, 0, 6, 0, 0, 3, 2, 0, 0, 0, 8, 0, 0, 6, 0, 5, 0, 0, 0, 0, 9, 0, 0, 4, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 9, 7, 0, 0};
        for(int i=0;i<81;i++)
        {
            cout<<sudokuQ[i];
            if(i%9==8) cout<<"\n";
            else cout<<" ";

        }
    }
    void Sudoku:: change()
    {
        srand(time(NULL));
        changeNum(1+rand()%9, 1+rand()%9);
        changeRow(rand()%3, rand()%3);
        changeCol(rand()%3, rand()%3);
        rotate(rand()%101);
        flip(rand()%2);
    }
    void Sudoku:: changeNum(int a, int b)
    {
        for (int i = 0; i < 81; ++i)
        {
            if (map_[i]==a)
            {
                map_[i]=b;
            }
            else
                if (map_[i]==b)
                {
                    map_[i]=a;
                }
        }
    }
    void Sudoku:: changeRow(int a,int b)
    {
        int row_a[27], row_b[27];
        if(a!=b)
        {
            for(int i=0 ; i<27 ;i++)
            {
                row_a[i]=map_[i+a*27];
                row_b[i]=map_[i+b*27];
                map_[i+a*27]=row_b[i];
                map_[i+b*27]=row_a[i];
            }
        }
    }
    void Sudoku:: changeCol(int a, int b)
    {
        int col_a[27], col_b[27];
        if (a!=b)
        {
            for (int i = 0; i < 9; ++i)
            {
                col_a[i]=map_[i*9+a*3];
                col_b[i]=map_[i*9+b*3];

                col_a[i+9]=map_[i*9+a*3+1];
                col_b[i+9]=map_[i*9+b*3+1];

                col_a[i+18]=map_[i*9+a*3+2];
                col_b[i+18]=map_[i*9+b*3+2];
            }
            for(int i=0 ; i<9 ;i++)
            {
                map_[i*9+a*3]=col_b[i];
                map_[i*9+a*3+1]=col_b[i+9];
                map_[i*9+a*3+2]=col_b[i+18];

                map_[i*9+b*3]=col_a[i];
                map_[i*9+b*3+1]=col_a[i+9];
                map_[i*9+b*3+2]=col_a[i+18];
            }
        }
    }
    void Sudoku:: rotate(int n)
    {
        int change_rotate[sudokuSize];
        int a, b, newlocation;

            for(int i=0;i<81;i++)
            {
                newlocation=i;
                for (int j=0;j<4-n%4;j++)
                {
                    newlocation=(8-newlocation/9)+(newlocation%9)*9;

                }
                change_rotate[i]=map_[newlocation];
            }
            for (int i = 0; i < 81; ++i)
            {
                map_[i]=change_rotate[i];
            }
    }
    void Sudoku:: flip(int n)
    {
        int change_flip[sudokuSize];
        int a, b, newlocation;
        for (int i = 0; i < 81; ++i)
        {
            a=i%9;
            b=i/9;
            if(n==1)
            {
                if (a>=4)
                {
                    newlocation=b*9+4-(a-4);
                }
                else
                {
                    newlocation=b*9+4+(4-a);
                }
            }
            else if (n==0)
            {
                if (b>=4)
                {
                    newlocation=a+(4-(b-4))*9;
                }
                else
                {
                    newlocation=a+(4+(4-b))*9;
                }
            }
            change_flip[i]=map_[newlocation];
        }
        for (int i = 0; i < 81; ++i)
        {
            map_[i]=change_flip[i];
        }
    }
    bool Sudoku:: checkSudoku(int i)
    {
        bool result;
            result=checkCell(i);
            if(result==false)
                return false;
            result=checkCol(i);
            if(result==false)
                return false;
            result=checkRow(i);
            if(result==false)
                return false;
        return true;
    }
    bool Sudoku:: checkQuestion()
    {                        for(int i=0;i<81;i++)
                        {
                            cout<<Answer[i];
                            if(i%9==8) cout<<"\n";
                            else cout<<" ";
                        }
        int result;
        for(int i=0;i<81;i++)
        {
            result=checkSudoku(i);
            if(result==false)
            {
                return false;
            }
        }
        return true;

    }
    bool Sudoku:: checkAns(int arr_[])
    {
        for(int i=0;i<sudokuSize;i++)
        {
            if(arr_[i]==0)
                return false;
        }
        return true;
    }
    bool Sudoku:: checkUnity(int arr[])
    {
        int arr_unity[9];

        for(int i=0; i<9; ++i)
            arr_unity[i] = 0;
        for(int i=0; i<9; ++i)
        {
            if (arr[i]-1==-1)
            {
                continue;
            }
            ++arr_unity[arr[i]-1];
            if(arr_unity[arr[i]-1] != 1)//§A­nÀË¬d­è­è§ïªº¨º­Ó®æ§a
                {return false;}
        }
        return true;
    }
    bool Sudoku:: checkRow(int num)
    {
        int Row_num1=(num/9)*9;
        int arr_Row[9];
        bool result;

        for(int i=0;i<9;i++)
        {
            arr_Row[i]=map_[Row_num1+i];
        }
        result=checkUnity(arr_Row);

        return result;
    }
    bool Sudoku:: checkCol(int num)
    {
        int Col_num1=num%9;
        int arr_Col[9];
        bool result;

        for(int i=0;i<9;i++)
        {
            arr_Col[i]=map_[Col_num1+i*9];
        }
        result=checkUnity(arr_Col);

        return result;
    }

    bool Sudoku:: checkCell(int num)
    {
        int Cell_num1=num-(num%9)%3-((num/9)%3)*9;//§ä¨ì¨º®æCellªº¥ª¤W¨¤?

        int arr_Cell[9];
        bool result;

        for(int i=0;i<3;i++)
        {
            arr_Cell[i]=map_[Cell_num1+i];
            arr_Cell[i+3]=map_[Cell_num1+i+9];
            arr_Cell[i+6]=map_[Cell_num1+i+18];
        }

        result=checkUnity(arr_Cell);

        return result;
    }
    int Sudoku:: Fillin(int num, int st)
    {
        for(int i=st;i<=9;i++)
        {
            map_[num]=i;
            if (checkSudoku(num))
            {
                return i;
            }
        }
        return 0;
    }
    void Sudoku:: solve()
    {
        if(checkQuestion()==true)
        {
            solveSudoku();
            if(checkAns(Answer)==true||checkAns(map_)==true)
            {
                if(answerNum>1)
                    cout<<2;
                else
                {
                    cout<<1<<endl;
                    if(checkAns(Answer)==true)
                    {
                        print();
                    }
                    else if(checkAns(map_)==true)
                        for(int i=0;i<81;i++)
                        {
                            cout<<map_[i];
                            if(i%9==8) cout<<"\n";
                            else cout<<" ";
                        }
                }
            }
            else
                cout<<answerNum;
        }
        else
            cout<<answerNum;
    }
    bool Sudoku:: solveSudoku()
    {
        int start;
        static int lastZero=0;
        start = getZero(lastZero);
        lastZero=start;

        if(start == -1)
        {
            for(int i=0;i<=80;i++)
            {
                if(checkSudoku(i)!=true)
                {
                    return false;
                }
            }
                return true;
        }

        else
        {
            int fillNum=0;
            while(fillNum=Fillin(start, fillNum+1))
            {
                setElement(start,fillNum);
                if (solveSudoku())
                {
                    for(int i=0;i<81;i++)
                    {
                        Answer[i]=map_[i];
                    }
                    answerNum++;
                }

            }
            setElement(start,0);    //¥¢±Ñ­nÁÙ­ì
            lastZero=start;
            return false;
        }
    }
    int Sudoku:: getZero(int num)
    {
        for(int i=num;i<sudokuSize;i++)
        {
            if(map_[i]==0)
                return i;
        }
        return -1;
    }
    void Sudoku:: setElement(int index, int value)
    {
        map_[index] = value;
    }
    int Sudoku:: getElement(int index)
    {
        return map_[index];
    }
