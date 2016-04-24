#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"
#include <stdio.h>
#include "parse.h"
#include "struct.h"

void parse(char * text, admin ** p)
{
	cJSON * jList = cJSON_Parse(text);
	if (!jList) {
		printf("Error before[%s]\n", cJSON_GetErrorPtr());
		return 1;

	}
   else{
    int count = cJSON_GetArraySize(jList);
   for (int i = 0; i < count; i++) {
        cJSON * jItem = cJSON_GetArrayItem(jList, i);
        char * name = cJSON_GetObjectItem(jItem, "name")->valuestring;
        char * surname = cJSON_GetObjectItem(jItem, "surname")->valuestring;
        char * birthdate = cJSON_GetObjectItem(jItem, "birthdate")->valuestring;
        cJSON * jGroup = cJSON_GetObjectItem(jItem, "company");
        char * companyName = cJSON_GetObjectItem(jGroup, "Network")->valuestring;
        char * language = cJSON_GetObjectItem(jGroup, "language")->valuestring;
        int  release = cJSON_GetObjectItem(jGroup, "release")->valueint;
        printf("Admin%i :\nName: %s\tSurnm:%s\t birthdate %s\t Working :\n Company :%s Language:%s Release %i  \n",i + 1, name, surname, birthdate, companyName, language, release);
// set_admin(p[i,name,surname,birthdate,company,hours);


}
   }
    cJSON_Delete(jList);

}
