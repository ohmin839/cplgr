#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "mapping.h"

static bool includes_char(char* token, char target);
static int add_score_iota_subscriptum(char* token, int score);
static int add_score_accent(char* token, int score);
static int add_score_breath(char* token, int score);
static int add_score_dialesis(char* token, int score);
static int calc_score(char* token);

static bool includes_char(char* token, char target)
{
    size_t l = strlen(token);
    for (int i = 0; i < l; i++) {
        if (token[i] == target) {
            return true;
        }
    }
    return false;
}

static int add_score_iota_subscriptum(char* token, int score)
{
    if (includes_char(token, '|')) {
        return score + 1;
    } else {
        return score;
    }
}

static int add_score_accent(char* token, int score)
{
    if (includes_char(token, '\'')) { // acute
        return score + 4;
    } else if (includes_char(token, '`')) { // grave
        return score + 8;
    } else if (includes_char(token, '~')) { // circumflex
        return score + 12;
    } else {
        return score;
    }
}

static int add_score_breath(char* token, int score)
{
    if (includes_char(token, '<')) { // breathful
        return score + 16;
    } else if (includes_char(token, '>')) { // breathless
        return score + 32;
    } else {
        return score;
    }

}

static int add_score_dialesis(char* token, int score)
{
    if (includes_char(token, '"')) {
        return score + 64;
    } else {
        return score;
    }
}

static int calc_score(char* token)
{
    return add_score_iota_subscriptum(token,
            add_score_accent(token,
                add_score_breath(token,
                    add_score_dialesis(token, 0))));
}

PARSED_CHUNK* create_chunk(char* str)
{
    PARSED_CHUNK *pc = malloc(sizeof(PARSED_CHUNK));

    size_t len = strlen(str);
    pc->v = malloc(sizeof(char) * (len+1));
    strcpy(pc->v, str);

    pc->n = NULL;

    return pc;
}

void print_chunk(PARSED_CHUNK* pc)
{
    while(pc != NULL)
    {
        printf("%s", pc->v);
        pc = pc->n;
    }
}

void free_chunk(PARSED_CHUNK* pc)
{
    PARSED_CHUNK *npc;
    while(pc != NULL)
    {
        npc = pc->n;
        free(pc->v);
        free(pc);
        pc = npc;
    }
}

PARSED_CHUNK* convert_to_large_alpha(char* token)
{
    int score = calc_score(token);
    switch (score)
    {
        case  1: return create_chunk("\u1FBC"); // A|
        case  4: return create_chunk("\u1FBB"); // 'A
//      case  5: return create_chunk("\uxxxx"); // 'A|
        case  8: return create_chunk("\u1FBA"); // `A
//      case  9: return create_chunk("\uxxxx"); // `A|
//      case 12: return create_chunk("\uxxxx"); // ~A
//      case 13: return create_chunk("\uxxxx"); // ~A|
        case 16: return create_chunk("\u1F09"); // <A
        case 17: return create_chunk("\u1F89"); // <A|
        case 20: return create_chunk("\u1F0D"); // <'A
        case 21: return create_chunk("\u1F8D"); // <'A|
        case 24: return create_chunk("\u1F0B"); // <`A
        case 25: return create_chunk("\u1F8B"); // <`A|
        case 28: return create_chunk("\u1F0F"); // <~A
        case 29: return create_chunk("\u1F8F"); // <`A|
        case 32: return create_chunk("\u1F08"); // >A
        case 33: return create_chunk("\u1F88"); // >A|
        case 36: return create_chunk("\u1F0C"); // >'A
        case 37: return create_chunk("\u1F8C"); // >'A|
        case 40: return create_chunk("\u1F0A"); // >`A
        case 41: return create_chunk("\u1F8A"); // >`A|
        case 44: return create_chunk("\u1F0E"); // >~A
        case 45: return create_chunk("\u1F8E"); // >~A|
        default: return create_chunk("\u0391"); // A
    }
}

