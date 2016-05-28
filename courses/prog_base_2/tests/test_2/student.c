#include "student.h"
#include <libxml/xmlwriter.h>
#include <stdlib.h>
#include <string.h>
#include <curl.h>


char * student_to_xml(Student* s){
  xmlBufferPtr buf;
  xmlTextWriterPtr writer;
  char * ret;

  buf = xmlBufferCreate();
  writer = xmlNewTextWriterMemory(buf, 0);

  xmlTextWriterStartDocument(writer, NULL, XML_E, NULL);


  xmlTextWriterStartElement(writer, BAD_CAST "authorInfo");
  xmlTextWriterWriteElement(writer, BAD_CAST "student", BAD_CAST s->name);
  xmlTextWriterWriteElement(writer, BAD_CAST "group", BAD_CAST s->group);
  xmlTextWriterWriteFormatElement(writer, BAD_CAST "variant", "%d", s->variant);
  xmlTextWriterEndElement(writer);

  xmlTextWriterEndDocument(writer);

  ret = malloc(buf->size);
  strcpy(ret,(char*)buf->content);
  xmlBufferFree(buf);

  return ret;
}
