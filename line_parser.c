#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>

void pline(char *line, char **words, int *length);

int main(void){
	char str[256];
	printf("Shëno rreshtin për me parse: ");
	scanf(" %255s[^\n]", str);
	printf("\n");

	printf("Rreshti jot: %s\n", str);

	char** words;
	int wordCnt;
	pline(str, words, &wordCnt);


	printf("Stringu i parsuar: {\n");
	for (int i = 0; i < wordCnt; i++)
		printf("\t%s,\n", words[i]);
	printf("}\n\n");

	printf("//.\n");	

	return 0;
}

void pline(char *line, char **words, int *length){
        int totalWordCount = 0;
        
	for (int i = 0; line[i] != '\0'; i++){              
                if (line[i] == ' '){
                        line[i] = '\0';
                        totalWordCount++;
                }
        }

	*length = totalWordCount;

        words = malloc(totalWordCount * sizeof(char*));
        for (int i = 0, wordCount = 0; wordCount < totalWordCount; i++){
		if (line[i] == '\0'){
			*(words+wordCount) = &line[i+1];
			wordCount++;
		}
	}
}
