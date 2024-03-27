#include <iostream>

int size{ 20 };

template <typename T>
struct Tuple
{
    T first;
    T second;
};

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

Tuple<int> partition(int* array, int begin, int end, int index)
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

    return Tuple<int>{ left, right };
}

Tuple<int> partition2(int* array, int begin, int end, int index)
{
    int left{ begin  };
    int current{ begin };
    int right{ end };

    int pivot{ array[index] };
    std::swap(array[begin], array[index]);

    while (current <= right)
    {
        if (array[current] < pivot)
            std::swap(array[current++], array[left++]);
        /*{
            std::swap(array[current], array[left]);
            current++;
            left++;
        }*/
        else if (array[current] > pivot)
            std::swap(array[current], array[right--]);
        /*{
            std::swap(array[current], array[right]);
            right--;
        }*/
        else
            current++;
    }

    std::cout << "pivot = " << pivot << "\n";
    std::cout << "left = " << left << "\n";
    std::cout << "right = " << right << "\n";

    return Tuple<int>{ left, right };

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

    int pivot = begin + rand() % (end - begin + 1);
    auto range = partition(array, begin, end, pivot);
    ArrayPrint(array, size);

    if (index >= range.first && index <= range.second)
        return array[index];
    if (index < range.first)
        return quick_select(array, begin, range.first - 1, index);
    if (index > range.second)
        return quick_select(array, range.second + 1, end, index);
}

void sort_bubble(int* array, int size)
{
    for (int i{}; i < size; i++)
        for (int j{ size - 1 }; j > i; j--)
            if (array[j] < array[j - 1])
                std::swap(array[j], array[j - 1]);
}


int main()
{
    srand(time(nullptr));

    
    int* array = new int[size];
    int* array2 = new int[size];
    int* array3 = new int[size];

    /*int array[]{ 7, 9, 8, 2, 7, 5, 7, 2, 9, 3, 8 };
    int array2[]{ 7, 9, 8, 2, 7, 5, 7, 2, 9, 3, 8 };
    int array3[]{ 7, 9, 8, 2, 7, 5, 7, 2, 9, 3, 8 };*/

    for (int i{}; i < size; i++)
    {
        int item = rand() % 20;
        array[i] = item;
        array2[i] = item;
        array3[i] = item;
    }
        

    ArrayPrint(array, size);

    /*int pivot = 0 + rand() % size;
    partition(array, 0, size - 1, pivot);
    ArrayPrint(array, size);

    partition2(array2, 0, size - 1, pivot);
    ArrayPrint(array2, size);*/

    /*partition3(array3, 0, size - 1, pivot);
    ArrayPrint(array3, size);*/

    int result = quick_select(array, 0, size - 1, size / 2);
    std::cout << "middle = " << result << "\n";
    ArrayPrint(array, size);

    std::cout << "----------\n";
    sort_bubble(array3, size);
    ArrayPrint(array3, size);
    std::cout << "middle = " << array3[size / 2] << "\n";
}
