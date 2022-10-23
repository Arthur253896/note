#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	int data;
	struct node *left;
	struct node *right;
}Node;

typedef struct tree {
	Node *root;
}Tree;

void create_tree(Tree *tree, int val)
{
	Node *node = (Node*)malloc(sizeof(Node));  //定义一个节点，将数放到节点中
	node->data = val;
	node->left = NULL;
	node->right = NULL;
	
	if (tree->root == NULL) {
		tree->root = node;   //如果根为空，就将这个节点放到根节点
	}
	else {
		Node *temp = tree->root;  //定义指针指向根节点
		while (temp != NULL) {
			if (val < temp->data) {  //如果要放入的值小于根节点
				if (temp->left == NULL) {  //根节点左孩为空，就直接放入
					temp->left = node;
					return;
				}
				else {
					temp = temp->left;  //根节点左孩不为空，就指向下一个左孩节点
				}
			}
			else {
				if (temp->right == NULL) { //右孩为空，直接放入
					temp->right = node;
					return;
				}
				else {
					temp = temp->right;  //右孩不为空，指向下一个右孩节点
				}
			}
		}
	}
}
void inorder(Node *node)
{
	if (node != NULL) {
		inorder(node->left);
		printf("%d\t",node->data);
		inorder(node->right);
	}
}
void delete(int x){
	
}
int main(int argc, char **argv)
{
	int a[10] = {7,4,5,6,1,8,9,32,43,12};
	int b[15] = {1,3,5,7,11,13,17,19,23,29,31,37,39,41,51};
	int c[11] = {2,4,6,8,10,12,14,16,18,20,22};
	Tree tree1,tree2,tree3;
	tree1.root = NULL;
	tree2.root = NULL;
	tree3.root = NULL;
	int i;
	int len1 = sizeof(a) / sizeof(int);
	for (i=0; i<len1; i++) {
		create_tree(&tree1, a[i]);
	}
	int len2 = sizeof(b) / sizeof(int);
	for (i=0; i<len2; i++) {
		create_tree(&tree2, b[i]);
	}
	int len3 = sizeof(c) / sizeof(int);
	for (i=0; i<len3; i++) {
		create_tree(&tree3, c[i]);
	}
	printf("测试用例1:\n");
	inorder(tree1.root);
	printf("\n");
	printf("测试用例2:\n");
	inorder(tree2.root);
	printf("\n");
	printf("测试用例3:\n");
	inorder(tree3.root);
	return 0;
}