PARSED_CHUNK* convert_to_large_epsilon(char* token)
{
    int score = calc_score(token);
    switch (score)
    {
        case  4: return create_chunk("\u1FC9"); // 'E
        case  8: return create_chunk("\u1FC8"); // `E
        case 16: return create_chunk("\u1F19"); // <E
        case 20: return create_chunk("\u1F1D"); // <'E
        case 24: return create_chunk("\u1F1B"); // <`E
        case 32: return create_chunk("\u1F18"); // >E
        case 36: return create_chunk("\u1F1C"); // >'E
        case 40: return create_chunk("\u1F1A"); // >`E
        default: return create_chunk("\u0395"); // E
    }
}

PARSED_CHUNK* convert_to_large_eta(char* token)
{
    int score = calc_score(token);
    switch (score)
    {
        case  1: return create_chunk("\u1FCC"); // ^E|
        case  4: return create_chunk("\u1FCB"); // '^E
//      case  5: return create_chunk("\uxxxx"); // '^E|
        case  8: return create_chunk("\u1FCA"); // `^E
//      case  9: return create_chunk("\uxxxx"); // `^E|
//      case 12: return create_chunk("\uxxxx"); // ~^E
//      case 13: return create_chunk("\uxxxx"); // ~^E|
        case 16: return create_chunk("\u1F29"); // <^E
        case 17: return create_chunk("\u1F99"); // <^E|
        case 20: return create_chunk("\u1F2D"); // <'^E
        case 21: return create_chunk("\u1F9D"); // <'^E|
        case 24: return create_chunk("\u1F2B"); // <`^E
        case 25: return create_chunk("\u1F9B"); // <`^E|
        case 28: return create_chunk("\u1F2F"); // <~^E
        case 29: return create_chunk("\u1F9F"); // <`^E|
        case 32: return create_chunk("\u1F28"); // >^E
        case 33: return create_chunk("\u1F98"); // >^E|
        case 36: return create_chunk("\u1F2C"); // >'^E
        case 37: return create_chunk("\u1F9C"); // >'^E|
        case 40: return create_chunk("\u1F2A"); // >`^E
        case 41: return create_chunk("\u1F9A"); // >`^E|
        case 44: return create_chunk("\u1F2E"); // >~^E
        case 45: return create_chunk("\u1F9E"); // >~^E|
        default: return create_chunk("\u0397"); // ^E
    }
}

PARSED_CHUNK* convert_to_large_iota(char* token)
{
    int score = calc_score(token);
    switch (score)
    {
        case  4: return create_chunk("\u1FDB"); // 'I
        case  8: return create_chunk("\u1FDA"); // `I
//      case 12: return create_chunk("\uxxxx"); // ~I
        case 16: return create_chunk("\u1F39"); // <I
        case 20: return create_chunk("\u1F3D"); // <'I
        case 24: return create_chunk("\u1F3B"); // <`I
        case 28: return create_chunk("\u1F3F"); // <~I
        case 32: return create_chunk("\u1F38"); // >I
        case 36: return create_chunk("\u1F3C"); // >'I
        case 40: return create_chunk("\u1F3A"); // >`I
        case 44: return create_chunk("\u1F3E"); // >~I
        case 64: return create_chunk("\u03AA"); // "I
        default: return create_chunk("\u0399"); // I
    }
}

PARSED_CHUNK* convert_to_large_omicron(char* token)
{
    int score = calc_score(token);
    switch (score)
    {
        case  4: return create_chunk("\u1FF9"); // 'O
        case  8: return create_chunk("\u1FF8"); // `O
        case 16: return create_chunk("\u1F49"); // <O
        case 20: return create_chunk("\u1F4D"); // <'O
        case 24: return create_chunk("\u1F4B"); // <`O
        case 32: return create_chunk("\u1F48"); // >O
        case 36: return create_chunk("\u1F4C"); // >'O
        case 40: return create_chunk("\u1F4A"); // >`O
        default: return create_chunk("\u039F"); // O
    }
}

PARSED_CHUNK* convert_to_large_upsilon(char* token)
{
    int score = calc_score(token);
    switch (score)
    {
        case  4: return create_chunk("\u1FEB"); // 'Y
        case  8: return create_chunk("\u1FEA"); // `Y
//      case 12: return create_chunk("\uxxxx"); // ~Y
        case 16: return create_chunk("\u1F59"); // <Y
        case 20: return create_chunk("\u1F5D"); // <'Y
        case 24: return create_chunk("\u1F5B"); // <`Y
        case 28: return create_chunk("\u1F5F"); // <~Y
        case 64: return create_chunk("\u03AB"); // "Y
        default: return create_chunk("\u03A5"); // Y
    }
}

