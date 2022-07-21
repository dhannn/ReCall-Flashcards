#include "tokenizer.h"
#include "../external/queue.h"
#include "../external/stringlib.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define COURSE_OPEN_DELIM   '['
#define COURSE_CLOSE_DELIM  ']'
#define NEWLINE             '\n'
#define ANSWER_DELIM        '-'

#define SAMPLE \
"[CCICOMP] Hardware Components" \
"\n"

#define SAMPLE2 \
"\n" \
"\nExplain the machine cycle." \
"\n- CPU fetches instructions from RAM. Control unit decodes the instructions."\
"\nALU executes instructions. Results are stored back to RAM."\
"\n"\
"\nDiffferentiate random-access memory and hard drive."\
"\n- RAM is volatile memory that is cleared when shutdown while the hard drive "\
"\nstores long-term non-volatile memory. RAM is faster while the hard drive is slower."

typedef enum {
    T_COURSE_DELIMITER,
    T_ANSWER_DELIMITER,
    T_NEWLINE,
    T_STRING
} _TokenType;

typedef struct __token {
    char *str;
    _TokenType type;
} Token;

struct __tokenlist {
    queue_list_t tokens;
    int size;
};

/* -------------------------------------------------------------------------- */
/*                         PRIVATE FUNCTION PROTOTYPES                        */
/* -------------------------------------------------------------------------- */
static Token *__next_token(char **str);
static char *__extract_alnum_token(char *str);
static char *__extract_nonalnum_token(char *str);
static _TokenType __get_token_type(char *token);

/* -------------------------------------------------------------------------- */
/*                       PUBLIC FUNCTION IMPLEMENTATIONS                      */
/* -------------------------------------------------------------------------- */

Tokenlist *t_tokenize_string(char *str)
{
    Tokenlist *tl = malloc(sizeof(Tokenlist));
    tl->tokens = q_init();
    
    int count = 0;

    char *curr = str;
    while(*curr != '\0') {
        Token *currentToken = __next_token(&curr);
        q_push(tl->tokens, currentToken);

        count++;
    }

    tl->size = count;
    return tl;
}

/* -------------------------------------------------------------------------- */
/*                      PRIVATE FUNCTION IMPLEMENTATIONS                      */
/* -------------------------------------------------------------------------- */

static Token *__next_token(char **str)
{
    Token *token = malloc(sizeof(Token));

    char *temp = *str;
    char *tokenString;
    _TokenType type;

    if(isalnum(*temp)) {
        tokenString = __extract_alnum_token(temp);
    } else {
        tokenString = __extract_nonalnum_token(temp);
    }

    type = __get_token_type(tokenString);

    token->str = tokenString;
    token->type = type;

    *str += strlen(tokenString);

    return token;
}

static char *__extract_alnum_token(char *str)
{
    char *temp = s_duplicate(str);
    char *curr = temp;
    while(isalnum(*curr) || *curr == ' ') 
        curr++;
    
    *curr = '\0';

    return temp;
}

static char *__extract_nonalnum_token(char *str)
{
    char *temp = s_duplicate(str);
    temp[1] = '\0';

    return temp;
}

static _TokenType __get_token_type(char *token)
{
    if(isalnum(*token))
        return T_STRING;
    
    switch(*token) {
        case NEWLINE:
            return T_NEWLINE;
            break;
        case ANSWER_DELIM:
            return T_ANSWER_DELIMITER;
            break;
        case COURSE_OPEN_DELIM:
        case COURSE_CLOSE_DELIM:
            return T_COURSE_DELIMITER;
            break;
    }

    return T_STRING;
}
