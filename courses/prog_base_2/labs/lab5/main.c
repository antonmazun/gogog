#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <windows.h>
#include "http.h"
#include "xml.h"
#include "socket.h"
#include "db_manager.h"
#define MAXBUFLEN 1000
#define NO_FLAGS_SET 0
#define PORT 80
#include <stddef.h>
#include "socket.h"
int http_getPath(const char * const request, char * pathBuf, int maxPathBuf);
void server_homepage(socket_t * client);
void server_insert_admin(socket_t * client, http_request_t * req);
http_request_t * http_request_parse(const char * const request);
void server_database_api(socket_t * client) ;
//void server_external(socket_t * client);
void server_database(socket_t * client);
void server_database_id(socket_t * client, http_request_t * req);
void server_database_id_xml(socket_t * client, http_request_t * req);
void server_database_id_api(socket_t * client, http_request_t * req);
void error_massage(char * str, socket_t * client);
void server_database_select(socket_t * client, http_request_t * req);
SOCKET socket_new_();
int main() {
    lib_init();
    socket_t * server = socket_new();
    socket_bind(server, 5000);
    socket_listen(server);

   char buf[10000];
    char pathBuf[256];
    socket_t * client = NULL;

    while(1) {
		client = socket_accept(server);
        socket_read(client, buf, sizeof(buf));
		if (strlen(buf) == 0)
			continue;
        printf(">> Got request:\n%s\n", buf);

        http_getPath(buf, pathBuf, sizeof(pathBuf));

        http_request_t * request = http_request_parse(buf);

        if (strcmp(request->uri, "/") == 0) {
            server_homepage(client);
        } else if (strcmp(request->uri, "/admins") == 0) {
			server_database_api(client);
		} else if (strcmp(request->uri, "/api/admins/new") == 0){
			server_insert_admin(client, request);
		} else if (strcmp(request->uri, "/api/admins") >= 0) {
			server_database_select(client, request);
		} else if (strcmp(request->uri, "/admins/") > 0) {
			server_database_id(client, request);
		} else {
            error_massage("404 - NOT FOUND!", client);
        }
		socket_free(client);
    }
    socket_free(server);
    lib_free();
    return 0;
}

int http_getPath(const char * const request, char * pathBuf, int maxPathBuf) {
    // get method
    char method[8];
    ptrdiff_t methodLen = strstr(request, " ") - request;  // find first whitespace
    memcpy(method, request, methodLen);
    method[methodLen] = '\0';
    // get uri
    const char * uriStartPtr = request + strlen(method) + 1;
    const char * uriEndPtr = strstr(uriStartPtr, " ");  // find second whitespace
    ptrdiff_t uriLen = uriEndPtr - uriStartPtr;
    memcpy(pathBuf, uriStartPtr, uriLen);
    pathBuf[uriLen] = '\0';
    return uriLen;
}

void server_homepage(socket_t * client) {
    const char pageText[1024] = "<!DOCTYPE html> <html> <head> <title>Page Title</title> </head> <body> <h1>My First Heading</h1> <p> <a href=\"http://127.0.0.1:5000/api/admins\">Show persons</a></p> </body> </html>";
    char homeBuf[1024];
    sprintf(homeBuf,
        "HTTP/1.1 200 OK\n"
        "Content-Type: text/html\n"
        "Content-Length: %u\n"
        "\n%s", strlen(pageText), pageText);
    socket_write_string(client, homeBuf);
    socket_close(client);
}

