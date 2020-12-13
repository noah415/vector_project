#include "vector.h"

using namespace std;

//constructors
Vector::Vector()
/* this is the default constructor. It automatically sets the 
allocated space to 50, the number of doubles to 0, and sets the 
array pointer to an type double array of capacity 50 in heap memory. */
{
    //cout << "created vector with default space\n"; //for testing

    _maxCount = 50;
    _count = 0;
    _arr = new double[50];
}


Vector::Vector(int maxCount)
/* this is the constructor that takes 1 input (capacity of array).
Sets the maxCount to input and sets the capacity of the array 
pointer to the given input.*/
{
    //cout << "created vector with " << maxCount << " space\n"; //for testing

    _maxCount = maxCount;
    _count = 0;
    _arr = new double[maxCount];
}

//destructor
Vector::~Vector()
/* destructor: deletes the array pointer in the heap. */
{
    //cout << "destroyed\n"; //for testing

    delete[] _arr;
}

//overloading operators
Vector& Vector::operator=(Vector &other)
/* copies the members of "other vector" to the current one */
{
    double *trash = _arr;
    delete[] trash;

    _arr = new double[other.capacity()];
    _maxCount = other._maxCount;
    _count = other._count;

    for (int i = 0; i < _count; i++)
    {
        _arr[i] = other._arr[i];
    } 

    return *this;
}

bool Vector::operator==(Vector &other)
{
    if (_count != other._count || _maxCount != other._maxCount) return false;

    for (int i = 0; i < _count; i++)
    {
        if (_arr[i] != other._arr[i]) return false;
    }

    return true;
}






//other methods
int Vector::capacity()
/* returns an int value representing the maximum capacity of the Vector. */
{
    return _maxCount;
}


int Vector::size()
/* returns an int value representing the number of double items in the 
Vector. */
{
    return _count;
}


double Vector::valuAt(int index)
/* returns the double value of the item at index 
inputed in the Vector */
{
    return _arr[index];
}

void Vector::push_back(double item)
/*  if the Vector is not full:
        append item to the vector*/
{
    if (_count < _maxCount) 
    {
        _arr[_count] = item;
    }

    else
    {
        _maxCount = _maxCount*2;

        double *trash = _arr;
        _arr = new double[_maxCount];
        
        for (int i = 0; i < _count; i++) //loops through the old array and copies the 
                                               //old array items to the new array 
        {
            _arr[i] = trash[i];
        }

        _arr[_count] = item;
        delete[] trash;
    }

    _count++;
}

void Vector::changeValeAt(double newVal, int index)
{
    _arr[index] = newVal;
}

void Vector::resize(int space)
{
    if (space < _maxCount && space > 0)
    {
        double *trash = _arr;
        _arr = new double[space];
        _count = space;
        _maxCount = space;
        for (int i = 0; i < space; i++)
        {
            _arr[i] = trash[i];
        }
        delete[] trash;
    }
    else
    {
        double *trash = _arr;
        _arr = new double[space];
        _maxCount = space;
        for (int i = 0; i < _count; i++)
        {
            _arr[i] = trash[i];
        }
        delete[] trash;
    }
}

void Vector::reserve(int space)
{
    if (space > _maxCount)
    {
        double *trash = _arr;
        _arr = new double[space];
        _maxCount = space;
        for (int i = 0; i < _count; i++)
        {
            _arr[i] = trash[i];
        }
        delete[] trash;
    }
}




//----------------------- testing methods ----------------------------

void Vector::print()
/* {{only used for testing}}
Prints the space allocated
for the vector, the number of doubles in the vector,
and prints out the vector itself. */
{
    cout << "space: " << _maxCount << "\tnum items: " << _count << "\tvector: {";

    for (int i = 0; i < _count; i++)
    {
        if (i < _count-1)
        {
            cout << _arr[i] << ",";
        }
        else
        {
            cout << _arr[i];
        }
    }

    cout << "}\n";
}