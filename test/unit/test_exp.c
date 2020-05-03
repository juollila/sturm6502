#include "lcut.h"
#include "string.h"

struct symbol {
   unsigned int value;
   char *name;
   struct symbol *global; /* global next symbol */
   struct symbol *local; /* local next symbol */
};
struct symbol *find_symbol(char *);
extern void parse_line(void);
extern void init(void);
extern char line[];
extern unsigned char unit_obj[];
extern unsigned char column;
extern unsigned int PC;
extern unsigned char opt_debug;

void tc_dec1(lcut_tc_t *tc, void *data) {
   struct symbol *sym;
   init();
   strcpy(&line[0], "TEST = 65535\n");
   parse_line();
   sym = find_symbol("TEST");
   LCUT_INT_EQUAL(tc, 0xffff, sym->value);
}

void tc_dec2(lcut_tc_t *tc, void *data) {
   struct symbol *sym;
   init();
   strcpy(&line[0], "TEST = -10\n");
   parse_line();
   sym = find_symbol("TEST");
   LCUT_INT_EQUAL(tc, -10, sym->value);
}

void tc_hex1(lcut_tc_t *tc, void *data) {
   struct symbol *sym;
   init();
   strcpy(&line[0], "TEST = $ABCD\n");
   parse_line();
   sym = find_symbol("TEST");
   LCUT_INT_EQUAL(tc, 0xabcd, sym->value);
}

void tc_hex2(lcut_tc_t *tc, void *data) {
   struct symbol *sym;
   init();
   strcpy(&line[0], "TEST = -$ABCD\n");
   parse_line();
   sym = find_symbol("TEST");
   LCUT_INT_EQUAL(tc, -0xabcd, sym->value);
}

void tc_bin1(lcut_tc_t *tc, void *data) {
   struct symbol *sym;
   init();
   strcpy(&line[0], "TEST = %10000000\n");
   parse_line();
   sym = find_symbol("TEST");
   LCUT_INT_EQUAL(tc, 0x80, sym->value);
}

void tc_bin2(lcut_tc_t *tc, void *data) {
   struct symbol *sym;
   init();
   strcpy(&line[0], "TEST = %000100000000\n");
   parse_line();
   sym = find_symbol("TEST");
   LCUT_INT_EQUAL(tc, 0x100, sym->value);
}

void tc_mul1(lcut_tc_t *tc, void *data) {
   struct symbol *sym;
   init();
   strcpy(&line[0], "ARG1 = 256\n");
   parse_line();
   strcpy(&line[0], "ARG2 = 4\n");
   column = 0;
   parse_line();
   strcpy(&line[0], "TEST = ARG1 * ARG2\n");
   column = 0;
   parse_line();
   sym = find_symbol("TEST");
   LCUT_INT_EQUAL(tc, 1024, sym->value);
}

void tc_mul2(lcut_tc_t *tc, void *data) {
   struct symbol *sym;
   init();
   strcpy(&line[0], "ARG1 = 256\n");
   parse_line();
   strcpy(&line[0], "ARG2 = -4\n");
   column = 0;
   parse_line();
   strcpy(&line[0], "TEST=ARG2*ARG1\n");
   column = 0;
   parse_line();
   sym = find_symbol("TEST");
   LCUT_INT_EQUAL(tc, -1024, sym->value);
}

void tc_div1(lcut_tc_t *tc, void *data) {
   struct symbol *sym;
   init();
   strcpy(&line[0], "ARG1 = 1024\n");
   parse_line();
   strcpy(&line[0], "ARG2 = 4\n");
   column = 0;
   parse_line();
   strcpy(&line[0], "TEST = ARG1 / ARG2\n");
   column = 0;
   parse_line();
   sym = find_symbol("TEST");
   LCUT_INT_EQUAL(tc, 256, sym->value);
}

void tc_add1(lcut_tc_t *tc, void *data) {
   struct symbol *sym;
   init();
   strcpy(&line[0], "ARG1 = 1024\n");
   parse_line();
   strcpy(&line[0], "ARG2 = 4\n");
   column = 0;
   parse_line();
   strcpy(&line[0], "TEST = ARG1 + ARG2\n");
   column = 0;
   parse_line();
   sym = find_symbol("TEST");
   LCUT_INT_EQUAL(tc, 1028, sym->value);
}

void tc_sub1(lcut_tc_t *tc, void *data) {
   struct symbol *sym;
   init();
   strcpy(&line[0], "ARG1 = 1024\n");
   parse_line();
   strcpy(&line[0], "ARG2 = 4\n");
   column = 0;
   parse_line();
   strcpy(&line[0], "TEST = ARG2 - ARG1\n");
   column = 0;
   parse_line();
   sym = find_symbol("TEST");
   LCUT_INT_EQUAL(tc, -1020, sym->value);
}

