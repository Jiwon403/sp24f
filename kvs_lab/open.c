#include "kvs.h"


kvs_t* open() {
	kvs_t* kvs = (kvs_t*)malloc(sizeof(kvs_t));
	if(kvs) { 
		kvs->items = 0;
		kvs->level = 1;
		for(int i = 0; i < max_level; i++) kvs->db[i] = (node_t*)malloc(sizeof(node_t));
		printf("Open: kvs has %d items\n", kvs->items);
	}
	return kvs;
}