http_request_t * http_request_parse(const char * const request) {
    http_request_t * req = malloc(sizeof(struct http_request_s));
    // get method
    ptrdiff_t methodLen = strstr(request, " ") - request;  // find first whitespace
    memcpy(req->method, request, methodLen);
    req->method[methodLen] = '\0';
    // get uri
    const char * uriStartPtr = request + strlen(req->method) + 1;
    const char * uriEndPtr = strstr(uriStartPtr, " ");  // find second whitespace
    ptrdiff_t uriLen = uriEndPtr - uriStartPtr;
    memcpy(req->uri, uriStartPtr, uriLen);
    req->uri[uriLen] = '\0';

    const char * bodyStartPtr = strstr(request, "\r\n\r\n") + strlen("\r\n\r\n");
    const char * cur = bodyStartPtr;
    const char * pairEndPtr = cur;
    const char * eqPtr = cur;
    while (strlen(cur) > 0) {
        pairEndPtr = strchr(cur, '&');
        if (NULL == pairEndPtr) {
            pairEndPtr = cur + strlen(cur);
        }
        keyvalue_t kv;
        // get key
        eqPtr = strchr(cur, '=');
        ptrdiff_t keyLen = eqPtr - cur;
        memcpy(kv.key, cur, keyLen);
        kv.key[keyLen] = '\0';
        // get value
        eqPtr++;
        ptrdiff_t valueLen = pairEndPtr - eqPtr;
        memcpy(kv.value, eqPtr, valueLen);
        kv.value[valueLen] = '\0';
        // insert key-value pair into request form list
        req->formLength += 1;
        req->form = realloc(req->form, sizeof(keyvalue_t) * req->formLength);
        req->form[req->formLength - 1] = kv;
        cur = pairEndPtr + ((strlen(pairEndPtr) > 0) ? 1 : 0);
    }
    return req;
}

void error_massage(char * str, socket_t * client)
{
    char homeBuf[1024];
    sprintf(homeBuf,
        "HTTP/1.1 404 \n"
        "Content-Type: text/html\n"
        "Content-Length: %u\n"
        "\n%s", strlen(str), str);
    socket_write_string(client, homeBuf);
    socket_close(client);
}

void server_database(socket_t * client) {
	char strbuf[10240] = "";
	char buf[1000];
	FILE * file = fopen("newBase.xml", "r");
	while(fgets(buf, 1000, file) != NULL)
	{
		strcat(strbuf, buf);
		puts(buf);
	}
	list_t list = xml_to_list(strbuf);
	if (list == NULL)
	{
		error_massage("error, no admins", client);
		return;
	}
	puts(((struct admin_s *)list_get(list, 0))->name);
	char * text = list_to_html(list);
	sprintf(strbuf,
		"HTTP/1.1 200 OK\n"
		"Content-Type: text/html\n"
		"Content-Length: %u\n"
		"Connection: keep-alive\n"
		"\n%s", strlen(text), text);
	//free(allStudentsJson);
	free (text);
	fclose(file);
    socket_write_string(client, strbuf);
    socket_close(client);
}

void server_database_api(socket_t * client) {
	char strbuf[10240] = "";
	char buf[10000];
	FILE * file = fopen("newBase.xml", "r");
	while(fgets(buf, 1000, file) != NULL)
	{
		strcat(strbuf, buf);
	}
	sprintf(buf,
		"HTTP/1.1 200 OK\n"
		"Content-Type: text/xml\n"
		"Content-Length: %u\n"
		"Connection: keep-alive\n"
		"\n%s", strlen(strbuf), strbuf);
	//free(allStudentsJson);s
	fclose(file);
    socket_write_string(client, buf);
    socket_close(client);
}

const char *
http_request_getArg(http_request_t * self, const char * key) {
    for (int i = 0; i < self->formLength; i++) {
        if (strcmp(self->form[i].key, key) == 0) {
            printf("\nKey:%s Value: %s\n", self->form[i].key, self->form[i].value);
            return self->form[i].value;
        }
    }
    return NULL;
}

