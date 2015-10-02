#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// gcc -Wall -O2 sboxes.c tiger.c destiny.c -o destiny


#define TIGER_HASH_LENGTH (16)

void tiger(uint64_t *str, uint64_t length, uint64_t res[3]);

const uint8_t target_hash[TIGER_HASH_LENGTH] = {
    0x1F, 0xDB, 0x94, 0x72, 0xD0, 0xD9, 0x5B, 0x42,
    0xE9, 0x09, 0x0C, 0x4B, 0xA3, 0x76, 0xBA, 0x17
};


int main(int argc, char **argv) {
    uint8_t best_hash[TIGER_HASH_LENGTH];
    int  best_diff = 999;

    uint8_t cur_hash[TIGER_HASH_LENGTH];
    int  cur_diff;

    char  *cur_line = NULL;
    size_t cur_line_malloc_size = 0;
    uint32_t cur_line_len = 0;

    size_t line_count = 0;
    int i;

    // Unbuffer STDOUT so progress messages appear
    setvbuf(stdout, NULL, _IONBF, 0);


    while ( getline(&cur_line, &cur_line_malloc_size, stdin) != -1 ) { 
        // Remove the trailing newline
        cur_line_len = strlen(cur_line);
        cur_line[ --cur_line_len ] = 0;

        // Actual hashing
        tiger((uint64_t *)cur_line, (uint64_t)cur_line_len, (uint64_t *)cur_hash);

        // Calculating string difference
        // This is done nibble-by-nibble instead of byte-by-byte to simulate
        //   comparing the data as a hex string, not binary data
        // The minimum difference is 0, the maximum difference is 128 (TIGER_HASH_LENGTH * 2)
        cur_diff = 0;
        for (i = 0; i < TIGER_HASH_LENGTH; i++) {
            if ( (cur_hash[i] & 0xF0) != (target_hash[i] & 0xF0) ) { cur_diff++; }
            if ( (cur_hash[i] & 0x0F) != (target_hash[i] & 0x0F) ) { cur_diff++; }
        }

        if ( ++line_count % 1000000 == 0 ) {
            // ANSI escape for erasing the current line
            printf("\033[0K");
            printf("Current Line: %s\r", cur_line);
        }


        if ( cur_diff < best_diff ) {
            best_diff = cur_diff;
            memcpy(best_hash, cur_hash, TIGER_HASH_LENGTH);

            printf("Diff: %d; Str: <%s>; Hash: ", cur_diff, cur_line);
            for ( i = 0; i < TIGER_HASH_LENGTH; i++ ) {
                printf("%02x", cur_hash[i] & 0xFF);
            }
            printf("\n");
        }
    }


    printf("Input ended after %zu lines\n", line_count);

    return 0;
}
