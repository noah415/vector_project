#include "vector.h"
#include <iostream>

/*A program that loops to update the vector function.
#reaccuring prompt
    Your vector: {<items>}
    Type the wanted char command:
        push_(b)ack
        (r)eserve
        re(s)ize
        (v)alueAt
        (c)hangeValAt
        (l)eave
*/

/*
    practice project:
        - VectorDouble class
        - base type double
        - private dynamic array
        - int maxCount
            + size of dynamic array
        - int count
            + number of array positions being used
        - If adding an element to a full array, create a new one with twice the capacity of the original and copy the elements over
        - Three constructors
            1. Default creates a dynamic array for 50 elements
            2. With 1 argument for the number of elements in the initial dynamic array
            3. Copy constructor
        - Destructor
        - Overloaded = operator
        - Overloaded == operator 
            + values of count and the count array elements must be equal
        - Functions push_back(), capacity(), size(), reserve(), and resize()
            + behave the same way as the functions of the same names for vectors
        - valuAt(i)
            + returns the value of the ith element in the dynamic array
        - changeValeAt(d, i)
            + changes the ith element to d
        - Restrictions where appropriate
*/

using namespace std;

int main()
{
    char command; //creates a variable for the command inputs 
    char choice; //creates variable for the initial question (helps exit the program)
    int startCap; //starting capacity of the vector hello

    //prompts user if they want to proceed
    cout << "\ndo you want to create a vector? (y/n): ";
    cin >> choice;
    if (choice == 'n') return 0;

    //prompts user if they wich to choose a capacity for vector
    cout << "do you want to choose the capacity of your vector? (y/n): ";
    cin >> choice;
    if (choice == 'y')
    {
        cout << "input capacity (int): ";
        cin >> startCap;

        while (startCap < 0)
        {
            cout << "Invalid input. Capacity must be greater than or equal to 0.\n";
            cout << "input capacity (int): ";
            cin >> startCap;
        }
    }
    else startCap = 50; //default capacity for Vector is 50

    Vector vector(startCap); //creates a Vector

    //do-while loop for input commands (manipulation and display of created Vector)
    do {
        
        cout << "\n\ncommands:\n\tpush_(b)ack" << endl << "\t(r)eserve" << endl << "\tre(s)ize" << endl
             << "\t(v)alueAt" << endl << "\t(c)hangeValAt" << endl << "\t(l)eave" << "\n";
        cout << "\nYour vector: ";
        vector.print();
        cout << endl;
        cout << "Type the wanted char command: ";

        cin >> command;

        //push_back command
        if (command == 'b') 
        {
            double input;
            cout << "input (double): ";
            cin >> input;

            vector.push_back(input);
        }

        //reserve command
        else if (command == 'r')
        {
            int input;
            cout << "input space (int): ";
            cin >> input;
            vector.reserve(input);
        }

        //resize command
        else if (command == 's')
        {
            int input;
            cout << "input space (int): ";
            cin >> input;
            try
            {
                vector.resize(input);
            }
            catch(runtime_error e)
            {
                cerr << e.what() << '\n';
            }
        }

        //valuAt command
        else if (command == 'v')
        {
            int input;
            cout << "input index (int): ";
            cin >> input;
            try
            {
                double value = vector.valuAt(input);
                cout << "value at index " << input << " is " << value << endl;
            }
            catch(runtime_error e)
            {
                cerr << e.what() << '\n';
            }
        }

        //changeValeAt command
        else if (command == 'c')
        {
            double input1;
            int input2;
            cout << "input value (double): ";
            cin >> input1;
            cout << "input index (int): ";
            cin >> input2;
            try
            {
                vector.changeValeAt(input1, input2);
            }
            catch(runtime_error e)
            {
                cerr << e.what() << '\n';
            }
            
            
        }


    } while(command != 'l'); //if input command is 'l', break out of loop
    
    return 0;
}