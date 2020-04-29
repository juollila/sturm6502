#include "lcut.h"
#include "string.h"
extern void parse_line(void);
extern void init(void);
extern char line[];
extern unsigned char unit_obj[];
extern unsigned int PC;
extern unsigned char unit_asm_fails;
extern unsigned char column;

void tc_adc1(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "ADC #$44\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x69, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x44, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_adc2(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "ADC $32\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x65, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_adc3(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "ADC $32,X\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x75, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_adc4(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "ADC $3200\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x6d, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x00, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[2]);
    LCUT_INT_EQUAL(tc, 0x03, PC);
}

void tc_adc5(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "ADC $3200,X\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x7d, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x00, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[2]);
    LCUT_INT_EQUAL(tc, 0x03, PC);
}

void tc_adc6(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "ADC $3200,Y\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x79, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x00, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[2]);
    LCUT_INT_EQUAL(tc, 0x03, PC);
}

void tc_adc7(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "ADC ($32,X)\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x61, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_adc8(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "ADC ($32),Y\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x71, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_and1(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "AND #$44\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x29, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x44, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_and2(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "AND $32\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x25, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_and3(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "AND $32,X\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x35, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_and4(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "AND $3200\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x2d, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x00, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[2]);
    LCUT_INT_EQUAL(tc, 0x03, PC);
}

void tc_and5(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "AND $3200,X\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x3d, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x00, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[2]);
    LCUT_INT_EQUAL(tc, 0x03, PC);
}

void tc_and6(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "AND $3200,Y\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x39, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x00, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[2]);
    LCUT_INT_EQUAL(tc, 0x03, PC);
}

void tc_and7(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "AND ($32,X)\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x21, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_and8(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "AND ($32),Y\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x31, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_asl1(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "ASL A\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x0a, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x01, PC);
}

void tc_asl2(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "ASL $32\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x06, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_asl3(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "ASL $32,X\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x16, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_asl4(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "ASL $3200\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x0e, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x00, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[2]);
    LCUT_INT_EQUAL(tc, 0x03, PC);
}

void tc_asl5(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "ASL $3200,X\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x1e, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x00, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[2]);
    LCUT_INT_EQUAL(tc, 0x03, PC);
}

void tc_bit1(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "BIT $32\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x24, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_bit2(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "BIT $3200\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x2c, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x00, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[2]);
    LCUT_INT_EQUAL(tc, 0x03, PC);
}

void tc_bpl(lcut_tc_t *tc, void *data) {
    init();
    PC=0xc00a;
    strcpy(&line[0], "BPL $C000\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x10, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0xf4, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0xc00c, PC);
}

void tc_bmi(lcut_tc_t *tc, void *data) {
    init();
    PC=0xc000;
    strcpy(&line[0], "BMI $C020\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x30, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x1e, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0xc002, PC);
}

void tc_bvc(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "BVC $0081\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x50, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x7f, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_bvs(lcut_tc_t *tc, void *data) {
    init();
    PC=0xc000;
    strcpy(&line[0], "BVS $BF82\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x70, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x80, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0xc002, PC);
}

void tc_bcc(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "BCC $0081\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x90, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x7f, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_bcs(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "BCS $0081\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xb0, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x7f, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_bne(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "BNE $0081\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xd0, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x7f, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_beq(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "BEQ $0081\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xf0, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x7f, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_brk(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "BRK\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x00, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x01, PC);
}

void tc_cmp1(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "CMP #$44\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xc9, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x44, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_cmp2(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "CMP $32\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xc5, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_cmp3(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "CMP $32,X\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xd5, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_cmp4(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "CMP $3200\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xcd, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x00, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[2]);
    LCUT_INT_EQUAL(tc, 0x03, PC);
}

void tc_cmp5(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "CMP $3200,X\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xdd, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x00, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[2]);
    LCUT_INT_EQUAL(tc, 0x03, PC);
}

void tc_cmp6(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "CMP $3200,Y\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xd9, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x00, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[2]);
    LCUT_INT_EQUAL(tc, 0x03, PC);
}

void tc_cmp7(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "CMP ($32,X)\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xc1, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_cmp8(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "CMP ($32),Y\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xd1, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_cpx1(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "CPX #$32\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xe0, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_cpx2(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "CPX $32\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xe4, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_cpx3(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "CPX $3200\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xec, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x00, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[2]);
    LCUT_INT_EQUAL(tc, 0x03, PC);
}

void tc_cpy1(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "CPY #$32\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xc0, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_cpy2(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "CPY $32\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xc4, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_cpy3(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "CPY $3200\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xcc, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x00, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[2]);
    LCUT_INT_EQUAL(tc, 0x03, PC);
}

void tc_dec1(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "DEC $32\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xc6, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_dec2(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "DEC $32,X\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xd6, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_dec3(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "DEC $3200\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xce, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x00, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[2]);
    LCUT_INT_EQUAL(tc, 0x03, PC);
}

void tc_dec4(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "DEC $3200,X\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xde, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x00, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[2]);
    LCUT_INT_EQUAL(tc, 0x03, PC);
}

void tc_clc(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "CLC\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x18, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x01, PC);
}

void tc_sec(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "SEC\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x38, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x01, PC);
}

void tc_cli(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "CLI\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x58, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x01, PC);
}

void tc_sei(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "SEI\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x78, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x01, PC);
}

void tc_clv(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "CLV\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xb8, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x01, PC);
}

void tc_cld(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "CLD\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xd8, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x01, PC);
}

void tc_sed(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "SED\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xf8, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x01, PC);
}

void tc_inc1(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "INC $32\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xe6, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_inc2(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "INC $32,X\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xf6, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_inc3(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "INC $3200\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xee, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x00, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[2]);
    LCUT_INT_EQUAL(tc, 0x03, PC);
}

void tc_inc4(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "INC $3200,X\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xfe, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x00, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[2]);
    LCUT_INT_EQUAL(tc, 0x03, PC);
}

void tc_jmp1(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "JMP $FFD2\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x4c, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0xd2, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0xff, unit_obj[2]);
    LCUT_INT_EQUAL(tc, 0x03, PC);
}

void tc_jmp2(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "JMP ($FFD2)\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x6c, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0xd2, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0xff, unit_obj[2]);
    LCUT_INT_EQUAL(tc, 0x03, PC);
}

void tc_jsr1(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "JSR $3200\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x20, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x00, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[2]);
    LCUT_INT_EQUAL(tc, 0x03, PC);
}

void tc_lda1(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "LDA #$44\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xa9, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x44, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_lda2(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "LDA $32\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xa5, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_lda3(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "LDA $32,X\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xb5, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_lda4(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "LDA $3200\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xad, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x00, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[2]);
    LCUT_INT_EQUAL(tc, 0x03, PC);
}

void tc_lda5(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "LDA $3200,X\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xbd, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x00, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[2]);
    LCUT_INT_EQUAL(tc, 0x03, PC);
}

void tc_lda6(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "LDA $3200,Y\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xb9, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x00, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[2]);
    LCUT_INT_EQUAL(tc, 0x03, PC);
}

void tc_lda7(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "LDA ($32,X)\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xa1, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_lda8(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "LDA ($32),Y\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xb1, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_ldx1(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "LDX #$32\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xa2, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_ldx2(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "LDX $32\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xa6, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_ldx3(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "LDX $32,Y\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xb6, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_ldx4(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "LDX $3200\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xae, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x00, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[2]);
    LCUT_INT_EQUAL(tc, 0x03, PC);
}

void tc_ldx5(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "LDX $3200,Y\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xbe, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x00, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[2]);
    LCUT_INT_EQUAL(tc, 0x03, PC);
}

void tc_ldy1(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "LDY #$32\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xa0, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_ldy2(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "LDY $32\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xa4, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_ldy3(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "LDY $32,X\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xb4, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_ldy4(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "LDY $3200\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xac, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x00, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[2]);
    LCUT_INT_EQUAL(tc, 0x03, PC);
}

void tc_ldy5(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "LDY $3200,X\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xbc, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x00, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[2]);
    LCUT_INT_EQUAL(tc, 0x03, PC);
}

void tc_lsr1(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "LSR\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x4a, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x01, PC);
}

void tc_lsr2(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "LSR $32\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x46, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_lsr3(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "LSR $32,X\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x56, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_lsr4(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "LSR $3200\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x4e, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x00, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[2]);
    LCUT_INT_EQUAL(tc, 0x03, PC);
}

void tc_lsr5(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "LSR $3200,X\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x5e, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x00, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[2]);
    LCUT_INT_EQUAL(tc, 0x03, PC);
}

void tc_nop(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "NOP\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xea, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x01, PC);
}

void tc_ora1(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "ORA #$44\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x09, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x44, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_ora2(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "ORA $32\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x05, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_ora3(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "ORA $32,X\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x15, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_ora4(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "ORA $3200\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x0d, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x00, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[2]);
    LCUT_INT_EQUAL(tc, 0x03, PC);
}

void tc_ora5(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "ORA $3200,X\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x1d, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x00, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[2]);
    LCUT_INT_EQUAL(tc, 0x03, PC);
}

void tc_ora6(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "ORA $3200,Y\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x19, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x00, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[2]);
    LCUT_INT_EQUAL(tc, 0x03, PC);
}

void tc_ora7(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "ORA ($32,X)\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x01, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_ora8(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "ORA ($32),Y\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x11, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_tax(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "TAX\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xaa, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x01, PC);
}

void tc_txa(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "TXA\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x8a, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x01, PC);
}

void tc_dex(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "DEX\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xca, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x01, PC);
}

void tc_inx(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "INX\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xe8, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x01, PC);
}

void tc_tay(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "TAY\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xa8, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x01, PC);
}

void tc_tya(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "TYA\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x98, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x01, PC);
}

void tc_dey(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "DEY\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x88, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x01, PC);
}

void tc_iny(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "INY\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xc8, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x01, PC);
}

void tc_rol1(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "ROL\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x2a, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x01, PC);
}

void tc_rol2(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "ROL $32\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x26, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_rol3(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "ROL $32,X\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x36, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_rol4(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "ROL $3200\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x2e, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x00, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[2]);
    LCUT_INT_EQUAL(tc, 0x03, PC);
}

void tc_rol5(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "ROL $3200,X\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x3e, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x00, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[2]);
    LCUT_INT_EQUAL(tc, 0x03, PC);
}

void tc_ror1(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "ROR\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x6a, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x01, PC);
}

void tc_ror2(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "ROR $32\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x66, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_ror3(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "ROR $32,X\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x76, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_ror4(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "ROR $3200\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x6e, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x00, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[2]);
    LCUT_INT_EQUAL(tc, 0x03, PC);
}

void tc_ror5(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "ROR $3200,X\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x7e, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x00, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[2]);
    LCUT_INT_EQUAL(tc, 0x03, PC);
}

void tc_rti(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "RTI\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x40, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x01, PC);
}

void tc_rts(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "RTS\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x60, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x01, PC);
}

void tc_sbc1(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "SBC #$44\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xe9, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x44, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_sbc2(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "SBC $32\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xe5, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_sbc3(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "SBC $32,X\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xf5, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_sbc4(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "SBC $3200\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xed, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x00, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[2]);
    LCUT_INT_EQUAL(tc, 0x03, PC);
}

void tc_sbc5(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "SBC $3200,X\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xfd, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x00, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[2]);
    LCUT_INT_EQUAL(tc, 0x03, PC);
}

void tc_sbc6(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "SBC $3200,Y\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xf9, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x00, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[2]);
    LCUT_INT_EQUAL(tc, 0x03, PC);
}

void tc_sbc7(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "SBC ($32,X)\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xe1, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_sbc8(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "SBC ($32),Y\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xf1, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_sta1(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "STA $32\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x85, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_sta2(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "STA $32,X\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x95, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_sta3(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "STA $3200\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x8d, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x00, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[2]);
    LCUT_INT_EQUAL(tc, 0x03, PC);
}

void tc_sta4(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "STA $3200,X\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x9d, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x00, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[2]);
    LCUT_INT_EQUAL(tc, 0x03, PC);
}

void tc_sta5(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "STA $3200,Y\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x99, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x00, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[2]);
    LCUT_INT_EQUAL(tc, 0x03, PC);
}

void tc_sta6(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "STA ($32,X)\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x81, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_sta7(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "STA ($32),Y\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x91, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_txs(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "TXS\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x9a, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x01, PC);
}

void tc_tsx(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "TSX\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0xba, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x01, PC);
}

void tc_pha(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "PHA\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x48, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x01, PC);
}

void tc_pla(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "PLA\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x68, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x01, PC);
}

void tc_php(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "PHP\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x08, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x01, PC);
}

void tc_plp(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "PLP\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x28, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x01, PC);
}

void tc_stx1(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "STX $32\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x86, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_stx2(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "STX $32,Y\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x96, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_stx3(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "STX $3200\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x8e, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x00, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[2]);
    LCUT_INT_EQUAL(tc, 0x03, PC);
}

void tc_sty1(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "STY $32\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x84, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_sty2(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "STY $32,X\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x94, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x02, PC);
}

void tc_sty3(lcut_tc_t *tc, void *data) {
    init();
    strcpy(&line[0], "STY $3200\n");
    parse_line();
    LCUT_INT_EQUAL(tc, 0x8c, unit_obj[0]);
    LCUT_INT_EQUAL(tc, 0x00, unit_obj[1]);
    LCUT_INT_EQUAL(tc, 0x32, unit_obj[2]);
    LCUT_INT_EQUAL(tc, 0x03, PC);
}

int main() {
    lcut_ts_t   *suite = NULL;
    LCUT_TEST_BEGIN("Sturm6502 macro assembler", NULL, NULL);

    LCUT_TS_INIT(suite, "ADC", NULL, NULL);
    LCUT_TC_ADD(suite, "ADC #1", tc_adc1, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "ADC #2", tc_adc2, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "ADC #3", tc_adc3, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "ADC #4", tc_adc4, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "ADC #5", tc_adc5, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "ADC #6", tc_adc6, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "ADC #7", tc_adc7, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "ADC #8", tc_adc8, NULL, NULL, NULL);
    LCUT_TS_ADD(suite);

    LCUT_TS_INIT(suite, "AND", NULL, NULL);
    LCUT_TC_ADD(suite, "AND #1", tc_and1, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "AND #2", tc_and2, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "AND #3", tc_and3, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "AND #4", tc_and4, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "AND #5", tc_and5, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "AND #6", tc_and6, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "AND #7", tc_and7, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "AND #8", tc_and8, NULL, NULL, NULL);
    LCUT_TS_ADD(suite);

    LCUT_TS_INIT(suite, "ASL", NULL, NULL);
    LCUT_TC_ADD(suite, "ASL #1", tc_asl1, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "ASL #2", tc_asl2, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "ASL #3", tc_asl3, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "ASL #4", tc_asl4, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "ASL #5", tc_asl5, NULL, NULL, NULL);
    LCUT_TS_ADD(suite);

    LCUT_TS_INIT(suite, "BIT", NULL, NULL);
    LCUT_TC_ADD(suite, "BIT #1", tc_bit1, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "BIT #2", tc_bit2, NULL, NULL, NULL);
    LCUT_TS_ADD(suite);

    LCUT_TS_INIT(suite, "BRANCH", NULL, NULL);
    LCUT_TC_ADD(suite, "BPL", tc_bpl, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "BMI", tc_bmi, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "BVC", tc_bvc, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "BVS", tc_bvs, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "BCC", tc_bcc, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "BCS", tc_bcs, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "BNE", tc_bne, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "BEQ", tc_beq, NULL, NULL, NULL);
    LCUT_TS_ADD(suite);

    LCUT_TS_INIT(suite, "BRK", NULL, NULL);
    LCUT_TC_ADD(suite, "BRK", tc_brk, NULL, NULL, NULL);
    LCUT_TS_ADD(suite);

    LCUT_TS_INIT(suite, "CMP", NULL, NULL);
    LCUT_TC_ADD(suite, "CMP #1", tc_cmp1, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "CMP #2", tc_cmp2, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "CMP #3", tc_cmp3, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "CMP #4", tc_cmp4, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "CMP #5", tc_cmp5, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "CMP #6", tc_cmp6, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "CMP #7", tc_cmp7, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "CMP #8", tc_cmp8, NULL, NULL, NULL);
    LCUT_TS_ADD(suite);

    LCUT_TS_INIT(suite, "CPX", NULL, NULL);
    LCUT_TC_ADD(suite, "CPX #1", tc_cpx1, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "CPX #2", tc_cpx2, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "CPX #3", tc_cpx3, NULL, NULL, NULL);
    LCUT_TS_ADD(suite);

    LCUT_TS_INIT(suite, "CPY", NULL, NULL);
    LCUT_TC_ADD(suite, "CPY #1", tc_cpy1, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "CPY #2", tc_cpy2, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "CPY #3", tc_cpy3, NULL, NULL, NULL);
    LCUT_TS_ADD(suite);

    LCUT_TS_INIT(suite, "DEC", NULL, NULL);
    LCUT_TC_ADD(suite, "DEC #1", tc_dec1, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "DEC #2", tc_dec2, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "DEC #3", tc_dec3, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "DEC #4", tc_dec4, NULL, NULL, NULL);
    LCUT_TS_ADD(suite);

    LCUT_TS_INIT(suite, "FLAG", NULL, NULL);
    LCUT_TC_ADD(suite, "CLC", tc_clc, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "SEC", tc_sec, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "CLI", tc_cli, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "SEI", tc_sei, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "CLV", tc_clv, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "CLD", tc_cld, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "SED", tc_sed, NULL, NULL, NULL);
    LCUT_TS_ADD(suite);

    LCUT_TS_INIT(suite, "INC", NULL, NULL);
    LCUT_TC_ADD(suite, "INC #1", tc_inc1, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "INC #2", tc_inc2, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "INC #3", tc_inc3, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "INC #4", tc_inc4, NULL, NULL, NULL);
    LCUT_TS_ADD(suite);

    LCUT_TS_INIT(suite, "JMP", NULL, NULL);
    LCUT_TC_ADD(suite, "JMP #1", tc_jmp1, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "JMP #2", tc_jmp2, NULL, NULL, NULL);
    LCUT_TS_ADD(suite);

    LCUT_TS_INIT(suite, "JSR", NULL, NULL);
    LCUT_TC_ADD(suite, "JSR #1", tc_jsr1, NULL, NULL, NULL);
    LCUT_TS_ADD(suite);

    LCUT_TS_INIT(suite, "LDA", NULL, NULL);
    LCUT_TC_ADD(suite, "LDA #1", tc_lda1, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "LDA #2", tc_lda2, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "LDA #3", tc_lda3, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "LDA #4", tc_lda4, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "LDA #5", tc_lda5, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "LDA #6", tc_lda6, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "LDA #7", tc_lda7, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "LDA #8", tc_lda8, NULL, NULL, NULL);
    LCUT_TS_ADD(suite);

    LCUT_TS_INIT(suite, "LDX", NULL, NULL);
    LCUT_TC_ADD(suite, "LDX #1", tc_ldx1, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "LDX #2", tc_ldx2, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "LDX #3", tc_ldx3, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "LDX #4", tc_ldx4, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "LDX #5", tc_ldx5, NULL, NULL, NULL);
    LCUT_TS_ADD(suite);

    LCUT_TS_INIT(suite, "LDY", NULL, NULL);
    LCUT_TC_ADD(suite, "LDY #1", tc_ldy1, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "LDY #2", tc_ldy2, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "LDY #3", tc_ldy3, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "LDY #4", tc_ldy4, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "LDY #5", tc_ldy5, NULL, NULL, NULL);
    LCUT_TS_ADD(suite);

    LCUT_TS_INIT(suite, "LSR", NULL, NULL);
    LCUT_TC_ADD(suite, "LSR #1", tc_lsr1, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "LSR #2", tc_lsr2, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "LSR #3", tc_lsr3, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "LSR #4", tc_lsr4, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "LSR #5", tc_lsr5, NULL, NULL, NULL);
    LCUT_TS_ADD(suite);

    LCUT_TS_INIT(suite, "NOP", NULL, NULL);
    LCUT_TC_ADD(suite, "NOP #1", tc_nop, NULL, NULL, NULL);
    LCUT_TS_ADD(suite);

    LCUT_TS_INIT(suite, "ORA", NULL, NULL);
    LCUT_TC_ADD(suite, "ORA #1", tc_ora1, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "ORA #2", tc_ora2, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "ORA #3", tc_ora3, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "ORA #4", tc_ora4, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "ORA #5", tc_ora5, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "ORA #6", tc_ora6, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "ORA #7", tc_ora7, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "ORA #8", tc_ora8, NULL, NULL, NULL);
    LCUT_TS_ADD(suite);

    LCUT_TS_INIT(suite, "REGISTER", NULL, NULL);
    LCUT_TC_ADD(suite, "TAX", tc_tax, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "TXA", tc_txa, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "DEX", tc_dex, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "INX", tc_inx, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "TAY", tc_tay, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "TYA", tc_tya, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "DEY", tc_dey, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "INY", tc_iny, NULL, NULL, NULL);
    LCUT_TS_ADD(suite);

    LCUT_TS_INIT(suite, "ROL", NULL, NULL);
    LCUT_TC_ADD(suite, "ROL #1", tc_rol1, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "ROL #2", tc_rol2, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "ROL #3", tc_rol3, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "ROL #4", tc_rol4, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "ROL #5", tc_rol5, NULL, NULL, NULL);
    LCUT_TS_ADD(suite);

    LCUT_TS_INIT(suite, "ROR", NULL, NULL);
    LCUT_TC_ADD(suite, "ROR #1", tc_ror1, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "ROR #2", tc_ror2, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "ROR #3", tc_ror3, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "ROR #4", tc_ror4, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "ROR #5", tc_ror5, NULL, NULL, NULL);
    LCUT_TS_ADD(suite);

    LCUT_TS_INIT(suite, "RTI", NULL, NULL);
    LCUT_TC_ADD(suite, "RTI #1", tc_rti, NULL, NULL, NULL);
    LCUT_TS_ADD(suite);

    LCUT_TS_INIT(suite, "RTS", NULL, NULL);
    LCUT_TC_ADD(suite, "RTS #1", tc_rts, NULL, NULL, NULL);
    LCUT_TS_ADD(suite);

    LCUT_TS_INIT(suite, "SBC", NULL, NULL);
    LCUT_TC_ADD(suite, "SBC #1", tc_sbc1, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "SBC #2", tc_sbc2, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "SBC #3", tc_sbc3, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "SBC #4", tc_sbc4, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "SBC #5", tc_sbc5, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "SBC #6", tc_sbc6, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "SBC #7", tc_sbc7, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "SBC #8", tc_sbc8, NULL, NULL, NULL);
    LCUT_TS_ADD(suite);

    LCUT_TS_INIT(suite, "STA", NULL, NULL);
    LCUT_TC_ADD(suite, "STA #1", tc_sta1, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "STA #2", tc_sta2, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "STA #3", tc_sta3, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "STA #4", tc_sta4, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "STA #5", tc_sta5, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "STA #6", tc_sta6, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "STA #7", tc_sta7, NULL, NULL, NULL);
    LCUT_TS_ADD(suite);

    LCUT_TS_INIT(suite, "STACK", NULL, NULL);
    LCUT_TC_ADD(suite, "TXS", tc_txs, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "TSX", tc_tsx, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "PHA", tc_pha, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "PLA", tc_pla, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "PHP", tc_php, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "PLP", tc_plp, NULL, NULL, NULL);
    LCUT_TS_ADD(suite);

    LCUT_TS_INIT(suite, "STX", NULL, NULL);
    LCUT_TC_ADD(suite, "STX #1", tc_stx1, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "STX #2", tc_stx2, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "STX #3", tc_stx3, NULL, NULL, NULL);
    LCUT_TS_ADD(suite);

    LCUT_TS_INIT(suite, "STY", NULL, NULL);
    LCUT_TC_ADD(suite, "STY #1", tc_sty1, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "STY #2", tc_sty2, NULL, NULL, NULL);
    LCUT_TC_ADD(suite, "STY #3", tc_sty3, NULL, NULL, NULL);
    LCUT_TS_ADD(suite);

    LCUT_TEST_RUN();
    LCUT_TEST_REPORT();
    LCUT_TEST_END();

    LCUT_TEST_RESULT();
}

