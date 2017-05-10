#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 81

typedef struct Tree
{
	char key;
	int counter;
	struct Tree *left, *right;
} Tree;

void AddNode(Tree**, char);
void ShowElements(Tree*);
int CountNodes(Tree*);
Tree *SearchKey(Tree*, char);

int main()
{
	Tree *root = NULL, *sym;
	char *p;
	char s[MAX_LEN];
	printf("Enter your word: ");
	gets (s);
	printf("Enter the symbol you would like to find: ");
	char c = getchar();
	for(p = s; *p; ++p)
	{
		AddNode(&root, *p);
	}
	printf("In ascending order of unicode: ");
	ShowElements(root);
	printf("\n");
	if (sym = SearchKey(root, c))
	{
	   printf("Nodes in the left subtree: %d\n", CountNodes(sym->left));
	   printf("Nodes in the right subtree: %d\n", CountNodes(sym->right));
	}
	getch();
	return 0;
}

void AddNode(Tree **sym, char x)
{
	if (*sym == NULL)
	{
	   *sym = (Tree *)malloc(sizeof(Tree));
	   (*sym)->key = x;
	   (*sym)->counter = 1;
	   (*sym)->left = (*sym)->right = NULL;
	}
	else
	{
		if ((*sym)->key == x)
		{
			((*sym)->counter)++;
		}
		else
		{
			if ((*sym)->key > x)
			{
				AddNode(&((*sym)->left), x);
			}
			else
			{
				AddNode(&((*sym)->right), x);
			}
		}
	}
}

void ShowElements(Tree *sym)
{
	if (sym != NULL)
	{
	  ShowElements(sym->left);
	  printf("%c ", sym->key, sym->counter);
	  ShowElements(sym->right);
	}
}

int CountNodes(Tree *sym)
{
	if (sym == NULL)
	{
		return 0;
	}
	else
	{
	   return 1 + CountNodes(sym->left) + CountNodes(sym->right);
	}
}

Tree *SearchKey(Tree *sym, char x)
{
	if (sym == NULL)
	{
	  return NULL;
	}
	else
	{
		if (sym->key == x)
		{
			return sym;
		}
		else
		{
			if (sym->key > x)
			{
				return SearchKey(sym->left, x);
			}
			else
			{
				return SearchKey(sym->right, x);
			}
		}
	}
}
