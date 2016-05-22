#ifndef TEXT_H_INCLUDED
#define TEXT_H_INCLUDED
typedef struct text_s text_t;
typedef struct sentense_s sentense_t;
typedef struct word_s word_t;

text_t * text_new(char * filename);
sentense_t * sentence_new();

void text_print(text_t * text);
int sentence_word_count(sentense_t * sentense);
int text_sentence_count(text_t * text);
word_t * sentence_get_word(sentense_t * sentense, int pos);
sentense_t * text_get_sentence(text_t * text, int pos);
char * word_get_str(word_t * word);
sentense_t * text_del_sentence(text_t * text, int pos);
word_t * sentence_del_word(sentense_t * sentense, int pos);
void text_free(text_t * text);
#endif // TEXT_H_INCLUDED
