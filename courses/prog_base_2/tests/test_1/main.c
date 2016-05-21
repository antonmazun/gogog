// The functions contained in this file are pretty dummy
// and are included only as a placeholder. Nevertheless,
// they *will* get included in the static library if you
// don't remove them :)
//
// Obviously, you 'll have to write yourself the super-duper
// functions to include in the resulting library...
// Also, it's not necessary to write every function in this file.
// Feel free to add more files in this project. They will be
// included in the resulting library.

// A function adding two integers and returning the resulte
#include "main.h"
#include <stdlib.h>
#include "list.h"


struct blog_s{
    char * blog;
    //char * user;
    char * post;
    char * com;


};


struct user_s {

     char * login;
     char * country;
     int * age;

};

user_t * user_new(){

user_t * us  = malloc(sizeof(struct user_s));
us->login = NULL;
us->country = NULL;
us->country = NULL;
us-> age = NULL;

return us;
}

user_t * blog_free(user_t * us){

 if(us->login != NULL){
    free(us->login);
}
if(us->country != NULL){
    free(us->country);
}


  if(us->age != NULL){
    free(us->age);
}

}


}

blog_t * blog_new(){

    blog_t * blog = malloc(sizeof(struct blog_s));
    blog->blog = NULL;
    blog->user = NULL;
    blog->post = NULL;
    blog->com = NULL;

    return blog;

}




blog_t * blog_free(blog_t * blog){
    if(blog->blog != NULL){
    free(blog->blog);
}
   if(blog->user != NULL){
    free(blog->user);
}
  if(blog->post != NULL){
    free(blog->post);
  }
    if(blog->com != NULL){
    free(blog->com);
}

}



int SampleAddInt(int i1, int i2)
{
    return i1 + i2;
}



// A function doing nothing ;)
void created_blog(char * str , blog_t * blog )
{
    blog->blog = malloc(sizeof(char) * strlen(str));
    strcpy(str , blog->blog);


}


/*
void created_user(char * str , blog_t * blog )
{
    blog->user = malloc(sizeof(char) * strlen(str));
    strcpy(str , blog->user);

}
*/


void created_post(char * str , blog_t * blog )
{
    blog->post = malloc(sizeof(char) * strlen(str));
    strcpy(str , blog->post);
}



void created_com(char * str , blog_t * blog )
{
    blog->com = malloc(sizeof(char) * strlen(str));
    strcpy(str , blog->com);
}



char * blog_getblog(blog_t * blog){

return blog->blog;
}



char * blog_getuser(blog_t * blog){

return blog->user;
}



char * blog_getpost(blog_t * blog){

return blog->post;
}



char * blog_getcom(blog_t * blog){

return blog->com;
}

