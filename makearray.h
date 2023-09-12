#ifndef MAKEARRAY_H
#define MAKEARRAY_H

#include <string>

class makearray {
private:
    int intArray[120];
    int size;

public:
    makearray();

    void readFromFile();
    void inArray(int num);
    void modifyValueAtIndex(int index, int newValue);
    void addToArray(int add);
    void replaceZero(int index);
    void printArray();
};

#endif // MAKEARRAY_H