void server_database_id_xml(socket_t * client, http_request_t * req) {
	char strbuf[10240] = "";
	char buf[10000];
	if (strcmp(req->method, "GET") == 0){
		for (int i = 12; i < strlen(req->uri); i++)
			if (req->uri[i] < '0' || req->uri[i] > '9')
			{
				error_massage("wrong request!!", client);
				return;
			}
		FILE * file = fopen("newBase.xml", "r");
		while(fgets(buf, 10000, file) != NULL)
		{
			strcat(strbuf, buf);
			puts(buf);
		}
		list_t list = xml_to_list(strbuf);
		char id[10];
		for (int i = 12; i < strlen(req->uri); i++)
		{
			id[i - 12] = req->uri[i];
		}
		id[strlen(req->uri) - 12] = '\0';
		int id_int = atoi(id);
		if (id_int > list_size(list))
		{
			error_massage("client whith such id don't exist!!", client);
			return;
		}
		//puts(((struct admin_s *)list_get(list, 0))->name);
		char * text = list_to_html_id(list, id_int - 1);
		if (text == NULL)
		{
			error_massage("unknown error", client);
			return;
		}
		puts(id);
		sprintf(strbuf,
			"HTTP/1.1 200 OK\n"
			"Content-Type: text/html\n"
			"Content-Length: %u\n"
			"Connection: keep-alive\n"
			"\n%s", strlen(text), text);
		//free(allStudentsJson);
		free (text);
		fclose(file);
		socket_write_string(client, strbuf);
		socket_close(client);
	}
	else if (strcmp(req->method, "DELETE") == 0)
	{
		/*for (int i = 12; i < strlen(req->uri); i++)
			if (req->uri[i] < '0' || req->uri[i] > '9')
			{
				error_massage("wrong request!!", client);
				return;
			}*/
		FILE * file = fopen("newBase.xml", "r");
		while(fgets(buf, 10000, file) != NULL)
		{
			strcat(strbuf, buf);
			puts(buf);
		}
		list_t list = xml_to_list(strbuf);
		char id[10];
		for (int i = 12; i < strlen(req->uri); i++)
		{
			if (req->uri[i] != '#')
				id[i - 12] = req->uri[i];
			else id[i - 12] = '\0';
		}
		puts(id);
		int id_int = atoi(id);
		if (id_int > list_size(list))
		{
			error_massage("client whith such id don't exist!!", client);
			return;
		}
		list_del(list, id_int - 1);
		char * text = list_to_xml1(list);
		fclose(file);
		file = fopen("newBase.xml", "w");
		fprintf(file, "%s", text);
		free (text);
		//puts(((struct admin_s *)list_get(list, 0))->name);
		text = list_to_html(list);
		if (text == NULL)
		{
			error_massage("unknown error", client);
			return;
		}
		puts(id);
		sprintf(strbuf,
			"HTTP/1.1 200 OK\n"
			"Content-Type: text/html\n"
			"Content-Length: %u\n"
			"Connection: keep-alive\n"
			"\n%s", strlen(text), text);
		//free(allStudentsJson);*/
		free (text);
		fclose(file);
		socket_write_string(client, strbuf);
		socket_close(client);
	}
	else if (strcmp(req->method, "OPTIONS") == 0)
	{
		sprintf(strbuf,
            "HTTP/1.1 200 OK\n"
            "Access-Control-Allow-Origin: *\n"
            "Access-Control-Allow-Methods: DELETE\n"
            "\n");
		socket_write_string(client, strbuf);
		socket_close(client);
	}
}


void server_database_id_api(socket_t * client, http_request_t * req) {
	char strbuf[10240] = "";
	char buf[10000];
	if (strcmp(req->method, "GET") == 0){
		for (int i = 8; i < strlen(req->uri); i++)
			if (req->uri[i] < '0' || req->uri[i] > '9')
			{
				error_massage("wrong request!!", client);
				return;
			}
		FILE * file = fopen("newBase.xml", "r");
		while(fgets(buf, 10000, file) != NULL)
		{
			strcat(strbuf, buf);
			puts(buf);
		}
		list_t list = xml_to_list(strbuf);
		char id[10];
		for (int i = 8; i < strlen(req->uri); i++)
		{
			id[i - 8] = req->uri[i];
		}
		id[strlen(req->uri) - 8] = '\0';
		int id_int = atoi(id);
		if (id_int > list_size(list))
		{
			error_massage("client whith such id don't exist!!", client);
			return;
		}
		char * text = list_to_xml_id(list, id_int - 1);
		if (text == NULL)
		{
			error_massage("unknown error", client);
			return;
		}
		puts(id);
		sprintf(strbuf,
			"HTTP/1.1 200 OK\n"
			"Content-Type: text/xml\n"
			"Content-Length: %u\n"
			"Connection: keep-alive\n"
			"\n%s", strlen(text), text);
		//free(allStudentsJson);
		free (text);
		fclose(file);
		socket_write_string(client, strbuf);
		socket_close(client);
	}
}

