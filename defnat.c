#include <stdio.h>

int main() {
    int n;
    char p = '|';
    int i;
    printf("Введите целое число: ");
    scanf("%d", &n);
    if (n <= 0){
        printf(" ");
    } else {
        for (i = 1; i <= n; i++){
            printf("%c", p);
        }
    }
    return 0;
}