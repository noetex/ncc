static ncc_lexer
ncc_lexer_create(char* Buffer, size_t Length)
{
	ncc_lexer Result = {0};
	Result.Buffer = Buffer;
	Result.BufferLength = Length;
	//Result.CurrentLineNumber = 1;
	//Result.Curren
	return Result;
}

static void
ncc_lexer_skip_whitespaces(ncc_lexer* Lexer)
{
	for(;;)
	{
		char Character = Lexer->Buffer[Lexer->CurrentBufferOffset];
//		if(is_whitespace(Character))
//		{
//			Lexer->CurrentBufferOffset += 1;
//		}
	}
}

//static void
//ncc_lexer_skip_comment

static ncc_token
ncc_lexer_get_token(ncc_lexer* Lexer)
{
	ncc_token Result = {0};
	ncc_lexer_skip_whitespaces(Lexer);
	//switch(Lexer->Buffer[])
	if(Lexer->CurrentBufferOffset >= Lexer->BufferLength)
	{

	}
	Result.Begin = &Lexer->Buffer[Lexer->CurrentBufferOffset];
	Result.Location.LineNumber = Lexer->CurrentLineNumber;
	Result.Location.LineOffset = Lexer->CurrentLineOffset;
	return Result;
}
