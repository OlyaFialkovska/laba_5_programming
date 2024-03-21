#include <stdio.h>
#include <stdlib.h>

typedef struct //structure
{
    struct
    {
        char *surname,
             *name,
             *middle_name;
    } full_name;

    char *sex;
    int *height;

    struct
    {
        int *programming,
            *SDA,
            *Mathematical_analysis,
            *Linear_algebra;
    } subject;

} student ;

student s[26];
/*
struct{
int d:3;
int a:4;
}t;

union{
char surname,
    name;
};
*/
void inizialization()
{
    char line[150];
    FILE *file = fopen("D:\students.txt", "r");

    for(int i=0; i<26; i++)//inizialization
    {
        fgets(line, sizeof(line), file);

        int length = strcspn(line, "\n");//calculates the length of the number of characters before "\n"

        char *token_surname = strtok(line," ");
        char *surname = strdup(token_surname);//without handling memory
        s[i].full_name.surname = surname;

        char *token_name = strtok(NULL," ");
        char *name = strdup(token_name);
        s[i].full_name.name = name;

        char *token_middle_name = strtok(NULL," ");
        char *middle_name = strdup(token_middle_name);
        s[i].full_name.middle_name = middle_name;

        s[i].height = atoi (strtok(NULL," "));

        s[i].subject.programming = atoi (strtok(NULL," "));
        s[i].subject.SDA = atoi (strtok(NULL," "));
        s[i].subject.Mathematical_analysis = atoi (strtok(NULL," "));
        s[i].subject.Linear_algebra = atoi (strtok(NULL," "));

        s[i].sex = line [length-1];
    }

    fclose(file);
}
void out_inizialization()
{
    for(int i=0; i<26; i++)
    {
        printf("Student[%d]:\n",i);
        puts(s[i].full_name.surname);
        puts(s[i].full_name.name);
        puts(s[i].full_name.middle_name);//out inizialization
        printf("%d\t",s[i].height);
        printf("%d\t",s[i].subject.programming);
        printf("%d\t",s[i].subject.SDA);
        printf("%d\t",s[i].subject.Mathematical_analysis);
        printf("%d\t",s[i].subject.Linear_algebra);
        printf("%c\t",s[i].sex);
        puts("\n");
    }
}

void sort(int *max_height1)
{
    int buf;
    for(int i=0; i<26 ; i++)//in dod mas
        max_height1[i] = s[i].height;

    for(int k=1; k<26 ; k++)//sort
        for(int i=0; i<26-k ; i++)
        {
            if(max_height1[i] < max_height1[i+1] )
            {
                buf = max_height1[i];
                max_height1[i] = max_height1[i+1];
                max_height1[i+1] = buf;
            }
        }
}

void out_sort(int max_height1[26],int ind)
{
    int p=0;
    for(int i=0; i<26 ; i++)//out sort
        for(int j=0; j<26 ; j++)
            if(max_height1[i] == s[j].height && ind != j && p!=4 && s[j].sex == 'm' )
            {
                ind = j;
                printf("\n\nStudent[%d]:\n",i);
                puts(s[ind].full_name.surname);
                puts(s[ind].full_name.name);
                puts(s[ind].full_name.middle_name);//out inizialization
                printf("%d\t",s[ind].height);
                printf("%d\t",s[ind].subject.programming);
                printf("%d\t",s[ind].subject.SDA);
                printf("%d\t",s[ind].subject.Mathematical_analysis);
                printf("%d\t",s[ind].subject.Linear_algebra);
                printf("%c\t",s[ind].sex);
                printf("\t|max [%d] = %d\n",ind,s[ind].height);
                p++;
            }
}

void separator()
{
    for(int i = 1; i < 9*13; i++)
        printf("-");
    printf("\n");
}

int main()
{
    int max_height[26],ind;

    separator();//-
    inizialization();
    out_inizialization();

    sort(&max_height);

    separator();//-
    out_sort(&max_height,ind);
    separator();//-

    return 0;
}
