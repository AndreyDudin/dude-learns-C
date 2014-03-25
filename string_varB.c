#include <stdio.h>

#include <stdlib.h>




int input_line(char **line, int *size)
{
	char *buf, *last;
	int rets;

	*size = 81;
	buf = (char*)calloc(*size, sizeof(char));
	scanf("%80[^\n]%n", buf, &rets);
	if (feof(stdin))
	{
		free(buf);
		return 1;
	}
	while (rets > 79)
	{
		last = &(buf[*size - 1]);
		*size += 80;
		buf = (char*)realloc(buf, *size * sizeof(char));
		scanf("%80[^\n]%n", last, &rets);
	}
	fflush(stdin);
	*line = buf;
	return 0;
}

void process_line(char *line, int size)
{ char *words[40], *dest, *source;
	int len=0,spaces,pr=0;
	int i,j=0;
	while(*line++){
		if(*line='\t')
			++pr;
		++len;
	}
	line-=len;
	spaces=80-len+pr;
	*line=0;
	for(i=0;i<len,i++;){
		if(*line=='\t')
			while(*(line+=i)=='\t'){
				line-=i;
				i+=1;
			}
			words[j]=line;
			while(*line++!='\t'){
				*words[j]++=*line;
				i+=1;
			}




	
		
	}

	
}

void print_line(char *line)
{
	printf("%s\n", line);
	free(line);
}

int main()
{
	char *buf;
	int size;
	for (;;)
	{
		if (input_line(&buf, &size))
			break;
		process_line(&buf, size);
		print_line(buf);
	}
	return 0;
}