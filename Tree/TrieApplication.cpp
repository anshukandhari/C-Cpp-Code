#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include "tries.h"

int main()
{
	trie* a;

	char* str=(char*)malloc(10);
	char* key=(char*)malloc(10);
        int ch,res;
        a=init();
       	do
	{
		printf("\n1.Insert into trie\n2.Search for a word in trie\n3.Exit\nEnter choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the word to be inserted\n");
				scanf("%s",str);
				trie_add(a,str);
				break;
			case 2:
				printf("Enter the word to be searched\n");
				scanf("%s",key);
				res=trie_lookup(a,key);
				if(res!=0)
					printf("Word present!\n");
				else
					printf("Word not in trie!\n");
				break;
			case 3:
				printf("Exitting.....\n");
				break;
		}
	}while(ch!=3);
	return 0;
}
