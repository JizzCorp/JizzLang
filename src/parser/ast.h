#ifndef AST
#define AST

typedef enum {
	NODEPROGRAM, NODESTATEMENT, NODEOUTPUT, NODEIF, NODECASE, NODELOOP, NODERETURN, NODEEXIT, NODEFUNCTIONDECL, NODEINPUT, NODEDECLARATION, NODEASSIGNMENT,
	NODEFUNCTIONCALL, NODEEXPRESSION, NODELOGOR, NODELOGAND, NODEBITOR, NODEBITAND, NODEEQUALITY, NODEINEQ, NODEADD, NODEMULT, NODEPOWER, NODENOT,
	NODEPRIMARY
} NodeType;

typedef struct {
	NodeType node_type;
	NodeType child_type;
	void* statement; // Output* | If* | Case* | Loop* | Return* | Exit* | FunctionDecl* | Input* | Declaration* | Assignment* | FunctionCall* | Expression*
} NodeStatement;

typedef struct {
	NodeType node_type;
	NodeStatement** statements;
} NodeProgram;

typedef struct {
	NodeType node_type;
	void* expr; // NodeExpression*
	Token* primary_datatype;
} NodePrimary;

typedef struct _NodeNot_ {
	NodeType node_type;
	struct _NodeNot_* recnot;
	NodePrimary* primary;
} NodeNot;

typedef struct _NodePower_ {
	NodeType node_type;
	NodeNot* operand;
	struct _NodePower_* exponent;
} NodePower;

typedef struct {
	NodeType node_type;
	Token* operation;
	NodePower* operand1;
	NodePower* operand2;
} NodeMult;

typedef struct {
	NodeType node_type;
	Token* operation;
	NodeMult* operand1;
	NodeMult* operand2;
} NodeAdd;

typedef struct {
	NodeType node_type;
	Token* operation;
	NodeAdd* operand1;
	NodeAdd* operand2;
} NodeIneq;

typedef struct {
	NodeType node_type;
	Token* operation;
	NodeIneq* operand1;
	NodeIneq* operand2;
} NodeEquality;

typedef struct {
	NodeType node_type;
	NodeEquality* operand1;
	NodeEquality* operand2;
} NodeBitAnd;

typedef struct {
	NodeType node_type;
	NodeBitAnd* operand1;
	NodeBitAnd* operand2;
} NodeBitOr;

typedef struct {
	NodeType node_type;
	NodeBitOr* operand1;
	NodeBitOr* operand2;
} NodeLogAnd;

typedef struct {
	NodeType node_type;
	NodeLogAnd* operand1;
	NodeLogAnd* operand2;
} NodeLogOr;

typedef struct {
	NodeType node_type;
	NodeLogOr* logical_or;
} NodeExpression;

typedef struct {
	NodeType node_type;
	Token* function_name;
	NodeExpression** args;
} NodeFunctionCall;

typedef struct {
	NodeType node_type;
	Token* var;
	NodeExpression* expr;
} NodeAssignment;

typedef struct {
	NodeType node_type;
	Token* data_type;
	Token* var;
	NodeAssignment* assn;
} NodeDeclaration;

typedef struct {
	NodeType node_type;
	Token* data_type;
	Token* var;
	Token* inputstr;
} NodeInput;

typedef struct {
	NodeType node_type;
	Token* function_name;
	Token* args_types;
	Token* args_names;
	NodeProgram* procedure;
} NodeFunctionDecl;

typedef struct {
	NodeType node_type;
	Token* nat_token;
} NodeExit;

typedef struct {
	NodeType node_type;
	NodeExpression* return_expr;
} NodeReturn;

typedef struct {
	NodeType node_type;
	NodeExpression* condition;

	NodeType loop_instructions_type;
	void* loop_instructions; // NodeStatement* | NodeProgram*
} NodeLoop;

typedef struct {
	NodeType node_type;
	NodeExpression* condition;

	NodeType mainbrach_type;
	void* mainbranch; // NodeStatement* | NodeProgram*

	NodeType elsecasebrach_type;
	void* elsecasebranch; // NodeStatement* | NodeProgram*
} NodeCase;

typedef struct {
	NodeType node_type;
	NodeExpression* condition;

	NodeType mainbranch_type;
	void* mainbranch; // NodeStatement* | NodeProgram*
	
	NodeType elsebranch_type;
	void* elsebranch; // NodeStatement* | NodeProgram*
} NodeIf;

typedef struct {
	NodeType node_type;
	NodeExpression* expression_node;
} NodeOutput;

typedef NodeProgram* AbstractSyntaxTree;

#endif
