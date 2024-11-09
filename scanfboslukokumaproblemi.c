#include <stdio.h>
#include <stdlib.h>

typedef struct Student{
    char name[20];
    int student_number;
    char course[20];
    float mark;
} student;

void create(student *student){
    printf("\nEnter name: ");
    scanf("%[^\n]%*c", student->name); 

    //scanf("%s", ...) fonksiyonunun bu sekilde kullaniminda birden fazla kelime girisinde boşluk karakterini bir girişin sonu olarak algılamasından kaynaklanan bir sorun ortaya cikiyor. 
    //scanf in bosluk okumasini saglamak icin 2 yontem var:
    //1. ->  scanf("%[^\n]%*c",...) kullanmak
        //%[^\n]: Bu format spesifikasyonu, newline karakterine kadar olan tüm karakterleri okur. 
        //Yani, boşluklar dahil olmak üzere bütün satırı okur.
        //%*c: Buradaki * işareti, scanf'ın son okuduğu karakteri (bu durumda newline karakterini) okuyup atlamasını sağlar. 
        //Eğer *c kullanmazsanız, newline karakteri name dizisine eklenir.

        //getchar() kullanarak, tampondaki newline karakterini temizliyoruz.

    //2. -> fgets(student.name, sizeof(student.name), stdin);
        //Kullanıcıdan bir satır verisi alır, yani boşluklar da dahil olmak üzere tüm karakterleri okur.
        //Bu nedenle, boşluklu metinler (örneğin: tam ad veya kurs adı) için çok uygundur.
        //bundan sonra da getchar() kullanmak gerek


    printf("\nEnter roll number: ");
    scanf("%d", &student->student_number);
    getchar();  // To consume the newline left in the input buffer

    printf("\nEnter the course name: ");
    scanf("%[^\n]%*c", student->course);  // Get course name including spaces

    printf("\nEnter marks: ");
    scanf("%f", &student->mark);
}

void show(student *student){
    printf("Name: %s\nRoll number: %d\nCourse name: %s\nMarks: %.2f", 
           student->name, student->student_number, student->course, student->mark);
}

int main(){
    student *student1 = (student*)malloc(sizeof(student));

    printf("Please enter the student information: \n");

    create(student1);

    printf("\nThe information you entered:\n");

    show(student1);

    free(student1);//

    return 0;
}
