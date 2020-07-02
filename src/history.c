#include "history.h"
#include "string.h"
#include <stdio.h>

#define NULL 0

/* Initialize the linked list to keep the history. */
List* init_history()
{
  List* list = (List*)malloc(sizeof(List));
  list->root = NULL;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List* list, char* str)
{
  Item* preNode = NULL;
  Item* curNode = NULL;
  char* buffer = NULL;
  Item* node = NULL;
  int id = 1;

  buffer = malloc(sizeof(char) * strlen(str) + 1);
  strcpy(buffer, str);
  node = malloc(sizeof(Item));
  node->next = NULL;
  node->str = buffer;

  if (list->root == NULL)

    {
      node->id = id;
      list->root = node;
      return;

    }

  curNode = list->root;
  preNode = curNode;

  while (curNode != NULL)

    {

      id++;

      preNode = curNode;

      curNode = curNode->next;

    }

  node->id = id;
  preNode->next = node;
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char* get_history(List* list, int id)
{
  Item* root = list->root;

  while (root != NULL)

    {

      if (root->id == id)

	{

	  return root->str;

	}

      root = root->next;

    }

  return NULL;
}

/*Print the entire contents of the list. */
void print_history(List * list)
{
  Item* root = list->root;

  while (root != NULL)

    {

      printf("id = %d string:%s", root->id, root->str);

      root = root->next;

    }
}

/*Free the history list and the strings it references. */
void free_history(List * list)
{

  Item* node = NULL;
  Item* preNode = NULL;

  if (list == NULL)

    {

      return;

    }

  if (list->root == NULL)

    {

      return;

    }

  node = list->root;

  while (node != NULL)

    {

      if (node->str != NULL)

	{

	  free(node->str);

	  node->str = NULL;

	}

      preNode = node;

      node = node->next;

      free(preNode);

      preNode = NULL;

    }


  free(list);
}
