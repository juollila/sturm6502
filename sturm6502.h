
/* addressing modes */
#define NONE    0x1    /* implied */
#define IMM     0x2    /* immediate */
#define ZP      0x4
#define ZP_X    0x8
#define ZP_Y    0x10
#define ABS     0x20
#define ABS_X   0x40
#define ABS_Y   0x80
#define REL     0x100  /* relative */
#define IND_X   0x200  /* (indirect,x) */
#define IND_Y   0x400  /* (indirect),y */
#define ABS_IND 0x800  /* (absolute indirect) */
#define ACC     0x1000 /* accumulator */
#define IMM2	0x2000 /* special handling for ldy, cpy, cpx, ldx */
#define ABS_Y2  0x4000 /* special handling for ldx */

/* misc defines */
#define MAX_LINE_LEN 128
#define EOL 0x0d
#define NOT_FOUND -1

/* tokens */
enum {
   TOKEN_EOL,
   TOKEN_CMD,
   TOKEN_COMMENT,
   TOKEN_A,
   TOKEN_X,
   TOKEN_Y,
   TOKEN_HASH,
   TOKEN_COMMA,
   TOKEN_LPAREN,
   TOKEN_RPAREN,
   TOKEN_MUL,
   TOKEN_LOW,
   TOKEN_HIGH,
   TOKEN_PLUS,
   TOKEN_MINUS,
   TOKEN_DIV,
   TOKEN_EQU,
   TOKEN_NUMBER,
   TOKEN_IDENT,
   TOKEN_STRING,
   TOKEN_DOT,
   TOKEN_PSEUDO,
   TOKEN_CHAR,
   TOKEN_PARAM,
   TOKEN_LOCAL,
   TOKEN_UNKNOWN
};
/* error messages */
enum {
   INVALID_MODE,
   SYNTAX_ERROR,
   INVALID_CMD,
   INVALID_EXPR,
   WRITE_ERROR,
   OPEN_ERROR,
   INVALID_BRANCH,
   INVALID_OPTION,
   READ_ERROR,
   INTERNAL_ERROR,
   INVALID_MACRO,
   OUT_OF_MEMORY,
   DIV_0,
   RIGHT_PAREN
};

char *error_msg[] = {
   "Invalid addressing mode",
   "Syntax error",
   "Invalid command",
   "Invalid expression",
   "Write to file failed",
   "Cannot open file",
   "Branch out of range",
   "Value missing",
   "Cannot read file",
   "Internal error",
   "Macro already exist",
   "Out of memory",
   "Division by zero",
   "Right parenthesis expected"
};


char *delimiter_chars = "\t :";
char *comment_chars = ";*";

struct macro_param {
   char *str;
   struct macro_param *next;
};

struct macro_line {
   char *str;
   struct macro_line *next;
};

struct macro {
   char *name;
   struct macro_param *param;
   struct macro_line *line;
   struct symbol *local; /* local next symbol */
   struct macro *next;
};

struct token {
   unsigned int id;
   int value;
   char *label;
   struct macro *mac;
   struct token *next;
};

struct instruction {
   char *mnemonic;
   unsigned int addr_modes;
   unsigned char op_code; /* base value */
};

struct pseudo_func {
   char *name;
   void (*func)(void);
};

struct file {
   FILE *file;
   char *name;
   char *mode;
   unsigned int line_number;
};

struct symbol {
   unsigned int value;
   char *name;
   struct symbol *global; /* global next symbol */
   struct symbol *local; /* local next symbol */
};

