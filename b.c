#include <stdio.h>
#include <stdlib.h>

int str_len(char *);
char *str_cat(char *, const char *);
char *add_spaces(char *, int);
int count_spaces(char *);

int input_line(char **);
void process_line(char **);
void print_line(char *);

int main()
{
    char *buf;
    for (;;)
    {
        if (input_line(&buf))
            break;
        process_line(&buf);
        print_line(buf);
    }
    return 0;
}

int str_len(char *string)
{
    int length = 0;
    while (*string++ != '\0')
    {
        length++;
    }
    return length;
}

char *str_cat(char *dest, const char *source)
{
    char *s1 = dest;
    const char *s2 = source;
    char c;

    while (*s1 != '\0')
    {
        s1++;
    }
    s1--;

    do
    {
        c = *s2++;
        *++s1 = c;
    }
    while (c != '\0');

    return dest;
}

char *add_spaces(char *string, int count)
{
    char *s = string;

    while (*s != '\0')
    {
        s++;
    }
    s--;

    while (count--)
    {
        *++s = ' ';
    }
    *++s = '\0';

    return string;
}

int count_spaces(char *string)
{
    int spaces = 0;
    while (*string != '\0')
    {
        if (*string == ' ' || *string == '\t')
        {
            spaces++;
        }
        *string++;
    }
    return spaces;
}

int input_line(char **line)
{
    char *buf, *last;
    int rets;
    int size = 81;
    buf = (char *)calloc(size, sizeof(char));
    scanf("%80[^\n]%n", buf, &rets);
    if (feof(stdin))
    {
        free(buf);
        return 1;
    }
    while (rets > 79)
    {
        last = &(buf[size - 1]);
        size += 80;
        buf = (char *)realloc(buf, size * sizeof(char));
        scanf("%80[^\n]%n", last, &rets);
    }
    fflush(stdin);
    *line = buf;
    return 0;
}

void process_line(char **source)
{
    int i, j;
    char *line = *source;
    char *words[40];
    char *dest = (char *)calloc(81, sizeof(char));
    int length = str_len(line);
    int pr = count_spaces(line);
    int spaces = 80 - length + pr;
    int common_spaces;
    int extra_spaces;
    int word_qu = 0;

    while (*line != '\0')
    {
        while (*line == ' ' || *line == '\t')
        {
            line++;
        }
        words[word_qu] = line;
        while (*line != ' ' && *line != '\t' && *line != '\0')
        {
            line++;
        }
        *line = 0;
        line++;
        word_qu++;
    }

    common_spaces = spaces / (word_qu - 1);
    extra_spaces = spaces % (word_qu - 1);

    for (j = 0; j < word_qu - 1; j++)
    {
        str_cat(dest, words[j]);
        if (j < extra_spaces)
        {
            add_spaces(dest, common_spaces + 1);
        }
        else
        {
            add_spaces(dest, common_spaces);
        }
    }
    str_cat(dest, words[word_qu - 1]);
    free(*source);

    *source = dest;
}



void print_line(char *line)
{
    printf("%s\n", line);
    free(line);
}