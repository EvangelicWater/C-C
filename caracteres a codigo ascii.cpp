#include <stdio.h>
#include <string.h>

int main() {

    char name[100];
    int ascii=0;
    memset(name, 0, sizeof(name));
    printf("Enter a name : \n");
    fgets(name, sizeof(name), stdin);

    size_t n = strlen(name);
    if (n > 0 && name[n - 1] == '\n') {
        name[n - 1] = '\0';

        --n;
       
    }

    for (size_t i = 0; i < n; i++){
        int e = name[i];
         ascii=ascii+name[i];
        printf("The ASCII value of the letter %c is : %d resultado de la suma: %d\n", name[i], e,ascii);
    }


    /* To correctly print a size_t, use %zu */
    printf("%zu\n", n);

    /* In C99 main implicitly returns 0 if you don't add a return value
       yourself, but it's a good habit to remember to return from functions. */
    return 0;
}
