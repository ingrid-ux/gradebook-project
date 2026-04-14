#include <stdio.h>
#include "student.h"
#include "gradebook.h"
#include "course.h"
#include "system.h"



/* 
1. Add a course(s) to the system - can change later to add more courses,
   but for now we can just have one course in the system to keep it simple.
   We can always expand later if we want to support multiple courses.
      - creates a gradebook for that course
2. Create a student
3. Add student to a course
4. Record grades for a student for that course

- functions
- print list of all grades a student in course
- prints a list of all students in a course
- compute the avg for a student in a course
- prints a list of all courses
- prints a list of all classes
- computes the average for a course
*/

int main(){

   printf("Welcome to the gradebook program!\n");
   System sys;
   systemMenu(&sys);

   // MELANIES CODE
   
   /* int find(//array name, int a){
        int ID = a;
        char grade;
        //search for id in array
        for(int i=0; i<arraysize; i++){
           
        }
        //get grade that corressponds to the id enterd
                grade =;
        //display id number and student grade
        printf("-----------------Student Infromation------------------------");
        printf("Student ID: %d\tGrade: %s",ID, grade);

        }*/
    
}
