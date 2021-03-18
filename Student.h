#pragma once

typedef struct Student *PStudent;

PStudent Student_create(char *fn, char *sn);
void Student_print(PStudent);
void Student_delete(PStudent);
void Student_write(PStudent student, char * filename);
PStudent Student_read(char *filename);
void Student_writeArray(PStudent *students, char * filename, int count);
PStudent * Student_readArray(char * filename, int count);