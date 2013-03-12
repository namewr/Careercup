#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* if it is not the same, user has to free it himself*/
char* compress(char *str)
{
	int i, n = strlen(str);
	char *tmp;
	char cur;
	int count;	

	if(str == NULL || n <= 0)
		return NULL;

	tmp = (char*)malloc(n);
	memset(tmp, '\0', n);
	count = 1;
	for(i = 0; i < n; i++){
		if(str[i] != str[i+1]){
			/* sprintf performance question? strcat better?*/
			sprintf(tmp,"%s%c%d", tmp, str[i], count);
			count = 1;
		}
		else
			count++;
	}

	if(strlen(tmp) < strlen(str))
		return tmp;
	return str;
}

int main()
{
	char str[265];

	scanf("%s", str);
	printf("%s\n", compress(str));	
}
