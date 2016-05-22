#include "text.h"
#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
struct text_s{
    list_t sentense;
};

struct sentense_s{
    list_t word;
};

struct word_s{
    char * word;
};

void text_print(text_t * text)
{
    int i , j;
    list_t tmp_list;
        for (i = 0; i < list_size(text->sentense); i++)
        {
            tmp_list = ((sentense_t *)list_get(text->sentense, i))->word;
            for ( j = 0; j < list_size(tmp_list); j++)
                printf("%s ", ((word_t *)list_get(tmp_list, j))->word);
            if (list_size(tmp_list))
                printf("\n");
        }
}

sentense_t * text_get_sentence(text_t * text, int pos)
{
    return (sentense_t *)list_get(text->sentense, pos);
}

word_t * sentence_del_word(sentense_t * sentense, int pos)
{
    return (word_t *)list_del(sentense->word, pos);
}

sentense_t * text_del_sentence(text_t * text, int pos)
{
    return (sentense_t *)list_get(text->sentense, pos);
}

char * word_get_str(word_t * word)
{
    return word->word;
}

word_t * sentence_get_word(sentense_t * sentense, int pos)
{
    return (word_t *)list_get(sentense->word, pos);
}

int text_sentence_count(text_t * text)
{
    return list_size(text->sentense);
}

int sentence_word_count(sentense_t * sentense)
{
    return list_size(sentense->word);
}

sentense_t * sentence_new()
{
    sentense_t * sen = malloc(sizeof(struct sentense_s));
    sen->word = list_new();
    return sen;
}

void process_sentence(char * sentense, sentense_t * list)
{
    int i;
    word_t * data;
    char * tmp_word;
    char * word = NULL;
    word = strtok(sentense, " ");
    while (word != NULL)
    {
        tmp_word = malloc(sizeof(char) * (strlen(word) + 1));
        data = malloc(sizeof (struct word_s));
        data->word =tmp_word;
        for ( i = 0; i < strlen(word); i++)
            tmp_word[i] = word[i];
        tmp_word[strlen(word)] = '\0';
        puts(tmp_word);
        list_add(list->word, data, list_size(list->word));
        word = strtok(NULL, " ");
    }
}
void process_buffer(char * buffer, list_t list)
{
    int i;
    puts(buffer);
    sentense_t * sentense_list;
    char * sentence = NULL;
    char * tmp_sen;
    sentence = strtok(buffer, ".");
    while (sentence != NULL)
    {
        sentense_list = sentence_new();
        list_add(list, sentense_list, list_size(list));
        tmp_sen = malloc(sizeof(char) * (strlen(sentence) + 3));
        for ( i = 0; i < strlen(sentence) + 1; i++)
            tmp_sen[i] = sentence[i];
        tmp_sen[strlen(sentence) + 1] = ' ';
        tmp_sen[strlen(sentence) + 2] = '\0';
        process_sentence(tmp_sen, sentense_list);
        free(tmp_sen);
        sentence = strtok(NULL, " ");
    }
}

text_t * text_new(char * filename)
{
    text_t * text = malloc(sizeof(struct text_s));
    text->sentense = list_new();
    FILE * file_in = NULL;
    file_in = fopen(filename, "r");
    if (file_in == NULL)
        return NULL;
    char buffer[1000];
    while (fgets(buffer, sizeof buffer, file_in) != NULL)
    {
        process_buffer(buffer, text->sentense);
    }
    fclose(file_in);
    return text;
}

void text_free(text_t * text)
{ int i,j;
    sentense_t * tmp;
    for ( i = 0; i < text_sentence_count(text); i++)
    {
        tmp = text_get_sentence(text, i);
        for ( j = 0; j < sentence_word_count(tmp); j++)
        {
            free(word_get_str(sentence_get_word(tmp, j)));
            free(sentence_del_word(tmp, j));
        }
        list_free(tmp->word);
        free(text_del_sentence(text, i));
    }
    list_free(text->sentense);
    free(text);

}
