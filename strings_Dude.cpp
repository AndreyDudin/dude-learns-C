#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int input_line(char **line, int *size)
{
    char *buf, *last;
    int rets;

    *size = 81;
    buf = calloc(*size, sizeof(char));
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
        buf = realloc(buf, *size * sizeof(char));
        scanf("%80[^\n]%n", last, &rets);
    }
    fflush(stdin);
    *line = buf;
    return 0;
}

void process_line(char **line, int size)
{
    char *source, *dest, *words[40], *tok;
    int i, j;
    int quchars, quword, spaces, divspaces, modspaces, lentok, destsize = 3; /*назови нормально*/

    source = *line; /*зачем?*/
    dest = calloc(destsize, sizeof(char));
    tok = strtok(source, " \t");
    quword = 1;
    quchars = strlen(tok);
    words[0] = tok;
    while (tok = strtok(NULL, " \t"))
    {
        lentok = strlen(tok);
        quchars += lentok;
        if (quchars >= 80 -quword)
        {
            quchars -= lentok;
            destsize += 83;
            dest = realloc(dest, destsize * sizeof(char));
            spaces = 80 - quchars;
            divspaces = k / (quword - 1);
            modspaces = k % (quword - 1);
            for (i = 0; i < quword; i++)
            {
                strcat(dest, words[i]);
                if (i < quword - 1)
                {
                    for (j = 0; j < (i >= modpaces ? divspaces : divspaces + 1); j++)
                    {
                        strcat(dest, " ");
                    }
                }
            }
            quword = 1;
            quchars = strlen(tok);
            words[0] = tok;
        }
        else
        {
            words[quword++] = tok;
        }
    }
    if (quchars + quword < 80)
    {
        destsize += 82;
        dest = realloc(dest, destsize * sizeof(char));
        modspaces = 80 - quchars;
        if (quword > 1)
        {
            divspaces = k / (quword - 1);
            modspaces = k % (quword - 1);
            for (i = 0; i < n; i++)
            {
                strcat(dest, words[i]);
                if (i < quword - 1)
                {
                    for (j = 0; j < (i >= modspaces ? divspaces : divspaces + 1); j++)
                    {
                        strcat(dest, " ");
                    }
                }
            }
        }
        else
        {
            strcat(dest, words[0]);
            /*strcat(dest, "\n"); наху€, если вывод в print_line?*/
        }
    }
    free(source);
    *line = dest;
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
        if (input_line(&buf, &size)) break;
        process_line(&buf, size);
        print_line(buf);
    }
    return 0;
}