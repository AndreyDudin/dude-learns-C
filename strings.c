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
    char *source, *result, *words[40], *token;
    int i, j;
    int char_quantity;
    int word_quantity;
    int spaces, common_spaces, extra_spaces;
    int token_length;
    int result_length = 3;

    source = *line; /*зачем? почему нельзя работать с line?*/
    result = calloc(result_length, sizeof(char));
    token = strtok(source, " \t");
    word_quantity = 1;
    char_quantity = strlen(token);
    words[0] = token;
    while (token = strtok(NULL, " \t"))
    {
        token_length = strlen(token);
        char_quantity += token_length;
        if (char_quantity >= 80 - word_quantity)
        {
            char_quantity -= token_length;
            result_length += 83;
            result = realloc(result, result_length * sizeof(char));
            spaces = 80 - char_quantity;
            common_spaces = spaces / (word_quantity - 1);
            extra_spaces = spaces % (word_quantity - 1);
            for (i = 0; i < word_quantity; i++)
            {
                strcat(result, words[i]);
                if (i < word_quantity - 1)
                {
                    for (j = 0; j < (i >= extra_spaces ? common_spaces : common_spaces + 1); j++)
                    {
                        strcat(result, " ");
                    }
                }
            }
            word_quantity = 1;
            char_quantity = strlen(token);
            words[0] = token;
        }
        else
        {
            words[word_quantity++] = token;
        }
    }
    if (char_quantity + word_quantity < 80)
    {
        result_length += 82;
        result = realloc(result, result_length * sizeof(char));
        spaces = 80 - char_quantity;
        if (word_quantity > 1)
        {
            common_spaces = spaces / (word_quantity - 1);
            extra_spaces = spaces % (word_quantity - 1);
            for (i = 0; i < word_quantity; i++)
            {
                strcat(result, words[i]);
                if (i < word_quantity - 1)
                {
                    for (j = 0; j < (i >= extra_spaces ? common_spaces : common_spaces + 1); j++)
                    {
                        strcat(result, " ");
                    }
                }
            }
        }
        else
        {
            strcat(result, words[0]);
        }
    }
    free(source);
    *line = result;
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