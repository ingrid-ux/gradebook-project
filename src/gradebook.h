#ifndef GRADEBOOK_H
#define GRADEBOOK_H
#include "student.h"

typedef struct{

    student *students;
    int studentCount;
    int capacity; 



}gradebook;

void addStudentToGradebook(gradebook *gb, student s);
void printListofStudentsInCourse(gradebook *gb);
void initGradebook(gradebook *gb);
int selectStudent(gradebook *gb);
void updateStudentInGradebook(gradebook *gb);
void managingScores(gradebook *gb);
void deleteStudentFromGradebook(gradebook *gb, int index);
student* findStudentByID(gradebook *gb);
void printStudentAverages(gradebook *gb);
void sortStudentsByID(gradebook *gb);

#endif
