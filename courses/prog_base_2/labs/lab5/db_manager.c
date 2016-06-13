#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <sqlite3.h>
//#include "sqlite3ext.h"
#include "db_manager.h"

struct db_s {
    sqlite3 * db;
};
static void _fillStudent(sqlite3_stmt * stmt, admin_t * st) {
    int id = sqlite3_column_int(stmt, 0);
    const char * name = sqlite3_column_text(stmt, 1);
    const char * surname = sqlite3_column_text(stmt, 2);
    int birthdate = sqlite3_column_int(stmt, 3);
    double rate = sqlite3_column_double(stmt, 4);
    int creating_year = sqlite3_column_int(stmt, 5);
    int followers = sqlite3_column_int(stmt, 6);
    st->id = id;
    if(name == NULL)
		puts("done");
    strcpy(st->name, (const char *)name);
    strcpy(st->surname, (const char *)surname);
    st->rate = rate;
    st->birthdate = birthdate;
    st->followers = followers;
    st->creating_year = creating_year;

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
    int newStudentId = -1;
    sqlite3_stmt * stmt = NULL;
    const char * sqlQuery = "INSERT INTO admins VALUES (null, ?, ?, ?, ?, ?, ?);";
    sqlite3_prepare_v2(self->db, sqlQuery, strlen(sqlQuery), &stmt, 0);
    sqlite3_bind_text(stmt, 1, admin->name, strlen(admin->name), NULL);
    sqlite3_bind_text(stmt, 2, admin->surname, strlen(admin->surname), NULL);
    sqlite3_bind_int(stmt, 3, admin->birthdate);
    sqlite3_bind_double(stmt, 4, (double)admin->rate);
    sqlite3_bind_int(stmt, 5, admin->creating_year);
    sqlite3_bind_int(stmt, 6, admin->followers);
    int rc = sqlite3_step(stmt);
    if (SQLITE_ERROR == rc) {
        printf("can't select admins\n");
        exit(1);
    }
	sqlite3_finalize(stmt);
    return newStudentId;
}

admin_t * db_getAdminById(db_t * self, int id) {
    admin_t * admin = malloc(sizeof(struct admin_s));
    sqlite3_stmt * stmt = NULL;
    const char * sqlQuery = "SELECT * FROM admins WHERE Id == ?;";
    sqlite3_prepare_v2(self->db, sqlQuery, strlen(sqlQuery), &stmt, 0);
    sqlite3_bind_int(stmt, 1, id);
    int rc = sqlite3_step(stmt);
    if (SQLITE_ERROR == rc) {
        printf("can't select admins\n");
        exit(1);
    } else
        _fillStudent(stmt, admin);
	sqlite3_finalize(stmt);
    return admin;
}

void db_updateAdmin(db_t * self, admin_t * admin) {
    sqlite3_stmt * stmt = NULL;
    const char * sqlQuery = "UPDATE admins SET Name = ?, Surname = ?, Birthdate = ?, Rate = ?, CreatingYear = ?, Followers = ? WHERE Id == ?;";
    sqlite3_prepare_v2(self->db, sqlQuery, strlen(sqlQuery), &stmt, 0);
    sqlite3_bind_text(stmt, 1, admin->name, strlen(admin->name), NULL);
    sqlite3_bind_text(stmt, 2, admin->surname, strlen(admin->surname), NULL);
    sqlite3_bind_int(stmt, 3, admin->birthdate);
    sqlite3_bind_double(stmt, 4, (double)admin->rate);
    sqlite3_bind_int(stmt, 5, admin->creating_year);
    sqlite3_bind_int(stmt, 6, admin->followers);
    sqlite3_bind_int(stmt, 7, admin->id);
    int rc = sqlite3_step(stmt);
    if (SQLITE_ERROR == rc) {
        printf("can't select admins\n");
        exit(1);
    }
}

