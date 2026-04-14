#include "course.h"
#include "gradebook.h"
#include <string.h>
#include <stdio.h>

course addCourse(){
    course c;
    printf("Creating a new course...\n");
    printf("Enter course name: ");
    scanf(" %49[^\n]", c.course_name);

    initGradebook(&c.gradebook);

    return c;
}

void setCourseName(course *c, char *courseName) {
    // Placeholder for setting the course name
    strcpy(c->course_name, courseName);
}

char *getCourseName(course *c) {
    // Placeholder for getting the course name
    return c->course_name;
}
void  findstudent(//array name, //int s){
        int idnum;
        //ask user for students id
        printf("Enter the students id number: ");
        scanf("%10d",&idnum);
        
        //search for id in array
        for (int i=0; i<s;i++);{
                if (student[i].id == idnum) 
                {
                        printf("Student found.\n");
                        //display students current info
                        printf("-----------------Student Infromation------------------------\n");
                        printf("Student Name: %s\tID: %d\tGrade: %c",student[i].name student[i].id, student[i].grade);
                }
                else{ 
                printf("Student not found..."); 
                }
         
        }
         
        }
