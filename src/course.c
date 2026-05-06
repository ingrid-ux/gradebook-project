#include "course.h"
#include "gradebook.h"
#include <string.h>
#include <stdio.h>

course addCourse(){
    course c;
    printf("Creating a new course...\n");
    printf("Enter course name: ");
    scanf(" %49[^\n]", c.course_name);
    printf("________________________________\n");

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


void deleteCourse(course *courses, int *courseCount, int courseIndex){

    
    if(courseIndex < 0 || courseIndex >= *courseCount){
        printf("Invalid course selection.\n");
        return;
    }

    
    for(int i = courseIndex; i < *courseCount - 1; i++){
        courses[i] = courses[i + 1];
    }

    
    (*courseCount)--;

    printf("Course was successfully deleted.\n");
}


/*
void findstudent(course *course, int courseCount){
        //course *course is a pointer to course structure
        // the * means its a pointer (points to something in an array)
        //without declaring first, findstudent wont know which course to search through
        //int courseCount tells us how big the array of holding all the courses is
        char subject[51];
        int courseIndex=-1;
        //found will keep track on whether course is found 
        //found = 0 means course was not found and if found = 1 course was found in array
        int found = 0;
        // key will hold the id number the user inputs
        int key;
        //ask for course name to search for student in
        printf("Enter the course you want to look for a student in: ");
        scanf("%49[^\n]",subject);
        
        //first check if course exsits 
        // if it does ask for id, if it doesn't return to main menu
        //strcmp will compare two strings character by character, 0 means the strings are equal
      for (int i=0; i<courseCount; i++)
      {
        if(strcmp (subject, course[i].course_name)==0)
            printf("Course found...");
            found = 1;
            courseIndex=i;
      }
      if(!found)
      {
          printf("Course was not found...\n");
          return;
      }
    
        //asking user for students id(key)
        // used id for key incase their are students whith same name or name gets missspelled
        printf("Enter the student's ID number: ");
        scanf("%d",&key);
        
        //access course and look for student in course
        gradebook *gb = &course[courseIndex].gradebook;
        for (int i=0; i< gb->studentCount; i++)
          {
                if (gb->students[i].id_num == key) 
                {
                        printf("Student found.\n");
                        //display students current info such as 
                        //name, id, hw scores, project scores, test scores
                        printf("-----------------Student Information------------------------\n");
                        printf("Student Name: %s\n",gb->students[i].name);
                        printf("ID: %d\n", gb->students[i].id_number);
                        
                        //use for loop to display student's scores for each hw, exam, and projects
                        printf("Homework scores: \n");
                        for(int a=0; a< gb->students[i].homeworkCount; a++ )
                        {
                            printf("%f\n", gb->students[i].hw_scores[a] );
                        }
                        
                        printf("Exam Scores: \n"); 
                        for(int b =0; b< gb->studnets[i].examCount; b++ )
                        {
                            printf("%f\n", gb->students[i].exam_scores[b]);
                        }
                        printf("Project scores: \n");
                        for(int x = 0; x<gb->students[i].project_scores; x++ )
                        {
                            printf("%f\n",gb->students[i].project_scores[x]);
                        }
                        //exiting 
                        break;
                    
                }
                
         
         }
         //line below wont print if student is found b/c of the return statment in the if , print statment is controlled
         printf("Student with ID: %d was not found...",key);
         return;
        }
    // Updating student course
    void updateStudent(course courses[], int courseCount){
        char subject[50];
        int key;
        int courseIndex = -1;

        printf("Enter the course you want to update a student in: ");
        scanf(" %49[^\n]", subject);

        for (int i = 0; i < courseCount; i++) {
        if (strcmp(subject, courses[i].course_name) == 0) {
            courseIndex = i;
            break;
        }
    }

    if (courseIndex == -1) {
        printf("Course not found.\n");
        return;
    }

    printf("Enter the student's ID number: ");
    scanf("%d", &key);

    gradebook *gb = &courses[courseIndex].gradebook;

    for (int i = 0; i < gb->studentCount; i++) {

        if (gb->students[i].id_num == key) {

            printf("Student found.\n");

            printf("Enter new name: ");
            scanf(" %49[^\n]", gb->students[i].name);

            printf("Student updated successfully.\n");

            return;
        }
    }

    printf("Student not found.\n");
}
*/