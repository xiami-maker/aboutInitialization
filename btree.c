#include <stdio.h>
#include <malloc.h>

#include "mec.h"
#include "btree.h"
#include "mecStack.h"

void travelLastRoot(const BTREE *root) {
	if(root == NULL) {
		return;
	}

	travelLastRoot(root->leftChild);
	travelLastRoot(root->rightChild);
	printf("%c ",root->ch );
}

void travelFirstRoot(const BTREE *root) {
	if(root == NULL) {
		return;
	}
	printf("%c ",root->ch );
	travelLastRoot(root->leftChild);
	travelLastRoot(root->rightChild);
	
}

void travelMiddleRoot(const BTREE *root ) {
	if(root == NULL) {
		return;
	}
	
	travelLastRoot(root->leftChild);
	printf("%c ",root->ch );
	travelLastRoot(root->rightChild);
}

boolean isalpha(int ch);
 
boolean isalpha(int ch) {
	if (ch >= 'A' && ch <= 'Z') {
		return TRUE;
	}
	return FALSE;
}  

typedef struct BTREE_ARG {
	boolean ok;
	boolean finished;
	int status;
	int index;
	int breaketMatch;
	BTREE *root;
	MEC_STACK *nodeStack;
	boolean whichChild;
	BTREE *tmp;
}BTREE_ARG;

const char *errMess;
const char * const illegalError = "非法字符!";

static boolean dealBtreeStatementStrat(int ch,BTREE_ARG *arg);
static boolean dealBtreeStatementRoot(int ch,BTREE_ARG *arg);
static boolean dealBtreeStatementRight(int ch,BTREE_ARG *arg);
static boolean dealBtreeStatementOVER(BTREE_ARG *arg);
static boolean dealBtreeStatementLEFT(int ch,BTREE_ARG *arg);
static boolean dealBtreeStatementCOMMA(int ch,BTREE_ARG *arg);
static boolean dealBtreeStatementCHILD(int ch,BTREE_ARG *arg);
static void processComma(BTREE_ARG *arg);
static BTREE *produceNewNode(int ch);
static void processLeftBracket(BTREE_ARG *arg);
static void processRigthBracket(BTREE_ARG *arg);
static void processAlpha(BTREE_ARG *arg,int ch);
static void destroyBtree(BTREE *arg);


static void destroyBtree(BTREE *arg) {
	if (arg == NULL) {
		return;
	}
	destroyBtree(arg->leftChild);
	destroyBtree(arg->rightChild);
	free(arg);
}

static void processAlpha(BTREE_ARG *arg,int ch) {
	BTREE *parent = (BTREE *) readTop(arg->nodeStack);

	if (parent->right != NULL && arg->whichChild == RIGHT_CHILD ) {
		errMess = "娃太多了";
		arg->ok = FALSE;
		return;
	}

	arg->tmp = produceNewNode(ch);
	if (arg->whichChild == LEFT_CHILD) {
		parent->leftChild = arg->tmp;
	} else {
		parent->rigthChild = arg->tmp;
	}
	++arg->index;
	arg->status = STATEMENT_ROOT;
}

static void processRigthBracket(BTREE_ARG *arg) {
	if (--arg->breaketMatch < 0) {
		errMess = "括号不匹配之缺少左括号";
		arg->ok = FALSE;
		return TRUE;
	}
	arg->status = STATEMENT_RIGHT;
	++arg->index;
	pop(arg->nodeStack);
}

static void processLeftBracket(BTREE_ARG *arg) {
	++arg->index;
	arg->status = STATEMENT_LEFT;
	++arg->breaketMatch;
	push(arg->nodeStack,arg->tmp);
	arg->whichChild = LEFT_CHILD;
}

static BTREE *produceNewNode(int ch) {
	BTREE *res = (BTREE *) calloc(sizeof(BTREE),1);
	res->data = ch;
	res->leftChild = res->rightChild = NULL;

	return res;
}

static void processComma(BTREE_ARG *arg) {
	arg->status = STATEMENT_COMMA;
	++arg->index;
	arg->whichChild = RIGHT_CHILD;
}

static boolean dealBtreeStatementCHILD(int ch,BTREE_ARG *arg) {
	if (arg == NULL) {
		return FALSE;
	}

	if (ch == '(') {
		// 处理LEFT状态
		processLeftBracket(arg);
	} else if (ch == ')') {
		// 处理RIGHT状态
		processRigthBracket(arg);
	} else if (ch == ',') {
		// 处理COMMA状态
		processComma(arg);
	} else {
		arg->ok == FALSE;
	}
	return TRUE;
}

