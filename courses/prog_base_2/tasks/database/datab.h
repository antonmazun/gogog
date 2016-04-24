#ifndef DATAB_H_INCLUDED
#define DATAB_H_INCLUDED
#include "admin.h"
#include <sqlite3.h>
typedef struct db_s db_t;

db_t * db_new(const char * dbFile);
static void _fillAdmin(sqlite3_stmt * stmt, admin_t * p);
db_t * db_new(const char * dbFile);
void db_free(db_t * self);
int db_insertAdmin(db_t * self, admin_t * admin);
admin_t * db_getAdminById(db_t * self, int number);
void db_updateAdmin(db_t * self, admin_t * admin);
void db_deleteAdmin(db_t * self, int number);

int db_countAdmins(db_t * self);
int db_getStudentsTask(db_t * self, int K, int P, admin_t * arr, int arrMax);




#endif // DATAB_H_INCLUDED
