#include <stdio.h>

#include "mapping.h"

int main(void)
{
    PARSED_CHUNK *large_alpha = convert_to_large_alpha(">~A|");
    PARSED_CHUNK *large_epsilon = convert_to_large_epsilon(">'E");
    PARSED_CHUNK *large_eta = convert_to_large_eta(">~^E|");
    PARSED_CHUNK *large_iota = convert_to_large_iota(">~I");
    PARSED_CHUNK *large_omicron = convert_to_large_omicron(">'O");
    PARSED_CHUNK *large_rho = convert_to_large_rho("<R");
    PARSED_CHUNK *large_upsilon = convert_to_large_upsilon("<~Y");
    PARSED_CHUNK *large_omega = convert_to_large_omega(">~^O|");

    PARSED_CHUNK *small_alpha = convert_to_small_alpha(">~a|");
    PARSED_CHUNK *small_epsilon = convert_to_small_epsilon(">'e");
    PARSED_CHUNK *small_eta = convert_to_small_eta(">~^e|");
    PARSED_CHUNK *small_iota = convert_to_small_iota("\"'i");
    PARSED_CHUNK *small_omicron = convert_to_small_omicron(">'o");
    PARSED_CHUNK *small_rho = convert_to_small_rho("<r");
    PARSED_CHUNK *small_upsilon = convert_to_small_upsilon("\"'y");
    PARSED_CHUNK *small_omega = convert_to_small_omega(">~^o|");

    printf("%s\n", large_alpha->v);
    printf("%s\n", large_epsilon->v);
    printf("%s\n", large_eta->v);
    printf("%s\n", large_iota->v);
    printf("%s\n", large_omicron->v);
    printf("%s\n", large_rho->v);
    printf("%s\n", large_upsilon->v);
    printf("%s\n", large_omega->v);

    printf("%s\n", small_alpha->v);
    printf("%s\n", small_epsilon->v);
    printf("%s\n", small_eta->v);
    printf("%s\n", small_iota->v);
    printf("%s\n", small_omicron->v);
    printf("%s\n", small_rho->v);
    printf("%s\n", small_upsilon->v);
    printf("%s\n", small_omega->v);

    free_chunk(large_alpha);
    free_chunk(large_epsilon);
    free_chunk(large_eta);
    free_chunk(large_iota);
    free_chunk(large_omicron);
    free_chunk(large_rho);
    free_chunk(large_upsilon);
    free_chunk(large_omega);

    free_chunk(small_alpha);
    free_chunk(small_epsilon);
    free_chunk(small_eta);
    free_chunk(small_iota);
    free_chunk(small_omicron);
    free_chunk(small_rho);
    free_chunk(small_upsilon);
    free_chunk(small_omega);
}
