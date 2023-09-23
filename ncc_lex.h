typedef enum
{
	TOKEN_TYPE_EOF = 0,
	TOKEN_TYPE_IDENTIFIER,
	TOKEN_TYPE_XOR,
	TOKEN_TYPE_XOREQ,
	TOKEN_TYPE_PLUS,
	TOKEN_TYPE_PLUSEQ,
	TOKEN_TYPE_PLUSPLUS,
	TOKEN_TYPE_MINUS,
	TOKEN_TYPE_MINUSEQ,
	TOKEN_TYPE_MINUSMINUS,
	TOKEN_TYPE_ASTERISK,
	TOKEN_TYPE_ASTERISKEQ,
	TOKEN_TYPE_MODULO,
	TOKEN_TYPE_MODULOEQ,
	TOKEN_TYPE_EQUAL,
	TOKEN_TYPE_EQUAL_EQUAL,
	TOKEN_TYPE_LESS_THAN,
	TOKEN_TYPE_LESS_EQUAL,
	TOKEN_TYPE_GREATER_THAN,
	TOKEN_TYPE_GREATER_EQUAL,
	TOKEN_TYPE_SHIFT_LEFT,
	TOKEN_TYPE_SHIFT_RIGHT,
	TOKEN_TYPE_EQUALEQUAL,
	TOKEN_TYPE_LOGICAL_OR,
	TOKEN_TYPE_LOGICAL_OREQ,
	TOKEN_TYPE_LOGICAL_AND,
	TOKEN_TYPE_LOGICAL_ANDEQ,
	TOKEN_TYPE_LOGICAL_NOT,
	TOKEN_TYPE_BITWISE_OR,
	TOKEN_TYPE_BITWISE_OREQ,
	TOKEN_TYPE_BITWISE_AND,
	TOKEN_TYPE_BITWISE_ANDEQ,
	TOKEN_TYPE_BITWISE_NOT,
	TOKEN_TYPE_CURLY_BRACKET_LEFT,
	TOKEN_TYPE_CURLY_BRACKET_RIGHT,
	TOKEN_TYPE_SQUARE_BRACKET_LEFT,
	TOKEN_TYPE_SQUARE_BRACKET_RIGHT,
	TOKEN_TYPE_PARANTHESIS_LEFT,
	TOKEN_TYPE_PARANTHESIS_RIGHT,
	TOKEN_TYPE_HASH,
	TOKEN_TYPE_BACKSLASH,
	TOKEN_TYPE_FRONTSLASH,
	TOKEN_TYPE_SINGLE_QUOTE,
	TOKEN_TYPE_DOUBLE_QUOTE,
	TOKEN_TYPE_SEMICOLON,
	TOKEN_TYPE_COLON,
	TOKEN_TYPE_COMMA,
	TOKEN_TYPE_DOT,
	TOKEN_TYPE_UNKNOWN = -1,
} token_type;

typedef enum
{
	RETURN_TYPE_VOID,
	RETURN_TYPE_BOOL,
	RETURN_TYPE_FLOAT,
	RETURN_TYPE_DOUBLE,
	RETURN_TYPE_LONGDOUBLE,
	RETURN_TYPE_STRUCT,
	RETURN_TYPE_POINTER,
} return_type;

typedef struct
{
	char* Name;
	return_type ReturnType;
} function_signature;

typedef struct
{
	size_t LineNumber;
	size_t LineOffset;
} token_location;

typedef struct
{
	token_type Type;
	char* Begin;
	size_t Length;
	token_location Location;
} ncc_token;

typedef struct
{
	char* Buffer;
	size_t BufferLength;
	size_t CurrentBufferOffset;
	size_t CurrentLineNumber;
	size_t CurrentLineOffset;
} ncc_lexer;

static char* KEYWORDS_C[] =
{
	"auto", "break", "case", "char", "const",
	"continue", "default", "do", "double",
	"else", "enum", "extern", "float", "for",
	"goto", "if", "int", "long", "register",
	"return", "short", "signed", "sizeof",
	"static", "struct", "switch", "typedef",
	"union", "unsigned", "void", "volatile", "while",
};

static char* KEYWORDS_PREPROCESSOR[] =
{
	"define",
	"defined",
	"elif",
	"else",
	"endif",
	"error",
	"if",
	"pragma",
};
