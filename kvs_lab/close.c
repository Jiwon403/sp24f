#include "kvs.h"

int close(kvs_t* kvs) {
	node_t* cur = kvs->db[0];
	while(cur) {
		node_t* tmp = cur;
		cur = cur->next[0];
		free(tmp->value);
		free(tmp);
	}
	if(kvs) printf("Close: kvs has %d items\n", kvs->items);
	free(kvs);
	return 0;
}
