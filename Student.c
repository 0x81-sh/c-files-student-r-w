#include "Student.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Student {
    char fn[30];
    char ln[30];
};

PStudent Student_create(char *fn, char *ln) {
    PStudent s = (PStudent) malloc(sizeof (struct Student));

    if (!s) {
        printf("Error: cannot create a Student");
    }

    strncpy(s->fn, fn, 30);
    s->fn[29] = 0;
    strncpy(s->ln, ln, 30);
    s->ln[29] = 0;

    return s;
}

void Student_print(PStudent _this) {
    printf("%s %s\n", _this->fn, _this->ln);
}

void Student_delete(PStudent _this) {
    free(_this);
}

void Student_write(PStudent student, char * filename) {
    FILE *file = fopen(filename, "ab");
    fwrite(student, sizeof (struct Student), 1, file);

    fclose(file);
}

PStudent Student_read(char *filename) {
    FILE *file = fopen(filename, "rb");
    PStudent read = (PStudent) malloc(sizeof (struct Student));

    fread(read, sizeof (struct Student), 1, file);

    fclose(file);
    return read;
}

void Student_writeArray(PStudent *students, char * filename, int count) {
    FILE *file = fopen(filename, "wb");

    for (int i = 0; i < count; i++) {
        fwrite(students[i], sizeof (struct Student), 1, file);
    }

    fclose(file);
}

PStudent * Student_readArray(char * filename, int count) {
    FILE *file = fopen(filename, "rb");
    PStudent *read = (PStudent *) malloc(sizeof (int) * count);

    for (int i = 0; i < count; i++) {
        read[i] = (PStudent) malloc(sizeof (struct Student));
        fread(read[i], sizeof (struct Student), 1, file);
    };

    fclose(file);
    return read;
}