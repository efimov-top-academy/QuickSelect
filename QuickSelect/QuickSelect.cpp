#include <iostream>

void ArrayPrint(int* array, int size)
{
    for (int i{}; i < size; i++)
        //std::cout << array[i] << "(" << i << ") ";
        std::cout << array[i] << " ";
    std::cout << "\n";
}

int compare(int num1, int num2) 
{
    if (num1 > num2)
        return 1;
    else if (num1 < num2)
        return -1;
    else
        return 0;
}

void swap(int* array, int position1, int position2) 
{
    if (position1 != position2) 
    {
        int temp = array[position1];
        array[position1] = array[position2];
        array[position2] = temp;
    }
}

void partition(int* array, int begin, int end, int index)
{
    int left{ begin };
    int current{ begin };
    int right{ end };
    int pivot{ array[index] };

    swap(array, begin, index);

    while (current <= right) 
    {
        int compareCurrent = compare(array[current], pivot);
        switch (compareCurrent) 
        {
        case -1:
            swap(array, current++, left++);
            break;
        case 0:
            current++;
            break;
        case 1:
            swap(array, current, right--);
            break;
        }
    }

    std::cout << "pivot = " << pivot << "\n";
    std::cout << "left = " << left << "\n";
    std::cout << "right = " << right << "\n";
}

void partition2(int* array, int begin, int end, int index)
{
    int left{ begin  };
    int current{ begin };
    int right{ end };

    int pivot{ array[index] };
    std::swap(array[begin], array[index]);

    while (current <= right)
    {
        if (array[current] < pivot)
        {
            std::swap(array[current], array[left]);
            current++;
            left++;
        }
        else if (array[current] > pivot)
        {
            std::swap(array[current], array[right]);
            right--;
        }
        else
            current++;
    }

    std::cout << "pivot = " << pivot << "\n";
    std::cout << "left = " << left << "\n";
    std::cout << "right = " << right << "\n";
}

void partition3(int* array, int begin, int end, int index)
{
    int left{ begin };
    int right{ end };
    int pivot{ array[index] };

    do {
        while (array[left] < pivot) left++;
        while (array[right] > pivot) right--;

        if (left <= right)
        {
            std::swap(array[left], array[right]);
            left++;
            right--;
        }
    } while (left <= right);

    std::cout << "pivot = " << pivot << "\n";
    std::cout << "left = " << left << "\n";
    std::cout << "right = " << right << "\n";
}

int quick_select(int* array, int begin, int end, int index)
{
    if (begin == end) return array[begin];

    
}

int main()
{
    srand(time(nullptr));

    int size{ 20 };
    int* array = new int[size];
    int* array2 = new int[size];
    int* array3 = new int[size];

    /*int array[]{ 7, 9, 8, 2, 7, 5, 7, 2, 9, 3, 8 };
    int array2[]{ 7, 9, 8, 2, 7, 5, 7, 2, 9, 3, 8 };
    int array3[]{ 7, 9, 8, 2, 7, 5, 7, 2, 9, 3, 8 };*/

    for (int i{}; i < size; i++)
    {
        int item = rand() % 10;
        array[i] = item;
        array2[i] = item;
        array3[i] = item;
    }
        

    ArrayPrint(array, size);

    int pivot = 0 + rand() % size;
    partition(array, 0, size - 1, pivot);
    ArrayPrint(array, size);

    partition2(array2, 0, size - 1, pivot);
    ArrayPrint(array2, size);

    partition3(array3, 0, size - 1, pivot);
    ArrayPrint(array3, size);
}
