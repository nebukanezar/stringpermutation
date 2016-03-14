#include<stdio.h>
#include<string.h>
void print_permutation(char *wordRa);
void rotateLeft(char *wordRa);
char toBePrinted[10]="";
main(){
	char word[20];
	scanf("%s",word);
	//gets(word);
	//rotateLeft(word);
	//printf("%s",word);
	print_permutation(word);
}
void rotateLeft(char *wordRa){
	int length,i;
	char ch;
	length=strlen(wordRa);
	ch=wordRa[0];
	for(i=1;i<length;i++){
		wordRa[i-1]=wordRa[i];
	}
	wordRa[length-1]=ch;
}
void print_permutation(char *wordRa){
	static count;
	char singleWord[2];
	char aheadWord[10],currentwordRa[10];
	int index,wordRalength,i;
	wordRalength=strlen(wordRa);
	if(wordRalength>2){
		
		strcpy(currentwordRa,wordRa);
		for(i=0;i<wordRalength;i++){
			singleWord[0]=currentwordRa[0];
			singleWord[1]='\0';
			strcat(toBePrinted,singleWord);
			strcpy(aheadWord,currentwordRa+1);
			print_permutation(aheadWord);
			index=strlen(toBePrinted)-1;
			toBePrinted[index]='\0';
			rotateLeft(currentwordRa);
		}
		
	}else
	{
		//printf("\n%d)TOBEpTelse=%s",++count,toBePrinted);
		printf("\n%s",toBePrinted);
		printf("%s",wordRa);
		//printf("\n%d)TOBEpTelse=%s",++count,toBePrinted);
		printf("\n%s",toBePrinted);
		printf("%c%c",wordRa[1],wordRa[0]);
	}
}
