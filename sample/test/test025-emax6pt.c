#ifdef EMAXSC
/* EMAXSC start */
#ifndef UTYPEDEF
#define UTYPEDEF
typedef unsigned char      Uchar;
typedef unsigned short     Ushort;
typedef unsigned int       Uint;
typedef unsigned long long Ull;
typedef long long int      Sll;
#if __AARCH64EL__ == 1
typedef long double Dll;
#else
typedef struct {Ull u[2];} Dll;
#endif
#endif
#define EMAX_NCHIP 4
#define EMAX_DEPTH 64
#define EMAX_WIDTH 4
#define UNIT_WIDTH 4
Uint    uLOOP[EMAX_DEPTH][EMAX_NCHIP];
Ull     INIT1[EMAX_NCHIP], INIT0[EMAX_NCHIP];
struct  {Ull b[EMAX_NCHIP][EMAX_WIDTH],o[EMAX_NCHIP][EMAX_WIDTH],awoo[EMAX_NCHIP][EMAX_WIDTH],d[EMAX_NCHIP][EMAX_WIDTH][2];} SCM0[EMAX_DEPTH] __attribute__((aligned(64)));
struct  {Ull b[EMAX_NCHIP][EMAX_WIDTH],o[EMAX_NCHIP][EMAX_WIDTH],awoo[EMAX_NCHIP][EMAX_WIDTH],d[EMAX_NCHIP][EMAX_WIDTH][2];} SCM1[EMAX_DEPTH] __attribute__((aligned(64)));
struct  {Ull r[EMAX_NCHIP][EMAX_WIDTH];}                                                                                     SCAR[EMAX_DEPTH] __attribute__((aligned(64)));
struct  {Ull r[EMAX_NCHIP][2][EMAX_WIDTH*UNIT_WIDTH],enq[EMAX_NCHIP],d0[4],deq[EMAX_NCHIP],d1[4];}                           SCBR[EMAX_DEPTH] __attribute__((aligned(64)));
#undef  EMAX_NCHIP
#undef  EMAX_DEPTH
#undef  EMAX_WIDTH
#undef  UNIT_WIDTH
void emax6sc_pth_mm_00(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit0 */
uLOOP[0][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[0][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[0][CHIP]==0) continue;
if ((0 && SCBR[63].enq[CHIP]==SCBR[63].deq[CHIP]) || SCBR[0].enq[CHIP]!=SCBR[0].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[0][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[0][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[63].deq[CHIP] = 1-SCBR[63].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!1||(INIT1[CHIP]&&INIT0[CHIP])||((1&1)&&INIT0[CHIP]) ? SCBR[63].r[CHIP][SCBR[0].enq[CHIP]][3] : SCAR[0].r[CHIP][2], 0);
ex2 = exm(((1&2)&&INIT0[CHIP]) ? SCBR[63].r[CHIP][SCBR[0].enq[CHIP]][4] : 0, 0);
t2 = (ex1>>32&0x00000000ffffffffLL)+(ex2>>32&0x00000000ffffffffLL);
t2 &= 0x00000000ffffffffLL;
t0 = (ex1    &0x00000000ffffffffLL)+(ex2    &0x00000000ffffffffLL);
t0 &= 0x00000000ffffffffLL;
ex1_outd = (t2<<32)|(t0);
ex4 = 0==0 ? 0xffffffffffffffffLL : 0==1 ? SCBR[63].r[CHIP][SCBR[0].enq[CHIP]][4] : SCBR[63].r[CHIP][SCBR[0].enq[CHIP]][0];
ex2_outd = ex1_outd & ex4;
SCAR[0].r[CHIP][2] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!1||(INIT1[CHIP]&&INIT0[CHIP])||((2&1)&&INIT0[CHIP]) ? SCBR[63].r[CHIP][SCBR[0].enq[CHIP]][5] : SCAR[0].r[CHIP][3], 0);
ex2 = exm(((2&2)&&INIT0[CHIP]) ? SCBR[63].r[CHIP][SCBR[0].enq[CHIP]][6] : 0, 0);
t2 = (ex1>>32&0x00000000ffffffffLL)+(ex2>>32&0x00000000ffffffffLL);
t2 &= 0x00000000ffffffffLL;
t0 = (ex1    &0x00000000ffffffffLL)+(ex2    &0x00000000ffffffffLL);
t0 &= 0x00000000ffffffffLL;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[0].r[CHIP][3] = ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
}
{
}
{
SCBR[0].r[CHIP][SCBR[0].enq[CHIP]][10] = SCAR[0].r[CHIP][2];
}
{
SCBR[0].r[CHIP][SCBR[0].enq[CHIP]][14] = SCAR[0].r[CHIP][3];
}
uLOOP[0][CHIP]--;
SCBR[0].enq[CHIP] = 1-SCBR[0].enq[CHIP];
}
}
}
void emax6sc_pth_mm_01(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit1 */
uLOOP[1][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[1][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[1][CHIP]==0) continue;
if ((1 && SCBR[0].enq[CHIP]==SCBR[0].deq[CHIP]) || SCBR[1].enq[CHIP]!=SCBR[1].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[1][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[1][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[0].deq[CHIP] = 1-SCBR[0].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[1].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[1].r[CHIP][SCBR[1].enq[CHIP]][0]:SCM1[1].b[CHIP][0]) : SCM1[1].awoo[CHIP][0];
SCM1[1].o[CHIP][0] = eam(1 ? SCBR[1].r[CHIP][SCBR[1].enq[CHIP]][10] : SCM1[1].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[1].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[1].b[CHIP][0]:SCM1[1].awoo[CHIP][0]);
adr = (Ull)(SCM1[1].awoo[CHIP][0] + SCM1[1].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[1].r[CHIP][SCBR[1].enq[CHIP]][1] = SCM1[1].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[1].r[CHIP][SCBR[1].enq[CHIP]][1] = SCM1[1].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[1].r[CHIP][SCBR[1].enq[CHIP]][1] = SCM1[1].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[1].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[1].r[CHIP][SCBR[1].enq[CHIP]][0]:SCM0[1].b[CHIP][0]) : SCM0[1].awoo[CHIP][0];
SCM0[1].o[CHIP][0] = eam(1 ? SCBR[1].r[CHIP][SCBR[1].enq[CHIP]][10] : SCM0[1].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[1].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[1].b[CHIP][0]:SCM0[1].awoo[CHIP][0]);
adr = (Ull)(SCM0[1].awoo[CHIP][0] + SCM0[1].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[1].r[CHIP][SCBR[1].enq[CHIP]][0] = SCM0[1].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[1].r[CHIP][SCBR[1].enq[CHIP]][0] = SCM0[1].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[1].r[CHIP][SCBR[1].enq[CHIP]][0] = SCM0[1].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[1].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[1].r[CHIP][SCBR[1].enq[CHIP]][0]:SCM1[1].b[CHIP][1]) : SCM1[1].awoo[CHIP][1];
SCM1[1].o[CHIP][1] = eam(1 ? SCBR[1].r[CHIP][SCBR[1].enq[CHIP]][10] : SCM1[1].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[1].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[1].b[CHIP][1]:SCM1[1].awoo[CHIP][1]);
adr = (Ull)(SCM1[1].awoo[CHIP][1] + SCM1[1].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[1].r[CHIP][SCBR[1].enq[CHIP]][5] = SCM1[1].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[1].r[CHIP][SCBR[1].enq[CHIP]][5] = SCM1[1].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[1].r[CHIP][SCBR[1].enq[CHIP]][5] = SCM1[1].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[1].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[1].r[CHIP][SCBR[1].enq[CHIP]][0]:SCM0[1].b[CHIP][1]) : SCM0[1].awoo[CHIP][1];
SCM0[1].o[CHIP][1] = eam(1 ? SCBR[1].r[CHIP][SCBR[1].enq[CHIP]][10] : SCM0[1].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[1].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[1].b[CHIP][1]:SCM0[1].awoo[CHIP][1]);
adr = (Ull)(SCM0[1].awoo[CHIP][1] + SCM0[1].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[1].r[CHIP][SCBR[1].enq[CHIP]][4] = SCM0[1].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[1].r[CHIP][SCBR[1].enq[CHIP]][4] = SCM0[1].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[1].r[CHIP][SCBR[1].enq[CHIP]][4] = SCM0[1].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[0].r[CHIP][SCBR[1].enq[CHIP]][14] : SCAR[1].r[CHIP][0], 0);
ex2 = exm(((0&2)&&INIT0[CHIP]) ? SCBR[0].r[CHIP][SCBR[1].enq[CHIP]][10] : 0, 1);
t2 = (ex1>>32&0x00000000ffffffffLL)+(ex2>>32&0x00000000ffffffffLL);
t2 &= 0x00000000ffffffffLL;
t0 = (ex1    &0x00000000ffffffffLL)+(ex2    &0x00000000ffffffffLL);
t0 &= 0x00000000ffffffffLL;
ex1_outd = (t2<<32)|(t0);
ex4 = 0==0 ? 0x00000000ffffffffLL : 0==1 ? SCBR[0].r[CHIP][SCBR[1].enq[CHIP]][10] : SCBR[0].r[CHIP][SCBR[1].enq[CHIP]][0];
ex2_outd = ex1_outd & ex4;
SCAR[1].r[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[1].r[CHIP][SCBR[1].enq[CHIP]][2] = SCAR[1].r[CHIP][0];
}
{
SCBR[1].r[CHIP][SCBR[1].enq[CHIP]][6] = SCBR[0].r[CHIP][SCBR[10].enq[CHIP]][-1853690872];
}
{
}
{
}
uLOOP[1][CHIP]--;
SCBR[1].enq[CHIP] = 1-SCBR[1].enq[CHIP];
}
}
}
void emax6sc_pth_mm_02(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit2 */
uLOOP[2][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[2][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[2][CHIP]==0) continue;
if ((2 && SCBR[1].enq[CHIP]==SCBR[1].deq[CHIP]) || SCBR[2].enq[CHIP]!=SCBR[2].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[2][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[2][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[1].deq[CHIP] = 1-SCBR[1].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[2].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[2].r[CHIP][SCBR[2].enq[CHIP]][0]:SCM1[2].b[CHIP][0]) : SCM1[2].awoo[CHIP][0];
SCM1[2].o[CHIP][0] = eam(1 ? SCBR[2].r[CHIP][SCBR[2].enq[CHIP]][6] : SCM1[2].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[2].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[2].b[CHIP][0]:SCM1[2].awoo[CHIP][0]);
adr = (Ull)(SCM1[2].awoo[CHIP][0] + SCM1[2].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[2].r[CHIP][SCBR[2].enq[CHIP]][1] = SCM1[2].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[2].r[CHIP][SCBR[2].enq[CHIP]][1] = SCM1[2].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[2].r[CHIP][SCBR[2].enq[CHIP]][1] = SCM1[2].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[2].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[2].r[CHIP][SCBR[2].enq[CHIP]][0]:SCM0[2].b[CHIP][0]) : SCM0[2].awoo[CHIP][0];
SCM0[2].o[CHIP][0] = eam(1 ? SCBR[2].r[CHIP][SCBR[2].enq[CHIP]][6] : SCM0[2].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[2].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[2].b[CHIP][0]:SCM0[2].awoo[CHIP][0]);
adr = (Ull)(SCM0[2].awoo[CHIP][0] + SCM0[2].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[2].r[CHIP][SCBR[2].enq[CHIP]][0] = SCM0[2].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[2].r[CHIP][SCBR[2].enq[CHIP]][0] = SCM0[2].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[2].r[CHIP][SCBR[2].enq[CHIP]][0] = SCM0[2].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[2].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[2].r[CHIP][SCBR[2].enq[CHIP]][0]:SCM1[2].b[CHIP][1]) : SCM1[2].awoo[CHIP][1];
SCM1[2].o[CHIP][1] = eam(1 ? SCBR[2].r[CHIP][SCBR[2].enq[CHIP]][6] : SCM1[2].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[2].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[2].b[CHIP][1]:SCM1[2].awoo[CHIP][1]);
adr = (Ull)(SCM1[2].awoo[CHIP][1] + SCM1[2].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[2].r[CHIP][SCBR[2].enq[CHIP]][5] = SCM1[2].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[2].r[CHIP][SCBR[2].enq[CHIP]][5] = SCM1[2].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[2].r[CHIP][SCBR[2].enq[CHIP]][5] = SCM1[2].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[2].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[2].r[CHIP][SCBR[2].enq[CHIP]][0]:SCM0[2].b[CHIP][1]) : SCM0[2].awoo[CHIP][1];
SCM0[2].o[CHIP][1] = eam(1 ? SCBR[2].r[CHIP][SCBR[2].enq[CHIP]][6] : SCM0[2].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[2].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[2].b[CHIP][1]:SCM0[2].awoo[CHIP][1]);
adr = (Ull)(SCM0[2].awoo[CHIP][1] + SCM0[2].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[2].r[CHIP][SCBR[2].enq[CHIP]][4] = SCM0[2].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[2].r[CHIP][SCBR[2].enq[CHIP]][4] = SCM0[2].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[2].r[CHIP][SCBR[2].enq[CHIP]][4] = SCM0[2].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[1].r[CHIP][SCBR[2].enq[CHIP]][1] : SCAR[2].r[CHIP][0], 0);
ex2 = exm(((0&2)&&INIT0[CHIP]) ? SCBR[1].r[CHIP][SCBR[2].enq[CHIP]][3] : 0, 2);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32);
f0.f = f1.f * f2.f;
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2);
f0.f = f1.f * f2.f;
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[2].r[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[1].r[CHIP][SCBR[2].enq[CHIP]][0] : SCAR[2].r[CHIP][1], 0);
ex2 = exm(((0&2)&&INIT0[CHIP]) ? SCBR[1].r[CHIP][SCBR[2].enq[CHIP]][3] : 0, 2);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32);
f0.f = f1.f * f2.f;
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2);
f0.f = f1.f * f2.f;
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[2].r[CHIP][1] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[1].r[CHIP][SCBR[2].enq[CHIP]][5] : SCAR[2].r[CHIP][2], 0);
ex2 = exm(((0&2)&&INIT0[CHIP]) ? SCBR[1].r[CHIP][SCBR[2].enq[CHIP]][3] : 0, 2);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32);
f0.f = f1.f * f2.f;
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2);
f0.f = f1.f * f2.f;
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[2].r[CHIP][2] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[1].r[CHIP][SCBR[2].enq[CHIP]][4] : SCAR[2].r[CHIP][3], 0);
ex2 = exm(((0&2)&&INIT0[CHIP]) ? SCBR[1].r[CHIP][SCBR[2].enq[CHIP]][3] : 0, 2);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32);
f0.f = f1.f * f2.f;
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2);
f0.f = f1.f * f2.f;
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[2].r[CHIP][3] = ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[2].r[CHIP][SCBR[2].enq[CHIP]][3] = SCBR[1].r[CHIP][SCBR[6].enq[CHIP]][-1853690776];
}
{
SCBR[2].r[CHIP][SCBR[2].enq[CHIP]][7] = SCBR[1].r[CHIP][SCBR[2].enq[CHIP]][-1853690744];
}
{
}
{
}
uLOOP[2][CHIP]--;
SCBR[2].enq[CHIP] = 1-SCBR[2].enq[CHIP];
}
}
}
void emax6sc_pth_mm_03(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit3 */
uLOOP[3][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[3][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[3][CHIP]==0) continue;
if ((3 && SCBR[2].enq[CHIP]==SCBR[2].deq[CHIP]) || SCBR[3].enq[CHIP]!=SCBR[3].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[3][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[3][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[2].deq[CHIP] = 1-SCBR[2].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[3].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[3].r[CHIP][SCBR[3].enq[CHIP]][0]:SCM1[3].b[CHIP][0]) : SCM1[3].awoo[CHIP][0];
SCM1[3].o[CHIP][0] = eam(1 ? SCBR[3].r[CHIP][SCBR[3].enq[CHIP]][3] : SCM1[3].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[3].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[3].b[CHIP][0]:SCM1[3].awoo[CHIP][0]);
adr = (Ull)(SCM1[3].awoo[CHIP][0] + SCM1[3].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[3].r[CHIP][SCBR[3].enq[CHIP]][1] = SCM1[3].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[3].r[CHIP][SCBR[3].enq[CHIP]][1] = SCM1[3].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[3].r[CHIP][SCBR[3].enq[CHIP]][1] = SCM1[3].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[3].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[3].r[CHIP][SCBR[3].enq[CHIP]][0]:SCM0[3].b[CHIP][0]) : SCM0[3].awoo[CHIP][0];
SCM0[3].o[CHIP][0] = eam(1 ? SCBR[3].r[CHIP][SCBR[3].enq[CHIP]][3] : SCM0[3].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[3].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[3].b[CHIP][0]:SCM0[3].awoo[CHIP][0]);
adr = (Ull)(SCM0[3].awoo[CHIP][0] + SCM0[3].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[3].r[CHIP][SCBR[3].enq[CHIP]][0] = SCM0[3].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[3].r[CHIP][SCBR[3].enq[CHIP]][0] = SCM0[3].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[3].r[CHIP][SCBR[3].enq[CHIP]][0] = SCM0[3].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[3].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[3].r[CHIP][SCBR[3].enq[CHIP]][0]:SCM1[3].b[CHIP][1]) : SCM1[3].awoo[CHIP][1];
SCM1[3].o[CHIP][1] = eam(1 ? SCBR[3].r[CHIP][SCBR[3].enq[CHIP]][3] : SCM1[3].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[3].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[3].b[CHIP][1]:SCM1[3].awoo[CHIP][1]);
adr = (Ull)(SCM1[3].awoo[CHIP][1] + SCM1[3].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[3].r[CHIP][SCBR[3].enq[CHIP]][5] = SCM1[3].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[3].r[CHIP][SCBR[3].enq[CHIP]][5] = SCM1[3].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[3].r[CHIP][SCBR[3].enq[CHIP]][5] = SCM1[3].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[3].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[3].r[CHIP][SCBR[3].enq[CHIP]][0]:SCM0[3].b[CHIP][1]) : SCM0[3].awoo[CHIP][1];
SCM0[3].o[CHIP][1] = eam(1 ? SCBR[3].r[CHIP][SCBR[3].enq[CHIP]][3] : SCM0[3].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[3].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[3].b[CHIP][1]:SCM0[3].awoo[CHIP][1]);
adr = (Ull)(SCM0[3].awoo[CHIP][1] + SCM0[3].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[3].r[CHIP][SCBR[3].enq[CHIP]][4] = SCM0[3].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[3].r[CHIP][SCBR[3].enq[CHIP]][4] = SCM0[3].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[3].r[CHIP][SCBR[3].enq[CHIP]][4] = SCM0[3].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[3].r[CHIP][SCBR[3].enq[CHIP]][2] = SCBR[2].r[CHIP][SCBR[3].enq[CHIP]][-1853690648];
SCBR[3].r[CHIP][SCBR[3].enq[CHIP]][3] = SCBR[2].r[CHIP][SCBR[7].enq[CHIP]][-1853690648];
}
{
}
{
}
{
}
uLOOP[3][CHIP]--;
SCBR[3].enq[CHIP] = 1-SCBR[3].enq[CHIP];
}
}
}
void emax6sc_pth_mm_04(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit4 */
uLOOP[4][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[4][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[4][CHIP]==0) continue;
if ((4 && SCBR[3].enq[CHIP]==SCBR[3].deq[CHIP]) || SCBR[4].enq[CHIP]!=SCBR[4].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[4][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[4][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[3].deq[CHIP] = 1-SCBR[3].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[4].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[4].r[CHIP][SCBR[4].enq[CHIP]][0]:SCM1[4].b[CHIP][0]) : SCM1[4].awoo[CHIP][0];
SCM1[4].o[CHIP][0] = eam(1 ? SCBR[4].r[CHIP][SCBR[4].enq[CHIP]][2] : SCM1[4].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[4].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[4].b[CHIP][0]:SCM1[4].awoo[CHIP][0]);
adr = (Ull)(SCM1[4].awoo[CHIP][0] + SCM1[4].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[4].r[CHIP][SCBR[4].enq[CHIP]][1] = SCM1[4].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[4].r[CHIP][SCBR[4].enq[CHIP]][1] = SCM1[4].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[4].r[CHIP][SCBR[4].enq[CHIP]][1] = SCM1[4].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[4].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[4].r[CHIP][SCBR[4].enq[CHIP]][0]:SCM0[4].b[CHIP][0]) : SCM0[4].awoo[CHIP][0];
SCM0[4].o[CHIP][0] = eam(1 ? SCBR[4].r[CHIP][SCBR[4].enq[CHIP]][2] : SCM0[4].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[4].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[4].b[CHIP][0]:SCM0[4].awoo[CHIP][0]);
adr = (Ull)(SCM0[4].awoo[CHIP][0] + SCM0[4].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[4].r[CHIP][SCBR[4].enq[CHIP]][0] = SCM0[4].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[4].r[CHIP][SCBR[4].enq[CHIP]][0] = SCM0[4].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[4].r[CHIP][SCBR[4].enq[CHIP]][0] = SCM0[4].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[4].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[4].r[CHIP][SCBR[4].enq[CHIP]][0]:SCM1[4].b[CHIP][1]) : SCM1[4].awoo[CHIP][1];
SCM1[4].o[CHIP][1] = eam(1 ? SCBR[4].r[CHIP][SCBR[4].enq[CHIP]][2] : SCM1[4].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[4].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[4].b[CHIP][1]:SCM1[4].awoo[CHIP][1]);
adr = (Ull)(SCM1[4].awoo[CHIP][1] + SCM1[4].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[4].r[CHIP][SCBR[4].enq[CHIP]][5] = SCM1[4].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[4].r[CHIP][SCBR[4].enq[CHIP]][5] = SCM1[4].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[4].r[CHIP][SCBR[4].enq[CHIP]][5] = SCM1[4].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[4].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[4].r[CHIP][SCBR[4].enq[CHIP]][0]:SCM0[4].b[CHIP][1]) : SCM0[4].awoo[CHIP][1];
SCM0[4].o[CHIP][1] = eam(1 ? SCBR[4].r[CHIP][SCBR[4].enq[CHIP]][2] : SCM0[4].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[4].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[4].b[CHIP][1]:SCM0[4].awoo[CHIP][1]);
adr = (Ull)(SCM0[4].awoo[CHIP][1] + SCM0[4].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[4].r[CHIP][SCBR[4].enq[CHIP]][4] = SCM0[4].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[4].r[CHIP][SCBR[4].enq[CHIP]][4] = SCM0[4].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[4].r[CHIP][SCBR[4].enq[CHIP]][4] = SCM0[4].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[4].r[CHIP][SCBR[4].enq[CHIP]][2] = SCBR[3].r[CHIP][SCBR[2].enq[CHIP]][-1853690520];
SCBR[4].r[CHIP][SCBR[4].enq[CHIP]][3] = SCBR[3].r[CHIP][SCBR[3].enq[CHIP]][-1853690520];
}
{
}
{
}
{
}
uLOOP[4][CHIP]--;
SCBR[4].enq[CHIP] = 1-SCBR[4].enq[CHIP];
}
}
}
void emax6sc_pth_mm_05(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit5 */
uLOOP[5][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[5][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[5][CHIP]==0) continue;
if ((5 && SCBR[4].enq[CHIP]==SCBR[4].deq[CHIP]) || SCBR[5].enq[CHIP]!=SCBR[5].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[5][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[5][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[4].deq[CHIP] = 1-SCBR[4].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[5].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[5].r[CHIP][SCBR[5].enq[CHIP]][0]:SCM1[5].b[CHIP][0]) : SCM1[5].awoo[CHIP][0];
SCM1[5].o[CHIP][0] = eam(1 ? SCBR[5].r[CHIP][SCBR[5].enq[CHIP]][2] : SCM1[5].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[5].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[5].b[CHIP][0]:SCM1[5].awoo[CHIP][0]);
adr = (Ull)(SCM1[5].awoo[CHIP][0] + SCM1[5].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[5].r[CHIP][SCBR[5].enq[CHIP]][1] = SCM1[5].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[5].r[CHIP][SCBR[5].enq[CHIP]][1] = SCM1[5].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[5].r[CHIP][SCBR[5].enq[CHIP]][1] = SCM1[5].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[5].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[5].r[CHIP][SCBR[5].enq[CHIP]][0]:SCM0[5].b[CHIP][0]) : SCM0[5].awoo[CHIP][0];
SCM0[5].o[CHIP][0] = eam(1 ? SCBR[5].r[CHIP][SCBR[5].enq[CHIP]][2] : SCM0[5].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[5].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[5].b[CHIP][0]:SCM0[5].awoo[CHIP][0]);
adr = (Ull)(SCM0[5].awoo[CHIP][0] + SCM0[5].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[5].r[CHIP][SCBR[5].enq[CHIP]][0] = SCM0[5].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[5].r[CHIP][SCBR[5].enq[CHIP]][0] = SCM0[5].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[5].r[CHIP][SCBR[5].enq[CHIP]][0] = SCM0[5].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[5].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[5].r[CHIP][SCBR[5].enq[CHIP]][0]:SCM1[5].b[CHIP][1]) : SCM1[5].awoo[CHIP][1];
SCM1[5].o[CHIP][1] = eam(1 ? SCBR[5].r[CHIP][SCBR[5].enq[CHIP]][2] : SCM1[5].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[5].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[5].b[CHIP][1]:SCM1[5].awoo[CHIP][1]);
adr = (Ull)(SCM1[5].awoo[CHIP][1] + SCM1[5].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[5].r[CHIP][SCBR[5].enq[CHIP]][5] = SCM1[5].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[5].r[CHIP][SCBR[5].enq[CHIP]][5] = SCM1[5].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[5].r[CHIP][SCBR[5].enq[CHIP]][5] = SCM1[5].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[5].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[5].r[CHIP][SCBR[5].enq[CHIP]][0]:SCM0[5].b[CHIP][1]) : SCM0[5].awoo[CHIP][1];
SCM0[5].o[CHIP][1] = eam(1 ? SCBR[5].r[CHIP][SCBR[5].enq[CHIP]][2] : SCM0[5].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[5].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[5].b[CHIP][1]:SCM0[5].awoo[CHIP][1]);
adr = (Ull)(SCM0[5].awoo[CHIP][1] + SCM0[5].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[5].r[CHIP][SCBR[5].enq[CHIP]][4] = SCM0[5].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[5].r[CHIP][SCBR[5].enq[CHIP]][4] = SCM0[5].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[5].r[CHIP][SCBR[5].enq[CHIP]][4] = SCM0[5].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[5].r[CHIP][SCBR[5].enq[CHIP]][2] = SCBR[4].r[CHIP][SCBR[2].enq[CHIP]][-1853690392];
SCBR[5].r[CHIP][SCBR[5].enq[CHIP]][3] = SCBR[4].r[CHIP][SCBR[3].enq[CHIP]][-1853690392];
}
{
}
{
}
{
}
uLOOP[5][CHIP]--;
SCBR[5].enq[CHIP] = 1-SCBR[5].enq[CHIP];
}
}
}
void emax6sc_pth_mm_06(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit6 */
uLOOP[6][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[6][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[6][CHIP]==0) continue;
if ((6 && SCBR[5].enq[CHIP]==SCBR[5].deq[CHIP]) || SCBR[6].enq[CHIP]!=SCBR[6].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[6][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[6][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[5].deq[CHIP] = 1-SCBR[5].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[6].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[6].r[CHIP][SCBR[6].enq[CHIP]][0]:SCM1[6].b[CHIP][0]) : SCM1[6].awoo[CHIP][0];
SCM1[6].o[CHIP][0] = eam(1 ? SCBR[6].r[CHIP][SCBR[6].enq[CHIP]][2] : SCM1[6].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[6].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[6].b[CHIP][0]:SCM1[6].awoo[CHIP][0]);
adr = (Ull)(SCM1[6].awoo[CHIP][0] + SCM1[6].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[6].r[CHIP][SCBR[6].enq[CHIP]][1] = SCM1[6].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[6].r[CHIP][SCBR[6].enq[CHIP]][1] = SCM1[6].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[6].r[CHIP][SCBR[6].enq[CHIP]][1] = SCM1[6].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[6].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[6].r[CHIP][SCBR[6].enq[CHIP]][0]:SCM0[6].b[CHIP][0]) : SCM0[6].awoo[CHIP][0];
SCM0[6].o[CHIP][0] = eam(1 ? SCBR[6].r[CHIP][SCBR[6].enq[CHIP]][2] : SCM0[6].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[6].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[6].b[CHIP][0]:SCM0[6].awoo[CHIP][0]);
adr = (Ull)(SCM0[6].awoo[CHIP][0] + SCM0[6].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[6].r[CHIP][SCBR[6].enq[CHIP]][0] = SCM0[6].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[6].r[CHIP][SCBR[6].enq[CHIP]][0] = SCM0[6].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[6].r[CHIP][SCBR[6].enq[CHIP]][0] = SCM0[6].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[6].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[6].r[CHIP][SCBR[6].enq[CHIP]][0]:SCM1[6].b[CHIP][1]) : SCM1[6].awoo[CHIP][1];
SCM1[6].o[CHIP][1] = eam(1 ? SCBR[6].r[CHIP][SCBR[6].enq[CHIP]][2] : SCM1[6].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[6].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[6].b[CHIP][1]:SCM1[6].awoo[CHIP][1]);
adr = (Ull)(SCM1[6].awoo[CHIP][1] + SCM1[6].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[6].r[CHIP][SCBR[6].enq[CHIP]][5] = SCM1[6].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[6].r[CHIP][SCBR[6].enq[CHIP]][5] = SCM1[6].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[6].r[CHIP][SCBR[6].enq[CHIP]][5] = SCM1[6].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[6].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[6].r[CHIP][SCBR[6].enq[CHIP]][0]:SCM0[6].b[CHIP][1]) : SCM0[6].awoo[CHIP][1];
SCM0[6].o[CHIP][1] = eam(1 ? SCBR[6].r[CHIP][SCBR[6].enq[CHIP]][2] : SCM0[6].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[6].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[6].b[CHIP][1]:SCM0[6].awoo[CHIP][1]);
adr = (Ull)(SCM0[6].awoo[CHIP][1] + SCM0[6].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[6].r[CHIP][SCBR[6].enq[CHIP]][4] = SCM0[6].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[6].r[CHIP][SCBR[6].enq[CHIP]][4] = SCM0[6].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[6].r[CHIP][SCBR[6].enq[CHIP]][4] = SCM0[6].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[6].r[CHIP][SCBR[6].enq[CHIP]][2] = SCBR[5].r[CHIP][SCBR[2].enq[CHIP]][-1853690264];
SCBR[6].r[CHIP][SCBR[6].enq[CHIP]][3] = SCBR[5].r[CHIP][SCBR[3].enq[CHIP]][-1853690264];
}
{
}
{
}
{
}
uLOOP[6][CHIP]--;
SCBR[6].enq[CHIP] = 1-SCBR[6].enq[CHIP];
}
}
}
void emax6sc_pth_mm_07(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit7 */
uLOOP[7][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[7][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[7][CHIP]==0) continue;
if ((7 && SCBR[6].enq[CHIP]==SCBR[6].deq[CHIP]) || SCBR[7].enq[CHIP]!=SCBR[7].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[7][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[7][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[6].deq[CHIP] = 1-SCBR[6].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[7].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[7].r[CHIP][SCBR[7].enq[CHIP]][0]:SCM1[7].b[CHIP][0]) : SCM1[7].awoo[CHIP][0];
SCM1[7].o[CHIP][0] = eam(1 ? SCBR[7].r[CHIP][SCBR[7].enq[CHIP]][2] : SCM1[7].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[7].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[7].b[CHIP][0]:SCM1[7].awoo[CHIP][0]);
adr = (Ull)(SCM1[7].awoo[CHIP][0] + SCM1[7].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[7].r[CHIP][SCBR[7].enq[CHIP]][1] = SCM1[7].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[7].r[CHIP][SCBR[7].enq[CHIP]][1] = SCM1[7].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[7].r[CHIP][SCBR[7].enq[CHIP]][1] = SCM1[7].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[7].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[7].r[CHIP][SCBR[7].enq[CHIP]][0]:SCM0[7].b[CHIP][0]) : SCM0[7].awoo[CHIP][0];
SCM0[7].o[CHIP][0] = eam(1 ? SCBR[7].r[CHIP][SCBR[7].enq[CHIP]][2] : SCM0[7].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[7].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[7].b[CHIP][0]:SCM0[7].awoo[CHIP][0]);
adr = (Ull)(SCM0[7].awoo[CHIP][0] + SCM0[7].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[7].r[CHIP][SCBR[7].enq[CHIP]][0] = SCM0[7].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[7].r[CHIP][SCBR[7].enq[CHIP]][0] = SCM0[7].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[7].r[CHIP][SCBR[7].enq[CHIP]][0] = SCM0[7].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[7].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[7].r[CHIP][SCBR[7].enq[CHIP]][0]:SCM1[7].b[CHIP][1]) : SCM1[7].awoo[CHIP][1];
SCM1[7].o[CHIP][1] = eam(1 ? SCBR[7].r[CHIP][SCBR[7].enq[CHIP]][2] : SCM1[7].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[7].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[7].b[CHIP][1]:SCM1[7].awoo[CHIP][1]);
adr = (Ull)(SCM1[7].awoo[CHIP][1] + SCM1[7].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[7].r[CHIP][SCBR[7].enq[CHIP]][5] = SCM1[7].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[7].r[CHIP][SCBR[7].enq[CHIP]][5] = SCM1[7].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[7].r[CHIP][SCBR[7].enq[CHIP]][5] = SCM1[7].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[7].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[7].r[CHIP][SCBR[7].enq[CHIP]][0]:SCM0[7].b[CHIP][1]) : SCM0[7].awoo[CHIP][1];
SCM0[7].o[CHIP][1] = eam(1 ? SCBR[7].r[CHIP][SCBR[7].enq[CHIP]][2] : SCM0[7].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[7].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[7].b[CHIP][1]:SCM0[7].awoo[CHIP][1]);
adr = (Ull)(SCM0[7].awoo[CHIP][1] + SCM0[7].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[7].r[CHIP][SCBR[7].enq[CHIP]][4] = SCM0[7].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[7].r[CHIP][SCBR[7].enq[CHIP]][4] = SCM0[7].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[7].r[CHIP][SCBR[7].enq[CHIP]][4] = SCM0[7].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[7].r[CHIP][SCBR[7].enq[CHIP]][2] = SCBR[6].r[CHIP][SCBR[2].enq[CHIP]][-1853690136];
SCBR[7].r[CHIP][SCBR[7].enq[CHIP]][3] = SCBR[6].r[CHIP][SCBR[3].enq[CHIP]][-1853690136];
}
{
}
{
}
{
}
uLOOP[7][CHIP]--;
SCBR[7].enq[CHIP] = 1-SCBR[7].enq[CHIP];
}
}
}
void emax6sc_pth_mm_08(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit8 */
uLOOP[8][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[8][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[8][CHIP]==0) continue;
if ((8 && SCBR[7].enq[CHIP]==SCBR[7].deq[CHIP]) || SCBR[8].enq[CHIP]!=SCBR[8].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[8][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[8][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[7].deq[CHIP] = 1-SCBR[7].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[8].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[8].r[CHIP][SCBR[8].enq[CHIP]][0]:SCM1[8].b[CHIP][0]) : SCM1[8].awoo[CHIP][0];
SCM1[8].o[CHIP][0] = eam(1 ? SCBR[8].r[CHIP][SCBR[8].enq[CHIP]][2] : SCM1[8].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[8].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[8].b[CHIP][0]:SCM1[8].awoo[CHIP][0]);
adr = (Ull)(SCM1[8].awoo[CHIP][0] + SCM1[8].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[8].r[CHIP][SCBR[8].enq[CHIP]][1] = SCM1[8].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[8].r[CHIP][SCBR[8].enq[CHIP]][1] = SCM1[8].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[8].r[CHIP][SCBR[8].enq[CHIP]][1] = SCM1[8].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[8].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[8].r[CHIP][SCBR[8].enq[CHIP]][0]:SCM0[8].b[CHIP][0]) : SCM0[8].awoo[CHIP][0];
SCM0[8].o[CHIP][0] = eam(1 ? SCBR[8].r[CHIP][SCBR[8].enq[CHIP]][2] : SCM0[8].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[8].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[8].b[CHIP][0]:SCM0[8].awoo[CHIP][0]);
adr = (Ull)(SCM0[8].awoo[CHIP][0] + SCM0[8].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[8].r[CHIP][SCBR[8].enq[CHIP]][0] = SCM0[8].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[8].r[CHIP][SCBR[8].enq[CHIP]][0] = SCM0[8].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[8].r[CHIP][SCBR[8].enq[CHIP]][0] = SCM0[8].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[8].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[8].r[CHIP][SCBR[8].enq[CHIP]][0]:SCM1[8].b[CHIP][1]) : SCM1[8].awoo[CHIP][1];
SCM1[8].o[CHIP][1] = eam(1 ? SCBR[8].r[CHIP][SCBR[8].enq[CHIP]][2] : SCM1[8].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[8].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[8].b[CHIP][1]:SCM1[8].awoo[CHIP][1]);
adr = (Ull)(SCM1[8].awoo[CHIP][1] + SCM1[8].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[8].r[CHIP][SCBR[8].enq[CHIP]][5] = SCM1[8].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[8].r[CHIP][SCBR[8].enq[CHIP]][5] = SCM1[8].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[8].r[CHIP][SCBR[8].enq[CHIP]][5] = SCM1[8].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[8].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[8].r[CHIP][SCBR[8].enq[CHIP]][0]:SCM0[8].b[CHIP][1]) : SCM0[8].awoo[CHIP][1];
SCM0[8].o[CHIP][1] = eam(1 ? SCBR[8].r[CHIP][SCBR[8].enq[CHIP]][2] : SCM0[8].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[8].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[8].b[CHIP][1]:SCM0[8].awoo[CHIP][1]);
adr = (Ull)(SCM0[8].awoo[CHIP][1] + SCM0[8].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[8].r[CHIP][SCBR[8].enq[CHIP]][4] = SCM0[8].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[8].r[CHIP][SCBR[8].enq[CHIP]][4] = SCM0[8].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[8].r[CHIP][SCBR[8].enq[CHIP]][4] = SCM0[8].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[8].r[CHIP][SCBR[8].enq[CHIP]][2] = SCBR[7].r[CHIP][SCBR[2].enq[CHIP]][-1853690008];
SCBR[8].r[CHIP][SCBR[8].enq[CHIP]][3] = SCBR[7].r[CHIP][SCBR[3].enq[CHIP]][-1853690008];
}
{
}
{
}
{
}
uLOOP[8][CHIP]--;
SCBR[8].enq[CHIP] = 1-SCBR[8].enq[CHIP];
}
}
}
void emax6sc_pth_mm_09(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit9 */
uLOOP[9][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[9][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[9][CHIP]==0) continue;
if ((9 && SCBR[8].enq[CHIP]==SCBR[8].deq[CHIP]) || SCBR[9].enq[CHIP]!=SCBR[9].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[9][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[9][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[8].deq[CHIP] = 1-SCBR[8].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[9].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[9].r[CHIP][SCBR[9].enq[CHIP]][0]:SCM1[9].b[CHIP][0]) : SCM1[9].awoo[CHIP][0];
SCM1[9].o[CHIP][0] = eam(1 ? SCBR[9].r[CHIP][SCBR[9].enq[CHIP]][2] : SCM1[9].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[9].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[9].b[CHIP][0]:SCM1[9].awoo[CHIP][0]);
adr = (Ull)(SCM1[9].awoo[CHIP][0] + SCM1[9].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[9].r[CHIP][SCBR[9].enq[CHIP]][1] = SCM1[9].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[9].r[CHIP][SCBR[9].enq[CHIP]][1] = SCM1[9].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[9].r[CHIP][SCBR[9].enq[CHIP]][1] = SCM1[9].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[9].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[9].r[CHIP][SCBR[9].enq[CHIP]][0]:SCM0[9].b[CHIP][0]) : SCM0[9].awoo[CHIP][0];
SCM0[9].o[CHIP][0] = eam(1 ? SCBR[9].r[CHIP][SCBR[9].enq[CHIP]][2] : SCM0[9].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[9].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[9].b[CHIP][0]:SCM0[9].awoo[CHIP][0]);
adr = (Ull)(SCM0[9].awoo[CHIP][0] + SCM0[9].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[9].r[CHIP][SCBR[9].enq[CHIP]][0] = SCM0[9].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[9].r[CHIP][SCBR[9].enq[CHIP]][0] = SCM0[9].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[9].r[CHIP][SCBR[9].enq[CHIP]][0] = SCM0[9].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[9].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[9].r[CHIP][SCBR[9].enq[CHIP]][0]:SCM1[9].b[CHIP][1]) : SCM1[9].awoo[CHIP][1];
SCM1[9].o[CHIP][1] = eam(1 ? SCBR[9].r[CHIP][SCBR[9].enq[CHIP]][2] : SCM1[9].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[9].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[9].b[CHIP][1]:SCM1[9].awoo[CHIP][1]);
adr = (Ull)(SCM1[9].awoo[CHIP][1] + SCM1[9].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[9].r[CHIP][SCBR[9].enq[CHIP]][5] = SCM1[9].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[9].r[CHIP][SCBR[9].enq[CHIP]][5] = SCM1[9].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[9].r[CHIP][SCBR[9].enq[CHIP]][5] = SCM1[9].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[9].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[9].r[CHIP][SCBR[9].enq[CHIP]][0]:SCM0[9].b[CHIP][1]) : SCM0[9].awoo[CHIP][1];
SCM0[9].o[CHIP][1] = eam(1 ? SCBR[9].r[CHIP][SCBR[9].enq[CHIP]][2] : SCM0[9].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[9].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[9].b[CHIP][1]:SCM0[9].awoo[CHIP][1]);
adr = (Ull)(SCM0[9].awoo[CHIP][1] + SCM0[9].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[9].r[CHIP][SCBR[9].enq[CHIP]][4] = SCM0[9].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[9].r[CHIP][SCBR[9].enq[CHIP]][4] = SCM0[9].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[9].r[CHIP][SCBR[9].enq[CHIP]][4] = SCM0[9].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[9].r[CHIP][SCBR[9].enq[CHIP]][2] = SCBR[8].r[CHIP][SCBR[2].enq[CHIP]][-1853689880];
SCBR[9].r[CHIP][SCBR[9].enq[CHIP]][3] = SCBR[8].r[CHIP][SCBR[3].enq[CHIP]][-1853689880];
}
{
}
{
}
{
}
uLOOP[9][CHIP]--;
SCBR[9].enq[CHIP] = 1-SCBR[9].enq[CHIP];
}
}
}
void emax6sc_pth_mm_10(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit10 */
uLOOP[10][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[10][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[10][CHIP]==0) continue;
if ((10 && SCBR[9].enq[CHIP]==SCBR[9].deq[CHIP]) || SCBR[10].enq[CHIP]!=SCBR[10].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[10][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[10][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[9].deq[CHIP] = 1-SCBR[9].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[10].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[10].r[CHIP][SCBR[10].enq[CHIP]][0]:SCM1[10].b[CHIP][0]) : SCM1[10].awoo[CHIP][0];
SCM1[10].o[CHIP][0] = eam(1 ? SCBR[10].r[CHIP][SCBR[10].enq[CHIP]][2] : SCM1[10].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[10].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[10].b[CHIP][0]:SCM1[10].awoo[CHIP][0]);
adr = (Ull)(SCM1[10].awoo[CHIP][0] + SCM1[10].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[10].r[CHIP][SCBR[10].enq[CHIP]][1] = SCM1[10].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[10].r[CHIP][SCBR[10].enq[CHIP]][1] = SCM1[10].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[10].r[CHIP][SCBR[10].enq[CHIP]][1] = SCM1[10].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[10].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[10].r[CHIP][SCBR[10].enq[CHIP]][0]:SCM0[10].b[CHIP][0]) : SCM0[10].awoo[CHIP][0];
SCM0[10].o[CHIP][0] = eam(1 ? SCBR[10].r[CHIP][SCBR[10].enq[CHIP]][2] : SCM0[10].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[10].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[10].b[CHIP][0]:SCM0[10].awoo[CHIP][0]);
adr = (Ull)(SCM0[10].awoo[CHIP][0] + SCM0[10].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[10].r[CHIP][SCBR[10].enq[CHIP]][0] = SCM0[10].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[10].r[CHIP][SCBR[10].enq[CHIP]][0] = SCM0[10].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[10].r[CHIP][SCBR[10].enq[CHIP]][0] = SCM0[10].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[10].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[10].r[CHIP][SCBR[10].enq[CHIP]][0]:SCM1[10].b[CHIP][1]) : SCM1[10].awoo[CHIP][1];
SCM1[10].o[CHIP][1] = eam(1 ? SCBR[10].r[CHIP][SCBR[10].enq[CHIP]][2] : SCM1[10].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[10].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[10].b[CHIP][1]:SCM1[10].awoo[CHIP][1]);
adr = (Ull)(SCM1[10].awoo[CHIP][1] + SCM1[10].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[10].r[CHIP][SCBR[10].enq[CHIP]][5] = SCM1[10].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[10].r[CHIP][SCBR[10].enq[CHIP]][5] = SCM1[10].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[10].r[CHIP][SCBR[10].enq[CHIP]][5] = SCM1[10].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[10].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[10].r[CHIP][SCBR[10].enq[CHIP]][0]:SCM0[10].b[CHIP][1]) : SCM0[10].awoo[CHIP][1];
SCM0[10].o[CHIP][1] = eam(1 ? SCBR[10].r[CHIP][SCBR[10].enq[CHIP]][2] : SCM0[10].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[10].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[10].b[CHIP][1]:SCM0[10].awoo[CHIP][1]);
adr = (Ull)(SCM0[10].awoo[CHIP][1] + SCM0[10].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[10].r[CHIP][SCBR[10].enq[CHIP]][4] = SCM0[10].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[10].r[CHIP][SCBR[10].enq[CHIP]][4] = SCM0[10].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[10].r[CHIP][SCBR[10].enq[CHIP]][4] = SCM0[10].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[10].r[CHIP][SCBR[10].enq[CHIP]][2] = SCBR[9].r[CHIP][SCBR[2].enq[CHIP]][-1853689752];
SCBR[10].r[CHIP][SCBR[10].enq[CHIP]][3] = SCBR[9].r[CHIP][SCBR[3].enq[CHIP]][-1853689752];
}
{
}
{
}
{
}
uLOOP[10][CHIP]--;
SCBR[10].enq[CHIP] = 1-SCBR[10].enq[CHIP];
}
}
}
void emax6sc_pth_mm_11(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit11 */
uLOOP[11][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[11][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[11][CHIP]==0) continue;
if ((11 && SCBR[10].enq[CHIP]==SCBR[10].deq[CHIP]) || SCBR[11].enq[CHIP]!=SCBR[11].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[11][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[11][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[10].deq[CHIP] = 1-SCBR[10].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[11].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[11].r[CHIP][SCBR[11].enq[CHIP]][0]:SCM1[11].b[CHIP][0]) : SCM1[11].awoo[CHIP][0];
SCM1[11].o[CHIP][0] = eam(1 ? SCBR[11].r[CHIP][SCBR[11].enq[CHIP]][2] : SCM1[11].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[11].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[11].b[CHIP][0]:SCM1[11].awoo[CHIP][0]);
adr = (Ull)(SCM1[11].awoo[CHIP][0] + SCM1[11].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[11].r[CHIP][SCBR[11].enq[CHIP]][1] = SCM1[11].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[11].r[CHIP][SCBR[11].enq[CHIP]][1] = SCM1[11].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[11].r[CHIP][SCBR[11].enq[CHIP]][1] = SCM1[11].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[11].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[11].r[CHIP][SCBR[11].enq[CHIP]][0]:SCM0[11].b[CHIP][0]) : SCM0[11].awoo[CHIP][0];
SCM0[11].o[CHIP][0] = eam(1 ? SCBR[11].r[CHIP][SCBR[11].enq[CHIP]][2] : SCM0[11].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[11].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[11].b[CHIP][0]:SCM0[11].awoo[CHIP][0]);
adr = (Ull)(SCM0[11].awoo[CHIP][0] + SCM0[11].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[11].r[CHIP][SCBR[11].enq[CHIP]][0] = SCM0[11].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[11].r[CHIP][SCBR[11].enq[CHIP]][0] = SCM0[11].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[11].r[CHIP][SCBR[11].enq[CHIP]][0] = SCM0[11].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[11].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[11].r[CHIP][SCBR[11].enq[CHIP]][0]:SCM1[11].b[CHIP][1]) : SCM1[11].awoo[CHIP][1];
SCM1[11].o[CHIP][1] = eam(1 ? SCBR[11].r[CHIP][SCBR[11].enq[CHIP]][2] : SCM1[11].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[11].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[11].b[CHIP][1]:SCM1[11].awoo[CHIP][1]);
adr = (Ull)(SCM1[11].awoo[CHIP][1] + SCM1[11].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[11].r[CHIP][SCBR[11].enq[CHIP]][5] = SCM1[11].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[11].r[CHIP][SCBR[11].enq[CHIP]][5] = SCM1[11].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[11].r[CHIP][SCBR[11].enq[CHIP]][5] = SCM1[11].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[11].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[11].r[CHIP][SCBR[11].enq[CHIP]][0]:SCM0[11].b[CHIP][1]) : SCM0[11].awoo[CHIP][1];
SCM0[11].o[CHIP][1] = eam(1 ? SCBR[11].r[CHIP][SCBR[11].enq[CHIP]][2] : SCM0[11].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[11].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[11].b[CHIP][1]:SCM0[11].awoo[CHIP][1]);
adr = (Ull)(SCM0[11].awoo[CHIP][1] + SCM0[11].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[11].r[CHIP][SCBR[11].enq[CHIP]][4] = SCM0[11].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[11].r[CHIP][SCBR[11].enq[CHIP]][4] = SCM0[11].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[11].r[CHIP][SCBR[11].enq[CHIP]][4] = SCM0[11].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[11].r[CHIP][SCBR[11].enq[CHIP]][2] = SCBR[10].r[CHIP][SCBR[2].enq[CHIP]][-1853689624];
SCBR[11].r[CHIP][SCBR[11].enq[CHIP]][3] = SCBR[10].r[CHIP][SCBR[3].enq[CHIP]][-1853689624];
}
{
}
{
}
{
}
uLOOP[11][CHIP]--;
SCBR[11].enq[CHIP] = 1-SCBR[11].enq[CHIP];
}
}
}
void emax6sc_pth_mm_12(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit12 */
uLOOP[12][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[12][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[12][CHIP]==0) continue;
if ((12 && SCBR[11].enq[CHIP]==SCBR[11].deq[CHIP]) || SCBR[12].enq[CHIP]!=SCBR[12].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[12][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[12][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[11].deq[CHIP] = 1-SCBR[11].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[12].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[12].r[CHIP][SCBR[12].enq[CHIP]][0]:SCM1[12].b[CHIP][0]) : SCM1[12].awoo[CHIP][0];
SCM1[12].o[CHIP][0] = eam(1 ? SCBR[12].r[CHIP][SCBR[12].enq[CHIP]][2] : SCM1[12].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[12].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[12].b[CHIP][0]:SCM1[12].awoo[CHIP][0]);
adr = (Ull)(SCM1[12].awoo[CHIP][0] + SCM1[12].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[12].r[CHIP][SCBR[12].enq[CHIP]][1] = SCM1[12].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[12].r[CHIP][SCBR[12].enq[CHIP]][1] = SCM1[12].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[12].r[CHIP][SCBR[12].enq[CHIP]][1] = SCM1[12].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[12].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[12].r[CHIP][SCBR[12].enq[CHIP]][0]:SCM0[12].b[CHIP][0]) : SCM0[12].awoo[CHIP][0];
SCM0[12].o[CHIP][0] = eam(1 ? SCBR[12].r[CHIP][SCBR[12].enq[CHIP]][2] : SCM0[12].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[12].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[12].b[CHIP][0]:SCM0[12].awoo[CHIP][0]);
adr = (Ull)(SCM0[12].awoo[CHIP][0] + SCM0[12].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[12].r[CHIP][SCBR[12].enq[CHIP]][0] = SCM0[12].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[12].r[CHIP][SCBR[12].enq[CHIP]][0] = SCM0[12].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[12].r[CHIP][SCBR[12].enq[CHIP]][0] = SCM0[12].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[12].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[12].r[CHIP][SCBR[12].enq[CHIP]][0]:SCM1[12].b[CHIP][1]) : SCM1[12].awoo[CHIP][1];
SCM1[12].o[CHIP][1] = eam(1 ? SCBR[12].r[CHIP][SCBR[12].enq[CHIP]][2] : SCM1[12].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[12].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[12].b[CHIP][1]:SCM1[12].awoo[CHIP][1]);
adr = (Ull)(SCM1[12].awoo[CHIP][1] + SCM1[12].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[12].r[CHIP][SCBR[12].enq[CHIP]][5] = SCM1[12].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[12].r[CHIP][SCBR[12].enq[CHIP]][5] = SCM1[12].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[12].r[CHIP][SCBR[12].enq[CHIP]][5] = SCM1[12].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[12].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[12].r[CHIP][SCBR[12].enq[CHIP]][0]:SCM0[12].b[CHIP][1]) : SCM0[12].awoo[CHIP][1];
SCM0[12].o[CHIP][1] = eam(1 ? SCBR[12].r[CHIP][SCBR[12].enq[CHIP]][2] : SCM0[12].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[12].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[12].b[CHIP][1]:SCM0[12].awoo[CHIP][1]);
adr = (Ull)(SCM0[12].awoo[CHIP][1] + SCM0[12].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[12].r[CHIP][SCBR[12].enq[CHIP]][4] = SCM0[12].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[12].r[CHIP][SCBR[12].enq[CHIP]][4] = SCM0[12].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[12].r[CHIP][SCBR[12].enq[CHIP]][4] = SCM0[12].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[12].r[CHIP][SCBR[12].enq[CHIP]][2] = SCBR[11].r[CHIP][SCBR[2].enq[CHIP]][-1853689496];
SCBR[12].r[CHIP][SCBR[12].enq[CHIP]][3] = SCBR[11].r[CHIP][SCBR[3].enq[CHIP]][-1853689496];
}
{
}
{
}
{
}
uLOOP[12][CHIP]--;
SCBR[12].enq[CHIP] = 1-SCBR[12].enq[CHIP];
}
}
}
void emax6sc_pth_mm_13(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit13 */
uLOOP[13][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[13][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[13][CHIP]==0) continue;
if ((13 && SCBR[12].enq[CHIP]==SCBR[12].deq[CHIP]) || SCBR[13].enq[CHIP]!=SCBR[13].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[13][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[13][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[12].deq[CHIP] = 1-SCBR[12].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[13].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[13].r[CHIP][SCBR[13].enq[CHIP]][0]:SCM1[13].b[CHIP][0]) : SCM1[13].awoo[CHIP][0];
SCM1[13].o[CHIP][0] = eam(1 ? SCBR[13].r[CHIP][SCBR[13].enq[CHIP]][2] : SCM1[13].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[13].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[13].b[CHIP][0]:SCM1[13].awoo[CHIP][0]);
adr = (Ull)(SCM1[13].awoo[CHIP][0] + SCM1[13].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[13].r[CHIP][SCBR[13].enq[CHIP]][1] = SCM1[13].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[13].r[CHIP][SCBR[13].enq[CHIP]][1] = SCM1[13].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[13].r[CHIP][SCBR[13].enq[CHIP]][1] = SCM1[13].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[13].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[13].r[CHIP][SCBR[13].enq[CHIP]][0]:SCM0[13].b[CHIP][0]) : SCM0[13].awoo[CHIP][0];
SCM0[13].o[CHIP][0] = eam(1 ? SCBR[13].r[CHIP][SCBR[13].enq[CHIP]][2] : SCM0[13].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[13].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[13].b[CHIP][0]:SCM0[13].awoo[CHIP][0]);
adr = (Ull)(SCM0[13].awoo[CHIP][0] + SCM0[13].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[13].r[CHIP][SCBR[13].enq[CHIP]][0] = SCM0[13].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[13].r[CHIP][SCBR[13].enq[CHIP]][0] = SCM0[13].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[13].r[CHIP][SCBR[13].enq[CHIP]][0] = SCM0[13].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[13].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[13].r[CHIP][SCBR[13].enq[CHIP]][0]:SCM1[13].b[CHIP][1]) : SCM1[13].awoo[CHIP][1];
SCM1[13].o[CHIP][1] = eam(1 ? SCBR[13].r[CHIP][SCBR[13].enq[CHIP]][2] : SCM1[13].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[13].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[13].b[CHIP][1]:SCM1[13].awoo[CHIP][1]);
adr = (Ull)(SCM1[13].awoo[CHIP][1] + SCM1[13].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[13].r[CHIP][SCBR[13].enq[CHIP]][5] = SCM1[13].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[13].r[CHIP][SCBR[13].enq[CHIP]][5] = SCM1[13].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[13].r[CHIP][SCBR[13].enq[CHIP]][5] = SCM1[13].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[13].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[13].r[CHIP][SCBR[13].enq[CHIP]][0]:SCM0[13].b[CHIP][1]) : SCM0[13].awoo[CHIP][1];
SCM0[13].o[CHIP][1] = eam(1 ? SCBR[13].r[CHIP][SCBR[13].enq[CHIP]][2] : SCM0[13].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[13].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[13].b[CHIP][1]:SCM0[13].awoo[CHIP][1]);
adr = (Ull)(SCM0[13].awoo[CHIP][1] + SCM0[13].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[13].r[CHIP][SCBR[13].enq[CHIP]][4] = SCM0[13].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[13].r[CHIP][SCBR[13].enq[CHIP]][4] = SCM0[13].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[13].r[CHIP][SCBR[13].enq[CHIP]][4] = SCM0[13].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[13].r[CHIP][SCBR[13].enq[CHIP]][2] = SCBR[12].r[CHIP][SCBR[2].enq[CHIP]][-1853689368];
SCBR[13].r[CHIP][SCBR[13].enq[CHIP]][3] = SCBR[12].r[CHIP][SCBR[3].enq[CHIP]][-1853689368];
}
{
}
{
}
{
}
uLOOP[13][CHIP]--;
SCBR[13].enq[CHIP] = 1-SCBR[13].enq[CHIP];
}
}
}
void emax6sc_pth_mm_14(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit14 */
uLOOP[14][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[14][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[14][CHIP]==0) continue;
if ((14 && SCBR[13].enq[CHIP]==SCBR[13].deq[CHIP]) || SCBR[14].enq[CHIP]!=SCBR[14].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[14][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[14][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[13].deq[CHIP] = 1-SCBR[13].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[14].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[14].r[CHIP][SCBR[14].enq[CHIP]][0]:SCM1[14].b[CHIP][0]) : SCM1[14].awoo[CHIP][0];
SCM1[14].o[CHIP][0] = eam(1 ? SCBR[14].r[CHIP][SCBR[14].enq[CHIP]][2] : SCM1[14].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[14].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[14].b[CHIP][0]:SCM1[14].awoo[CHIP][0]);
adr = (Ull)(SCM1[14].awoo[CHIP][0] + SCM1[14].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[14].r[CHIP][SCBR[14].enq[CHIP]][1] = SCM1[14].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[14].r[CHIP][SCBR[14].enq[CHIP]][1] = SCM1[14].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[14].r[CHIP][SCBR[14].enq[CHIP]][1] = SCM1[14].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[14].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[14].r[CHIP][SCBR[14].enq[CHIP]][0]:SCM0[14].b[CHIP][0]) : SCM0[14].awoo[CHIP][0];
SCM0[14].o[CHIP][0] = eam(1 ? SCBR[14].r[CHIP][SCBR[14].enq[CHIP]][2] : SCM0[14].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[14].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[14].b[CHIP][0]:SCM0[14].awoo[CHIP][0]);
adr = (Ull)(SCM0[14].awoo[CHIP][0] + SCM0[14].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[14].r[CHIP][SCBR[14].enq[CHIP]][0] = SCM0[14].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[14].r[CHIP][SCBR[14].enq[CHIP]][0] = SCM0[14].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[14].r[CHIP][SCBR[14].enq[CHIP]][0] = SCM0[14].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[14].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[14].r[CHIP][SCBR[14].enq[CHIP]][0]:SCM1[14].b[CHIP][1]) : SCM1[14].awoo[CHIP][1];
SCM1[14].o[CHIP][1] = eam(1 ? SCBR[14].r[CHIP][SCBR[14].enq[CHIP]][2] : SCM1[14].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[14].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[14].b[CHIP][1]:SCM1[14].awoo[CHIP][1]);
adr = (Ull)(SCM1[14].awoo[CHIP][1] + SCM1[14].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[14].r[CHIP][SCBR[14].enq[CHIP]][5] = SCM1[14].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[14].r[CHIP][SCBR[14].enq[CHIP]][5] = SCM1[14].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[14].r[CHIP][SCBR[14].enq[CHIP]][5] = SCM1[14].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[14].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[14].r[CHIP][SCBR[14].enq[CHIP]][0]:SCM0[14].b[CHIP][1]) : SCM0[14].awoo[CHIP][1];
SCM0[14].o[CHIP][1] = eam(1 ? SCBR[14].r[CHIP][SCBR[14].enq[CHIP]][2] : SCM0[14].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[14].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[14].b[CHIP][1]:SCM0[14].awoo[CHIP][1]);
adr = (Ull)(SCM0[14].awoo[CHIP][1] + SCM0[14].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[14].r[CHIP][SCBR[14].enq[CHIP]][4] = SCM0[14].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[14].r[CHIP][SCBR[14].enq[CHIP]][4] = SCM0[14].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[14].r[CHIP][SCBR[14].enq[CHIP]][4] = SCM0[14].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[14].r[CHIP][SCBR[14].enq[CHIP]][2] = SCBR[13].r[CHIP][SCBR[2].enq[CHIP]][-1853689240];
SCBR[14].r[CHIP][SCBR[14].enq[CHIP]][3] = SCBR[13].r[CHIP][SCBR[3].enq[CHIP]][-1853689240];
}
{
}
{
}
{
}
uLOOP[14][CHIP]--;
SCBR[14].enq[CHIP] = 1-SCBR[14].enq[CHIP];
}
}
}
void emax6sc_pth_mm_15(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit15 */
uLOOP[15][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[15][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[15][CHIP]==0) continue;
if ((15 && SCBR[14].enq[CHIP]==SCBR[14].deq[CHIP]) || SCBR[15].enq[CHIP]!=SCBR[15].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[15][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[15][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[14].deq[CHIP] = 1-SCBR[14].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[15].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[15].r[CHIP][SCBR[15].enq[CHIP]][0]:SCM1[15].b[CHIP][0]) : SCM1[15].awoo[CHIP][0];
SCM1[15].o[CHIP][0] = eam(1 ? SCBR[15].r[CHIP][SCBR[15].enq[CHIP]][2] : SCM1[15].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[15].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[15].b[CHIP][0]:SCM1[15].awoo[CHIP][0]);
adr = (Ull)(SCM1[15].awoo[CHIP][0] + SCM1[15].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[15].r[CHIP][SCBR[15].enq[CHIP]][1] = SCM1[15].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[15].r[CHIP][SCBR[15].enq[CHIP]][1] = SCM1[15].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[15].r[CHIP][SCBR[15].enq[CHIP]][1] = SCM1[15].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[15].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[15].r[CHIP][SCBR[15].enq[CHIP]][0]:SCM0[15].b[CHIP][0]) : SCM0[15].awoo[CHIP][0];
SCM0[15].o[CHIP][0] = eam(1 ? SCBR[15].r[CHIP][SCBR[15].enq[CHIP]][2] : SCM0[15].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[15].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[15].b[CHIP][0]:SCM0[15].awoo[CHIP][0]);
adr = (Ull)(SCM0[15].awoo[CHIP][0] + SCM0[15].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[15].r[CHIP][SCBR[15].enq[CHIP]][0] = SCM0[15].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[15].r[CHIP][SCBR[15].enq[CHIP]][0] = SCM0[15].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[15].r[CHIP][SCBR[15].enq[CHIP]][0] = SCM0[15].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[15].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[15].r[CHIP][SCBR[15].enq[CHIP]][0]:SCM1[15].b[CHIP][1]) : SCM1[15].awoo[CHIP][1];
SCM1[15].o[CHIP][1] = eam(1 ? SCBR[15].r[CHIP][SCBR[15].enq[CHIP]][2] : SCM1[15].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[15].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[15].b[CHIP][1]:SCM1[15].awoo[CHIP][1]);
adr = (Ull)(SCM1[15].awoo[CHIP][1] + SCM1[15].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[15].r[CHIP][SCBR[15].enq[CHIP]][5] = SCM1[15].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[15].r[CHIP][SCBR[15].enq[CHIP]][5] = SCM1[15].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[15].r[CHIP][SCBR[15].enq[CHIP]][5] = SCM1[15].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[15].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[15].r[CHIP][SCBR[15].enq[CHIP]][0]:SCM0[15].b[CHIP][1]) : SCM0[15].awoo[CHIP][1];
SCM0[15].o[CHIP][1] = eam(1 ? SCBR[15].r[CHIP][SCBR[15].enq[CHIP]][2] : SCM0[15].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[15].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[15].b[CHIP][1]:SCM0[15].awoo[CHIP][1]);
adr = (Ull)(SCM0[15].awoo[CHIP][1] + SCM0[15].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[15].r[CHIP][SCBR[15].enq[CHIP]][4] = SCM0[15].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[15].r[CHIP][SCBR[15].enq[CHIP]][4] = SCM0[15].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[15].r[CHIP][SCBR[15].enq[CHIP]][4] = SCM0[15].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[15].r[CHIP][SCBR[15].enq[CHIP]][2] = SCBR[14].r[CHIP][SCBR[2].enq[CHIP]][-1853689112];
SCBR[15].r[CHIP][SCBR[15].enq[CHIP]][3] = SCBR[14].r[CHIP][SCBR[3].enq[CHIP]][-1853689112];
}
{
}
{
}
{
}
uLOOP[15][CHIP]--;
SCBR[15].enq[CHIP] = 1-SCBR[15].enq[CHIP];
}
}
}
void emax6sc_pth_mm_16(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit16 */
uLOOP[16][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[16][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[16][CHIP]==0) continue;
if ((16 && SCBR[15].enq[CHIP]==SCBR[15].deq[CHIP]) || SCBR[16].enq[CHIP]!=SCBR[16].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[16][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[16][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[15].deq[CHIP] = 1-SCBR[15].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[16].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[16].r[CHIP][SCBR[16].enq[CHIP]][0]:SCM1[16].b[CHIP][0]) : SCM1[16].awoo[CHIP][0];
SCM1[16].o[CHIP][0] = eam(1 ? SCBR[16].r[CHIP][SCBR[16].enq[CHIP]][2] : SCM1[16].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[16].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[16].b[CHIP][0]:SCM1[16].awoo[CHIP][0]);
adr = (Ull)(SCM1[16].awoo[CHIP][0] + SCM1[16].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[16].r[CHIP][SCBR[16].enq[CHIP]][1] = SCM1[16].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[16].r[CHIP][SCBR[16].enq[CHIP]][1] = SCM1[16].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[16].r[CHIP][SCBR[16].enq[CHIP]][1] = SCM1[16].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[16].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[16].r[CHIP][SCBR[16].enq[CHIP]][0]:SCM0[16].b[CHIP][0]) : SCM0[16].awoo[CHIP][0];
SCM0[16].o[CHIP][0] = eam(1 ? SCBR[16].r[CHIP][SCBR[16].enq[CHIP]][2] : SCM0[16].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[16].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[16].b[CHIP][0]:SCM0[16].awoo[CHIP][0]);
adr = (Ull)(SCM0[16].awoo[CHIP][0] + SCM0[16].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[16].r[CHIP][SCBR[16].enq[CHIP]][0] = SCM0[16].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[16].r[CHIP][SCBR[16].enq[CHIP]][0] = SCM0[16].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[16].r[CHIP][SCBR[16].enq[CHIP]][0] = SCM0[16].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[16].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[16].r[CHIP][SCBR[16].enq[CHIP]][0]:SCM1[16].b[CHIP][1]) : SCM1[16].awoo[CHIP][1];
SCM1[16].o[CHIP][1] = eam(1 ? SCBR[16].r[CHIP][SCBR[16].enq[CHIP]][2] : SCM1[16].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[16].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[16].b[CHIP][1]:SCM1[16].awoo[CHIP][1]);
adr = (Ull)(SCM1[16].awoo[CHIP][1] + SCM1[16].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[16].r[CHIP][SCBR[16].enq[CHIP]][5] = SCM1[16].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[16].r[CHIP][SCBR[16].enq[CHIP]][5] = SCM1[16].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[16].r[CHIP][SCBR[16].enq[CHIP]][5] = SCM1[16].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[16].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[16].r[CHIP][SCBR[16].enq[CHIP]][0]:SCM0[16].b[CHIP][1]) : SCM0[16].awoo[CHIP][1];
SCM0[16].o[CHIP][1] = eam(1 ? SCBR[16].r[CHIP][SCBR[16].enq[CHIP]][2] : SCM0[16].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[16].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[16].b[CHIP][1]:SCM0[16].awoo[CHIP][1]);
adr = (Ull)(SCM0[16].awoo[CHIP][1] + SCM0[16].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[16].r[CHIP][SCBR[16].enq[CHIP]][4] = SCM0[16].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[16].r[CHIP][SCBR[16].enq[CHIP]][4] = SCM0[16].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[16].r[CHIP][SCBR[16].enq[CHIP]][4] = SCM0[16].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[16].r[CHIP][SCBR[16].enq[CHIP]][2] = SCBR[15].r[CHIP][SCBR[2].enq[CHIP]][-1853688984];
SCBR[16].r[CHIP][SCBR[16].enq[CHIP]][3] = SCBR[15].r[CHIP][SCBR[3].enq[CHIP]][-1853688984];
}
{
}
{
}
{
}
uLOOP[16][CHIP]--;
SCBR[16].enq[CHIP] = 1-SCBR[16].enq[CHIP];
}
}
}
void emax6sc_pth_mm_17(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit17 */
uLOOP[17][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[17][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[17][CHIP]==0) continue;
if ((17 && SCBR[16].enq[CHIP]==SCBR[16].deq[CHIP]) || SCBR[17].enq[CHIP]!=SCBR[17].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[17][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[17][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[16].deq[CHIP] = 1-SCBR[16].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[17].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[17].r[CHIP][SCBR[17].enq[CHIP]][0]:SCM1[17].b[CHIP][0]) : SCM1[17].awoo[CHIP][0];
SCM1[17].o[CHIP][0] = eam(1 ? SCBR[17].r[CHIP][SCBR[17].enq[CHIP]][2] : SCM1[17].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[17].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[17].b[CHIP][0]:SCM1[17].awoo[CHIP][0]);
adr = (Ull)(SCM1[17].awoo[CHIP][0] + SCM1[17].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[17].r[CHIP][SCBR[17].enq[CHIP]][1] = SCM1[17].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[17].r[CHIP][SCBR[17].enq[CHIP]][1] = SCM1[17].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[17].r[CHIP][SCBR[17].enq[CHIP]][1] = SCM1[17].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[17].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[17].r[CHIP][SCBR[17].enq[CHIP]][0]:SCM0[17].b[CHIP][0]) : SCM0[17].awoo[CHIP][0];
SCM0[17].o[CHIP][0] = eam(1 ? SCBR[17].r[CHIP][SCBR[17].enq[CHIP]][2] : SCM0[17].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[17].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[17].b[CHIP][0]:SCM0[17].awoo[CHIP][0]);
adr = (Ull)(SCM0[17].awoo[CHIP][0] + SCM0[17].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[17].r[CHIP][SCBR[17].enq[CHIP]][0] = SCM0[17].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[17].r[CHIP][SCBR[17].enq[CHIP]][0] = SCM0[17].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[17].r[CHIP][SCBR[17].enq[CHIP]][0] = SCM0[17].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[17].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[17].r[CHIP][SCBR[17].enq[CHIP]][0]:SCM1[17].b[CHIP][1]) : SCM1[17].awoo[CHIP][1];
SCM1[17].o[CHIP][1] = eam(1 ? SCBR[17].r[CHIP][SCBR[17].enq[CHIP]][2] : SCM1[17].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[17].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[17].b[CHIP][1]:SCM1[17].awoo[CHIP][1]);
adr = (Ull)(SCM1[17].awoo[CHIP][1] + SCM1[17].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[17].r[CHIP][SCBR[17].enq[CHIP]][5] = SCM1[17].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[17].r[CHIP][SCBR[17].enq[CHIP]][5] = SCM1[17].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[17].r[CHIP][SCBR[17].enq[CHIP]][5] = SCM1[17].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[17].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[17].r[CHIP][SCBR[17].enq[CHIP]][0]:SCM0[17].b[CHIP][1]) : SCM0[17].awoo[CHIP][1];
SCM0[17].o[CHIP][1] = eam(1 ? SCBR[17].r[CHIP][SCBR[17].enq[CHIP]][2] : SCM0[17].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[17].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[17].b[CHIP][1]:SCM0[17].awoo[CHIP][1]);
adr = (Ull)(SCM0[17].awoo[CHIP][1] + SCM0[17].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[17].r[CHIP][SCBR[17].enq[CHIP]][4] = SCM0[17].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[17].r[CHIP][SCBR[17].enq[CHIP]][4] = SCM0[17].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[17].r[CHIP][SCBR[17].enq[CHIP]][4] = SCM0[17].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[17].r[CHIP][SCBR[17].enq[CHIP]][2] = SCBR[16].r[CHIP][SCBR[2].enq[CHIP]][-1853688856];
SCBR[17].r[CHIP][SCBR[17].enq[CHIP]][3] = SCBR[16].r[CHIP][SCBR[3].enq[CHIP]][-1853688856];
}
{
}
{
}
{
}
uLOOP[17][CHIP]--;
SCBR[17].enq[CHIP] = 1-SCBR[17].enq[CHIP];
}
}
}
void emax6sc_pth_mm_18(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit18 */
uLOOP[18][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[18][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[18][CHIP]==0) continue;
if ((18 && SCBR[17].enq[CHIP]==SCBR[17].deq[CHIP]) || SCBR[18].enq[CHIP]!=SCBR[18].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[18][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[18][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[17].deq[CHIP] = 1-SCBR[17].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[18].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[18].r[CHIP][SCBR[18].enq[CHIP]][0]:SCM1[18].b[CHIP][0]) : SCM1[18].awoo[CHIP][0];
SCM1[18].o[CHIP][0] = eam(1 ? SCBR[18].r[CHIP][SCBR[18].enq[CHIP]][2] : SCM1[18].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[18].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[18].b[CHIP][0]:SCM1[18].awoo[CHIP][0]);
adr = (Ull)(SCM1[18].awoo[CHIP][0] + SCM1[18].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[18].r[CHIP][SCBR[18].enq[CHIP]][1] = SCM1[18].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[18].r[CHIP][SCBR[18].enq[CHIP]][1] = SCM1[18].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[18].r[CHIP][SCBR[18].enq[CHIP]][1] = SCM1[18].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[18].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[18].r[CHIP][SCBR[18].enq[CHIP]][0]:SCM0[18].b[CHIP][0]) : SCM0[18].awoo[CHIP][0];
SCM0[18].o[CHIP][0] = eam(1 ? SCBR[18].r[CHIP][SCBR[18].enq[CHIP]][2] : SCM0[18].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[18].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[18].b[CHIP][0]:SCM0[18].awoo[CHIP][0]);
adr = (Ull)(SCM0[18].awoo[CHIP][0] + SCM0[18].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[18].r[CHIP][SCBR[18].enq[CHIP]][0] = SCM0[18].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[18].r[CHIP][SCBR[18].enq[CHIP]][0] = SCM0[18].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[18].r[CHIP][SCBR[18].enq[CHIP]][0] = SCM0[18].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[18].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[18].r[CHIP][SCBR[18].enq[CHIP]][0]:SCM1[18].b[CHIP][1]) : SCM1[18].awoo[CHIP][1];
SCM1[18].o[CHIP][1] = eam(1 ? SCBR[18].r[CHIP][SCBR[18].enq[CHIP]][2] : SCM1[18].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[18].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[18].b[CHIP][1]:SCM1[18].awoo[CHIP][1]);
adr = (Ull)(SCM1[18].awoo[CHIP][1] + SCM1[18].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[18].r[CHIP][SCBR[18].enq[CHIP]][5] = SCM1[18].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[18].r[CHIP][SCBR[18].enq[CHIP]][5] = SCM1[18].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[18].r[CHIP][SCBR[18].enq[CHIP]][5] = SCM1[18].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[18].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[18].r[CHIP][SCBR[18].enq[CHIP]][0]:SCM0[18].b[CHIP][1]) : SCM0[18].awoo[CHIP][1];
SCM0[18].o[CHIP][1] = eam(1 ? SCBR[18].r[CHIP][SCBR[18].enq[CHIP]][2] : SCM0[18].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[18].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[18].b[CHIP][1]:SCM0[18].awoo[CHIP][1]);
adr = (Ull)(SCM0[18].awoo[CHIP][1] + SCM0[18].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[18].r[CHIP][SCBR[18].enq[CHIP]][4] = SCM0[18].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[18].r[CHIP][SCBR[18].enq[CHIP]][4] = SCM0[18].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[18].r[CHIP][SCBR[18].enq[CHIP]][4] = SCM0[18].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[18].r[CHIP][SCBR[18].enq[CHIP]][2] = SCBR[17].r[CHIP][SCBR[2].enq[CHIP]][-1853688728];
SCBR[18].r[CHIP][SCBR[18].enq[CHIP]][3] = SCBR[17].r[CHIP][SCBR[3].enq[CHIP]][-1853688728];
}
{
}
{
}
{
}
uLOOP[18][CHIP]--;
SCBR[18].enq[CHIP] = 1-SCBR[18].enq[CHIP];
}
}
}
void emax6sc_pth_mm_19(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit19 */
uLOOP[19][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[19][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[19][CHIP]==0) continue;
if ((19 && SCBR[18].enq[CHIP]==SCBR[18].deq[CHIP]) || SCBR[19].enq[CHIP]!=SCBR[19].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[19][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[19][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[18].deq[CHIP] = 1-SCBR[18].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[19].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[19].r[CHIP][SCBR[19].enq[CHIP]][0]:SCM1[19].b[CHIP][0]) : SCM1[19].awoo[CHIP][0];
SCM1[19].o[CHIP][0] = eam(1 ? SCBR[19].r[CHIP][SCBR[19].enq[CHIP]][2] : SCM1[19].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[19].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[19].b[CHIP][0]:SCM1[19].awoo[CHIP][0]);
adr = (Ull)(SCM1[19].awoo[CHIP][0] + SCM1[19].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[19].r[CHIP][SCBR[19].enq[CHIP]][1] = SCM1[19].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[19].r[CHIP][SCBR[19].enq[CHIP]][1] = SCM1[19].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[19].r[CHIP][SCBR[19].enq[CHIP]][1] = SCM1[19].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[19].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[19].r[CHIP][SCBR[19].enq[CHIP]][0]:SCM0[19].b[CHIP][0]) : SCM0[19].awoo[CHIP][0];
SCM0[19].o[CHIP][0] = eam(1 ? SCBR[19].r[CHIP][SCBR[19].enq[CHIP]][2] : SCM0[19].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[19].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[19].b[CHIP][0]:SCM0[19].awoo[CHIP][0]);
adr = (Ull)(SCM0[19].awoo[CHIP][0] + SCM0[19].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[19].r[CHIP][SCBR[19].enq[CHIP]][0] = SCM0[19].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[19].r[CHIP][SCBR[19].enq[CHIP]][0] = SCM0[19].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[19].r[CHIP][SCBR[19].enq[CHIP]][0] = SCM0[19].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[19].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[19].r[CHIP][SCBR[19].enq[CHIP]][0]:SCM1[19].b[CHIP][1]) : SCM1[19].awoo[CHIP][1];
SCM1[19].o[CHIP][1] = eam(1 ? SCBR[19].r[CHIP][SCBR[19].enq[CHIP]][2] : SCM1[19].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[19].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[19].b[CHIP][1]:SCM1[19].awoo[CHIP][1]);
adr = (Ull)(SCM1[19].awoo[CHIP][1] + SCM1[19].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[19].r[CHIP][SCBR[19].enq[CHIP]][5] = SCM1[19].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[19].r[CHIP][SCBR[19].enq[CHIP]][5] = SCM1[19].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[19].r[CHIP][SCBR[19].enq[CHIP]][5] = SCM1[19].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[19].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[19].r[CHIP][SCBR[19].enq[CHIP]][0]:SCM0[19].b[CHIP][1]) : SCM0[19].awoo[CHIP][1];
SCM0[19].o[CHIP][1] = eam(1 ? SCBR[19].r[CHIP][SCBR[19].enq[CHIP]][2] : SCM0[19].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[19].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[19].b[CHIP][1]:SCM0[19].awoo[CHIP][1]);
adr = (Ull)(SCM0[19].awoo[CHIP][1] + SCM0[19].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[19].r[CHIP][SCBR[19].enq[CHIP]][4] = SCM0[19].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[19].r[CHIP][SCBR[19].enq[CHIP]][4] = SCM0[19].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[19].r[CHIP][SCBR[19].enq[CHIP]][4] = SCM0[19].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[19].r[CHIP][SCBR[19].enq[CHIP]][2] = SCBR[18].r[CHIP][SCBR[2].enq[CHIP]][-1853688600];
SCBR[19].r[CHIP][SCBR[19].enq[CHIP]][3] = SCBR[18].r[CHIP][SCBR[3].enq[CHIP]][-1853688600];
}
{
}
{
}
{
}
uLOOP[19][CHIP]--;
SCBR[19].enq[CHIP] = 1-SCBR[19].enq[CHIP];
}
}
}
void emax6sc_pth_mm_20(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit20 */
uLOOP[20][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[20][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[20][CHIP]==0) continue;
if ((20 && SCBR[19].enq[CHIP]==SCBR[19].deq[CHIP]) || SCBR[20].enq[CHIP]!=SCBR[20].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[20][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[20][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[19].deq[CHIP] = 1-SCBR[19].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[20].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[20].r[CHIP][SCBR[20].enq[CHIP]][0]:SCM1[20].b[CHIP][0]) : SCM1[20].awoo[CHIP][0];
SCM1[20].o[CHIP][0] = eam(1 ? SCBR[20].r[CHIP][SCBR[20].enq[CHIP]][2] : SCM1[20].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[20].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[20].b[CHIP][0]:SCM1[20].awoo[CHIP][0]);
adr = (Ull)(SCM1[20].awoo[CHIP][0] + SCM1[20].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[20].r[CHIP][SCBR[20].enq[CHIP]][1] = SCM1[20].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[20].r[CHIP][SCBR[20].enq[CHIP]][1] = SCM1[20].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[20].r[CHIP][SCBR[20].enq[CHIP]][1] = SCM1[20].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[20].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[20].r[CHIP][SCBR[20].enq[CHIP]][0]:SCM0[20].b[CHIP][0]) : SCM0[20].awoo[CHIP][0];
SCM0[20].o[CHIP][0] = eam(1 ? SCBR[20].r[CHIP][SCBR[20].enq[CHIP]][2] : SCM0[20].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[20].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[20].b[CHIP][0]:SCM0[20].awoo[CHIP][0]);
adr = (Ull)(SCM0[20].awoo[CHIP][0] + SCM0[20].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[20].r[CHIP][SCBR[20].enq[CHIP]][0] = SCM0[20].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[20].r[CHIP][SCBR[20].enq[CHIP]][0] = SCM0[20].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[20].r[CHIP][SCBR[20].enq[CHIP]][0] = SCM0[20].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[20].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[20].r[CHIP][SCBR[20].enq[CHIP]][0]:SCM1[20].b[CHIP][1]) : SCM1[20].awoo[CHIP][1];
SCM1[20].o[CHIP][1] = eam(1 ? SCBR[20].r[CHIP][SCBR[20].enq[CHIP]][2] : SCM1[20].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[20].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[20].b[CHIP][1]:SCM1[20].awoo[CHIP][1]);
adr = (Ull)(SCM1[20].awoo[CHIP][1] + SCM1[20].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[20].r[CHIP][SCBR[20].enq[CHIP]][5] = SCM1[20].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[20].r[CHIP][SCBR[20].enq[CHIP]][5] = SCM1[20].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[20].r[CHIP][SCBR[20].enq[CHIP]][5] = SCM1[20].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[20].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[20].r[CHIP][SCBR[20].enq[CHIP]][0]:SCM0[20].b[CHIP][1]) : SCM0[20].awoo[CHIP][1];
SCM0[20].o[CHIP][1] = eam(1 ? SCBR[20].r[CHIP][SCBR[20].enq[CHIP]][2] : SCM0[20].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[20].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[20].b[CHIP][1]:SCM0[20].awoo[CHIP][1]);
adr = (Ull)(SCM0[20].awoo[CHIP][1] + SCM0[20].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[20].r[CHIP][SCBR[20].enq[CHIP]][4] = SCM0[20].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[20].r[CHIP][SCBR[20].enq[CHIP]][4] = SCM0[20].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[20].r[CHIP][SCBR[20].enq[CHIP]][4] = SCM0[20].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[20].r[CHIP][SCBR[20].enq[CHIP]][2] = SCBR[19].r[CHIP][SCBR[2].enq[CHIP]][-1853688472];
SCBR[20].r[CHIP][SCBR[20].enq[CHIP]][3] = SCBR[19].r[CHIP][SCBR[3].enq[CHIP]][-1853688472];
}
{
}
{
}
{
}
uLOOP[20][CHIP]--;
SCBR[20].enq[CHIP] = 1-SCBR[20].enq[CHIP];
}
}
}
void emax6sc_pth_mm_21(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit21 */
uLOOP[21][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[21][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[21][CHIP]==0) continue;
if ((21 && SCBR[20].enq[CHIP]==SCBR[20].deq[CHIP]) || SCBR[21].enq[CHIP]!=SCBR[21].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[21][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[21][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[20].deq[CHIP] = 1-SCBR[20].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[21].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[21].r[CHIP][SCBR[21].enq[CHIP]][0]:SCM1[21].b[CHIP][0]) : SCM1[21].awoo[CHIP][0];
SCM1[21].o[CHIP][0] = eam(1 ? SCBR[21].r[CHIP][SCBR[21].enq[CHIP]][2] : SCM1[21].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[21].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[21].b[CHIP][0]:SCM1[21].awoo[CHIP][0]);
adr = (Ull)(SCM1[21].awoo[CHIP][0] + SCM1[21].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[21].r[CHIP][SCBR[21].enq[CHIP]][1] = SCM1[21].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[21].r[CHIP][SCBR[21].enq[CHIP]][1] = SCM1[21].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[21].r[CHIP][SCBR[21].enq[CHIP]][1] = SCM1[21].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[21].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[21].r[CHIP][SCBR[21].enq[CHIP]][0]:SCM0[21].b[CHIP][0]) : SCM0[21].awoo[CHIP][0];
SCM0[21].o[CHIP][0] = eam(1 ? SCBR[21].r[CHIP][SCBR[21].enq[CHIP]][2] : SCM0[21].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[21].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[21].b[CHIP][0]:SCM0[21].awoo[CHIP][0]);
adr = (Ull)(SCM0[21].awoo[CHIP][0] + SCM0[21].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[21].r[CHIP][SCBR[21].enq[CHIP]][0] = SCM0[21].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[21].r[CHIP][SCBR[21].enq[CHIP]][0] = SCM0[21].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[21].r[CHIP][SCBR[21].enq[CHIP]][0] = SCM0[21].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[21].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[21].r[CHIP][SCBR[21].enq[CHIP]][0]:SCM1[21].b[CHIP][1]) : SCM1[21].awoo[CHIP][1];
SCM1[21].o[CHIP][1] = eam(1 ? SCBR[21].r[CHIP][SCBR[21].enq[CHIP]][2] : SCM1[21].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[21].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[21].b[CHIP][1]:SCM1[21].awoo[CHIP][1]);
adr = (Ull)(SCM1[21].awoo[CHIP][1] + SCM1[21].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[21].r[CHIP][SCBR[21].enq[CHIP]][5] = SCM1[21].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[21].r[CHIP][SCBR[21].enq[CHIP]][5] = SCM1[21].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[21].r[CHIP][SCBR[21].enq[CHIP]][5] = SCM1[21].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[21].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[21].r[CHIP][SCBR[21].enq[CHIP]][0]:SCM0[21].b[CHIP][1]) : SCM0[21].awoo[CHIP][1];
SCM0[21].o[CHIP][1] = eam(1 ? SCBR[21].r[CHIP][SCBR[21].enq[CHIP]][2] : SCM0[21].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[21].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[21].b[CHIP][1]:SCM0[21].awoo[CHIP][1]);
adr = (Ull)(SCM0[21].awoo[CHIP][1] + SCM0[21].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[21].r[CHIP][SCBR[21].enq[CHIP]][4] = SCM0[21].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[21].r[CHIP][SCBR[21].enq[CHIP]][4] = SCM0[21].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[21].r[CHIP][SCBR[21].enq[CHIP]][4] = SCM0[21].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[21].r[CHIP][SCBR[21].enq[CHIP]][2] = SCBR[20].r[CHIP][SCBR[2].enq[CHIP]][-1853688344];
SCBR[21].r[CHIP][SCBR[21].enq[CHIP]][3] = SCBR[20].r[CHIP][SCBR[3].enq[CHIP]][-1853688344];
}
{
}
{
}
{
}
uLOOP[21][CHIP]--;
SCBR[21].enq[CHIP] = 1-SCBR[21].enq[CHIP];
}
}
}
void emax6sc_pth_mm_22(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit22 */
uLOOP[22][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[22][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[22][CHIP]==0) continue;
if ((22 && SCBR[21].enq[CHIP]==SCBR[21].deq[CHIP]) || SCBR[22].enq[CHIP]!=SCBR[22].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[22][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[22][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[21].deq[CHIP] = 1-SCBR[21].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[22].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[22].r[CHIP][SCBR[22].enq[CHIP]][0]:SCM1[22].b[CHIP][0]) : SCM1[22].awoo[CHIP][0];
SCM1[22].o[CHIP][0] = eam(1 ? SCBR[22].r[CHIP][SCBR[22].enq[CHIP]][2] : SCM1[22].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[22].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[22].b[CHIP][0]:SCM1[22].awoo[CHIP][0]);
adr = (Ull)(SCM1[22].awoo[CHIP][0] + SCM1[22].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[22].r[CHIP][SCBR[22].enq[CHIP]][1] = SCM1[22].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[22].r[CHIP][SCBR[22].enq[CHIP]][1] = SCM1[22].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[22].r[CHIP][SCBR[22].enq[CHIP]][1] = SCM1[22].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[22].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[22].r[CHIP][SCBR[22].enq[CHIP]][0]:SCM0[22].b[CHIP][0]) : SCM0[22].awoo[CHIP][0];
SCM0[22].o[CHIP][0] = eam(1 ? SCBR[22].r[CHIP][SCBR[22].enq[CHIP]][2] : SCM0[22].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[22].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[22].b[CHIP][0]:SCM0[22].awoo[CHIP][0]);
adr = (Ull)(SCM0[22].awoo[CHIP][0] + SCM0[22].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[22].r[CHIP][SCBR[22].enq[CHIP]][0] = SCM0[22].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[22].r[CHIP][SCBR[22].enq[CHIP]][0] = SCM0[22].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[22].r[CHIP][SCBR[22].enq[CHIP]][0] = SCM0[22].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[22].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[22].r[CHIP][SCBR[22].enq[CHIP]][0]:SCM1[22].b[CHIP][1]) : SCM1[22].awoo[CHIP][1];
SCM1[22].o[CHIP][1] = eam(1 ? SCBR[22].r[CHIP][SCBR[22].enq[CHIP]][2] : SCM1[22].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[22].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[22].b[CHIP][1]:SCM1[22].awoo[CHIP][1]);
adr = (Ull)(SCM1[22].awoo[CHIP][1] + SCM1[22].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[22].r[CHIP][SCBR[22].enq[CHIP]][5] = SCM1[22].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[22].r[CHIP][SCBR[22].enq[CHIP]][5] = SCM1[22].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[22].r[CHIP][SCBR[22].enq[CHIP]][5] = SCM1[22].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[22].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[22].r[CHIP][SCBR[22].enq[CHIP]][0]:SCM0[22].b[CHIP][1]) : SCM0[22].awoo[CHIP][1];
SCM0[22].o[CHIP][1] = eam(1 ? SCBR[22].r[CHIP][SCBR[22].enq[CHIP]][2] : SCM0[22].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[22].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[22].b[CHIP][1]:SCM0[22].awoo[CHIP][1]);
adr = (Ull)(SCM0[22].awoo[CHIP][1] + SCM0[22].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[22].r[CHIP][SCBR[22].enq[CHIP]][4] = SCM0[22].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[22].r[CHIP][SCBR[22].enq[CHIP]][4] = SCM0[22].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[22].r[CHIP][SCBR[22].enq[CHIP]][4] = SCM0[22].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[22].r[CHIP][SCBR[22].enq[CHIP]][2] = SCBR[21].r[CHIP][SCBR[2].enq[CHIP]][-1853688216];
SCBR[22].r[CHIP][SCBR[22].enq[CHIP]][3] = SCBR[21].r[CHIP][SCBR[3].enq[CHIP]][-1853688216];
}
{
}
{
}
{
}
uLOOP[22][CHIP]--;
SCBR[22].enq[CHIP] = 1-SCBR[22].enq[CHIP];
}
}
}
void emax6sc_pth_mm_23(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit23 */
uLOOP[23][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[23][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[23][CHIP]==0) continue;
if ((23 && SCBR[22].enq[CHIP]==SCBR[22].deq[CHIP]) || SCBR[23].enq[CHIP]!=SCBR[23].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[23][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[23][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[22].deq[CHIP] = 1-SCBR[22].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[23].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[23].r[CHIP][SCBR[23].enq[CHIP]][0]:SCM1[23].b[CHIP][0]) : SCM1[23].awoo[CHIP][0];
SCM1[23].o[CHIP][0] = eam(1 ? SCBR[23].r[CHIP][SCBR[23].enq[CHIP]][2] : SCM1[23].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[23].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[23].b[CHIP][0]:SCM1[23].awoo[CHIP][0]);
adr = (Ull)(SCM1[23].awoo[CHIP][0] + SCM1[23].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[23].r[CHIP][SCBR[23].enq[CHIP]][1] = SCM1[23].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[23].r[CHIP][SCBR[23].enq[CHIP]][1] = SCM1[23].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[23].r[CHIP][SCBR[23].enq[CHIP]][1] = SCM1[23].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[23].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[23].r[CHIP][SCBR[23].enq[CHIP]][0]:SCM0[23].b[CHIP][0]) : SCM0[23].awoo[CHIP][0];
SCM0[23].o[CHIP][0] = eam(1 ? SCBR[23].r[CHIP][SCBR[23].enq[CHIP]][2] : SCM0[23].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[23].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[23].b[CHIP][0]:SCM0[23].awoo[CHIP][0]);
adr = (Ull)(SCM0[23].awoo[CHIP][0] + SCM0[23].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[23].r[CHIP][SCBR[23].enq[CHIP]][0] = SCM0[23].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[23].r[CHIP][SCBR[23].enq[CHIP]][0] = SCM0[23].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[23].r[CHIP][SCBR[23].enq[CHIP]][0] = SCM0[23].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[23].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[23].r[CHIP][SCBR[23].enq[CHIP]][0]:SCM1[23].b[CHIP][1]) : SCM1[23].awoo[CHIP][1];
SCM1[23].o[CHIP][1] = eam(1 ? SCBR[23].r[CHIP][SCBR[23].enq[CHIP]][2] : SCM1[23].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[23].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[23].b[CHIP][1]:SCM1[23].awoo[CHIP][1]);
adr = (Ull)(SCM1[23].awoo[CHIP][1] + SCM1[23].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[23].r[CHIP][SCBR[23].enq[CHIP]][5] = SCM1[23].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[23].r[CHIP][SCBR[23].enq[CHIP]][5] = SCM1[23].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[23].r[CHIP][SCBR[23].enq[CHIP]][5] = SCM1[23].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[23].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[23].r[CHIP][SCBR[23].enq[CHIP]][0]:SCM0[23].b[CHIP][1]) : SCM0[23].awoo[CHIP][1];
SCM0[23].o[CHIP][1] = eam(1 ? SCBR[23].r[CHIP][SCBR[23].enq[CHIP]][2] : SCM0[23].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[23].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[23].b[CHIP][1]:SCM0[23].awoo[CHIP][1]);
adr = (Ull)(SCM0[23].awoo[CHIP][1] + SCM0[23].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[23].r[CHIP][SCBR[23].enq[CHIP]][4] = SCM0[23].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[23].r[CHIP][SCBR[23].enq[CHIP]][4] = SCM0[23].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[23].r[CHIP][SCBR[23].enq[CHIP]][4] = SCM0[23].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[23].r[CHIP][SCBR[23].enq[CHIP]][2] = SCBR[22].r[CHIP][SCBR[2].enq[CHIP]][-1853688088];
SCBR[23].r[CHIP][SCBR[23].enq[CHIP]][3] = SCBR[22].r[CHIP][SCBR[3].enq[CHIP]][-1853688088];
}
{
}
{
}
{
}
uLOOP[23][CHIP]--;
SCBR[23].enq[CHIP] = 1-SCBR[23].enq[CHIP];
}
}
}
void emax6sc_pth_mm_24(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit24 */
uLOOP[24][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[24][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[24][CHIP]==0) continue;
if ((24 && SCBR[23].enq[CHIP]==SCBR[23].deq[CHIP]) || SCBR[24].enq[CHIP]!=SCBR[24].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[24][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[24][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[23].deq[CHIP] = 1-SCBR[23].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[24].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[24].r[CHIP][SCBR[24].enq[CHIP]][0]:SCM1[24].b[CHIP][0]) : SCM1[24].awoo[CHIP][0];
SCM1[24].o[CHIP][0] = eam(1 ? SCBR[24].r[CHIP][SCBR[24].enq[CHIP]][2] : SCM1[24].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[24].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[24].b[CHIP][0]:SCM1[24].awoo[CHIP][0]);
adr = (Ull)(SCM1[24].awoo[CHIP][0] + SCM1[24].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[24].r[CHIP][SCBR[24].enq[CHIP]][1] = SCM1[24].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[24].r[CHIP][SCBR[24].enq[CHIP]][1] = SCM1[24].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[24].r[CHIP][SCBR[24].enq[CHIP]][1] = SCM1[24].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[24].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[24].r[CHIP][SCBR[24].enq[CHIP]][0]:SCM0[24].b[CHIP][0]) : SCM0[24].awoo[CHIP][0];
SCM0[24].o[CHIP][0] = eam(1 ? SCBR[24].r[CHIP][SCBR[24].enq[CHIP]][2] : SCM0[24].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[24].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[24].b[CHIP][0]:SCM0[24].awoo[CHIP][0]);
adr = (Ull)(SCM0[24].awoo[CHIP][0] + SCM0[24].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[24].r[CHIP][SCBR[24].enq[CHIP]][0] = SCM0[24].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[24].r[CHIP][SCBR[24].enq[CHIP]][0] = SCM0[24].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[24].r[CHIP][SCBR[24].enq[CHIP]][0] = SCM0[24].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[24].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[24].r[CHIP][SCBR[24].enq[CHIP]][0]:SCM1[24].b[CHIP][1]) : SCM1[24].awoo[CHIP][1];
SCM1[24].o[CHIP][1] = eam(1 ? SCBR[24].r[CHIP][SCBR[24].enq[CHIP]][2] : SCM1[24].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[24].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[24].b[CHIP][1]:SCM1[24].awoo[CHIP][1]);
adr = (Ull)(SCM1[24].awoo[CHIP][1] + SCM1[24].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[24].r[CHIP][SCBR[24].enq[CHIP]][5] = SCM1[24].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[24].r[CHIP][SCBR[24].enq[CHIP]][5] = SCM1[24].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[24].r[CHIP][SCBR[24].enq[CHIP]][5] = SCM1[24].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[24].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[24].r[CHIP][SCBR[24].enq[CHIP]][0]:SCM0[24].b[CHIP][1]) : SCM0[24].awoo[CHIP][1];
SCM0[24].o[CHIP][1] = eam(1 ? SCBR[24].r[CHIP][SCBR[24].enq[CHIP]][2] : SCM0[24].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[24].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[24].b[CHIP][1]:SCM0[24].awoo[CHIP][1]);
adr = (Ull)(SCM0[24].awoo[CHIP][1] + SCM0[24].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[24].r[CHIP][SCBR[24].enq[CHIP]][4] = SCM0[24].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[24].r[CHIP][SCBR[24].enq[CHIP]][4] = SCM0[24].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[24].r[CHIP][SCBR[24].enq[CHIP]][4] = SCM0[24].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[24].r[CHIP][SCBR[24].enq[CHIP]][2] = SCBR[23].r[CHIP][SCBR[2].enq[CHIP]][-1853687960];
SCBR[24].r[CHIP][SCBR[24].enq[CHIP]][3] = SCBR[23].r[CHIP][SCBR[3].enq[CHIP]][-1853687960];
}
{
}
{
}
{
}
uLOOP[24][CHIP]--;
SCBR[24].enq[CHIP] = 1-SCBR[24].enq[CHIP];
}
}
}
void emax6sc_pth_mm_25(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit25 */
uLOOP[25][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[25][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[25][CHIP]==0) continue;
if ((25 && SCBR[24].enq[CHIP]==SCBR[24].deq[CHIP]) || SCBR[25].enq[CHIP]!=SCBR[25].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[25][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[25][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[24].deq[CHIP] = 1-SCBR[24].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[25].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[25].r[CHIP][SCBR[25].enq[CHIP]][0]:SCM1[25].b[CHIP][0]) : SCM1[25].awoo[CHIP][0];
SCM1[25].o[CHIP][0] = eam(1 ? SCBR[25].r[CHIP][SCBR[25].enq[CHIP]][2] : SCM1[25].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[25].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[25].b[CHIP][0]:SCM1[25].awoo[CHIP][0]);
adr = (Ull)(SCM1[25].awoo[CHIP][0] + SCM1[25].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[25].r[CHIP][SCBR[25].enq[CHIP]][1] = SCM1[25].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[25].r[CHIP][SCBR[25].enq[CHIP]][1] = SCM1[25].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[25].r[CHIP][SCBR[25].enq[CHIP]][1] = SCM1[25].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[25].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[25].r[CHIP][SCBR[25].enq[CHIP]][0]:SCM0[25].b[CHIP][0]) : SCM0[25].awoo[CHIP][0];
SCM0[25].o[CHIP][0] = eam(1 ? SCBR[25].r[CHIP][SCBR[25].enq[CHIP]][2] : SCM0[25].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[25].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[25].b[CHIP][0]:SCM0[25].awoo[CHIP][0]);
adr = (Ull)(SCM0[25].awoo[CHIP][0] + SCM0[25].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[25].r[CHIP][SCBR[25].enq[CHIP]][0] = SCM0[25].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[25].r[CHIP][SCBR[25].enq[CHIP]][0] = SCM0[25].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[25].r[CHIP][SCBR[25].enq[CHIP]][0] = SCM0[25].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[25].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[25].r[CHIP][SCBR[25].enq[CHIP]][0]:SCM1[25].b[CHIP][1]) : SCM1[25].awoo[CHIP][1];
SCM1[25].o[CHIP][1] = eam(1 ? SCBR[25].r[CHIP][SCBR[25].enq[CHIP]][2] : SCM1[25].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[25].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[25].b[CHIP][1]:SCM1[25].awoo[CHIP][1]);
adr = (Ull)(SCM1[25].awoo[CHIP][1] + SCM1[25].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[25].r[CHIP][SCBR[25].enq[CHIP]][5] = SCM1[25].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[25].r[CHIP][SCBR[25].enq[CHIP]][5] = SCM1[25].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[25].r[CHIP][SCBR[25].enq[CHIP]][5] = SCM1[25].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[25].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[25].r[CHIP][SCBR[25].enq[CHIP]][0]:SCM0[25].b[CHIP][1]) : SCM0[25].awoo[CHIP][1];
SCM0[25].o[CHIP][1] = eam(1 ? SCBR[25].r[CHIP][SCBR[25].enq[CHIP]][2] : SCM0[25].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[25].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[25].b[CHIP][1]:SCM0[25].awoo[CHIP][1]);
adr = (Ull)(SCM0[25].awoo[CHIP][1] + SCM0[25].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[25].r[CHIP][SCBR[25].enq[CHIP]][4] = SCM0[25].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[25].r[CHIP][SCBR[25].enq[CHIP]][4] = SCM0[25].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[25].r[CHIP][SCBR[25].enq[CHIP]][4] = SCM0[25].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[25].r[CHIP][SCBR[25].enq[CHIP]][2] = SCBR[24].r[CHIP][SCBR[2].enq[CHIP]][-1853687832];
SCBR[25].r[CHIP][SCBR[25].enq[CHIP]][3] = SCBR[24].r[CHIP][SCBR[3].enq[CHIP]][-1853687832];
}
{
}
{
}
{
}
uLOOP[25][CHIP]--;
SCBR[25].enq[CHIP] = 1-SCBR[25].enq[CHIP];
}
}
}
void emax6sc_pth_mm_26(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit26 */
uLOOP[26][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[26][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[26][CHIP]==0) continue;
if ((26 && SCBR[25].enq[CHIP]==SCBR[25].deq[CHIP]) || SCBR[26].enq[CHIP]!=SCBR[26].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[26][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[26][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[25].deq[CHIP] = 1-SCBR[25].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[26].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[26].r[CHIP][SCBR[26].enq[CHIP]][0]:SCM1[26].b[CHIP][0]) : SCM1[26].awoo[CHIP][0];
SCM1[26].o[CHIP][0] = eam(1 ? SCBR[26].r[CHIP][SCBR[26].enq[CHIP]][2] : SCM1[26].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[26].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[26].b[CHIP][0]:SCM1[26].awoo[CHIP][0]);
adr = (Ull)(SCM1[26].awoo[CHIP][0] + SCM1[26].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[26].r[CHIP][SCBR[26].enq[CHIP]][1] = SCM1[26].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[26].r[CHIP][SCBR[26].enq[CHIP]][1] = SCM1[26].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[26].r[CHIP][SCBR[26].enq[CHIP]][1] = SCM1[26].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[26].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[26].r[CHIP][SCBR[26].enq[CHIP]][0]:SCM0[26].b[CHIP][0]) : SCM0[26].awoo[CHIP][0];
SCM0[26].o[CHIP][0] = eam(1 ? SCBR[26].r[CHIP][SCBR[26].enq[CHIP]][2] : SCM0[26].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[26].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[26].b[CHIP][0]:SCM0[26].awoo[CHIP][0]);
adr = (Ull)(SCM0[26].awoo[CHIP][0] + SCM0[26].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[26].r[CHIP][SCBR[26].enq[CHIP]][0] = SCM0[26].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[26].r[CHIP][SCBR[26].enq[CHIP]][0] = SCM0[26].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[26].r[CHIP][SCBR[26].enq[CHIP]][0] = SCM0[26].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[26].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[26].r[CHIP][SCBR[26].enq[CHIP]][0]:SCM1[26].b[CHIP][1]) : SCM1[26].awoo[CHIP][1];
SCM1[26].o[CHIP][1] = eam(1 ? SCBR[26].r[CHIP][SCBR[26].enq[CHIP]][2] : SCM1[26].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[26].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[26].b[CHIP][1]:SCM1[26].awoo[CHIP][1]);
adr = (Ull)(SCM1[26].awoo[CHIP][1] + SCM1[26].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[26].r[CHIP][SCBR[26].enq[CHIP]][5] = SCM1[26].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[26].r[CHIP][SCBR[26].enq[CHIP]][5] = SCM1[26].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[26].r[CHIP][SCBR[26].enq[CHIP]][5] = SCM1[26].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[26].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[26].r[CHIP][SCBR[26].enq[CHIP]][0]:SCM0[26].b[CHIP][1]) : SCM0[26].awoo[CHIP][1];
SCM0[26].o[CHIP][1] = eam(1 ? SCBR[26].r[CHIP][SCBR[26].enq[CHIP]][2] : SCM0[26].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[26].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[26].b[CHIP][1]:SCM0[26].awoo[CHIP][1]);
adr = (Ull)(SCM0[26].awoo[CHIP][1] + SCM0[26].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[26].r[CHIP][SCBR[26].enq[CHIP]][4] = SCM0[26].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[26].r[CHIP][SCBR[26].enq[CHIP]][4] = SCM0[26].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[26].r[CHIP][SCBR[26].enq[CHIP]][4] = SCM0[26].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[26].r[CHIP][SCBR[26].enq[CHIP]][2] = SCBR[25].r[CHIP][SCBR[2].enq[CHIP]][-1853687704];
SCBR[26].r[CHIP][SCBR[26].enq[CHIP]][3] = SCBR[25].r[CHIP][SCBR[3].enq[CHIP]][-1853687704];
}
{
}
{
}
{
}
uLOOP[26][CHIP]--;
SCBR[26].enq[CHIP] = 1-SCBR[26].enq[CHIP];
}
}
}
void emax6sc_pth_mm_27(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit27 */
uLOOP[27][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[27][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[27][CHIP]==0) continue;
if ((27 && SCBR[26].enq[CHIP]==SCBR[26].deq[CHIP]) || SCBR[27].enq[CHIP]!=SCBR[27].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[27][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[27][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[26].deq[CHIP] = 1-SCBR[26].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[27].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[27].r[CHIP][SCBR[27].enq[CHIP]][0]:SCM1[27].b[CHIP][0]) : SCM1[27].awoo[CHIP][0];
SCM1[27].o[CHIP][0] = eam(1 ? SCBR[27].r[CHIP][SCBR[27].enq[CHIP]][2] : SCM1[27].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[27].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[27].b[CHIP][0]:SCM1[27].awoo[CHIP][0]);
adr = (Ull)(SCM1[27].awoo[CHIP][0] + SCM1[27].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[27].r[CHIP][SCBR[27].enq[CHIP]][1] = SCM1[27].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[27].r[CHIP][SCBR[27].enq[CHIP]][1] = SCM1[27].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[27].r[CHIP][SCBR[27].enq[CHIP]][1] = SCM1[27].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[27].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[27].r[CHIP][SCBR[27].enq[CHIP]][0]:SCM0[27].b[CHIP][0]) : SCM0[27].awoo[CHIP][0];
SCM0[27].o[CHIP][0] = eam(1 ? SCBR[27].r[CHIP][SCBR[27].enq[CHIP]][2] : SCM0[27].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[27].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[27].b[CHIP][0]:SCM0[27].awoo[CHIP][0]);
adr = (Ull)(SCM0[27].awoo[CHIP][0] + SCM0[27].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[27].r[CHIP][SCBR[27].enq[CHIP]][0] = SCM0[27].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[27].r[CHIP][SCBR[27].enq[CHIP]][0] = SCM0[27].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[27].r[CHIP][SCBR[27].enq[CHIP]][0] = SCM0[27].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[27].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[27].r[CHIP][SCBR[27].enq[CHIP]][0]:SCM1[27].b[CHIP][1]) : SCM1[27].awoo[CHIP][1];
SCM1[27].o[CHIP][1] = eam(1 ? SCBR[27].r[CHIP][SCBR[27].enq[CHIP]][2] : SCM1[27].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[27].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[27].b[CHIP][1]:SCM1[27].awoo[CHIP][1]);
adr = (Ull)(SCM1[27].awoo[CHIP][1] + SCM1[27].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[27].r[CHIP][SCBR[27].enq[CHIP]][5] = SCM1[27].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[27].r[CHIP][SCBR[27].enq[CHIP]][5] = SCM1[27].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[27].r[CHIP][SCBR[27].enq[CHIP]][5] = SCM1[27].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[27].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[27].r[CHIP][SCBR[27].enq[CHIP]][0]:SCM0[27].b[CHIP][1]) : SCM0[27].awoo[CHIP][1];
SCM0[27].o[CHIP][1] = eam(1 ? SCBR[27].r[CHIP][SCBR[27].enq[CHIP]][2] : SCM0[27].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[27].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[27].b[CHIP][1]:SCM0[27].awoo[CHIP][1]);
adr = (Ull)(SCM0[27].awoo[CHIP][1] + SCM0[27].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[27].r[CHIP][SCBR[27].enq[CHIP]][4] = SCM0[27].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[27].r[CHIP][SCBR[27].enq[CHIP]][4] = SCM0[27].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[27].r[CHIP][SCBR[27].enq[CHIP]][4] = SCM0[27].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[27].r[CHIP][SCBR[27].enq[CHIP]][2] = SCBR[26].r[CHIP][SCBR[2].enq[CHIP]][-1853687576];
SCBR[27].r[CHIP][SCBR[27].enq[CHIP]][3] = SCBR[26].r[CHIP][SCBR[3].enq[CHIP]][-1853687576];
}
{
}
{
}
{
}
uLOOP[27][CHIP]--;
SCBR[27].enq[CHIP] = 1-SCBR[27].enq[CHIP];
}
}
}
void emax6sc_pth_mm_28(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit28 */
uLOOP[28][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[28][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[28][CHIP]==0) continue;
if ((28 && SCBR[27].enq[CHIP]==SCBR[27].deq[CHIP]) || SCBR[28].enq[CHIP]!=SCBR[28].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[28][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[28][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[27].deq[CHIP] = 1-SCBR[27].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[28].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[28].r[CHIP][SCBR[28].enq[CHIP]][0]:SCM1[28].b[CHIP][0]) : SCM1[28].awoo[CHIP][0];
SCM1[28].o[CHIP][0] = eam(1 ? SCBR[28].r[CHIP][SCBR[28].enq[CHIP]][2] : SCM1[28].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[28].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[28].b[CHIP][0]:SCM1[28].awoo[CHIP][0]);
adr = (Ull)(SCM1[28].awoo[CHIP][0] + SCM1[28].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[28].r[CHIP][SCBR[28].enq[CHIP]][1] = SCM1[28].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[28].r[CHIP][SCBR[28].enq[CHIP]][1] = SCM1[28].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[28].r[CHIP][SCBR[28].enq[CHIP]][1] = SCM1[28].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[28].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[28].r[CHIP][SCBR[28].enq[CHIP]][0]:SCM0[28].b[CHIP][0]) : SCM0[28].awoo[CHIP][0];
SCM0[28].o[CHIP][0] = eam(1 ? SCBR[28].r[CHIP][SCBR[28].enq[CHIP]][2] : SCM0[28].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[28].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[28].b[CHIP][0]:SCM0[28].awoo[CHIP][0]);
adr = (Ull)(SCM0[28].awoo[CHIP][0] + SCM0[28].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[28].r[CHIP][SCBR[28].enq[CHIP]][0] = SCM0[28].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[28].r[CHIP][SCBR[28].enq[CHIP]][0] = SCM0[28].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[28].r[CHIP][SCBR[28].enq[CHIP]][0] = SCM0[28].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[28].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[28].r[CHIP][SCBR[28].enq[CHIP]][0]:SCM1[28].b[CHIP][1]) : SCM1[28].awoo[CHIP][1];
SCM1[28].o[CHIP][1] = eam(1 ? SCBR[28].r[CHIP][SCBR[28].enq[CHIP]][2] : SCM1[28].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[28].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[28].b[CHIP][1]:SCM1[28].awoo[CHIP][1]);
adr = (Ull)(SCM1[28].awoo[CHIP][1] + SCM1[28].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[28].r[CHIP][SCBR[28].enq[CHIP]][5] = SCM1[28].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[28].r[CHIP][SCBR[28].enq[CHIP]][5] = SCM1[28].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[28].r[CHIP][SCBR[28].enq[CHIP]][5] = SCM1[28].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[28].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[28].r[CHIP][SCBR[28].enq[CHIP]][0]:SCM0[28].b[CHIP][1]) : SCM0[28].awoo[CHIP][1];
SCM0[28].o[CHIP][1] = eam(1 ? SCBR[28].r[CHIP][SCBR[28].enq[CHIP]][2] : SCM0[28].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[28].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[28].b[CHIP][1]:SCM0[28].awoo[CHIP][1]);
adr = (Ull)(SCM0[28].awoo[CHIP][1] + SCM0[28].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[28].r[CHIP][SCBR[28].enq[CHIP]][4] = SCM0[28].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[28].r[CHIP][SCBR[28].enq[CHIP]][4] = SCM0[28].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[28].r[CHIP][SCBR[28].enq[CHIP]][4] = SCM0[28].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[28].r[CHIP][SCBR[28].enq[CHIP]][2] = SCBR[27].r[CHIP][SCBR[2].enq[CHIP]][-1853687448];
SCBR[28].r[CHIP][SCBR[28].enq[CHIP]][3] = SCBR[27].r[CHIP][SCBR[3].enq[CHIP]][-1853687448];
}
{
}
{
}
{
}
uLOOP[28][CHIP]--;
SCBR[28].enq[CHIP] = 1-SCBR[28].enq[CHIP];
}
}
}
void emax6sc_pth_mm_29(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit29 */
uLOOP[29][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[29][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[29][CHIP]==0) continue;
if ((29 && SCBR[28].enq[CHIP]==SCBR[28].deq[CHIP]) || SCBR[29].enq[CHIP]!=SCBR[29].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[29][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[29][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[28].deq[CHIP] = 1-SCBR[28].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[29].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[29].r[CHIP][SCBR[29].enq[CHIP]][0]:SCM1[29].b[CHIP][0]) : SCM1[29].awoo[CHIP][0];
SCM1[29].o[CHIP][0] = eam(1 ? SCBR[29].r[CHIP][SCBR[29].enq[CHIP]][2] : SCM1[29].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[29].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[29].b[CHIP][0]:SCM1[29].awoo[CHIP][0]);
adr = (Ull)(SCM1[29].awoo[CHIP][0] + SCM1[29].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[29].r[CHIP][SCBR[29].enq[CHIP]][1] = SCM1[29].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[29].r[CHIP][SCBR[29].enq[CHIP]][1] = SCM1[29].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[29].r[CHIP][SCBR[29].enq[CHIP]][1] = SCM1[29].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[29].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[29].r[CHIP][SCBR[29].enq[CHIP]][0]:SCM0[29].b[CHIP][0]) : SCM0[29].awoo[CHIP][0];
SCM0[29].o[CHIP][0] = eam(1 ? SCBR[29].r[CHIP][SCBR[29].enq[CHIP]][2] : SCM0[29].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[29].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[29].b[CHIP][0]:SCM0[29].awoo[CHIP][0]);
adr = (Ull)(SCM0[29].awoo[CHIP][0] + SCM0[29].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[29].r[CHIP][SCBR[29].enq[CHIP]][0] = SCM0[29].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[29].r[CHIP][SCBR[29].enq[CHIP]][0] = SCM0[29].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[29].r[CHIP][SCBR[29].enq[CHIP]][0] = SCM0[29].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[29].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[29].r[CHIP][SCBR[29].enq[CHIP]][0]:SCM1[29].b[CHIP][1]) : SCM1[29].awoo[CHIP][1];
SCM1[29].o[CHIP][1] = eam(1 ? SCBR[29].r[CHIP][SCBR[29].enq[CHIP]][2] : SCM1[29].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[29].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[29].b[CHIP][1]:SCM1[29].awoo[CHIP][1]);
adr = (Ull)(SCM1[29].awoo[CHIP][1] + SCM1[29].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[29].r[CHIP][SCBR[29].enq[CHIP]][5] = SCM1[29].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[29].r[CHIP][SCBR[29].enq[CHIP]][5] = SCM1[29].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[29].r[CHIP][SCBR[29].enq[CHIP]][5] = SCM1[29].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[29].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[29].r[CHIP][SCBR[29].enq[CHIP]][0]:SCM0[29].b[CHIP][1]) : SCM0[29].awoo[CHIP][1];
SCM0[29].o[CHIP][1] = eam(1 ? SCBR[29].r[CHIP][SCBR[29].enq[CHIP]][2] : SCM0[29].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[29].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[29].b[CHIP][1]:SCM0[29].awoo[CHIP][1]);
adr = (Ull)(SCM0[29].awoo[CHIP][1] + SCM0[29].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[29].r[CHIP][SCBR[29].enq[CHIP]][4] = SCM0[29].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[29].r[CHIP][SCBR[29].enq[CHIP]][4] = SCM0[29].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[29].r[CHIP][SCBR[29].enq[CHIP]][4] = SCM0[29].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[29].r[CHIP][SCBR[29].enq[CHIP]][2] = SCBR[28].r[CHIP][SCBR[2].enq[CHIP]][-1853687320];
SCBR[29].r[CHIP][SCBR[29].enq[CHIP]][3] = SCBR[28].r[CHIP][SCBR[3].enq[CHIP]][-1853687320];
}
{
}
{
}
{
}
uLOOP[29][CHIP]--;
SCBR[29].enq[CHIP] = 1-SCBR[29].enq[CHIP];
}
}
}
void emax6sc_pth_mm_30(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit30 */
uLOOP[30][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[30][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[30][CHIP]==0) continue;
if ((30 && SCBR[29].enq[CHIP]==SCBR[29].deq[CHIP]) || SCBR[30].enq[CHIP]!=SCBR[30].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[30][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[30][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[29].deq[CHIP] = 1-SCBR[29].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[30].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[30].r[CHIP][SCBR[30].enq[CHIP]][0]:SCM1[30].b[CHIP][0]) : SCM1[30].awoo[CHIP][0];
SCM1[30].o[CHIP][0] = eam(1 ? SCBR[30].r[CHIP][SCBR[30].enq[CHIP]][2] : SCM1[30].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[30].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[30].b[CHIP][0]:SCM1[30].awoo[CHIP][0]);
adr = (Ull)(SCM1[30].awoo[CHIP][0] + SCM1[30].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[30].r[CHIP][SCBR[30].enq[CHIP]][1] = SCM1[30].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[30].r[CHIP][SCBR[30].enq[CHIP]][1] = SCM1[30].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[30].r[CHIP][SCBR[30].enq[CHIP]][1] = SCM1[30].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[30].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[30].r[CHIP][SCBR[30].enq[CHIP]][0]:SCM0[30].b[CHIP][0]) : SCM0[30].awoo[CHIP][0];
SCM0[30].o[CHIP][0] = eam(1 ? SCBR[30].r[CHIP][SCBR[30].enq[CHIP]][2] : SCM0[30].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[30].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[30].b[CHIP][0]:SCM0[30].awoo[CHIP][0]);
adr = (Ull)(SCM0[30].awoo[CHIP][0] + SCM0[30].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[30].r[CHIP][SCBR[30].enq[CHIP]][0] = SCM0[30].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[30].r[CHIP][SCBR[30].enq[CHIP]][0] = SCM0[30].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[30].r[CHIP][SCBR[30].enq[CHIP]][0] = SCM0[30].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[30].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[30].r[CHIP][SCBR[30].enq[CHIP]][0]:SCM1[30].b[CHIP][1]) : SCM1[30].awoo[CHIP][1];
SCM1[30].o[CHIP][1] = eam(1 ? SCBR[30].r[CHIP][SCBR[30].enq[CHIP]][2] : SCM1[30].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[30].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[30].b[CHIP][1]:SCM1[30].awoo[CHIP][1]);
adr = (Ull)(SCM1[30].awoo[CHIP][1] + SCM1[30].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[30].r[CHIP][SCBR[30].enq[CHIP]][5] = SCM1[30].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[30].r[CHIP][SCBR[30].enq[CHIP]][5] = SCM1[30].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[30].r[CHIP][SCBR[30].enq[CHIP]][5] = SCM1[30].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[30].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[30].r[CHIP][SCBR[30].enq[CHIP]][0]:SCM0[30].b[CHIP][1]) : SCM0[30].awoo[CHIP][1];
SCM0[30].o[CHIP][1] = eam(1 ? SCBR[30].r[CHIP][SCBR[30].enq[CHIP]][2] : SCM0[30].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[30].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[30].b[CHIP][1]:SCM0[30].awoo[CHIP][1]);
adr = (Ull)(SCM0[30].awoo[CHIP][1] + SCM0[30].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[30].r[CHIP][SCBR[30].enq[CHIP]][4] = SCM0[30].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[30].r[CHIP][SCBR[30].enq[CHIP]][4] = SCM0[30].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[30].r[CHIP][SCBR[30].enq[CHIP]][4] = SCM0[30].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[30].r[CHIP][SCBR[30].enq[CHIP]][2] = SCBR[29].r[CHIP][SCBR[2].enq[CHIP]][-1853687192];
SCBR[30].r[CHIP][SCBR[30].enq[CHIP]][3] = SCBR[29].r[CHIP][SCBR[3].enq[CHIP]][-1853687192];
}
{
}
{
}
{
}
uLOOP[30][CHIP]--;
SCBR[30].enq[CHIP] = 1-SCBR[30].enq[CHIP];
}
}
}
void emax6sc_pth_mm_31(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit31 */
uLOOP[31][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[31][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[31][CHIP]==0) continue;
if ((31 && SCBR[30].enq[CHIP]==SCBR[30].deq[CHIP]) || SCBR[31].enq[CHIP]!=SCBR[31].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[31][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[31][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[30].deq[CHIP] = 1-SCBR[30].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[31].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[31].r[CHIP][SCBR[31].enq[CHIP]][0]:SCM1[31].b[CHIP][0]) : SCM1[31].awoo[CHIP][0];
SCM1[31].o[CHIP][0] = eam(1 ? SCBR[31].r[CHIP][SCBR[31].enq[CHIP]][2] : SCM1[31].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[31].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[31].b[CHIP][0]:SCM1[31].awoo[CHIP][0]);
adr = (Ull)(SCM1[31].awoo[CHIP][0] + SCM1[31].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[31].r[CHIP][SCBR[31].enq[CHIP]][1] = SCM1[31].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[31].r[CHIP][SCBR[31].enq[CHIP]][1] = SCM1[31].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[31].r[CHIP][SCBR[31].enq[CHIP]][1] = SCM1[31].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[31].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[31].r[CHIP][SCBR[31].enq[CHIP]][0]:SCM0[31].b[CHIP][0]) : SCM0[31].awoo[CHIP][0];
SCM0[31].o[CHIP][0] = eam(1 ? SCBR[31].r[CHIP][SCBR[31].enq[CHIP]][2] : SCM0[31].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[31].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[31].b[CHIP][0]:SCM0[31].awoo[CHIP][0]);
adr = (Ull)(SCM0[31].awoo[CHIP][0] + SCM0[31].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[31].r[CHIP][SCBR[31].enq[CHIP]][0] = SCM0[31].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[31].r[CHIP][SCBR[31].enq[CHIP]][0] = SCM0[31].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[31].r[CHIP][SCBR[31].enq[CHIP]][0] = SCM0[31].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[31].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[31].r[CHIP][SCBR[31].enq[CHIP]][0]:SCM1[31].b[CHIP][1]) : SCM1[31].awoo[CHIP][1];
SCM1[31].o[CHIP][1] = eam(1 ? SCBR[31].r[CHIP][SCBR[31].enq[CHIP]][2] : SCM1[31].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[31].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[31].b[CHIP][1]:SCM1[31].awoo[CHIP][1]);
adr = (Ull)(SCM1[31].awoo[CHIP][1] + SCM1[31].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[31].r[CHIP][SCBR[31].enq[CHIP]][5] = SCM1[31].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[31].r[CHIP][SCBR[31].enq[CHIP]][5] = SCM1[31].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[31].r[CHIP][SCBR[31].enq[CHIP]][5] = SCM1[31].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[31].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[31].r[CHIP][SCBR[31].enq[CHIP]][0]:SCM0[31].b[CHIP][1]) : SCM0[31].awoo[CHIP][1];
SCM0[31].o[CHIP][1] = eam(1 ? SCBR[31].r[CHIP][SCBR[31].enq[CHIP]][2] : SCM0[31].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[31].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[31].b[CHIP][1]:SCM0[31].awoo[CHIP][1]);
adr = (Ull)(SCM0[31].awoo[CHIP][1] + SCM0[31].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[31].r[CHIP][SCBR[31].enq[CHIP]][4] = SCM0[31].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[31].r[CHIP][SCBR[31].enq[CHIP]][4] = SCM0[31].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[31].r[CHIP][SCBR[31].enq[CHIP]][4] = SCM0[31].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[31].r[CHIP][SCBR[31].enq[CHIP]][2] = SCBR[30].r[CHIP][SCBR[2].enq[CHIP]][-1853687064];
SCBR[31].r[CHIP][SCBR[31].enq[CHIP]][3] = SCBR[30].r[CHIP][SCBR[3].enq[CHIP]][-1853687064];
}
{
}
{
}
{
}
uLOOP[31][CHIP]--;
SCBR[31].enq[CHIP] = 1-SCBR[31].enq[CHIP];
}
}
}
void emax6sc_pth_mm_32(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit32 */
uLOOP[32][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[32][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[32][CHIP]==0) continue;
if ((32 && SCBR[31].enq[CHIP]==SCBR[31].deq[CHIP]) || SCBR[32].enq[CHIP]!=SCBR[32].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[32][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[32][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[31].deq[CHIP] = 1-SCBR[31].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[32].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[32].r[CHIP][SCBR[32].enq[CHIP]][0]:SCM1[32].b[CHIP][0]) : SCM1[32].awoo[CHIP][0];
SCM1[32].o[CHIP][0] = eam(1 ? SCBR[32].r[CHIP][SCBR[32].enq[CHIP]][2] : SCM1[32].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[32].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[32].b[CHIP][0]:SCM1[32].awoo[CHIP][0]);
adr = (Ull)(SCM1[32].awoo[CHIP][0] + SCM1[32].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[32].r[CHIP][SCBR[32].enq[CHIP]][1] = SCM1[32].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[32].r[CHIP][SCBR[32].enq[CHIP]][1] = SCM1[32].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[32].r[CHIP][SCBR[32].enq[CHIP]][1] = SCM1[32].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[32].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[32].r[CHIP][SCBR[32].enq[CHIP]][0]:SCM0[32].b[CHIP][0]) : SCM0[32].awoo[CHIP][0];
SCM0[32].o[CHIP][0] = eam(1 ? SCBR[32].r[CHIP][SCBR[32].enq[CHIP]][2] : SCM0[32].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[32].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[32].b[CHIP][0]:SCM0[32].awoo[CHIP][0]);
adr = (Ull)(SCM0[32].awoo[CHIP][0] + SCM0[32].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[32].r[CHIP][SCBR[32].enq[CHIP]][0] = SCM0[32].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[32].r[CHIP][SCBR[32].enq[CHIP]][0] = SCM0[32].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[32].r[CHIP][SCBR[32].enq[CHIP]][0] = SCM0[32].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[32].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[32].r[CHIP][SCBR[32].enq[CHIP]][0]:SCM1[32].b[CHIP][1]) : SCM1[32].awoo[CHIP][1];
SCM1[32].o[CHIP][1] = eam(1 ? SCBR[32].r[CHIP][SCBR[32].enq[CHIP]][2] : SCM1[32].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[32].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[32].b[CHIP][1]:SCM1[32].awoo[CHIP][1]);
adr = (Ull)(SCM1[32].awoo[CHIP][1] + SCM1[32].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[32].r[CHIP][SCBR[32].enq[CHIP]][5] = SCM1[32].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[32].r[CHIP][SCBR[32].enq[CHIP]][5] = SCM1[32].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[32].r[CHIP][SCBR[32].enq[CHIP]][5] = SCM1[32].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[32].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[32].r[CHIP][SCBR[32].enq[CHIP]][0]:SCM0[32].b[CHIP][1]) : SCM0[32].awoo[CHIP][1];
SCM0[32].o[CHIP][1] = eam(1 ? SCBR[32].r[CHIP][SCBR[32].enq[CHIP]][2] : SCM0[32].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[32].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[32].b[CHIP][1]:SCM0[32].awoo[CHIP][1]);
adr = (Ull)(SCM0[32].awoo[CHIP][1] + SCM0[32].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[32].r[CHIP][SCBR[32].enq[CHIP]][4] = SCM0[32].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[32].r[CHIP][SCBR[32].enq[CHIP]][4] = SCM0[32].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[32].r[CHIP][SCBR[32].enq[CHIP]][4] = SCM0[32].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[32].r[CHIP][SCBR[32].enq[CHIP]][2] = SCBR[31].r[CHIP][SCBR[2].enq[CHIP]][-1853686936];
SCBR[32].r[CHIP][SCBR[32].enq[CHIP]][3] = SCBR[31].r[CHIP][SCBR[3].enq[CHIP]][-1853686936];
}
{
}
{
}
{
}
uLOOP[32][CHIP]--;
SCBR[32].enq[CHIP] = 1-SCBR[32].enq[CHIP];
}
}
}
void emax6sc_pth_mm_33(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit33 */
uLOOP[33][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[33][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[33][CHIP]==0) continue;
if ((33 && SCBR[32].enq[CHIP]==SCBR[32].deq[CHIP]) || SCBR[33].enq[CHIP]!=SCBR[33].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[33][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[33][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[32].deq[CHIP] = 1-SCBR[32].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[33].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[33].r[CHIP][SCBR[33].enq[CHIP]][0]:SCM1[33].b[CHIP][0]) : SCM1[33].awoo[CHIP][0];
SCM1[33].o[CHIP][0] = eam(1 ? SCBR[33].r[CHIP][SCBR[33].enq[CHIP]][2] : SCM1[33].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[33].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[33].b[CHIP][0]:SCM1[33].awoo[CHIP][0]);
adr = (Ull)(SCM1[33].awoo[CHIP][0] + SCM1[33].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[33].r[CHIP][SCBR[33].enq[CHIP]][1] = SCM1[33].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[33].r[CHIP][SCBR[33].enq[CHIP]][1] = SCM1[33].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[33].r[CHIP][SCBR[33].enq[CHIP]][1] = SCM1[33].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[33].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[33].r[CHIP][SCBR[33].enq[CHIP]][0]:SCM0[33].b[CHIP][0]) : SCM0[33].awoo[CHIP][0];
SCM0[33].o[CHIP][0] = eam(1 ? SCBR[33].r[CHIP][SCBR[33].enq[CHIP]][2] : SCM0[33].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[33].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[33].b[CHIP][0]:SCM0[33].awoo[CHIP][0]);
adr = (Ull)(SCM0[33].awoo[CHIP][0] + SCM0[33].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[33].r[CHIP][SCBR[33].enq[CHIP]][0] = SCM0[33].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[33].r[CHIP][SCBR[33].enq[CHIP]][0] = SCM0[33].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[33].r[CHIP][SCBR[33].enq[CHIP]][0] = SCM0[33].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[33].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[33].r[CHIP][SCBR[33].enq[CHIP]][0]:SCM1[33].b[CHIP][1]) : SCM1[33].awoo[CHIP][1];
SCM1[33].o[CHIP][1] = eam(1 ? SCBR[33].r[CHIP][SCBR[33].enq[CHIP]][2] : SCM1[33].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[33].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[33].b[CHIP][1]:SCM1[33].awoo[CHIP][1]);
adr = (Ull)(SCM1[33].awoo[CHIP][1] + SCM1[33].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[33].r[CHIP][SCBR[33].enq[CHIP]][5] = SCM1[33].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[33].r[CHIP][SCBR[33].enq[CHIP]][5] = SCM1[33].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[33].r[CHIP][SCBR[33].enq[CHIP]][5] = SCM1[33].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[33].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[33].r[CHIP][SCBR[33].enq[CHIP]][0]:SCM0[33].b[CHIP][1]) : SCM0[33].awoo[CHIP][1];
SCM0[33].o[CHIP][1] = eam(1 ? SCBR[33].r[CHIP][SCBR[33].enq[CHIP]][2] : SCM0[33].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[33].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[33].b[CHIP][1]:SCM0[33].awoo[CHIP][1]);
adr = (Ull)(SCM0[33].awoo[CHIP][1] + SCM0[33].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[33].r[CHIP][SCBR[33].enq[CHIP]][4] = SCM0[33].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[33].r[CHIP][SCBR[33].enq[CHIP]][4] = SCM0[33].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[33].r[CHIP][SCBR[33].enq[CHIP]][4] = SCM0[33].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[33].r[CHIP][SCBR[33].enq[CHIP]][2] = SCBR[32].r[CHIP][SCBR[2].enq[CHIP]][-1853686808];
SCBR[33].r[CHIP][SCBR[33].enq[CHIP]][3] = SCBR[32].r[CHIP][SCBR[3].enq[CHIP]][-1853686808];
}
{
}
{
}
{
}
uLOOP[33][CHIP]--;
SCBR[33].enq[CHIP] = 1-SCBR[33].enq[CHIP];
}
}
}
void emax6sc_pth_mm_34(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit34 */
uLOOP[34][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[34][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[34][CHIP]==0) continue;
if ((34 && SCBR[33].enq[CHIP]==SCBR[33].deq[CHIP]) || SCBR[34].enq[CHIP]!=SCBR[34].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[34][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[34][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[33].deq[CHIP] = 1-SCBR[33].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[34].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[34].r[CHIP][SCBR[34].enq[CHIP]][0]:SCM1[34].b[CHIP][0]) : SCM1[34].awoo[CHIP][0];
SCM1[34].o[CHIP][0] = eam(1 ? SCBR[34].r[CHIP][SCBR[34].enq[CHIP]][2] : SCM1[34].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[34].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[34].b[CHIP][0]:SCM1[34].awoo[CHIP][0]);
adr = (Ull)(SCM1[34].awoo[CHIP][0] + SCM1[34].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[34].r[CHIP][SCBR[34].enq[CHIP]][1] = SCM1[34].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[34].r[CHIP][SCBR[34].enq[CHIP]][1] = SCM1[34].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[34].r[CHIP][SCBR[34].enq[CHIP]][1] = SCM1[34].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[34].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[34].r[CHIP][SCBR[34].enq[CHIP]][0]:SCM0[34].b[CHIP][0]) : SCM0[34].awoo[CHIP][0];
SCM0[34].o[CHIP][0] = eam(1 ? SCBR[34].r[CHIP][SCBR[34].enq[CHIP]][2] : SCM0[34].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[34].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[34].b[CHIP][0]:SCM0[34].awoo[CHIP][0]);
adr = (Ull)(SCM0[34].awoo[CHIP][0] + SCM0[34].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[34].r[CHIP][SCBR[34].enq[CHIP]][0] = SCM0[34].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[34].r[CHIP][SCBR[34].enq[CHIP]][0] = SCM0[34].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[34].r[CHIP][SCBR[34].enq[CHIP]][0] = SCM0[34].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[34].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[34].r[CHIP][SCBR[34].enq[CHIP]][0]:SCM1[34].b[CHIP][1]) : SCM1[34].awoo[CHIP][1];
SCM1[34].o[CHIP][1] = eam(1 ? SCBR[34].r[CHIP][SCBR[34].enq[CHIP]][2] : SCM1[34].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[34].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[34].b[CHIP][1]:SCM1[34].awoo[CHIP][1]);
adr = (Ull)(SCM1[34].awoo[CHIP][1] + SCM1[34].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[34].r[CHIP][SCBR[34].enq[CHIP]][5] = SCM1[34].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[34].r[CHIP][SCBR[34].enq[CHIP]][5] = SCM1[34].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[34].r[CHIP][SCBR[34].enq[CHIP]][5] = SCM1[34].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[34].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[34].r[CHIP][SCBR[34].enq[CHIP]][0]:SCM0[34].b[CHIP][1]) : SCM0[34].awoo[CHIP][1];
SCM0[34].o[CHIP][1] = eam(1 ? SCBR[34].r[CHIP][SCBR[34].enq[CHIP]][2] : SCM0[34].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[34].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[34].b[CHIP][1]:SCM0[34].awoo[CHIP][1]);
adr = (Ull)(SCM0[34].awoo[CHIP][1] + SCM0[34].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[34].r[CHIP][SCBR[34].enq[CHIP]][4] = SCM0[34].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[34].r[CHIP][SCBR[34].enq[CHIP]][4] = SCM0[34].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[34].r[CHIP][SCBR[34].enq[CHIP]][4] = SCM0[34].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[34].r[CHIP][SCBR[34].enq[CHIP]][2] = SCBR[33].r[CHIP][SCBR[2].enq[CHIP]][-1853686680];
SCBR[34].r[CHIP][SCBR[34].enq[CHIP]][3] = SCBR[33].r[CHIP][SCBR[3].enq[CHIP]][-1853686680];
}
{
}
{
}
{
}
uLOOP[34][CHIP]--;
SCBR[34].enq[CHIP] = 1-SCBR[34].enq[CHIP];
}
}
}
void emax6sc_pth_mm_35(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit35 */
uLOOP[35][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[35][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[35][CHIP]==0) continue;
if ((35 && SCBR[34].enq[CHIP]==SCBR[34].deq[CHIP]) || SCBR[35].enq[CHIP]!=SCBR[35].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[35][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[35][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[34].deq[CHIP] = 1-SCBR[34].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[35].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[35].r[CHIP][SCBR[35].enq[CHIP]][0]:SCM1[35].b[CHIP][0]) : SCM1[35].awoo[CHIP][0];
SCM1[35].o[CHIP][0] = eam(1 ? SCBR[35].r[CHIP][SCBR[35].enq[CHIP]][2] : SCM1[35].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[35].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[35].b[CHIP][0]:SCM1[35].awoo[CHIP][0]);
adr = (Ull)(SCM1[35].awoo[CHIP][0] + SCM1[35].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[35].r[CHIP][SCBR[35].enq[CHIP]][1] = SCM1[35].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[35].r[CHIP][SCBR[35].enq[CHIP]][1] = SCM1[35].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[35].r[CHIP][SCBR[35].enq[CHIP]][1] = SCM1[35].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[35].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[35].r[CHIP][SCBR[35].enq[CHIP]][0]:SCM0[35].b[CHIP][0]) : SCM0[35].awoo[CHIP][0];
SCM0[35].o[CHIP][0] = eam(1 ? SCBR[35].r[CHIP][SCBR[35].enq[CHIP]][2] : SCM0[35].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[35].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[35].b[CHIP][0]:SCM0[35].awoo[CHIP][0]);
adr = (Ull)(SCM0[35].awoo[CHIP][0] + SCM0[35].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[35].r[CHIP][SCBR[35].enq[CHIP]][0] = SCM0[35].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[35].r[CHIP][SCBR[35].enq[CHIP]][0] = SCM0[35].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[35].r[CHIP][SCBR[35].enq[CHIP]][0] = SCM0[35].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[35].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[35].r[CHIP][SCBR[35].enq[CHIP]][0]:SCM1[35].b[CHIP][1]) : SCM1[35].awoo[CHIP][1];
SCM1[35].o[CHIP][1] = eam(1 ? SCBR[35].r[CHIP][SCBR[35].enq[CHIP]][2] : SCM1[35].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[35].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[35].b[CHIP][1]:SCM1[35].awoo[CHIP][1]);
adr = (Ull)(SCM1[35].awoo[CHIP][1] + SCM1[35].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[35].r[CHIP][SCBR[35].enq[CHIP]][5] = SCM1[35].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[35].r[CHIP][SCBR[35].enq[CHIP]][5] = SCM1[35].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[35].r[CHIP][SCBR[35].enq[CHIP]][5] = SCM1[35].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[35].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[35].r[CHIP][SCBR[35].enq[CHIP]][0]:SCM0[35].b[CHIP][1]) : SCM0[35].awoo[CHIP][1];
SCM0[35].o[CHIP][1] = eam(1 ? SCBR[35].r[CHIP][SCBR[35].enq[CHIP]][2] : SCM0[35].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[35].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[35].b[CHIP][1]:SCM0[35].awoo[CHIP][1]);
adr = (Ull)(SCM0[35].awoo[CHIP][1] + SCM0[35].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[35].r[CHIP][SCBR[35].enq[CHIP]][4] = SCM0[35].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[35].r[CHIP][SCBR[35].enq[CHIP]][4] = SCM0[35].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[35].r[CHIP][SCBR[35].enq[CHIP]][4] = SCM0[35].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[35].r[CHIP][SCBR[35].enq[CHIP]][2] = SCBR[34].r[CHIP][SCBR[2].enq[CHIP]][-1853686552];
SCBR[35].r[CHIP][SCBR[35].enq[CHIP]][3] = SCBR[34].r[CHIP][SCBR[3].enq[CHIP]][-1853686552];
}
{
}
{
}
{
}
uLOOP[35][CHIP]--;
SCBR[35].enq[CHIP] = 1-SCBR[35].enq[CHIP];
}
}
}
void emax6sc_pth_mm_36(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit36 */
uLOOP[36][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[36][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[36][CHIP]==0) continue;
if ((36 && SCBR[35].enq[CHIP]==SCBR[35].deq[CHIP]) || SCBR[36].enq[CHIP]!=SCBR[36].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[36][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[36][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[35].deq[CHIP] = 1-SCBR[35].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[36].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[36].r[CHIP][SCBR[36].enq[CHIP]][0]:SCM1[36].b[CHIP][0]) : SCM1[36].awoo[CHIP][0];
SCM1[36].o[CHIP][0] = eam(1 ? SCBR[36].r[CHIP][SCBR[36].enq[CHIP]][2] : SCM1[36].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[36].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[36].b[CHIP][0]:SCM1[36].awoo[CHIP][0]);
adr = (Ull)(SCM1[36].awoo[CHIP][0] + SCM1[36].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[36].r[CHIP][SCBR[36].enq[CHIP]][1] = SCM1[36].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[36].r[CHIP][SCBR[36].enq[CHIP]][1] = SCM1[36].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[36].r[CHIP][SCBR[36].enq[CHIP]][1] = SCM1[36].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[36].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[36].r[CHIP][SCBR[36].enq[CHIP]][0]:SCM0[36].b[CHIP][0]) : SCM0[36].awoo[CHIP][0];
SCM0[36].o[CHIP][0] = eam(1 ? SCBR[36].r[CHIP][SCBR[36].enq[CHIP]][2] : SCM0[36].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[36].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[36].b[CHIP][0]:SCM0[36].awoo[CHIP][0]);
adr = (Ull)(SCM0[36].awoo[CHIP][0] + SCM0[36].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[36].r[CHIP][SCBR[36].enq[CHIP]][0] = SCM0[36].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[36].r[CHIP][SCBR[36].enq[CHIP]][0] = SCM0[36].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[36].r[CHIP][SCBR[36].enq[CHIP]][0] = SCM0[36].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[36].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[36].r[CHIP][SCBR[36].enq[CHIP]][0]:SCM1[36].b[CHIP][1]) : SCM1[36].awoo[CHIP][1];
SCM1[36].o[CHIP][1] = eam(1 ? SCBR[36].r[CHIP][SCBR[36].enq[CHIP]][2] : SCM1[36].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[36].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[36].b[CHIP][1]:SCM1[36].awoo[CHIP][1]);
adr = (Ull)(SCM1[36].awoo[CHIP][1] + SCM1[36].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[36].r[CHIP][SCBR[36].enq[CHIP]][5] = SCM1[36].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[36].r[CHIP][SCBR[36].enq[CHIP]][5] = SCM1[36].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[36].r[CHIP][SCBR[36].enq[CHIP]][5] = SCM1[36].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[36].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[36].r[CHIP][SCBR[36].enq[CHIP]][0]:SCM0[36].b[CHIP][1]) : SCM0[36].awoo[CHIP][1];
SCM0[36].o[CHIP][1] = eam(1 ? SCBR[36].r[CHIP][SCBR[36].enq[CHIP]][2] : SCM0[36].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[36].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[36].b[CHIP][1]:SCM0[36].awoo[CHIP][1]);
adr = (Ull)(SCM0[36].awoo[CHIP][1] + SCM0[36].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[36].r[CHIP][SCBR[36].enq[CHIP]][4] = SCM0[36].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[36].r[CHIP][SCBR[36].enq[CHIP]][4] = SCM0[36].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[36].r[CHIP][SCBR[36].enq[CHIP]][4] = SCM0[36].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[36].r[CHIP][SCBR[36].enq[CHIP]][2] = SCBR[35].r[CHIP][SCBR[2].enq[CHIP]][-1853686424];
SCBR[36].r[CHIP][SCBR[36].enq[CHIP]][3] = SCBR[35].r[CHIP][SCBR[3].enq[CHIP]][-1853686424];
}
{
}
{
}
{
}
uLOOP[36][CHIP]--;
SCBR[36].enq[CHIP] = 1-SCBR[36].enq[CHIP];
}
}
}
void emax6sc_pth_mm_37(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit37 */
uLOOP[37][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[37][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[37][CHIP]==0) continue;
if ((37 && SCBR[36].enq[CHIP]==SCBR[36].deq[CHIP]) || SCBR[37].enq[CHIP]!=SCBR[37].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[37][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[37][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[36].deq[CHIP] = 1-SCBR[36].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[37].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[37].r[CHIP][SCBR[37].enq[CHIP]][0]:SCM1[37].b[CHIP][0]) : SCM1[37].awoo[CHIP][0];
SCM1[37].o[CHIP][0] = eam(1 ? SCBR[37].r[CHIP][SCBR[37].enq[CHIP]][2] : SCM1[37].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[37].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[37].b[CHIP][0]:SCM1[37].awoo[CHIP][0]);
adr = (Ull)(SCM1[37].awoo[CHIP][0] + SCM1[37].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[37].r[CHIP][SCBR[37].enq[CHIP]][1] = SCM1[37].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[37].r[CHIP][SCBR[37].enq[CHIP]][1] = SCM1[37].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[37].r[CHIP][SCBR[37].enq[CHIP]][1] = SCM1[37].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[37].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[37].r[CHIP][SCBR[37].enq[CHIP]][0]:SCM0[37].b[CHIP][0]) : SCM0[37].awoo[CHIP][0];
SCM0[37].o[CHIP][0] = eam(1 ? SCBR[37].r[CHIP][SCBR[37].enq[CHIP]][2] : SCM0[37].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[37].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[37].b[CHIP][0]:SCM0[37].awoo[CHIP][0]);
adr = (Ull)(SCM0[37].awoo[CHIP][0] + SCM0[37].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[37].r[CHIP][SCBR[37].enq[CHIP]][0] = SCM0[37].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[37].r[CHIP][SCBR[37].enq[CHIP]][0] = SCM0[37].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[37].r[CHIP][SCBR[37].enq[CHIP]][0] = SCM0[37].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[37].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[37].r[CHIP][SCBR[37].enq[CHIP]][0]:SCM1[37].b[CHIP][1]) : SCM1[37].awoo[CHIP][1];
SCM1[37].o[CHIP][1] = eam(1 ? SCBR[37].r[CHIP][SCBR[37].enq[CHIP]][2] : SCM1[37].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[37].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[37].b[CHIP][1]:SCM1[37].awoo[CHIP][1]);
adr = (Ull)(SCM1[37].awoo[CHIP][1] + SCM1[37].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[37].r[CHIP][SCBR[37].enq[CHIP]][5] = SCM1[37].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[37].r[CHIP][SCBR[37].enq[CHIP]][5] = SCM1[37].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[37].r[CHIP][SCBR[37].enq[CHIP]][5] = SCM1[37].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[37].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[37].r[CHIP][SCBR[37].enq[CHIP]][0]:SCM0[37].b[CHIP][1]) : SCM0[37].awoo[CHIP][1];
SCM0[37].o[CHIP][1] = eam(1 ? SCBR[37].r[CHIP][SCBR[37].enq[CHIP]][2] : SCM0[37].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[37].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[37].b[CHIP][1]:SCM0[37].awoo[CHIP][1]);
adr = (Ull)(SCM0[37].awoo[CHIP][1] + SCM0[37].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[37].r[CHIP][SCBR[37].enq[CHIP]][4] = SCM0[37].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[37].r[CHIP][SCBR[37].enq[CHIP]][4] = SCM0[37].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[37].r[CHIP][SCBR[37].enq[CHIP]][4] = SCM0[37].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[37].r[CHIP][SCBR[37].enq[CHIP]][2] = SCBR[36].r[CHIP][SCBR[2].enq[CHIP]][-1853686296];
SCBR[37].r[CHIP][SCBR[37].enq[CHIP]][3] = SCBR[36].r[CHIP][SCBR[3].enq[CHIP]][-1853686296];
}
{
}
{
}
{
}
uLOOP[37][CHIP]--;
SCBR[37].enq[CHIP] = 1-SCBR[37].enq[CHIP];
}
}
}
void emax6sc_pth_mm_38(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit38 */
uLOOP[38][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[38][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[38][CHIP]==0) continue;
if ((38 && SCBR[37].enq[CHIP]==SCBR[37].deq[CHIP]) || SCBR[38].enq[CHIP]!=SCBR[38].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[38][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[38][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[37].deq[CHIP] = 1-SCBR[37].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[38].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[38].r[CHIP][SCBR[38].enq[CHIP]][0]:SCM1[38].b[CHIP][0]) : SCM1[38].awoo[CHIP][0];
SCM1[38].o[CHIP][0] = eam(1 ? SCBR[38].r[CHIP][SCBR[38].enq[CHIP]][2] : SCM1[38].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[38].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[38].b[CHIP][0]:SCM1[38].awoo[CHIP][0]);
adr = (Ull)(SCM1[38].awoo[CHIP][0] + SCM1[38].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[38].r[CHIP][SCBR[38].enq[CHIP]][1] = SCM1[38].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[38].r[CHIP][SCBR[38].enq[CHIP]][1] = SCM1[38].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[38].r[CHIP][SCBR[38].enq[CHIP]][1] = SCM1[38].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[38].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[38].r[CHIP][SCBR[38].enq[CHIP]][0]:SCM0[38].b[CHIP][0]) : SCM0[38].awoo[CHIP][0];
SCM0[38].o[CHIP][0] = eam(1 ? SCBR[38].r[CHIP][SCBR[38].enq[CHIP]][2] : SCM0[38].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[38].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[38].b[CHIP][0]:SCM0[38].awoo[CHIP][0]);
adr = (Ull)(SCM0[38].awoo[CHIP][0] + SCM0[38].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[38].r[CHIP][SCBR[38].enq[CHIP]][0] = SCM0[38].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[38].r[CHIP][SCBR[38].enq[CHIP]][0] = SCM0[38].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[38].r[CHIP][SCBR[38].enq[CHIP]][0] = SCM0[38].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[38].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[38].r[CHIP][SCBR[38].enq[CHIP]][0]:SCM1[38].b[CHIP][1]) : SCM1[38].awoo[CHIP][1];
SCM1[38].o[CHIP][1] = eam(1 ? SCBR[38].r[CHIP][SCBR[38].enq[CHIP]][2] : SCM1[38].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[38].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[38].b[CHIP][1]:SCM1[38].awoo[CHIP][1]);
adr = (Ull)(SCM1[38].awoo[CHIP][1] + SCM1[38].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[38].r[CHIP][SCBR[38].enq[CHIP]][5] = SCM1[38].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[38].r[CHIP][SCBR[38].enq[CHIP]][5] = SCM1[38].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[38].r[CHIP][SCBR[38].enq[CHIP]][5] = SCM1[38].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[38].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[38].r[CHIP][SCBR[38].enq[CHIP]][0]:SCM0[38].b[CHIP][1]) : SCM0[38].awoo[CHIP][1];
SCM0[38].o[CHIP][1] = eam(1 ? SCBR[38].r[CHIP][SCBR[38].enq[CHIP]][2] : SCM0[38].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[38].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[38].b[CHIP][1]:SCM0[38].awoo[CHIP][1]);
adr = (Ull)(SCM0[38].awoo[CHIP][1] + SCM0[38].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[38].r[CHIP][SCBR[38].enq[CHIP]][4] = SCM0[38].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[38].r[CHIP][SCBR[38].enq[CHIP]][4] = SCM0[38].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[38].r[CHIP][SCBR[38].enq[CHIP]][4] = SCM0[38].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[38].r[CHIP][SCBR[38].enq[CHIP]][2] = SCBR[37].r[CHIP][SCBR[2].enq[CHIP]][-1853686168];
SCBR[38].r[CHIP][SCBR[38].enq[CHIP]][3] = SCBR[37].r[CHIP][SCBR[3].enq[CHIP]][-1853686168];
}
{
}
{
}
{
}
uLOOP[38][CHIP]--;
SCBR[38].enq[CHIP] = 1-SCBR[38].enq[CHIP];
}
}
}
void emax6sc_pth_mm_39(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit39 */
uLOOP[39][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[39][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[39][CHIP]==0) continue;
if ((39 && SCBR[38].enq[CHIP]==SCBR[38].deq[CHIP]) || SCBR[39].enq[CHIP]!=SCBR[39].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[39][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[39][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[38].deq[CHIP] = 1-SCBR[38].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[39].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[39].r[CHIP][SCBR[39].enq[CHIP]][0]:SCM1[39].b[CHIP][0]) : SCM1[39].awoo[CHIP][0];
SCM1[39].o[CHIP][0] = eam(1 ? SCBR[39].r[CHIP][SCBR[39].enq[CHIP]][2] : SCM1[39].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[39].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[39].b[CHIP][0]:SCM1[39].awoo[CHIP][0]);
adr = (Ull)(SCM1[39].awoo[CHIP][0] + SCM1[39].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[39].r[CHIP][SCBR[39].enq[CHIP]][1] = SCM1[39].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[39].r[CHIP][SCBR[39].enq[CHIP]][1] = SCM1[39].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[39].r[CHIP][SCBR[39].enq[CHIP]][1] = SCM1[39].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[39].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[39].r[CHIP][SCBR[39].enq[CHIP]][0]:SCM0[39].b[CHIP][0]) : SCM0[39].awoo[CHIP][0];
SCM0[39].o[CHIP][0] = eam(1 ? SCBR[39].r[CHIP][SCBR[39].enq[CHIP]][2] : SCM0[39].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[39].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[39].b[CHIP][0]:SCM0[39].awoo[CHIP][0]);
adr = (Ull)(SCM0[39].awoo[CHIP][0] + SCM0[39].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[39].r[CHIP][SCBR[39].enq[CHIP]][0] = SCM0[39].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[39].r[CHIP][SCBR[39].enq[CHIP]][0] = SCM0[39].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[39].r[CHIP][SCBR[39].enq[CHIP]][0] = SCM0[39].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[39].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[39].r[CHIP][SCBR[39].enq[CHIP]][0]:SCM1[39].b[CHIP][1]) : SCM1[39].awoo[CHIP][1];
SCM1[39].o[CHIP][1] = eam(1 ? SCBR[39].r[CHIP][SCBR[39].enq[CHIP]][2] : SCM1[39].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[39].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[39].b[CHIP][1]:SCM1[39].awoo[CHIP][1]);
adr = (Ull)(SCM1[39].awoo[CHIP][1] + SCM1[39].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[39].r[CHIP][SCBR[39].enq[CHIP]][5] = SCM1[39].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[39].r[CHIP][SCBR[39].enq[CHIP]][5] = SCM1[39].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[39].r[CHIP][SCBR[39].enq[CHIP]][5] = SCM1[39].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[39].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[39].r[CHIP][SCBR[39].enq[CHIP]][0]:SCM0[39].b[CHIP][1]) : SCM0[39].awoo[CHIP][1];
SCM0[39].o[CHIP][1] = eam(1 ? SCBR[39].r[CHIP][SCBR[39].enq[CHIP]][2] : SCM0[39].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[39].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[39].b[CHIP][1]:SCM0[39].awoo[CHIP][1]);
adr = (Ull)(SCM0[39].awoo[CHIP][1] + SCM0[39].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[39].r[CHIP][SCBR[39].enq[CHIP]][4] = SCM0[39].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[39].r[CHIP][SCBR[39].enq[CHIP]][4] = SCM0[39].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[39].r[CHIP][SCBR[39].enq[CHIP]][4] = SCM0[39].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[39].r[CHIP][SCBR[39].enq[CHIP]][2] = SCBR[38].r[CHIP][SCBR[2].enq[CHIP]][-1853686040];
SCBR[39].r[CHIP][SCBR[39].enq[CHIP]][3] = SCBR[38].r[CHIP][SCBR[3].enq[CHIP]][-1853686040];
}
{
}
{
}
{
}
uLOOP[39][CHIP]--;
SCBR[39].enq[CHIP] = 1-SCBR[39].enq[CHIP];
}
}
}
void emax6sc_pth_mm_40(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit40 */
uLOOP[40][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[40][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[40][CHIP]==0) continue;
if ((40 && SCBR[39].enq[CHIP]==SCBR[39].deq[CHIP]) || SCBR[40].enq[CHIP]!=SCBR[40].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[40][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[40][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[39].deq[CHIP] = 1-SCBR[39].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[40].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[40].r[CHIP][SCBR[40].enq[CHIP]][0]:SCM1[40].b[CHIP][0]) : SCM1[40].awoo[CHIP][0];
SCM1[40].o[CHIP][0] = eam(1 ? SCBR[40].r[CHIP][SCBR[40].enq[CHIP]][2] : SCM1[40].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[40].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[40].b[CHIP][0]:SCM1[40].awoo[CHIP][0]);
adr = (Ull)(SCM1[40].awoo[CHIP][0] + SCM1[40].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[40].r[CHIP][SCBR[40].enq[CHIP]][1] = SCM1[40].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[40].r[CHIP][SCBR[40].enq[CHIP]][1] = SCM1[40].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[40].r[CHIP][SCBR[40].enq[CHIP]][1] = SCM1[40].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[40].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[40].r[CHIP][SCBR[40].enq[CHIP]][0]:SCM0[40].b[CHIP][0]) : SCM0[40].awoo[CHIP][0];
SCM0[40].o[CHIP][0] = eam(1 ? SCBR[40].r[CHIP][SCBR[40].enq[CHIP]][2] : SCM0[40].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[40].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[40].b[CHIP][0]:SCM0[40].awoo[CHIP][0]);
adr = (Ull)(SCM0[40].awoo[CHIP][0] + SCM0[40].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[40].r[CHIP][SCBR[40].enq[CHIP]][0] = SCM0[40].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[40].r[CHIP][SCBR[40].enq[CHIP]][0] = SCM0[40].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[40].r[CHIP][SCBR[40].enq[CHIP]][0] = SCM0[40].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[40].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[40].r[CHIP][SCBR[40].enq[CHIP]][0]:SCM1[40].b[CHIP][1]) : SCM1[40].awoo[CHIP][1];
SCM1[40].o[CHIP][1] = eam(1 ? SCBR[40].r[CHIP][SCBR[40].enq[CHIP]][2] : SCM1[40].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[40].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[40].b[CHIP][1]:SCM1[40].awoo[CHIP][1]);
adr = (Ull)(SCM1[40].awoo[CHIP][1] + SCM1[40].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[40].r[CHIP][SCBR[40].enq[CHIP]][5] = SCM1[40].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[40].r[CHIP][SCBR[40].enq[CHIP]][5] = SCM1[40].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[40].r[CHIP][SCBR[40].enq[CHIP]][5] = SCM1[40].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[40].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[40].r[CHIP][SCBR[40].enq[CHIP]][0]:SCM0[40].b[CHIP][1]) : SCM0[40].awoo[CHIP][1];
SCM0[40].o[CHIP][1] = eam(1 ? SCBR[40].r[CHIP][SCBR[40].enq[CHIP]][2] : SCM0[40].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[40].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[40].b[CHIP][1]:SCM0[40].awoo[CHIP][1]);
adr = (Ull)(SCM0[40].awoo[CHIP][1] + SCM0[40].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[40].r[CHIP][SCBR[40].enq[CHIP]][4] = SCM0[40].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[40].r[CHIP][SCBR[40].enq[CHIP]][4] = SCM0[40].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[40].r[CHIP][SCBR[40].enq[CHIP]][4] = SCM0[40].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[40].r[CHIP][SCBR[40].enq[CHIP]][2] = SCBR[39].r[CHIP][SCBR[2].enq[CHIP]][-1853685912];
SCBR[40].r[CHIP][SCBR[40].enq[CHIP]][3] = SCBR[39].r[CHIP][SCBR[3].enq[CHIP]][-1853685912];
}
{
}
{
}
{
}
uLOOP[40][CHIP]--;
SCBR[40].enq[CHIP] = 1-SCBR[40].enq[CHIP];
}
}
}
void emax6sc_pth_mm_41(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit41 */
uLOOP[41][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[41][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[41][CHIP]==0) continue;
if ((41 && SCBR[40].enq[CHIP]==SCBR[40].deq[CHIP]) || SCBR[41].enq[CHIP]!=SCBR[41].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[41][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[41][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[40].deq[CHIP] = 1-SCBR[40].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[41].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[41].r[CHIP][SCBR[41].enq[CHIP]][0]:SCM1[41].b[CHIP][0]) : SCM1[41].awoo[CHIP][0];
SCM1[41].o[CHIP][0] = eam(1 ? SCBR[41].r[CHIP][SCBR[41].enq[CHIP]][2] : SCM1[41].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[41].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[41].b[CHIP][0]:SCM1[41].awoo[CHIP][0]);
adr = (Ull)(SCM1[41].awoo[CHIP][0] + SCM1[41].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[41].r[CHIP][SCBR[41].enq[CHIP]][1] = SCM1[41].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[41].r[CHIP][SCBR[41].enq[CHIP]][1] = SCM1[41].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[41].r[CHIP][SCBR[41].enq[CHIP]][1] = SCM1[41].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[41].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[41].r[CHIP][SCBR[41].enq[CHIP]][0]:SCM0[41].b[CHIP][0]) : SCM0[41].awoo[CHIP][0];
SCM0[41].o[CHIP][0] = eam(1 ? SCBR[41].r[CHIP][SCBR[41].enq[CHIP]][2] : SCM0[41].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[41].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[41].b[CHIP][0]:SCM0[41].awoo[CHIP][0]);
adr = (Ull)(SCM0[41].awoo[CHIP][0] + SCM0[41].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[41].r[CHIP][SCBR[41].enq[CHIP]][0] = SCM0[41].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[41].r[CHIP][SCBR[41].enq[CHIP]][0] = SCM0[41].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[41].r[CHIP][SCBR[41].enq[CHIP]][0] = SCM0[41].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[41].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[41].r[CHIP][SCBR[41].enq[CHIP]][0]:SCM1[41].b[CHIP][1]) : SCM1[41].awoo[CHIP][1];
SCM1[41].o[CHIP][1] = eam(1 ? SCBR[41].r[CHIP][SCBR[41].enq[CHIP]][2] : SCM1[41].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[41].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[41].b[CHIP][1]:SCM1[41].awoo[CHIP][1]);
adr = (Ull)(SCM1[41].awoo[CHIP][1] + SCM1[41].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[41].r[CHIP][SCBR[41].enq[CHIP]][5] = SCM1[41].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[41].r[CHIP][SCBR[41].enq[CHIP]][5] = SCM1[41].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[41].r[CHIP][SCBR[41].enq[CHIP]][5] = SCM1[41].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[41].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[41].r[CHIP][SCBR[41].enq[CHIP]][0]:SCM0[41].b[CHIP][1]) : SCM0[41].awoo[CHIP][1];
SCM0[41].o[CHIP][1] = eam(1 ? SCBR[41].r[CHIP][SCBR[41].enq[CHIP]][2] : SCM0[41].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[41].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[41].b[CHIP][1]:SCM0[41].awoo[CHIP][1]);
adr = (Ull)(SCM0[41].awoo[CHIP][1] + SCM0[41].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[41].r[CHIP][SCBR[41].enq[CHIP]][4] = SCM0[41].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[41].r[CHIP][SCBR[41].enq[CHIP]][4] = SCM0[41].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[41].r[CHIP][SCBR[41].enq[CHIP]][4] = SCM0[41].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[41].r[CHIP][SCBR[41].enq[CHIP]][2] = SCBR[40].r[CHIP][SCBR[2].enq[CHIP]][-1853685784];
SCBR[41].r[CHIP][SCBR[41].enq[CHIP]][3] = SCBR[40].r[CHIP][SCBR[3].enq[CHIP]][-1853685784];
}
{
}
{
}
{
}
uLOOP[41][CHIP]--;
SCBR[41].enq[CHIP] = 1-SCBR[41].enq[CHIP];
}
}
}
void emax6sc_pth_mm_42(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit42 */
uLOOP[42][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[42][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[42][CHIP]==0) continue;
if ((42 && SCBR[41].enq[CHIP]==SCBR[41].deq[CHIP]) || SCBR[42].enq[CHIP]!=SCBR[42].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[42][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[42][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[41].deq[CHIP] = 1-SCBR[41].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[42].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[42].r[CHIP][SCBR[42].enq[CHIP]][0]:SCM1[42].b[CHIP][0]) : SCM1[42].awoo[CHIP][0];
SCM1[42].o[CHIP][0] = eam(1 ? SCBR[42].r[CHIP][SCBR[42].enq[CHIP]][2] : SCM1[42].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[42].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[42].b[CHIP][0]:SCM1[42].awoo[CHIP][0]);
adr = (Ull)(SCM1[42].awoo[CHIP][0] + SCM1[42].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[42].r[CHIP][SCBR[42].enq[CHIP]][1] = SCM1[42].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[42].r[CHIP][SCBR[42].enq[CHIP]][1] = SCM1[42].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[42].r[CHIP][SCBR[42].enq[CHIP]][1] = SCM1[42].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[42].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[42].r[CHIP][SCBR[42].enq[CHIP]][0]:SCM0[42].b[CHIP][0]) : SCM0[42].awoo[CHIP][0];
SCM0[42].o[CHIP][0] = eam(1 ? SCBR[42].r[CHIP][SCBR[42].enq[CHIP]][2] : SCM0[42].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[42].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[42].b[CHIP][0]:SCM0[42].awoo[CHIP][0]);
adr = (Ull)(SCM0[42].awoo[CHIP][0] + SCM0[42].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[42].r[CHIP][SCBR[42].enq[CHIP]][0] = SCM0[42].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[42].r[CHIP][SCBR[42].enq[CHIP]][0] = SCM0[42].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[42].r[CHIP][SCBR[42].enq[CHIP]][0] = SCM0[42].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[42].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[42].r[CHIP][SCBR[42].enq[CHIP]][0]:SCM1[42].b[CHIP][1]) : SCM1[42].awoo[CHIP][1];
SCM1[42].o[CHIP][1] = eam(1 ? SCBR[42].r[CHIP][SCBR[42].enq[CHIP]][2] : SCM1[42].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[42].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[42].b[CHIP][1]:SCM1[42].awoo[CHIP][1]);
adr = (Ull)(SCM1[42].awoo[CHIP][1] + SCM1[42].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[42].r[CHIP][SCBR[42].enq[CHIP]][5] = SCM1[42].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[42].r[CHIP][SCBR[42].enq[CHIP]][5] = SCM1[42].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[42].r[CHIP][SCBR[42].enq[CHIP]][5] = SCM1[42].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[42].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[42].r[CHIP][SCBR[42].enq[CHIP]][0]:SCM0[42].b[CHIP][1]) : SCM0[42].awoo[CHIP][1];
SCM0[42].o[CHIP][1] = eam(1 ? SCBR[42].r[CHIP][SCBR[42].enq[CHIP]][2] : SCM0[42].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[42].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[42].b[CHIP][1]:SCM0[42].awoo[CHIP][1]);
adr = (Ull)(SCM0[42].awoo[CHIP][1] + SCM0[42].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[42].r[CHIP][SCBR[42].enq[CHIP]][4] = SCM0[42].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[42].r[CHIP][SCBR[42].enq[CHIP]][4] = SCM0[42].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[42].r[CHIP][SCBR[42].enq[CHIP]][4] = SCM0[42].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[42].r[CHIP][SCBR[42].enq[CHIP]][2] = SCBR[41].r[CHIP][SCBR[2].enq[CHIP]][-1853685656];
SCBR[42].r[CHIP][SCBR[42].enq[CHIP]][3] = SCBR[41].r[CHIP][SCBR[3].enq[CHIP]][-1853685656];
}
{
}
{
}
{
}
uLOOP[42][CHIP]--;
SCBR[42].enq[CHIP] = 1-SCBR[42].enq[CHIP];
}
}
}
void emax6sc_pth_mm_43(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit43 */
uLOOP[43][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[43][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[43][CHIP]==0) continue;
if ((43 && SCBR[42].enq[CHIP]==SCBR[42].deq[CHIP]) || SCBR[43].enq[CHIP]!=SCBR[43].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[43][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[43][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[42].deq[CHIP] = 1-SCBR[42].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[43].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[43].r[CHIP][SCBR[43].enq[CHIP]][0]:SCM1[43].b[CHIP][0]) : SCM1[43].awoo[CHIP][0];
SCM1[43].o[CHIP][0] = eam(1 ? SCBR[43].r[CHIP][SCBR[43].enq[CHIP]][2] : SCM1[43].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[43].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[43].b[CHIP][0]:SCM1[43].awoo[CHIP][0]);
adr = (Ull)(SCM1[43].awoo[CHIP][0] + SCM1[43].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[43].r[CHIP][SCBR[43].enq[CHIP]][1] = SCM1[43].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[43].r[CHIP][SCBR[43].enq[CHIP]][1] = SCM1[43].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[43].r[CHIP][SCBR[43].enq[CHIP]][1] = SCM1[43].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[43].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[43].r[CHIP][SCBR[43].enq[CHIP]][0]:SCM0[43].b[CHIP][0]) : SCM0[43].awoo[CHIP][0];
SCM0[43].o[CHIP][0] = eam(1 ? SCBR[43].r[CHIP][SCBR[43].enq[CHIP]][2] : SCM0[43].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[43].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[43].b[CHIP][0]:SCM0[43].awoo[CHIP][0]);
adr = (Ull)(SCM0[43].awoo[CHIP][0] + SCM0[43].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[43].r[CHIP][SCBR[43].enq[CHIP]][0] = SCM0[43].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[43].r[CHIP][SCBR[43].enq[CHIP]][0] = SCM0[43].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[43].r[CHIP][SCBR[43].enq[CHIP]][0] = SCM0[43].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[43].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[43].r[CHIP][SCBR[43].enq[CHIP]][0]:SCM1[43].b[CHIP][1]) : SCM1[43].awoo[CHIP][1];
SCM1[43].o[CHIP][1] = eam(1 ? SCBR[43].r[CHIP][SCBR[43].enq[CHIP]][2] : SCM1[43].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[43].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[43].b[CHIP][1]:SCM1[43].awoo[CHIP][1]);
adr = (Ull)(SCM1[43].awoo[CHIP][1] + SCM1[43].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[43].r[CHIP][SCBR[43].enq[CHIP]][5] = SCM1[43].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[43].r[CHIP][SCBR[43].enq[CHIP]][5] = SCM1[43].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[43].r[CHIP][SCBR[43].enq[CHIP]][5] = SCM1[43].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[43].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[43].r[CHIP][SCBR[43].enq[CHIP]][0]:SCM0[43].b[CHIP][1]) : SCM0[43].awoo[CHIP][1];
SCM0[43].o[CHIP][1] = eam(1 ? SCBR[43].r[CHIP][SCBR[43].enq[CHIP]][2] : SCM0[43].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[43].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[43].b[CHIP][1]:SCM0[43].awoo[CHIP][1]);
adr = (Ull)(SCM0[43].awoo[CHIP][1] + SCM0[43].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[43].r[CHIP][SCBR[43].enq[CHIP]][4] = SCM0[43].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[43].r[CHIP][SCBR[43].enq[CHIP]][4] = SCM0[43].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[43].r[CHIP][SCBR[43].enq[CHIP]][4] = SCM0[43].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[43].r[CHIP][SCBR[43].enq[CHIP]][2] = SCBR[42].r[CHIP][SCBR[2].enq[CHIP]][-1853685528];
SCBR[43].r[CHIP][SCBR[43].enq[CHIP]][3] = SCBR[42].r[CHIP][SCBR[3].enq[CHIP]][-1853685528];
}
{
}
{
}
{
}
uLOOP[43][CHIP]--;
SCBR[43].enq[CHIP] = 1-SCBR[43].enq[CHIP];
}
}
}
void emax6sc_pth_mm_44(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit44 */
uLOOP[44][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[44][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[44][CHIP]==0) continue;
if ((44 && SCBR[43].enq[CHIP]==SCBR[43].deq[CHIP]) || SCBR[44].enq[CHIP]!=SCBR[44].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[44][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[44][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[43].deq[CHIP] = 1-SCBR[43].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[44].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[44].r[CHIP][SCBR[44].enq[CHIP]][0]:SCM1[44].b[CHIP][0]) : SCM1[44].awoo[CHIP][0];
SCM1[44].o[CHIP][0] = eam(1 ? SCBR[44].r[CHIP][SCBR[44].enq[CHIP]][2] : SCM1[44].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[44].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[44].b[CHIP][0]:SCM1[44].awoo[CHIP][0]);
adr = (Ull)(SCM1[44].awoo[CHIP][0] + SCM1[44].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[44].r[CHIP][SCBR[44].enq[CHIP]][1] = SCM1[44].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[44].r[CHIP][SCBR[44].enq[CHIP]][1] = SCM1[44].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[44].r[CHIP][SCBR[44].enq[CHIP]][1] = SCM1[44].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[44].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[44].r[CHIP][SCBR[44].enq[CHIP]][0]:SCM0[44].b[CHIP][0]) : SCM0[44].awoo[CHIP][0];
SCM0[44].o[CHIP][0] = eam(1 ? SCBR[44].r[CHIP][SCBR[44].enq[CHIP]][2] : SCM0[44].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[44].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[44].b[CHIP][0]:SCM0[44].awoo[CHIP][0]);
adr = (Ull)(SCM0[44].awoo[CHIP][0] + SCM0[44].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[44].r[CHIP][SCBR[44].enq[CHIP]][0] = SCM0[44].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[44].r[CHIP][SCBR[44].enq[CHIP]][0] = SCM0[44].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[44].r[CHIP][SCBR[44].enq[CHIP]][0] = SCM0[44].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[44].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[44].r[CHIP][SCBR[44].enq[CHIP]][0]:SCM1[44].b[CHIP][1]) : SCM1[44].awoo[CHIP][1];
SCM1[44].o[CHIP][1] = eam(1 ? SCBR[44].r[CHIP][SCBR[44].enq[CHIP]][2] : SCM1[44].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[44].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[44].b[CHIP][1]:SCM1[44].awoo[CHIP][1]);
adr = (Ull)(SCM1[44].awoo[CHIP][1] + SCM1[44].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[44].r[CHIP][SCBR[44].enq[CHIP]][5] = SCM1[44].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[44].r[CHIP][SCBR[44].enq[CHIP]][5] = SCM1[44].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[44].r[CHIP][SCBR[44].enq[CHIP]][5] = SCM1[44].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[44].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[44].r[CHIP][SCBR[44].enq[CHIP]][0]:SCM0[44].b[CHIP][1]) : SCM0[44].awoo[CHIP][1];
SCM0[44].o[CHIP][1] = eam(1 ? SCBR[44].r[CHIP][SCBR[44].enq[CHIP]][2] : SCM0[44].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[44].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[44].b[CHIP][1]:SCM0[44].awoo[CHIP][1]);
adr = (Ull)(SCM0[44].awoo[CHIP][1] + SCM0[44].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[44].r[CHIP][SCBR[44].enq[CHIP]][4] = SCM0[44].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[44].r[CHIP][SCBR[44].enq[CHIP]][4] = SCM0[44].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[44].r[CHIP][SCBR[44].enq[CHIP]][4] = SCM0[44].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[44].r[CHIP][SCBR[44].enq[CHIP]][2] = SCBR[43].r[CHIP][SCBR[2].enq[CHIP]][-1853685400];
SCBR[44].r[CHIP][SCBR[44].enq[CHIP]][3] = SCBR[43].r[CHIP][SCBR[3].enq[CHIP]][-1853685400];
}
{
}
{
}
{
}
uLOOP[44][CHIP]--;
SCBR[44].enq[CHIP] = 1-SCBR[44].enq[CHIP];
}
}
}
void emax6sc_pth_mm_45(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit45 */
uLOOP[45][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[45][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[45][CHIP]==0) continue;
if ((45 && SCBR[44].enq[CHIP]==SCBR[44].deq[CHIP]) || SCBR[45].enq[CHIP]!=SCBR[45].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[45][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[45][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[44].deq[CHIP] = 1-SCBR[44].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[45].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[45].r[CHIP][SCBR[45].enq[CHIP]][0]:SCM1[45].b[CHIP][0]) : SCM1[45].awoo[CHIP][0];
SCM1[45].o[CHIP][0] = eam(1 ? SCBR[45].r[CHIP][SCBR[45].enq[CHIP]][2] : SCM1[45].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[45].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[45].b[CHIP][0]:SCM1[45].awoo[CHIP][0]);
adr = (Ull)(SCM1[45].awoo[CHIP][0] + SCM1[45].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[45].r[CHIP][SCBR[45].enq[CHIP]][1] = SCM1[45].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[45].r[CHIP][SCBR[45].enq[CHIP]][1] = SCM1[45].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[45].r[CHIP][SCBR[45].enq[CHIP]][1] = SCM1[45].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[45].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[45].r[CHIP][SCBR[45].enq[CHIP]][0]:SCM0[45].b[CHIP][0]) : SCM0[45].awoo[CHIP][0];
SCM0[45].o[CHIP][0] = eam(1 ? SCBR[45].r[CHIP][SCBR[45].enq[CHIP]][2] : SCM0[45].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[45].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[45].b[CHIP][0]:SCM0[45].awoo[CHIP][0]);
adr = (Ull)(SCM0[45].awoo[CHIP][0] + SCM0[45].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[45].r[CHIP][SCBR[45].enq[CHIP]][0] = SCM0[45].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[45].r[CHIP][SCBR[45].enq[CHIP]][0] = SCM0[45].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[45].r[CHIP][SCBR[45].enq[CHIP]][0] = SCM0[45].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[45].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[45].r[CHIP][SCBR[45].enq[CHIP]][0]:SCM1[45].b[CHIP][1]) : SCM1[45].awoo[CHIP][1];
SCM1[45].o[CHIP][1] = eam(1 ? SCBR[45].r[CHIP][SCBR[45].enq[CHIP]][2] : SCM1[45].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[45].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[45].b[CHIP][1]:SCM1[45].awoo[CHIP][1]);
adr = (Ull)(SCM1[45].awoo[CHIP][1] + SCM1[45].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[45].r[CHIP][SCBR[45].enq[CHIP]][5] = SCM1[45].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[45].r[CHIP][SCBR[45].enq[CHIP]][5] = SCM1[45].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[45].r[CHIP][SCBR[45].enq[CHIP]][5] = SCM1[45].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[45].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[45].r[CHIP][SCBR[45].enq[CHIP]][0]:SCM0[45].b[CHIP][1]) : SCM0[45].awoo[CHIP][1];
SCM0[45].o[CHIP][1] = eam(1 ? SCBR[45].r[CHIP][SCBR[45].enq[CHIP]][2] : SCM0[45].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[45].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[45].b[CHIP][1]:SCM0[45].awoo[CHIP][1]);
adr = (Ull)(SCM0[45].awoo[CHIP][1] + SCM0[45].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[45].r[CHIP][SCBR[45].enq[CHIP]][4] = SCM0[45].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[45].r[CHIP][SCBR[45].enq[CHIP]][4] = SCM0[45].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[45].r[CHIP][SCBR[45].enq[CHIP]][4] = SCM0[45].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[45].r[CHIP][SCBR[45].enq[CHIP]][2] = SCBR[44].r[CHIP][SCBR[2].enq[CHIP]][-1853685272];
SCBR[45].r[CHIP][SCBR[45].enq[CHIP]][3] = SCBR[44].r[CHIP][SCBR[3].enq[CHIP]][-1853685272];
}
{
}
{
}
{
}
uLOOP[45][CHIP]--;
SCBR[45].enq[CHIP] = 1-SCBR[45].enq[CHIP];
}
}
}
void emax6sc_pth_mm_46(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit46 */
uLOOP[46][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[46][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[46][CHIP]==0) continue;
if ((46 && SCBR[45].enq[CHIP]==SCBR[45].deq[CHIP]) || SCBR[46].enq[CHIP]!=SCBR[46].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[46][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[46][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[45].deq[CHIP] = 1-SCBR[45].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[46].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[46].r[CHIP][SCBR[46].enq[CHIP]][0]:SCM1[46].b[CHIP][0]) : SCM1[46].awoo[CHIP][0];
SCM1[46].o[CHIP][0] = eam(1 ? SCBR[46].r[CHIP][SCBR[46].enq[CHIP]][2] : SCM1[46].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[46].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[46].b[CHIP][0]:SCM1[46].awoo[CHIP][0]);
adr = (Ull)(SCM1[46].awoo[CHIP][0] + SCM1[46].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[46].r[CHIP][SCBR[46].enq[CHIP]][1] = SCM1[46].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[46].r[CHIP][SCBR[46].enq[CHIP]][1] = SCM1[46].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[46].r[CHIP][SCBR[46].enq[CHIP]][1] = SCM1[46].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[46].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[46].r[CHIP][SCBR[46].enq[CHIP]][0]:SCM0[46].b[CHIP][0]) : SCM0[46].awoo[CHIP][0];
SCM0[46].o[CHIP][0] = eam(1 ? SCBR[46].r[CHIP][SCBR[46].enq[CHIP]][2] : SCM0[46].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[46].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[46].b[CHIP][0]:SCM0[46].awoo[CHIP][0]);
adr = (Ull)(SCM0[46].awoo[CHIP][0] + SCM0[46].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[46].r[CHIP][SCBR[46].enq[CHIP]][0] = SCM0[46].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[46].r[CHIP][SCBR[46].enq[CHIP]][0] = SCM0[46].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[46].r[CHIP][SCBR[46].enq[CHIP]][0] = SCM0[46].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[46].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[46].r[CHIP][SCBR[46].enq[CHIP]][0]:SCM1[46].b[CHIP][1]) : SCM1[46].awoo[CHIP][1];
SCM1[46].o[CHIP][1] = eam(1 ? SCBR[46].r[CHIP][SCBR[46].enq[CHIP]][2] : SCM1[46].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[46].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[46].b[CHIP][1]:SCM1[46].awoo[CHIP][1]);
adr = (Ull)(SCM1[46].awoo[CHIP][1] + SCM1[46].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[46].r[CHIP][SCBR[46].enq[CHIP]][5] = SCM1[46].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[46].r[CHIP][SCBR[46].enq[CHIP]][5] = SCM1[46].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[46].r[CHIP][SCBR[46].enq[CHIP]][5] = SCM1[46].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[46].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[46].r[CHIP][SCBR[46].enq[CHIP]][0]:SCM0[46].b[CHIP][1]) : SCM0[46].awoo[CHIP][1];
SCM0[46].o[CHIP][1] = eam(1 ? SCBR[46].r[CHIP][SCBR[46].enq[CHIP]][2] : SCM0[46].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[46].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[46].b[CHIP][1]:SCM0[46].awoo[CHIP][1]);
adr = (Ull)(SCM0[46].awoo[CHIP][1] + SCM0[46].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[46].r[CHIP][SCBR[46].enq[CHIP]][4] = SCM0[46].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[46].r[CHIP][SCBR[46].enq[CHIP]][4] = SCM0[46].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[46].r[CHIP][SCBR[46].enq[CHIP]][4] = SCM0[46].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[46].r[CHIP][SCBR[46].enq[CHIP]][2] = SCBR[45].r[CHIP][SCBR[2].enq[CHIP]][-1853685144];
SCBR[46].r[CHIP][SCBR[46].enq[CHIP]][3] = SCBR[45].r[CHIP][SCBR[3].enq[CHIP]][-1853685144];
}
{
}
{
}
{
}
uLOOP[46][CHIP]--;
SCBR[46].enq[CHIP] = 1-SCBR[46].enq[CHIP];
}
}
}
void emax6sc_pth_mm_47(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit47 */
uLOOP[47][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[47][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[47][CHIP]==0) continue;
if ((47 && SCBR[46].enq[CHIP]==SCBR[46].deq[CHIP]) || SCBR[47].enq[CHIP]!=SCBR[47].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[47][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[47][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[46].deq[CHIP] = 1-SCBR[46].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[47].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[47].r[CHIP][SCBR[47].enq[CHIP]][0]:SCM1[47].b[CHIP][0]) : SCM1[47].awoo[CHIP][0];
SCM1[47].o[CHIP][0] = eam(1 ? SCBR[47].r[CHIP][SCBR[47].enq[CHIP]][2] : SCM1[47].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[47].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[47].b[CHIP][0]:SCM1[47].awoo[CHIP][0]);
adr = (Ull)(SCM1[47].awoo[CHIP][0] + SCM1[47].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[47].r[CHIP][SCBR[47].enq[CHIP]][1] = SCM1[47].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[47].r[CHIP][SCBR[47].enq[CHIP]][1] = SCM1[47].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[47].r[CHIP][SCBR[47].enq[CHIP]][1] = SCM1[47].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[47].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[47].r[CHIP][SCBR[47].enq[CHIP]][0]:SCM0[47].b[CHIP][0]) : SCM0[47].awoo[CHIP][0];
SCM0[47].o[CHIP][0] = eam(1 ? SCBR[47].r[CHIP][SCBR[47].enq[CHIP]][2] : SCM0[47].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[47].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[47].b[CHIP][0]:SCM0[47].awoo[CHIP][0]);
adr = (Ull)(SCM0[47].awoo[CHIP][0] + SCM0[47].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[47].r[CHIP][SCBR[47].enq[CHIP]][0] = SCM0[47].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[47].r[CHIP][SCBR[47].enq[CHIP]][0] = SCM0[47].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[47].r[CHIP][SCBR[47].enq[CHIP]][0] = SCM0[47].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[47].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[47].r[CHIP][SCBR[47].enq[CHIP]][0]:SCM1[47].b[CHIP][1]) : SCM1[47].awoo[CHIP][1];
SCM1[47].o[CHIP][1] = eam(1 ? SCBR[47].r[CHIP][SCBR[47].enq[CHIP]][2] : SCM1[47].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[47].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[47].b[CHIP][1]:SCM1[47].awoo[CHIP][1]);
adr = (Ull)(SCM1[47].awoo[CHIP][1] + SCM1[47].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[47].r[CHIP][SCBR[47].enq[CHIP]][5] = SCM1[47].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[47].r[CHIP][SCBR[47].enq[CHIP]][5] = SCM1[47].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[47].r[CHIP][SCBR[47].enq[CHIP]][5] = SCM1[47].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[47].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[47].r[CHIP][SCBR[47].enq[CHIP]][0]:SCM0[47].b[CHIP][1]) : SCM0[47].awoo[CHIP][1];
SCM0[47].o[CHIP][1] = eam(1 ? SCBR[47].r[CHIP][SCBR[47].enq[CHIP]][2] : SCM0[47].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[47].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[47].b[CHIP][1]:SCM0[47].awoo[CHIP][1]);
adr = (Ull)(SCM0[47].awoo[CHIP][1] + SCM0[47].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[47].r[CHIP][SCBR[47].enq[CHIP]][4] = SCM0[47].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[47].r[CHIP][SCBR[47].enq[CHIP]][4] = SCM0[47].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[47].r[CHIP][SCBR[47].enq[CHIP]][4] = SCM0[47].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[47].r[CHIP][SCBR[47].enq[CHIP]][2] = SCBR[46].r[CHIP][SCBR[2].enq[CHIP]][-1853685016];
SCBR[47].r[CHIP][SCBR[47].enq[CHIP]][3] = SCBR[46].r[CHIP][SCBR[3].enq[CHIP]][-1853685016];
}
{
}
{
}
{
}
uLOOP[47][CHIP]--;
SCBR[47].enq[CHIP] = 1-SCBR[47].enq[CHIP];
}
}
}
void emax6sc_pth_mm_48(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit48 */
uLOOP[48][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[48][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[48][CHIP]==0) continue;
if ((48 && SCBR[47].enq[CHIP]==SCBR[47].deq[CHIP]) || SCBR[48].enq[CHIP]!=SCBR[48].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[48][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[48][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[47].deq[CHIP] = 1-SCBR[47].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[48].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[48].r[CHIP][SCBR[48].enq[CHIP]][0]:SCM1[48].b[CHIP][0]) : SCM1[48].awoo[CHIP][0];
SCM1[48].o[CHIP][0] = eam(1 ? SCBR[48].r[CHIP][SCBR[48].enq[CHIP]][2] : SCM1[48].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[48].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[48].b[CHIP][0]:SCM1[48].awoo[CHIP][0]);
adr = (Ull)(SCM1[48].awoo[CHIP][0] + SCM1[48].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[48].r[CHIP][SCBR[48].enq[CHIP]][1] = SCM1[48].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[48].r[CHIP][SCBR[48].enq[CHIP]][1] = SCM1[48].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[48].r[CHIP][SCBR[48].enq[CHIP]][1] = SCM1[48].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[48].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[48].r[CHIP][SCBR[48].enq[CHIP]][0]:SCM0[48].b[CHIP][0]) : SCM0[48].awoo[CHIP][0];
SCM0[48].o[CHIP][0] = eam(1 ? SCBR[48].r[CHIP][SCBR[48].enq[CHIP]][2] : SCM0[48].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[48].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[48].b[CHIP][0]:SCM0[48].awoo[CHIP][0]);
adr = (Ull)(SCM0[48].awoo[CHIP][0] + SCM0[48].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[48].r[CHIP][SCBR[48].enq[CHIP]][0] = SCM0[48].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[48].r[CHIP][SCBR[48].enq[CHIP]][0] = SCM0[48].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[48].r[CHIP][SCBR[48].enq[CHIP]][0] = SCM0[48].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[48].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[48].r[CHIP][SCBR[48].enq[CHIP]][0]:SCM1[48].b[CHIP][1]) : SCM1[48].awoo[CHIP][1];
SCM1[48].o[CHIP][1] = eam(1 ? SCBR[48].r[CHIP][SCBR[48].enq[CHIP]][2] : SCM1[48].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[48].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[48].b[CHIP][1]:SCM1[48].awoo[CHIP][1]);
adr = (Ull)(SCM1[48].awoo[CHIP][1] + SCM1[48].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[48].r[CHIP][SCBR[48].enq[CHIP]][5] = SCM1[48].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[48].r[CHIP][SCBR[48].enq[CHIP]][5] = SCM1[48].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[48].r[CHIP][SCBR[48].enq[CHIP]][5] = SCM1[48].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[48].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[48].r[CHIP][SCBR[48].enq[CHIP]][0]:SCM0[48].b[CHIP][1]) : SCM0[48].awoo[CHIP][1];
SCM0[48].o[CHIP][1] = eam(1 ? SCBR[48].r[CHIP][SCBR[48].enq[CHIP]][2] : SCM0[48].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[48].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[48].b[CHIP][1]:SCM0[48].awoo[CHIP][1]);
adr = (Ull)(SCM0[48].awoo[CHIP][1] + SCM0[48].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[48].r[CHIP][SCBR[48].enq[CHIP]][4] = SCM0[48].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[48].r[CHIP][SCBR[48].enq[CHIP]][4] = SCM0[48].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[48].r[CHIP][SCBR[48].enq[CHIP]][4] = SCM0[48].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[48].r[CHIP][SCBR[48].enq[CHIP]][2] = SCBR[47].r[CHIP][SCBR[2].enq[CHIP]][-1853684888];
SCBR[48].r[CHIP][SCBR[48].enq[CHIP]][3] = SCBR[47].r[CHIP][SCBR[3].enq[CHIP]][-1853684888];
}
{
}
{
}
{
}
uLOOP[48][CHIP]--;
SCBR[48].enq[CHIP] = 1-SCBR[48].enq[CHIP];
}
}
}
void emax6sc_pth_mm_49(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit49 */
uLOOP[49][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[49][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[49][CHIP]==0) continue;
if ((49 && SCBR[48].enq[CHIP]==SCBR[48].deq[CHIP]) || SCBR[49].enq[CHIP]!=SCBR[49].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[49][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[49][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[48].deq[CHIP] = 1-SCBR[48].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[49].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[49].r[CHIP][SCBR[49].enq[CHIP]][0]:SCM1[49].b[CHIP][0]) : SCM1[49].awoo[CHIP][0];
SCM1[49].o[CHIP][0] = eam(1 ? SCBR[49].r[CHIP][SCBR[49].enq[CHIP]][2] : SCM1[49].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[49].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[49].b[CHIP][0]:SCM1[49].awoo[CHIP][0]);
adr = (Ull)(SCM1[49].awoo[CHIP][0] + SCM1[49].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[49].r[CHIP][SCBR[49].enq[CHIP]][1] = SCM1[49].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[49].r[CHIP][SCBR[49].enq[CHIP]][1] = SCM1[49].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[49].r[CHIP][SCBR[49].enq[CHIP]][1] = SCM1[49].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[49].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[49].r[CHIP][SCBR[49].enq[CHIP]][0]:SCM0[49].b[CHIP][0]) : SCM0[49].awoo[CHIP][0];
SCM0[49].o[CHIP][0] = eam(1 ? SCBR[49].r[CHIP][SCBR[49].enq[CHIP]][2] : SCM0[49].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[49].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[49].b[CHIP][0]:SCM0[49].awoo[CHIP][0]);
adr = (Ull)(SCM0[49].awoo[CHIP][0] + SCM0[49].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[49].r[CHIP][SCBR[49].enq[CHIP]][0] = SCM0[49].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[49].r[CHIP][SCBR[49].enq[CHIP]][0] = SCM0[49].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[49].r[CHIP][SCBR[49].enq[CHIP]][0] = SCM0[49].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[49].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[49].r[CHIP][SCBR[49].enq[CHIP]][0]:SCM1[49].b[CHIP][1]) : SCM1[49].awoo[CHIP][1];
SCM1[49].o[CHIP][1] = eam(1 ? SCBR[49].r[CHIP][SCBR[49].enq[CHIP]][2] : SCM1[49].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[49].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[49].b[CHIP][1]:SCM1[49].awoo[CHIP][1]);
adr = (Ull)(SCM1[49].awoo[CHIP][1] + SCM1[49].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[49].r[CHIP][SCBR[49].enq[CHIP]][5] = SCM1[49].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[49].r[CHIP][SCBR[49].enq[CHIP]][5] = SCM1[49].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[49].r[CHIP][SCBR[49].enq[CHIP]][5] = SCM1[49].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[49].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[49].r[CHIP][SCBR[49].enq[CHIP]][0]:SCM0[49].b[CHIP][1]) : SCM0[49].awoo[CHIP][1];
SCM0[49].o[CHIP][1] = eam(1 ? SCBR[49].r[CHIP][SCBR[49].enq[CHIP]][2] : SCM0[49].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[49].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[49].b[CHIP][1]:SCM0[49].awoo[CHIP][1]);
adr = (Ull)(SCM0[49].awoo[CHIP][1] + SCM0[49].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[49].r[CHIP][SCBR[49].enq[CHIP]][4] = SCM0[49].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[49].r[CHIP][SCBR[49].enq[CHIP]][4] = SCM0[49].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[49].r[CHIP][SCBR[49].enq[CHIP]][4] = SCM0[49].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[49].r[CHIP][SCBR[49].enq[CHIP]][2] = SCBR[48].r[CHIP][SCBR[2].enq[CHIP]][-1853684760];
SCBR[49].r[CHIP][SCBR[49].enq[CHIP]][3] = SCBR[48].r[CHIP][SCBR[3].enq[CHIP]][-1853684760];
}
{
}
{
}
{
}
uLOOP[49][CHIP]--;
SCBR[49].enq[CHIP] = 1-SCBR[49].enq[CHIP];
}
}
}
void emax6sc_pth_mm_50(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit50 */
uLOOP[50][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[50][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[50][CHIP]==0) continue;
if ((50 && SCBR[49].enq[CHIP]==SCBR[49].deq[CHIP]) || SCBR[50].enq[CHIP]!=SCBR[50].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[50][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[50][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[49].deq[CHIP] = 1-SCBR[49].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[50].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[50].r[CHIP][SCBR[50].enq[CHIP]][0]:SCM1[50].b[CHIP][0]) : SCM1[50].awoo[CHIP][0];
SCM1[50].o[CHIP][0] = eam(1 ? SCBR[50].r[CHIP][SCBR[50].enq[CHIP]][2] : SCM1[50].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[50].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[50].b[CHIP][0]:SCM1[50].awoo[CHIP][0]);
adr = (Ull)(SCM1[50].awoo[CHIP][0] + SCM1[50].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[50].r[CHIP][SCBR[50].enq[CHIP]][1] = SCM1[50].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[50].r[CHIP][SCBR[50].enq[CHIP]][1] = SCM1[50].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[50].r[CHIP][SCBR[50].enq[CHIP]][1] = SCM1[50].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[50].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[50].r[CHIP][SCBR[50].enq[CHIP]][0]:SCM0[50].b[CHIP][0]) : SCM0[50].awoo[CHIP][0];
SCM0[50].o[CHIP][0] = eam(1 ? SCBR[50].r[CHIP][SCBR[50].enq[CHIP]][2] : SCM0[50].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[50].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[50].b[CHIP][0]:SCM0[50].awoo[CHIP][0]);
adr = (Ull)(SCM0[50].awoo[CHIP][0] + SCM0[50].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[50].r[CHIP][SCBR[50].enq[CHIP]][0] = SCM0[50].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[50].r[CHIP][SCBR[50].enq[CHIP]][0] = SCM0[50].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[50].r[CHIP][SCBR[50].enq[CHIP]][0] = SCM0[50].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[50].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[50].r[CHIP][SCBR[50].enq[CHIP]][0]:SCM1[50].b[CHIP][1]) : SCM1[50].awoo[CHIP][1];
SCM1[50].o[CHIP][1] = eam(1 ? SCBR[50].r[CHIP][SCBR[50].enq[CHIP]][2] : SCM1[50].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[50].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[50].b[CHIP][1]:SCM1[50].awoo[CHIP][1]);
adr = (Ull)(SCM1[50].awoo[CHIP][1] + SCM1[50].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[50].r[CHIP][SCBR[50].enq[CHIP]][5] = SCM1[50].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[50].r[CHIP][SCBR[50].enq[CHIP]][5] = SCM1[50].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[50].r[CHIP][SCBR[50].enq[CHIP]][5] = SCM1[50].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[50].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[50].r[CHIP][SCBR[50].enq[CHIP]][0]:SCM0[50].b[CHIP][1]) : SCM0[50].awoo[CHIP][1];
SCM0[50].o[CHIP][1] = eam(1 ? SCBR[50].r[CHIP][SCBR[50].enq[CHIP]][2] : SCM0[50].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[50].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[50].b[CHIP][1]:SCM0[50].awoo[CHIP][1]);
adr = (Ull)(SCM0[50].awoo[CHIP][1] + SCM0[50].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[50].r[CHIP][SCBR[50].enq[CHIP]][4] = SCM0[50].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[50].r[CHIP][SCBR[50].enq[CHIP]][4] = SCM0[50].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[50].r[CHIP][SCBR[50].enq[CHIP]][4] = SCM0[50].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[50].r[CHIP][SCBR[50].enq[CHIP]][2] = SCBR[49].r[CHIP][SCBR[2].enq[CHIP]][-1853684632];
SCBR[50].r[CHIP][SCBR[50].enq[CHIP]][3] = SCBR[49].r[CHIP][SCBR[3].enq[CHIP]][-1853684632];
}
{
}
{
}
{
}
uLOOP[50][CHIP]--;
SCBR[50].enq[CHIP] = 1-SCBR[50].enq[CHIP];
}
}
}
void emax6sc_pth_mm_51(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit51 */
uLOOP[51][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[51][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[51][CHIP]==0) continue;
if ((51 && SCBR[50].enq[CHIP]==SCBR[50].deq[CHIP]) || SCBR[51].enq[CHIP]!=SCBR[51].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[51][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[51][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[50].deq[CHIP] = 1-SCBR[50].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[51].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[51].r[CHIP][SCBR[51].enq[CHIP]][0]:SCM1[51].b[CHIP][0]) : SCM1[51].awoo[CHIP][0];
SCM1[51].o[CHIP][0] = eam(1 ? SCBR[51].r[CHIP][SCBR[51].enq[CHIP]][2] : SCM1[51].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[51].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[51].b[CHIP][0]:SCM1[51].awoo[CHIP][0]);
adr = (Ull)(SCM1[51].awoo[CHIP][0] + SCM1[51].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[51].r[CHIP][SCBR[51].enq[CHIP]][1] = SCM1[51].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[51].r[CHIP][SCBR[51].enq[CHIP]][1] = SCM1[51].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[51].r[CHIP][SCBR[51].enq[CHIP]][1] = SCM1[51].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[51].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[51].r[CHIP][SCBR[51].enq[CHIP]][0]:SCM0[51].b[CHIP][0]) : SCM0[51].awoo[CHIP][0];
SCM0[51].o[CHIP][0] = eam(1 ? SCBR[51].r[CHIP][SCBR[51].enq[CHIP]][2] : SCM0[51].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[51].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[51].b[CHIP][0]:SCM0[51].awoo[CHIP][0]);
adr = (Ull)(SCM0[51].awoo[CHIP][0] + SCM0[51].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[51].r[CHIP][SCBR[51].enq[CHIP]][0] = SCM0[51].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[51].r[CHIP][SCBR[51].enq[CHIP]][0] = SCM0[51].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[51].r[CHIP][SCBR[51].enq[CHIP]][0] = SCM0[51].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[51].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[51].r[CHIP][SCBR[51].enq[CHIP]][0]:SCM1[51].b[CHIP][1]) : SCM1[51].awoo[CHIP][1];
SCM1[51].o[CHIP][1] = eam(1 ? SCBR[51].r[CHIP][SCBR[51].enq[CHIP]][2] : SCM1[51].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[51].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[51].b[CHIP][1]:SCM1[51].awoo[CHIP][1]);
adr = (Ull)(SCM1[51].awoo[CHIP][1] + SCM1[51].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[51].r[CHIP][SCBR[51].enq[CHIP]][5] = SCM1[51].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[51].r[CHIP][SCBR[51].enq[CHIP]][5] = SCM1[51].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[51].r[CHIP][SCBR[51].enq[CHIP]][5] = SCM1[51].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[51].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[51].r[CHIP][SCBR[51].enq[CHIP]][0]:SCM0[51].b[CHIP][1]) : SCM0[51].awoo[CHIP][1];
SCM0[51].o[CHIP][1] = eam(1 ? SCBR[51].r[CHIP][SCBR[51].enq[CHIP]][2] : SCM0[51].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[51].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[51].b[CHIP][1]:SCM0[51].awoo[CHIP][1]);
adr = (Ull)(SCM0[51].awoo[CHIP][1] + SCM0[51].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[51].r[CHIP][SCBR[51].enq[CHIP]][4] = SCM0[51].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[51].r[CHIP][SCBR[51].enq[CHIP]][4] = SCM0[51].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[51].r[CHIP][SCBR[51].enq[CHIP]][4] = SCM0[51].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[51].r[CHIP][SCBR[51].enq[CHIP]][2] = SCBR[50].r[CHIP][SCBR[2].enq[CHIP]][-1853684504];
SCBR[51].r[CHIP][SCBR[51].enq[CHIP]][3] = SCBR[50].r[CHIP][SCBR[3].enq[CHIP]][-1853684504];
}
{
}
{
}
{
}
uLOOP[51][CHIP]--;
SCBR[51].enq[CHIP] = 1-SCBR[51].enq[CHIP];
}
}
}
void emax6sc_pth_mm_52(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit52 */
uLOOP[52][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[52][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[52][CHIP]==0) continue;
if ((52 && SCBR[51].enq[CHIP]==SCBR[51].deq[CHIP]) || SCBR[52].enq[CHIP]!=SCBR[52].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[52][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[52][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[51].deq[CHIP] = 1-SCBR[51].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[52].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[52].r[CHIP][SCBR[52].enq[CHIP]][0]:SCM1[52].b[CHIP][0]) : SCM1[52].awoo[CHIP][0];
SCM1[52].o[CHIP][0] = eam(1 ? SCBR[52].r[CHIP][SCBR[52].enq[CHIP]][2] : SCM1[52].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[52].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[52].b[CHIP][0]:SCM1[52].awoo[CHIP][0]);
adr = (Ull)(SCM1[52].awoo[CHIP][0] + SCM1[52].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[52].r[CHIP][SCBR[52].enq[CHIP]][1] = SCM1[52].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[52].r[CHIP][SCBR[52].enq[CHIP]][1] = SCM1[52].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[52].r[CHIP][SCBR[52].enq[CHIP]][1] = SCM1[52].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[52].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[52].r[CHIP][SCBR[52].enq[CHIP]][0]:SCM0[52].b[CHIP][0]) : SCM0[52].awoo[CHIP][0];
SCM0[52].o[CHIP][0] = eam(1 ? SCBR[52].r[CHIP][SCBR[52].enq[CHIP]][2] : SCM0[52].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[52].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[52].b[CHIP][0]:SCM0[52].awoo[CHIP][0]);
adr = (Ull)(SCM0[52].awoo[CHIP][0] + SCM0[52].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[52].r[CHIP][SCBR[52].enq[CHIP]][0] = SCM0[52].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[52].r[CHIP][SCBR[52].enq[CHIP]][0] = SCM0[52].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[52].r[CHIP][SCBR[52].enq[CHIP]][0] = SCM0[52].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[52].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[52].r[CHIP][SCBR[52].enq[CHIP]][0]:SCM1[52].b[CHIP][1]) : SCM1[52].awoo[CHIP][1];
SCM1[52].o[CHIP][1] = eam(1 ? SCBR[52].r[CHIP][SCBR[52].enq[CHIP]][2] : SCM1[52].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[52].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[52].b[CHIP][1]:SCM1[52].awoo[CHIP][1]);
adr = (Ull)(SCM1[52].awoo[CHIP][1] + SCM1[52].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[52].r[CHIP][SCBR[52].enq[CHIP]][5] = SCM1[52].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[52].r[CHIP][SCBR[52].enq[CHIP]][5] = SCM1[52].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[52].r[CHIP][SCBR[52].enq[CHIP]][5] = SCM1[52].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[52].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[52].r[CHIP][SCBR[52].enq[CHIP]][0]:SCM0[52].b[CHIP][1]) : SCM0[52].awoo[CHIP][1];
SCM0[52].o[CHIP][1] = eam(1 ? SCBR[52].r[CHIP][SCBR[52].enq[CHIP]][2] : SCM0[52].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[52].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[52].b[CHIP][1]:SCM0[52].awoo[CHIP][1]);
adr = (Ull)(SCM0[52].awoo[CHIP][1] + SCM0[52].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[52].r[CHIP][SCBR[52].enq[CHIP]][4] = SCM0[52].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[52].r[CHIP][SCBR[52].enq[CHIP]][4] = SCM0[52].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[52].r[CHIP][SCBR[52].enq[CHIP]][4] = SCM0[52].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[52].r[CHIP][SCBR[52].enq[CHIP]][2] = SCBR[51].r[CHIP][SCBR[2].enq[CHIP]][-1853684376];
SCBR[52].r[CHIP][SCBR[52].enq[CHIP]][3] = SCBR[51].r[CHIP][SCBR[3].enq[CHIP]][-1853684376];
}
{
}
{
}
{
}
uLOOP[52][CHIP]--;
SCBR[52].enq[CHIP] = 1-SCBR[52].enq[CHIP];
}
}
}
void emax6sc_pth_mm_53(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit53 */
uLOOP[53][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[53][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[53][CHIP]==0) continue;
if ((53 && SCBR[52].enq[CHIP]==SCBR[52].deq[CHIP]) || SCBR[53].enq[CHIP]!=SCBR[53].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[53][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[53][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[52].deq[CHIP] = 1-SCBR[52].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[53].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[53].r[CHIP][SCBR[53].enq[CHIP]][0]:SCM1[53].b[CHIP][0]) : SCM1[53].awoo[CHIP][0];
SCM1[53].o[CHIP][0] = eam(1 ? SCBR[53].r[CHIP][SCBR[53].enq[CHIP]][2] : SCM1[53].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[53].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[53].b[CHIP][0]:SCM1[53].awoo[CHIP][0]);
adr = (Ull)(SCM1[53].awoo[CHIP][0] + SCM1[53].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[53].r[CHIP][SCBR[53].enq[CHIP]][1] = SCM1[53].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[53].r[CHIP][SCBR[53].enq[CHIP]][1] = SCM1[53].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[53].r[CHIP][SCBR[53].enq[CHIP]][1] = SCM1[53].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[53].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[53].r[CHIP][SCBR[53].enq[CHIP]][0]:SCM0[53].b[CHIP][0]) : SCM0[53].awoo[CHIP][0];
SCM0[53].o[CHIP][0] = eam(1 ? SCBR[53].r[CHIP][SCBR[53].enq[CHIP]][2] : SCM0[53].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[53].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[53].b[CHIP][0]:SCM0[53].awoo[CHIP][0]);
adr = (Ull)(SCM0[53].awoo[CHIP][0] + SCM0[53].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[53].r[CHIP][SCBR[53].enq[CHIP]][0] = SCM0[53].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[53].r[CHIP][SCBR[53].enq[CHIP]][0] = SCM0[53].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[53].r[CHIP][SCBR[53].enq[CHIP]][0] = SCM0[53].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[53].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[53].r[CHIP][SCBR[53].enq[CHIP]][0]:SCM1[53].b[CHIP][1]) : SCM1[53].awoo[CHIP][1];
SCM1[53].o[CHIP][1] = eam(1 ? SCBR[53].r[CHIP][SCBR[53].enq[CHIP]][2] : SCM1[53].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[53].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[53].b[CHIP][1]:SCM1[53].awoo[CHIP][1]);
adr = (Ull)(SCM1[53].awoo[CHIP][1] + SCM1[53].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[53].r[CHIP][SCBR[53].enq[CHIP]][5] = SCM1[53].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[53].r[CHIP][SCBR[53].enq[CHIP]][5] = SCM1[53].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[53].r[CHIP][SCBR[53].enq[CHIP]][5] = SCM1[53].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[53].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[53].r[CHIP][SCBR[53].enq[CHIP]][0]:SCM0[53].b[CHIP][1]) : SCM0[53].awoo[CHIP][1];
SCM0[53].o[CHIP][1] = eam(1 ? SCBR[53].r[CHIP][SCBR[53].enq[CHIP]][2] : SCM0[53].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[53].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[53].b[CHIP][1]:SCM0[53].awoo[CHIP][1]);
adr = (Ull)(SCM0[53].awoo[CHIP][1] + SCM0[53].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[53].r[CHIP][SCBR[53].enq[CHIP]][4] = SCM0[53].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[53].r[CHIP][SCBR[53].enq[CHIP]][4] = SCM0[53].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[53].r[CHIP][SCBR[53].enq[CHIP]][4] = SCM0[53].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[53].r[CHIP][SCBR[53].enq[CHIP]][2] = SCBR[52].r[CHIP][SCBR[2].enq[CHIP]][-1853684248];
SCBR[53].r[CHIP][SCBR[53].enq[CHIP]][3] = SCBR[52].r[CHIP][SCBR[3].enq[CHIP]][-1853684248];
}
{
}
{
}
{
}
uLOOP[53][CHIP]--;
SCBR[53].enq[CHIP] = 1-SCBR[53].enq[CHIP];
}
}
}
void emax6sc_pth_mm_54(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit54 */
uLOOP[54][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[54][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[54][CHIP]==0) continue;
if ((54 && SCBR[53].enq[CHIP]==SCBR[53].deq[CHIP]) || SCBR[54].enq[CHIP]!=SCBR[54].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[54][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[54][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[53].deq[CHIP] = 1-SCBR[53].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[54].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[54].r[CHIP][SCBR[54].enq[CHIP]][0]:SCM1[54].b[CHIP][0]) : SCM1[54].awoo[CHIP][0];
SCM1[54].o[CHIP][0] = eam(1 ? SCBR[54].r[CHIP][SCBR[54].enq[CHIP]][2] : SCM1[54].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[54].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[54].b[CHIP][0]:SCM1[54].awoo[CHIP][0]);
adr = (Ull)(SCM1[54].awoo[CHIP][0] + SCM1[54].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[54].r[CHIP][SCBR[54].enq[CHIP]][1] = SCM1[54].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[54].r[CHIP][SCBR[54].enq[CHIP]][1] = SCM1[54].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[54].r[CHIP][SCBR[54].enq[CHIP]][1] = SCM1[54].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[54].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[54].r[CHIP][SCBR[54].enq[CHIP]][0]:SCM0[54].b[CHIP][0]) : SCM0[54].awoo[CHIP][0];
SCM0[54].o[CHIP][0] = eam(1 ? SCBR[54].r[CHIP][SCBR[54].enq[CHIP]][2] : SCM0[54].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[54].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[54].b[CHIP][0]:SCM0[54].awoo[CHIP][0]);
adr = (Ull)(SCM0[54].awoo[CHIP][0] + SCM0[54].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[54].r[CHIP][SCBR[54].enq[CHIP]][0] = SCM0[54].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[54].r[CHIP][SCBR[54].enq[CHIP]][0] = SCM0[54].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[54].r[CHIP][SCBR[54].enq[CHIP]][0] = SCM0[54].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[54].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[54].r[CHIP][SCBR[54].enq[CHIP]][0]:SCM1[54].b[CHIP][1]) : SCM1[54].awoo[CHIP][1];
SCM1[54].o[CHIP][1] = eam(1 ? SCBR[54].r[CHIP][SCBR[54].enq[CHIP]][2] : SCM1[54].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[54].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[54].b[CHIP][1]:SCM1[54].awoo[CHIP][1]);
adr = (Ull)(SCM1[54].awoo[CHIP][1] + SCM1[54].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[54].r[CHIP][SCBR[54].enq[CHIP]][5] = SCM1[54].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[54].r[CHIP][SCBR[54].enq[CHIP]][5] = SCM1[54].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[54].r[CHIP][SCBR[54].enq[CHIP]][5] = SCM1[54].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[54].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[54].r[CHIP][SCBR[54].enq[CHIP]][0]:SCM0[54].b[CHIP][1]) : SCM0[54].awoo[CHIP][1];
SCM0[54].o[CHIP][1] = eam(1 ? SCBR[54].r[CHIP][SCBR[54].enq[CHIP]][2] : SCM0[54].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[54].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[54].b[CHIP][1]:SCM0[54].awoo[CHIP][1]);
adr = (Ull)(SCM0[54].awoo[CHIP][1] + SCM0[54].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[54].r[CHIP][SCBR[54].enq[CHIP]][4] = SCM0[54].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[54].r[CHIP][SCBR[54].enq[CHIP]][4] = SCM0[54].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[54].r[CHIP][SCBR[54].enq[CHIP]][4] = SCM0[54].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[54].r[CHIP][SCBR[54].enq[CHIP]][2] = SCBR[53].r[CHIP][SCBR[2].enq[CHIP]][-1853684120];
SCBR[54].r[CHIP][SCBR[54].enq[CHIP]][3] = SCBR[53].r[CHIP][SCBR[3].enq[CHIP]][-1853684120];
}
{
}
{
}
{
}
uLOOP[54][CHIP]--;
SCBR[54].enq[CHIP] = 1-SCBR[54].enq[CHIP];
}
}
}
void emax6sc_pth_mm_55(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit55 */
uLOOP[55][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[55][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[55][CHIP]==0) continue;
if ((55 && SCBR[54].enq[CHIP]==SCBR[54].deq[CHIP]) || SCBR[55].enq[CHIP]!=SCBR[55].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[55][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[55][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[54].deq[CHIP] = 1-SCBR[54].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[55].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[55].r[CHIP][SCBR[55].enq[CHIP]][0]:SCM1[55].b[CHIP][0]) : SCM1[55].awoo[CHIP][0];
SCM1[55].o[CHIP][0] = eam(1 ? SCBR[55].r[CHIP][SCBR[55].enq[CHIP]][2] : SCM1[55].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[55].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[55].b[CHIP][0]:SCM1[55].awoo[CHIP][0]);
adr = (Ull)(SCM1[55].awoo[CHIP][0] + SCM1[55].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[55].r[CHIP][SCBR[55].enq[CHIP]][1] = SCM1[55].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[55].r[CHIP][SCBR[55].enq[CHIP]][1] = SCM1[55].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[55].r[CHIP][SCBR[55].enq[CHIP]][1] = SCM1[55].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[55].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[55].r[CHIP][SCBR[55].enq[CHIP]][0]:SCM0[55].b[CHIP][0]) : SCM0[55].awoo[CHIP][0];
SCM0[55].o[CHIP][0] = eam(1 ? SCBR[55].r[CHIP][SCBR[55].enq[CHIP]][2] : SCM0[55].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[55].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[55].b[CHIP][0]:SCM0[55].awoo[CHIP][0]);
adr = (Ull)(SCM0[55].awoo[CHIP][0] + SCM0[55].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[55].r[CHIP][SCBR[55].enq[CHIP]][0] = SCM0[55].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[55].r[CHIP][SCBR[55].enq[CHIP]][0] = SCM0[55].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[55].r[CHIP][SCBR[55].enq[CHIP]][0] = SCM0[55].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[55].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[55].r[CHIP][SCBR[55].enq[CHIP]][0]:SCM1[55].b[CHIP][1]) : SCM1[55].awoo[CHIP][1];
SCM1[55].o[CHIP][1] = eam(1 ? SCBR[55].r[CHIP][SCBR[55].enq[CHIP]][2] : SCM1[55].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[55].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[55].b[CHIP][1]:SCM1[55].awoo[CHIP][1]);
adr = (Ull)(SCM1[55].awoo[CHIP][1] + SCM1[55].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[55].r[CHIP][SCBR[55].enq[CHIP]][5] = SCM1[55].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[55].r[CHIP][SCBR[55].enq[CHIP]][5] = SCM1[55].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[55].r[CHIP][SCBR[55].enq[CHIP]][5] = SCM1[55].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[55].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[55].r[CHIP][SCBR[55].enq[CHIP]][0]:SCM0[55].b[CHIP][1]) : SCM0[55].awoo[CHIP][1];
SCM0[55].o[CHIP][1] = eam(1 ? SCBR[55].r[CHIP][SCBR[55].enq[CHIP]][2] : SCM0[55].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[55].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[55].b[CHIP][1]:SCM0[55].awoo[CHIP][1]);
adr = (Ull)(SCM0[55].awoo[CHIP][1] + SCM0[55].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[55].r[CHIP][SCBR[55].enq[CHIP]][4] = SCM0[55].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[55].r[CHIP][SCBR[55].enq[CHIP]][4] = SCM0[55].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[55].r[CHIP][SCBR[55].enq[CHIP]][4] = SCM0[55].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[55].r[CHIP][SCBR[55].enq[CHIP]][2] = SCBR[54].r[CHIP][SCBR[2].enq[CHIP]][-1853683992];
SCBR[55].r[CHIP][SCBR[55].enq[CHIP]][3] = SCBR[54].r[CHIP][SCBR[3].enq[CHIP]][-1853683992];
}
{
}
{
}
{
}
uLOOP[55][CHIP]--;
SCBR[55].enq[CHIP] = 1-SCBR[55].enq[CHIP];
}
}
}
void emax6sc_pth_mm_56(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit56 */
uLOOP[56][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[56][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[56][CHIP]==0) continue;
if ((56 && SCBR[55].enq[CHIP]==SCBR[55].deq[CHIP]) || SCBR[56].enq[CHIP]!=SCBR[56].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[56][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[56][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[55].deq[CHIP] = 1-SCBR[55].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[56].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[56].r[CHIP][SCBR[56].enq[CHIP]][0]:SCM1[56].b[CHIP][0]) : SCM1[56].awoo[CHIP][0];
SCM1[56].o[CHIP][0] = eam(1 ? SCBR[56].r[CHIP][SCBR[56].enq[CHIP]][2] : SCM1[56].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[56].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[56].b[CHIP][0]:SCM1[56].awoo[CHIP][0]);
adr = (Ull)(SCM1[56].awoo[CHIP][0] + SCM1[56].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[56].r[CHIP][SCBR[56].enq[CHIP]][1] = SCM1[56].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[56].r[CHIP][SCBR[56].enq[CHIP]][1] = SCM1[56].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[56].r[CHIP][SCBR[56].enq[CHIP]][1] = SCM1[56].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[56].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[56].r[CHIP][SCBR[56].enq[CHIP]][0]:SCM0[56].b[CHIP][0]) : SCM0[56].awoo[CHIP][0];
SCM0[56].o[CHIP][0] = eam(1 ? SCBR[56].r[CHIP][SCBR[56].enq[CHIP]][2] : SCM0[56].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[56].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[56].b[CHIP][0]:SCM0[56].awoo[CHIP][0]);
adr = (Ull)(SCM0[56].awoo[CHIP][0] + SCM0[56].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[56].r[CHIP][SCBR[56].enq[CHIP]][0] = SCM0[56].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[56].r[CHIP][SCBR[56].enq[CHIP]][0] = SCM0[56].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[56].r[CHIP][SCBR[56].enq[CHIP]][0] = SCM0[56].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[56].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[56].r[CHIP][SCBR[56].enq[CHIP]][0]:SCM1[56].b[CHIP][1]) : SCM1[56].awoo[CHIP][1];
SCM1[56].o[CHIP][1] = eam(1 ? SCBR[56].r[CHIP][SCBR[56].enq[CHIP]][2] : SCM1[56].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[56].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[56].b[CHIP][1]:SCM1[56].awoo[CHIP][1]);
adr = (Ull)(SCM1[56].awoo[CHIP][1] + SCM1[56].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[56].r[CHIP][SCBR[56].enq[CHIP]][5] = SCM1[56].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[56].r[CHIP][SCBR[56].enq[CHIP]][5] = SCM1[56].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[56].r[CHIP][SCBR[56].enq[CHIP]][5] = SCM1[56].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[56].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[56].r[CHIP][SCBR[56].enq[CHIP]][0]:SCM0[56].b[CHIP][1]) : SCM0[56].awoo[CHIP][1];
SCM0[56].o[CHIP][1] = eam(1 ? SCBR[56].r[CHIP][SCBR[56].enq[CHIP]][2] : SCM0[56].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[56].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[56].b[CHIP][1]:SCM0[56].awoo[CHIP][1]);
adr = (Ull)(SCM0[56].awoo[CHIP][1] + SCM0[56].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[56].r[CHIP][SCBR[56].enq[CHIP]][4] = SCM0[56].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[56].r[CHIP][SCBR[56].enq[CHIP]][4] = SCM0[56].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[56].r[CHIP][SCBR[56].enq[CHIP]][4] = SCM0[56].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[56].r[CHIP][SCBR[56].enq[CHIP]][2] = SCBR[55].r[CHIP][SCBR[2].enq[CHIP]][-1853683864];
SCBR[56].r[CHIP][SCBR[56].enq[CHIP]][3] = SCBR[55].r[CHIP][SCBR[3].enq[CHIP]][-1853683864];
}
{
}
{
}
{
}
uLOOP[56][CHIP]--;
SCBR[56].enq[CHIP] = 1-SCBR[56].enq[CHIP];
}
}
}
void emax6sc_pth_mm_57(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit57 */
uLOOP[57][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[57][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[57][CHIP]==0) continue;
if ((57 && SCBR[56].enq[CHIP]==SCBR[56].deq[CHIP]) || SCBR[57].enq[CHIP]!=SCBR[57].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[57][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[57][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[56].deq[CHIP] = 1-SCBR[56].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[57].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[57].r[CHIP][SCBR[57].enq[CHIP]][0]:SCM1[57].b[CHIP][0]) : SCM1[57].awoo[CHIP][0];
SCM1[57].o[CHIP][0] = eam(1 ? SCBR[57].r[CHIP][SCBR[57].enq[CHIP]][2] : SCM1[57].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[57].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[57].b[CHIP][0]:SCM1[57].awoo[CHIP][0]);
adr = (Ull)(SCM1[57].awoo[CHIP][0] + SCM1[57].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[57].r[CHIP][SCBR[57].enq[CHIP]][1] = SCM1[57].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[57].r[CHIP][SCBR[57].enq[CHIP]][1] = SCM1[57].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[57].r[CHIP][SCBR[57].enq[CHIP]][1] = SCM1[57].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[57].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[57].r[CHIP][SCBR[57].enq[CHIP]][0]:SCM0[57].b[CHIP][0]) : SCM0[57].awoo[CHIP][0];
SCM0[57].o[CHIP][0] = eam(1 ? SCBR[57].r[CHIP][SCBR[57].enq[CHIP]][2] : SCM0[57].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[57].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[57].b[CHIP][0]:SCM0[57].awoo[CHIP][0]);
adr = (Ull)(SCM0[57].awoo[CHIP][0] + SCM0[57].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[57].r[CHIP][SCBR[57].enq[CHIP]][0] = SCM0[57].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[57].r[CHIP][SCBR[57].enq[CHIP]][0] = SCM0[57].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[57].r[CHIP][SCBR[57].enq[CHIP]][0] = SCM0[57].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[57].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[57].r[CHIP][SCBR[57].enq[CHIP]][0]:SCM1[57].b[CHIP][1]) : SCM1[57].awoo[CHIP][1];
SCM1[57].o[CHIP][1] = eam(1 ? SCBR[57].r[CHIP][SCBR[57].enq[CHIP]][2] : SCM1[57].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[57].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[57].b[CHIP][1]:SCM1[57].awoo[CHIP][1]);
adr = (Ull)(SCM1[57].awoo[CHIP][1] + SCM1[57].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[57].r[CHIP][SCBR[57].enq[CHIP]][5] = SCM1[57].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[57].r[CHIP][SCBR[57].enq[CHIP]][5] = SCM1[57].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[57].r[CHIP][SCBR[57].enq[CHIP]][5] = SCM1[57].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[57].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[57].r[CHIP][SCBR[57].enq[CHIP]][0]:SCM0[57].b[CHIP][1]) : SCM0[57].awoo[CHIP][1];
SCM0[57].o[CHIP][1] = eam(1 ? SCBR[57].r[CHIP][SCBR[57].enq[CHIP]][2] : SCM0[57].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[57].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[57].b[CHIP][1]:SCM0[57].awoo[CHIP][1]);
adr = (Ull)(SCM0[57].awoo[CHIP][1] + SCM0[57].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[57].r[CHIP][SCBR[57].enq[CHIP]][4] = SCM0[57].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[57].r[CHIP][SCBR[57].enq[CHIP]][4] = SCM0[57].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[57].r[CHIP][SCBR[57].enq[CHIP]][4] = SCM0[57].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[57].r[CHIP][SCBR[57].enq[CHIP]][2] = SCBR[56].r[CHIP][SCBR[2].enq[CHIP]][-1853683736];
SCBR[57].r[CHIP][SCBR[57].enq[CHIP]][3] = SCBR[56].r[CHIP][SCBR[3].enq[CHIP]][-1853683736];
}
{
}
{
}
{
}
uLOOP[57][CHIP]--;
SCBR[57].enq[CHIP] = 1-SCBR[57].enq[CHIP];
}
}
}
void emax6sc_pth_mm_58(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit58 */
uLOOP[58][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[58][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[58][CHIP]==0) continue;
if ((58 && SCBR[57].enq[CHIP]==SCBR[57].deq[CHIP]) || SCBR[58].enq[CHIP]!=SCBR[58].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[58][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[58][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[57].deq[CHIP] = 1-SCBR[57].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[58].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[58].r[CHIP][SCBR[58].enq[CHIP]][0]:SCM1[58].b[CHIP][0]) : SCM1[58].awoo[CHIP][0];
SCM1[58].o[CHIP][0] = eam(1 ? SCBR[58].r[CHIP][SCBR[58].enq[CHIP]][2] : SCM1[58].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[58].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[58].b[CHIP][0]:SCM1[58].awoo[CHIP][0]);
adr = (Ull)(SCM1[58].awoo[CHIP][0] + SCM1[58].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[58].r[CHIP][SCBR[58].enq[CHIP]][1] = SCM1[58].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[58].r[CHIP][SCBR[58].enq[CHIP]][1] = SCM1[58].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[58].r[CHIP][SCBR[58].enq[CHIP]][1] = SCM1[58].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[58].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[58].r[CHIP][SCBR[58].enq[CHIP]][0]:SCM0[58].b[CHIP][0]) : SCM0[58].awoo[CHIP][0];
SCM0[58].o[CHIP][0] = eam(1 ? SCBR[58].r[CHIP][SCBR[58].enq[CHIP]][2] : SCM0[58].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[58].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[58].b[CHIP][0]:SCM0[58].awoo[CHIP][0]);
adr = (Ull)(SCM0[58].awoo[CHIP][0] + SCM0[58].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[58].r[CHIP][SCBR[58].enq[CHIP]][0] = SCM0[58].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[58].r[CHIP][SCBR[58].enq[CHIP]][0] = SCM0[58].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[58].r[CHIP][SCBR[58].enq[CHIP]][0] = SCM0[58].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[58].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[58].r[CHIP][SCBR[58].enq[CHIP]][0]:SCM1[58].b[CHIP][1]) : SCM1[58].awoo[CHIP][1];
SCM1[58].o[CHIP][1] = eam(1 ? SCBR[58].r[CHIP][SCBR[58].enq[CHIP]][2] : SCM1[58].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[58].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[58].b[CHIP][1]:SCM1[58].awoo[CHIP][1]);
adr = (Ull)(SCM1[58].awoo[CHIP][1] + SCM1[58].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[58].r[CHIP][SCBR[58].enq[CHIP]][5] = SCM1[58].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[58].r[CHIP][SCBR[58].enq[CHIP]][5] = SCM1[58].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[58].r[CHIP][SCBR[58].enq[CHIP]][5] = SCM1[58].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[58].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[58].r[CHIP][SCBR[58].enq[CHIP]][0]:SCM0[58].b[CHIP][1]) : SCM0[58].awoo[CHIP][1];
SCM0[58].o[CHIP][1] = eam(1 ? SCBR[58].r[CHIP][SCBR[58].enq[CHIP]][2] : SCM0[58].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[58].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[58].b[CHIP][1]:SCM0[58].awoo[CHIP][1]);
adr = (Ull)(SCM0[58].awoo[CHIP][1] + SCM0[58].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[58].r[CHIP][SCBR[58].enq[CHIP]][4] = SCM0[58].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[58].r[CHIP][SCBR[58].enq[CHIP]][4] = SCM0[58].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[58].r[CHIP][SCBR[58].enq[CHIP]][4] = SCM0[58].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[58].r[CHIP][SCBR[58].enq[CHIP]][2] = SCBR[57].r[CHIP][SCBR[2].enq[CHIP]][-1853683608];
SCBR[58].r[CHIP][SCBR[58].enq[CHIP]][3] = SCBR[57].r[CHIP][SCBR[3].enq[CHIP]][-1853683608];
}
{
}
{
}
{
}
uLOOP[58][CHIP]--;
SCBR[58].enq[CHIP] = 1-SCBR[58].enq[CHIP];
}
}
}
void emax6sc_pth_mm_59(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit59 */
uLOOP[59][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[59][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[59][CHIP]==0) continue;
if ((59 && SCBR[58].enq[CHIP]==SCBR[58].deq[CHIP]) || SCBR[59].enq[CHIP]!=SCBR[59].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[59][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[59][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[58].deq[CHIP] = 1-SCBR[58].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[59].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[59].r[CHIP][SCBR[59].enq[CHIP]][0]:SCM1[59].b[CHIP][0]) : SCM1[59].awoo[CHIP][0];
SCM1[59].o[CHIP][0] = eam(1 ? SCBR[59].r[CHIP][SCBR[59].enq[CHIP]][2] : SCM1[59].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[59].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[59].b[CHIP][0]:SCM1[59].awoo[CHIP][0]);
adr = (Ull)(SCM1[59].awoo[CHIP][0] + SCM1[59].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[59].r[CHIP][SCBR[59].enq[CHIP]][1] = SCM1[59].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[59].r[CHIP][SCBR[59].enq[CHIP]][1] = SCM1[59].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[59].r[CHIP][SCBR[59].enq[CHIP]][1] = SCM1[59].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[59].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[59].r[CHIP][SCBR[59].enq[CHIP]][0]:SCM0[59].b[CHIP][0]) : SCM0[59].awoo[CHIP][0];
SCM0[59].o[CHIP][0] = eam(1 ? SCBR[59].r[CHIP][SCBR[59].enq[CHIP]][2] : SCM0[59].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[59].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[59].b[CHIP][0]:SCM0[59].awoo[CHIP][0]);
adr = (Ull)(SCM0[59].awoo[CHIP][0] + SCM0[59].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[59].r[CHIP][SCBR[59].enq[CHIP]][0] = SCM0[59].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[59].r[CHIP][SCBR[59].enq[CHIP]][0] = SCM0[59].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[59].r[CHIP][SCBR[59].enq[CHIP]][0] = SCM0[59].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[59].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[59].r[CHIP][SCBR[59].enq[CHIP]][0]:SCM1[59].b[CHIP][1]) : SCM1[59].awoo[CHIP][1];
SCM1[59].o[CHIP][1] = eam(1 ? SCBR[59].r[CHIP][SCBR[59].enq[CHIP]][2] : SCM1[59].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[59].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[59].b[CHIP][1]:SCM1[59].awoo[CHIP][1]);
adr = (Ull)(SCM1[59].awoo[CHIP][1] + SCM1[59].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[59].r[CHIP][SCBR[59].enq[CHIP]][5] = SCM1[59].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[59].r[CHIP][SCBR[59].enq[CHIP]][5] = SCM1[59].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[59].r[CHIP][SCBR[59].enq[CHIP]][5] = SCM1[59].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[59].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[59].r[CHIP][SCBR[59].enq[CHIP]][0]:SCM0[59].b[CHIP][1]) : SCM0[59].awoo[CHIP][1];
SCM0[59].o[CHIP][1] = eam(1 ? SCBR[59].r[CHIP][SCBR[59].enq[CHIP]][2] : SCM0[59].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[59].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[59].b[CHIP][1]:SCM0[59].awoo[CHIP][1]);
adr = (Ull)(SCM0[59].awoo[CHIP][1] + SCM0[59].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[59].r[CHIP][SCBR[59].enq[CHIP]][4] = SCM0[59].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[59].r[CHIP][SCBR[59].enq[CHIP]][4] = SCM0[59].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[59].r[CHIP][SCBR[59].enq[CHIP]][4] = SCM0[59].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[59].r[CHIP][SCBR[59].enq[CHIP]][2] = SCBR[58].r[CHIP][SCBR[2].enq[CHIP]][-1853683480];
SCBR[59].r[CHIP][SCBR[59].enq[CHIP]][3] = SCBR[58].r[CHIP][SCBR[3].enq[CHIP]][-1853683480];
}
{
}
{
}
{
}
uLOOP[59][CHIP]--;
SCBR[59].enq[CHIP] = 1-SCBR[59].enq[CHIP];
}
}
}
void emax6sc_pth_mm_60(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit60 */
uLOOP[60][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[60][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[60][CHIP]==0) continue;
if ((60 && SCBR[59].enq[CHIP]==SCBR[59].deq[CHIP]) || SCBR[60].enq[CHIP]!=SCBR[60].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[60][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[60][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[59].deq[CHIP] = 1-SCBR[59].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[60].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[60].r[CHIP][SCBR[60].enq[CHIP]][0]:SCM1[60].b[CHIP][0]) : SCM1[60].awoo[CHIP][0];
SCM1[60].o[CHIP][0] = eam(1 ? SCBR[60].r[CHIP][SCBR[60].enq[CHIP]][2] : SCM1[60].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[60].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[60].b[CHIP][0]:SCM1[60].awoo[CHIP][0]);
adr = (Ull)(SCM1[60].awoo[CHIP][0] + SCM1[60].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[60].r[CHIP][SCBR[60].enq[CHIP]][1] = SCM1[60].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[60].r[CHIP][SCBR[60].enq[CHIP]][1] = SCM1[60].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[60].r[CHIP][SCBR[60].enq[CHIP]][1] = SCM1[60].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[60].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[60].r[CHIP][SCBR[60].enq[CHIP]][0]:SCM0[60].b[CHIP][0]) : SCM0[60].awoo[CHIP][0];
SCM0[60].o[CHIP][0] = eam(1 ? SCBR[60].r[CHIP][SCBR[60].enq[CHIP]][2] : SCM0[60].o[CHIP][0], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[60].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[60].b[CHIP][0]:SCM0[60].awoo[CHIP][0]);
adr = (Ull)(SCM0[60].awoo[CHIP][0] + SCM0[60].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[60].r[CHIP][SCBR[60].enq[CHIP]][0] = SCM0[60].d[CHIP][0][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[60].r[CHIP][SCBR[60].enq[CHIP]][0] = SCM0[60].d[CHIP][0][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[60].r[CHIP][SCBR[60].enq[CHIP]][0] = SCM0[60].d[CHIP][0][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[60].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[60].r[CHIP][SCBR[60].enq[CHIP]][0]:SCM1[60].b[CHIP][1]) : SCM1[60].awoo[CHIP][1];
SCM1[60].o[CHIP][1] = eam(1 ? SCBR[60].r[CHIP][SCBR[60].enq[CHIP]][2] : SCM1[60].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[60].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[60].b[CHIP][1]:SCM1[60].awoo[CHIP][1]);
adr = (Ull)(SCM1[60].awoo[CHIP][1] + SCM1[60].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[60].r[CHIP][SCBR[60].enq[CHIP]][5] = SCM1[60].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[60].r[CHIP][SCBR[60].enq[CHIP]][5] = SCM1[60].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[60].r[CHIP][SCBR[60].enq[CHIP]][5] = SCM1[60].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
SCM0[60].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[60].r[CHIP][SCBR[60].enq[CHIP]][0]:SCM0[60].b[CHIP][1]) : SCM0[60].awoo[CHIP][1];
SCM0[60].o[CHIP][1] = eam(1 ? SCBR[60].r[CHIP][SCBR[60].enq[CHIP]][2] : SCM0[60].o[CHIP][1], 13);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[60].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[60].b[CHIP][1]:SCM0[60].awoo[CHIP][1]);
adr = (Ull)(SCM0[60].awoo[CHIP][1] + SCM0[60].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[60].r[CHIP][SCBR[60].enq[CHIP]][4] = SCM0[60].d[CHIP][1][0] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[60].r[CHIP][SCBR[60].enq[CHIP]][4] = SCM0[60].d[CHIP][1][0] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[60].r[CHIP][SCBR[60].enq[CHIP]][4] = SCM0[60].d[CHIP][1][0] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[60].r[CHIP][SCBR[60].enq[CHIP]][2] = SCBR[59].r[CHIP][SCBR[3].enq[CHIP]][-1853683352];
}
{
}
{
}
{
}
uLOOP[60][CHIP]--;
SCBR[60].enq[CHIP] = 1-SCBR[60].enq[CHIP];
}
}
}
void emax6sc_pth_mm_61(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit61 */
uLOOP[61][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[61][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[61][CHIP]==0) continue;
if ((61 && SCBR[60].enq[CHIP]==SCBR[60].deq[CHIP]) || SCBR[61].enq[CHIP]!=SCBR[61].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[61][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[61][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[60].deq[CHIP] = 1-SCBR[60].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
}
{
SCBR[61].r[CHIP][SCBR[61].enq[CHIP]][0] = SCBR[60].r[CHIP][SCBR[2].enq[CHIP]][10];
}
{
}
{
}
{
}
uLOOP[61][CHIP]--;
SCBR[61].enq[CHIP] = 1-SCBR[61].enq[CHIP];
}
}
}
void emax6sc_pth_mm_62(struct pth *param) {
for (CHIP=0; CHIP<4; CHIP++) { /* unit62 */
uLOOP[62][CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[62][CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[62][CHIP]==0) continue;
if ((62 && SCBR[61].enq[CHIP]==SCBR[61].deq[CHIP]) || SCBR[62].enq[CHIP]!=SCBR[62].deq[CHIP]) continue;
INIT1[CHIP]=(uLOOP[62][CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[62][CHIP]-(uLOOP[0][CHIP]/LOOP0*LOOP0)==0);
SCBR[61].deq[CHIP] = 1-SCBR[61].deq[CHIP];
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[62].b[CHIP][0] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[62].r[CHIP][SCBR[62].enq[CHIP]][8]:SCM1[62].b[CHIP][0]) : SCM1[62].awoo[CHIP][0];
SCM1[62].o[CHIP][0] = eam(1 ? SCBR[62].r[CHIP][SCBR[62].enq[CHIP]][0] : SCM1[62].o[CHIP][0], 12);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[62].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM1[62].b[CHIP][0]:SCM1[62].awoo[CHIP][0]);
adr = (Ull)(SCM1[62].awoo[CHIP][0] + SCM1[62].o[CHIP][0]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[62].r[CHIP][SCBR[62].enq[CHIP]][1] = SCM1[62].d[CHIP][0][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[62].r[CHIP][SCBR[62].enq[CHIP]][1] = SCM1[62].d[CHIP][0][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[62].r[CHIP][SCBR[62].enq[CHIP]][1] = SCM1[62].d[CHIP][0][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[62].b[CHIP][1] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[62].r[CHIP][SCBR[62].enq[CHIP]][8]:SCM1[62].b[CHIP][1]) : SCM1[62].awoo[CHIP][1];
SCM1[62].o[CHIP][1] = eam(1 ? SCBR[62].r[CHIP][SCBR[62].enq[CHIP]][0] : SCM1[62].o[CHIP][1], 12);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[62].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM1[62].b[CHIP][1]:SCM1[62].awoo[CHIP][1]);
adr = (Ull)(SCM1[62].awoo[CHIP][1] + SCM1[62].o[CHIP][1]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[62].r[CHIP][SCBR[62].enq[CHIP]][5] = SCM1[62].d[CHIP][1][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[62].r[CHIP][SCBR[62].enq[CHIP]][5] = SCM1[62].d[CHIP][1][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[62].r[CHIP][SCBR[62].enq[CHIP]][5] = SCM1[62].d[CHIP][1][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[62].b[CHIP][2] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[62].r[CHIP][SCBR[62].enq[CHIP]][8]:SCM1[62].b[CHIP][2]) : SCM1[62].awoo[CHIP][2];
SCM1[62].o[CHIP][2] = eam(1 ? SCBR[62].r[CHIP][SCBR[62].enq[CHIP]][0] : SCM1[62].o[CHIP][2], 12);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[62].awoo[CHIP][2] = (Ull)(INIT0[CHIP]?SCM1[62].b[CHIP][2]:SCM1[62].awoo[CHIP][2]);
adr = (Ull)(SCM1[62].awoo[CHIP][2] + SCM1[62].o[CHIP][2]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[62].r[CHIP][SCBR[62].enq[CHIP]][9] = SCM1[62].d[CHIP][2][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[62].r[CHIP][SCBR[62].enq[CHIP]][9] = SCM1[62].d[CHIP][2][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[62].r[CHIP][SCBR[62].enq[CHIP]][9] = SCM1[62].d[CHIP][2][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ Ull adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
SCM1[62].b[CHIP][3] = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[62].r[CHIP][SCBR[62].enq[CHIP]][8]:SCM1[62].b[CHIP][3]) : SCM1[62].awoo[CHIP][3];
SCM1[62].o[CHIP][3] = eam(1 ? SCBR[62].r[CHIP][SCBR[62].enq[CHIP]][0] : SCM1[62].o[CHIP][3], 12);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM1[62].awoo[CHIP][3] = (Ull)(INIT0[CHIP]?SCM1[62].b[CHIP][3]:SCM1[62].awoo[CHIP][3]);
adr = (Ull)(SCM1[62].awoo[CHIP][3] + SCM1[62].o[CHIP][3]);
load64 = *(Ull*)(adr&~7LL);
if ((adr&7) == 0)
  SCBR[62].r[CHIP][SCBR[62].enq[CHIP]][13] = SCM1[62].d[CHIP][3][1] = load64;
else if (!emax6_unaligned_load_valid) { /* BR[][][1] */
  emax6_unaligned_load_valid = 1;
  emax6_unaligned_load_high = load64;
  SCBR[62].r[CHIP][SCBR[62].enq[CHIP]][13] = SCM1[62].d[CHIP][3][1] = load64 >> (adr&7)*8;
}
else { /* BR[][][0] */
  emax6_unaligned_load_valid = 0;
  SCBR[62].r[CHIP][SCBR[62].enq[CHIP]][13] = SCM1[62].d[CHIP][3][1] = emax6_unaligned_load_high << (8-(adr&7))*8 | load64 >> (adr&7)*8;
}
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[62].r[CHIP][SCBR[62].enq[CHIP]][0] : SCAR[62].r[CHIP][0], 0);
ex2 = exm(((0&2)&&INIT0[CHIP]) ? SCBR[62].r[CHIP][SCBR[62].enq[CHIP]][1] : 0, 62);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32);
f0.f = f1.f + f2.f;
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2);
f0.f = f1.f + f2.f;
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[62].r[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[62].r[CHIP][SCBR[62].enq[CHIP]][3] : SCAR[62].r[CHIP][1], 0);
ex2 = exm(((0&2)&&INIT0[CHIP]) ? SCBR[62].r[CHIP][SCBR[62].enq[CHIP]][5] : 0, 62);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32);
f0.f = f1.f + f2.f;
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2);
f0.f = f1.f + f2.f;
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[62].r[CHIP][1] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[62].r[CHIP][SCBR[62].enq[CHIP]][4] : SCAR[62].r[CHIP][2], 0);
ex2 = exm(((0&2)&&INIT0[CHIP]) ? SCBR[62].r[CHIP][SCBR[62].enq[CHIP]][9] : 0, 62);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32);
f0.f = f1.f + f2.f;
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2);
f0.f = f1.f + f2.f;
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[62].r[CHIP][2] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[62].r[CHIP][SCBR[62].enq[CHIP]][7] : SCAR[62].r[CHIP][3], 0);
ex2 = exm(((0&2)&&INIT0[CHIP]) ? SCBR[62].r[CHIP][SCBR[62].enq[CHIP]][13] : 0, 62);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32);
f0.f = f1.f + f2.f;
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2);
f0.f = f1.f + f2.f;
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
SCAR[62].r[CHIP][3] = ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
cex = 3;
SCM0[62].b[CHIP][0] = (!(2&1)||INIT0[CHIP]) ? ((2&2)?SCBR[62].r[CHIP][SCBR[62].enq[CHIP]][8]:SCM0[62].b[CHIP][0]) : SCM0[62].awoo[CHIP][0];
SCM0[62].o[CHIP][0] = eam(0 ? SCBR[62].r[CHIP][SCBR[62].enq[CHIP]][0] : SCM0[62].o[CHIP][0], 14);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[62].awoo[CHIP][0] = (Ull)(INIT0[CHIP]?SCM0[62].b[CHIP][0]:SCM0[62].awoo[CHIP][0]);
adr = (Ull)(SCM0[62].awoo[CHIP][0] + SCM0[62].o[CHIP][0]);
if (cex>>1&1) *((Uint*)(adr&~7LL)+1) = (1==1? SCAR[62].r[CHIP][0] : SCBR[62].r[CHIP][SCBR[62].enq[CHIP]][0])>>32;
if (cex   &1) *((Uint*)(adr&~7LL)  ) = (1==1? SCAR[62].r[CHIP][0] : SCBR[62].r[CHIP][SCBR[62].enq[CHIP]][0]);
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
cex = 3;
SCM0[62].b[CHIP][1] = (!(2&1)||INIT0[CHIP]) ? ((2&2)?SCBR[62].r[CHIP][SCBR[62].enq[CHIP]][8]:SCM0[62].b[CHIP][1]) : SCM0[62].awoo[CHIP][1];
SCM0[62].o[CHIP][1] = eam(0 ? SCBR[62].r[CHIP][SCBR[62].enq[CHIP]][0] : SCM0[62].o[CHIP][1], 14);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[62].awoo[CHIP][1] = (Ull)(INIT0[CHIP]?SCM0[62].b[CHIP][1]:SCM0[62].awoo[CHIP][1]);
adr = (Ull)(SCM0[62].awoo[CHIP][1] + SCM0[62].o[CHIP][1]);
if (cex>>1&1) *((Uint*)(adr&~7LL)+1) = (1==1? SCAR[62].r[CHIP][1] : SCBR[62].r[CHIP][SCBR[62].enq[CHIP]][0])>>32;
if (cex   &1) *((Uint*)(adr&~7LL)  ) = (1==1? SCAR[62].r[CHIP][1] : SCBR[62].r[CHIP][SCBR[62].enq[CHIP]][0]);
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
cex = 3;
SCM0[62].b[CHIP][2] = (!(2&1)||INIT0[CHIP]) ? ((2&2)?SCBR[62].r[CHIP][SCBR[62].enq[CHIP]][8]:SCM0[62].b[CHIP][2]) : SCM0[62].awoo[CHIP][2];
SCM0[62].o[CHIP][2] = eam(0 ? SCBR[62].r[CHIP][SCBR[62].enq[CHIP]][0] : SCM0[62].o[CHIP][2], 14);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[62].awoo[CHIP][2] = (Ull)(INIT0[CHIP]?SCM0[62].b[CHIP][2]:SCM0[62].awoo[CHIP][2]);
adr = (Ull)(SCM0[62].awoo[CHIP][2] + SCM0[62].o[CHIP][2]);
if (cex>>1&1) *((Uint*)(adr&~7LL)+1) = (1==1? SCAR[62].r[CHIP][2] : SCBR[62].r[CHIP][SCBR[62].enq[CHIP]][0])>>32;
if (cex   &1) *((Uint*)(adr&~7LL)  ) = (1==1? SCAR[62].r[CHIP][2] : SCBR[62].r[CHIP][SCBR[62].enq[CHIP]][0]);
}
{ Ull cs0, cs1, cs2, cs3, cex, adr, mexdist;
cex = 3;
SCM0[62].b[CHIP][3] = (!(2&1)||INIT0[CHIP]) ? ((2&2)?SCBR[62].r[CHIP][SCBR[62].enq[CHIP]][8]:SCM0[62].b[CHIP][3]) : SCM0[62].awoo[CHIP][3];
SCM0[62].o[CHIP][3] = eam(0 ? SCBR[62].r[CHIP][SCBR[62].enq[CHIP]][0] : SCM0[62].o[CHIP][3], 14);
mexdist = (0 || INIT0[CHIP]) ? 0 : 0;
SCM0[62].awoo[CHIP][3] = (Ull)(INIT0[CHIP]?SCM0[62].b[CHIP][3]:SCM0[62].awoo[CHIP][3]);
adr = (Ull)(SCM0[62].awoo[CHIP][3] + SCM0[62].o[CHIP][3]);
if (cex>>1&1) *((Uint*)(adr&~7LL)+1) = (1==1? SCAR[62].r[CHIP][3] : SCBR[62].r[CHIP][SCBR[62].enq[CHIP]][0])>>32;
if (cex   &1) *((Uint*)(adr&~7LL)  ) = (1==1? SCAR[62].r[CHIP][3] : SCBR[62].r[CHIP][SCBR[62].enq[CHIP]][0]);
}
{
}
{
}
{
SCBR[62].r[CHIP][SCBR[62].enq[CHIP]][8] = SCBR[61].r[CHIP][SCBR[0].enq[CHIP]][10];
}
{
}
uLOOP[62][CHIP]--;
SCBR[62].enq[CHIP] = 1-SCBR[62].enq[CHIP];
}
}
}
/* EMAXSC end */
#endif
