/*
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
*/
#include <vector>
#include <iostream>
using namespace std;

void transpose(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for(int i=0;i<n;i++) {
        for(int j=0;j<i;j++) {
            swap(matrix[i][j],matrix[j][i]);
        }
    }
}
void rotate(vector<vector<int>>& matrix) {
    transpose(matrix);
    int n = matrix.size();
    int first = 0, last = n;
    for(int i=0;i<n;i++) {
        first = 0;
        last = n;
        while((first!=last)&&(first!=--last)) {
            swap(matrix[i][first],matrix[i][last]);
            ++first;
        }
    }
}

void printMatrix(const vector<vector<int>>& matrix) {
    for(const vector<int> &row : matrix) {
        for(const int &col : row) {
            cout<<col<<' ';
        }
        cout<<endl;
    }
}

int main() {
    vector<vector<int>> testcase1 {{1,2,3},{4,5,6},{7,8,9}};
    cout<<"90 deg clockwise rotation"<<endl;
    cout<<"Before"<<endl;
    printMatrix(testcase1);
    rotate(testcase1);
    cout<<"After"<<endl;
    printMatrix(testcase1);
}