static char * readHTML(char * nameFile){
         char * page = malloc(sizeof(char) * 5000);
		 char tmp[5000];
         FILE* finput = fopen(nameFile, "r");
         int len = fread(tmp, sizeof(char), sizeof(tmp)/sizeof(char), finput);
		 //strcat(page, tmp);
         puts("\n");
         printf("%i", len);
         puts("\n");
         tmp[len] = '\0';
         fclose(finput);
		 sprintf(page,  "HTTP/1.1 200 OK\nContent-length: %u\nContent-type: text/html\n\n%s", len,  tmp);
         return page;
}

void server_insert_admin(socket_t * client, http_request_t * req){
    if(strcmp(req->method, "GET") == 0)
	{
		socket_write_string(client, readHTML("webpage.html"));
	}
     else if(strcmp(req->method, "POST") == 0)
	{
		char result[10000];
		char buf[10000];
		char strbuf[10000];
		strbuf[0] = '\0';
		puts("done");
		const char * w_name = http_request_getArg(req, "name");
		const char * w_surname = http_request_getArg(req, "surname");
		int w_birthdate = atoi(http_request_getArg(req, "birthdate"));
		double w_rate = atof(http_request_getArg(req, "rate"));
		int w_creating_year = atoi(http_request_getArg(req, "creating_year"));
		int w_followers = atoi(http_request_getArg(req, "followers"));
		puts("done1");
		admin_t * pers = malloc(sizeof(struct admin_s));
		strcpy(pers->name, w_name);
		strcpy(pers->surname, w_surname);
		pers->birthdate = w_birthdate;
		pers->rate = w_rate;
		pers->creating_year = w_creating_year;
		pers->followers = w_followers;

		db_t * db = db_new("admin.db");
		db_insertAdmin(db, pers);
		list_t list = database_to_list_select(db, "SELECT * FROM admins;");
		char * text = list_to_html(list);
		sprintf(result,
				"HTTP/1.1 200 OK\n"
				"Content-length: %u\n"
				"Content-type: text/html\n"
				"\n"
				"%s",
				strlen(text), text);
		free(text);

		socket_write_string(client, result);
	}

}
/*
sprintf(strbuf,
            "HTTP/1.1 200 OK\n"
            "Access-Control-Allow-Origin: *\n"
            "Access-Control-Allow-Methods: DELETE\n"
            "\n");
*/

