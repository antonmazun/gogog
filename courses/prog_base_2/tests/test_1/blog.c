#include "main.h"
#include <stdlib.h>
#include "main.h"

/*
struct user_s {

    char * login;
    char * country;
    int * age;

};
*/

int post_getCount(blog_t * self) {
    int i;
    blog_t * blog = NULL;
    for (i = 0; i < list_size(blog->post); i++) {
        //car_t * car = list_get(self->cars, i);
        blog_t * blog  = list_get(blog_t * blog->post , i);
       // seats += car->seats;
    }
    return blog;
}

int get_data_user(){

    user_t * us  = user_new("sflls" , "dsdsfg" , "dssfdgf" , "sasfdgf");

}

int main(){

        blog_t * blog = blog_new("asd" , "sd" , "sad"  , "asd");
        blog = blog_new("klass" , "addsad" , "sadsd" , "sadsfd");


    return 0;
}



