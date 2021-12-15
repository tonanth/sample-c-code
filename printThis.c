#include <stdio.h>

/*
 * Sample program to print out the name of the program and the command line arugments provided.
 * This is for Linux based operating systems. I'm unsure if it works for others
 * For example, execute cc printThis.c -o printThis in the current directory
 * Then do ./printThis one two three 
 * It should print out exactly what you just typed.
 */
int main(int n, char* args[]) {
    int i;
    for(i = 0; i < n; i++){
        printf("%s ", args[i]);
    }
    printf("\n");
    return 0;
}