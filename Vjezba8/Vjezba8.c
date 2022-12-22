#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void red() {
    printf("\033[1;31m");
}

void cyan() {
    printf("\033[0;36m");
}

void white() {
    printf("\033[0;37m");
}
void yellow() {
	printf("\033[0;33m");
}
void green() {
	printf("\033[0;32m");
}
struct Btree;
typedef struct Btree *Position;
typedef struct Btree {
    int data;
	Position left;
	Position right;
};

Position MakeRoot(Position);
Position InsertElement(Position, Position);
int CreatNode(int);
int InOrderPrint(Position);
int PostOrderPrint(Position);
int PreOrderPrint(Position);
int LevelOrderPrint (Position);
int height(Position);
void CurrentLevel(Position, int);
Position DeleteElement(int, Position);
Position FindMin(Position);
Position FindMax(Position);
Position FindElement(int, Position);
int Example();

int Smile(int);


int main()
{
    int x = 1;
    char y = { 0 };
	int newEl;
	int element;
	int i = NULL;
	int smile;
	int example;
    Position Root = NULL;
	Position New = NULL;
	Position tmp = NULL;
	Root = MakeRoot(Root);
	green();
	printf("\n\t\t\t\t WELCOME TO MY PROGRAM!");
	smile = Smile (i);
	printf("\n");
	example = Example();
	while (x)
	{
	
		printf("\n  \n");
		cyan();
		printf("\t\t    ______________  PLEASE CHOOSE  ______________ \n");
		white();
		printf("\n                ---------------------------------------------------  \n");
	
		red();
		printf("\n             *     PRESS 1:");
		white();
		printf(" ADD NEW ELEMENT                         *");
		red();
		printf("\n             *     PRESS 2:");
		white();
		printf(" INORDER                                 *");
		red();
		printf("\n             *     PRESS 3:");
		white();
		printf(" PREORDER                                *");
		red();
		printf("\n             *     PRESS 4:");
		white();
		printf(" POSTORDER                               *");
		red();
		printf("\n             *     PRESS 5:");
		white();
		printf(" LEVEL ORDER                             *");
		red();
		printf("\n             *     PRESS 6:");
		white();
		printf(" DELETE ELEMENT                          *");
		red();
		printf("\n             *     PRESS 7:");
		white();
		printf(" FIND ELEMENT                            *");
		red();
		printf("\n             *     PRESS 8:");
		white();
		printf(" TO EXIT THE PROGRAM.                    *");
		printf("\n                ___________________________________________________\n");
		printf("\n");
		printf("\t\t\t ->");
		cyan();
		scanf("  %c", &y);
		white();
		switch (y) {

		case '1':

			printf("\n            WHICH ELEMENT YOU WANT INSERT:  ");
			red();
			printf(" ~ ");
			scanf(" %d", &x);
			
			New = CreatNode(x);
			Root = InsertElement(Root, New);
			white();
			printf(" \n\t     Successfully!");
			Smile(i);
			break;

		case '2':
			printf("\tINORDER: \n");
			InOrderPrint(Root);
			printf("\n");
			break;


		case '3':
			printf("\tPREORDER: \n");
			PreOrderPrint(Root);
			printf("\n");
			break;

		case '4':
			printf("\tPOSTORDER: \n");
			PostOrderPrint(Root);
			printf("\n");
            break;

		case '5':
			printf("\tLEVEL ORDER: \n");
			LevelOrderPrint(Root);
			
			break;

		case '6':

			printf("\t WHICH ELEMENT YOU WANT DELETE: ~ ");
			red();
			scanf("\t%d", &element);
			white();
			Root = DeleteElement(element, Root);

			break;

		case '7':
			printf("\n\t\tWHICH ELEMENT YOU WANT FIND: ~ ");
			red();
			scanf("\t%d", &element);
			tmp = FindElement(element, Root);
			if (tmp)
				cyan();
				printf("\n\t\tELEMENT %d SE NALAZI NA ADRESI: ", tmp->data);
				green();
				printf(" %d", tmp);
				white();
			break;

		case '8':
			exit(0);
			break;

		default:
			red();
			printf("\n    I'm sorry, you chose the wrong option.\n");
			white();
			printf("\n   TRY AGAIN!");
			Smile(i);
			break;
		}
	}
	return 0;
}


Position MakeRoot(Position p)
{
    if (p != NULL)
    {
        p->left = MakeRoot(p->left);
        p->right = MakeRoot(p->right);
        free(p);
    }
	return NULL;
}