struct instruction instructions[] = {
   { "ADC", IMM|ZP|ZP_X|ABS|ABS_X|ABS_Y|IND_X|IND_Y, 0x61 },
   { "AND", IMM|ZP|ZP_X|ABS|ABS_X|ABS_Y|IND_X|IND_Y, 0x21 },
   { "ASL", ACC|ZP|ZP_X|ABS|ABS_X, 0x02 },
   { "BCC", REL, 0x90 },
   { "BCS", REL, 0xb0 },
   { "BEQ", REL, 0xf0 },
   { "BIT", ZP|ABS, 0x20 },
   { "BMI", REL, 0x30 },
   { "BNE", REL, 0xd0 },
   { "BPL", REL, 0x10 },
   { "BRK", NONE, 0x00 },
   { "BVC", REL, 0x50 },
   { "BVS", REL, 0x70 },
   { "CLC", NONE, 0x18 },
   { "CLD", NONE, 0xd8 },
   { "CLI", NONE, 0x58 },
   { "CLV", NONE, 0xb8 },
   { "CMP", IMM|ZP|ZP_X|ABS|ABS_X|ABS_Y|IND_X|IND_Y, 0xc1 },
   { "CPX", IMM2|ZP|ABS, 0xe0 },
   { "CPY", IMM2|ZP|ABS, 0xc0 },
   { "DEC", ZP|ZP_X|ABS|ABS_X, 0xc2 },
   { "DEX", NONE, 0xca },
   { "DEY", NONE, 0x88 },
   { "EOR", IMM|ZP|ZP_X|ABS|ABS_X|ABS_Y|IND_X|IND_Y, 0x41 },
   { "INC", ZP|ZP_X|ABS|ABS_X, 0xe2 },
   { "INX", NONE, 0xe8 },
   { "INY", NONE, 0xc8 },
   { "JMP", ABS|ABS_IND, 0x40 },
   { "JSR", ABS, 0x14 },
   { "LDA", IMM|ZP|ZP_X|ABS|ABS_X|ABS_Y|IND_X|IND_Y, 0xa1 },
   { "LDX", IMM2|ZP|ZP_Y|ABS|ABS_Y2, 0xa2 },
   { "LDY", IMM2|ZP|ZP_X|ABS|ABS_X, 0xa0 },
   { "LSR", ACC|ZP|ZP_X|ABS|ABS_X, 0x42 },
   { "NOP", NONE, 0xea },
   { "ORA", IMM|ZP|ZP_X|ABS|ABS_X|ABS_Y|IND_X|IND_Y, 0x01 },
   { "PHA", NONE, 0x48 },
   { "PHP", NONE, 0x08 },
   { "PLA", NONE, 0x68 },
   { "PLP", NONE, 0x28 },
   { "ROL", ACC|ZP|ZP_X|ABS|ABS_X, 0x22 },
   { "ROR", ACC|ZP|ZP_X|ABS|ABS_X, 0x62 },
   { "RTI", NONE, 0x40 },
   { "RTS", NONE, 0x60 },
   { "SBC", IMM|ZP|ZP_X|ABS|ABS_X|ABS_Y|IND_X|IND_Y, 0xe1 },
   { "SEC", NONE, 0x38 },
   { "SED", NONE, 0xf8 },
   { "SEI", NONE, 0x78 },
   { "STA", ZP|ZP_X|ABS|ABS_X|ABS_Y|IND_X|IND_Y, 0x81 },
   { "STX", ZP|ZP_Y|ABS, 0x82 },
   { "STY", ZP|ZP_X|ABS, 0x80 },
   { "TAX", NONE, 0xaa },
   { "TAY", NONE, 0xa8 },
   { "TSX", NONE, 0xba },
   { "TXA", NONE, 0x8a },
   { "TXS", NONE, 0x9a },
   { "TYA", NONE, 0x98 }
};

void handle_byte(void);
void handle_else(void);
void handle_endif(void);
void handle_endmac(void);
void handle_if(void);
void handle_ifdef(void);
void handle_ifndef(void);
void handle_incbin(void);
void handle_include(void);
void handle_mac(void);
void handle_org(void);
void handle_word(void);

struct pseudo_func functions[] = {
   { ".BYTE", &handle_byte },
   { ".ELSE", &handle_else },
   { ".ENDIF", &handle_endif },
   { ".ENDMAC", &handle_endmac }, /* number 3 */
   { ".IF", &handle_if },
   { ".IFDEF", &handle_ifdef },
   { ".IFNDEF", &handle_ifndef },
   { ".INCBIN", &handle_incbin },
   { ".INCLUDE", &handle_include },
   { ".MAC", &handle_mac }, /* number 9 */
   { ".ORG", &handle_org },
   { ".WORD", &handle_word }
};

#define ENDMAC 3
#define MACRO 9
