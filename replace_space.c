#include <stdio.h>
#include <string.h>

char* replace(char *str, int n)
{
	int i, j, count;
	struct list *head = NULL;

	if(n <= 0)
		return NULL;
	
	for(i = 0, count = 0; i < n; i++)
		if(str[i] == ' ')
			count++;

	str[n+count*2] = '\0';
	for(i = n+count*2-1, j = n-1; i >= 0; i--, j--){
		if(str[j] != ' ')
			str[i] = str[j];
		else{
			str[i--] = '0';
			str[i--] = '2';
			str[i] = '%';
		}
	}
	
	return str;
}

int main()
{
	char str[256];

	scanf("%[^\n]",str);
	printf("%s\n", replace(str, strlen(str)));
	
	return 0;
}
