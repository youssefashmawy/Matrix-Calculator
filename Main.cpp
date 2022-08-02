#include <iostream>
#include <math.h>
#include <string>
using namespace std;
const int row=15;
const int col=15;
int used_row_a=0;
int used_col_a=0;
int used_row_b=0;
int used_col_b=0;
long long det(long long array1[][col],int used_rows,int used_col);
void minors(long long array1[][col],int used_rows,int used_col,long double result[][col]);


int main()

{
    cout<<"Please enter dimensions of Matrix A:"<<endl;
    cin>>used_row_a>>used_col_a;
    //intilization of the first matrix
    long long matrix_a[row][col]={0};

    cout<<"Please enter dimensions of Matrix B:"<<endl;
    cin>>used_row_b>>used_col_b;
    //intilization of the second matrix
    long long matrix_b[row][col]={0};

    //values of the first matrix
    cout<<"Please enter values of Matrix A:"<<endl;
    for (int r =0;r<used_row_a;r++)
    {
        for(int c=0;c<used_col_a;c++)
        {
            cin>>matrix_a[r][c];
        }
    }
    //values of the first matrix
    cout<<"Please enter values of Matrix B:"<<endl;
    for (int r =0;r<used_row_b;r++)
    {
        for(int c=0;c<used_col_b;c++)
        {
            cin>>matrix_b[r][c];
        }
    }

    long long matrix_result[row][col]={0};
    long double matrix_result_2[row][col]={0};
    long double matrix_result_3[row][col]={0};


    bool loop_exit=true;


    while(loop_exit)
    {
        cout<<"Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):"<<endl;
        int choice=0;
        cin>>choice;

        if(choice==1)//addition
        {
            if (used_row_b !=used_row_a || used_col_b!=used_col_a)
            {
                cout<<"The operation you chose is invalid for the given matrices."<<endl;
                continue;

            }
            for (int r =0;r<used_row_b;r++)
            {
                for(int c=0;c<used_col_b;c++)
                {
                    matrix_result[r][c]=matrix_a[r][c]+matrix_b[r][c];
                }
            }
            for (int r =0;r<used_row_b;r++)
            {
                for(int c=0;c<used_col_b;c++)
                {

                    cout<<matrix_result[r][c]<<" ";
                    matrix_result[r][c]=0;

                }
                cout<<endl;
            }

        }
        else if(choice==2)//subtraction
        {
            if (used_row_b !=used_row_a || used_col_b!=used_col_a)
            {
                cout<<"The operation you chose is invalid for the given matrices."<<endl;
                continue;

            }
             for (int r =0;r<used_row_b;r++)
            {
                for(int c=0;c<used_col_b;c++)
                {
                    matrix_result[r][c]=matrix_a[r][c]-matrix_b[r][c];
                }
            }
            for (int r =0;r<used_row_b;r++)
            {
                for(int c=0;c<used_col_b;c++)
                {

                    cout<<matrix_result[r][c]<<" ";
                    matrix_result[r][c]=0;
                }
                cout<<endl;
            }
        }
        else if(choice==3)//Multiplication
        {
            if(used_col_a !=used_row_b ||used_col_a==0||used_row_b==0 || used_row_a==0 ||used_col_b==0)
            {
                cout<<"The operation you chose is invalid for the given matrices."<<endl;
                continue;
            }
            for (int r =0;r<used_row_a;r++)
            {
                for(int c=0;c<used_col_b;c++)
                {
                    for(int j=0;j<used_row_b;j++)
                    {
                        matrix_result[r][c]=matrix_result[r][c]+matrix_a[r][j]*matrix_b[j][c];
                    }
                }
            }
            for (int r =0;r<used_row_a;r++)
            {
                for(int c=0;c<used_col_b;c++)
                {

                    cout<<matrix_result[r][c]<<" ";
                    matrix_result[r][c]=0;
                }
                cout<<endl;
            }

        }
        else if (choice==4)//choice 4 A*inverse(B) of dete
        {
            if(used_col_b !=used_row_b ||used_col_b==0 || used_row_b==0||det(matrix_b,used_row_b,used_col_b)==0|| used_col_a !=used_row_b ||used_col_a==0||used_row_b==0 || used_row_a==0 ||used_col_b==0)
            {
                cout<<"The operation you chose is invalid for the given matrices."<<endl;
                continue;
            }
            //double fraction_result[][];
           minors(matrix_b,used_row_b,used_col_b,matrix_result_3);
        //    for (int r =0;r<used_row_a;r++)
        //     {
        //         for(int c=0;c<used_col_b;c++)
        //         {
        //            matrix_result_3[c][r]=(matrix_result[c][r]/float(det(matrix_b,used_row_b,used_col_b)));
        //            if (matrix_result_3[c][r]==-0)
        //            {
        //                matrix_result_3[c][r]=0;
        //            }
        //         }
        //     }
            for (int r=0;r<used_row_a;r++)
            {
                for(int c=0;c<used_col_b;c++)
                {

                    for(int j=0;j<used_row_b;j++)
                    {
                        matrix_result_2[r][c]=matrix_result_2[r][c]+matrix_a[r][j]*matrix_result_3[c][j];
                    }
                    cout<<(long long)round(matrix_result_2[r][c])<<" ";
                    matrix_result_2[r][c]=0;
                }
                cout<<endl;
            }

        }

        else if (choice==5)//choice 6 is the same as choice 5 result of dete
        {
            if(used_col_a !=used_row_a ||used_col_a==0 || used_row_a==0)
            {
                cout<<"The operation you chose is invalid for the given matrices."<<endl;
                continue;
            }
            long long determinant_result=det(matrix_a,used_row_a,used_col_a);
            cout<<determinant_result<<endl;

        }
        else if (choice==6)//choice 6 is the same as choice 5 result of detem
        {
            if(used_col_b !=used_row_b ||used_col_b==0 || used_row_b==0)
            {
                cout<<"The operation you chose is invalid for the given matrices."<<endl;
                continue;
            }
            long long determinant_result=det(matrix_b,used_row_b,used_col_b);
            cout<<determinant_result<<endl;

        }

        else if(choice==7)//quit
        {
            cout<<"Thank you!";
            loop_exit=false;
            // return 0;
        }
    }



}
//i need to cut the big matrix into small submatrices that i can solve using basic math
long long det(long long array1[][col],int used_rows,int used_col)
{
    //final dete result that will be rounded but i dont think that rounding will be necessary
    long long determinant_result=0;
    //The submatrix that will be solved
    long long SubMatrix[row][col];
    //if the matrix 1X1 it should be that number
    if(used_rows==1)
    {
        return array1[0][0];
    }
    //the most general case of solving a matrix that is a 2X2 matrix a 3X3 can be done as well but i dont think thats going to be as efficent as a 2X2 matrix
    if (used_rows==2)
    {
        long long determinant_result_1=(array1[0][0]*array1[1][1]-array1[1][0]*array1[0][1]);
        return determinant_result_1;
    }
    for(int col_row_1=0;col_row_1<used_col;col_row_1++)
    {
        for(int r=1,r_sub=0;r<used_rows;r++)
        {
            for(int c=0,c_sub=0;c<used_col;c++)
            {
                /*the matrix and the submatrix need diff increments as to make my submatrix organized and can be easily calculated but if my submatrix had the same incrementer as the matrix it would have
                random values and impossible to solve as the positions of the random values i wont be able to determine them
                */
                if(c==col_row_1)
                {
                    continue;
                }
                SubMatrix[r_sub][c_sub]=array1[r][c];
                c_sub++;
            }
            r_sub++;
        }
        //for every coulmn there is a submatrix so for example a 3X3 matrix is divided into 3 2X2 submatrices multiplied by the elements of the first row of the matrix
         determinant_result+=array1[0][col_row_1]*det(SubMatrix,used_rows-1,used_col-1)*((long long)pow(-1,col_row_1));
    }

    return  determinant_result;
}

