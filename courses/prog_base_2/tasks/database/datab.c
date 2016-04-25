#include <stdio.h>
#include <stdlib.h>
#include "datab.h"
#include <sqlite3.h>

struct db_s{

    sqlite3 * db;
};
static void _fillAdmin(sqlite3_stmt * stmt, admin_t * p) {
    /*if(stmt == NULL)
    {
    puts("done1");
    return;
    }*/
    int number = sqlite3_column_int(stmt, 0);
    const unsigned char * name = sqlite3_column_text(stmt, 1);
    const unsigned char * surname = sqlite3_column_text(stmt, 2);
    int subscribes = sqlite3_column_int(stmt, 3);
    int years = sqlite3_column_int(stmt, 4);
    double Rank = sqlite3_column_double(stmt, 5);
    /*if(name == NULL)
    {
    puts("done");
    return;
    }*/
    p->number = number;

    strcpy(p->name, (const char *)name);
    strcpy(p->surname, (const char *)surname);
    p->subscribes = subscribes;
    p->years = years;
    p->Rank = Rank;


}



db_t * db_new(const char * dbFile) {
    db_t * self = malloc(sizeof(struct db_s));
    int rc = sqlite3_open(dbFile, & (self->db));
    if (SQLITE_ERROR == rc) {
        printf("can't open database\n");
        exit(1);
    }
    return self;
}

void db_free(db_t * self) {
    sqlite3_close(self->db);
    free(self);
}



int db_insertAdmin(db_t * self, admin_t * admin) {
    int newAdminId = -1;
    sqlite3_stmt * stmt = NULL;
    int rc = 0;
      if(SQLITE_OK != sqlite3_prepare_v2(self->db,"INSERT INTO Admins  (Name, Surname, Subscribes, Years, Rank) VALUES (?,?,?,?,?);", -1, &stmt, NULL)) {
        printf("Not prepared!\n");
    }
    //const char * sqlQuery = "INSERT INTO admins(Name , Surname , Subscribes , Data , Rank) VALUES (?, ?, ?, ?, ?);";
    //sqlite3_prepare_v2(self->db, sqlQuery, strlen(sqlQuery), &stmt, 0);
   sqlite3_bind_text(stmt , 1 , admin->name , strlen(admin->name) ,NULL);
   sqlite3_bind_text(stmt , 2 , admin->surname , strlen(admin->surname) , NULL);
   sqlite3_bind_int(stmt , 3 , admin->subscribes);
   sqlite3_bind_int(stmt , 4 , admin->years);
   sqlite3_bind_double(stmt , 5 , admin->Rank);

    if (SQLITE_DONE != (rc = sqlite3_step(stmt))) {
        printf("Not inserted! %i\n", rc);
    }
    //int rc = sqlite3_step(stmt);
    //if (SQLITE_ERROR == rc) {
    //    printf("can't select admins\n");
    //    exit(1);
  //  }
    newAdminId = (int) sqlite3_last_insert_rowid (self->db);
    sqlite3_finalize(stmt);
    return newAdminId;
}




admin_t * db_getAdminById(db_t * self, int number) {
    admin_t * admin = malloc(sizeof(struct admin_s));
    sqlite3_stmt * stmt = NULL;
    const char * sqlQuery = "SELECT * FROM admins WHERE c == ?;";
    sqlite3_prepare_v2(self->db, sqlQuery, strlen(sqlQuery), &stmt, 0);
    sqlite3_bind_int(stmt, 1, number);
    int rc = sqlite3_step(stmt);
    if (SQLITE_ERROR == rc) {
        printf("can't select admins\n");
        exit(1);
    } else
        _fillAdmin(stmt, admin);
    return admin;
}



void db_updateAdmin(db_t * self, admin_t * admin) {
    sqlite3_stmt * stmt = NULL;
    const char * sqlQuery = "UPDATE admins SET Name = ?, Surname = ?, Subscribes = ?, Years= ?, Rank = ?, WHERE Number == ?;";
    sqlite3_prepare_v2(self->db, sqlQuery, strlen(sqlQuery), &stmt, 0);
    sqlite3_bind_text(stmt, 1, admin->name, strlen(admin->name), NULL);
    sqlite3_bind_text(stmt, 2, admin->surname, strlen(admin->surname), NULL);
    sqlite3_bind_int(stmt, 3, admin->subscribes);
    sqlite3_bind_int(stmt, 4, (int)admin->years);
    sqlite3_bind_double(stmt, 5, admin->Rank);

    int rc = sqlite3_step(stmt);
    if (SQLITE_ERROR == rc) {
        printf("can't select admins\n");
        exit(1);
    }
}



void db_deleteAdmin(db_t * self, int number) {
    sqlite3_stmt * stmt = NULL;
    const char * sqlQuery = "DELETE FROM admins WHERE number == ?";
    sqlite3_prepare_v2(self->db, sqlQuery, strlen(sqlQuery), &stmt, 0);
    sqlite3_bind_int(stmt, 1, number);
    int rc = sqlite3_step(stmt);
    if (SQLITE_ERROR == rc) {
        printf("can't select admins\n");
        exit(1);
    }
}



int db_countAdmins(db_t * self) {
    sqlite3_stmt * stmt = NULL;
    sqlite3_prepare_v2(self->db, "SELECT COUNT(*) FROM Admins;", -1, &stmt, 0);
    int rc = sqlite3_step(stmt);
    if (SQLITE_ERROR == rc) {
        printf("can't select count\n");
        exit(1);
    }
    int count = sqlite3_column_int(stmt, 0);
    sqlite3_finalize(stmt);
    return count;
}


int db_getStudentsTask(db_t * self, int K, int P, admin_t * arr, int arrMax) {
    sqlite3_stmt * stmt = NULL;
    const char * sqlQuery = "SELECT * FROM Admins WHERE Subscribes > ? AND Years < ?;";
    sqlite3_prepare_v2(self->db, sqlQuery, strlen(sqlQuery), &stmt, 0);
    sqlite3_bind_int(stmt, 1, K);
    sqlite3_bind_int(stmt, 2, P);
    int count = 0;
    while (1) {
        int rc = sqlite3_step(stmt);
        if (SQLITE_ERROR == rc) {
            printf("can't select admins\n");
            exit(1);
        } else if (SQLITE_DONE == rc || stmt == NULL) {
            break;
        } else {
            _fillAdmin(stmt, &arr[count]);
            count++;
        }
    }
    sqlite3_finalize(stmt);
    return count;
}
