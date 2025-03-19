#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

int Fourbyte_value(char *filename);

int main(int argc, char *argv[]) {
   if (argc < 2) {
        fprintf(stderr, "Usage: %s <file1> [<file2>...]\n", argv[0]);
        return 1;
    }

    uint32_t sum = 0;

    for (int i = 1; i < argc; i++) { 
        if (i > 1) printf(" + ");  
        int value = Fourbyte_value(argv[i]);
        if (value == -1) return 1; 
        printf("%d(0x%x)", value, value);
        sum += value;
    }

    printf(" = %d(0x%x)\n", sum, sum);
    return 0;
}

int Fourbyte_value(char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("File not found");
        return -1;
    }

    uint32_t num = 0;

    fseek(file, 0, SEEK_END); 

    int file_size = ftell(file);
    if (file_size != 4) {
        perror("Not 4Byte!");
        fclose(file);
        return -1;
    }

    fseek(file, 0, SEEK_SET); 

    int bytes_read = fread(&num, sizeof(char), 4, file);
    fclose(file);

    if (bytes_read == 4) {
        printf("%d(0x%x)", ntohl(num), ntohl(num));
        return ntohl(num);
    } else {
        perror("Not 4Byte!!");
        return -1;
    }
}

