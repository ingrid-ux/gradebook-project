READ ME FILE
This program is divided into multiple source files, each containing functions responsible for a specific part of the gradebook system.
Main.c
main()
The starting point of the program. It displays the menu, reads user input, and calls the appropriate functions to perform actions such as adding, updating, or viewing students.
Gradebook.c
addStudent()
Adds a new student to the gradebook by collecting their name and ID.
findStudentByID()
Searches for a student using their ID and returns a pointer to the student if found.
updateStudentInGradebook()
Allows updating of a student’s homework, exam, or project scores.
deleteStudent()
Removes a student from the gradebook and shifts remaining records to maintain structure.
listStudents()
Displays all students and their corresponding information.
Student.c
Functions in this file handle individual student data, including storing and accessing student attributes such as name, ID, and scores.
Course.c
Functions related to course structure, such as managing assignments, exams, and project categories within the gradebook.
System.c
Handles system-level operations such as menu display, user prompts, and general program control flow.