void server_database_select(socket_t * client, http_request_t * req) {
	char * keys[20];
	char * val[20];
	int index = 0;
	for (int i = 0; i < strlen(req->uri); i++)
	{
		if (req->uri[i] == '?')
		{
			index = i;
			break;
		}
	}
	char select[200];
	int count = 0;
	if (index == 0)
	{
		strcpy(select, "SELECT * FROM admins WHERE Id > 0;");
	}
	else
	{
		for (int i = ++index; i < strlen(req->uri); i++)
		{
			if (req->uri[i] == '=')
			{
				keys[count] = malloc(sizeof(char) * (i - index + 1));
				for (int j = 0; j < i - index; j++)
				{
					keys[count][j] = req->uri[index + j];

				}
				keys[count][i - index] = '\0';
				index = i + 1;
			}
			if (req->uri[i] == '&')
			{
				val[count] = malloc(sizeof(char) * (i - index + 1));
				for (int j = 0; j < i - index; j++)
				{
					val[count][j] = req->uri[index + j];

				}
				val[count++][i - index] = '\0';
				index = i + 1;
			}
			if (req->uri[i + 1] == '\0')
			{
				val[count] = malloc(sizeof(char) * (i - index + 2));
				for (int j = 0; j < i - index + 1; j++)
				{
					val[count][j] = req->uri[index + j];

				}
				val[count++][i - index + 1] = '\0';
				index = i + 1;
			}
		}
		strcpy(select, "SELECT * FROM admins WHERE ");
		for (int i = 0; i < count; i++)
		{
			strcat(select, keys[i]);
			strcat(select, " > ");
			strcat(select, val[i]);
			if (i < count - 1)
				strcat(select, " AND ");

		}
		strcat(select, ";");
	}
	for (int i = 0; i < count; i++)
	{
		puts(keys[i]);
		puts(val[i]);
	}
	puts(select);
	char strbuf[10240] = "";
	char buf[1000];/*
	FILE * file = fopen("Untitled1.xml", "r");
	while(fgets(buf, 1000, file) != NULL)
	{
		strcat(strbuf, buf);
		puts(buf);
	}
	*/
	db_t * db = db_new("admin.db");
	list_t list = database_to_list_select(db, select);
	if (list_size(list) == 0)
	{
		error_massage("no matches", client);
		list_free(list);
		return;
	}
	puts(((struct admin_s *)list_get(list, 0))->name);
	char * text = list_to_html(list);
	sprintf(strbuf,
		"HTTP/1.1 200 OK\n"
		"Content-Type: text/html\n"
		"Content-Length: %u\n"
		"Connection: keep-alive\n"
		"\n%s", strlen(text), text);
	//free(allStudentsJson);
	free (text);
	//fclose(file);
    socket_write_string(client, strbuf);
    socket_close(client);
}

void server_database_id(socket_t * client, http_request_t * req) {
	char strbuf[10240] = "";
	char buf[10000];
	if (strcmp(req->method, "GET") == 0){
		for (int i = 8; i < strlen(req->uri); i++)
			if (req->uri[i] < '0' || req->uri[i] > '9')
			{
				error_massage("wrong request!!", client);
				return;
			}
		char id[10];
		for (int i = 8; i <= strlen(req->uri); i++)
		{
			id[i - 8] = req->uri[i];
		}
		int id_int = atoi(id);
        printf("\nId after atoi: %i", id_int);
		char * text = db_to_html_id(id_int);
		if (text == NULL)
		{
			error_massage("unknown error", client);
			return;
		}
		//puts(id);
		sprintf(strbuf,
			"HTTP/1.1 200 OK\n"
			"Content-Type: text/html\n"
			"Content-Length: %u\n"
			"Connection: keep-alive\n"
			"\n%s", strlen(text), text);
		//free(allStudentsJson);
		free (text);
		socket_write_string(client, strbuf);
		socket_close(client);
	}
	else if (strcmp(req->method, "DELETE") == 0)
	{
	    db_t * db = db_new("admin.db");
		char id[10];
		for (int i = 8; i < strlen(req->uri); i++)
		{
			if (req->uri[i] != '#')
				id[i - 8] = req->uri[i];
			else id[i - 8] = '\0';
		}
		id[strlen(req->uri) - 8] = '\0';

		int id_int = atoi(id);
		printf("\nId: %i", id_int);
		db_deleteAdmin(db, id_int);
		list_t list = database_to_list_select(db, "SELECT * FROM admins;");
		char * text = list_to_html(list);
		if (text == NULL)
		{
			error_massage("unknown error", client);
			return;
		}
		puts(id);
		sprintf(strbuf,
			"HTTP/1.1 200 OK\n"
			"Content-Type: text/html\n"
			"Content-Length: %u\n"
			"Connection: keep-alive\n"
			"\n%s", strlen(text), text);
		//free(allStudentsJson);*/
		free (text);
		socket_write_string(client, strbuf);
		socket_close(client);
	}
	else if (strcmp(req->method, "OPTIONS") == 0)
	{
		sprintf(strbuf,
            "HTTP/1.1 200 OK\n"
            "Access-Control-Allow-Origin: *\n"
            "Access-Control-Allow-Methods: DELETE\n"
            "\n");
		socket_write_string(client, strbuf);
		socket_close(client);
	}
}

