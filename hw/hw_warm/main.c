#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "split.h"

int main(int argc, char* argv[]) {
	//get delimiter:
	int len = 0;
	for( int i = 1; i < argc; i++){
		len += strlen(argv[i]);
	}

	//char concatSep[500] = "";
	char *concatSep = (char *)malloc(len+1);
	if(argc == 1){
		strcpy(concatSep, " \t");
	}
	else{

		for(int i = 1; i < argc; i++){
			strcat(concatSep, argv[i]);
		}
	}
	//get line-by-line input:
	char buff[1000];
	
	while(fgets(buff, 4096, stdin) != NULL){
		int wordCount;
		buff[strlen(buff)-1] = '\0';
		char **words = string_split(buff, concatSep, &wordCount);

		
		if(buff[0] == '.' && buff[1] == '\n'){
			break;
		}

		//buff[strlen(buff)-1] = '\0';
		for(int j = 0; j < wordCount; j++){
			printf("[%s]", words[j]);
			free(words[j]);
		}
		 
		

		free(words);
	}
	free(concatSep);
	return 0;
}


