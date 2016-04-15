/* CS261- Assignment 1 - Q.3*/
/* Name: Joseph DePrey
 * Date: 4/10/2016
 * Solution description: Write a function void sort(int* numbers, int n) to sort a 
 * 	given array of n integers in ascending order.
 *		1. In the main function, declare an integer n and assign it a value of 20. 
 *		   Allocate memory for an array of n integers using malloc. Fill this array 
 *		   with random numbers, using the c math library random number generator 
 *		   rand(). Print the contents of the array.
 *		2. Pass this array along with n to the sort(...) function above. Print the 
 * 		   contents of the sorted array following the call to sort(...). You may 
 *		   *not* use the C provided sort function (e.g. qsort()).
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void sort(int* number, int n){
     /*Sort the given array number , of length n*/
     int i, j, temp;
     for(i = 0; i < n; i++){
     	for(j = i + 1; j < n; j++){
     		if(number[i] > number[j]){
     			temp = number[i];
     			number[i] = number[j];
     			number[j] = temp;
     		}
     	}
     }     
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;
    
    /*Allocate memory for an array of n integers using malloc.*/
    int *array = malloc(n * sizeof(int));
  
    /*Fill this array with random numbers, using rand().*/
    for(int i = 0; i < n; i++){
    	array[i] = rand();
    }

    /*Print the contents of the array.*/
    printf("\nUnsorted: \n");
    for(int i = 0; i < n; i++){
    	printf("%d \n", array[i]);
    }

    /*Pass this array along with n to the sort() function of part a.*/
    sort(array, n);
    /*Print the contents of the array.*/    
    printf("\nSorted: \n");
    for(int i = 0; i < n; i++){
    	printf("%d \n", array[i]);
    }
    /*Deallocate memory from array*/
    free(array);

    return 0;
}
