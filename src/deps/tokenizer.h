typedef struct __tokenlist Tokenlist;
    
Tokenlist *t_tokenize_string(char *str);
char *t_next_token(Tokenlist *tl);
void t_free(Tokenlist *tl);
