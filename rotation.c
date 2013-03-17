#include <stdio.h>
#include <string.h>

char* rotation(char *str, int rot)
{
	int cur, len = strlen(str), lbound;
	int i, j;
	char tmp;
	int t_len;

	if(rot <= 0)
		return NULL;
	for(cur = len - rot, lbound = 0 
		; cur > lbound; cur -= rot, len -= rot){
		printf("%d, %d, %d\n", cur, rot, len);
		for(i = cur, j = len < rot * 2? lbound : cur - rot;
				 i < cur + rot; i++, j++){
			tmp = str[i];
			str[i] = str[j];
			str[j] = tmp;
		}

		if(len == (rot*2) || len == 1)
			break;
		
		if(len < (rot * 2)){
			t_len = len;
			lbound += rot;
			cur = len;
			len = rot;
			rot -= (t_len - rot);
		}
		printf("%s\n", str);
	}
	return str;
}

int main()
{
	char str[256];
	int rot;
	
	scanf("%s %d", str, &rot);
	printf("%s\n", rotation(str, rot));
}
