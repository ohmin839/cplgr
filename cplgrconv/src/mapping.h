#if !defined(PLGR_MAPPING_H)
#define PLGR_MAPPING_H

typedef struct parsed_chunk {
    char* v;
    struct parsed_chunk* n;
} PARSED_CHUNK;

PARSED_CHUNK* create_chunk(char* str);
void print_chunk(PARSED_CHUNK* pc);
void free_chunk(PARSED_CHUNK* pc);

// vowels

PARSED_CHUNK* convert_to_large_alpha(char* token);
PARSED_CHUNK* convert_to_large_epsilon(char* token);
PARSED_CHUNK* convert_to_large_eta(char* token);
PARSED_CHUNK* convert_to_large_iota(char* token);
PARSED_CHUNK* convert_to_large_omicron(char* token);
PARSED_CHUNK* convert_to_large_upsilon(char* token);
PARSED_CHUNK* convert_to_large_omega(char* token);

PARSED_CHUNK* convert_to_small_alpha(char* token);
PARSED_CHUNK* convert_to_small_epsilon(char* token);
PARSED_CHUNK* convert_to_small_eta(char* token);
PARSED_CHUNK* convert_to_small_iota(char* token);
PARSED_CHUNK* convert_to_small_omicron(char* token);
PARSED_CHUNK* convert_to_small_upsilon(char* token);
PARSED_CHUNK* convert_to_small_omega(char* token);

// consonants

PARSED_CHUNK* convert_to_large_kappa(char* token);
PARSED_CHUNK* convert_to_large_pi(char* token);
PARSED_CHUNK* convert_to_large_rho(char* token);
PARSED_CHUNK* convert_to_large_tau(char* token);

PARSED_CHUNK* convert_to_small_kappa(char* token);
PARSED_CHUNK* convert_to_small_pi(char* token);
PARSED_CHUNK* convert_to_small_rho(char* token);
PARSED_CHUNK* convert_to_small_sigma(char* token);
PARSED_CHUNK* convert_to_small_tau(char* token);

#endif
