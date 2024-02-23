#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include <malloc.h>


int main() 
{
	setlocale(LC_ALL, "Rus");
	char sentence[] = "˜˜˜ ˜˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜ ˜˜˜˜˜ ˜˜˜ ˜˜˜˜ ˜˜˜˜! ˜˜˜ ˜˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜ ˜˜˜˜˜ ˜˜˜ ˜˜˜˜ ˜˜˜˜? ˜˜˜ ˜˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜ 5 ˜˜˜˜.";
	int count = 0, wordCount = 0, inWord = 0;
	for (int i = 0; i < strlen(sentence); i++)
	{
		if (sentence[i] == ' ' || sentence[i] == '\t' || sentence[i] == '\n' || sentence[i] == '\0') {
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
		if (sentence[i] == '.' || sentence[i] == '?' || sentence[i] == '!')
		{
			if (wordCount > 5) {
				count++;
			}
			wordCount = 0;
		}
		
	}
	
	printf("˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜ ˜˜˜˜ ˜˜˜˜ ˜˜˜˜˜: %d", count);
	return 0;
}