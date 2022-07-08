#include <iostream>
#include "BinaryTree.h"
#include "Functions.h"

int main()
{
    srand(time(0));

    const int arrSize = 10;

    int* arr = new int[arrSize];
    generateArray(arr, arrSize, 1, 30);
    printArray(arr, arrSize);
    std::cout << "\n";

    BinaryTree br(arr, arrSize);
    br.printStraight();
    br.printReverse();
    br.printSymmetrical(); 

    delete[] arr;
}
