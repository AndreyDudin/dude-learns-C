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

void process_line(char **pLine, int *size)
{ char *words[40], *dest,*line, *dest_l;
	int len=0,spaces,pr=0,common_spaces,extra_spaces;
	int i,j=0,word_qu;
	line = *pLine;
	dest_l=dest=(char*)calloc(82,sizeof(char));
	while(*(line++)){
		if(*line==' ')
			++pr;
		++len;
	}
	line-=len;
	spaces=80-len+pr;
	while(*line!='\0'){
			while((*line==' ')) line++;
			words[j]=line;
 			while((*line!=' ')&&(*line!=0)) line++;

			*line=0;
			line++;
			j+=1;
	}
	word_qu=j;

	common_spaces=spaces/(j-1);
	extra_spaces=spaces%(j-1);
	j=0;
	for(j=0;j<word_qu-1;j++){
		while(*dest++=*words[j]++);
		dest--;
		for(i=0;i<common_spaces;i++) 
			*(dest+i)=' ';
		dest+=i;
		if(j<=extra_spaces)
			*dest++=' ';
		*dest=0;
	}
	while(*dest++=*words[word_qu-1]++);
	free (*pLine);

	*pLine = dest_l;
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
		process_line(&buf, &size);
		print_line(buf);
	}
	return 0;
}