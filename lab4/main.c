#include <stdio.h>
#include <stdlib.h>

int main()
{
    fflush(stdin);
    int filePathByteSize = 50;
    char *filePath = (char*)calloc(filePathByteSize, sizeof(char));
    char ch;
    int filePathLength = 0;

    // ---- Input

    printf("Input path of file\n");
    while (10 != (ch = getc(stdin)))
    {
        *(filePath + filePathLength) = ch;
        filePathLength++;
        if (filePathLength == filePathByteSize)
        {
            filePathByteSize += 50;
            char *filePathTemp = (char*)realloc(filePath, filePathByteSize*sizeof(char));
            filePath = filePathTemp;
            free(filePathTemp);
        }
    }
    FILE *file = fopen(filePath, "r");
    int backTrackFlag = 0;
    if(NULL == file)
    {
      printf("Can't open file");
      return 0;
    }

    rewind(file);

    int wordAmount = 0;

    char vowels[13] = {65, 69, 73, 79, 85, 89, 97, 101, 105, 111, 117, 121};
    while ((ch = getc(file)) != -1 )
    {
        while (!(((ch > 64)&&(ch < 91))||((ch > 96)&&(ch < 123))||((ch < 58)&&(ch > 47)||(ch != -1))))
        {
            ch = getc(file);
        }
        int i;
        int wordLength = 0;
        for (i=0; i<12; i++)
        {
            if (backTrackFlag)
            {
                break;
            }
            if (vowels[i] == ch)
            {
                char chLast;
                while (((ch > 64)&&(ch < 91))||((ch > 96)&&(ch < 123)))
                {
                    wordLength++;
                    chLast = ch;
                    ch = getc(file);
                }
//                if (wordLength > 1)
//                {
                    int j;
                    for (j=0; j<12; j++)
                    {
                        if (vowels[j] == chLast)
                        {
                            wordAmount++;
                            if (10 == ch)
                            {
                                wordLength++;
                            }
                            if (-1 != ch)
                            {
                                wordLength++;
                            }
                            fseek(file, -wordLength, SEEK_CUR);

                            while ((((ch = getc(file)) > 64)&&(ch < 91))||((ch > 96)&&(ch < 123)))
                            {

                                printf("%c",ch);
                            }
                            printf("\n");
                            backTrackFlag = 1;
                            break;
                        }
                    }
                    break;
//                }
            }
        }
        if (backTrackFlag)
        {
            backTrackFlag = 0;
            continue;
        }
        while ((((ch = getc(file)) > 64)&&(ch < 91))||((ch > 96)&&(ch < 123)))
        {

        }
    }
    if (0 == wordAmount)
    {
        printf("Matching words wasn't found\n");
    }
//    getchar();
    return 0;
}
