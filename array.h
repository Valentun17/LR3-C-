#include <iostream>

class Array {
private:
    int initialSize;
    int step;
    int *array;
    int currentIndex;
    int currentSize;

public:
    Array(int initialSize = 10, int step = 10) : initialSize(initialSize), step(step), currentIndex(0), currentSize(0) {
        array = new int[initialSize];
    }

    ~Array() {
        delete[] array;
    }

    void showElements() {
        for (int i = 0; i < currentIndex; ++i) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }

    void expandArray(int size) {
        int newSize = currentSize + size;
        int *tempArray = new int[newSize];
        for (int i = 0; i < currentSize; ++i) {
            tempArray[i] = array[i];
        }
        delete[] array;
        array = tempArray;
        currentSize = newSize;
    }

    int getSize() {
        return currentSize;
    }

    int getElemSize() {
        return currentIndex;
    }

    void setValue(int val) {
        if (currentIndex == currentSize) {
            expandArray(step);
        }
        array[currentIndex++] = val;
    }

    void setArray(int *pArr, int size) {
        if (currentSize < currentIndex + size) {
            expandArray(currentIndex + size - currentSize);
        }
        for (int i = 0; i < size; ++i) {
            array[currentIndex + i] = pArr[i];
        }
        currentIndex += size; // збільшуємо currentIndex на розмір переданого масиву
    }
};