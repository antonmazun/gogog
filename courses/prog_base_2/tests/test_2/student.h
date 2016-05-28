#ifndef _STUDENT
#define _STUDENT
#include "encoding.h"

#define MAX_NAME_SURNAME_LENGTH 60
#define MAX_GROUP_LENGTH 16

typedef struct Student {
  char name[MAX_NAME_SURNAME_LENGTH];
  char group[MAX_GROUP_LENGTH];
  int variant;
} Student;

char* student_to_xml(Student* t);

#endif