PARSED_CHUNK* convert_to_large_omega(char* token)
{
    int score = calc_score(token);
    switch (score)
    {
        case  1: return create_chunk("\u1FFC"); // ^O|
        case  4: return create_chunk("\u1FFB"); // '^O
//      case  5: return create_chunk("\uxxxx"); // '^O|
        case  8: return create_chunk("\u1FFA"); // `^O
//      case  9: return create_chunk("\uxxxx"); // `^O|
//      case 12: return create_chunk("\uxxxx"); // ~^O
//      case 13: return create_chunk("\uxxxx"); // ~^O|
        case 16: return create_chunk("\u1F69"); // <^O
        case 17: return create_chunk("\u1FA9"); // <^O|
        case 20: return create_chunk("\u1F6D"); // <'^O
        case 21: return create_chunk("\u1FAD"); // <'^O|
        case 24: return create_chunk("\u1F6B"); // <`^O
        case 25: return create_chunk("\u1FAB"); // <`^O|
        case 28: return create_chunk("\u1F6F"); // <~^O
        case 29: return create_chunk("\u1FAF"); // <`^O|
        case 32: return create_chunk("\u1F68"); // >^O
        case 33: return create_chunk("\u1FA8"); // >^O|
        case 36: return create_chunk("\u1F6C"); // >'^O
        case 37: return create_chunk("\u1FAC"); // >'^O|
        case 40: return create_chunk("\u1F6A"); // >`^O
        case 41: return create_chunk("\u1FAA"); // >`^O|
        case 44: return create_chunk("\u1F6E"); // >~^O
        case 45: return create_chunk("\u1FAE"); // >~^O|
        default: return create_chunk("\u03A9"); // ^O
    }
}

PARSED_CHUNK* convert_to_small_alpha(char* token)
{
    int score = calc_score(token);
    switch (score)
    {
        case  1: return create_chunk("\u1FB3"); // a|
        case  4: return create_chunk("\u1F71"); // 'a
        case  5: return create_chunk("\u1FB4"); // 'a|
        case  8: return create_chunk("\u1F70"); // `a
        case  9: return create_chunk("\u1FB2"); // `a|
        case 12: return create_chunk("\u1FB6"); // ~a
        case 13: return create_chunk("\u1FB7"); // ~a|
        case 16: return create_chunk("\u1F01"); // <a
        case 17: return create_chunk("\u1F81"); // <a|
        case 20: return create_chunk("\u1F05"); // <'a
        case 21: return create_chunk("\u1F85"); // <'a|
        case 24: return create_chunk("\u1F03"); // <`a
        case 25: return create_chunk("\u1F83"); // <`a|
        case 28: return create_chunk("\u1F07"); // <~a
        case 29: return create_chunk("\u1F87"); // <`a|
        case 32: return create_chunk("\u1F00"); // >a
        case 33: return create_chunk("\u1F80"); // >a|
        case 36: return create_chunk("\u1F04"); // >'a
        case 37: return create_chunk("\u1F84"); // >'a|
        case 40: return create_chunk("\u1F02"); // >`a
        case 41: return create_chunk("\u1F82"); // >`a|
        case 44: return create_chunk("\u1F06"); // >~a
        case 45: return create_chunk("\u1F86"); // >~a|
        default: return create_chunk("\u03B1"); // a
    }
}

PARSED_CHUNK* convert_to_small_epsilon(char* token)
{
    int score = calc_score(token);
    switch (score)
    {
        case  4: return create_chunk("\u1F73"); // 'e
        case  8: return create_chunk("\u1F72"); // `e
        case 16: return create_chunk("\u1F11"); // <e
        case 20: return create_chunk("\u1F15"); // <'e
        case 24: return create_chunk("\u1F13"); // <`e
        case 32: return create_chunk("\u1F10"); // >e
        case 36: return create_chunk("\u1F14"); // >'e
        case 40: return create_chunk("\u1F12"); // >`e
        default: return create_chunk("\u03B5"); // e
    }
}

