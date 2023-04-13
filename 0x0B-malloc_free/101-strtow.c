#include <stdio.h>
#include <stdlib.h>

int count_words(char *str)
{
	int count = 0;
	int i = 0;

	while (str[i])
	{
		if (str[i] != ' ')
		{
			count++;
			while (str[i] != ' ')
				i++;
		}
		i++;
	}
	return (count);
}

int len_words(char *s)
{
	int len = 0;

	while (*s && *s != ' ')
	{
		len++;
		s++;
	}
	return (len);
}

/**
 * _strncpy - copies a string
 * @dest: destination string
 * @src: source string
 * @n: number of bytes to copy
 *
 * Return: pointer to the resulting string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	i = 0;

	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char **strtow(char *str)
{
	char **result;
	int len;
	int i = 0;

	if (str == NULL || *str == '\0')
		return (NULL);

	result = malloc(sizeof(char *) * (count_words(str) + 1));
	while (*str)
	{
		if (*str != ' ')
		{
			len = len_words(str);
			result[i] = malloc(sizeof(char) * len + 1);
			if (!result[i])
			{
				for (int j = 0; j < i; i++)
					free(result[j]);
				free(result);
				return (NULL);
			}
			_strncpy(result[i], str, len);

			i++;
			while (*str != ' ')
				str++;
		}
		while (*str == ' ')
			str++;
	}
	return (result);
}

void print_tab(char **tab)
{
	int i;

	for (i = 0; tab[i] != NULL; ++i)
	{
		printf("%s\n", tab[i]);
	}
}
int main(void)
{
	char **tab;

	tab = strtow("  ALX School  #cisfun  ");
	if (tab == NULL)
	{
		printf("Failed\n");
		return (1);
	}
	print_tab(tab);
	return (0);
}
