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
T** add_row_at_position(T** arr, size_t& rows, size_t*& array_rows_size, size_t position, size_t new_row_size)
{
    if (position < 0 || position > rows)
    {
        cout << "Invalid position. The row cannot be added at the specified position." << endl;
        return arr;
    }

    T** new_arr = new T * [rows + 1];

    // Створюємо та заповнюємо новий рядок
    new_arr[position] = new T[new_row_size];
    for (size_t i = 0; i < new_row_size; i++)
    {
        new_arr[position][i] = rand() % 10;
    }

    // Копіюємо рядки до нового масиву перед вказаною позицією
    for (size_t i = 0; i < position; i++)
    {
        new_arr[i] = arr[i];
    }

    // Копіюємо рядки після вказаної позиції
    for (size_t i = position; i < rows; i++)
    {
        new_arr[i + 1] = arr[i];
    }

    // Збільшуємо кількість рядків в масиві
    rows++;

    // Оновлюємо розміри рядків
    size_t* new_array_rows_size = new size_t[rows];
    for (size_t i = 0; i < position; i++)
    {
        new_array_rows_size[i] = array_rows_size[i];
    }
    new_array_rows_size[position] = new_row_size;
    for (size_t i = position + 1; i < rows; i++)
    {
        new_array_rows_size[i] = array_rows_size[i - 1];
    }

    // Видаляємо старі масиви та розміри рядків
    delete[] arr;
    delete[] array_rows_size;

    // Оновлюємо вказівники на масиви та розміри рядків
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

    size_t position;
    cout << "Enter the position to add a new row: ";
    cin >> position;
    cout << "Enter the size of the new row: ";
    cin >> new_size;
    arr_d = add_row_at_position<int>(arr_d, rows, array_rows_size, position, new_size);
    showArray(arr_d, rows, array_rows_size);

    return 0;
}
