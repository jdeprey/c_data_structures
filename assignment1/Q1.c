/* CS261- Assignment 1 - Q.1*/
/* Name: Joseph DePrey
 * Date: 4/10/2016
 * Solution description: 1. Write a function struct student* allocate() that allocates memory for 
 ten students and returns the pointer.
  2. Write a function void generate(struct student* students) that generates random IDs and 
  scores for each of the ten students and stores them in the array of students. You can make 
  use of the rand() function to generate random numbers. Ensure that IDs are unique and 
  between 1 and 10 (both inclusive) and score is between 0 and 100(both inclusive).
  3. Write a function void output(struct student* students) that prints the ids and scores 
  of all the students. the output of the function need not to be sorted.
  4. Write a function void summary(struct student* students) that prints the minimum score, 
  maximum score and average score of the ten students.
  5. Write a function void deallocate(struct student* stud) that frees the memory allocated 
  to students. Check that students is not NULL (NULL == 0) before you attempt to free it.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
     struct student* sptr = malloc(10 * (sizeof(struct student)));
     /*return the pointer*/
     return sptr;
}

void generate(struct student* students){
    /*Generate random and unique ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
	/*First value does not need to be checked for uniqueness*/
	students[0].id = (rand() % 10) + 1;
	students[0].score = (rand() % 101);
	
    for(int i = 1; i < 10; i++){
        students[i].id = (rand() % 10) + 1;
        /*Check for unique values among student IDs*/
        for(int j = 0; j < i; j++){
        	if (students[i].id == students[j].id){
        		i--;
        		break;
        	}
        }
        students[i].score = (rand() % 101);
    } 
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
    for(int i = 0; i < 10; i++){
        printf("ID: %d Score: %d\n", students[i].id, students[i].score);
    }
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
    int min = 100, max = 0, sum = 0;
    /* Use double for decimal values */
    double avg = 0; 
    /* Minimum score */
    for(int i = 0; i < 10; i++){
        if(students[i].score < min){
            min = students[i].score;
        }
    }
    /* Maximum score */
    for(int i = 0; i < 10; i++){
        if(students[i].score > max){
            max = students[i].score;
        }
    }
    /* Average score */
    for(int i = 0; i < 10; i++){
        sum += students[i].score;
    }
    avg = sum/10.0;  

     printf("Minimum score: %d\n", min);
     printf("Maximum score: %d\n", max);
     printf("Average score: %4.2f\n", avg);

}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
    if(stud != 0){
        free(stud);
    }
}

int main(){
    struct student* stud = NULL;
    
    /*call allocate*/
    stud = allocate();
    /*call generate*/
    generate(stud);
    /*call output*/
    output(stud);
    /*call summary*/
    summary(stud);
    /*call deallocate*/
    deallocate(stud);
    return 0;
}
