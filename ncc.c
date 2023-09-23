#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"ncc_lex.h"
#include"ncc_lex.c"

int main(void)
{
	char Buffer[0x1000];
	FILE* File = fopen("ncc.c", "r");
	fread(Buffer, sizeof(Buffer), 1, File);
	ncc_lexer Lexer = ncc_lexer_create(Buffer, sizeof(Buffer));

	return 0;
}
