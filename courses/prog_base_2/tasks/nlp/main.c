#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "text.h"
int main()
{   int i,j;
    char str[20] = "do1.txt";
    text_t * text = text_new(str);
   // if (text != NULL)
        //text_print(text);
    sentense_t * tmp = NULL;
    int flag = 0;
    for ( i = 0; i < text_sentence_count(text); i++)
    {
        tmp = text_get_sentence(text, i);
        for ( j = 0; j < sentence_word_count(tmp); j++)
        {
            flag = 0;
            while (strcmp(word_get_str(sentence_get_word(tmp, j)), "not") == 0)
            {
                j++;
                if (j == sentence_word_count(tmp))
                    break;
                    flag = 1;
            }
            if (flag == 1)
                flag = 0;
            else
            {
                sentence_del_word(tmp, j);
                j--;
            }
        }
    }

    FILE * file_out = NULL;
    file_out = fopen("posle.txt", "w");
    if (file_out == NULL)
        return 1;

    for ( i = 0; i < text_sentence_count(text); i++)
    {
        tmp = text_get_sentence(text, i);
        for ( j = 0; j < sentence_word_count(tmp); j++)
        {
            if (j < sentence_word_count(tmp) - 1)
                fprintf(file_out, "%s, ", word_get_str(sentence_get_word(tmp, j)));
            else
                fprintf(file_out, "%s\n", word_get_str(sentence_get_word(tmp, j)));
        }
    }
    text_print(text);
    text_free(text);
    fclose(file_out);

    return 0;
}
