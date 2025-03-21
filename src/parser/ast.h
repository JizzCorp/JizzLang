#ifndef AST
#define AST

typedef enum {
	NONE,
	PROGRAM,
	// statements
	OUTPUT,
	IF,
	CASE,
	LOOP,
	RETURN,
	EXIT,
	FUNCDECL,
	INPUT,
	DECL,
	ASSIGN,
	FUNCALL,
	ELSE,
	ELSECASE,
	PARAMS,
	// expressions
	LOGOR,
	LOGAND,
	BITOR,
	BITAND,
	EQ,
	NEQ,
	GT,
	GE,
	LT,
	LE,
	ADD,
	SUB,
	CONCAT,
	MULT,
	DIV,
	MODULO,
	// primary data
	NATURAL,
	NEGINT,
	POSREAL,
	NEGREAL,
	IDENTIF,
	STRING
} NodeType;

typedef struct {
	NodeType nodetype; // assign PROGRAM
	NodeType statement_type; // NONE | OUTPUT | IF | CASE | LOOP | RETURN | EXIT | FUNCDECL | INPUT | DECL | ASSIGN | FUNCALL
	void* statement; // statement; can be NULL or one of the follwing node pointers
	// OutputNode* | IfNode* | CaseNode*
	// LoopNode* | ReturnNode* | ExitNode* |
	// FuncDeclNode* | InputNode* | DeclNode* |
	// AssingNode* | FunCallNode*
} ProgramNode;

typedef struct {
	NodeType nodetype; // assign OUTPUT
	
	NodeType output_content_type;
	void* output_content; // expression; can be one of the following node pointers
	// LogOrNode* | LogAndNode* |
	// BitOrNode* | BitAndNode* |
	// EqNode* | NeqNode*| GtNode* |
	// GeNode* | LtNode*| LeNode* |
	// AddNode* | SubNode*| ConcatNode* |
	// MultNode* | DivNode*| ModuloNode* |
	// NaturalNode* | NegIntNode* |
	// PosRealNode* | NegRealNode* |
	// IdentifNode* | StringNode* |
	// ElseNode* | ElsecaseNode* | ParamsNode*
} OutputNode;

typedef struct {
	NodeType nodetype; // assign IF
	
	NodeType condition_type;
	void* condition; // expression; can be one of the following node pointers
	// LogOrNode* | LogAndNode* |
	// BitOrNode* | BitAndNode* |
	// EqNode* | NeqNode*| GtNode* |
	// GeNode* | LtNode*| LeNode* |
	// AddNode* | SubNode*| ConcatNode* |
	// MultNode* | DivNode*| ModuloNode* |
	// NaturalNode* | NegIntNode* |
	// PosRealNode* | NegRealNode* |
	// IdentifNode* | StringNode* |
	// ElseNode* | ElsecaseNode* | ParamsNode*
	
	ProgramNode* mainbranch;
	ProgramNode* elsebranch;
} IfNode;

typedef struct {
	NodeType nodetype; // assign CASE
	
	NodeType condition_type;
	void* condition; // expression; can be one of the following node pointers
	// LogOrNode* | LogAndNode* |
	// BitOrNode* | BitAndNode* |
	// EqNode* | NeqNode*| GtNode* |
	// GeNode* | LtNode*| LeNode* |
	// AddNode* | SubNode*| ConcatNode* |
	// MultNode* | DivNode*| ModuloNode* |
	// NaturalNode* | NegIntNode* |
	// PosRealNode* | NegRealNode* |
	// IdentifNode* | StringNode* |
	// ElseNode* | ElsecaseNode* | ParamsNode*
	
	ProgramNode* mainbranch;
	ProgramNode* elsebranch;
} CaseNode;

typedef struct {
	NodeType nodetype; // assign LOOP
	
	NodeType condition_type;
	void* condition; // expression; can be one of the following node pointers
	// LogOrNode* | LogAndNode* |
	// BitOrNode* | BitAndNode* |
	// EqNode* | NeqNode*| GtNode* |
	// GeNode* | LtNode*| LeNode* |
	// AddNode* | SubNode*| ConcatNode* |
	// MultNode* | DivNode*| ModuloNode* |
	// NaturalNode* | NegIntNode* |
	// PosRealNode* | NegRealNode* |
	// IdentifNode* | StringNode* |
	
	ProgramNode* procedure;
} LoopNode;

typedef struct {
	NodeType nodetype; // assign RETURN
	
	NodeType exprtype;
	void* expr; // expression; can be one of the following node pointers
	// LogOrNode* | LogAndNode* |
	// BitOrNode* | BitAndNode* |
	// EqNode* | NeqNode*| GtNode* |
	// GeNode* | LtNode*| LeNode* |
	// AddNode* | SubNode*| ConcatNode* |
	// MultNode* | DivNode*| ModuloNode* |
	// NaturalNode* | NegIntNode* |
	// PosRealNode* | NegRealNode* |
	// IdentifNode* | StringNode* |
	// ElseNode* | ElsecaseNode* | ParamsNode*
} ReturnNode;

typedef struct {
	NodeType nodetype; // assign EXIT
	Token* natural;
} ExitNode;

typedef struct {
	NodeType nodetype; // assign FUNCDECL
	Token* function_name;
	ProgramNode* procedure;
	// put parameters' types and names in symbol table (yet to be implemented)
} FuncDeclNode;

typedef struct {
	NodeType nodetype; // assign INPUT
	Token* storevar;
	// in case we have an input without declaration, check if variable is in symbol table (yet to be implemented)
} InputNode;

typedef struct {
	NodeType nodetype; // assign DECL
	Token* var;
	// put variable's data type in symbol table (yet to be implemented)
} DeclNode;

typedef struct {
	NodeType nodetype; // assign ASSIGN (lol)
	Token* varname;
	// put variable type and content in symbol table (yet to be implemented)
} AssingNode;

typedef struct {
	NodeType nodetype; // assign FUNCALL
	Token* function_name;
	void** expressions; // use symbol table to check if function exists and expressions' count and types match with existing function's
	// expressions array can be NULL or contain one or more of the following node pointers
	// LogOrNode* | LogAndNode* |
	// BitOrNode* | BitAndNode* |
	// EqNode* | NeqNode*| GtNode* |
	// GeNode* | LtNode*| LeNode* |
	// AddNode* | SubNode*| ConcatNode* |
	// MultNode* | DivNode*| ModuloNode* |
	// NaturalNode* | NegIntNode* |
	// PosRealNode* | NegRealNode* |
	// IdentifNode* | StringNode* |
	// ElseNode* | ElsecaseNode* | ParamsNode*
} FunCallNode;

// add expression nodes

#endif
