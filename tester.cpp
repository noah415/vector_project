#include "vector.h"
#include <iostream>

using namespace std;

int main()
{
    Vector v1;
    Vector v2(3);

    //prints out v1 and v2
    //cout << "v1: "; v1.print();
    cout << "v2: "; v2.print();

    v2.push_back(9);
    cout << "v2: "; v2.print();
    v2.push_back(5);
    cout << "v2: "; v2.print();
    v2.push_back(3);
    cout << "v2: "; v2.print();
    v2.push_back(3);
    cout << "v2: "; v2.print();

    bool equal = v1==v2;
    equal == 0 ? cout << "false\n" : cout << "true\n";
    v1 = v2;
    equal = v1==v2; 
    equal == 0 ? cout << "false\n" : cout << "true\n";
    cout << "v1: "; v1.print();

    
    
    return 0;
}