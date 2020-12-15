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
    if (_maxCount < 0) throw runtime_error("Invalid input. Capacity should be greater than or equal to 0.");
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
    //creates a new pointer to old array and deletes old array
    double *trash = _arr;
    delete[] trash;

    //creates all new members for Vector Class
    _arr = new double[other.capacity()];
    _maxCount = other._maxCount;
    _count = other._count;

    //copies the array from the "other" vector to the new one
    for (int i = 0; i < _count; i++)
    {
        _arr[i] = other._arr[i];
    } 

    return *this; 
}

bool Vector::operator==(Vector &other)
/* compares each member of each Vector to each other.
if something is not the same then return False */
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

    if (index >= _count || index < 0) throw runtime_error("Invalid input. Input must be the index of a valid item.");
    else return _arr[index];
    
}

void Vector::push_back(double item)
/*  appends item to the vector. if the vector is full 
the vector's space is doubled and the vector is updated*/
{
    if (_count < _maxCount) //if array is not full
    {
        _arr[_count] = item;
    }

    else //if array is full
    {
        _maxCount = _maxCount*2; //makes capacity double the old capacity

        //creates a new pointer to old array and new array
        double *trash = _arr;
        _arr = new double[_maxCount];
        
        //copies items from old array to new one
        for (int i = 0; i < _count; i++)
        {
            _arr[i] = trash[i];
        }

        _arr[_count] = item; //puts the item at the end of the array
        delete[] trash;
    }

    _count++; 
}

void Vector::changeValeAt(double newVal, int index)
/* Changes value at index in the Vector with a new double
that are both specified by the input parameters. */
{
    if (index >= _count || index < 0) throw runtime_error("Invalid input. Input must be the index of a valid item.");
    else _arr[index] = newVal;
}

void Vector::resize(int space)
/* resets the _maxCount to specified int from the input. */
{
    if (space < _maxCount && space > 0) //input is less than capacity
    {
        //creates a new pointer to old array and new array
        double *trash = _arr;
        _arr = new double[space];

        _count = space;
        _maxCount = space;

        //copies needed items from old array to new one
        for (int i = 0; i < space; i++)
        {
            _arr[i] = trash[i];
        }
        delete[] trash;
    }
    else if (space == _count && space < _maxCount) //input is less than capacity and is number of items
    {
        //creates a new pointer to old array and new array
        double *trash = _arr;
        _arr = new double[space];

        _maxCount = space;

        //copies items from old array to new one
        for (int i = 0; i < _count; i++)
        {
            _arr[i] = trash[i];
        }
        delete[] trash;
    }
    else //input is less than 0
    {
        throw runtime_error("Invalid input. Input must be greater then 0.");
    }
    
}

void Vector::reserve(int space)
/* only purpose is to add capacity to the Vector. If the input
is less then the current _maxCount then nothing is changed. */
{
    if (space > _maxCount)
    {
        //creates a new pointer to old array and new array
        double *trash = _arr;
        _arr = new double[space];

        _maxCount = space;

        //copying old array to the new one
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