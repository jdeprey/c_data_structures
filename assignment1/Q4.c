/* CS261- Assignment 1 - Q.4*/
/* Name: Joseph DePrey
 * Date: 4/10/2016
 * Solution description: Consider the structure student in Q1.c. Modify the 
 *   above sort(...) function from Q.3 to sort an array of n students based on
 *   their scores in ascending order. The function prototype is void sort(struct 
 *   student* students, int n). The IDs and scores of the students are to be 
 *   generated randomly (see use of rand()). Also you must make sure that IDs 
 *   are unique.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
     /*Sort the n students based on their score*/
     int i, j, tempScore, tempID;
     for(i = 0; i < n; i++){
        for(j = i + 1; j < n; j++){
            if(students[i].score > students[j].score){
                tempScore = students[i].score;
                tempID = students[i].id;
                students[i].score = students[j].score;
                students[i].id = students[j].id;
                students[j].score = tempScore;
                students[j].id = tempID;
            }
        }
     }       
}

int main(){
    /*Declare an integer n and assign it a value.*/
    int n = 10;
    /*Allocate memory for n students using malloc.*/
    struct student *students = malloc(n * (sizeof(struct student)));
    /*Generate random IDs and scores for the n students, using rand().*/
    /*First value does not need to be checked for uniqueness*/
    students[0].id = (rand() % n) + 1;
    students[0].score = (rand() % 101);
    
    for(int i = 1; i < n; i++){
        students[i].id = (rand() % n) + 1;
        /*Check for unique values among student IDs*/
        for(int j = 0; j < i; j++){
            if (students[i].id == students[j].id){
                i--;
                break;
            }
        }
        students[i].score = (rand() % 101);
    } 
    /*Print the contents of the array of n students.*/
    printf("Unsorted\nID\tScore\n");
    for(int i = 0; i < n; i++){
        printf("%d\t%d\n", students[i].id, students[i].score);
    }
    /*Pass this array along with n to the sort() function*/
    sort(students, n); 

    /*Print the contents of the array of n students.*/
    printf("Sorted\nID\tScore\n");
    for(int i = 0; i < n; i++){
        printf("%d\t%d\n", students[i].id, students[i].score);
    }
    return 0;
}
