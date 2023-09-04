#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "split.h"


char **string_split(const char *input, const char *sep, int *num_words){
    /*
    strspn(s1, s2): returns length of how many chars in s2 are in s1 
    strcspn: returns length of how many chars in s2 are NOT in s1 
    (opposite of strspn)
	 //strchr() returns pointer to first occurence of char
    */
   //ex. trees-are--cool (delim = - ) -> [trees][are][cool] 


 
	*num_words = 0;
   char **words = (char **)malloc(100 * sizeof(char *)); //dynamically instead of constant 100* ?
  
	char* inputCopy = strdup(input);
  
	char* tokens = strtok(inputCopy, sep); //will split for us based on sep, returns pointer to first tok
   int start_delim = strcspn(inputCopy, sep);

   if(start_delim == 0){
      words[*num_words] = (char *) malloc((1) * sizeof(char));
      words[*num_words][0] = '\0';
     
     (* num_words)++;
   }


	while(tokens != NULL){
		words[(*num_words)++] = strdup(tokens); //index by the num_words + 1, copy token over
		tokens = strtok(NULL, sep); //NULL will let strtok iterate thru same input string internally.
	}
   strncpy(inputCopy, input+(strlen(input)-1),1);

   if(strcspn(inputCopy, sep) == 0 ){
      words[*num_words] = (char *) malloc((1) * sizeof(char));
      words[*num_words][0] = '\0';
      (* num_words)++;
   }
	free(inputCopy);
	return words;



}
    

// int main() {
//    //  int len;
//    //  const char str1[] = "trees-are--cool";
//    //  const char str2[] = "trees";

//    //  len = strspn(str1, str2);

//    //  printf("%d\n", len );
   
//    //  return(0);

// 	const char* input = "AAAAfooXXXXbarZXYYYbazYYYY";
//     const char* delimiter = "AXZ";

//     int numWords;
//     char** words = string_split(input, delimiter, &numWords);

//     for (int i = 0; i < numWords; i++) {
//         printf("Word %d: %s\n", i + 1, words[i]);
//         free(words[i]); 
//     }

//     free(words); 
//     return 0;
// }

