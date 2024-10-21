
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void CreateRow(int** a, const int rowNo, const int n, const int Low, const int High, int colNo);
void CreateMatrix(int** a, const int k, const int n, const int Low, const int High, int rowNo);
void PrintRow(int** a, const int rowNo, const int n, int colNo);
void PrintMatrix(int** a, const int k, const int n, int rowNo);
int FindMinInRow(int* row, const int n, int colNo);
int FindMaxOfMinRows(int** a, const int k, const int n, int rowNo, int maxMin);

int main()
{
    srand((unsigned)time(NULL));

    int k, n;
    cout << "Enter number of rows (k): "; cin >> k;
    cout << "Enter number of columns (n): "; cin >> n;

    int Low = 7;
    int High = 65;

    int** a = new int* [k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];

 
    CreateMatrix(a, k, n, Low, High, 0);
    PrintMatrix(a, k, n, 0);

  
    int maxMinElement = FindMaxOfMinRows(a, k, n, 0, a[0][0]);
    cout << "Max of the minimum elements = " << maxMinElement << endl;

    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void CreateRow(int** a, const int rowNo, const int n, const int Low, const int High, int colNo)
{
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < n - 1)
        CreateRow(a, rowNo, n, Low, High, colNo + 1);
}

void CreateMatrix(int** a, const int k, const int n, const int Low, const int High, int rowNo)
{
    CreateRow(a, rowNo, n, Low, High, 0);
    if (rowNo < k - 1)
        CreateMatrix(a, k, n, Low, High, rowNo + 1);
}

void PrintRow(int** a, const int rowNo, const int n, int colNo)
{
    cout << setw(4) << a[rowNo][colNo];
    if (colNo < n - 1)
        PrintRow(a, rowNo, n, colNo + 1);
    else
        cout << endl;
}

void PrintMatrix(int** a, const int k, const int n, int rowNo)
{
    PrintRow(a, rowNo, n, 0);
    if (rowNo < k - 1)
        PrintMatrix(a, k, n, rowNo + 1);
}

int FindMinInRow(int* row, const int n, int colNo)
{
    if (colNo == n - 1)
        return row[colNo];
    int minInRow = FindMinInRow(row, n, colNo + 1);
    return row[colNo] < minInRow ? row[colNo] : minInRow;
}

int FindMaxOfMinRows(int** a, const int k, const int n, int rowNo, int maxMin)
{
    int minInRow = FindMinInRow(a[rowNo], n, 0);
    if (minInRow > maxMin)
        maxMin = minInRow;
    if (rowNo == k - 1)
        return maxMin;
    return FindMaxOfMinRows(a, k, n, rowNo + 1, maxMin);
}
