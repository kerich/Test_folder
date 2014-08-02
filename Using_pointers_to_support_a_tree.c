#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _tree {
	void *data;
	struct _tree *left;
	struct _tree *right;
} TreeNode;

typedef struct _employee{
	char name[32];
	unsigned int age;
}Employee;

int compareEmployee(Employee *e1, Employee *e2);
int compareEmployee(Employee *e1, Employee *e2) {
	return strcmp(e1->name, e2->name);
}

typedef int (*COMPARE) (void*, void*);

void insertNode(TreeNode **root, COMPARE compare, void* data);
void insertNode(TreeNode **root, COMPARE compare, void* data) {
	TreeNode *node = (TreeNode*) malloc(sizeof(TreeNode));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	if(*root == NULL) {
		*root = node;
		return;
	}

	while(1) {
		if(compare((*root)->data, data) > 0) {
			if((*root)->left != NULL) {
				*root = (*root)->left;
			} else {
				(*root)->left = node;
				break;
			}
		} else {
			if((*root)->right != NULL) {
				*root = (*root)->right;
			} else {
				(*root)->right = node;
				break;
			}
		}
	}
}

// another insert Node method
/*
void insertNode(TreeNode **realroot, COMPARE compare, void* data);
void insertNode(TreeNode **realroot, COMPARE compare, void* data) {
    TreeNode *node = (TreeNode*) malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    TreeNode *root = *realroot;

    if(root == NULL) {
        *realroot = node;
        return;
    }

    while(1) {
        if(compare((root)->data, data) > 0) {
            if((root)->left != NULL) {
                root = (root)->left;
            } else {
                (root)->left = node;
                break;
            }
        } else {
            if((root)->right != NULL) {
                root = (root)->right;
            } else {
                (root)->right = node;
                break;
            }
        }
    }
}
*/

typedef void (*DISPLAY) (void*);

void displayEmployee(Employee* employee);
void displayEmployee(Employee* employee){
	printf("%s\t%d\n", employee->name, employee->age);
}


void preOrder(TreeNode *root, DISPLAY display);
void preOrder(TreeNode *root, DISPLAY display) {
	if(root != NULL){
		display(root->data);
		preOrder(root->left, display);
		preOrder(root->right, display);
	}
}

void inOrder(TreeNode *root, DISPLAY display);
void inOrder(TreeNode *root, DISPLAY display) {
    if(root != NULL){
		inOrder(root->left, display);
                display(root->data);
                inOrder(root->right, display);
    }
}

void postOrder(TreeNode *root, DISPLAY display);
void postOrder(TreeNode *root, DISPLAY display) {
	if(root != NULL) {
		postOrder(root->left, display);
		postOrder(root->right, display);
                display(root->data);
	}
}

int main(void) {

	TreeNode *tree = NULL;
	
	Employee *samuel = (Employee*) malloc(sizeof(Employee));
	strcpy(samuel->name, "Samuel");
	samuel->age = 32;

	Employee *sally = (Employee*) malloc(sizeof(Employee));
	strcpy(sally->name, "Sally");
	sally->age = 28;

	Employee *susan = (Employee*) malloc(sizeof(Employee));
	strcpy(susan->name, "Susan");
	susan->age = 45;

	insertNode(&tree, (COMPARE) compareEmployee, samuel);
	insertNode(&tree, (COMPARE) compareEmployee, sally);
	insertNode(&tree, (COMPARE) compareEmployee, susan);

	printf("pre-Order:\n");
        preOrder(tree, (DISPLAY) displayEmployee);
	printf("in-Order:\n");
        inOrder(tree, (DISPLAY) displayEmployee);
	printf("post-Order:\n");
	postOrder(tree, (DISPLAY) displayEmployee);

	return 0;
}
