#include <iostream>
#include <ctime>

using namespace std;

template<typename T>
void showArray(T** arr, size_t rows, size_t* array_rows_size)
{
    cout << "Array dynamic: " << endl;
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < array_rows_size[i]; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

template<typename T>
T** add_new_top_row(T** arr, size_t& rows, size_t*& array_rows_size, size_t new_row_size)
{

    T** new_arr = new T * [rows + 1];

    new_arr[0] = new T[new_row_size];
    for (size_t i = 0; i < new_row_size; i++)
    {
        new_arr[0][i] = rand() % 10;
    }

    for (size_t i = 0; i < rows; i++)
    {
        new_arr[i + 1] = arr[i];
    }

    rows++;

    size_t* new_array_rows_size = new size_t[rows];
    new_array_rows_size[0] = new_row_size;
    for (size_t i = 1; i < rows; i++)
    {
        new_array_rows_size[i] = array_rows_size[i - 1];
    }

    delete[] arr;
    delete[] array_rows_size;

    arr = new_arr;
    array_rows_size = new_array_rows_size;

    return arr;
}

int main()
{
    srand(time(0));

    size_t rows, new_size;
    cout << "Enter the number of rows: ";
    cin >> rows;
    size_t* array_rows_size = new size_t[rows];
    int** arr_d = new int* [rows];
    for (size_t i = 0; i < rows; i++)
    {
        cout << "Enter the size of row " << i + 1 << ": ";
        cin >> array_rows_size[i];
        arr_d[i] = new int[array_rows_size[i]];
        for (size_t j = 0; j < array_rows_size[i]; j++)
        {
            arr_d[i][j] = rand() % 10;
        }
    }
    showArray(arr_d, rows, array_rows_size);
    cout << endl << endl;

    cout << "Enter the size of the new row: ";
    cin >> new_size;
    arr_d = add_new_top_row<int>(arr_d, rows, array_rows_size, new_size);
    showArray(arr_d, rows, array_rows_size);

    return 0;
}