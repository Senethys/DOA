#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "table.h"

/*
 * Minimum working example for table.c. Inserts 4 key-value pairs into
 * a table, including one duplicate. Makes two lookups and prints the
 * result. The responsibility to deallocate the key-value pairs is NOT
 * handed over to the table. Thus, all pointers must be stored outside
 * the table.
 *
 * Authors: Niclas Borlin (niclas@cs.umu.se)
 *	    Adam Dahlgren Lindstrom (dali@cs.umu.se)
 *
 * Version information:
 *   2018-02-06: v1.0, first public version.
 *   2019-03-05: v1.01, improved docs.
 */

// Create a dynamic copy of the string str.
static char* make_string_copy(const char *str)
{
	char *copy = calloc(strlen(str) + 1, sizeof(char));
	strcpy(copy, str);
	return copy;
}

// Interpret the supplied key and value pointers and print their content.
static void print_int_string_pair(const void *key, const void *value)
{
	//const int *k=key;
	const char *s=value;
	printf("%d, %s", 	*(int*)key, s);
}

// Compare two keys (int *).
static int compare_ints(const void *k1, const void *k2)
{
	int key1 = *(int *)k1;
	int key2 = *(int *)k2;

	if ( key1 == key2 )
		return 0;
	if ( key1 < key2 )
		return -1;
	return 1;
}

int main(void)
{
	// Keep track of the key-value pairs we allocate.
	int *key[6];
	char *value[6];
	printf("Creating table:\n");
	table *t = table_empty(compare_ints, NULL, NULL);
	printf("Is table empty? %d\n\n", table_is_empty(t));
//	table_choose_key(t); Crashes the program

	key[0] = malloc(sizeof(int));
	*key[0] = 90187;
	value[0] = make_string_copy("Umea");
	table_insert(t, key[0], value[0]);

	printf("Table after inserting 1 pair: \n");
	table_print(t, print_int_string_pair);
	printf("Is table empty? %d\n\n", table_is_empty(t));
	printf("Lookup of a non existent key:\n");
	char *return_value = (char *) table_lookup(t, key[1]);
	printf("%s \n\n", return_value);
	table_print(t, print_int_string_pair);
	printf("Lookup of a existent key:\n");
	char *return_value1 = (char *) table_lookup(t, key[0]);
	printf("%s \n", return_value1);


	// printf("Inserting 3 more pairs... \n");
	//
	// key[1] = malloc(sizeof(int));
	// *key[1] = 90184;
	// value[1] = make_string_copy("Kumea");
	// table_insert(t, key[1], value[1]);
	//
	// key[2] = malloc(sizeof(int));
	// *key[2] = 98185;
	// value[2] = make_string_copy("Kiruna");
	// table_insert(t, key[2], value[2]);
	//
	// key[4] = malloc(sizeof(int));
	// *key[4] = 98186;
	// value[4] = make_string_copy("Kiruna2");
	// table_insert(t, key[4], value[4]);
	//
	// printf("Table after inserting 3 more pairs: \n\n");
	// table_print(t, print_int_string_pair);
	//
	//
	// int c=90187;
	// const char *s=table_lookup(t,&c);
	// printf("Lookup of postal code %d: %s.\n",c,s);
	// printf("Table_choose_key: ");
	// int *tlk = table_choose_key(t);
	// printf("%d: \n\n", *tlk );

	//
	// printf("Adding a postal code %d: %s.\n\n",80317,"Gävle");
	// key[4] = malloc(sizeof(int));
	// *key[4] = 80317;
	// value[4] = make_string_copy("Gävle");
	// table_insert(t, key[4], value[4]);
	//
	// printf("Adding a duplicate of postal code %d: %s.\n\n",90187,"Umeå University");
	// key[3] = malloc(sizeof(int));
	// *key[3] = 90187;
	// value[3] = make_string_copy("Umea (Universitet)");
	// table_insert(t, key[3], value[3]);
	//
	// printf("Table after inserting 2 pairs:\n\n");
	// table_print(t, print_int_string_pair);
	//
	//
	// int b=90187;
	// s=table_lookup(t,&b);
	// printf("Lookup of postal code %d: %s.\n",b,s);
	// printf("Table after lookup:\n\n");
	// table_print(t, print_int_string_pair);
	//
	//
	// key[5] = malloc(sizeof(int));
	// *key[5] = 101001;
	// value[5] = make_string_copy("Kaunas");
	// table_insert(t, key[5], value[5]);
	//
	//
	// key[6] = malloc(sizeof(int));
	// *key[6] = 201011;
	// value[6] = make_string_copy("S:t Petersburg");
	// table_insert(t, key[6], value[6]);
	//
	// printf("Table after adding 2 entries:\n");
	// table_print(t, print_int_string_pair);
	//
	// printf("Table before lookup:\n\n");
	// table_print(t, print_int_string_pair);
	// int a = 98185;
	// a=98185;
	// s=table_lookup(t,&a);
	// printf("Lookup of postal code %d: %s.\n",a,s);
	//
	//
	// table_print(t, print_int_string_pair);
	// printf("Removing...:\n");
	// int test = 90187;
	// table_remove(t, &test);
	// printf("Table after remove of Umea (dubplicate):\n\n");
	// table_print(t, print_int_string_pair);
	//
	// table_print(t, print_int_string_pair);
  //       // Kill table.
	// table_kill(t);
	//
  //       // Free key/value pairs that we put in	 the table.
  //       for (int i=0; i<sizeof(key)/sizeof(key[0]); i++) {
  //               free(key[i]);
  //               free(value[i]);
  //       }
		table_kill(t);
		printf("End.\n\n");
}
