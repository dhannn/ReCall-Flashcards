typedef struct __tokenlist Tokenlist;
    
Tokenlist *t_tokenize_string(char *str);
void t_free(Tokenlist *tl);
