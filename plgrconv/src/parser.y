%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mapping.h"

int yylex(void);
int yyerror(char *s);
%}


%union {
    PARSED_CHUNK *pc;
}

%token <pc> LARGE_ALPHA
%token <pc> LARGE_EPSILON
%token <pc> LARGE_ETA
%token <pc> LARGE_IOTA
%token <pc> LARGE_OMICRON
%token <pc> LARGE_UPSILON
%token <pc> LARGE_OMEGA

%token <pc> LARGE_BETA
%token <pc> LARGE_GAMMA
%token <pc> LARGE_DELTA
%token <pc> LARGE_ZETA
%token <pc> LARGE_KAPPA
%token <pc> LARGE_LAMBDA
%token <pc> LARGE_MU
%token <pc> LARGE_NU
%token <pc> LARGE_XI
%token <pc> LARGE_PI
%token <pc> LARGE_RHO
%token <pc> LARGE_SIGMA
%token <pc> LARGE_TAU

%token <pc> SMALL_ALPHA
%token <pc> SMALL_EPSILON
%token <pc> SMALL_ETA
%token <pc> SMALL_IOTA
%token <pc> SMALL_OMICRON
%token <pc> SMALL_UPSILON
%token <pc> SMALL_OMEGA

%token <pc> SMALL_BETA
%token <pc> SMALL_GAMMA
%token <pc> SMALL_DELTA
%token <pc> SMALL_ZETA
%token <pc> SMALL_KAPPA
%token <pc> SMALL_LAMBDA
%token <pc> SMALL_MU
%token <pc> SMALL_NU
%token <pc> SMALL_XI
%token <pc> SMALL_PI
%token <pc> SMALL_RHO
%token <pc> SMALL_SIGMA
%token <pc> SMALL_TAU

%token <pc> COMMA
%token <pc> SEMICORON
%token <pc> PERIOD
%token <pc> QUESTION
%token <pc> APOSTROPH
%token <pc> LGUILLEMET
%token <pc> RGUILLEMET
%token <pc> OTHERS
%token <pc> NEWLINE

%type <pc> letters
%type <pc> letter
%type <pc> alphabet
%type <pc> non_final_sigma
%type <pc> large_nasable_gamma
%type <pc> small_nasable_gamma
%type <pc> single_alphabet
%type <pc> punctuation

%%

text:
    | lines
    ;

lines:
    lines line
    | line
    ;

line:
    letters NEWLINE
    {
        print_chunk($1);
        print_chunk($2);
        free_chunk($1);
        free_chunk($2);
    }
    | NEWLINE
    {
        print_chunk($1);
        free_chunk($1);
    }
    ;

letters:
    letter letters
    {
        $1->n = $2;
        $$ = $1;
    }
    | letter
    ;

letter:
    alphabet
    | punctuation
    | OTHERS
    ;

alphabet:
    non_final_sigma
    | large_nasable_gamma
    | small_nasable_gamma
    | single_alphabet
    ;

non_final_sigma:
    SMALL_SIGMA alphabet
    {
        size_t len1 = strlen($1->v);
        size_t len2 = strlen($2->v);
        char str[len1+len2+1];

        strcpy(str, "\u03C3");
        strcat(str, $2->v);

        $$ = create_chunk(str);
    }
    ;

large_nasable_gamma:
    LARGE_NU LARGE_GAMMA
    {
        size_t len1 = strlen($1->v);
        size_t len2 = strlen($2->v);
        char str[len1+len2+1];

        strcpy(str, "\u0393");
        strcat(str, $2->v);

        $$ = create_chunk(str);
    }
    | LARGE_NU LARGE_KAPPA
    {
        size_t len1 = strlen($1->v);
        size_t len2 = strlen($2->v);
        char str[len1+len2+1];

        strcpy(str, "\u0393");
        strcat(str, $2->v);

        $$ = create_chunk(str);
    }
    | LARGE_NU LARGE_XI
    {
        size_t len1 = strlen($1->v);
        size_t len2 = strlen($2->v);
        char str[len1+len2+1];

        strcpy(str, "\u0393");
        strcat(str, $2->v);

        $$ = create_chunk(str);
    }
    ;

small_nasable_gamma:
    SMALL_NU SMALL_GAMMA
    {
        size_t len1 = strlen($1->v);
        size_t len2 = strlen($2->v);
        char str[len1+len2+1];

        strcpy(str, "\u03B3");
        strcat(str, $2->v);

        $$ = create_chunk(str);
    }
    | SMALL_NU SMALL_KAPPA
    {
        size_t len1 = strlen($1->v);
        size_t len2 = strlen($2->v);
        char str[len1+len2+1];

        strcpy(str, "\u03B3");
        strcat(str, $2->v);

        $$ = create_chunk(str);
    }
    | SMALL_NU SMALL_XI
    {
        size_t len1 = strlen($1->v);
        size_t len2 = strlen($2->v);
        char str[len1+len2+1];

        strcpy(str, "\u03B3");
        strcat(str, $2->v);

        $$ = create_chunk(str);
    }
    ;

single_alphabet:
    LARGE_ALPHA
    | LARGE_EPSILON
    | LARGE_ETA
    | LARGE_IOTA
    | LARGE_OMICRON
    | LARGE_UPSILON
    | LARGE_OMEGA
    | LARGE_BETA
    | LARGE_GAMMA
    | LARGE_DELTA
    | LARGE_ZETA
    | LARGE_KAPPA
    | LARGE_LAMBDA
    | LARGE_MU
    | LARGE_NU
    | LARGE_XI
    | LARGE_PI
    | LARGE_RHO
    | LARGE_SIGMA
    | LARGE_TAU
    | SMALL_ALPHA
    | SMALL_EPSILON
    | SMALL_ETA
    | SMALL_IOTA
    | SMALL_OMICRON
    | SMALL_UPSILON
    | SMALL_OMEGA
    | SMALL_BETA
    | SMALL_GAMMA
    | SMALL_DELTA
    | SMALL_ZETA
    | SMALL_KAPPA
    | SMALL_LAMBDA
    | SMALL_MU
    | SMALL_NU
    | SMALL_XI
    | SMALL_PI
    | SMALL_RHO
    | SMALL_SIGMA
    | SMALL_TAU
    ;

punctuation:
    COMMA
    | SEMICORON
    | PERIOD
    | QUESTION
    | APOSTROPH
    | LGUILLEMET
    | RGUILLEMET
    ;

%%

extern FILE *yyin;

int main(void)
{
    do {
        yyparse();
    } while(!feof(yyin));
    return 0;
}

int yyerror(char *s)
{
    fprintf(stderr, "%s\n", s);
    return 0;
}

