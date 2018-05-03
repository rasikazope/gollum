#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>


/*
 *  * Complete the function below.
 *   */
char* findOrder(int strDict_size, char** strDict) {


}




int main() {
    FILE *f = fopen(getenv("OUTPUT_PATH"), "w");
    char* res;

    int _strDict_size = 0;
    int _strDict_i;
    scanf("%d\n", &_strDict_size);
    char* _strDict[_strDict_size];
    for(_strDict_i = 0; _strDict_i < _strDict_size; _strDict_i++) {
        char* _strDict_item;
        _strDict_item = (char *)malloc(10240 * sizeof(char));
        scanf("\n%[^\n]",_strDict_item);

        _strDict[_strDict_i] = _strDict_item;
    }

    res = findOrder(_strDict_size, _strDict);
    fprintf(f, "%s\n", res);

    fclose(f);
    return 0;
}

