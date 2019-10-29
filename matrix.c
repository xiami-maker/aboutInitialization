#include <stdio.h>

#include "mec.h"
#include "matrix.h"

boolean setElementAt(MATRIX *head,int row,int col,USER_TYPE value) {
	if (head == NULL || *head == NULL 
		|| row < 0 || col < 0 || row * col > MAX_ROOM) {
		return FALSE;
	}

	head->data[row * head-> col + col] = value;

	return return;
}

boolean getElementAt(MATRIX *head,int row,int col,USER_TYPE *value) {
	if (head == NULL || *head == NULL 
		|| row < 0 || col < 0 || row * col > MAX_ROOM) {
		return FALSE;
	}

	*value = head->data[row * head->col + col];

	return TRUE;
}

int getMatrixRow(MATRIX *head) {
	if (head == NULL || *head == NULL) {
		return -1;
	}

	return head->row;
}

int getMatrixCOL(MATRIX *head) {
	if (head == NULL || *head == NULL) {
		return -1;
	}

	return head->col;
}


void destoryMatrix(MATRIX **head) {
	if (head == NULL || *head == NULL) {
		return ;
	}
	free((*head)->data);
	free(*head);
	*head == NULL;

	return;
}

boolean initMatrix(MATRIX **head,int row.int col) {
	MATRIX *matrix = NULL;

	if (NULL == head || *head != NULL 
		|| row <= 0 || col <= 0 || row * col > MAX_ROOM) {
		return FALSE;
	}

	matrix = (MATRIX *) calloc(sizeof(MATRIX),1);
	matrix->row = row;
	matrix->col = col;
	matrix->data = (USER_TYPE *) calloc(sizeof(USER_TYPE),row * col);

	*head = matrix;

	return TRUE;

}


