#include <stdio.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <stdlib.h>


void saveFile(char* path, wchar_t* enter);
wchar_t* loadFile(char* path);

int main() 
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    wchar_t sentence[1000];
    wprintf(L"Введите предложение: ");
    fgetws(sentence, 1000, stdin);
    int count = 0, wordCount = 0, inWord = 0;
    for (int i = 0; sentence[i] != L'\0'; i++)
    {
        if (iswspace(sentence[i]) || sentence[i] == L'\n') { // Учитываем символ новой строки
            if (inWord) 
            {
                wordCount++;
                inWord = 0;
            }
        }
        else 
        {
            inWord = 1;
        }
        if (sentence[i] == L'.' || sentence[i] == L'?' || sentence[i] == L'!')
        {
            if (wordCount >= 5) {
                count++;
            }
            wordCount = 0;
        }
    }
    wprintf(L"Количество предложений, содержащих больше 5 слов: %d\n", count);
    saveFile("pr18.txt", sentence);
    wprintf(loadFile("pr18.txt"));
    system("pause");
    return 0;
}


void saveFile(char* path, wchar_t* enter)
{
    FILE* file = fopen(path, "w");
    if (file == NULL)
    {
        printf("Ошибка при открытии файла\n");
        return;
    }
    fwprintf(file, L"%ls", enter); // Write the wide-character string to the file
    fclose(file);
}

wchar_t* loadFile(char* path)
{
    FILE* file = fopen(path, "r");
    if (file == NULL)
    {
        printf("Ошибка при открытии файла\n");
        return NULL;
    }
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fseek(file, 0, SEEK_SET);
    wchar_t* enter = (wchar_t*)malloc(sizeof(wchar_t) * (size + 1)); // Allocate memory for the wide-character string
    fgetws(enter, size + 1, file); // Read the wide-character string from the file
    fclose(file);
    return enter;
}