PARSED_CHUNK* convert_to_small_eta(char* token)
{
    int score = calc_score(token);
    switch (score)
    {
        case  1: return create_chunk("\u1FC3"); // ^e|
        case  4: return create_chunk("\u1F75"); // '^e
        case  5: return create_chunk("\u1FC4"); // '^e|
        case  8: return create_chunk("\u1F74"); // `^e
        case  9: return create_chunk("\u1FC2"); // `^e|
        case 12: return create_chunk("\u1FC6"); // ~^e
        case 13: return create_chunk("\u1FC7"); // ~^e|
        case 16: return create_chunk("\u1F21"); // <^e
        case 17: return create_chunk("\u1F91"); // <^e|
        case 20: return create_chunk("\u1F25"); // <'^e
        case 21: return create_chunk("\u1F95"); // <'^e|
        case 24: return create_chunk("\u1F23"); // <`^e
        case 25: return create_chunk("\u1F93"); // <`^e|
        case 28: return create_chunk("\u1F27"); // <~^e
        case 29: return create_chunk("\u1F97"); // <`^e|
        case 32: return create_chunk("\u1F20"); // >^e
        case 33: return create_chunk("\u1F90"); // >^e|
        case 36: return create_chunk("\u1F24"); // >'^e
        case 37: return create_chunk("\u1F94"); // >'^e|
        case 40: return create_chunk("\u1F22"); // >`^e
        case 41: return create_chunk("\u1F92"); // >`^e|
        case 44: return create_chunk("\u1F26"); // >~^e
        case 45: return create_chunk("\u1F96"); // >~^e|
        default: return create_chunk("\u03B7"); // ^e
    }
}

PARSED_CHUNK* convert_to_small_iota(char* token)
{
    int score = calc_score(token);
    switch (score)
    {
        case  4: return create_chunk("\u1F77"); // 'i
        case  8: return create_chunk("\u1F76"); // `i
        case 12: return create_chunk("\u1FD6"); // ~i
        case 16: return create_chunk("\u1F31"); // <i
        case 20: return create_chunk("\u1F35"); // <'i
        case 24: return create_chunk("\u1F33"); // <`i
        case 28: return create_chunk("\u1F37"); // <~i
        case 32: return create_chunk("\u1F30"); // >i
        case 36: return create_chunk("\u1F34"); // >'i
        case 40: return create_chunk("\u1F32"); // >`i
        case 44: return create_chunk("\u1F36"); // >~i
        case 64: return create_chunk("\u03CA"); // "i
        case 68: return create_chunk("\u1FD3"); // "'i
        case 72: return create_chunk("\u1FD2"); // "`i
        case 76: return create_chunk("\u1FD7"); // "~i
        default: return create_chunk("\u03B9"); // i
    }
}

PARSED_CHUNK* convert_to_small_omicron(char* token)
{
    int score = calc_score(token);
    switch (score)
    {
        case  4: return create_chunk("\u1F79"); // 'o
        case  8: return create_chunk("\u1F78"); // `o
        case 16: return create_chunk("\u1F41"); // <o
        case 20: return create_chunk("\u1F45"); // <'o
        case 24: return create_chunk("\u1F43"); // <`o
        case 32: return create_chunk("\u1F40"); // >o
        case 36: return create_chunk("\u1F44"); // >'o
        case 40: return create_chunk("\u1F42"); // >`o
        default: return create_chunk("\u03BF"); // o
    }
}

PARSED_CHUNK* convert_to_small_upsilon(char* token)
{
    int score = calc_score(token);
    switch (score)
    {
        case  4: return create_chunk("\u1F7B"); // 'y
        case  8: return create_chunk("\u1F7A"); // `y
        case 12: return create_chunk("\u1FE6"); // ~y
        case 16: return create_chunk("\u1F51"); // <y
        case 20: return create_chunk("\u1F55"); // <'y
        case 24: return create_chunk("\u1F53"); // <`y
        case 28: return create_chunk("\u1F57"); // <~y
        case 32: return create_chunk("\u1F50"); // >y
        case 36: return create_chunk("\u1F54"); // >'y
        case 40: return create_chunk("\u1F52"); // >`y
        case 44: return create_chunk("\u1F56"); // >~y
        case 64: return create_chunk("\u03CB"); // "y
        case 68: return create_chunk("\u1FE3"); // "'y
        case 72: return create_chunk("\u1FE2"); // "`y
        case 76: return create_chunk("\u1FE7"); // "~y
        default: return create_chunk("\u03C5"); // y
    }
}

