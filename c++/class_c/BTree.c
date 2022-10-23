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
	Node *node = (Node*)malloc(sizeof(Node));  //����һ���ڵ㣬�����ŵ��ڵ���
	node->data = val;
	node->left = NULL;
	node->right = NULL;
	
	if (tree->root == NULL) {
		tree->root = node;   //�����Ϊ�գ��ͽ�����ڵ�ŵ����ڵ�
	}
	else {
		Node *temp = tree->root;  //����ָ��ָ����ڵ�
		while (temp != NULL) {
			if (val < temp->data) {  //���Ҫ�����ֵС�ڸ��ڵ�
				if (temp->left == NULL) {  //���ڵ���Ϊ�գ���ֱ�ӷ���
					temp->left = node;
					return;
				}
				else {
					temp = temp->left;  //���ڵ��󺢲�Ϊ�գ���ָ����һ���󺢽ڵ�
				}
			}
			else {
				if (temp->right == NULL) { //�Һ�Ϊ�գ�ֱ�ӷ���
					temp->right = node;
					return;
				}
				else {
					temp = temp->right;  //�Һ���Ϊ�գ�ָ����һ���Һ��ڵ�
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
	printf("��������1:\n");
	inorder(tree1.root);
	printf("\n");
	printf("��������2:\n");
	inorder(tree2.root);
	printf("\n");
	printf("��������3:\n");
	inorder(tree3.root);
	return 0;
}