#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int inputline (char **line, int *size){
	char *buf, *last; int rets;
	*size = 81;
	buf = (char *)calloc(*size, sizeof(char));
	scanf("%80[^\n]%n", buf, &rets);
	if (feof(stdin)){free(buf); return 1;}
	while (rets>79) {
		last = &(buf[*size-1]);
		*size += 80;
		buf = (char *)realloc(buf, *size * sizeof(char));
		scanf("%80[^\n]%n", last, &rets);
	}
	fflush(stdin);
	*line = buf;
	return 0;
}

void processline (char **line, int size){
	char *source, *dest, *words[40], *tok;
	int m, n, k, l, i, j, r, ll, destsize=3;
	
	source = *line;
	dest = (char*) calloc(destsize, sizeof(char));
	tok = strtok (source, " \t");
	n = 1;
	m = strlen(tok);
	words[0]=tok;
	while (tok = strtok (NULL, " \t")) {
		ll=strlen(tok);
		m+=ll;
		if (m>=80-n) {
			m-=ll;
			destsize +=83;
			dest = (char*) realloc (dest, destsize * sizeof(char));
			k = 80 - m;
			l = k / (n-1);
			r = k % (n-1);
			for (i=0; i<n; i++) {
				strcat(dest, words[i]);
				if (i<n-1) 
					for (j=0; j< (i>=r?l:l+1); j++)
						strcat(dest," ");
			}
			n=1;
			m=strlen(tok);
			words[0]=tok;
		} else {
			words[n++]=tok;
		}
	}
	if (m+n<80) {
			destsize +=82;
			dest = (char*) realloc (dest, destsize * sizeof(char));
			k = 80 - m;
			if (n>1) {
			l = k / (n-1);
			r = k % (n-1);
			for (i=0; i<n; i++) {
				strcat(dest, words[i]);
				if (i<n-1) for (j=0; j< (i>=r?l:l+1); j++)
					strcat(dest," ");
			}
			} else {strcat(dest, words[0]); strcat(dest, "\n");}
	}
	free(source);
	*line = dest;
	return;
}

void outputline(char *line){
	printf("\n%s\n", line);
	free(line);
	return;
}

int main(){
	char * buf;
	int size;
	for (;;) {
		if (inputline(&buf, &size)) break;
		processline(&buf, size);
		outputline(buf);
	}
	return 0;
}