PARSED_CHUNK* convert_to_small_omega(char* token)
{
    int score = calc_score(token);
    switch (score)
    {
        case  1: return create_chunk("\u1FF3"); // ^o|
        case  4: return create_chunk("\u1F7D"); // '^o
        case  5: return create_chunk("\u1FF4"); // '^o|
        case  8: return create_chunk("\u1F7C"); // `^o
        case  9: return create_chunk("\u1FF2"); // `^o|
        case 12: return create_chunk("\u1FF6"); // ~^o
        case 13: return create_chunk("\u1FF7"); // ~^o|
        case 16: return create_chunk("\u1F61"); // <^o
        case 17: return create_chunk("\u1FA1"); // <^o|
        case 20: return create_chunk("\u1F65"); // <'^o
        case 21: return create_chunk("\u1FA5"); // <'^o|
        case 24: return create_chunk("\u1F63"); // <`^o
        case 25: return create_chunk("\u1FA3"); // <`^o|
        case 28: return create_chunk("\u1F67"); // <~^o
        case 29: return create_chunk("\u1FA7"); // <`^o|
        case 32: return create_chunk("\u1F60"); // >^o
        case 33: return create_chunk("\u1FA0"); // >^o|
        case 36: return create_chunk("\u1F64"); // >'^o
        case 37: return create_chunk("\u1FA4"); // >'^o|
        case 40: return create_chunk("\u1F62"); // >`^o
        case 41: return create_chunk("\u1FA2"); // >`^o|
        case 44: return create_chunk("\u1F66"); // >~^o
        case 45: return create_chunk("\u1FA6"); // >~^o|
        default: return create_chunk("\u03C9"); // ^o
    }
}


PARSED_CHUNK* convert_to_large_kappa(char* token)
{
    if (includes_char(token, 'h')) {
        return create_chunk("\u03A7"); // large khi
    } else {
        return create_chunk("\u039A"); // large kappa
    }
}

PARSED_CHUNK* convert_to_large_pi(char* token)
{
    if (includes_char(token, 'h')) {
        return create_chunk("\u03A6"); // large phi
    } else if (includes_char(token, 's')) {
        return create_chunk("\u03A8"); // large psi
    } else {
        return create_chunk("\u03A0"); // large pi
    }
}

PARSED_CHUNK* convert_to_large_rho(char* token)
{
    int score = calc_score(token);
    switch (score)
    {
        case 16: return create_chunk("\u1FEC"); // <R 
        default: return create_chunk("\u03A1"); // R
    }
}

PARSED_CHUNK* convert_to_large_tau(char* token)
{
    if (includes_char(token, 'h')) {
        return create_chunk("\u0398"); // large theta
    } else {
        return create_chunk("\u03A4"); // large tau
    }
}


PARSED_CHUNK* convert_to_small_kappa(char* token)
{
    if (includes_char(token, 'h')) {
        return create_chunk("\u03C7"); // small khi
    } else {
        return create_chunk("\u03BA"); // small kappa
    }
}

PARSED_CHUNK* convert_to_small_pi(char* token)
{
    if (includes_char(token, 'h')) {
        return create_chunk("\u03C6"); // small phi
    } else if (includes_char(token, 's')) {
        return create_chunk("\u03C8"); // small psi
    } else {
        return create_chunk("\u03C0"); // small pi
    }
}

PARSED_CHUNK* convert_to_small_rho(char* token)
{
    int score = calc_score(token);
    switch (score)
    {
        case 16: return create_chunk("\u1FE5"); // <r
        case 32: return create_chunk("\u1FE4"); // >r
        default: return create_chunk("\u03C1"); // r
    }
}

PARSED_CHUNK* convert_to_small_sigma(char* token)
{
    if (includes_char(token, 's')) {
        return create_chunk("\u03C2"); // final sigma
    } else { // 'c'
        return create_chunk("\u03C3"); // non-final sigma
    }
}

PARSED_CHUNK* convert_to_small_tau(char* token)
{
    if (includes_char(token, 'h')) {
        return create_chunk("\u03B8"); // small theta
    } else {
        return create_chunk("\u03C4"); // small tau
    }
}

