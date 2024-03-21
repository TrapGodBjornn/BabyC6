#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/* print msg, followed by the usage message, and exit the program */
void print_usage(char *msg);

/* return an array that has the number of lines, words, and characters in filename */
/* should pass in a filename of "" to indicate to read from stdin */
int *get_counts(char *filename);

/* print the indicated counts for file name */
/* show should be an array of three ints that indicates if the number of lines,
 * words, and characters should be printed */
/* count is an array of the three counts */
/* name is the name to print after the counts */
void print_counts(int *show, int *count, char *name);

int main(int argc, char **argv)
{
    return 0;
}
