
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include "list.h"
#include "json.h"


list_t xml_to_list(char *text) {

	xmlDoc * xDoc;
	xDoc = xmlReadMemory(text, strlen(text), NULL, NULL, 0);
    if(NULL == xDoc){
        printf("error");
        return 0;
    }
	list_t persons = list_new();
	//struct person * pers = malloc(sizeof(struct admin_s));
    xmlNode * xRootEl;
    int i = 0;
    xRootEl = xmlDocGetRootElement(xDoc);
	int flag = 0;
    for(xmlNode * xCur = xRootEl->children; NULL != xCur ;xCur = xCur->next){
		struct admin_s * pers = malloc(sizeof(struct admin_s));
		flag = 0;
        for(xmlNode * xJ = xCur->children; NULL != xJ ;xJ = xJ->next){
            if(XML_ELEMENT_NODE == xJ->type){
				flag = 1;
                const char * content = xmlNodeGetContent(xJ);
                if(strcmp(xJ->name, "name") == 0){
                    strcpy(pers->name, content);
                }
                if(strcmp(xJ->name, "surname") == 0){
                    strcpy(pers->surname, content);
                }
                if(strcmp(xJ->name, "birthdate") == 0){
                    pers->birthdate = atoi(content);
                }
                if(strcmp(xJ->name, "rate") == 0){
                    pers->rate = atof(content);
                }
                if(strcmp(xJ->name, "creating_year") == 0){
                    pers->creating_year = atoi(content);
                }
                if(strcmp(xJ->name, "followers") == 0){
                    pers->followers = atoi(content);
                }

            }

        }
		if (flag)
			list_add(persons, pers, list_size(persons));
    }
	return persons;
}


char * list_to_xml1(list_t list) {
    xmlDoc * doc = NULL;
	xmlNode * rootNode = NULL;
	xmlNode * studentNode = NULL;
	xmlNode * groupNode = NULL;
	char strBuf[100];
	char * text = malloc(sizeof (char) * 10000);
	doc = xmlNewDoc("1.0");
	rootNode = xmlNewNode(NULL, "admins");
	//FILE * file = fopen("newBase.xml", "w");

	/*int id;
    char name[256];
    char surname[256];
    int birthdate;
    float rate;
    int creating_year;
    int followers;*/
	for (int i = 0;i < list_size(list); i++)
	{
		if (list_get(list, i) == NULL)
			continue;
		puts(((struct admin_s *)list_get(list, i))->name);
		xmlDocSetRootElement(doc, rootNode);
		studentNode = xmlNewChild(rootNode, NULL, "admin", NULL);
		xmlNewChild(studentNode, NULL, "name", ((struct admin_s *)list_get(list, i))->name);
		xmlNewChild(studentNode, NULL, "surname", ((struct admin_s *)list_get(list, i))->surname);
		sprintf(strBuf, "%i", ((struct admin_s *)list_get(list, i))->birthdate);
		xmlNewChild(studentNode, NULL, "birthdate", strBuf);
		sprintf(strBuf, "%llf", ((struct admin_s *)list_get(list, i))->rate);
		xmlNewChild(studentNode, NULL, "rate", strBuf);
		//groupNode = xmlNewChild(studentNode, NULL, "work", NULL);
		//xmlNewProp(groupNode, "name", ((struct person *)list_get(list, i))->work.name);
		sprintf(strBuf, "%i", ((struct admin_s *)list_get(list, i))->creating_year);
		xmlNewChild(studentNode, NULL, "creating_year",strBuf);
		sprintf(strBuf, "%i", ((struct admin_s *)list_get(list, i))->followers);
		xmlNewChild(studentNode, NULL, "followers", strBuf);
			puts("sdfgsfbsgf");
	}
	xmlBuffer * bufferPtr = xmlBufferCreate();
		xmlNodeDump(bufferPtr, NULL, (xmlNode *)doc, 0, 1);
		printf("%s", (const char *)bufferPtr->content);
		//fprintf(file, "%s", (const char *)bufferPtr->content);
		strcpy(text, (const char *)bufferPtr->content);
		xmlBufferFree(bufferPtr);
	//fclose(file);
      xmlFreeDoc(doc);
	xmlCleanupParser();
	return text;
}

