#include "lcut.h"
#include "string.h"
extern void parse_line(void);
extern void init(void);
extern char line[];
extern char cline[];
extern unsigned char unit_obj[];
extern unsigned char column;
extern unsigned int PC;

void tc_byte1(lcut_tc_t *tc, void *data) {
   init();
   strcpy(&line[0], ".BYTE \"STURM6502\"\n");
   parse_line();
   LCUT_INT_EQUAL(tc, '2', unit_obj[0]);
   LCUT_INT_EQUAL(tc, 0x09, PC);
}

void tc_byte2(lcut_tc_t *tc, void *data) {
   init();
   strcpy(&line[0], ".BYTE $AA, $BB\n");
   parse_line();
   LCUT_INT_EQUAL(tc, 0xbb, unit_obj[0]);
   LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_byte3(lcut_tc_t *tc, void *data) {
   init();
   strcpy(&line[0], ".BYTE '3'\n");
   parse_line();
   LCUT_INT_EQUAL(tc, '3', unit_obj[0]);
   LCUT_INT_EQUAL(tc, 0x01, PC);
}

void tc_word1(lcut_tc_t *tc, void *data) {
   init();
   strcpy(&line[0], ".WORD $1234, $ABCD\n");
   parse_line();
   LCUT_INT_EQUAL(tc, 0xcd, unit_obj[0]);
   LCUT_INT_EQUAL(tc, 0xab, unit_obj[1]);
   LCUT_INT_EQUAL(tc, 0x04, PC);
}

void tc_word2(lcut_tc_t *tc, void *data) {
   init();
   strcpy(&line[0], ".WORD 9\n");
   parse_line();
   LCUT_INT_EQUAL(tc, 0x09, unit_obj[0]);
   LCUT_INT_EQUAL(tc, 0x00, unit_obj[1]);
   LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_org1(lcut_tc_t *tc, void *data) {
   init();
   strcpy(&line[0], ".ORG 49152\n");
   parse_line();
   LCUT_INT_EQUAL(tc, 0xc000, PC);
}

void tc_if1(lcut_tc_t *tc, void *data) {
   init();
   strcpy(&line[0], ".IF 5 * 0\n");
   parse_line();
   strcpy(&line[0], "NOP\n");
   column = 0;
   parse_line();
   strcpy(&line[0], ".ENDIF\n");
   column = 0;
   parse_line();
   LCUT_INT_EQUAL(tc, 0x00, PC);
}

void tc_if2(lcut_tc_t *tc, void *data) {
   init();
   strcpy(&line[0], ".IF 5 * 1\n");
   parse_line();
   strcpy(&line[0], "BRK\n");
   column = 0;
   parse_line();
   strcpy(&line[0], ".ENDIF\n");
   column = 0;
   parse_line();
   LCUT_INT_EQUAL(tc, 0x01, PC);
}

void tc_if3(lcut_tc_t *tc, void *data) {
   init();
   strcpy(&line[0], ".IF 5 * 0\n");
   parse_line();
   strcpy(&line[0], "NOP\n");
   column = 0;
   parse_line();
   strcpy(&line[0], ".ELSE\n");
   column = 0;
   parse_line();
   strcpy(&line[0], "LDA #1\n");
   column = 0;
   parse_line();
   strcpy(&line[0], ".ENDIF\n");
   column = 0;
   parse_line();
   LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_if4(lcut_tc_t *tc, void *data) {
   init();
   strcpy(&line[0], ".IF 1\n");
   parse_line();
   strcpy(&line[0], "NOP\n");
   column = 0;
   parse_line();
   strcpy(&line[0], ".ELSE\n");
   column = 0;
   parse_line();
   strcpy(&line[0], "LDA #1\n");
   column = 0;
   parse_line();
   strcpy(&line[0], ".ENDIF\n");
   column = 0;
   parse_line();
   LCUT_INT_EQUAL(tc, 0x01, PC);
}

void tc_ifdef1(lcut_tc_t *tc, void *data) {
   init();
   strcpy(&line[0], ".IFDEF FOOBAR\n");
   parse_line();
   strcpy(&line[0], "NOP\n");
   column = 0;
   parse_line();
   strcpy(&line[0], ".ELSE\n");
   column = 0;
   parse_line();
   strcpy(&line[0], "LDA #1\n");
   column = 0;
   parse_line();
   strcpy(&line[0], ".ENDIF\n");
   column = 0;
   parse_line();
   LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_ifdef2(lcut_tc_t *tc, void *data) {
   init();
   strcpy(&line[0], "FOOBAR = 1\n");
   column = 0;
   parse_line();
   strcpy(&line[0], ".IFDEF FOOBAR\n");
   column = 0;
   parse_line();
   strcpy(&line[0], "NOP\n");
   column = 0;
   parse_line();
   strcpy(&line[0], ".ELSE\n");
   column = 0;
   parse_line();
   strcpy(&line[0], "LDA #1\n");
   column = 0;
   parse_line();
   strcpy(&line[0], ".ENDIF\n");
   column = 0;
   parse_line();
   LCUT_INT_EQUAL(tc, 0x01, PC);
}

void tc_ifndef1(lcut_tc_t *tc, void *data) {
   init();
   strcpy(&line[0], ".IFNDEF FOOBAR\n");
   parse_line();
   strcpy(&line[0], "NOP\n");
   column = 0;
   parse_line();
   strcpy(&line[0], ".ELSE\n");
   column = 0;
   parse_line();
   strcpy(&line[0], "LDA #1\n");
   column = 0;
   parse_line();
   strcpy(&line[0], ".ENDIF\n");
   column = 0;
   parse_line();
   LCUT_INT_EQUAL(tc, 0x01, PC);
}

void tc_ifndef2(lcut_tc_t *tc, void *data) {
   init();
   strcpy(&line[0], "FOOBAR = 1\n");
   column = 0;
   parse_line();
   strcpy(&line[0], ".IFNDEF FOOBAR\n");
   column = 0;
   parse_line();
   strcpy(&line[0], "NOP\n");
   column = 0;
   parse_line();
   strcpy(&line[0], ".ELSE\n");
   column = 0;
   parse_line();
   strcpy(&line[0], "LDA #1\n");
   column = 0;
   parse_line();
   strcpy(&line[0], ".ENDIF\n");
   column = 0;
   parse_line();
   LCUT_INT_EQUAL(tc, 0x02, PC);
}

/* NOTE: Tests do not cover .incbin, .include, .mac or .endmac */

int main() {
   lcut_ts_t   *suite = NULL;
   LCUT_TEST_BEGIN("Sturm6502 macro assembler", NULL, NULL);

   LCUT_TS_INIT(suite, ".BYTE", NULL, NULL);
   LCUT_TC_ADD(suite, ".BYTE #1", tc_byte1, NULL, NULL, NULL);
   LCUT_TC_ADD(suite, ".BYTE #2", tc_byte2, NULL, NULL, NULL);
   LCUT_TC_ADD(suite, ".BYTE #2", tc_byte3, NULL, NULL, NULL);
   LCUT_TS_ADD(suite);

   LCUT_TS_INIT(suite, ".WORD", NULL, NULL);
   LCUT_TC_ADD(suite, ".WORD #1", tc_word1, NULL, NULL, NULL);
   LCUT_TC_ADD(suite, ".WORD #2", tc_word2, NULL, NULL, NULL);
   LCUT_TS_ADD(suite);

   LCUT_TS_INIT(suite, ".ORG", NULL, NULL);
   LCUT_TC_ADD(suite, ".ORG #1", tc_org1, NULL, NULL, NULL);
   LCUT_TS_ADD(suite);

   /* includes also .else and .endif */
   LCUT_TS_INIT(suite, ".IF", NULL, NULL);
   LCUT_TC_ADD(suite, ".IF #1", tc_if1, NULL, NULL, NULL);
   LCUT_TC_ADD(suite, ".IF #2", tc_if2, NULL, NULL, NULL);
   LCUT_TC_ADD(suite, ".IF #3", tc_if3, NULL, NULL, NULL);
   LCUT_TC_ADD(suite, ".IF #4", tc_if4, NULL, NULL, NULL);
   LCUT_TS_ADD(suite);

   LCUT_TS_INIT(suite, ".IFDEF", NULL, NULL);
   LCUT_TC_ADD(suite, ".IFDEF #1", tc_ifdef1, NULL, NULL, NULL);
   LCUT_TC_ADD(suite, ".IFDEF #2", tc_ifdef2, NULL, NULL, NULL);
   LCUT_TS_ADD(suite);

   LCUT_TS_INIT(suite, ".IFNDEF", NULL, NULL);
   LCUT_TC_ADD(suite, ".IFNDEF #1", tc_ifndef1, NULL, NULL, NULL);
   LCUT_TC_ADD(suite, ".IFNDEF #2", tc_ifndef2, NULL, NULL, NULL);
   LCUT_TS_ADD(suite);

   LCUT_TEST_RUN();
   LCUT_TEST_REPORT();
   LCUT_TEST_END();

   LCUT_TEST_RESULT();
}
