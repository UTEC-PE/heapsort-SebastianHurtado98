#include <iostream>
#include <iostream>
#include <random>
#include <assert.h>
#include <string.h>

using namespace std;

#define MIN 100
#define MAX 500

mt19937 rng;

int generateRandomInt(int min, int max);
void printArray(int *array, size_t size);
void heapsort(int* array, size_t size);
void heapify(int* array, int i, int size);
void get_max(int* array, size_t size);
void
bool validate(int* array, size_t size);

int main(int argc, char *argv[]) {
    rng.seed(random_device()());
    cout << "===========================================================" << endl;
    cout << "\tHeapsort Practice" << endl;
    cout << "===========================================================" << endl << endl;

    const int numberOfElements = generateRandomInt(MIN, MAX);
    int *numbers = new int[numberOfElements];
    for (int i = 0; i < numberOfElements; i++) {
        numbers[i] = generateRandomInt(0, 100);
    }

    printArray(numbers, numberOfElements);
    heapsort(numbers, numberOfElements);
    printArray(numbers, numberOfElements);
    assert(validate(numbers, numberOfElements) && "The sort is not ordering all the elements");

    system("read");
    return EXIT_SUCCESS;
}

int generateRandomInt(int min, int max) {
    uniform_int_distribution<mt19937::result_type> distribution(min, max);
    return distribution(rng);
}

void printArray(int *array, size_t size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void get_max(int* array, size_t size){
    for (int i=size/2; i>=1; i--){
        heapify(array, i, size);
    }
}

void heapsort(int* array, size_t size) {
    get_max(array, size);
    for (int i=size; i>=1; i--){
        swap(array[0], array[i]);
        heapify(array, 1, i);
    }
}

void heapify(int* array, int i, int size)
{
    int largest;
    int l = 2 * i;
    int r = (2 * i) + 1;

    if ((l <= size) && (array[l-1] > array[i-1]))
        largest = l;
    else
        largest = i;

    if ((r <= size) && (array[r-1] > array[largest-1]))
        largest = r;

    if (largest != i)
    {
        swap(array[i-1], array[largest-1]);
        heapify(array, largest, size);
    }
}



bool validate(int* array, size_t size) {
    for (int i = 0; i < size - 1; i++) {
        if (array[i] > array[i+1]) {
            return false;
        }
    }
    return true;
}
