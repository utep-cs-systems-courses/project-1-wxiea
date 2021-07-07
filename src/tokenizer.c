#include "tokenizer.h"
#include "string.h"
#include <stdio.h>

#define NULL 0

/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c)
{
  if (c == '\t' ||c == ' ')

    {

      return 1;

    }
  return 0;
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */
int non_space_char(char c)
{
  if (c != '\t' && c != ' ')

    {

      return 1;

    }
  return 0;
}

/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   str does not contain any words. */
char word_start(char *str)
{
  int index = 0;
  int space = 0;

  while (str[index] != '\0')

    {

      if (space == 0)

	{

	  if (str[index] == ' ')

	    {

	      space = 1;

	    }

	}

      else

	{

	  if (str[index] != ' ')

	    {

	      return str[index];

	    }

	}

      index++;

    }
  return '\0';
}

/* Returns a pointer terminator char following *word */
char* word_terminator(char* word)
{
  int index = 0;

  while (word[index] != '\0')

    {

      index++;

    }
  return &word[index];
}

/* Counts the number of words in the string argument. */
int count_words(char* str)
{
  int index = 0;
  int word = 0;
  int count = 0;

  while (1)

    {

      if (0 == word)

	{

	  while (str[index] != '\0' && str[index] == ' ')

	    {

	      index++;

	    }



	  if (str[index] != '\0')

	    {

	      word = 1;

	      count++;

	    }

	  else

	    {

	      if (str[index - 1] != ' ')

		{

		  count++;

		}

	      return count;

	    }

	}

      else

	{

	  while (str[index] != '\0' && str[index] != ' ')

	    {

	      index++;

	    }





	  if (str[index] == '\0')

	    {

	      return count;

	    }

	  word = 0;

	}

    }
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char* copy_str(char* inStr, short len)
{
  char* buffer = malloc(sizeof(char) * len + 1);
  int index = 0;

  while (index < len)

    {

      buffer[index] = inStr[index];

      index++;

    }
  buffer[index] = '\0';
  return buffer;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char** tokenize(char* str)
{
  int wordStart = 0;
  int wordStartFlag = 0;
  int wordLen = 0;
  int wordIndex = 0;
  int count = count_words(str);
  int index = 0;
  char** tokens = malloc(sizeof(char*) * count + 1);
  tokens[count] = NULL;


  while (str[index] != '\0')

    {

      if (non_space_char(str[index]) > 0)

	{

	  if (wordStartFlag == 0)

	    {

	      wordStartFlag = 1;

	      wordStart = index;

	      wordLen = 0;

	    }

	  wordLen++;

	}



      if (space_char(str[index]) > 0)

	{



	  if (wordStartFlag == 1)

	    {



	      wordStartFlag = 0;



	      tokens[wordIndex++] = copy_str(&str[wordStart], wordLen);



	      wordStart = 0;

	      wordLen = 0;

	    }

	}

      index++;

    }

  if (wordStartFlag == 1)

    {

      tokens[wordIndex++] = copy_str(&str[wordStart], wordLen);

    }

  return tokens;
}

/* Prints all tokens. */
void print_tokens(char** tokens)
{
  int index = 0;

  while (tokens[index] != NULL)

    {

      printf("%s\n", tokens[index]);

      index++;

    }
  free(tokens);
}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char** tokens)
{
  int index = 0;

  while (tokens[index] != NULL)

    {

      free(tokens[index]);

      tokens[index] = NULL;

      index++;

    }
  free(*tokens);
}
