#include <stdio.h>
#include <stdlib.h>
int main()
{
      char str[100];
    int i,vowCount=0,consCount=0,ac=0;;
    printf("Enter a string for count vowel and consonant\n");
    gets(str);
    i=0;
    do{
        if(str[i] == 'a'|| str[i] == 'e'|| str[i] == 'i'|| str[i] == 'o'|| str[i] == 'u'
    ||str[i] == 'A'|| str[i] == 'E'|| str[i] == 'I'|| str[i] == 'O'|| str[i] == 'U' ){
        vowCount++;
    }
    else if((str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z' )){
        consCount++;
    }
    else if((str[i] == 'á'|| str[i] == 'é'|| str[i] == 'í'|| str[i] == 'ó'|| str[i] == 'ú'|| str[i]=='ý') ){
    	ac++;
	}
     i++;
}while(str[i]);
printf("The number of vowels: %d \n",vowCount);
printf("The number of consonant: %d \n",consCount);
printf("%d",ac);

    return 0;
}


