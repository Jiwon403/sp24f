#include "kvs.h"

char* get(kvs_t* kvs, const char* key) {
	node_t* cur = kvs->db;
	for(int i = kvs->level - 1; i >= 0; i--) {
		while(cur->next[i] && strcmp(cur->next[i]->key, key) < 0) cur = cur->next[i];
	}
	cur = cur->next[0];
	return (cur && !strcmp(cur->key, key)) ? strdup(cur->value) : "-1";
}