char * list_to_html(list_t list)
{
	xmlDoc * doc = NULL;
	xmlNode * rootNode = NULL;
	xmlNode * studentNode = NULL;
	xmlNode * groupNode = NULL;
	char strBuf[100];
	char * text = malloc(sizeof (char) * 10000);
	text[0] = '\0';
	strcat(text, "<!DOCTYPE html> <html> <head> <meta charset=\"UTF-8\"> <title>Admins</title> </head> <body> <table> <caption>Admins</caption> <tr> <th>Id</th> <th>Name</th> <th>Surname</th> <th>Birthdate</th> <th>Rate</th> <th>Creating year</th> <th>Followers</th> </tr>");
	for (int i = 0;i < list_size(list); i++)
	{
		if (list_get(list, i) == NULL)
			continue;
		//<tr> <th>Id</th> <th>Name</th> <th>Surname</th> <th>Birthdate</th> <th>Rate</th> <th>Creating year</th> <th>Followers</th> </tr>");
		strcat(text, "<tr> <th>");
		itoa(i + 1, strBuf, 10);
		strcat(text, strBuf);
		strcat(text, "</th> <th> <a href=\"http://127.0.0.1:5000/api/admins/");
		strcat(text, strBuf);
		strcat(text, "\">");
		strcat(text, ((struct admin_s *)list_get(list, i))->name);
		strcat(text, "</a> <th>");
		strcat(text, ((struct admin_s *)list_get(list, i))->surname);
		strcat(text, "</th> <th>");
		itoa(((struct admin_s *)list_get(list, i))->birthdate, strBuf, 10);
		strcat(text, strBuf);
		strcat(text, "</th> <th>");
	    sprintf(strBuf, "%.2llf", ((struct admin_s *)list_get(list, i))->rate);
		strcat(text, strBuf);
		strcat(text, "</th> <th>");
		itoa(((struct admin_s *)list_get(list, i))->creating_year, strBuf, 10);
		strcat(text, strBuf);
		strcat(text, "</th> <th>");
		itoa(((struct admin_s *)list_get(list, i))->followers, strBuf, 10);
		strcat(text, strBuf);
		strcat(text, "</th> </tr>");
		puts(((struct admin_s *)list_get(list, i))->name);
	}
	strcat(text, "</table> </body> </html>");
	return text;
}

char * list_to_html_id(list_t list, int i)
{
	xmlDoc * doc = NULL;
	xmlNode * rootNode = NULL;
	xmlNode * studentNode = NULL;
	xmlNode * groupNode = NULL;
	char strBuf[100];
	char * text = malloc(sizeof (char) * 10000);
	text[0] = '\0';
	strcat(text, "<!DOCTYPE html> <html> <head> <meta charset=\"UTF-8\"> <title>Admins</title> </head> <body> <table> <caption>Admins</caption> <tr> <th>Id</th> <th>Name</th> <th>Surname</th> <th>Birthdate</th> <th>Rate</th> <th>Creating year</th> <th>Followers</th> </tr>");
	if (list_get(list, i) == NULL)
		return NULL;
	//<tr> <th>Id</th> <th>Name</th> <th>Surname</th> <th>Birthdate</th> <th>Rate</th> <th>Creating year</th> <th>Followers</th> </tr>");
	strcat(text, "<tr> <th>");
	itoa(i + 1, strBuf, 10);
	strcat(text, strBuf);
	strcat(text, "</th> <th>");
	strcat(text, ((struct admin_s *)list_get(list, i))->name);
	strcat(text, "</th> <th>");
	strcat(text, ((struct admin_s *)list_get(list, i))->surname);
	strcat(text, "</th> <th>");
	itoa(((struct admin_s *)list_get(list, i))->birthdate, strBuf, 10);
	strcat(text, strBuf);
	strcat(text, "</th> <th>");
	sprintf(strBuf, "%.2llf", ((struct admin_s *)list_get(list, i))->rate);
	strcat(text, strBuf);
	strcat(text, "</th> <th>");
	itoa(((struct admin_s *)list_get(list, i))->creating_year, strBuf, 10);
	strcat(text, strBuf);
	strcat(text, "</th> <th>");
	itoa(((struct admin_s *)list_get(list, i))->followers, strBuf, 10);
	strcat(text, strBuf);
	strcat(text, "</th> </tr>");
	puts(((struct admin_s *)list_get(list, i))->name);
	strcat(text, "</table>");
	strcat(text, "<a href=\"#\" onclick=\"doDelete()\">Delete</a> <script> function doDelete() { var xhttp = new XMLHttpRequest(); xhttp.open(\"DELETE\", \"http://127.0.0.1:5000/api/admins/");
	itoa(i + 1, strBuf, 10);
	strcat(text, strBuf);
	strcat(text, "\", true); xhttp.send();}</script> <a href=\"http://127.0.0.1:5000/api/admins\">Back</a>");
	strcat(text, "</body> </html>");
	return text;
}