static boolean dealBtreeStatementCOMMA(int ch,BTREE_ARG *arg) {
	if (arg == NULL) {
		return FALSE;
	} 

	if (')' == ch) {
		// 处理RIGHT状态
		processRigthBracket(arg);
	} else if (isalpha(ch)) {
		// 处理CHLID状态
		processAlpha(arg,ch);
	} else {
		arg->ok == FALSE;
	}
	return TRUE;

}

static boolean dealBtreeStatementLEFT(int ch,BTREE_ARG *arg) {
	if (arg == NULL) {
		return FALSE;
	} 

	if (isalpha(ch)) {
		// 处理ROOT状态
		processAlpha(arg,ch);
	} else if (ch == ')') {
		// 处理rigth状态
		processRigthBracket(arg);
	} else if (ch == ',') {
		// 处理COMMA状态
		 processComma(arg);
	} else {
		arg->ok == FALSE;
	}
	return TRUE;
}

static boolean dealBtreeStatementOVER(BTREE_ARG *arg) {
	if (arg == NULL) {
		return FALSE;
	} 

	// 处理结束状态
	if (arg->breaketMatch != 0) {
		errMess = "括号不匹配之缺少右括号";
		arg->ok = FALSE;
		return TRUE;
	}

	arg->finished = TRUE;
	return TRUE;
}

static boolean dealBtreeStatementRight(int ch,BTREE_ARG *arg) {
	if (arg == NULL) {
		return FALSE;
	} 

	if (ch == ',') {
		// 处理COMMA状态
		processComma(arg);
	} else if (ch == ')') {
		// 处理RIGHT状态
		processRigthBracket(arg);
	} else{
		arg->ok == FALSE;
		errMess = illegalError;
	}
	return TRUE;
}

static boolean dealBtreeStatementRoot(int ch,BTREE_ARG *arg) {
	if (arg == NULL) {
		return FALSE;
	} 

	if ('(' == ch) {
		// 处理LEFT状态
		processLeftBracket(arg);
	} else if (0 = ch) {
		// 处理OVER状态
		arg->status = STATEMENT_OVER;
	} else {
		arg->ok == FALSE;
		errMess = const char * const illegalError = "非法字符!";
	}
	return TRUE;
}

static boolean dealBtreeStatementStrat(int ch,BTREE_ARG *arg) {
	if (arg == NULL) {
		return FALSE;
	} 

	if (isalpha(ch)) {
		// 处理ROOT状态
		arg->root = produceNewNode(ch);
		++arg->index;
		arg->status = STATEMENT_ROOT;
	} else {
		arg->ok == FALSE;
		errMess = "出师未捷身先死";
	}
	return TRUE;
}

boolean createBTreeByString(const char *str,BTREE **btree) {
	BTREE_ARG arg = {
		TRUE,				//boolean ok;
		FALSE,				//boolean finished;
		STATEMENT_START,	//int status;
		0,					//int index;
		0,					//int breaketMatch;
		NULL,					//BTREE *root;
		NULL,					//MEC_STACK *nodeStack;
		LEFT_CHILD,					//boolean whichChild;
		NULL,					//BTREE *tmp;
	};

	if (str == NULL) {
		return FALSE;
	}

	while (!arg.finished && arg.ok) {
		if (arg.status == STATEMENT_START) {
			dealBtreeStatementStrat(str[arg.index],&arg);
		} else if (arg.status == STATEMENT_ROOT) {
			dealBtreeStatementRoot(str[arg.index],&arg);
		} else if (arg.status == STATEMENT_RIGHT) {
			dealBtreeStatementRight(str[arg.index],&arg);
		} else if (arg.status == STATEMENT_OVER) {
			dealBtreeStatementOVER(&arg);
		} else if (arg.status == STATEMENT_LEFT) {
			dealBtreeStatementLEFT(str[arg.index],&arg);
		} else if (arg.status == STATEMENT_COMMA) {
			dealBtreeStatementCOMMA(str[arg.index],&arg);
		} eles if (arg.status == STATEMENT_CHILD) {
			dealBtreeStatementCHILD(str[arg.index],&arg);
		}
	}

	if (ar.ok == FALSE) {
		destroyBtree(arg.root);
		arg.root = NULL;
		return FALSE;
	}
	destoryStack(&arg.nodeStack);

	*btree = arg->root;

	return TRUE;

}
