#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max_level 15
struct node {
	char key[100];
	char* value;
	struct node* next[];
};
typedef struct node node_t;
struct kvs{
	node_t* db;
	int items;
	int level;
};
typedef struct kvs kvs_t; 

kvs_t* open();
int close(kvs_t* kvs); 
int put(kvs_t* kvs, const char* key, const char* value);
char* get(kvs_t* kvs, const char* key); 
