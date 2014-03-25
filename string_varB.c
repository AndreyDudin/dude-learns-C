#include <stdio.h>

#include <stdlib.h>
int str_len(char *line){
	int i;
	while(*line++!='\0')
		++i;
	return i;
}



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

void process_line(char **line, int *size)
{ char *words[40], *dest;
	int len=0,spaces,pr=0,common_spaces,extra_spaces;
	int i,j=0,word_qu;
	dest=calloc(82,sizeof(char));
	while(*line++){
		if((*line=='\t')||(*line==' '))
			++pr;
		++len;
	}
	line-=len;
	spaces=80-len+pr;
	*line=0;
	while(*line!='\0'){
			while((*++line=='\t')||(*++line==' '))
			words[j]=line;
			while((*line++!='\t')||(*line++!=' ')){
				*++words[j]=*line;
				}
			j+=1;
	}
	word_qu=j;

	common_spaces=spaces/(j-1);
	extra_spaces=spaces%(j-1);
	j=0;
	while(j<word_qu){
		for(i=0;i<common_spaces;i++)
			*++words[j]=' ';
		++j;


	}
	j=0;
	while(j<extra_spaces){
		*++words[j]=' ';
		words[j]-=str_len(words[j]);
		++j;
	}
	while(j<word_qu){
		while(*dest++=*words[j]++);
		++j;
		
	}
	dest-=str_len(dest);
	*line=dest;
	
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