void db_deleteAdmin(db_t * self, int id) {
    sqlite3_stmt * stmt = NULL;
    const char * sqlQuery = "DELETE FROM admins WHERE Id == ?";
    sqlite3_prepare_v2(self->db, sqlQuery, strlen(sqlQuery), &stmt, 0);
    sqlite3_bind_int(stmt, 1, id);
    int rc = sqlite3_step(stmt);
    if (SQLITE_ERROR == rc) {
        printf("can't select admins\n");
        exit(1);
    }
}

int db_countAdmins(db_t * self) {
    sqlite3_stmt * stmt = NULL;
    sqlite3_prepare_v2(self->db, "SELECT COUNT(*) FROM admins;", -1, &stmt, 0);
    int rc = sqlite3_step(stmt);
    if (SQLITE_ERROR == rc) {
        printf("can't select count\n");
        exit(1);
    }
    int count = sqlite3_column_int(stmt, 0);
    sqlite3_finalize(stmt);
    return count;
}
/*

int db_getStudentsTask(db_t * self, int K, int P, admin_t * arr, int arrMax) {
    sqlite3_stmt * stmt = NULL;
    const char * sqlQuery = "SELECT * FROM admins WHERE CreatingYear > ? AND Followers > ?;";
    sqlite3_prepare_v2(self->db, sqlQuery, strlen(sqlQuery), &stmt, 0);
    sqlite3_bind_int(stmt, 1, K);
    sqlite3_bind_int(stmt, 2, P);
    int count = 0;
    while (1) {
        int rc = sqlite3_step(stmt);
        if (SQLITE_ERROR == rc) {
            printf("can't select admins\n");
            exit(1);
        } else if (SQLITE_DONE == rc) {
            break;
        } else {
            _fillStudent(stmt, &arr[count]);
            count++;
        }
    }
    sqlite3_finalize(stmt);
    return count;
}
*/
list_t database_to_list(db_t * self)
{
	list_t list = list_new();
	for (int i = 1; i < db_countAdmins(self) + 1; i++)
	{
		admin_t * admin = malloc(sizeof(struct admin_s));
		sqlite3_stmt * stmt = NULL;
		const char * sqlQuery = "SELECT * FROM admins WHERE Id == ?;";
		sqlite3_prepare_v2(self->db, sqlQuery, strlen(sqlQuery), &stmt, 0);
		sqlite3_bind_int(stmt, 1, i);
		puts("gdg");
		int rc = sqlite3_step(stmt);
		puts("gdg");
		if (SQLITE_ERROR == rc) {
			printf("can't select admins\n");
			exit(1);
		} else
			_fillStudent(stmt, admin);
		puts("gdg");
		list_add(list, admin, 0);
	}
	return list;
}

list_t database_to_list_select(db_t * self, char * select)
{
	list_t list = list_new();
	admin_t * admin = NULL;
	sqlite3_stmt * stmt = NULL;
	const char * sqlQuery = select;
	sqlite3_prepare_v2(self->db, sqlQuery, strlen(sqlQuery), &stmt, 0);
	//sqlite3_bind_int(stmt, 1, i);
	//puts("gdg");
	int rc = sqlite3_step(stmt);
	//puts("gdg");
	while (SQLITE_ROW == rc){
		admin = malloc(sizeof(struct admin_s));
		if (SQLITE_ERROR == rc) {
			printf("can't select admins\n");
			exit(1);
		} else
			_fillStudent(stmt, admin);
		list_add(list, admin, 0);
		//sqlite3_prepare_v2(self->db, sqlQuery, strlen(sqlQuery), &stmt, 0);
		rc = sqlite3_step(stmt);
	}
	return list;
}

