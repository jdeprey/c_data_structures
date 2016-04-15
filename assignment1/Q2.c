/* CS261- Assignment 1 - Q.2*/
/* Name: Joseph DePrey
 * Date: 4/10/2016
 * Solution description: Write a program (Q2.c) with the following:
 * 1. a function int foo(int* a, int *b, int c) which should perform the following computations
 *  1. Set the value of a to twice its original value.
 *  2. Set the value of b to half of its original value.
 *  3. Assign a+b to c.
 *  4. Return the value of c
 * 2. In the main function, declare three integers x,y, and z, and assign them values 5, 6, and 
 *  7 respectively. Print the values of x,y, and z. Call foo(...) appropriately passing x,y, and 
 *  z as arguments and print the returned value. After the function call, print out the values 
 *  of x,y, and z again. Answer the following question in a comment at the bottom of the file: 
 *  Is the return value different than the value of z? Why?
 */
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
    *a *= 2;
    /*Set b to half its original value*/
    *b /= 2;
    /*Assign a+b to c*/
    c = *a + *b;
    /*Return c*/
    return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
    int x = 5,
        y = 6,
        z = 7;
    /*Print the values of x, y and z*/
    printf("x: %d\ny: %d\nz: %d\n", x, y, z);
    /*Call foo() appropriately, passing x,y,z as parameters*/
    foo(&x, &y, z);
    /*Print the value returned by foo*/
    printf("Value returned by foo: %d\n", foo(&x, &y, z));
    /*Print the values of x, y and z again*/
    printf("x: %d\ny: %d\nz: %d\n", x, y, z);
    /*Is the return value different than the value of z?  Why?*/
    return 0;
}
/* Yes, the return value is different because the third parameter of the function foo copies c by 
 * value(makes a copy), instead of using a pointer. Value of z unchanged after calling foo. */    
    
