#include "../src/deps/tokenizer.c"
#include "minunit.h"
#include <string.h>
#include <stdio.h>

char *str;

void extract_alnum__setup()
{
    str = malloc(sizeof(char));
}

void extract_alnum__teardown()
{
    free(str);
}

MU_TEST(extract_alnum1) 
{
    char *input = "h";
    char *expected = "h";

    str = realloc(str, strlen(input) + 1);
    strcpy(str, input);

    char *actual = extract_alnum_token(str);
    mu_assert_string_eq(expected, actual);
    mu_assert_string_eq(input, str);
};

MU_TEST(extract_alnum2) 
{
    char *input = "hello";
    char *expected = "hello";

    str = realloc(str, strlen(input) + 1);
    strcpy(str, input);

    char *actual = extract_alnum_token(str);
    mu_assert_string_eq(expected, actual);
    mu_assert_string_eq(input, str);
};

MU_TEST(extract_alnum3) 
{
    char *input = "hello world";
    char *expected = "hello world";

    str = realloc(str, strlen(input) + 1);
    strcpy(str, input);

    char *actual = extract_alnum_token(str);
    mu_assert_string_eq(expected, actual);
    mu_assert_string_eq(input, str);
};

MU_TEST(extract_alnum4) 
{
    char *input = "h3llo world";
    char *expected = "h3llo world";

    str = realloc(str, strlen(input) + 1);
    strcpy(str, input);

    char *actual = extract_alnum_token(str);
    mu_assert_string_eq(expected, actual);
    mu_assert_string_eq(input, str);
};

MU_TEST(extract_alnum5) 
{
    char *input = "he!lo world";
    char *expected = "he";

    str = realloc(str, strlen(input) + 1);
    strcpy(str, input);

    char *actual = extract_alnum_token(str);
    mu_assert_string_eq(expected, actual);
    mu_assert_string_eq(input, str);
};

MU_TEST_SUITE(extract_alnum__tests)
{
    MU_SUITE_CONFIGURE(extract_alnum__setup, extract_alnum__teardown);

    MU_RUN_TEST(extract_alnum1);
    MU_RUN_TEST(extract_alnum2);
    MU_RUN_TEST(extract_alnum3);
    MU_RUN_TEST(extract_alnum4);
    MU_RUN_TEST(extract_alnum5);
}

void extract_nonalnum__setup()
{
    extract_alnum__setup();
}

void extract_nonalnum__teardown()
{
    extract_alnum__teardown();
}

MU_TEST(extract_nonalnum1)
{
    char *input = "!lo world";
    char *expected = "!";

    str = realloc(str, strlen(input) + 1);
    strcpy(str, input);

    char *actual = extract_nonalnum_token(str);
    mu_assert_string_eq(expected, actual);
    mu_assert_string_eq(input, str);

}

MU_TEST(extract_nonalnum2)
{
    char *input = "[Course Code]";
    char *expected = "[";

    str = realloc(str, strlen(input) + 1);
    strcpy(str, input);

    char *actual = extract_nonalnum_token(str);
    mu_assert_string_eq(expected, actual);
    mu_assert_string_eq(input, str);
}

MU_TEST(extract_nonalnum3)
{
    char *input = "] Hello World";
    char *expected = "]";

    str = realloc(str, strlen(input) + 1);
    strcpy(str, input);

    char *actual = extract_nonalnum_token(str);
    mu_assert_string_eq(expected, actual);
    mu_assert_string_eq(input, str);
}

MU_TEST_SUITE(extract_nonalnum__tests)
{
    MU_SUITE_CONFIGURE(extract_nonalnum__setup, extract_nonalnum__teardown);
    
    MU_RUN_TEST(extract_nonalnum1);
    MU_RUN_TEST(extract_nonalnum2);
    MU_RUN_TEST(extract_nonalnum3);
}

MU_TEST(get_token_type1)
{
    char *input = "Hello world";
    _TokenType expected = T_STRING;

    str = realloc(str, strlen(input) + 1);
    strcpy(str, input);

    _TokenType actual = get_token_type(str);
    mu_assert_int_eq(expected, actual);
}

