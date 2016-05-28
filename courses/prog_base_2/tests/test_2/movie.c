#include "movie.h"
#include <libxml/parser.h>
#include <libxml/xmlwriter.h>
#include <string.h>

void movie_from_xml(Movie* m, char* xml){
  xmlDoc* doc;
  xmlNode* xmlRoot;
  xmlNode* curr;
  int i,n;

  m->discover_time = time(NULL);

  doc = xmlParseDoc(BAD_CAST xml);
  xmlRoot = xmlDocGetRootElement(doc);
  n = xmlChildElementCount(xmlRoot);
  
  for(curr = xmlRoot->xmlChildrenNode; curr != NULL; 
      curr = curr->next){
    if(!strcmp((char* )curr->name,"movie")){
      char* val;
      val = (char*) xmlNodeGetContent(curr);
      strcpy(m->name, val);
      xmlFree(val);
    }
    if(!strcmp((char*)curr->name, "year")){
      char* val;
      val = (char*) xmlNodeGetContent(curr);
      sscanf(val, "%d", &m->year);
      xmlFree(val);
    }
  }

  xmlFreeDoc(doc);
}

char* movie_to_xml(Movie* m){
  xmlBufferPtr buf;
  xmlTextWriterPtr writer;
  char *ret;
  struct tm* lt;
  char time_buff[400];

  buf = xmlBufferCreate();
  writer = xmlNewTextWriterMemory(buf,0);

  xmlTextWriterStartDocument(writer, NULL, XML_E, NULL);
  xmlTextWriterStartElement(writer, BAD_CAST "object");
  xmlTextWriterWriteElement(writer, BAD_CAST "movie", BAD_CAST m->name);
  xmlTextWriterWriteFormatElement(writer, BAD_CAST "year", "%d", m->year);
  lt = localtime(&m->discover_time);
  strftime(time_buff, 400, "%c", lt);
  xmlTextWriterWriteElement(writer, BAD_CAST "time",BAD_CAST time_buff);
  xmlTextWriterEndElement(writer);
  xmlTextWriterEndDocument(writer);

  ret = malloc(buf->size);
  strcpy(ret, (char*) buf->content);
  xmlBufferFree(buf);

  return ret;
}
