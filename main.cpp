#include <iostream>
#include <ctime>

using namespace std;

template<typename T>
void showArray(T** arr, size_t rows, size_t* array_rows_size)
{
    cout << "Dynamic Array:" << endl;
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
T** delete_row_at_position(T** arr, size_t& rows, size_t*& array_rows_size, size_t position)
{
    if (position < 0 || position >= rows)
    {
        cout << "Invalid position. The row cannot be deleted at the specified position." << endl;
        return arr;
    }

    T** new_arr = new T * [rows - 1];

    for (size_t i = 0; i < position; i++)
    {
        new_arr[i] = arr[i];
    }

    for (size_t i = position + 1; i < rows; i++)
    {
        new_arr[i - 1] = arr[i];
    }

    rows--;

    size_t* new_array_rows_size = new size_t[rows];
    for (size_t i = 0; i < rows; i++)
    {
        new_array_rows_size[i] = array_rows_size[i];
    }

    delete[] arr[position];
    delete[] array_rows_size;
    delete[] arr;

    arr = new_arr;
    array_rows_size = new_array_rows_size;

    return arr;
}

int main()
{
    srand(time(0));

    size_t rows;
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

    size_t position;
    cout << "Enter the position to delete a row: ";
    cin >> position;
    arr_d = delete_row_at_position<int>(arr_d, rows, array_rows_size, position);
    showArray(arr_d, rows, array_rows_size);

    return 0;
}