Position InsertElement(Position p, Position newEl)
{
    if (p == NULL)
    {
        return newEl;
    }

    if (p->data < newEl->data)
    {
        p->right = InsertElement(p->right, newEl);
    }

    else if (p->data > newEl->data)
    {
        p->left = InsertElement(p->left, newEl);
    }
    
    else
    {
		red();
		printf("\tNumber already exists in tree!\n");
		free(newEl);
    }
	return p;
}

int CreatNode(int x)
{
	Position newEl = (Position)malloc(sizeof(struct Btree));
	if (newEl==NULL)
	{
		printf("\t\t\n  Can not allocate memory!\n");
		return newEl;
	}
	newEl->data = x;
	newEl->left = NULL;
	newEl->right = NULL;
	return newEl;

}

int InOrderPrint(Position root)
{
	if (root == NULL)
	{
		return 0;
	}

		InOrderPrint(root->left);
		green();
	    printf("%d\t", root->data);
		InOrderPrint(root->right);
	

}


int PostOrderPrint(Position root)
{
	if (root == NULL)
	{
		return 0;
	}
	
		PostOrderPrint(root->left);

		PostOrderPrint(root->right);
		green();
		printf("%d\t ", root->data);

}


int PreOrderPrint (Position root)
{
	if (root == NULL)
	{
		return 0;
	}
	    green();
		printf("%d\t", root->data);
        PreOrderPrint(root->left);
		PreOrderPrint(root->right);


}

int LevelOrderPrint(Position root)
{
	int h = height(root);
	int i;
	for (i = 1; i <= h; i++) {
		CurrentLevel(root, i);
		printf("\n");
	}	
}



int height(Position node)
{
	if (node == NULL)
	{
		return 0;
	}
	else 
	{
		int lheight = height(node->left);
		int rheight = height(node->right);
		if (lheight > rheight)
			return (lheight + 1);
		else return (rheight + 1);
	}
}

void CurrentLevel(Position root, int level)
{
	if (root == NULL)
	{
		return;
	}

	if (level == 1)
	
	{
		green();
		printf(" ( %d ) ", root->data);
		
	}

	else if (level > 1)
	{
		CurrentLevel(root->left, level - 1);
		CurrentLevel(root->right, level - 1);
	
	}
	
}

int Smile (int i)
	{
		for (i = 0; i <= 0; i++)
		{
			yellow();
			printf("  %c", 1);
		}
		return 0;
	}

Position DeleteElement(int element, Position Root)
{
	Position temp;
	if (!Root)
		return Root;
	else if (element < Root->data)
		Root->left = DeleteElement(element, Root->left);
	else if (element > Root->data)
		Root->right = DeleteElement(element, Root->right);
	else
	{
		if (Root->left && Root->right)
		{
			temp = FindMin(Root->right);
			Root->data = temp->data;
			Root->right = DeleteElement(temp->data, Root->right);
		}
		else
		{
			temp = Root;
			if (!Root->left)
				Root = Root->right;
			else if (!Root->right)
				Root = Root->left;
			free(temp);
		}
	}
	return Root;
}

Position FindMin(Position root)
{
	if (root == NULL)
	{
		printf("Tree is empty!\n");
		return NULL;
	}

	while (root->left != NULL)
	{
		root = root->left;
	}

	return root;
}

Position FindMax(Position root)
{
	if (root == NULL)
	{
		printf("Tree is empty!\n");
		return NULL;
	}

	while (root->right != NULL)
	{
		root = root->right;
	}

	return root;
}

Position FindElement(int element, Position root)
{
	if (!root)
		return root;
	else if (element < root->data)
		return FindElement(element, root->left);
	else if (element > root->data)
		return FindElement(element, root->right);
	else
		return root;
}

int Example ()
{
	int i;
cyan();
printf("\t*For easier tracking, you can use our binary tree example.\n");
yellow();
printf("\t                                                         ENJOY!\n");
red();
printf("\t            ______(%d)_____\n", 4);
white();
printf("\t           /              \\ \n");
cyan();
printf("\t      __(%d)__           __(%d)__\n", 2, 6);
white();
printf("\t     /       \\         /       \\ \n");
yellow();
printf("\t   (%d)       (%d)      (%d)      (%d)\n ", 1, 3, 5, 7);
white();
printf("\t  /   \\     /   \\    /   \\    /   \\ \n");
green();
printf("\t ( ) ( )   ( ) ( )  ( ) ( )  ( ) (%d)\n", 20);
white();
return;

}