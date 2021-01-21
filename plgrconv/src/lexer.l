%{
#include <stdio.h>
#include <string.h>
#include "mapping.h"
#include "parser.h"
%}

%%

[<>]?['`~]?A\|? {
    yylval.pc = convert_to_large_alpha(yytext);
    return LARGE_ALPHA;
}
[<>]?['`]?E {
    yylval.pc = convert_to_large_epsilon(yytext);
    return LARGE_EPSILON;
}
[<>]?['`~]?\^E\|? {
    yylval.pc = convert_to_large_eta(yytext);
    return LARGE_ETA;
}
[<>"]?['`~]?I {
    yylval.pc = convert_to_large_iota(yytext);
    return LARGE_IOTA;
}
[<>]?['`]?O {
    yylval.pc = convert_to_large_omicron(yytext);
    return LARGE_OMICRON;
}
[<>"]?['`~]?[UY] {
    yylval.pc = convert_to_large_upsilon(yytext);
    return LARGE_UPSILON;
}
[<>]?['`~]?\^O\|? {
    yylval.pc = convert_to_large_omega(yytext);
    return LARGE_OMEGA;
}

B {
    yylval.pc = create_chunk("\u0392");
    return LARGE_BETA;
}
G {
    yylval.pc = create_chunk("\u0393");
    return LARGE_GAMMA;
}
D {
    yylval.pc = create_chunk("\u0394");
    return LARGE_DELTA;
}
Z {
    yylval.pc = create_chunk("\u0396");
    return LARGE_ZETA;
}
Kh? {
    yylval.pc = convert_to_large_kappa(yytext);
    return LARGE_KAPPA;
}
L {
    yylval.pc = create_chunk("\u039B");
    return LARGE_LAMBDA;
}
M {
    yylval.pc = create_chunk("\u039C");
    return LARGE_MU;
}
N {
    yylval.pc = create_chunk("\u039D");
    return LARGE_NU;
}
X {
    yylval.pc = create_chunk("\u039E");
    return LARGE_XI;
}
Ph? {
    yylval.pc = convert_to_large_pi(yytext);
    return LARGE_PI;
}
\<?R {
    yylval.pc = convert_to_large_rho(yytext);
    return LARGE_RHO;
}
S {
    yylval.pc = create_chunk("\u03A3");
    return LARGE_SIGMA;
}
Th? {
    yylval.pc = convert_to_large_tau(yytext);
    return LARGE_TAU;
}

[<>]?['`~]?a\|? {
    yylval.pc = convert_to_small_alpha(yytext);
    return SMALL_ALPHA;
}
[<>]?['`]?e {
    yylval.pc = convert_to_small_epsilon(yytext);
    return SMALL_EPSILON;
}
[<>]?['`~]?\^e\|? {
    yylval.pc = convert_to_small_eta(yytext);
    return SMALL_ETA;
}
[<>"]?['`~]?i {
    yylval.pc = convert_to_small_iota(yytext);
    return SMALL_IOTA;
}
[<>]?['`]?o {
    yylval.pc = convert_to_small_omicron(yytext);
    return SMALL_OMICRON;
}
[<>"]?['`~]?[uy] {
    yylval.pc = convert_to_small_upsilon(yytext);
    return SMALL_UPSILON;
}
[<>]?['`~]?\^o\|? {
    yylval.pc = convert_to_small_omega(yytext);
    return SMALL_OMEGA;
}

b {
    yylval.pc = create_chunk("\u03B2");
    return SMALL_BETA;
}
g {
    yylval.pc = create_chunk("\u03B3");
    return SMALL_GAMMA;
}
d {
    yylval.pc = create_chunk("\u03B4");
    return SMALL_DELTA;
}
z {
    yylval.pc = create_chunk("\u03B6");
    return SMALL_ZETA;
}
kh? {
    yylval.pc = convert_to_small_kappa(yytext);
    return SMALL_KAPPA;
}
l {
    yylval.pc = create_chunk("\u03BB");
    return SMALL_LAMBDA;
}
m {
    yylval.pc = create_chunk("\u03BC");
    return SMALL_MU;
}
n {
    yylval.pc = create_chunk("\u03BD");
    return SMALL_NU;
}
x {
    yylval.pc = create_chunk("\u03BE");
    return SMALL_XI;
}
ph? {
    yylval.pc = convert_to_small_pi(yytext);
    return SMALL_PI;
}
[<>]?r {
    yylval.pc = convert_to_small_rho(yytext);
    return SMALL_RHO;
}
[cs] {
    yylval.pc = convert_to_small_sigma(yytext);
    return SMALL_SIGMA;
}
th? {
    yylval.pc = convert_to_small_tau(yytext);
    return SMALL_TAU;
}

, {
    yylval.pc = create_chunk(",");
    return COMMA;
}
; {
    yylval.pc = create_chunk("\u0387");
    return SEMICORON;
}
\. {
    yylval.pc = create_chunk(".");
    return PERIOD;
}
\? {
    yylval.pc = create_chunk("\u037E");
    return QUESTION;
}
'' {
    yylval.pc = create_chunk("'");
    return APOSTROPH;
}
\<< {
    yylval.pc = create_chunk("\u00AB");
    return LGUILLEMET;
}
>> {
    yylval.pc = create_chunk("\u00BB");
    return RGUILLEMET;
}
[ \t]+ {
    yylval.pc = create_chunk(yytext);
    return WHITESPACE;
}
\r?\n {
    yylval.pc = create_chunk(yytext);
    return NEWLINE;
}
\\. {
    char str[] = { yytext[1], '\0' };
    yylval.pc = create_chunk(str);
    return ESCAPE;
}

. ;

%%

