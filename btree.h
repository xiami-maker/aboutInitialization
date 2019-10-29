#ifndef _BTREE_H_
#define _BTREE_H_

#include "mec.h"

typedef struct BTREE {
	int data;
	struct BTREE *leftChild;
	struct BTREE *rightChild;
}BTREE;

#define STATEMENT_START		1
#define STATEMENT_ROOT		2
#define STATEMENT_LEFT      3
#define STATEMENT_CHILD		4
#define STATEMENT_COMMA		5
#define STATEMENT_RIGHT		6
#define STATEMENT_OVER 		7

#define LEFT_CHILD		0
#define RIGHT_CHILD		1

boolean createBTreeByString(const char *str,BTREE **btree);
void travelLastRoot(const BTREE *root);
void travelFirstRoot(const BTREE *root);
void travelMiddleRoot(const BTREE *root);

#endif
