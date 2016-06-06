#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <windows.h>
#include "http.h"
#include "json.h"
#include <stddef.h>
#include "socket.h"
#define MAXBUFLEN 1000
#define NO_FLAGS_SET 0
#define PORT 80
int http_getPath(const char * const request, char * pathBuf, int maxPathBuf);
void server_homepage(socket_t * client);
http_request_t http_request_parse(const char * const request);
//void server_external(socket_t * client);
void server_database(socket_t * client);
void server_database_id(socket_t * client, http_request_t * req);
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

        http_request_t request = http_request_parse(buf);

        if (strcmp(request.uri, "/") == 0) {
            server_homepage(client);
        } else if (strcmp(request.uri, "/api/admins") == 0) {
			server_database(client);
		} else if (strcmp(request.uri, "/api/admins/") > 0) {
			server_database_id(client, &request);
		} else {
            error_massage(client, "404 - NOT FOUND!");
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
    const char pageText[1024] = "<!DOCTYPE html> <html> <head> <title>VXOD</title> </head> <body> <h1>My First Heading</h1> <p> <a href=\"http://127.0.0.1:5000/api/admins\">Pokazatb adminov</a></p> </body> </html>";
    char homeBuf[1024];
    sprintf(homeBuf,
        "HTTP/1.1 200 OK\n"
        "Content-Type: text/html\n"
        "Content-Length: %u\n"
        "\n%s", strlen(pageText), pageText);
    socket_write_string(client, homeBuf);
    socket_close(client);
}

http_request_t http_request_parse(const char * const request) {
    http_request_t req;
    // get method
    ptrdiff_t methodLen = strstr(request, " ") - request;  // find first whitespace
    memcpy(req.method, request, methodLen);
    req.method[methodLen] = '\0';
    // get uri
    const char * uriStartPtr = request + strlen(req.method) + 1;
    const char * uriEndPtr = strstr(uriStartPtr, " ");  // find second whitespace
    ptrdiff_t uriLen = uriEndPtr - uriStartPtr;
    memcpy(req.uri, uriStartPtr, uriLen);
    req.uri[uriLen] = '\0';
    return req;
}

void server_database(socket_t * client) {
	char strbuf[10240] = "";
	char buf[100000];
	FILE * file = fopen("Admins.xml", "r");
	while(fgets(buf, 1000, file) != NULL)
	{
		strcat(strbuf, buf);
		puts(buf);
	}
	list_t list = xml_to_list(strbuf);
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

void server_database_id(socket_t * client, http_request_t * req) {
	char strbuf[10240] = "";
	char buf[1000];
	if (strcmp(req->method, "GET") == 0){
		for (int i = 12; i < strlen(req->uri); i++)
			if (req->uri[i] < '0' || req->uri[i] > '9')
			{
				error_massage("wrong request!!", client);
				return;
			}
		FILE * file = fopen("Admins.xml", "r");
		while(fgets(buf, 1000, file) != NULL)
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
		FILE * file = fopen("Admins.xml", "r");
		while(fgets(buf, 1000, file) != NULL)
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
		file = fopen("Admins.xml", "w");
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