void tc_low1(lcut_tc_t *tc, void *data) {
   struct symbol *sym;
   init();
   strcpy(&line[0], "ARG1 = $FFD2\n");
   parse_line();
   strcpy(&line[0], "TEST = <ARG1\n");
   column = 0;
   parse_line();
   sym = find_symbol("TEST");
   LCUT_INT_EQUAL(tc, 0xd2, sym->value);
}

void tc_high1(lcut_tc_t *tc, void *data) {
   struct symbol *sym;
   init();
   strcpy(&line[0], "ARG1 = $FFD2\n");
   parse_line();
   strcpy(&line[0], "TEST = >ARG1\n");
   column = 0;
   parse_line();
   sym = find_symbol("TEST");
   LCUT_INT_EQUAL(tc, 0xff, sym->value);
}

void tc_paren1(lcut_tc_t *tc, void *data) {
   struct symbol *sym;
   init();
   // opt_debug = 3;
   strcpy(&line[0], "FOO = $10\n");
   parse_line();
   strcpy(&line[0], "BAR = <FOO\n");
   column = 0;
   parse_line();
   strcpy(&line[0], "STURM = $74\n");
   column = 0;
   parse_line();
   strcpy(&line[0], "TEST = (FOO+BAR)*STURM\n");
   column = 0;
   parse_line();
   sym = find_symbol("TEST");
   LCUT_INT_EQUAL(tc, 0xe80, sym->value);
}

void tc_paren2(lcut_tc_t *tc, void *data) {
   struct symbol *sym;
   init();
   // opt_debug = 3;
   strcpy(&line[0], "FOO = $10\n");
   parse_line();
   strcpy(&line[0], "BAR = <FOO\n");
   column = 0;
   parse_line();
   strcpy(&line[0], "STURM = $74\n");
   column = 0;
   parse_line();
   strcpy(&line[0], "TEST = FOO+BAR*STURM\n");
   column = 0;
   parse_line();
   sym = find_symbol("TEST");
   LCUT_INT_EQUAL(tc, 0x750, sym->value);
}

int main() {
   lcut_ts_t   *suite = NULL;
   LCUT_TEST_BEGIN("Sturm6502 macro assembler - part 3", NULL, NULL);

   LCUT_TS_INIT(suite, "Decimal", NULL, NULL);
   LCUT_TC_ADD(suite, "Decimal #1", tc_dec1, NULL, NULL, NULL);
   LCUT_TC_ADD(suite, "Decimal #2", tc_dec2, NULL, NULL, NULL);
   LCUT_TS_ADD(suite);

   LCUT_TS_INIT(suite, "Hex", NULL, NULL);
   LCUT_TC_ADD(suite, "Hex #1", tc_hex1, NULL, NULL, NULL);
   LCUT_TC_ADD(suite, "Hex #2", tc_hex2, NULL, NULL, NULL);
   LCUT_TS_ADD(suite);

   LCUT_TS_INIT(suite, "Binary", NULL, NULL);
   LCUT_TC_ADD(suite, "Binary #1", tc_bin1, NULL, NULL, NULL);
   LCUT_TC_ADD(suite, "Binary #2", tc_bin2, NULL, NULL, NULL);
   LCUT_TS_ADD(suite);

   LCUT_TS_INIT(suite, "Mul", NULL, NULL);
   LCUT_TC_ADD(suite, "Mul #1", tc_mul1, NULL, NULL, NULL);
   LCUT_TC_ADD(suite, "Mul #2", tc_mul2, NULL, NULL, NULL);
   LCUT_TS_ADD(suite);

   LCUT_TS_INIT(suite, "Div", NULL, NULL);
   LCUT_TC_ADD(suite, "Div #1", tc_div1, NULL, NULL, NULL);
   LCUT_TS_ADD(suite);

   LCUT_TS_INIT(suite, "Add", NULL, NULL);
   LCUT_TC_ADD(suite, "Add #1", tc_add1, NULL, NULL, NULL);
   LCUT_TS_ADD(suite);

   LCUT_TS_INIT(suite, "Sub", NULL, NULL);
   LCUT_TC_ADD(suite, "Sub #1", tc_sub1, NULL, NULL, NULL);
   LCUT_TS_ADD(suite);

   LCUT_TS_INIT(suite, "Low", NULL, NULL);
   LCUT_TC_ADD(suite, "Low #1", tc_low1, NULL, NULL, NULL);
   LCUT_TS_ADD(suite);

   LCUT_TS_INIT(suite, "High", NULL, NULL);
   LCUT_TC_ADD(suite, "High #1", tc_high1, NULL, NULL, NULL);
   LCUT_TS_ADD(suite);

   LCUT_TS_INIT(suite, "Parenthesis", NULL, NULL);
   LCUT_TC_ADD(suite, "Parenthesis #1", tc_paren1, NULL, NULL, NULL);
   LCUT_TC_ADD(suite, "Parenthesis #2", tc_paren2, NULL, NULL, NULL);
   LCUT_TS_ADD(suite);

   LCUT_TEST_RUN();
   LCUT_TEST_REPORT();
   LCUT_TEST_END();

   LCUT_TEST_RESULT();
}

