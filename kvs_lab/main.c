#include "kvs.h"
int main() {
	kvs_t* kvs = open();

	if(!kvs) {
		printf("Failed to open kvs\n");
		return -1;
	}
	FILE *query1, *answer;
	query1 = fopen("query.dat", "r");
	answer = fopen("answer.dat", "w");
	
	if(answer == NULL || query1 == NULL) return -1;
	char str[256];
	char *cmd, *key, *value;
	while(fgets(str, sizeof(str), query1) != NULL) {
		cmd = strtok(str, ",");
		key = strtok(NULL, ",");
		value = strtok(NULL, ",");
		if(value[strlen(value) - 1] == '\n') value[strlen(value) - 1] = '\0';
		if(!strcmp(cmd, "set")) put(kvs, key, value);
		else if(!strcmp(cmd, "get")) fprintf(answer, "%s\n", get(kvs, key));
	}
	fclose(query1);
	fclose(answer);
	close(kvs);
	return 0;
}
