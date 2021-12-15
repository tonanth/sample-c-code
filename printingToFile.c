#include <stdio.h>
#include <assert.h>

/* A quick snippet of code to write to files.
 * Be very careful with this because it will wipe out
 * existing files with the same name.
 * 
 * Instructions : when calling this program the first argument should be the file name
 * Arguments after the file name will be written to a file, separated by newlines
 * Example: ./a.out one two three will yield a file named one and contents are
 * 
 * The program being run is: ./a.out
 *  The file name is: one
 *  The arguments are:
 *   two
 *   three
 *
 */

int main(int n, char* argv[]) {
    assert(n > 1);
    FILE *fp;
    fp = fopen(argv[1], "w");
    fprintf(fp,"The program being run is: %s", argv[0]);
    fprintf(fp,"\nThe file name is: %s", argv[1]);
    fprintf(fp,"\nThe arguments are:\n");
    int i;
    for(int i = 2; i < n; i++) {
        fprintf(fp,"%s\n", argv[i]);
    }
    fclose(fp);
}