#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <string>
#include <stdio.h>

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* root;

struct Node* CreateTree(struct Node* root, int data) {

	if (root == NULL) {
		root = (struct Node*)malloc(sizeof(struct Node));
		root->data = data;
		root->left = root->right = NULL;
		return root;
	}

	if (data < root->data) {
		root->left = CreateTree(root->left, data);
	}
	else {
		root->right = CreateTree(root->right, data);
	}

	return root;
}

void print_tree(struct Node* r, int l)
{
	if (r == NULL)
	{
		return;
	}
	print_tree(r->right, l + 1);
	for (int i = 0; i < l; i++)
	{
		printf(" ");
	}
	printf("%d\n", r->data);
	print_tree(r->left, l + 1);
}

struct Node* search(struct Node* root, int key) {
	if (root == NULL)
		return NULL;

	if (root == NULL || root->data == key)
		return root;

	if (key < root->data)
		return search(root->left, key);
	else
		return search(root->right, key);

	return NULL;
}

int countOccurrences(struct Node* root, int data) {
	if (root == NULL) return 0;
	if (root->data == data) return 1 + countOccurrences(root->left, data) + countOccurrences(root->right, data);

	return countOccurrences(root->left, data) + countOccurrences(root->right, data);
}

int main()
{
	setlocale(LC_ALL, "");
	int D, start = 1;
	root = NULL;
	printf("-1 - окончание построения дерева\n");

	while (start)
	{
		printf("Введите число: ");
		scanf_s("%d", &D);
		if (D == -1)
		{
			printf("Построение дерева окончено\n\n");
			start = 0;
		}
		else
			root = CreateTree(root, D);
	}

	print_tree(root, 0);
	
	int key;
	printf("Введите ключ для поиска: ");
	scanf("%d", &key);
	
	struct Node* found = search(root, key);

	if (found == NULL) {
		printf("Ключ к сожалению не найден\n");
	}
	else {
		printf("Ключ найден!\n");
	}
	
	int searchKey;
	printf("Введите ключ для поиска количества вхождений: ");
	scanf("%d", &searchKey);
	int count = countOccurrences(root, searchKey);
	printf("Количество вхождений элемента %d в дереве: %d", searchKey, count);

	return 0;
}

//УЧАСТОК КОДА ДЛЯ 3 ПУНКТА
/*
struct Node* search(struct Node* root, int key) {
	if (root == NULL || root->data == key)
		return root;

	if (key < root->data)
		return search(root->left, key);
	else
		return search(root->right, key);
}

struct Node* CreateTree(struct Node* root, int data) {

	if (search(root, data) != NULL)
		return root;

	if (root == NULL) {
		struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->data = data;
		newNode->left = newNode->right = NULL;
		return newNode;
	}

	if (data < root->data) {
		root->left = CreateTree(root->left, data);
	}
	else {
		root->right = CreateTree(root->right, data);
	}

	return root;

}*/