#include "analyzer_args.h"
#include "methods.h"

int letter(char c)
{
	if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return IDENTIFIER;
	else
		return 0;
}

int number(char c)
{
	if(c >= '0' && c <= '9')
		return IDENTIFIER;
	else
		return 0;
}

int cat_identifier(char s[])
{
	if(strcmp(s, "void") == 0)
		return VOID;
	else if(strcmp(s, "float") == 0)
		return FLOAT;
	else if(strcmp(s, "double") == 0)
		return DOUBLE;
	else if(strcmp(s, "if") == 0)
		return IF;
	else if(strcmp(s, "else") == 0)
		return ELSE;
	else if(strcmp(s, "for") == 0)
		return FOR;
	else if(strcmp(s, "do") == 0)
		return DO;
	else if(strcmp(s, "while") == 0)
		return WHILE;
	else if(strcmp(s, "return") == 0)
		return RETURN;
	else if(strcmp(s, "break") == 0)
		return BREAK;
	else
		return IDENTIFIER;
}

int cat_singleChar(char c)
{
	if(c == ';')
		return SEMICOLON;
	else if(c == ',')
		return COMMA;
	else if(c == '(')
		return L_PTS;
	else if(c == ')')
		return R_PTS;
	else if(c == '[')
		return L_BRACKET;
	else if(c == ']')
		return R_BRACKET;
	else if(c == '{')
		return L_BRACE;
	else if(c == '}')
		return R_BRACE;
	else if(c == '%')
		return IDIV;
	else
		return 0;
}

int cat_doubleChar_first(char c)
{
	if(c == '>')
		return GT;
	else if(c == '<')
		return LT;
	else if(c == '=')
		return MOV;
	else if(c == '!')
		return NOT;
	else if(c == '/')
		return DIV;
	else if(c == '+')
		return ADD;
	else if(c == '-')
		return MIN;
	else if(c == '*')
		return MUL;
	else if(c == '&')
		return AADD;
	else if(c == '|')
		return COL;
	else
		return 0;
}

int cat_doubleChar(int sign, char c)
{
	if(sign == GT)
	{
		if(c == '=')
			return GE;
		else if(c == '>')
			return RMOV;
		else
			return 0;
	}
	else if(sign == LT)
	{
		if(c == '=')
			return LE;
		else if(c == '<')
			return LMOV;
		else
			return 0;
	}
	else if(sign == MOV)
	{
		if(c == '=')
			return EQU;
		else
			return 0;
	}
	else if(sign == NOT)
	{
		if(c == '=')
			return NE;
		else
			return 0;
	}
	else if(sign == ADD)
	{
		if(c == '=')
			return AADD;
		else if(c == '+')
			return SADD;
		else
			return 0;
	}
	else if(sign == MIN)
	{
		if(c == '=')
			return AMIN;
		else if(c == '-')
			return SMIN;
		else
		return 0;
	}
	else if(sign == MUL)
	{
		if(c == '=')
			return AMUL;
		else if(c == '/')
			return NOTE_END;
		else
			return 0;
	}
	else if(sign == DIV)
	{
		if(c == '=')
			return ADIV;
		else if(c == '*')
			return NOTE_START;
		else if(c == '/')
			return NOTE;
		else
			return 0;
	}
	else if(sign == SAND)
	{
		if(c == '&')
			return AND;
		else
			return 0;
	}
	else if(sign == COL)
	{
		if(c == '|')
			return OR;
		else
			return 0;
	}
	else
	{
		return 0;
	}
}

void write_doubleChar(int sign, FILE* fw)
{
	if(sign == GT)
		fprintf(fw, "(%d, %c)\n", GT, ">=");
	else if(sign == LT)
		fprintf(fw, "(%d, %c)", LT, "<=");
	else if(sign == NE)
		fprintf(fw, "(%d, %c)\n", NE, "!=");
	else if(sign == EQU)
		fprintf(fw, "(%d, %c)\n", EQU, "==");
	else if(sign == SADD)
		fprintf(fw, "(%d, %c)\n", SADD, "++");
	else if(sign == SMIN)
		fprintf(fw, "(%d, %c)\n", SMIN, "--");
	else if(sign == AADD)
		fprintf(fw, "(%d, %c)\n", AADD, "+=");
	else if(sign == AMIN)
		fprintf(fw, "(%d, %c)\n", AMIN, "-=");
	else if(sign == AMUL)
		fprintf(fw, "(%d, %c)\n", AMUL, "*=");
	else if(sign == ADIV)
		fprintf(fw, "(%d, %c)\n", ADIV, "/=");
	else if(sign == LMOV)
		fprintf(fw, "(%d, %c)\n", LMOV, "<<");
	else if(sign == RMOV)
		fprintf(fw, "(%d, %c)\n", RMOV, ">>");
	else if(sign == AND)
		fprintf(fw, "(%d, %c)\n", AND, "&&");
	else if(sign == OR)
		fprintf(fw, "(%d, %c)\n", OR, "||");
	else if(sign == NOTE)
		fprintf(fw, "(%d, %c)\n", NOTE, "//");
	else if(sign == NOTE_START)
		fprintf(fw, "(%d, %c)\n", NOTE_START, "/*");
	else if(sign == NOTE_END)
		fprintf(fw, "(%d, %c)\n", NOTE_END, "*/");
	else
		return;
}

int analyzer(FILE* fp, FILE* fw)
{
	char c;
	int note_flag = 0;
	int line_note_flag = 0;
	c = fgetc(fp);

	while(!feof(fp))
	{
		if(note_flag == 1)
		{
			while(1)
			{
				if(cat_doubleChar(cat_doubleChar_first(c), fgetc(fp)) == NOTE_END)
				{
					note_flag = 0;
					break;
				}
				c = fgetc(fp);
			}
			c = fgetc(fp);
		}
		if(line_note_flag == 1)
		{
			while(1)
			{
				if(c == '\n')
				{
					line_note_flag = 0;
					break;
				}
				c = fgetc(fp);
			}
			c = fgetc(fp);
		}

		if(c == ' ' || c == '\t')
		{
			c = fgetc(fp);
			continue;
		}

		else if(c == '\n')
		{
			fprintf(fw, "\n");
			c = fgetc(fp);
			continue;
		}

		else if(letter(c) == IDENTIFIER)
		{
			char string[64];
			int i = 0;
			string[i++] = c;
			do
			{
				c = fgetc(fp);
				string[i++] = c;
			} while (letter(c) == IDENTIFIER || number(c) == IDENTIFIER);
			string[i - 1] = '\0';
			int cat = cat_identifier(string);
			fprintf(fw, "(%d, %s)\n", cat, string);
		}

		else if(number(c) == IDENTIFIER)
		{
			char string[64];
			int i = 0;
			string[i++] = c;
			do
			{
				c = fgetc(fp);
				string[i++] = c;
			} while (number(c) == IDENTIFIER);
			string[i - 1] = '\0';
			fprintf(fw, "(%d, %c)\n", UNSIGNED_INT, string);
		}

		else if(cat_singleChar(c) != 0)
		{
			fprintf(fw, "(%d, %c)\n", cat_singleChar(c), c);
			c = fgetc(fp);
		}

		else if(cat_doubleChar_first(c) != 0)
		{
			int sign = cat_doubleChar(cat_doubleChar_first(c), fgetc(fp));
			if(sign == NOTE_START)
				note_flag = 1;
			if(sign == NOTE)
				line_note_flag = 1;
			write_doubleChar(sign, fw);
		}
		
		else
			fprintf(fw, "error, unrecognized symbol!\n");
			printf("error, unrecognized symbol!\n");
			break;
	}
}