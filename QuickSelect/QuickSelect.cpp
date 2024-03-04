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

void swap(int* array, int position1, int position2) {
    if (position1 != position2) {
        int temp = array[position1];
        array[position1] = array[position2];
        array[position2] = temp;
    }
}

void partition(int* input, int begin, int end) {
    int lt = begin, current = begin, gt = end;
    int partitioningValue = 7; //input[begin];

    while (current <= gt) {
        int compareCurrent = compare(input[current], partitioningValue);
        switch (compareCurrent) {
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
}


int main()
{
    srand(time(nullptr));

    int size{ 11 };
    //int* array = new int[size];

    int array[]{ 7, 9, 8, 2, 7, 5, 7, 2, 9, 3, 8 };

    /*for (int i{}; i < size; i++)
        array[i] = rand() % 10;*/

    ArrayPrint(array, size);

    //partition(array, 0, 10);

    int left{};
    int current{};
    int right{ size - 1 };
    
    int pivot = 7;

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
        ArrayPrint(array, size);
    }

    std::cout << "left = " << left << "\n";
    std::cout << "right = " << right << "\n";

    /*int left{};
    int right{ size - 1 };
    int pindex = rand() % size;
    int pivot = array[pindex];

    do {
        while (array[left] < pivot) left++;
        while (array[right] > pivot) right--;
        
        int temp = array[left];
        array[left] = array[right];
        array[right] = temp;

        left++;
        right--;
    } while (left < right);

    std::cout << "pindex = " << pindex << "\n";
    std::cout << "pivot = " << pivot << "\n";
    std::cout << "left = " << left << "\n";
    std::cout << "right = " << right << "\n";*/

    ArrayPrint(array, size);
}
