#ifndef COURSE_H
#define COURSE_H

#include "gradebook.h"
typedef struct{

    gradebook gradebook;
    char course_name[50];


}course;

void setCourseName(course *c, char *courseName);
char *getCourseName(course *c);
course addCourse();
//declaring findstudent to use in course.c 
void findstudent (course *course, int courseCount);
void deleteCourse(course *courses, int *courseCount, int courseIndex);
#endif
