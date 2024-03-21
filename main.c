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

    } students ;

    students s [26];

int main()
{
    char line [150];
    FILE *file = fopen("D:\students.txt", "r");

    char ch;
    for(int i=0; i<26; i++)//inizialization
    {
        fgets(line, sizeof(line), file);
        while((ch = getc (file)) != EOF)
            printf ("%c", ch);

        s[i].full_name.surname = ch;
        s[i].full_name.name = ch;
        s[i].full_name.middle_name = ch;
        s[i].height = atoi (ch);
        s[i].subject.programming = atoi (ch);
        s[i].subject.SDA = atoi (ch);
        s[i].subject.Mathematical_analysis = atoi (ch);
        s[i].subject.Linear_algebra = atoi (ch);
        s[i].sex = ch;
        printf("Student[%d]:\n",i);
        puts(s[i].full_name.surname);
        puts(s[i].full_name.name);
        puts(s[i].full_name.middle_name);//out inizialization
        printf("%d\t",s[i].height);
        printf("%d\t",s[i].subject.programming);
        printf("%d\t",s[i].subject.SDA);
        printf("%d\t",s[i].subject.Mathematical_analysis);
        printf("%d\t",s[i].subject.Linear_algebra);
        puts(s[i].sex);
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

    for(int i=0,p=0; i<26 ; i++)//out sort
        for(int j=0; j<4 ; j++)
            if(max_height[j]==s[i].height && ind != i && p!=4)
            {
                ind = i;
                printf("max1 = %d,\tind = %d\n",s[ind].height,ind);
                p++;
            }

    fclose(file);

    return 0;
}
