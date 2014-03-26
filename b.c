#include <stdio.h>
#include <stdlib.h>

/*Вычисляет длину строки*/
int str_len(char *string)
{
    int length = 0;
    while (*string++ != '\0')
    {
        length++;
    }
    return length;
}

/*Сливает две строки в одну*/
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

/*Добавляет нужное число пробелов в конец*/
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

/*Подсчитывает количество пробелов и знаков табуляции в строке*/
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

int input_line(char **line, int *size)
{
    char *buf, *last;
    int rets;
    *size = 81;
    buf = (char *)calloc(*size, sizeof(char));
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
        buf = (char *)realloc(buf, *size * sizeof(char));
        scanf("%80[^\n]%n", last, &rets);
    }
    fflush(stdin);
    *line = buf;
    return 0;
}

void process_line(char **source, int *size)
{
    int i, j;
    char *line = *source;
    char *words[40];
    char *dest = (char *)calloc(82, sizeof(char));
    int length = str_len(line);
    int pr = count_spaces(line);
    int spaces;
    int common_spaces;
    int extra_spaces;
    int word_qu = 0;
    spaces = 80 - length + pr;

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
        if (j <= extra_spaces)
        {
            add_spaces(dest, common_spaces + 1);
        }
        else
        {
            add_spaces(dest, common_spaces);
        }
    }
    str_cat(dest, words[word_qu - 1]);
    free (*source);

    *source = dest;
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