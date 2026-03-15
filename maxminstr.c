//Задание - Вычисление максимальной и минимальной длины строк входного текстового файла на СИ
//Идея: считывать файл или строку посимвольно, пока он не прервётся или когда ввод прервёт пользователь
//С каждым переносом строки мы сравниваем предыдущую максимальную или минимальную длину строки с нынешней
//Можно рассмотреть несколько вариаций кода 1 - для вводимой пользователем строки, 2 - для выбранного файла, 3 - с выбором, вручную вводить строки или читать файл

//1 вариант
#include <stdio.h>

int Max(int n, int m){
    if (n >= m){
        return n;
    } else {
        return m;
    }
}

int Min(int n, int m){
    if (n <= m){
        return n;
    } else {
        return m;
    }
}

int main(){
    int mx = 0;
    int mn = 9999;
    int count = 0;
    char ch;
    while(1){
        ch = getchar();     //читаем всё посимвольно
        if (ch == EOF){     //конец ввода 
            if (count > 0){     //проверка на нулевую строку
                mx = Max(count, mx);
                mn = Min(count, mn);
            }
            break;      //выход из цикла 
        }

        if (ch == '\n'){        //перенос строки 
            if (count > 0){     //проверка на нулевую строку
                mx = Max(count, mx);
                mn = Min(count, mn);
            }
            count = 0;      //обнуление счётчика чтобы перейти к следующей строке
        }

        else {
            count = count + 1;      //считаем обычные символы помимо EOF и \n
        }
    }
    printf("Максимум: %d, Минимум: %d\n", mx, mn);

    return 0;
}


//2 вариант
#include <stdio.h>

int Max(int n, int m){
    if (n >= m){
        return n;
    } else {
        return m;
    }
}

int Min(int n, int m){
    if (n <= m){
        return n;
    } else {
        return m;
    }
}

int main(){
    char ch;
    int mx = 0;
    int mn = 9999;
    FILE *f;
    int count = 0;
    char filename[100];

    printf("Введите имя файла: ");
    scanf("%s", filename);
    f = fopen(filename, "r");
    if (f == NULL){                 //при неверном вводе имени
        printf("Нет такого файла\n");
        return 0;
    }

    while(1){
        ch = getc(f);
        if (ch == EOF){         //если конец файла
            if (count > 0){     //проверка на пустую строку
                mx = Max(count, mx);
                mn = Min(count, mn);
            }
            break;      //выход из файла и подведение итогов
        }

        if (ch == '\n'){        //если перенос строки
            if (count > 0){             //проверка на пустую строку
                mx = Max(count, mx);
                mn = Min(count, mn);
            }
            count = 0;          //обнуление счётчика и переход к следующей строке
        }

        else {
            count = count + 1;      //с каждым символом кроме EOF и \n будет прибавляться единица
        }
    }
    printf("Максимум: %d, Минимум: %d\n", mx, mn);
    return 0;
}


//3 вариант
#include <stdio.h>

int Max(int n, int m){  //функция максимума
    if (n >= m){
    return n;
    } else {
        return m;
    }
}

int Min(int n, int m){ //функция минимума
    if (n <= m){
        return n;
    } else {
        return m;
    }
}

int main() {
    char ch;           // символ
    int count = 0;     // кол-во символов
    int mx = 0;            // макс. значение
    int mn = 100;         // мин. значение
    char filename[100];
    FILE *f;
    int useFile = 0;
    
    printf("Читать из файла? (1 - да, 0 - нет)\n");
    scanf("%d", &useFile);

    if (useFile == 1){  //смотрим файл
    printf("Введите имя файла: \n");
    scanf("%s", filename);
    f = fopen(filename, "r");
        if (f == NULL){
            printf("Файл не найден\n");
            return 0;
        }
    } else {
        f = stdin;  //смотрим ввод
    }
    while (1) {
        ch = fgetc(f);    //читаем посимвольно
        if (ch == EOF) {   // если конец ввода/файла
            if (count > 0){
                mx = Max(count, mx);
                mn = Min(count, mn);
            }
            break;
        }
        // если перенос строки
        if (ch == '\n') {
            if (count > 0){
                mx = Max(count, mx);
                mn = Min(count, mn);
            }
            count = 0;
        }
        else { //обычный символ
            count = count + 1;
        }
    }
    if (useFile == 1){      //закрытие файла
        fclose(f);
    }

    // выводим результат
    printf("\nМаксимальное значение: %d, Минимальное значение: %d\n", mx, mn);

    return 0;
}


//tests (на 3-м варианте)


//счёт файла:

//Читать из файла? (1 - да, 0 - нет)
//1
//Введите имя файла: 
//test.txt
//Максимальное значение: 49, Минимальное значение: 1

//файл test.txt:
//awjdiajwidaw
//awd
//d
//dsfsdfdsfsdfsdddhdhdhdhdhdhdhdhdhdhdhhdhdhdhddhhd
//dwadjwdjadjwjdjawdjajdajwdjajd jj adj aj dj ad


//счёт ввода:
//Читать из файла? (1 - да, 0 - нет)
//0
//daddd
//dd
//dddddd
//^D
//Максимальное значение: 6, Минимальное значение: 2