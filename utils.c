#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NOSIZE ((size_t) -1)
#define CHUNCK 1024

char * popola_random(int col, int row) {
	srand(time(0));
    char * pointer;
	if ((pointer = (char *) calloc(col*row, sizeof(char))) == NULL) {
        printf("Popolazione random fallita");
        exit(1);
    }
	for (int i=0; i<col*row; i++) {
		pointer[i] = rand() % 2;
		printf("%d", i[pointer]);
		if (i % col == col - 1) {printf("\n");}
	}
	printf("\n");
	return pointer;
}

char * popola_file(char const * const file, int * columns, int * rows) {
    char * line;
    size_t len = 0;
    size_t read;
    FILE * fp = fopen(file, "r");
    int col = 0;
    int row = 0;
    int size_buffer = CHUNCK;
    char * buffer;
    if ((buffer = (char *) malloc(size_buffer)) == NULL) {
        printf("Errore 01: memoria insufficiente");
        exit(1);
    }
    if (fp) {
        while ((read = getline(&line, &len, fp)) != NOSIZE) {
            if(read == 1) {continue;}
            col = read - 1;

            while (((row+1)*col) > size_buffer) {
                size_buffer *= 2;
                if ((buffer = (char *) realloc(buffer, size_buffer)) == NULL) {
                    printf("Errore di memoria");
                    exit(2);
                }
            }

            for (int i = 0; i < col; i++) {
                buffer[col*row + i] = ((char) line[i]);
            }

            row++;
        }
        free(line);
        fclose(fp);        
    } else
    {
        printf("File non trovato");
        exit(1);
    }
    /*
    if ((*tablepointer = realloc(buffer, col*row)) == NULL) {
        printf("nope");
        exit(1);
    }*/
    //free(buffer);
    *columns = col;
    *rows = row;
    
    if (buffer = realloc(buffer, row*col) == NULL) {
		printf("Errore di memoria");
		exit(1);
	}
    return buffer;
}
/*
int main(int argc, char * argv[]) {
    char * line;
    size_t len = 0;
    size_t read;
    FILE * fp = fopen(argv[1], "r");
    int col = 0;
    int row = 0;
    int size_buffer = 1;
    char * pointer = malloc(size_pointer);
    if (fp) {
        while ((read = getline(&line, &len, fp)) != NOSIZE) {
            col = read - 1;

            while (((row+1)*col) > size_pointer) {
                size_pointer *= 2;
                pointer = realloc(pointer, size_pointer);
            }

            for (int i = 0; i < col; i++) {
                pointer[col*row + i] = ((char) line[i] == '*');
            }

            row++;
        }
        pointer = realloc(pointer, col*row);

        free(line);
        free(pointer);
        line = NULL;
        fclose(fp);        
    }
    return 0;
}
*/