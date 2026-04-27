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
void findstudent(){
        char subject[50];
        int key;
        //ask for course name to search for student in
        printf("Enter the course you want to look for a student in: ");
        scanf("%[^\n]s",&subject);
        
        //first check if course exsits 
        // if it does ask for id, if it doesn't return to main menu
      for (int i=0; i<//course array len; i++)
      {
        if(subjet == course[i].course_name)
            print("Course found...)"    
        else 
            printf("Course not found... returning...");
            return;
      }
        //asking user for students id(key)
        // used id for key incase their are students whith same name or name gets missspelled
        int key;
        printf("Enter the students id number: ");
        scanf("%10d",&key);
        //access course enter and look for student in course 
        for (int i=0; i<//student array len;i++);
          {
                if (student[i].id == key) 
                {
                        printf("Student found.\n");
                        //display students current info
                        printf("-----------------Student Infromation------------------------\n");
                        printf("Student Name: %s\n",s->name);
                        print("ID: %d\n",s->id_number);
                        printf("Homework grade: %f", s->hw_scores);
                        print("Exam grade: %f", s->exam_scores);
                        printf("Project grade: %f\n",s->project_scores);
                    
                }
                else
                { 
                printf("Student not found..."); 
                return;
                }
         
         }
         
        }