/*
int db_insertWorker(db_t * self, admin_t * worker) {
    int newStudentId = -1;
    sqlite3_stmt * stmt = NULL;
    const char * sqlQuery = "INSERT INTO admins VALUES ( null, ?, ?, ?, ?, ?);";
    sqlite3_prepare_v2(self->db, sqlQuery, strlen(sqlQuery), &stmt, 0);
    sqlite3_bind_text(stmt, 1, worker->name, strlen(worker->name), NULL);
    sqlite3_bind_text(stmt, 2, worker->surname, strlen(worker->surname), NULL);
    sqlite3_bind_text(stmt, 3, worker->birthdate, strlen(worker->birthdate), NULL);
    sqlite3_bind_int(stmt, 4, worker->cash);
    sqlite3_bind_double(stmt, 5, (double)worker->experience_age);
    int rc = sqlite3_step(stmt);
    printf("\n THAT IS RC: %i\n", rc);
    if (SQLITE_OK == rc) {
        printf("ALL IS OK");
        exit(1);
    }
    if (SQLITE_ERROR == rc) {
        printf("can't select workers\n");
        exit(1);
    }
    sqlite3_finalize(stmt);
    return newStudentId;
}*/

char * db_to_html_id(int i)
{
    db_t * db = db_new("admin.db");
	char strBuf[100];
	char * text = malloc(sizeof (char) * 10000);
	printf("\nI in db to html: %i", i);
	admin_t * admin = db_getAdminById(db, i);
	text[0] = '\0';
	//strcat(text, "<!DOCTYPE html> <html> <head> <meta charset=\"UTF-8\"> <title>Workers</title> </head> <body> <table> <caption>Workers</caption> <tr> <th>Id</th> <th>Name</th> <th>Surname</th> <th>Birthdate</th> <th>Cash</th> <th>Experience age</th> <th>Shop name</th> </tr>");
	/*strcat(text, "<tr> <th>");
	sprintf(strBuf, "%i", pers->id);
    strcat(text, strBuf);
	strcat(text, "</th> <th>");
	strcat(text, pers->name);
    strcat(text, "</a> <th>");
    strcat(text, pers->surname);
    strcat(text, "</th> <th>");
    strcat(text, pers->birthdate);
    strcat(text, "</th> <th>");
    sprintf(strBuf, "%i", pers->cash);
    strcat(text, strBuf);
    strcat(text, "</th> <th>");
    sprintf(strBuf, "%.1f", pers->experience_age);
    strcat(text, strBuf);
    strcat(text, "</th> <th>");
	strcat(text, "</th> </tr>");
	puts(pers->name);
	strcat(text, "</table>");*/
	//strcat(text, "<tr> <th>");
	//itoa(i + 1, strBuf, 10);
	//strcat(text, strBuf);
	strcat(text, "<!DOCTYPE html> <html> <head> <meta charset=\"UTF-8\"> <title>Admins</title> </head> <body> <table> <caption>Admins</caption> <tr> <th>Id</th> <th>Name</th> <th>Surname</th> <th>Birthdate</th> <th>Rate</th> <th>Creating year</th> <th>Followers</th> </tr>");
	strcat(text, "<tr> <th>");
	sprintf(strBuf, "%i", i);
	strcat(text, strBuf);
	strcat(text, "</th> <th> <a href=\"http://127.0.0.1:5000/api/admins/");
	strcat(text, strBuf);
	strcat(text, "\">");
	strcat(text, admin->name);
	strcat(text, "</a> <th>");
	strcat(text, admin->surname);
	strcat(text, "</th> <th>");
	itoa(admin->birthdate, strBuf, 10);
	strcat(text, strBuf);
	strcat(text, "</th> <th>");
	sprintf(strBuf, "%.2llf", admin->rate);
	strcat(text, strBuf);
	strcat(text, "</th> <th>");
	itoa(admin->creating_year, strBuf, 10);
	strcat(text, strBuf);
	strcat(text, "</th> <th>");
	itoa(admin->followers, strBuf, 10);
	strcat(text, strBuf);
	strcat(text, "</th> </tr>");
	strcat(text, "<a href=\"#\" onclick=\"doDelete()\">Delete</a> <script> function doDelete() { var xhttp = new XMLHttpRequest(); xhttp.open(\"DELETE\", \"http://127.0.0.1:5000/admins/");
	itoa(i, strBuf, 10);
	strcat(text, strBuf);
	strcat(text, "\", true); xhttp.send();}</script> <a href=\"http://127.0.0.1:5000/api/admins\">Back</a>");
	strcat(text, "</body> </html>");
	return text;
}
