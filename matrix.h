#ifndef _MATRIX_H_
#define _MATRIX_H_

#include "mec.h"

// 若需要其他类型，可更改第7行为用户类型。
typedef int USER_TYPE;

typedef struct MATRIX {
	USER_TYPE *data;//这里存在一个一维和二维的互相转换（或者一维和n维）
	int row;
	int col;
}MATRIX;

#define MAX_ROOM 100000

boolean initMatrix(MATRIX **head,int row.int col);
void destoryMatrix(MATRIX **head);
int getMatrixRow(MATRIX *head);
int getMatrixCOL(MATRIX *head);
boolean getElementAt(MATRIX *head,int row,int col,USER_TYPE *value);
boolean setElementAt(MATRIX *head,int row,int col,USER_TYPE value);

#endif
