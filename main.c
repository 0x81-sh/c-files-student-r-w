#include <stdio.h>
#include "Student.h"

void testWrite ();
void testRead ();
void testWriteArray();
void testReadArray();

int main() {
    printf("Single write test\n");
    testWrite();
    testRead();

    printf("\nArray write test\n");
    testWriteArray();
    testReadArray();

    return 0;
}

void testWrite () {
    PStudent test = Student_create("test", "student");
    Student_write(test, "test.dat");

    Student_delete(test);
}

void testRead () {
    PStudent testRead = Student_read("test.dat");
    Student_print(testRead);

    Student_delete(testRead);
}

void testWriteArray() {
    PStudent students[2] = {Student_create("name1", "name2"), Student_create("name3", "name4")};
    Student_writeArray(students, "test.dat", 2);

    Student_delete(students[1]);
    Student_delete(students[0]);
}

void testReadArray() {
    PStudent *students = Student_readArray("test.dat", 2);

    Student_print(students[0]);
    Student_print(students[1]);

    Student_delete(students[1]);
    Student_delete(students[0]);
}