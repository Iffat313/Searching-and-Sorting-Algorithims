/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

int main()
{
    int x = 5; //created a variable of an integer data type
    
    
    int *ptr1 = new int; //created a pointer to an integer where it stored the memory address of a dynamically allocated memory of an int type. Remember, during the creation of a pointer you also use a *. The memory address that this pointer points to or stores is different in comparison to the memory address of the variable x
    *ptr1 = x; //were using the * on the pointer here as a means to derference the pointer and access the contents stored at the memory address of this pointer
    
    int *ptr2 = &x; //created another pointer to an integer where it points to or stores the memory address of the variable x. In other words, the memory address that this pointer points to or stores is the same memory address of the variable x.
    
    
    cout << "This pointer stores the memory address dynamically allocated of an integer type, not the memeory address of the variable x we created, thus they're different " << ptr1 << endl;
    cout << "Here's the memory address of the variable x we created" << " "<< &x << endl;
    
    cout << endl;
    cout << "This pointer stores the memory address of the variable x we created, thus the memory address of the pointer points to or stores is the same as the " << " " << ptr2 << endl;
    cout << "Here's the memory address of the variable x we created" << " "<< &x;

    return 0;
}