void minors(long long array1[][col],int used_rows,int used_col,long double result[][col])
{
    //final inv result that will be rounded
    //The submatrix that will be solved
    long double det_result=(det(array1,used_rows,used_col));
    long long SubMatrix_1[row][col];
    //if the matrix 1X1 it should be that number
    for (int row_1=0;row_1<used_rows;row_1++)
    {
        for(int col_1=0;col_1<used_col;col_1++)
        {
            int r_sub=0;
            for(int r=0;r<used_rows;r++)
            {
                int c_sub=0;
                for(int c=0;c<used_col;c++)
                {
                /*the matrix and the submatrix need diff increments as to make my submatrix organized and can be easily calculated but if my submatrix had the same incrementer as the matrix it would have
                random values and impossible to solve as the positions of the random values i wont be able to determine them
                */
                    if(c==col_1 || r==row_1)
                    {
                     continue;
                    }
                    SubMatrix_1[r_sub][c_sub]=array1[r][c];


                    c_sub++;
                }
                if(r!=row_1)
                r_sub++;
            }
        //for every coulmn there is a submatrix so for example a 3X3 matrix is divided into 3 2X2 submatrices
        result[row_1][col_1]=(det(SubMatrix_1,used_rows-1,used_col-1)*((long long)pow(-1,row_1+col_1)))/det_result;
        }
    }
}
