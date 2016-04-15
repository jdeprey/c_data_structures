/* CS261- Assignment 1 - Q.5*/
/* Name: Joseph DePrey
 * Date: 4/10/2016
 * Solution description: Write a function void sticky(char* word) where word 
 *	is a single word such as “sticky” or “RANDOM”. sticky() should modify the 
 *	word to appear with “sticky caps” (http://en.wikipedia.org/wiki/StudlyCaps), 
 *	that is, the letters must be in alternating cases(upper and lower), starting 
 *	with upper case for the first letter. For example, “sticky” becomes “StIcKy” 
 *	and “RANDOM” becomes “RaNdOm”. Watch out for the end of the string, which is 
 *	denoted by ‘\0’. You can assume that legal strings are given to the sticky() 
 *	function.
 *	NOTE: You can use the toUpperCase(...) and toLowerCase(...) functions provided 
 *	in the skeletal code to change the case of a character. Notice that toUpperCase() 
 *	assumes that the character is currently in lower case. Therefore, you would 
 *	have to check the case of a character before calling toUpperCase(). The same 
 *	applies for toLowerCase().
 */
 
#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

void sticky(char* word){
     /*Convert to sticky caps*/
	for(int i = 0; word[i] != '\0'; i++){
		/*Every odd character should be lowercase*/
		if(i % 2){
			if((word[i] >= 'A') && (word[i] <= 'Z')){
				word[i] = toLowerCase(word[i]);
			}
		}
		/*Every even character should be uppercase*/
		else{
			if((word[i] >= 'a') && (word[i] <= 'z')){
				word[i] = toUpperCase(word[i]);	
			}
		}
	}
}

int main(){
    /*Read word from the keyboard using scanf*/
    char userString[509];
    printf("Enter a word: ");
    scanf("%s", userString);

    /*Call sticky*/
    sticky(userString);

    /*Print the new word*/
    printf("%s\n", userString);

    return 0;
}
