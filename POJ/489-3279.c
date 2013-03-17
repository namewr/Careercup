#include <stdio.h>
#include <stdlib.h>



int trans_tab[26] = {2, 2, 2, 3, 3, 3, 4, 4, 4,
			5, 5, 5, 6, 6, 6, 7, -1, 7, 7,
			8, 8, 8, 9, 9, 9, -1};

static inline char* std_form(int x, char *str)
{
	int i;

	for(i = 7; i >= 0; i--, x /= 10){
		str[i] = (x % 10) + '0';
		if(i == 4)
			str[--i] = '-';
	}

	str[8] = '\0';
	return str;
	
}

static inline int trans(char *str)
{
/* 
	int ret = trans_tab[a - 'A'];
	if(ret < 0)
		exit(0)
	return ret;
*/
	/* use upper to avoid lower case*/
	int i, ret;

	for(ret = 0, i = 0; str[i] != '\0'; i++){
		if(str[i] >= 'A' && str[i] <= 'Z'){
			ret += trans_tab[str[i] - 'A'];
			ret *= 10;
		}else if(str[i] >= '0' && str[i] <='9'){
			ret += str[i] - '0';
			ret *= 10;
		}
	}

	return ret/10;
}

int comp(const void *a, const void *b)
{
	return *(int*)a-*(int*)b;
}

int main()
{
	int num, *arr;
	char str[20];
	int i, count;
	char res[9];

	scanf("%d", &num);
	arr = (int*)malloc(sizeof(int)*num);
	for(i = 0; i < num; i++){
		scanf("%s", str);
		arr[i] = trans(str);
	} 
	
	qsort(arr, num, sizeof(int), comp);

	for(i = 1, count =1; i < num; i++){
		if(arr[i] == arr[i-1]){
			count++;
		}else{
			if(count > 1)
				printf("%s %d\n", 
					std_form(arr[i-1], res), count);
			count = 1;
		}
	}
}

