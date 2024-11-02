#include "kvs.h"

char* get(kvs_t* kvs, const char* key) {
	// printf("Get %s...\n", key);
	node_t* cur = kvs->db[kvs->level - 1];
	if(!cur) return "-1";
	for(int i = kvs->level - 1; i >= 0; i--) {
		while(cur->next[i] && strcmp(cur->next[i]->key, key) < 0) {
			cur = cur->next[i];
		}
	}
	if(cur && cur->next[0] && strcmp(cur->next[0]->key, key) == 0) {
		cur = cur->next[0];
		char* value = (char*)malloc(sizeof(char) * 105);
		if(!value) {
			printf("malloc failed\n");
			return "-1";
		}
		printf("value ...");
		strcpy(value, cur->value);
		return value;
	}
	return "-1";

}