MU_TEST(get_token_type2)
{
    char *input = "[";
    _TokenType expected = T_COURSE_DELIMITER;

    str = realloc(str, strlen(input) + 1);
    strcpy(str, input);

    _TokenType actual = get_token_type(str);
    mu_assert_int_eq(expected, actual);
}

MU_TEST(get_token_type3)
{
    char *input = "\n";
    _TokenType expected = T_NEWLINE;

    str = realloc(str, strlen(input) + 1);
    strcpy(str, input);

    _TokenType actual = get_token_type(str);
    mu_assert_int_eq(expected, actual);
}

MU_TEST(get_token_type4)
{
    char *input = "-";
    _TokenType expected = T_ANSWER_DELIMITER;

    str = realloc(str, strlen(input) + 1);
    strcpy(str, input);

    _TokenType actual = get_token_type(str);
    mu_assert_int_eq(expected, actual);
}

MU_TEST_SUITE(get_token_type__tests)
{
    MU_SUITE_CONFIGURE(extract_alnum__setup, extract_alnum__teardown);

    MU_RUN_TEST(get_token_type1);
    MU_RUN_TEST(get_token_type2);
    MU_RUN_TEST(get_token_type3);
    MU_RUN_TEST(get_token_type4);
}

/* -------------------------------------------------------------------------- */
/*                           t_tokenize_string test                           */
/* -------------------------------------------------------------------------- */

Tokenlist *tokenlist;

void t_tokenize_string__setup()
{
    return;
}

void t_tokenize_string__teardown()
{
    q_free_alt(tokenlist->tokens, true);
    free(tokenlist);
}

MU_TEST(t_tokenize_string__test1) 
{
    tokenlist = t_tokenize_string(SAMPLE);

    queue_node *node = q_first_node(tokenlist->tokens);
    
    char *expected[] = {
        "[",
        "CCICOMP",
        "]",
        " ",
        "Hardware Components",
        "\n"
    };

    int i = 0;
    while(node != NULL) {
        Token *currentToken = (Token*)node->data;
        char *str = currentToken->str;

        mu_assert_string_eq(expected[i], str);

        node = node->next;
        i++;
    }
}

MU_TEST(t_tokenize_string__test2) 
{
    tokenlist = t_tokenize_string(SAMPLE2);

    queue_node *node = q_first_node(tokenlist->tokens);
    
    char *expected[] = {
        "\n",
        "\n",
        "Explain the machine cycle",
        ".",
        "\n",
        "-",
        " ",
        "CPU fetches instructions from RAM",
        ".",
        " ",
        "Control unit decodes the instructions",
        ".",
        "\n",
        "ALU executes instructions",
        ".",
        " ",
        "Results are stored back to RAM",
        ".",
        "\n",
        "\n",
        "Diffferentiate random",
        "-",
        "access memory and hard drive",
        ".",
        "\n",
        "-",
        " ",
        "RAM is volatile memory that is cleared when shutdown while the hard drive ",
        "\n",
        "stores long",
        "-",
        "term non",
        "-",
        "volatile memory",
        ".",
        " ",
        "RAM is faster while the hard drive is slower",
        "."
    };

    int i = 0;
    while(node != NULL) {
        Token *currentToken = (Token*)node->data;
        char *str = currentToken->str;

        mu_assert_string_eq(expected[i], str);

        node = node->next;
        i++;
    }
}

MU_TEST_SUITE(t_tokenize_string__tests)
{
    MU_SUITE_CONFIGURE(t_tokenize_string__setup, t_tokenize_string__teardown);

    MU_RUN_TEST(t_tokenize_string__test1);
    MU_RUN_TEST(t_tokenize_string__test2);
}

int main()
{
    MU_RUN_SUITE(extract_alnum__tests);
    MU_RUN_SUITE(extract_nonalnum__tests);
    MU_RUN_SUITE(get_token_type__tests);
    MU_RUN_SUITE(t_tokenize_string__tests);
    MU_REPORT();

    return minunit_fail;
}
