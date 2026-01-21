#include<iostream>
#include "insertionSort.hpp"
#include "Date.hpp"

int main(void)
{
    int iArr[5] = {500,400,300,200,100};
    double dArr[5] = {5.5, 4.4, 3.3, 2.2, 1.1};
    Date dateArr[] = {
        Date(20,7,2025),
        Date(20,7,2024),
        Date(30,3,2025),
        Date(20,7,1986),
        Date(1,1,1970)
    };

    show<int>(iArr,5,"Before sort:");
    insertionSort<int>(iArr,5);
    show<int>(iArr,5,"After sort:");

    show<double>(dArr,5,"Before sort:");
    insertionSort<double>(dArr,5);
    show<double>(dArr,5,"After sort:");

    show<Date>(dateArr,5,"Before sort:");
    insertionSort<Date>(dateArr,5);
    show<Date>(dateArr,5,"After sort:");

    return 0;
};