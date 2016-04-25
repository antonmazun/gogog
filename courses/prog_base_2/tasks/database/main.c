#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include "admin.h"
#include "datab.h"


int main()
{


    const char * dbFile = "admins.db";
    admin_t adminList[100];
    db_t * db = db_new(dbFile);

    int countAdmins = db_countAdmins(db);
    printf("Admins total: %i\n\n", countAdmins);
    int filterFollowers = 9;
    int filterYears = 9;
    int size = db_getStudentsTask(db, filterYears, filterFollowers, adminList, 100);
    printf("%i %i year: %i\n\n", filterFollowers, filterYears, size);
    printList(adminList, size);


    return 0;
}
