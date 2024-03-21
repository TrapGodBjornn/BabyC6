#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/* print msg, followed by the usage message, and exit the program */
//void print_usage(char *msg);

/* return an array that has the number of lines, words, and characters in filename */
/* should pass in a filename of "" to indicate to read from stdin */
//int *get_counts(char *filename);

/* print the indicated counts for file name */
/* show should be an array of three ints that indicates if the number of lines,
 * words, and characters should be printed */
/* count is an array of the three counts */
/* name is the name to print after the counts */
//void print_counts(int *show, int *count, char *name);

void print_usage(char *msg){
	fprintf(stderr, "%s\n", msg);
	fprintf(stderr, "Usage: wc [-l] [-w] [-c] [FILES...]\nwhere:\n      -l   prints the number of lines\n      -w    prints the number of words\n      -c    prints the number of characters\n     FILES if no files are given, then read\n            from standard input");
	exit(1);
}
int *get_counts(char *filename){
	int fd, n;
	char buffer[1];
	int *counts= calloc(3, sizeof(int));
	if (counts== NULL){
		perror("Cill");
		return NULL;
	}

	if (filename[0] == '\0'){
		fd= STDIN_FILENO;
	}else{

		fd= open(filename, O_RDONLY);
		if (fd == -1){
			perror("Dont exist");
			free(counts);
			return NULL;
		}
	}
	int in_whitespace = 0;
	while (( n= read(fd, buffer, 1)) > 0) {
		if ( n== -1){
			perror("DEde");
			free(counts);
			close(fd);
			return NULL;
		}
	

		counts[2]++;

		if (isspace(buffer[0])){
			if (!in_whitespace){
				in_whitespace= 1;
				counts[1]++;
			}
			if (buffer[0] == '\n'){
				counts[0]++;
			}
	}	else {
		in_whitespace=0;
		}
	}

	if (n==0){
		if (fd!= STDIN_FILENO){
			close(fd);
		}
		return counts;
	}
	if ( n==-1){
		perror("dede");
	}
	free(counts);
	if (fd!= STDIN_FILENO){
		close(fd);

}	
	return NULL;

}



void print_counts(int *show, int *count, char *name){
	printf("%8d ", show[0] ? count[0] : 0);
	printf("%8d ", show[1] ? count[1] : 0);
	printf("%8d ", show[2] ? count[2] : 0);
	printf("%s\n", name);
}


int main(int argc, char **argv){
	int *counts;
	int show[3] = {1, 1, 1};

	if (argc < 2){
		print_usage("Not file");
	}

	for (int i= 1; i< argc; i++){
		if(argv[i][0] == '-'){
			if(strcmp(argv[i], "-l")== 0){
				show[0] = 0;
			} else if (strcmp(argv[i], "-w")==0){
				show[1]= 0;
			} else if (strcmp(argv[i], "-c")==0){
				show[2] = 0;
			} else{
				print_usage("jerk");
			}
		}else{
			break;
		}
	}
	for (int i= 1; i< argc; i++){
		if (argv[i][0] != '-'){
			counts = get_counts(argv[i]);
			if (counts == NULL) {
				fprintf(stderr, "brrrr: %s\n", argv[i]);
				continue;
			}
		print_counts(show, counts, argv[i]);
		free(counts);
		}
	}  
    return 0;
}
