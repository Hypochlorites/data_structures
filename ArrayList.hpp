#include <iostream>

#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

class ArrayList {
    public:
        ArrayList();
        ArrayList(int);
        int get(int);
        void append(int);
        void set(int, int);
        int pop();
        int pop(int);
        int remove(int);
        int getSize();
        int getLength();
        friend std::ostream & operator<<(std::ostream& os, ArrayList& list);

    
    private:
        int size;
        int length;
        int* array;
        void validateIndex(int);
        int* allocate(int);
        void doubleAndMove();
        void halfAndMove();
        void copy(int*, int*, int, int);
        
};

#endif 