#include <iostream>

#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

template <typename T>
class ArrayList;

template <typename T>
std::ostream& operator<<(std::ostream& os, const ArrayList<T>& list);

template <typename T> 
class ArrayList {
    public:
        ArrayList<T>();
        ArrayList(int);
        T get(int);
        void append(T);
        void set(int, int);
        T pop();
        T pop(int);
        T remove(int);
        int getSize();
        int getLength();
        friend std::ostream& operator<< <T>(std::ostream& os, const ArrayList<T>& list);

    
    private:
        int size;
        int length;
        T* array;
        void validateIndex(int);
        T* allocate(int);
        void doubleAndMove();
        void halfAndMove();
        void copy(T*, T*, int, int);
        
};

#endif 
