#include "student.h"
#include "list.h"
#include <libxml/parser.h>
#include "curl.h"
#include <stdlib.h>
#include <string.h>

void init_me(Student* s){
  strcpy(s->name, "Anton Mazun");
  puts("\n");
  strcpy(s->group, "KP-51");
  s->variant = 14;

}

int main(void){
  Student me;
  LIBXML_TEST_VERSION;
  init_me(&me);
  char* resp = student_to_xml(&me);
  puts(resp);
  free(resp);

  xmlCleanupParser();
}
