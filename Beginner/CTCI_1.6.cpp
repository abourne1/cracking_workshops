// given an image represented by nan NxN matrix where each pixel in the image is 4 bytes, 
// write a method to rotate the image by 90 degrees.
// Can you do this in place?

// Hint:
// starategy: go row by row (outer layers down to the central layer)

// TO RUN:
// >> g++ -o 1.6 CTCI_1.6.cpp
// >> ./1.6

#include <iostream>

template <size_t x>
void rotate(int n, int (&matrix)[x][x])
{
    // go layer by layer
    for(int l = 0; l < n/2; l++)
    {
        int start = l;
        int end = n-l-1;
        int temp = 0;

        for(int i = start; i < end; i++)
        {
            // save top left corner
            temp = matrix[start][i];
            // put bottom-left to top-left 
            matrix[start][i] = matrix[end-i+start][start]; 
            // put bottom-right to bottom-left
            matrix[end-i+start][start] = matrix[end][end-i+start];
            // put top-right to bottom-right
            matrix[end][end-i+start] = matrix[i][end];
            // put saved temp to top-right
            matrix[i][end] = temp;
        }   
    }

    return;
}    

template <size_t x>
void printMatrix(int n, int (&matrix)[x][x])
{
    for(int i = 0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(matrix[i][j] < 10)
                std::cout<<matrix[i][j]<<"  ";
            else 
                std::cout<<matrix[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}


int main()
{
    int matrix[4][4] = { 
        1,  2,  3,  4,
        5,  6,  7,  8,
        9, 10, 11, 12,
        13, 14, 15, 16
    };
    std::cout<<"Initially: "<<std::endl;
    printMatrix(4, matrix);
    rotate(4, matrix);
    std::cout<<"\nAfterwards: "<< std::endl;
    printMatrix(4, matrix);


    return 0;
}

// Complexity
// Time complexity O(n^2) which makes sense since we have to go through all of the elements
// to rotate them

// SUGGESTION:
// if you have trouble understanding, please refer to the post here:
// http://stackoverflow.com/questions/25882480/rotating-a-nxn-matrix-in-java
