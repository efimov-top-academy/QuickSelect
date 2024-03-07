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

void partition(int* input, int begin, int end) 
{
    int lt = begin, current = begin, gt = end;
    int partitioningValue = input[begin];

    while (current <= gt) 
    {
        int compareCurrent = compare(input[current], partitioningValue);
        switch (compareCurrent) 
        {
        case -1:
            swap(input, current++, lt++);
            break;
        case 0:
            current++;
            break;
        case 1:
            swap(input, current, gt--);
            break;
        }
    }

    std::cout << "pivot = " << partitioningValue << "\n";
    std::cout << "left = " << lt << "\n";
    std::cout << "right = " << gt << "\n";
}

void partition2(int* input, int begin, int end)
{
    int left{ begin  };
    int current{ begin };
    int right{ end };

    int pivot = input[begin];

    while (current <= right)
    {
        if (input[current] < pivot)
        {
            std::swap(input[current], input[left]);
            current++;
            left++;
        }
        else if (input[current] > pivot)
        {
            std::swap(input[current], input[right]);
            right--;
        }
        else
            current++;
    }

    std::cout << "pivot = " << pivot << "\n";
    std::cout << "left = " << left << "\n";
    std::cout << "right = " << right << "\n";
}

void partition3(int* input, int begin, int end)
{
    int left{ begin };
    int right{ end };
    int pindex = rand() % (end - begin + 1);
    int pivot = input[begin];

    do {
        while (input[left] < pivot) left++;
        while (input[right] > pivot) right--;

        if (left <= right)
        {
            int temp = input[left];
            input[left] = input[right];
            input[right] = temp;

            left++;
            right--;
        }
    } while (left <= right);

    std::cout << "pivot = " << pivot << "\n";
    std::cout << "left = " << left << "\n";
    std::cout << "right = " << right << "\n";
}

int main()
{
    srand(time(nullptr));

    int size{ 19 };
    int* array = new int[size];

    //int array[]{ 7, 9, 8, 2, 7, 5, 7, 2, 9, 3, 8 };

    for (int i{}; i < size; i++)
        array[i] = rand() % 10;

    ArrayPrint(array, size);

    partition(array, 0, size - 1);

    ArrayPrint(array, size);

    
}
