#include <stdio.h>
#include <string.h>

char* reverse(char *str, int n)
{
	int i, j;
	char tmp;

	if(n <= 0)
		return NULL;
	if(str == NULL)
		return str;
	
	for(i = 0, j = n-1; i < j ; i++, j--){
		tmp = str[j];
		str[j] = str[i];
		str[i] = tmp;
	}

	return str;
}

int main()
{
	char str[256];

	scanf("%s", str);
	printf("%s\n", reverse(str, strlen(str)));
}
