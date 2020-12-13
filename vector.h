#ifndef VECTOR
#define VECTOR
#include <iostream>

using namespace std;

class Vector
/*creates an array which changes dynamically to the user's preference.
The idea is to use an array pointer to allocate the appropriate amount of 
space for the user. */
{
    private:

        int _maxCount; //the max amount memory available for the double objects
        int _count; //current number of items being stored in array
        double *_arr = nullptr; //null pointer waiting to be assigned to an array pointer of appropriate size

    public:
    //constructors
        Vector();
        Vector(int maxCount);
        //maybe will make a copy constructor
    
    //destructor
        ~Vector();

    //overloaded operators
        Vector& operator=(Vector &other);
        bool operator==(Vector &other);

    //other methods
        void push_back(double item);
        void reserve(int space);
        void resize(int space);
        void changeValeAt(double newVal, int index);

        int capacity();
        int size();

        double valuAt(int index);

    //testing methods
        void print();
};


#endif