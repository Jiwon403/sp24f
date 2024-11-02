#include "kvs.h"

int rand_level() {
	int level = 1;
	while(rand() %2 && level < max_level) level++;
	return level++;
}

int put(kvs_t* kvs, const char* key, const char* value) {
	printf("(PUT) %s %s\n", key, value);
	node_t* update[max_level];
    node_t* cur = kvs->db[kvs->level - 1];
	if(!cur) {
		printf("failed to load cur\n");
		return -1;
	}
    for (int i = kvs->level - 1; i >= 0; i--) {
		// if(cur->next[i] == NULL) continue;
        while (cur->next[i] && strcmp(cur->next[i]->key, key) < 0) {
            cur = cur->next[i];
        }
        update[i] = cur;
    }

    cur = cur->next[0];
    // if (cur && strcmp(cur->key, key) == 0) {
    //     free(cur->value);
    //     cur->value = strdup(value);
    //     return 0;
    // }

    int level2 = rand_level();
    if (level2 > kvs->level) {
        for (int i = kvs->level; i < level2; i++) {
            update[i] = kvs->db[i];
        }
        kvs->level = level2;
    }
    // node2를 동적으로 할당하고, next 배열 크기를 level2에 맞춤
    node_t* node2 = (node_t*)malloc(sizeof(node_t) + level2 * sizeof(node_t*));
	if(!node2) {
		printf("Failed to malloc node2\n");
		return -1;
	}
	strcpy(node2->key, key);
    node2->value = strdup(value);
    for (int i = 0; i < kvs->level; i++) {
        node2->next[i] = update[i]->next[i];
        update[i]->next[i] = node2;
    }
    kvs->items++;
    return 0;
}
