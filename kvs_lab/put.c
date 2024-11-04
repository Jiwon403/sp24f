#include "kvs.h"

int rand_level() {
	int level = 1;
	while(rand() %2 && level < max_level) level++;
	return level++;
}

int put(kvs_t* kvs, const char* key, const char* value) {
    node_t* update[max_level];
    node_t* cur = kvs->db;

    for(int i = kvs->level-1; i>=0; i--) {
        while(cur->next[i] && strcmp(cur->next[i]->key, key) < 0) cur = cur->next[i];
        update[i] = cur;
    }
    int new_level = rand_level();
    if (new_level > kvs->level) {
        for (int i = kvs->level; i < new_level; i++) {
            update[i] = kvs->db;  // 새로 추가된 레벨을 헤더로 설정
        }
        kvs->level = new_level;
    }

    node_t* new_node = (node_t*)malloc(sizeof(*new_node) + new_level*sizeof(new_node));
    if(new_node == NULL) return -1;
    strcpy(new_node->key, key);
    new_node->value = strdup(value);
    for(int i = 0; i < new_level; i++) {
        new_node->next[i] = update[i]->next[i];
        update[i]->next[i] = new_node;
    }
    kvs->items++;
    return 0;
}
