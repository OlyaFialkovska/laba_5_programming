#include <stdio.h>
#include <stdlib.h>
//введення даних, розв’язок задачі, виведення результату

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

//puts(line);
student s [26];

int main()
{
    char line [150];
    FILE *file = fopen("D:\students.txt", "r");

    for(int i=0; i<26; i++)//inizialization
    {
        fgets(line, sizeof(line), file);

        int length = strcspn(line, "\n");

        char *token_surname = strtok(line," ");
        char *surname = strdup(token_surname);
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
        printf("Student[%d]:\n",i);//out inizialization
        puts(s[i].full_name.surname);
        puts(s[i].full_name.name);
        puts(s[i].full_name.middle_name);
        printf("%d\t",s[i].height);
        printf("%d\t",s[i].subject.programming);
        printf("%d\t",s[i].subject.SDA);
        printf("%d\t",s[i].subject.Mathematical_analysis);
        printf("%d\t",s[i].subject.Linear_algebra);
        printf("%c\t",s[i].sex);
        puts("\n");


    }
    puts("\n");

    int max_height[26],ind,buf;

    for(int i=0; i<26 ; i++)//in dod mas
        max_height[i] = s[i].height;

    for(int k=1; k<26 ; k++)//sort
        for(int i=0; i<26-k ; i++)
        {
            if(max_height[i] < max_height[i+1] )
            {
                buf = max_height[i];
                max_height[i] = max_height[i+1];
                max_height[i+1] = buf;
            }
        }
    for(int i=0; i<26 ; i++)//out sort
        printf("%d,%d,%c\n",s[i].height,max_height[i],s[i].sex);

    int p=0;
    for(int i=0; i<26 ; i++)//out sort
        for(int j=0; j<26 ; j++)
            if(max_height[i] == s[j].height && ind != j && p!=4 && s[j].sex == 'm' )//name and surname out???????
            {
                ind = j;
                printf("max1 = %d,\tind = %d\n",s[ind].height,ind);
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
                p++;
            }

    fclose(file);

    return 0;
}
