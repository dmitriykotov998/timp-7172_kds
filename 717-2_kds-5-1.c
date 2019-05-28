#include <stdio.h>
#include <stdlib.h>

typedef struct TempNode
{
	int value;
	struct TempNode *left;
	struct TempNode *right;
	struct TempNode *parent;
} TempNode;

typedef struct tree
{
	struct TempNode *root;
	int count;
} Tree;

typedef struct listTempNode
{
	TempNode *Gig_node_tree;
	struct listTempNode *next;
}TaskList;

typedef struct list
{
	TaskList *first;
	TaskList *last;
}List;

void createlist(List *r_);

int input(List *r_, TempNode *n);

void clearlist(List  *r_);
void init(Tree *tree) ;

void clear(Tree *tree);

int insert(Tree *tree, int value) ;

int RemoveMin(TempNode *n, Tree *t) ;

TempNode *search(TempNode *node, int value);

TempNode *min(TempNode *root) ;

int findTempNode(Tree *tree, int value, TempNode **node) ;


int turnLeft(Tree* tree); 

int turnRight(Tree *tree) ;

void print(TempNode* node);

void printTree(Tree *tree) ;

TempNode* _Remove(TempNode* tree, int value);

int Remove(Tree *tree, int value) ;
int CoutParentandSon(int m,Tree * tree);
int main() {
	Tree *tree = (Tree*)malloc(sizeof(TempNode));
	init(tree);

	int a[7];
	scanf("%d%d%d%d%d%d%d", &a[0], &a[1], &a[2], &a[3] ,&a[4],&a[5],&a[6]);
		insert(tree, a[0]);
		insert(tree, a[1]);
		insert(tree, a[2]);
		insert(tree, a[3]);
		insert(tree, a[4]);
		insert(tree, a[5]);
		insert(tree, a[6]);
	print(tree->root);
        printf("\n");
}

void createlist(List *r_)
{
	r_->first = NULL;
	r_->last = NULL;
}

int input(List *r_, TempNode *n)
{
	TaskList *newList = (TaskList*)malloc(sizeof(TaskList));
	newList->Gig_node_tree = n;
	newList->next = NULL;
	if (r_->first)
		r_->last->next = newList;
	else
		r_->first = newList;
	r_->last = newList;
	return 0;
}
void clearlist(List  *r_)
{
	TaskList *TmpParam, *nr_;
	TmpParam = r_->first;
	do
	{
		nr_ = TmpParam;
		TmpParam = TmpParam->next;
		free(nr_);
	} while (TmpParam);
	r_->first = NULL;
	r_->last = NULL;
}
void init(Tree *tree) { 

	tree->root = NULL;
}
void clear(Tree *tree) { 
	while (tree->root != NULL)
		RemoveMin(tree->root, tree);
}
int insert(Tree *tree, int value) { 
	TempNode *TmpParam = (TempNode*)malloc(sizeof(TempNode));

	TmpParam->value = value;


	if (tree->root == NULL) {
		TmpParam->left = TmpParam->right = NULL;
		TmpParam->parent = NULL;
		tree->root = TmpParam;
		tree->count = 1;
		return 0;
	}

	if (TmpParam->value == tree->root->value)
		return -1;

	TempNode *TmpRoot = (TempNode*)malloc(sizeof(TempNode)), *root3 = NULL;

	TmpRoot = tree->root;

	while (TmpRoot != NULL)
	{
		root3 = TmpRoot;
		if (value < TmpRoot->value)
			TmpRoot = TmpRoot->left;
		else
			TmpRoot = TmpRoot->right;
	}

	if (TmpParam->value == root3->value) {
		return -1;
	}

	TmpParam->parent = root3;
	TmpParam->left = NULL;
	TmpParam->right = NULL;

	if (value < root3->value)
		root3->left = TmpParam;
	else
		root3->right = TmpParam;
	tree->count++;
	return 0;
}
int RemoveMin(TempNode *n, Tree *t) {
	t->count--;

	if (t->count != 1) {

		while (n->left != NULL)
			n = n->left;

		if (n->right != NULL) {
			n->right->parent = n->parent;

			if (n == t->root)
				t->root = n->right;
			else
				n->parent->left = n->right;
		}
		else
			n->parent->left = NULL;

		int value = n->value;
		free(n);

		return value;
	}
	else {
		t->root = NULL;
		t->count = 0;
		free(t->root);

		return 0;
	}
}

void print(TempNode* node)
{
	if (node)
	{
		List ListTmp, List_;
		List *GigListTmp = &ListTmp;
		List *GigList_ = &List_;
		createlist(GigListTmp);
		createlist(GigList_);
		TempNode *TmpParam = NULL;
		TaskList*r_ = NULL;
		int c = 0, val = node->value, j = 0;
		TempNode *l = node->left;
		TempNode *r = node->right;
		input(GigListTmp, node);
		while (1)
		{
			while (GigListTmp->first)
			{
				if (GigListTmp->first)
	{
		TaskList *nodelist_pop;
		TmpParam = GigListTmp->first->Gig_node_tree;
		nodelist_pop = GigListTmp->first;
		GigListTmp->first = GigListTmp->first->next;
		if (GigListTmp->first == NULL)
			GigListTmp->last = NULL;
		free(nodelist_pop);
	}
	else
		TmpParam = NULL;
				if (GigListTmp->first == NULL)
				{

						printf("%d ", TmpParam->value);
				}
				else
					printf("%d ", TmpParam->value);
				if (TmpParam->left)
					input(GigList_, TmpParam->left);
				else
					input(GigList_, node);
				if (TmpParam->right)
					input(GigList_, TmpParam->right);
				else
					input(GigList_, node);

			}
			node->left = node->right = NULL;
			c = 1;
			r_ = GigList_->first;
			while (GigList_->first->Gig_node_tree->value == val)
			{
				GigList_->first = GigList_->first->next;
				if (GigList_->first->next == NULL)
					if (GigList_->first->Gig_node_tree->value == val)
					{
						j = 1;
						node->left = l;
						node->right = r;
						clearlist(GigList_);
						break;
					}
			}
			GigList_->first = r_;
			if (j == 1)
				break;
			GigListTmp->first = GigList_->first;
			GigListTmp->last = GigList_->last;
			GigList_->first = NULL;
			GigList_->last = NULL;
		}
	}
	else
		printf("-\n");
}

void printTree(Tree *tree) {
	print(tree->root);
	
}
