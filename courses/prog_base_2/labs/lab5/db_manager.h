#ifndef DB_MANAGER_H_INCLUDED
#define DB_MANAGER_H_INCLUDED

#include "list.h"
#include "xml.h"
typedef struct db_s db_t;
/*typedef struct admin_s {
    int id;
    char name[256];
    char surname[256];
    int birthdate;
    double rate;
    int creating_year;
    int followers;
} admin_t;*/

db_t * db_new(const char * dbFile);
void db_free(db_t * self);
list_t database_to_list_select(db_t * self, char * select);
int db_insertAdmin(db_t * self, admin_t * student);
admin_t * db_getAdminById(db_t * self, int id);
void db_updateAdmin(db_t * self, admin_t * student);
void db_deleteAdmin(db_t * self, int id);

int db_countAdmins(db_t * self);

int db_getAdminTask(db_t * self, int K, int P, admin_t * arr, int arrMax);
list_t database_to_list(db_t * self);
char * db_to_html_id(int i);
#endif // DB_MANAGER_H_INCLUDED
