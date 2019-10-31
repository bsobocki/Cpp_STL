#include <iostream>
#include <bits/stdc++.h>
#include <array>

template<std::size_t SIZE>
void show(std::array<int, SIZE>& array);
void show(const int array [], std::size_t size);

int main() {
    int arr [] = { 4, 6, 3, 8, 0, 5, 8, 0, 2, 1, 8, 6};
    int arr2 [] = { 4, 6, 3, 8, 0, 5, 8, 0, 2, 1, 8, 6};
    std::array<int, 8> array = {3, 4, 1, 9, 0 ,5 ,2, 8};
    std::array<int,8> array2 = array;
    std::array<int, 8> array3 = array;
    std::array<int, 8> array4 = array;

    std::cout<<"Array before sorting: "; show(arr, sizeof(arr)/sizeof(arr[0]));

    std::sort(
            arr,
            arr + sizeof(arr)/sizeof(arr[0]));

    std::cout<<"Array after sorting without giving function to compare: "; show(arr, sizeof(arr)/sizeof(arr[0]));

    std::sort(
            arr2,
            arr2 + sizeof(arr2)/sizeof(arr2[0]),
            std::less<>());

    std::cout<<"Array after sorting with 'std::less<>()': "; show(arr2, sizeof(arr2)/sizeof(arr2[0]));

    std::cout<<"\n####\n"<<std::endl;

    std::cout<<"Array before sorting: "; show(array);

    std::sort(
            array.begin(),
            array.end(),
            std::greater<>());

    std::cout<<"Array after descending sorting: "; show(array);

    std::sort(
            array2.begin(),
            array2.end(),
            [](const int & x, const int & y) -> bool {
                return x%2==0 ;
            });

    std::cout<<"Array after sorting by number parity: "; show(array2);

    std::sort(
            array3.begin(),
            array3.end(),
            [](const int & y, const int & x) -> bool {
                return x%2==0 ;
            });

    std::cout<<"Array after sorting by odd numbers: "; show(array3);

    std::sort(
            array4.begin(),
            array4.end(),
            std::less<>());

    std::sort(
            array4.begin(),
            array4.end(),
            [](const int & x, const int & y) -> bool {
                return x%2==0;
            });

    std::cout<<"Array sorting by number parity with sorting both parts: "; show(array4);
    return 0;
}

template<std::size_t SIZE>
void show(std::array<int, SIZE>& array){
    std::cout<<" { ";
    for(unsigned int i=0; i<array.size()-1; i++){
        std::cout<<array[i]<<", ";
    }
    std::cout<<array[array.size()-1]<<" }\n";
}

void show(const int array [], std::size_t size){
    std::cout<<" { ";
    for(unsigned int i=0; i<size-1; i++){
        std::cout<<array[i]<<", ";
    }
    std::cout<<array[size-1]<<" }\n";
}