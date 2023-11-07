#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

void CreateMatrix(int** matrix, const int rowCount, const int colCount, const int low, const int high, int i, int j);
void PrintMatrix(int** matrix, const int rowCount, const int colCount, int i, int j);
void SortMatrix(int** matrix, const int rowCount, const int colCount, int* sortingKeys, int i, int j);
void CalculateAndReplace(int** matrix, const int rowCount, const int colCount, int& sum, int& count, int i, int j);

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    const int rowCount = 8;
    const int colCount = 5;
    const int low = 4;
    const int high = 51;

    int** matrix = new int* [rowCount];
    for (int i = 0; i < rowCount; ++i) {
        matrix[i] = new int[colCount];
    }

    CreateMatrix(matrix, rowCount, colCount, low, high, 0, 0);
    cout << "Original Matrix:" << endl;
    PrintMatrix(matrix, rowCount, colCount, 0, 0);

    int sortingKeys[] = { 1, -1, -1 };
    SortMatrix(matrix, rowCount, colCount, sortingKeys, 0, 0);

    int sum = 0;
    int count = 0;
    CalculateAndReplace(matrix, rowCount, colCount, sum, count, 0, 0);

    cout << "Modified Matrix:" << endl;
    PrintMatrix(matrix, rowCount, colCount, 0, 0);
    cout << "Sum of elements satisfying the criterion: " << sum << endl;
    cout << "Count of elements satisfying the criterion: " << count << endl;

    for (int i = 0; i < rowCount; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}

void CreateMatrix(int** matrix, const int rowCount, const int colCount, const int low, const int high, int i, int j) {
    if (i >= rowCount) {
        return;
    }

    matrix[i][j] = low + rand() % (high - low + 1);
    j++;
    if (j >= colCount) {
        j = 0;
        i++;
    }

    CreateMatrix(matrix, rowCount, colCount, low, high, i, j);
}

void SortMatrix(int** matrix, const int rowCount, const int colCount, int* sortingKeys, int i, int j) {
    if (i >= rowCount) {
        return;
    }

    int next_i = i;
    int next_j = j + 1;
    if (next_j >= colCount) {
        next_j = 0;
        next_i++;
    }

    SortMatrix(matrix, rowCount, colCount, sortingKeys, next_i, next_j);

    if (i < rowCount - 1 && (sortingKeys[0] == 1 ? (matrix[i][0] > matrix[i + 1][0]) : (matrix[i][0] < matrix[i + 1][0]))) {
        for (int k = 0; k < colCount; k++) {
            int temp = matrix[i][k];
            matrix[i][k] = matrix[i + 1][k];
            matrix[i + 1][k] = temp;
        }
        SortMatrix(matrix, rowCount, colCount, sortingKeys, next_i, next_j);
    }
}

void CalculateAndReplace(int** matrix, const int rowCount, const int colCount, int& sum, int& count, int i, int j) {
    if (i >= rowCount) {
        return;
    }

    if (matrix[i][j] % 2 != 0 || (i % 3 == 0 && j % 3 == 0)) {
        sum += matrix[i][j];
        count++;
        matrix[i][j] = 0;
    }

    j++;
    if (j >= colCount) {
        j = 0;
        i++;
    }

    CalculateAndReplace(matrix, rowCount, colCount, sum, count, i, j);
}

void PrintMatrix(int** matrix, const int rowCount, const int colCount, int i, int j) {
    if (i >= rowCount) {
        return;
    }

    cout << setw(4) << matrix[i][j];

    if (j + 1 < colCount) {
        PrintMatrix(matrix, rowCount, colCount, i, j + 1);
    }
    else {
        cout << endl;
        PrintMatrix(matrix, rowCount, colCount, i + 1, 0);
    }
}
