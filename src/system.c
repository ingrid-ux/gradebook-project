#include "system.h"
#include <stdlib.h>
#include <stdio.h>


void addCoursetoSystem(System *sys, course c){
    // Before inserting, check if we have enough capacity
    if (sys->courseCount == sys->capacity) {
        //printf("no memory left\n");
        sys->capacity *= 2; // allocating new array with bigger capacity 2x
        sys->courses = realloc(sys->courses, sizeof(course) * sys->capacity); // copy the content from the current array to the new one

        if (sys->courses == NULL) {
            printf("Realloc failed\n");
            exit(1);
        }
    }

    sys->courses[sys->courseCount++] = c;

}

void initSystem(System *sys) {
    sys->courseCount = 0;
    sys->capacity = 1;

    sys->courses = malloc(sizeof(course) * sys->capacity);
    if (sys->courses == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
}

void printListofCoursesInSystem(System *sys){
    for (int i=0; i < sys->courseCount; i++){
        printf("%d: %s\n", i+1, getCourseName(&sys->courses[i]));
    }
}


int selectCourse(System *sys) {
    printf("Select a course:\n");
    printListofCoursesInSystem(sys);
    int choice;
    scanf("%d", &choice);
    if (choice < 1 || choice > sys->courseCount) {
        printf("Invalid choice. Please try again.\n");
        return -1;
    }
    return choice - 1; 
}

void systemMenu(System *sys){
   initSystem(sys);
   int choice; 

   do{
   printf("\n------------------------------------\n");
   printf("System Menu:\n");
   printf("1. Add course to system\n");
   printf("2. Print list of courses in system\n");
   printf("3. Choose a course to manage\n");
   printf("4. Find a student in Course\n");
   printf("5. Delete a student\n");
   printf("6. Exit\n");
   printf("4. Exit\n");
   printf("\n------------------------------------\n");
   scanf("%d", &choice);

 
      switch(choice){
         case 1: {
            printf("________________________________\n");
            printf("1. Adding a course to system\n");
            printf("________________________________\n");
            addCoursetoSystem(sys, addCourse());
            break;
         }
         case 2: {
            printf("List of courses in system:\n");
            printListofCoursesInSystem(sys);
            break;
         }
         case 3: {
            printf("Choose a course to manage:\n");
            int course_num = selectCourse(sys);
            if (course_num >= 0){
               courseMenu(&sys->courses[course_num]);
            }else{
                printf("Course not found.");
                break;
            }
            break;
         }
        case 4: {
            
        }
        case 5: {
            gradebook *gb = &c->gradebook;   // a shortcut pointer to gradebook
            
            int idx = selectStudent(gb);     // select student using shortcut
            
            // check to see if the valid index, delete the student
            if (idx >= 0) {
                deleteStudentFromGradebook(gb, idx);
            }
            break;
        }

         case 6:
            printf("Exiting program...\n");
            printf("Goodbye!\n");
            break;
          /*case 4:
          {
              findstudent(sys->courses, sys->courseCount);
                break;
          }
          */
         default:
            printf("Invalid choice. Please try again.\n");
      }

   }while(choice !=4);

   printf("Gradebook program end\n");

}

void courseMenu(course *c){
    // choosing the course to manage
    int choice;
 
            do{
               printf("\n------------------------------------\n");
               printf("Course Management Menu:\n");
               printf("1. Add student\n");
               printf("2. Print list of students in course\n");
               printf("3. Manage Gradebook\n");
               printf("4. Find Student by ID\n");
               printf("5. Update student name\n");
               printf("6. Manage student's scores\n");
               printf("0. Exit Course Management Menu..\n");
               printf("\n------------------------------------\n");
               scanf("%d", &choice);

               switch(choice){
                  case 1: {
                     // ADD STUDENT - INGRID'S PART COMPLETED
                     student newStudent = addStudent();
                     addStudentToGradebook(&c->gradebook, newStudent);
                     break;
                  }
                  case 2: {
                     // PRINT LIST OF STUDENTS IN COURSE 
                     printf("List of students in course:\n");
                     printListofStudentsInCourse(&c->gradebook);
                     break;
                  }
                  case 3: {
                     // MANAGE GRADEBOOK
                     // - accesses new menu
                     //   -enter homework scores, exam scores, project scores
                     //   - get avg of every score (exams, projects, assignments together)
                     // Support adding x, finding findStudent(), updating 
                     // updateStudent()->what field?, deleting-> deleteStudent(), and 
                     // listing students
                     int student_idx = selectStudent(&c->gradebook);
                     if(student_idx >= 0){
                        studentMenu(&c->gradebook.students[student_idx]);
                     }
                     break;
                    }
                    // MELANIE'S CODE
                   case 4: {
                        
                        break;
                   }
                   case 5: {
                        updateStudentInGradebook(&c->gradebook);
                        break;
                   }
                   case 6: {
                        managingScores(&c->gradebook);
                        break;
                   }
                
                  default:
                     printf("Invalid choice. Please try again.\n");
               }

            }while(choice != 0);

            printf("Exiting course managment menu.. going back to main menu");

}

void studentMenu(student *s){
    int choice;
    do{
        printf("\n------------------------------------\n");
        printf("Student : %s\n", s->name);
        printf("1. Add homework score\n");
        printf("2. Add exam score\n");
        printf("3. Add project score\n");
        printf("4. Get average\n");
        printf("5. Print All Scores of Student: %s\n", s->name);
        printf("0. Return back to Course Management Menu:\n");
        printf("\n------------------------------------\n");
        scanf("%d", &choice);

        switch(choice){
            case 1: 
                addHomeworkScore(s);
                listHomeworkScores(s);
                break;
            case 2:
                addExamScore(s);
                listExamScores(s);
                break;
            case 3:
                addProjectScore(s);
                listProjectScores(s);
                break;
            case 4:
                break;
            case 5:
                //printf("examCount=%d, hwCount=%d, projCount=%d\n", s->examCount, s->homeworkCount, s->projectCount);
                printAllScores(s);
                break;

        }

    } while(choice != 0);
}

