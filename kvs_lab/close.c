#include "kvs.h"

int close(kvs_t* kvs) {
	if(kvs) printf("Close: kvs has %d items\n", kvs->items);
	free(kvs);
	return 0;
}
