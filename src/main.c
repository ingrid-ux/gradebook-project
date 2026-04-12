#include <stdio.h>
#include "student.h"
#include "gradebook.h"
#include "course.h"

/* 
1. Add a course(s) to the gradebook - can change later to add more courses,
   but for now we can just have one course in the gradebook to keep it simple.
   We can always expand later if we want to support multiple courses.
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

int main() {

   /* int opition id; 
        printf("Select from options from list below.\n");
        printf("1.Add \n2.Find a student \n3.Update Students info \n4.Delete \n5.List Student Information\n");
        scanf("%d",&option);
        
        switch(option){
        case 1:
                //calls adding method
                break;
        case 2:
                //calls finding  method
                printf("Enter the students id number: ");
                scanf("%10d",&id)
                find(//array name ,id);
                break;
        case 3:
                //calls updating  method
                break;
        case 4:
                //calls delete method
                break;
        case 5:
                 //calls listing method
                break;
        } */


   printf("Gradebook program end\n");
   course c;
   setCourseName(&c, "Intro to C Programming");
   printf("Course Name: %s\n", getCourseName(&c));
   gradebook gb;
   gb.students = NULL;
   gb.studentCount = 0;

   student s = addStudent();
   addStudentToGradebook(&gb, s);

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
