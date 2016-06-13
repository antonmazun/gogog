#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include "student.h"
#include "datab.h"


int main()
{

char text[150];

    const char * dbFile = "student.db";
    admin_t adminList[100];
    db_t * db = db_new(dbFile);
admin_t * admin;
    int countAdmins = db_countAdmins(db);
    printf("Admins total: %i\n\n", countAdmins);
    int filterFollowers = 9;
    int filterYears = 9;
   int size = db_getStudentsTask(db, filterYears, filterFollowers, adminList, 100);
    printf("%i %i year: %i\n\n", filterFollowers, filterYears, size);
    printList(adminList, size);
    puts("Viberete functions : add or check");
    scanf("%s"  , &text);
    if(strcmp(text , "add") == 0){
        db_insertAdmin(db,admin);

    }
  //  db_insertAdmin(self , admin);

    return 0;
}
