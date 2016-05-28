#include "fileInfo.h"

#include <libxml/xmlwriter.h>
#include <string.h>

int countWords(FILE* f){
  char line_buff[4000];
  int res = 1;
  while(fgets(line_buff, 4000, f)){
    strtok(line_buff, " ,.!?");
    while(strtok(NULL, " ,.!?"))
      res++;
  }
  return res;
}

char* fileinfo_get(char* path){
  FILE* file;
  xmlBufferPtr buf;
  xmlTextWriterPtr writer;
  char* ret;
  int wordCount;

  file  = fopen(path, "r");
  wordCount = countWords(file);
  fclose(file);

  buf = xmlBufferCreate();
  writer = xmlNewTextWriterMemory(buf, 0);

  xmlTextWriterStartDocument(writer, NULL, XML_E, NULL);


  xmlTextWriterStartElement(writer, BAD_CAST "fileInfo");
  xmlTextWriterWriteFormatElement(writer, BAD_CAST "wordCount", "%d", wordCount);
  xmlTextWriterEndElement(writer);

  xmlTextWriterEndDocument(writer);

  ret = malloc(buf->size);
  strcpy(ret,(char*)buf->content);
  xmlBufferFree(buf);

  return ret;
}
