#include <stdio.h>
#include <string.h>

int main(void)
{
    char buffer[16];
    while(fgets(buffer, 10, stdin) != NULL) {
        size_t len = strlen(buffer);
        for (int i = 0; i < len; i++) {
            if (buffer[i] == 0x0A) {
                printf("%c", buffer[i]);
            } else {
                printf("\\x%02hhX", buffer[i]);
            }
        }
    }
}
