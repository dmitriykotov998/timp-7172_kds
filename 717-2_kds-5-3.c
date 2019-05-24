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

    void print(TempNode *TmpRoot) {
    if(TmpRoot)
	{
		print(TmpRoot->left);
		print(TmpRoot->right);
		printf("%d ", TmpRoot->value);
		
	}
    }
    
    int main()
    {
      Tree *tree = (Tree*)malloc(sizeof(TempNode));
      init(tree);
      for(int i = 0; i < 7; i++)
      {
        int a; scanf("%d",&a);
        insert(tree,a);
      }
      print(tree->root);
      printf("\n");
    }
