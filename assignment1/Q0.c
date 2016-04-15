/* CS261- Assignment 1 - Q. 0*/
/* Name: Joseph DePrey
 * Date: 4/10/2016
 * Solution description: 
 1. In the main function, declare an integer, x. Print the address of x (using the address of operator).
Pass x as an argument to a function void fooA(int* iptr).
 2. In fooA(int * iptr), print the value of the integer pointed to by iptr, the address pointed to by iptr, and
the address of iptr itself.
 3. In the main function, following the call to fooA(...), print the value of x.
 */
 
#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
     /*Print the value pointed to by iptr*/
     printf("The value pointed to by iptr is: %d\n", *iptr);
     /*Print the address pointed to by iptr*/
     printf("The address pointed to by iptr is: %p\n", iptr);
     /*Print the address of iptr itself*/
     printf("The address of iptr itself is: %p\n", (void*) &iptr);
}

int main(){
    
    /*declare an integer x*/
    int x;
    /*print the address of x*/
    printf("The address of x is: %p\n", (void*) &x);
    /*Call fooA() with the address of x*/
    fooA(&x);
    /*print the value of x*/
    printf("The value of x is: %d\n", x);
    return 0;
}
