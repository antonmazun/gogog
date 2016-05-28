#include "student.h"
#include "movie.h"
#include "fileInfo.h"
#include "list.h"
#include <libxml/parser.h>
#include <curl/curl.h>
#include <stdlib.h>
#include <string.h>

size_t curl_write_cb(void* ptr, size_t size, size_t count, void* stream){
  strcpy((char*) stream, (char*) ptr);
  return size*count;
}

char* external(CURL* curl){
  char answer[1000];
  Student me;
  Movie mov;

  curl_easy_setopt(curl, CURLOPT_URL, 
      "http://pb-homework.appspot.com/test/var/14?format=xml");
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curl_write_cb);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, answer);
  curl_easy_perform(curl);

  movie_from_xml(&mov, answer);
  return movie_to_xml(&mov);
}

void init_me(Student* s){
  strcpy(s->name, "Anton Mazun");
  strcpy(s->group, "KP-51");
  s->variant = 14;
}

int main(void){
  char user_input[1024];
  CURL* curl;

  LIBXML_TEST_VERSION;
  curl = curl_easy_init();
 while(1){
  fgets(user_input, 1024, stdin);
  if(!strcmp(user_input, "GET /info\n")){
    Student i;
    char* r;
    init_me(&i);
    r = student_to_xml(&i);
    puts(r);
    free(r);
  } else if (!strcmp(user_input, "GET /external\n")){
    puts(external(curl));
  } else {
    int i;
    char* fname = strstr(user_input,"GET /file/");
    if(fname == NULL) continue;
    fname+=strlen("GET /file/");
    fname[strlen(fname)-1] = '\0';
    puts(fname);
    if(*fname=='\0') continue;
    char name_buff[80];
    strcpy(name_buff, fname);
    puts(fileinfo_get(name_buff));
  }
 }

  curl_easy_cleanup(curl);
  curl_global_cleanup();
  xmlCleanupParser();
}
