
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

enum {
    BINARY, HEX
} output_mode = BINARY;

extern int optind;

unsigned decimal_to_bin(unsigned n);
unsigned decimal_to_hex(unsigned n);


int main(int argc, char** argv) {
    int opt;
    
    if (argc < 3) {
        perror("Usage: %s [-b | h] [decimal number...]");
        exit(-1);
    }


    while ((opt = getopt(argc, argv, "bh")) != -1) {
        switch(opt) {
            case 'b': 
                output_mode = BINARY;
                break;
            case 'h':
                output_mode = HEX;
                break;
            default:
                fprintf(stderr, "Usage: %s [-bh] [decimal number...]\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    char* input = argv[optind];
    unsigned decimal = (unsigned)atoi(input);

    if (output_mode == BINARY) {
        unsigned binary = decimal_to_bin(decimal);
        printf("%d\n", binary);
    } else {
        unsigned hex = decimal_to_hex(decimal);
        printf("%d\n", hex);
    }

}


unsigned decimal_to_bin(unsigned n) {
    if ( n == 0 ) return 0;
    else {
        return (n % 2 + 10 * 
            decimal_to_bin(n / 2));
    }
}


unsigned decimal_to_hex(unsigned n) {
    if ( n == 0 ) return 0;
    else {
        return (n % 16 + 10 *
            decimal_to_hex(n / 16));
    }
}
