#include "kvs.h"

kvs_t* open() {
	kvs_t* kvs = (kvs_t*)malloc(sizeof(*kvs));
	if(kvs == NULL) return NULL;
	if(kvs) { 
		kvs->items = 0;
		kvs->level = 1;
		node_t* header = (node_t*)malloc(sizeof(*header) + max_level*sizeof(header));
		if(!header) return NULL;
		strcpy(header->key, "Z");
		header->value = "Z";
		kvs->db = header;
		for(int i = 0; i < max_level; i++) kvs->db->next[i] = NULL;
		printf("Open: kvs has %d items\n", kvs->items);
		return kvs;
	}
	return NULL;
}
