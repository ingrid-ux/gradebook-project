#include "gradebook.h"
#include "student.h"
#include <stdlib.h>
#include <stdio.h>

void addStudentToGradebook(gradebook *gb, student s){
        if (gb->studentCount == gb->capacity) {
        // printf("no memory left\n");
        gb->capacity *= 2; // allocating new array with bigger capacity 2x
        gb->students = realloc(gb->students, sizeof(student) * gb->capacity); // copy the content from the current array to the new one

        if (gb->students == NULL) {
            printf("Realloc failed\n");
            exit(1);
        }
    }

    gb->students[gb->studentCount++] = s;
}


void initGradebook(gradebook *gb) {
    gb->studentCount = 0;
    gb->capacity = 1;

    gb->students = malloc(sizeof(student) * gb->capacity);
    if (gb->students == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
}
    

void printListofStudentsInCourse(gradebook *gb){
    for (int i = 0; i < gb->studentCount; i++) {
        printf("%d: %s (ID: %d)\n", 
            i + 1,
            gb->students[i].name, 
            gb->students[i].id_number);
    }
}

int selectStudent(gradebook *gb){
    printf("Select student:\n");
    if (gb->studentCount == 0){
        printf("No students.");
        return -1;
    }
    printListofStudentsInCourse(gb);
    int choice;
    scanf("%d", &choice);
    if (choice < 1 || choice > gb->studentCount) {
        printf("Invalid choice. Please try again.\n");
        return -1;
    }
    return choice - 1; 
}

// KIMBERLY'S CODE *** 

/* ADD YOUR UPDATE FUNCTION HERE */
void updateStudentInGradebook(gradebook *gb){

    int index = selectStudent(gb);

    if(index == -1){
        return;
    }

    int choice;

    printf("What would you like to update?\n");
    printf("1. Student Name\n");
    printf("2. Student ID\n");
    scanf("%d", &choice);

    if(choice == 1){

        printf("Enter new student name: ");
        scanf(" %49[^\n]", gb->students[index].name);

        printf("Student name updated successfully.\n");
    }

    else if(choice == 2){

        printf("Enter new student ID: ");
        scanf("%d", &gb->students[index].id_number);

        printf("Student ID updated successfully.\n");
    }

    else{
        printf("Invalid option.\n");
    }
}


void managingScores(gradebook *gb){

    int index = selectStudent(gb);

    if(index == -1){
        return;
    }

    int choice;
    printf("------------------------------------\n");
    printf("What would you like to update?\n");
    printf("1. Homework Score\n");
    printf("2. Exam Score\n");
    printf("3. Project Score\n");
    printf("------------------------------------\n");
    scanf("%d", &choice);

    if(choice == 1){

        int hwIndex;
        double newScore;

        if(gb->students[index].homeworkCount == 0){
            printf("No homework scores available.\n");
            return;
        }

        printf("Current Homework Scores:\n");

        for(int i = 0; i < gb->students[index].homeworkCount; i++){

            printf("%d. %f\n",
            i + 1,
            gb->students[index].hw_scores[i]);
        }

        printf("Which homework score number do you want to update? ");
        scanf("%d", &hwIndex);

        if(hwIndex < 1 ||
           hwIndex > gb->students[index].homeworkCount){

            printf("Invalid homework selection.\n");
            return;
        }

        printf("Enter new homework score: ");
        scanf("%lf", &newScore);

        gb->students[index].hw_scores[hwIndex - 1] = newScore;

        printf("Homework score updated successfully.\n");
    }

    else if(choice == 2){

        int examIndex;
        double newScore;

        if(gb->students[index].examCount == 0){
            printf("No exam scores available.\n");
            return;
        }

        printf("Current Exam Scores:\n");

        for(int i = 0; i < gb->students[index].examCount; i++){

            printf("%d. %f\n",
            i + 1,
            gb->students[index].exam_scores[i]);
        }

        printf("Enter exam number to update: ");
        scanf("%d", &examIndex);

        if(examIndex < 1 ||
           examIndex > gb->students[index].examCount){

            printf("Invalid exam selection.\n");
            return;
        }

        printf("Enter new exam score: ");
        scanf("%lf", &newScore);

        gb->students[index].exam_scores[examIndex - 1] = newScore;

        printf("Exam score updated successfully.\n");
    }

    else if(choice == 3){

        int projectIndex;
        double newScore;

        if(gb->students[index].projectCount == 0){
            printf("No project scores available.\n");
            return;
        }

        printf("Current Project Scores:\n");

        for(int i = 0; i < gb->students[index].projectCount; i++){

            printf("%d. %f\n",
            i + 1,
            gb->students[index].project_scores[i]);
        }

        printf("Enter project number to update: ");
        scanf("%d", &projectIndex);

        if(projectIndex < 1 ||
           projectIndex > gb->students[index].projectCount){

            printf("Invalid project selection.\n");
            return;
        }

        printf("Enter new project score: ");
        scanf("%lf", &newScore);

        gb->students[index].project_scores[projectIndex - 1] = newScore;

        printf("Project score updated successfully.\n");
    }

    else{
        printf("Invalid option.\n");
    }
}

void deleteStudentFromGradebook(gradebook *gb, int IDnumber) {
    // this validates the ID number given and checks if it exists amongst the student list
    if (IDnumber < 0 || IDnumber >= gb->studentCount) {
        printf("Invalid student ID.\n");
        return;
    }

    // this shifts all the students to the left by one to account for whichever entry is deleted
    for (int i = IDnumber; i < gb->studentCount - 1; i++) {
        gb->students[i] = gb->students[i + 1];
    }
        
    // this changes the student count minus 1 after a student is deleted
    gb->studentCount--;

    printf("Student was successfully deleted.\n");
}

// MELANIE'S CODE 
student* findStudentByID(gradebook *gb){
    int id;
    printf("Enter Student ID: ");
    scanf("%d", &id);
    for(int i = 0; i < gb->studentCount; i++)
    {
            if(gb->students[i].id_number == id){ 
           printf("-----------------Student Information------------------------\n");
            printf("Student: %s found in gradebook.\n", gb->students[i].name);
            printf("ID: %d\n", gb->students[i].id_number);
            //display students current info such as
            //name, id, hw scores, project scores, test scores
            //using exsiting printAllScores to display's students info
            printf("-----------------Scores Information------------------------\n");
            printAllScores(&gb->students[i]);
            return &gb->students[i];
        }
    }
        printf("Student not found.\n");
        return NULL; 
    
}

// KIMBERLY'S CODE 

void printStudentAverages(gradebook *gb){

    int index = selectStudent(gb);

    if(index == -1){
        return;
    }

    double hwAvg = 0, examAvg = 0, projectAvg = 0;

    // Homework average
    if(gb->students[index].homeworkCount > 0){
        double sum = 0;
        for(int i = 0; i < gb->students[index].homeworkCount; i++){
            sum += gb->students[index].hw_scores[i];
        }
        hwAvg = sum / gb->students[index].homeworkCount;
    }

    // Exam average
    if(gb->students[index].examCount > 0){
        double sum = 0;
        for(int i = 0; i < gb->students[index].examCount; i++){
            sum += gb->students[index].exam_scores[i];
        }
        examAvg = sum / gb->students[index].examCount;
    }

    // Project average
    if(gb->students[index].projectCount > 0){
        double sum = 0;
        for(int i = 0; i < gb->students[index].projectCount; i++){
            sum += gb->students[index].project_scores[i];
        }
        projectAvg = sum / gb->students[index].projectCount;
    }

    printf("\n--- Averages for %s ---\n", gb->students[index].name);
    printf("Homework Average: %.2f\n", hwAvg);
    printf("Exam Average: %.2f\n", examAvg);
    printf("Project Average: %.2f\n", projectAvg);
}
// KIMBERLY'S CODE 
void sortStudentsByID(gradebook *gb){

    for(int i = 0; i < gb->studentCount - 1; i++){
        for(int j = 0; j < gb->studentCount - i - 1; j++){

            if(gb->students[j].id_number > gb->students[j + 1].id_number){

                // swap students
                student temp = gb->students[j];
                gb->students[j] = gb->students[j + 1];
                gb->students[j + 1] = temp;
            }
        }
    }

    printf("Students sorted by ID successfully.\n");
}
