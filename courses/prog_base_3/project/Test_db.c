#include <stdio.h>
#include <stdlib.h>
#include "include/sqlite3.h"

static int callback(void *notUsed, int argc, char **argv, char **azColName);

int main(void){
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;  // return code
    const char * databaseFile = "test.db";
    const char * sqlScript = "SELECT * FROM Book;";

    rc = sqlite3_open(databaseFile, &db);
    if ( rc ) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return(1);
    }

    rc = sqlite3_exec(db, sqlScript, callback, 0, &zErrMsg);
    if ( SQLITE_OK != rc ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    sqlite3_close(db);
    return 0;
}

static int callback(void *notUsed, int argc, char **argv, char **azColName) {
    int i;
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}
