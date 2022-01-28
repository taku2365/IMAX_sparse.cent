/* EMAXSC start */
void emax6sc_pth_inv_x1_00(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit0 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (0 && SCBR[63].enq[CHIP]==SCBR[63].deq[CHIP]) || (0<17 && SCBR[0].enq[CHIP]!=SCBR[0].deq[CHIP])) continue;
SCBR[63].deq[CHIP] = 1-SCBR[63].deq[CHIP];
enq[CHIP] = SCBR[0].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!1||(INIT1[CHIP]&&INIT0[CHIP])||((1&1)&&INIT0[CHIP]) ? SCBR[63].r[CHIP][enq[CHIP]][3] : alud[CHIP][2], 0);
ex2 = exm(((1&2)&&!INIT0[CHIP]) ? 0 : SCBR[63].r[CHIP][enq[CHIP]][4], 0);
t2 = (ex1>>32&0x00000000ffffffffLL)+(ex2>>32&0x00000000ffffffffLL);
t2 &= 0x00000000ffffffffLL;
t0 = (ex1    &0x00000000ffffffffLL)+(ex2    &0x00000000ffffffffLL);
t0 &= 0x00000000ffffffffLL;
ex1_outd = (t2<<32)|(t0);
ex4 = 0==0 ? 0x00000000ffffffffLL : 0==1 ? SCBR[63].r[CHIP][enq[CHIP]][4] : SCBR[63].r[CHIP][enq[CHIP]][0];
ex2_outd = ex1_outd & ex4;
alud[CHIP][2] = ex2_outd;
SCBR[0].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!1||(INIT1[CHIP]&&INIT0[CHIP])||((2&1)&&INIT0[CHIP]) ? SCBR[63].r[CHIP][enq[CHIP]][5] : alud[CHIP][3], 0);
ex2 = exm(((2&2)&&!INIT0[CHIP]) ? 0 : SCBR[63].r[CHIP][enq[CHIP]][6], 0);
t2 = (ex1>>32&0x00000000ffffffffLL)+(ex2>>32&0x00000000ffffffffLL);
t2 &= 0x00000000ffffffffLL;
t0 = (ex1    &0x00000000ffffffffLL)+(ex2    &0x00000000ffffffffLL);
t0 &= 0x00000000ffffffffLL;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[0].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[0].enq[CHIP] = 1-SCBR[0].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_inv_x1_01(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit1 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (1 && SCBR[0].enq[CHIP]==SCBR[0].deq[CHIP]) || (1<17 && SCBR[1].enq[CHIP]!=SCBR[1].deq[CHIP])) continue;
SCBR[0].deq[CHIP] = 1-SCBR[0].deq[CHIP];
enq[CHIP] = SCBR[1].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[0].r[CHIP][enq[CHIP]][14] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[0].r[CHIP][enq[CHIP]][10], 0);
t2 = (ex1>>32&0x00000000ffffffffLL)+(ex2>>32&0x00000000ffffffffLL);
t2 &= 0x00000000ffffffffLL;
t0 = (ex1    &0x00000000ffffffffLL)+(ex2    &0x00000000ffffffffLL);
t0 &= 0x00000000ffffffffLL;
ex1_outd = (t2<<32)|(t0);
ex4 = 0==0 ? 0x00000000ffffffffLL : 0==1 ? SCBR[0].r[CHIP][enq[CHIP]][10] : SCBR[0].r[CHIP][enq[CHIP]][0];
ex2_outd = ex1_outd & ex4;
alud[CHIP][0] = ex2_outd;
SCBR[1].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[0].r[CHIP][enq[CHIP]][0] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[0].r[CHIP][enq[CHIP]][1], 0);
c1 = (ex1>>32&0x00000000ffffffffLL) < (ex2>>32&0x00000000ffffffffLL);
c0 = (ex1    &0x00000000ffffffffLL) < (ex2    &0x00000000ffffffffLL);
ex1_outd = (c1<<32)|c0;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[1].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[1].enq[CHIP] = 1-SCBR[1].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_inv_x1_02(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit2 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (2 && SCBR[1].enq[CHIP]==SCBR[1].deq[CHIP]) || (2<17 && SCBR[2].enq[CHIP]!=SCBR[2].deq[CHIP])) continue;
SCBR[1].deq[CHIP] = 1-SCBR[1].deq[CHIP];
enq[CHIP] = SCBR[2].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
SCBR[2].r[CHIP][enq[CHIP]][5] = SCBR[1].r[CHIP][enq[CHIP]][2];
}
{
}
{
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[1].r[CHIP][enq[CHIP]][0] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[1].r[CHIP][enq[CHIP]][1], 0);
ex3 = exm(SCBR[1].r[CHIP][enq[CHIP]][3], 0);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^80000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^80000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[1].r[CHIP][enq[CHIP]][5] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[1].r[CHIP][enq[CHIP]][7], 0);
c1 = (ex1>>32&0x00000000ffffffffLL) < (ex2>>32&0x00000000ffffffffLL);
c0 = (ex1    &0x00000000ffffffffLL) < (ex2    &0x00000000ffffffffLL);
ex1_outd = (c1<<32)|c0;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[2].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cs0 = SCBR[1].r[CHIP][enq[CHIP]][6];
cs1 = SCBR[1].r[CHIP][enq[CHIP]][4];
cs2 = SCBR[1].r[CHIP][enq[CHIP]][4];
cs3 = SCBR[1].r[CHIP][enq[CHIP]][4];
cex = ((0xaaaa>>(((cs3>>32&1)<<3)|((cs2>>32&1)<<2)|((cs1>>32&1)<<1)|(cs0>>32&1))&1)?2:0) | ((0xaaaa>>(((cs3&1)<<3)|((cs2&1)<<2)|((cs1&1)<<1)|(cs0&1))&1)?1:0);
base = (!(2&1)||INIT0[CHIP]) ? ((2&2)?SCBR[1].r[CHIP][enq[CHIP]][2]:SCM0[2].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[1].r[CHIP][enq[CHIP]][0] : SCM0[2].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (1==1? alud[CHIP][0] : SCBR[1].r[CHIP][enq[CHIP]][0]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[2].enq[CHIP] = 1-SCBR[2].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_inv_x1_03(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit3 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (3 && SCBR[2].enq[CHIP]==SCBR[2].deq[CHIP]) || (3<17 && SCBR[3].enq[CHIP]!=SCBR[3].deq[CHIP])) continue;
SCBR[2].deq[CHIP] = 1-SCBR[2].deq[CHIP];
enq[CHIP] = SCBR[3].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
SCBR[3].r[CHIP][enq[CHIP]][5] = SCBR[2].r[CHIP][enq[CHIP]][5];
}
{
}
{
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[2].r[CHIP][enq[CHIP]][0] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[2].r[CHIP][enq[CHIP]][1], 0);
ex3 = exm(SCBR[2].r[CHIP][enq[CHIP]][3], 0);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^80000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^80000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[2].r[CHIP][enq[CHIP]][7] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[2].r[CHIP][enq[CHIP]][8], 0);
c1 = (ex1>>32&0x00000000ffffffffLL) < (ex2>>32&0x00000000ffffffffLL);
c0 = (ex1    &0x00000000ffffffffLL) < (ex2    &0x00000000ffffffffLL);
ex1_outd = (c1<<32)|c0;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[3].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cs0 = SCBR[2].r[CHIP][enq[CHIP]][6];
cs1 = SCBR[2].r[CHIP][enq[CHIP]][4];
cs2 = SCBR[2].r[CHIP][enq[CHIP]][4];
cs3 = SCBR[2].r[CHIP][enq[CHIP]][4];
cex = ((0xaaaa>>(((cs3>>32&1)<<3)|((cs2>>32&1)<<2)|((cs1>>32&1)<<1)|(cs0>>32&1))&1)?2:0) | ((0xaaaa>>(((cs3&1)<<3)|((cs2&1)<<2)|((cs1&1)<<1)|(cs0&1))&1)?1:0);
base = (!(2&1)||INIT0[CHIP]) ? ((2&2)?SCBR[2].r[CHIP][enq[CHIP]][5]:SCM0[3].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[2].r[CHIP][enq[CHIP]][0] : SCM0[3].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (1==1? alud[CHIP][0] : SCBR[2].r[CHIP][enq[CHIP]][0]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[3].enq[CHIP] = 1-SCBR[3].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_inv_x1_04(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit4 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (4 && SCBR[3].enq[CHIP]==SCBR[3].deq[CHIP]) || (4<17 && SCBR[4].enq[CHIP]!=SCBR[4].deq[CHIP])) continue;
SCBR[3].deq[CHIP] = 1-SCBR[3].deq[CHIP];
enq[CHIP] = SCBR[4].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
SCBR[4].r[CHIP][enq[CHIP]][5] = SCBR[3].r[CHIP][enq[CHIP]][5];
}
{
}
{
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[3].r[CHIP][enq[CHIP]][0] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[3].r[CHIP][enq[CHIP]][1], 0);
ex3 = exm(SCBR[3].r[CHIP][enq[CHIP]][3], 0);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^80000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^80000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[3].r[CHIP][enq[CHIP]][7] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[3].r[CHIP][enq[CHIP]][8], 0);
c1 = (ex1>>32&0x00000000ffffffffLL) < (ex2>>32&0x00000000ffffffffLL);
c0 = (ex1    &0x00000000ffffffffLL) < (ex2    &0x00000000ffffffffLL);
ex1_outd = (c1<<32)|c0;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[4].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cs0 = SCBR[3].r[CHIP][enq[CHIP]][6];
cs1 = SCBR[3].r[CHIP][enq[CHIP]][4];
cs2 = SCBR[3].r[CHIP][enq[CHIP]][4];
cs3 = SCBR[3].r[CHIP][enq[CHIP]][4];
cex = ((0xaaaa>>(((cs3>>32&1)<<3)|((cs2>>32&1)<<2)|((cs1>>32&1)<<1)|(cs0>>32&1))&1)?2:0) | ((0xaaaa>>(((cs3&1)<<3)|((cs2&1)<<2)|((cs1&1)<<1)|(cs0&1))&1)?1:0);
base = (!(2&1)||INIT0[CHIP]) ? ((2&2)?SCBR[3].r[CHIP][enq[CHIP]][5]:SCM0[4].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[3].r[CHIP][enq[CHIP]][0] : SCM0[4].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (1==1? alud[CHIP][0] : SCBR[3].r[CHIP][enq[CHIP]][0]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[4].enq[CHIP] = 1-SCBR[4].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_inv_x1_05(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit5 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (5 && SCBR[4].enq[CHIP]==SCBR[4].deq[CHIP]) || (5<17 && SCBR[5].enq[CHIP]!=SCBR[5].deq[CHIP])) continue;
SCBR[4].deq[CHIP] = 1-SCBR[4].deq[CHIP];
enq[CHIP] = SCBR[5].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
SCBR[5].r[CHIP][enq[CHIP]][5] = SCBR[4].r[CHIP][enq[CHIP]][5];
}
{
}
{
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[4].r[CHIP][enq[CHIP]][0] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[4].r[CHIP][enq[CHIP]][1], 0);
ex3 = exm(SCBR[4].r[CHIP][enq[CHIP]][3], 0);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^80000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^80000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[4].r[CHIP][enq[CHIP]][7] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[4].r[CHIP][enq[CHIP]][8], 0);
c1 = (ex1>>32&0x00000000ffffffffLL) < (ex2>>32&0x00000000ffffffffLL);
c0 = (ex1    &0x00000000ffffffffLL) < (ex2    &0x00000000ffffffffLL);
ex1_outd = (c1<<32)|c0;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[5].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cs0 = SCBR[4].r[CHIP][enq[CHIP]][6];
cs1 = SCBR[4].r[CHIP][enq[CHIP]][4];
cs2 = SCBR[4].r[CHIP][enq[CHIP]][4];
cs3 = SCBR[4].r[CHIP][enq[CHIP]][4];
cex = ((0xaaaa>>(((cs3>>32&1)<<3)|((cs2>>32&1)<<2)|((cs1>>32&1)<<1)|(cs0>>32&1))&1)?2:0) | ((0xaaaa>>(((cs3&1)<<3)|((cs2&1)<<2)|((cs1&1)<<1)|(cs0&1))&1)?1:0);
base = (!(2&1)||INIT0[CHIP]) ? ((2&2)?SCBR[4].r[CHIP][enq[CHIP]][5]:SCM0[5].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[4].r[CHIP][enq[CHIP]][0] : SCM0[5].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (1==1? alud[CHIP][0] : SCBR[4].r[CHIP][enq[CHIP]][0]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[5].enq[CHIP] = 1-SCBR[5].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_inv_x1_06(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit6 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (6 && SCBR[5].enq[CHIP]==SCBR[5].deq[CHIP]) || (6<17 && SCBR[6].enq[CHIP]!=SCBR[6].deq[CHIP])) continue;
SCBR[5].deq[CHIP] = 1-SCBR[5].deq[CHIP];
enq[CHIP] = SCBR[6].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
SCBR[6].r[CHIP][enq[CHIP]][5] = SCBR[5].r[CHIP][enq[CHIP]][5];
}
{
}
{
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[5].r[CHIP][enq[CHIP]][0] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[5].r[CHIP][enq[CHIP]][1], 0);
ex3 = exm(SCBR[5].r[CHIP][enq[CHIP]][3], 0);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^80000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^80000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[5].r[CHIP][enq[CHIP]][7] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[5].r[CHIP][enq[CHIP]][8], 0);
c1 = (ex1>>32&0x00000000ffffffffLL) < (ex2>>32&0x00000000ffffffffLL);
c0 = (ex1    &0x00000000ffffffffLL) < (ex2    &0x00000000ffffffffLL);
ex1_outd = (c1<<32)|c0;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[6].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cs0 = SCBR[5].r[CHIP][enq[CHIP]][6];
cs1 = SCBR[5].r[CHIP][enq[CHIP]][4];
cs2 = SCBR[5].r[CHIP][enq[CHIP]][4];
cs3 = SCBR[5].r[CHIP][enq[CHIP]][4];
cex = ((0xaaaa>>(((cs3>>32&1)<<3)|((cs2>>32&1)<<2)|((cs1>>32&1)<<1)|(cs0>>32&1))&1)?2:0) | ((0xaaaa>>(((cs3&1)<<3)|((cs2&1)<<2)|((cs1&1)<<1)|(cs0&1))&1)?1:0);
base = (!(2&1)||INIT0[CHIP]) ? ((2&2)?SCBR[5].r[CHIP][enq[CHIP]][5]:SCM0[6].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[5].r[CHIP][enq[CHIP]][0] : SCM0[6].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (1==1? alud[CHIP][0] : SCBR[5].r[CHIP][enq[CHIP]][0]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[6].enq[CHIP] = 1-SCBR[6].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_inv_x1_07(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit7 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (7 && SCBR[6].enq[CHIP]==SCBR[6].deq[CHIP]) || (7<17 && SCBR[7].enq[CHIP]!=SCBR[7].deq[CHIP])) continue;
SCBR[6].deq[CHIP] = 1-SCBR[6].deq[CHIP];
enq[CHIP] = SCBR[7].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
SCBR[7].r[CHIP][enq[CHIP]][5] = SCBR[6].r[CHIP][enq[CHIP]][5];
}
{
}
{
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[6].r[CHIP][enq[CHIP]][0] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[6].r[CHIP][enq[CHIP]][1], 0);
ex3 = exm(SCBR[6].r[CHIP][enq[CHIP]][3], 0);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^80000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^80000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[6].r[CHIP][enq[CHIP]][7] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[6].r[CHIP][enq[CHIP]][8], 0);
c1 = (ex1>>32&0x00000000ffffffffLL) < (ex2>>32&0x00000000ffffffffLL);
c0 = (ex1    &0x00000000ffffffffLL) < (ex2    &0x00000000ffffffffLL);
ex1_outd = (c1<<32)|c0;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[7].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cs0 = SCBR[6].r[CHIP][enq[CHIP]][6];
cs1 = SCBR[6].r[CHIP][enq[CHIP]][4];
cs2 = SCBR[6].r[CHIP][enq[CHIP]][4];
cs3 = SCBR[6].r[CHIP][enq[CHIP]][4];
cex = ((0xaaaa>>(((cs3>>32&1)<<3)|((cs2>>32&1)<<2)|((cs1>>32&1)<<1)|(cs0>>32&1))&1)?2:0) | ((0xaaaa>>(((cs3&1)<<3)|((cs2&1)<<2)|((cs1&1)<<1)|(cs0&1))&1)?1:0);
base = (!(2&1)||INIT0[CHIP]) ? ((2&2)?SCBR[6].r[CHIP][enq[CHIP]][5]:SCM0[7].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[6].r[CHIP][enq[CHIP]][0] : SCM0[7].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (1==1? alud[CHIP][0] : SCBR[6].r[CHIP][enq[CHIP]][0]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[7].enq[CHIP] = 1-SCBR[7].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_inv_x1_08(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit8 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (8 && SCBR[7].enq[CHIP]==SCBR[7].deq[CHIP]) || (8<17 && SCBR[8].enq[CHIP]!=SCBR[8].deq[CHIP])) continue;
SCBR[7].deq[CHIP] = 1-SCBR[7].deq[CHIP];
enq[CHIP] = SCBR[8].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
SCBR[8].r[CHIP][enq[CHIP]][5] = SCBR[7].r[CHIP][enq[CHIP]][5];
}
{
}
{
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[7].r[CHIP][enq[CHIP]][0] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[7].r[CHIP][enq[CHIP]][1], 0);
ex3 = exm(SCBR[7].r[CHIP][enq[CHIP]][3], 0);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^80000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^80000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[7].r[CHIP][enq[CHIP]][7] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[7].r[CHIP][enq[CHIP]][8], 0);
c1 = (ex1>>32&0x00000000ffffffffLL) < (ex2>>32&0x00000000ffffffffLL);
c0 = (ex1    &0x00000000ffffffffLL) < (ex2    &0x00000000ffffffffLL);
ex1_outd = (c1<<32)|c0;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[8].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cs0 = SCBR[7].r[CHIP][enq[CHIP]][6];
cs1 = SCBR[7].r[CHIP][enq[CHIP]][4];
cs2 = SCBR[7].r[CHIP][enq[CHIP]][4];
cs3 = SCBR[7].r[CHIP][enq[CHIP]][4];
cex = ((0xaaaa>>(((cs3>>32&1)<<3)|((cs2>>32&1)<<2)|((cs1>>32&1)<<1)|(cs0>>32&1))&1)?2:0) | ((0xaaaa>>(((cs3&1)<<3)|((cs2&1)<<2)|((cs1&1)<<1)|(cs0&1))&1)?1:0);
base = (!(2&1)||INIT0[CHIP]) ? ((2&2)?SCBR[7].r[CHIP][enq[CHIP]][5]:SCM0[8].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[7].r[CHIP][enq[CHIP]][0] : SCM0[8].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (1==1? alud[CHIP][0] : SCBR[7].r[CHIP][enq[CHIP]][0]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[8].enq[CHIP] = 1-SCBR[8].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_inv_x1_09(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit9 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (9 && SCBR[8].enq[CHIP]==SCBR[8].deq[CHIP]) || (9<17 && SCBR[9].enq[CHIP]!=SCBR[9].deq[CHIP])) continue;
SCBR[8].deq[CHIP] = 1-SCBR[8].deq[CHIP];
enq[CHIP] = SCBR[9].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
SCBR[9].r[CHIP][enq[CHIP]][5] = SCBR[8].r[CHIP][enq[CHIP]][5];
}
{
}
{
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[8].r[CHIP][enq[CHIP]][0] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[8].r[CHIP][enq[CHIP]][1], 0);
ex3 = exm(SCBR[8].r[CHIP][enq[CHIP]][3], 0);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^80000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^80000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[8].r[CHIP][enq[CHIP]][7] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[8].r[CHIP][enq[CHIP]][8], 0);
c1 = (ex1>>32&0x00000000ffffffffLL) < (ex2>>32&0x00000000ffffffffLL);
c0 = (ex1    &0x00000000ffffffffLL) < (ex2    &0x00000000ffffffffLL);
ex1_outd = (c1<<32)|c0;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[9].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cs0 = SCBR[8].r[CHIP][enq[CHIP]][6];
cs1 = SCBR[8].r[CHIP][enq[CHIP]][4];
cs2 = SCBR[8].r[CHIP][enq[CHIP]][4];
cs3 = SCBR[8].r[CHIP][enq[CHIP]][4];
cex = ((0xaaaa>>(((cs3>>32&1)<<3)|((cs2>>32&1)<<2)|((cs1>>32&1)<<1)|(cs0>>32&1))&1)?2:0) | ((0xaaaa>>(((cs3&1)<<3)|((cs2&1)<<2)|((cs1&1)<<1)|(cs0&1))&1)?1:0);
base = (!(2&1)||INIT0[CHIP]) ? ((2&2)?SCBR[8].r[CHIP][enq[CHIP]][5]:SCM0[9].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[8].r[CHIP][enq[CHIP]][0] : SCM0[9].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (1==1? alud[CHIP][0] : SCBR[8].r[CHIP][enq[CHIP]][0]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[9].enq[CHIP] = 1-SCBR[9].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_inv_x1_10(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit10 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (10 && SCBR[9].enq[CHIP]==SCBR[9].deq[CHIP]) || (10<17 && SCBR[10].enq[CHIP]!=SCBR[10].deq[CHIP])) continue;
SCBR[9].deq[CHIP] = 1-SCBR[9].deq[CHIP];
enq[CHIP] = SCBR[10].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
SCBR[10].r[CHIP][enq[CHIP]][5] = SCBR[9].r[CHIP][enq[CHIP]][5];
}
{
}
{
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[9].r[CHIP][enq[CHIP]][0] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[9].r[CHIP][enq[CHIP]][1], 0);
ex3 = exm(SCBR[9].r[CHIP][enq[CHIP]][3], 0);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^80000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^80000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[9].r[CHIP][enq[CHIP]][7] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[9].r[CHIP][enq[CHIP]][8], 0);
c1 = (ex1>>32&0x00000000ffffffffLL) < (ex2>>32&0x00000000ffffffffLL);
c0 = (ex1    &0x00000000ffffffffLL) < (ex2    &0x00000000ffffffffLL);
ex1_outd = (c1<<32)|c0;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[10].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cs0 = SCBR[9].r[CHIP][enq[CHIP]][6];
cs1 = SCBR[9].r[CHIP][enq[CHIP]][4];
cs2 = SCBR[9].r[CHIP][enq[CHIP]][4];
cs3 = SCBR[9].r[CHIP][enq[CHIP]][4];
cex = ((0xaaaa>>(((cs3>>32&1)<<3)|((cs2>>32&1)<<2)|((cs1>>32&1)<<1)|(cs0>>32&1))&1)?2:0) | ((0xaaaa>>(((cs3&1)<<3)|((cs2&1)<<2)|((cs1&1)<<1)|(cs0&1))&1)?1:0);
base = (!(2&1)||INIT0[CHIP]) ? ((2&2)?SCBR[9].r[CHIP][enq[CHIP]][5]:SCM0[10].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[9].r[CHIP][enq[CHIP]][0] : SCM0[10].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (1==1? alud[CHIP][0] : SCBR[9].r[CHIP][enq[CHIP]][0]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[10].enq[CHIP] = 1-SCBR[10].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_inv_x1_11(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit11 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (11 && SCBR[10].enq[CHIP]==SCBR[10].deq[CHIP]) || (11<17 && SCBR[11].enq[CHIP]!=SCBR[11].deq[CHIP])) continue;
SCBR[10].deq[CHIP] = 1-SCBR[10].deq[CHIP];
enq[CHIP] = SCBR[11].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
SCBR[11].r[CHIP][enq[CHIP]][5] = SCBR[10].r[CHIP][enq[CHIP]][5];
}
{
}
{
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[10].r[CHIP][enq[CHIP]][0] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[10].r[CHIP][enq[CHIP]][1], 0);
ex3 = exm(SCBR[10].r[CHIP][enq[CHIP]][3], 0);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^80000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^80000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[10].r[CHIP][enq[CHIP]][7] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[10].r[CHIP][enq[CHIP]][8], 0);
c1 = (ex1>>32&0x00000000ffffffffLL) < (ex2>>32&0x00000000ffffffffLL);
c0 = (ex1    &0x00000000ffffffffLL) < (ex2    &0x00000000ffffffffLL);
ex1_outd = (c1<<32)|c0;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[11].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cs0 = SCBR[10].r[CHIP][enq[CHIP]][6];
cs1 = SCBR[10].r[CHIP][enq[CHIP]][4];
cs2 = SCBR[10].r[CHIP][enq[CHIP]][4];
cs3 = SCBR[10].r[CHIP][enq[CHIP]][4];
cex = ((0xaaaa>>(((cs3>>32&1)<<3)|((cs2>>32&1)<<2)|((cs1>>32&1)<<1)|(cs0>>32&1))&1)?2:0) | ((0xaaaa>>(((cs3&1)<<3)|((cs2&1)<<2)|((cs1&1)<<1)|(cs0&1))&1)?1:0);
base = (!(2&1)||INIT0[CHIP]) ? ((2&2)?SCBR[10].r[CHIP][enq[CHIP]][5]:SCM0[11].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[10].r[CHIP][enq[CHIP]][0] : SCM0[11].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (1==1? alud[CHIP][0] : SCBR[10].r[CHIP][enq[CHIP]][0]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[11].enq[CHIP] = 1-SCBR[11].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_inv_x1_12(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit12 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (12 && SCBR[11].enq[CHIP]==SCBR[11].deq[CHIP]) || (12<17 && SCBR[12].enq[CHIP]!=SCBR[12].deq[CHIP])) continue;
SCBR[11].deq[CHIP] = 1-SCBR[11].deq[CHIP];
enq[CHIP] = SCBR[12].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
SCBR[12].r[CHIP][enq[CHIP]][5] = SCBR[11].r[CHIP][enq[CHIP]][5];
}
{
}
{
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[11].r[CHIP][enq[CHIP]][0] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[11].r[CHIP][enq[CHIP]][1], 0);
ex3 = exm(SCBR[11].r[CHIP][enq[CHIP]][3], 0);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^80000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^80000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[11].r[CHIP][enq[CHIP]][7] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[11].r[CHIP][enq[CHIP]][8], 0);
c1 = (ex1>>32&0x00000000ffffffffLL) < (ex2>>32&0x00000000ffffffffLL);
c0 = (ex1    &0x00000000ffffffffLL) < (ex2    &0x00000000ffffffffLL);
ex1_outd = (c1<<32)|c0;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[12].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cs0 = SCBR[11].r[CHIP][enq[CHIP]][6];
cs1 = SCBR[11].r[CHIP][enq[CHIP]][4];
cs2 = SCBR[11].r[CHIP][enq[CHIP]][4];
cs3 = SCBR[11].r[CHIP][enq[CHIP]][4];
cex = ((0xaaaa>>(((cs3>>32&1)<<3)|((cs2>>32&1)<<2)|((cs1>>32&1)<<1)|(cs0>>32&1))&1)?2:0) | ((0xaaaa>>(((cs3&1)<<3)|((cs2&1)<<2)|((cs1&1)<<1)|(cs0&1))&1)?1:0);
base = (!(2&1)||INIT0[CHIP]) ? ((2&2)?SCBR[11].r[CHIP][enq[CHIP]][5]:SCM0[12].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[11].r[CHIP][enq[CHIP]][0] : SCM0[12].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (1==1? alud[CHIP][0] : SCBR[11].r[CHIP][enq[CHIP]][0]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[12].enq[CHIP] = 1-SCBR[12].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_inv_x1_13(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit13 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (13 && SCBR[12].enq[CHIP]==SCBR[12].deq[CHIP]) || (13<17 && SCBR[13].enq[CHIP]!=SCBR[13].deq[CHIP])) continue;
SCBR[12].deq[CHIP] = 1-SCBR[12].deq[CHIP];
enq[CHIP] = SCBR[13].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
SCBR[13].r[CHIP][enq[CHIP]][5] = SCBR[12].r[CHIP][enq[CHIP]][5];
}
{
}
{
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[12].r[CHIP][enq[CHIP]][0] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[12].r[CHIP][enq[CHIP]][1], 0);
ex3 = exm(SCBR[12].r[CHIP][enq[CHIP]][3], 0);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^80000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^80000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[12].r[CHIP][enq[CHIP]][7] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[12].r[CHIP][enq[CHIP]][8], 0);
c1 = (ex1>>32&0x00000000ffffffffLL) < (ex2>>32&0x00000000ffffffffLL);
c0 = (ex1    &0x00000000ffffffffLL) < (ex2    &0x00000000ffffffffLL);
ex1_outd = (c1<<32)|c0;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[13].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cs0 = SCBR[12].r[CHIP][enq[CHIP]][6];
cs1 = SCBR[12].r[CHIP][enq[CHIP]][4];
cs2 = SCBR[12].r[CHIP][enq[CHIP]][4];
cs3 = SCBR[12].r[CHIP][enq[CHIP]][4];
cex = ((0xaaaa>>(((cs3>>32&1)<<3)|((cs2>>32&1)<<2)|((cs1>>32&1)<<1)|(cs0>>32&1))&1)?2:0) | ((0xaaaa>>(((cs3&1)<<3)|((cs2&1)<<2)|((cs1&1)<<1)|(cs0&1))&1)?1:0);
base = (!(2&1)||INIT0[CHIP]) ? ((2&2)?SCBR[12].r[CHIP][enq[CHIP]][5]:SCM0[13].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[12].r[CHIP][enq[CHIP]][0] : SCM0[13].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (1==1? alud[CHIP][0] : SCBR[12].r[CHIP][enq[CHIP]][0]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[13].enq[CHIP] = 1-SCBR[13].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_inv_x1_14(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit14 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (14 && SCBR[13].enq[CHIP]==SCBR[13].deq[CHIP]) || (14<17 && SCBR[14].enq[CHIP]!=SCBR[14].deq[CHIP])) continue;
SCBR[13].deq[CHIP] = 1-SCBR[13].deq[CHIP];
enq[CHIP] = SCBR[14].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
SCBR[14].r[CHIP][enq[CHIP]][5] = SCBR[13].r[CHIP][enq[CHIP]][5];
}
{
}
{
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[13].r[CHIP][enq[CHIP]][0] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[13].r[CHIP][enq[CHIP]][1], 0);
ex3 = exm(SCBR[13].r[CHIP][enq[CHIP]][3], 0);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^80000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^80000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[13].r[CHIP][enq[CHIP]][7] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[13].r[CHIP][enq[CHIP]][8], 0);
c1 = (ex1>>32&0x00000000ffffffffLL) < (ex2>>32&0x00000000ffffffffLL);
c0 = (ex1    &0x00000000ffffffffLL) < (ex2    &0x00000000ffffffffLL);
ex1_outd = (c1<<32)|c0;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[14].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cs0 = SCBR[13].r[CHIP][enq[CHIP]][6];
cs1 = SCBR[13].r[CHIP][enq[CHIP]][4];
cs2 = SCBR[13].r[CHIP][enq[CHIP]][4];
cs3 = SCBR[13].r[CHIP][enq[CHIP]][4];
cex = ((0xaaaa>>(((cs3>>32&1)<<3)|((cs2>>32&1)<<2)|((cs1>>32&1)<<1)|(cs0>>32&1))&1)?2:0) | ((0xaaaa>>(((cs3&1)<<3)|((cs2&1)<<2)|((cs1&1)<<1)|(cs0&1))&1)?1:0);
base = (!(2&1)||INIT0[CHIP]) ? ((2&2)?SCBR[13].r[CHIP][enq[CHIP]][5]:SCM0[14].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[13].r[CHIP][enq[CHIP]][0] : SCM0[14].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (1==1? alud[CHIP][0] : SCBR[13].r[CHIP][enq[CHIP]][0]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[14].enq[CHIP] = 1-SCBR[14].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_inv_x1_15(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit15 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (15 && SCBR[14].enq[CHIP]==SCBR[14].deq[CHIP]) || (15<17 && SCBR[15].enq[CHIP]!=SCBR[15].deq[CHIP])) continue;
SCBR[14].deq[CHIP] = 1-SCBR[14].deq[CHIP];
enq[CHIP] = SCBR[15].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
SCBR[15].r[CHIP][enq[CHIP]][5] = SCBR[14].r[CHIP][enq[CHIP]][5];
}
{
}
{
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[14].r[CHIP][enq[CHIP]][0] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[14].r[CHIP][enq[CHIP]][1], 0);
ex3 = exm(SCBR[14].r[CHIP][enq[CHIP]][3], 0);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^80000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^80000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[14].r[CHIP][enq[CHIP]][7] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[14].r[CHIP][enq[CHIP]][8], 0);
c1 = (ex1>>32&0x00000000ffffffffLL) < (ex2>>32&0x00000000ffffffffLL);
c0 = (ex1    &0x00000000ffffffffLL) < (ex2    &0x00000000ffffffffLL);
ex1_outd = (c1<<32)|c0;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[15].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cs0 = SCBR[14].r[CHIP][enq[CHIP]][6];
cs1 = SCBR[14].r[CHIP][enq[CHIP]][4];
cs2 = SCBR[14].r[CHIP][enq[CHIP]][4];
cs3 = SCBR[14].r[CHIP][enq[CHIP]][4];
cex = ((0xaaaa>>(((cs3>>32&1)<<3)|((cs2>>32&1)<<2)|((cs1>>32&1)<<1)|(cs0>>32&1))&1)?2:0) | ((0xaaaa>>(((cs3&1)<<3)|((cs2&1)<<2)|((cs1&1)<<1)|(cs0&1))&1)?1:0);
base = (!(2&1)||INIT0[CHIP]) ? ((2&2)?SCBR[14].r[CHIP][enq[CHIP]][5]:SCM0[15].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[14].r[CHIP][enq[CHIP]][0] : SCM0[15].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (1==1? alud[CHIP][0] : SCBR[14].r[CHIP][enq[CHIP]][0]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[15].enq[CHIP] = 1-SCBR[15].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_inv_x1_16(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit16 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (16 && SCBR[15].enq[CHIP]==SCBR[15].deq[CHIP]) || (16<17 && SCBR[16].enq[CHIP]!=SCBR[16].deq[CHIP])) continue;
SCBR[15].deq[CHIP] = 1-SCBR[15].deq[CHIP];
enq[CHIP] = SCBR[16].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
SCBR[16].r[CHIP][enq[CHIP]][5] = SCBR[15].r[CHIP][enq[CHIP]][5];
}
{
}
{
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[15].r[CHIP][enq[CHIP]][0] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[15].r[CHIP][enq[CHIP]][1], 0);
ex3 = exm(SCBR[15].r[CHIP][enq[CHIP]][3], 0);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^80000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^80000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[15].r[CHIP][enq[CHIP]][7] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[15].r[CHIP][enq[CHIP]][8], 0);
c1 = (ex1>>32&0x00000000ffffffffLL) < (ex2>>32&0x00000000ffffffffLL);
c0 = (ex1    &0x00000000ffffffffLL) < (ex2    &0x00000000ffffffffLL);
ex1_outd = (c1<<32)|c0;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[16].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cs0 = SCBR[15].r[CHIP][enq[CHIP]][6];
cs1 = SCBR[15].r[CHIP][enq[CHIP]][4];
cs2 = SCBR[15].r[CHIP][enq[CHIP]][4];
cs3 = SCBR[15].r[CHIP][enq[CHIP]][4];
cex = ((0xaaaa>>(((cs3>>32&1)<<3)|((cs2>>32&1)<<2)|((cs1>>32&1)<<1)|(cs0>>32&1))&1)?2:0) | ((0xaaaa>>(((cs3&1)<<3)|((cs2&1)<<2)|((cs1&1)<<1)|(cs0&1))&1)?1:0);
base = (!(2&1)||INIT0[CHIP]) ? ((2&2)?SCBR[15].r[CHIP][enq[CHIP]][5]:SCM0[16].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[15].r[CHIP][enq[CHIP]][0] : SCM0[16].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (1==1? alud[CHIP][0] : SCBR[15].r[CHIP][enq[CHIP]][0]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[16].enq[CHIP] = 1-SCBR[16].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_inv_x1_17(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit17 */
uLOOP[CHIP]=LOOP1*LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (17 && SCBR[16].enq[CHIP]==SCBR[16].deq[CHIP]) || (17<17 && SCBR[17].enq[CHIP]!=SCBR[17].deq[CHIP])) continue;
SCBR[16].deq[CHIP] = 1-SCBR[16].deq[CHIP];
enq[CHIP] = SCBR[17].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[16].r[CHIP][enq[CHIP]][0] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[16].r[CHIP][enq[CHIP]][1], 0);
ex3 = exm(SCBR[16].r[CHIP][enq[CHIP]][3], 0);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^80000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^80000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cs0 = SCBR[16].r[CHIP][enq[CHIP]][6];
cs1 = SCBR[16].r[CHIP][enq[CHIP]][4];
cs2 = SCBR[16].r[CHIP][enq[CHIP]][4];
cs3 = SCBR[16].r[CHIP][enq[CHIP]][4];
cex = ((0xaaaa>>(((cs3>>32&1)<<3)|((cs2>>32&1)<<2)|((cs1>>32&1)<<1)|(cs0>>32&1))&1)?2:0) | ((0xaaaa>>(((cs3&1)<<3)|((cs2&1)<<2)|((cs1&1)<<1)|(cs0&1))&1)?1:0);
base = (!(2&1)||INIT0[CHIP]) ? ((2&2)?SCBR[16].r[CHIP][enq[CHIP]][5]:SCM0[17].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[16].r[CHIP][enq[CHIP]][0] : SCM0[17].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (1==1? alud[CHIP][0] : SCBR[16].r[CHIP][enq[CHIP]][0]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[17].enq[CHIP] = 1-SCBR[17].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_inv_x2_00(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit0 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (0 && SCBR[63].enq[CHIP]==SCBR[63].deq[CHIP]) || (0<15 && SCBR[0].enq[CHIP]!=SCBR[0].deq[CHIP])) continue;
SCBR[63].deq[CHIP] = 1-SCBR[63].deq[CHIP];
enq[CHIP] = SCBR[0].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!1||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[63].r[CHIP][enq[CHIP]][2] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[63].r[CHIP][enq[CHIP]][3], 0);
t2 = (ex1>>32&0x00000000ffffffffLL)+(ex2>>32&0x00000000ffffffffLL);
t2 &= 0x00000000ffffffffLL;
t0 = (ex1    &0x00000000ffffffffLL)+(ex2    &0x00000000ffffffffLL);
t0 &= 0x00000000ffffffffLL;
ex1_outd = (t2<<32)|(t0);
ex4 = 0==0 ? 0x00000000ffffffffLL : 0==1 ? SCBR[63].r[CHIP][enq[CHIP]][3] : SCBR[63].r[CHIP][enq[CHIP]][0];
ex2_outd = ex1_outd & ex4;
alud[CHIP][1] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!1||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[63].r[CHIP][enq[CHIP]][4] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[63].r[CHIP][enq[CHIP]][5], 0);
ex3 = exm(SCBR[63].r[CHIP][enq[CHIP]][6], 0);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^80000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^80000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[0].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cex = 3;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[63].r[CHIP][enq[CHIP]][0]:SCM0[0].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(0 ? SCBR[63].r[CHIP][enq[CHIP]][0] : SCM0[0].o[CHIP][2], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (1==1? alud[CHIP][2] : SCBR[63].r[CHIP][enq[CHIP]][0]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[0].enq[CHIP] = 1-SCBR[0].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_inv_x2_01(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit1 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (1 && SCBR[0].enq[CHIP]==SCBR[0].deq[CHIP]) || (1<15 && SCBR[1].enq[CHIP]!=SCBR[1].deq[CHIP])) continue;
SCBR[0].deq[CHIP] = 1-SCBR[0].deq[CHIP];
enq[CHIP] = SCBR[1].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!1||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[0].r[CHIP][enq[CHIP]][10] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[0].r[CHIP][enq[CHIP]][0], 0);
ex3 = exm(SCBR[0].r[CHIP][enq[CHIP]][1], 0);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^80000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^80000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[1].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cex = 3;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[0].r[CHIP][enq[CHIP]][0]:SCM0[1].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[0].r[CHIP][enq[CHIP]][0] : SCM0[1].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (1==1? alud[CHIP][0] : SCBR[0].r[CHIP][enq[CHIP]][0]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[1].enq[CHIP] = 1-SCBR[1].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_inv_x2_02(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit2 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (2 && SCBR[1].enq[CHIP]==SCBR[1].deq[CHIP]) || (2<15 && SCBR[2].enq[CHIP]!=SCBR[2].deq[CHIP])) continue;
SCBR[1].deq[CHIP] = 1-SCBR[1].deq[CHIP];
enq[CHIP] = SCBR[2].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!1||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[1].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[1].r[CHIP][enq[CHIP]][0], 0);
ex3 = exm(SCBR[1].r[CHIP][enq[CHIP]][1], 0);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^80000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^80000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[2].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cex = 3;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[1].r[CHIP][enq[CHIP]][0]:SCM0[2].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[1].r[CHIP][enq[CHIP]][0] : SCM0[2].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (1==1? alud[CHIP][0] : SCBR[1].r[CHIP][enq[CHIP]][0]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[2].enq[CHIP] = 1-SCBR[2].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_inv_x2_03(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit3 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (3 && SCBR[2].enq[CHIP]==SCBR[2].deq[CHIP]) || (3<15 && SCBR[3].enq[CHIP]!=SCBR[3].deq[CHIP])) continue;
SCBR[2].deq[CHIP] = 1-SCBR[2].deq[CHIP];
enq[CHIP] = SCBR[3].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!1||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[2].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[2].r[CHIP][enq[CHIP]][0], 0);
ex3 = exm(SCBR[2].r[CHIP][enq[CHIP]][1], 0);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^80000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^80000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[3].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cex = 3;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[2].r[CHIP][enq[CHIP]][0]:SCM0[3].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[2].r[CHIP][enq[CHIP]][0] : SCM0[3].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (1==1? alud[CHIP][0] : SCBR[2].r[CHIP][enq[CHIP]][0]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[3].enq[CHIP] = 1-SCBR[3].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_inv_x2_04(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit4 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (4 && SCBR[3].enq[CHIP]==SCBR[3].deq[CHIP]) || (4<15 && SCBR[4].enq[CHIP]!=SCBR[4].deq[CHIP])) continue;
SCBR[3].deq[CHIP] = 1-SCBR[3].deq[CHIP];
enq[CHIP] = SCBR[4].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!1||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[3].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[3].r[CHIP][enq[CHIP]][0], 0);
ex3 = exm(SCBR[3].r[CHIP][enq[CHIP]][1], 0);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^80000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^80000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[4].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cex = 3;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[3].r[CHIP][enq[CHIP]][0]:SCM0[4].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[3].r[CHIP][enq[CHIP]][0] : SCM0[4].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (1==1? alud[CHIP][0] : SCBR[3].r[CHIP][enq[CHIP]][0]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[4].enq[CHIP] = 1-SCBR[4].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_inv_x2_05(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit5 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (5 && SCBR[4].enq[CHIP]==SCBR[4].deq[CHIP]) || (5<15 && SCBR[5].enq[CHIP]!=SCBR[5].deq[CHIP])) continue;
SCBR[4].deq[CHIP] = 1-SCBR[4].deq[CHIP];
enq[CHIP] = SCBR[5].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!1||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[4].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[4].r[CHIP][enq[CHIP]][0], 0);
ex3 = exm(SCBR[4].r[CHIP][enq[CHIP]][1], 0);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^80000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^80000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[5].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cex = 3;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[4].r[CHIP][enq[CHIP]][0]:SCM0[5].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[4].r[CHIP][enq[CHIP]][0] : SCM0[5].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (1==1? alud[CHIP][0] : SCBR[4].r[CHIP][enq[CHIP]][0]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[5].enq[CHIP] = 1-SCBR[5].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_inv_x2_06(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit6 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (6 && SCBR[5].enq[CHIP]==SCBR[5].deq[CHIP]) || (6<15 && SCBR[6].enq[CHIP]!=SCBR[6].deq[CHIP])) continue;
SCBR[5].deq[CHIP] = 1-SCBR[5].deq[CHIP];
enq[CHIP] = SCBR[6].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!1||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[5].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[5].r[CHIP][enq[CHIP]][0], 0);
ex3 = exm(SCBR[5].r[CHIP][enq[CHIP]][1], 0);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^80000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^80000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[6].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cex = 3;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[5].r[CHIP][enq[CHIP]][0]:SCM0[6].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[5].r[CHIP][enq[CHIP]][0] : SCM0[6].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (1==1? alud[CHIP][0] : SCBR[5].r[CHIP][enq[CHIP]][0]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[6].enq[CHIP] = 1-SCBR[6].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_inv_x2_07(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit7 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (7 && SCBR[6].enq[CHIP]==SCBR[6].deq[CHIP]) || (7<15 && SCBR[7].enq[CHIP]!=SCBR[7].deq[CHIP])) continue;
SCBR[6].deq[CHIP] = 1-SCBR[6].deq[CHIP];
enq[CHIP] = SCBR[7].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!1||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[6].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[6].r[CHIP][enq[CHIP]][0], 0);
ex3 = exm(SCBR[6].r[CHIP][enq[CHIP]][1], 0);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^80000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^80000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[7].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cex = 3;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[6].r[CHIP][enq[CHIP]][0]:SCM0[7].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[6].r[CHIP][enq[CHIP]][0] : SCM0[7].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (1==1? alud[CHIP][0] : SCBR[6].r[CHIP][enq[CHIP]][0]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[7].enq[CHIP] = 1-SCBR[7].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_inv_x2_08(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit8 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (8 && SCBR[7].enq[CHIP]==SCBR[7].deq[CHIP]) || (8<15 && SCBR[8].enq[CHIP]!=SCBR[8].deq[CHIP])) continue;
SCBR[7].deq[CHIP] = 1-SCBR[7].deq[CHIP];
enq[CHIP] = SCBR[8].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!1||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[7].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[7].r[CHIP][enq[CHIP]][0], 0);
ex3 = exm(SCBR[7].r[CHIP][enq[CHIP]][1], 0);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^80000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^80000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[8].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cex = 3;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[7].r[CHIP][enq[CHIP]][0]:SCM0[8].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[7].r[CHIP][enq[CHIP]][0] : SCM0[8].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (1==1? alud[CHIP][0] : SCBR[7].r[CHIP][enq[CHIP]][0]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[8].enq[CHIP] = 1-SCBR[8].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_inv_x2_09(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit9 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (9 && SCBR[8].enq[CHIP]==SCBR[8].deq[CHIP]) || (9<15 && SCBR[9].enq[CHIP]!=SCBR[9].deq[CHIP])) continue;
SCBR[8].deq[CHIP] = 1-SCBR[8].deq[CHIP];
enq[CHIP] = SCBR[9].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!1||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[8].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[8].r[CHIP][enq[CHIP]][0], 0);
ex3 = exm(SCBR[8].r[CHIP][enq[CHIP]][1], 0);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^80000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^80000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[9].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cex = 3;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[8].r[CHIP][enq[CHIP]][0]:SCM0[9].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[8].r[CHIP][enq[CHIP]][0] : SCM0[9].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (1==1? alud[CHIP][0] : SCBR[8].r[CHIP][enq[CHIP]][0]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[9].enq[CHIP] = 1-SCBR[9].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_inv_x2_10(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit10 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (10 && SCBR[9].enq[CHIP]==SCBR[9].deq[CHIP]) || (10<15 && SCBR[10].enq[CHIP]!=SCBR[10].deq[CHIP])) continue;
SCBR[9].deq[CHIP] = 1-SCBR[9].deq[CHIP];
enq[CHIP] = SCBR[10].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!1||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[9].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[9].r[CHIP][enq[CHIP]][0], 0);
ex3 = exm(SCBR[9].r[CHIP][enq[CHIP]][1], 0);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^80000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^80000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[10].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cex = 3;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[9].r[CHIP][enq[CHIP]][0]:SCM0[10].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[9].r[CHIP][enq[CHIP]][0] : SCM0[10].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (1==1? alud[CHIP][0] : SCBR[9].r[CHIP][enq[CHIP]][0]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[10].enq[CHIP] = 1-SCBR[10].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_inv_x2_11(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit11 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (11 && SCBR[10].enq[CHIP]==SCBR[10].deq[CHIP]) || (11<15 && SCBR[11].enq[CHIP]!=SCBR[11].deq[CHIP])) continue;
SCBR[10].deq[CHIP] = 1-SCBR[10].deq[CHIP];
enq[CHIP] = SCBR[11].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!1||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[10].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[10].r[CHIP][enq[CHIP]][0], 0);
ex3 = exm(SCBR[10].r[CHIP][enq[CHIP]][1], 0);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^80000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^80000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[11].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cex = 3;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[10].r[CHIP][enq[CHIP]][0]:SCM0[11].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[10].r[CHIP][enq[CHIP]][0] : SCM0[11].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (1==1? alud[CHIP][0] : SCBR[10].r[CHIP][enq[CHIP]][0]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[11].enq[CHIP] = 1-SCBR[11].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_inv_x2_12(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit12 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (12 && SCBR[11].enq[CHIP]==SCBR[11].deq[CHIP]) || (12<15 && SCBR[12].enq[CHIP]!=SCBR[12].deq[CHIP])) continue;
SCBR[11].deq[CHIP] = 1-SCBR[11].deq[CHIP];
enq[CHIP] = SCBR[12].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!1||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[11].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[11].r[CHIP][enq[CHIP]][0], 0);
ex3 = exm(SCBR[11].r[CHIP][enq[CHIP]][1], 0);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^80000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^80000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[12].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cex = 3;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[11].r[CHIP][enq[CHIP]][0]:SCM0[12].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[11].r[CHIP][enq[CHIP]][0] : SCM0[12].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (1==1? alud[CHIP][0] : SCBR[11].r[CHIP][enq[CHIP]][0]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[12].enq[CHIP] = 1-SCBR[12].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_inv_x2_13(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit13 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (13 && SCBR[12].enq[CHIP]==SCBR[12].deq[CHIP]) || (13<15 && SCBR[13].enq[CHIP]!=SCBR[13].deq[CHIP])) continue;
SCBR[12].deq[CHIP] = 1-SCBR[12].deq[CHIP];
enq[CHIP] = SCBR[13].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!1||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[12].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[12].r[CHIP][enq[CHIP]][0], 0);
ex3 = exm(SCBR[12].r[CHIP][enq[CHIP]][1], 0);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^80000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^80000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[13].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cex = 3;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[12].r[CHIP][enq[CHIP]][0]:SCM0[13].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[12].r[CHIP][enq[CHIP]][0] : SCM0[13].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (1==1? alud[CHIP][0] : SCBR[12].r[CHIP][enq[CHIP]][0]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[13].enq[CHIP] = 1-SCBR[13].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_inv_x2_14(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit14 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (14 && SCBR[13].enq[CHIP]==SCBR[13].deq[CHIP]) || (14<15 && SCBR[14].enq[CHIP]!=SCBR[14].deq[CHIP])) continue;
SCBR[13].deq[CHIP] = 1-SCBR[13].deq[CHIP];
enq[CHIP] = SCBR[14].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!1||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[13].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[13].r[CHIP][enq[CHIP]][0], 0);
ex3 = exm(SCBR[13].r[CHIP][enq[CHIP]][1], 0);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^80000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^80000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[14].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cex = 3;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[13].r[CHIP][enq[CHIP]][0]:SCM0[14].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[13].r[CHIP][enq[CHIP]][0] : SCM0[14].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (1==1? alud[CHIP][0] : SCBR[13].r[CHIP][enq[CHIP]][0]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[14].enq[CHIP] = 1-SCBR[14].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_inv_x2_15(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit15 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (15 && SCBR[14].enq[CHIP]==SCBR[14].deq[CHIP]) || (15<15 && SCBR[15].enq[CHIP]!=SCBR[15].deq[CHIP])) continue;
SCBR[14].deq[CHIP] = 1-SCBR[14].deq[CHIP];
enq[CHIP] = SCBR[15].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!1||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[14].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[14].r[CHIP][enq[CHIP]][0], 0);
ex3 = exm(SCBR[14].r[CHIP][enq[CHIP]][1], 0);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^80000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^80000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cex = 3;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[14].r[CHIP][enq[CHIP]][0]:SCM0[15].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[14].r[CHIP][enq[CHIP]][0] : SCM0[15].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (1==1? alud[CHIP][0] : SCBR[14].r[CHIP][enq[CHIP]][0]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[15].enq[CHIP] = 1-SCBR[15].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_inv_x3_00(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit0 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (0 && SCBR[63].enq[CHIP]==SCBR[63].deq[CHIP]) || (0<15 && SCBR[0].enq[CHIP]!=SCBR[0].deq[CHIP])) continue;
SCBR[63].deq[CHIP] = 1-SCBR[63].deq[CHIP];
enq[CHIP] = SCBR[0].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!1||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[63].r[CHIP][enq[CHIP]][2] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[63].r[CHIP][enq[CHIP]][3], 0);
t2 = (ex1>>32&0x00000000ffffffffLL)+(ex2>>32&0x00000000ffffffffLL);
t2 &= 0x00000000ffffffffLL;
t0 = (ex1    &0x00000000ffffffffLL)+(ex2    &0x00000000ffffffffLL);
t0 &= 0x00000000ffffffffLL;
ex1_outd = (t2<<32)|(t0);
ex4 = 0==0 ? 0x00000000ffffffffLL : 0==1 ? SCBR[63].r[CHIP][enq[CHIP]][3] : SCBR[63].r[CHIP][enq[CHIP]][0];
ex2_outd = ex1_outd & ex4;
alud[CHIP][1] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!1||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[63].r[CHIP][enq[CHIP]][4] : alud[CHIP][2], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[63].r[CHIP][enq[CHIP]][5], 0);
ex3 = exm(SCBR[63].r[CHIP][enq[CHIP]][6], 0);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^80000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^80000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[0].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cex = 3;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[63].r[CHIP][enq[CHIP]][0]:SCM0[0].b[CHIP][2]) : awoo0[CHIP][2];
offs = eam(0 ? SCBR[63].r[CHIP][enq[CHIP]][0] : SCM0[0].o[CHIP][2], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
awoo0[CHIP][2] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][2]);
adr = (Ull)(awoo0[CHIP][2] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (1==1? alud[CHIP][2] : SCBR[63].r[CHIP][enq[CHIP]][0]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[0].enq[CHIP] = 1-SCBR[0].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_inv_x3_01(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit1 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (1 && SCBR[0].enq[CHIP]==SCBR[0].deq[CHIP]) || (1<15 && SCBR[1].enq[CHIP]!=SCBR[1].deq[CHIP])) continue;
SCBR[0].deq[CHIP] = 1-SCBR[0].deq[CHIP];
enq[CHIP] = SCBR[1].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!1||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[0].r[CHIP][enq[CHIP]][10] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[0].r[CHIP][enq[CHIP]][0], 0);
ex3 = exm(SCBR[0].r[CHIP][enq[CHIP]][1], 0);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^80000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^80000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[1].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cex = 3;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[0].r[CHIP][enq[CHIP]][0]:SCM0[1].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[0].r[CHIP][enq[CHIP]][0] : SCM0[1].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (1==1? alud[CHIP][0] : SCBR[0].r[CHIP][enq[CHIP]][0]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[1].enq[CHIP] = 1-SCBR[1].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_inv_x3_02(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit2 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (2 && SCBR[1].enq[CHIP]==SCBR[1].deq[CHIP]) || (2<15 && SCBR[2].enq[CHIP]!=SCBR[2].deq[CHIP])) continue;
SCBR[1].deq[CHIP] = 1-SCBR[1].deq[CHIP];
enq[CHIP] = SCBR[2].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!1||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[1].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[1].r[CHIP][enq[CHIP]][0], 0);
ex3 = exm(SCBR[1].r[CHIP][enq[CHIP]][1], 0);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^80000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^80000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[2].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cex = 3;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[1].r[CHIP][enq[CHIP]][0]:SCM0[2].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[1].r[CHIP][enq[CHIP]][0] : SCM0[2].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (1==1? alud[CHIP][0] : SCBR[1].r[CHIP][enq[CHIP]][0]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[2].enq[CHIP] = 1-SCBR[2].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_inv_x3_03(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit3 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (3 && SCBR[2].enq[CHIP]==SCBR[2].deq[CHIP]) || (3<15 && SCBR[3].enq[CHIP]!=SCBR[3].deq[CHIP])) continue;
SCBR[2].deq[CHIP] = 1-SCBR[2].deq[CHIP];
enq[CHIP] = SCBR[3].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!1||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[2].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[2].r[CHIP][enq[CHIP]][0], 0);
ex3 = exm(SCBR[2].r[CHIP][enq[CHIP]][1], 0);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^80000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^80000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[3].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cex = 3;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[2].r[CHIP][enq[CHIP]][0]:SCM0[3].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[2].r[CHIP][enq[CHIP]][0] : SCM0[3].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (1==1? alud[CHIP][0] : SCBR[2].r[CHIP][enq[CHIP]][0]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[3].enq[CHIP] = 1-SCBR[3].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_inv_x3_04(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit4 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (4 && SCBR[3].enq[CHIP]==SCBR[3].deq[CHIP]) || (4<15 && SCBR[4].enq[CHIP]!=SCBR[4].deq[CHIP])) continue;
SCBR[3].deq[CHIP] = 1-SCBR[3].deq[CHIP];
enq[CHIP] = SCBR[4].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!1||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[3].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[3].r[CHIP][enq[CHIP]][0], 0);
ex3 = exm(SCBR[3].r[CHIP][enq[CHIP]][1], 0);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^80000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^80000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[4].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cex = 3;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[3].r[CHIP][enq[CHIP]][0]:SCM0[4].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[3].r[CHIP][enq[CHIP]][0] : SCM0[4].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (1==1? alud[CHIP][0] : SCBR[3].r[CHIP][enq[CHIP]][0]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[4].enq[CHIP] = 1-SCBR[4].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_inv_x3_05(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit5 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (5 && SCBR[4].enq[CHIP]==SCBR[4].deq[CHIP]) || (5<15 && SCBR[5].enq[CHIP]!=SCBR[5].deq[CHIP])) continue;
SCBR[4].deq[CHIP] = 1-SCBR[4].deq[CHIP];
enq[CHIP] = SCBR[5].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!1||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[4].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[4].r[CHIP][enq[CHIP]][0], 0);
ex3 = exm(SCBR[4].r[CHIP][enq[CHIP]][1], 0);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^80000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^80000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[5].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cex = 3;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[4].r[CHIP][enq[CHIP]][0]:SCM0[5].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[4].r[CHIP][enq[CHIP]][0] : SCM0[5].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (1==1? alud[CHIP][0] : SCBR[4].r[CHIP][enq[CHIP]][0]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[5].enq[CHIP] = 1-SCBR[5].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_inv_x3_06(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit6 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (6 && SCBR[5].enq[CHIP]==SCBR[5].deq[CHIP]) || (6<15 && SCBR[6].enq[CHIP]!=SCBR[6].deq[CHIP])) continue;
SCBR[5].deq[CHIP] = 1-SCBR[5].deq[CHIP];
enq[CHIP] = SCBR[6].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!1||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[5].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[5].r[CHIP][enq[CHIP]][0], 0);
ex3 = exm(SCBR[5].r[CHIP][enq[CHIP]][1], 0);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^80000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^80000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[6].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cex = 3;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[5].r[CHIP][enq[CHIP]][0]:SCM0[6].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[5].r[CHIP][enq[CHIP]][0] : SCM0[6].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (1==1? alud[CHIP][0] : SCBR[5].r[CHIP][enq[CHIP]][0]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[6].enq[CHIP] = 1-SCBR[6].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_inv_x3_07(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit7 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (7 && SCBR[6].enq[CHIP]==SCBR[6].deq[CHIP]) || (7<15 && SCBR[7].enq[CHIP]!=SCBR[7].deq[CHIP])) continue;
SCBR[6].deq[CHIP] = 1-SCBR[6].deq[CHIP];
enq[CHIP] = SCBR[7].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!1||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[6].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[6].r[CHIP][enq[CHIP]][0], 0);
ex3 = exm(SCBR[6].r[CHIP][enq[CHIP]][1], 0);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^80000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^80000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[7].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cex = 3;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[6].r[CHIP][enq[CHIP]][0]:SCM0[7].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[6].r[CHIP][enq[CHIP]][0] : SCM0[7].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (1==1? alud[CHIP][0] : SCBR[6].r[CHIP][enq[CHIP]][0]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[7].enq[CHIP] = 1-SCBR[7].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_inv_x3_08(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit8 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (8 && SCBR[7].enq[CHIP]==SCBR[7].deq[CHIP]) || (8<15 && SCBR[8].enq[CHIP]!=SCBR[8].deq[CHIP])) continue;
SCBR[7].deq[CHIP] = 1-SCBR[7].deq[CHIP];
enq[CHIP] = SCBR[8].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!1||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[7].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[7].r[CHIP][enq[CHIP]][0], 0);
ex3 = exm(SCBR[7].r[CHIP][enq[CHIP]][1], 0);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^80000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^80000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[8].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cex = 3;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[7].r[CHIP][enq[CHIP]][0]:SCM0[8].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[7].r[CHIP][enq[CHIP]][0] : SCM0[8].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (1==1? alud[CHIP][0] : SCBR[7].r[CHIP][enq[CHIP]][0]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[8].enq[CHIP] = 1-SCBR[8].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_inv_x3_09(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit9 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (9 && SCBR[8].enq[CHIP]==SCBR[8].deq[CHIP]) || (9<15 && SCBR[9].enq[CHIP]!=SCBR[9].deq[CHIP])) continue;
SCBR[8].deq[CHIP] = 1-SCBR[8].deq[CHIP];
enq[CHIP] = SCBR[9].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!1||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[8].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[8].r[CHIP][enq[CHIP]][0], 0);
ex3 = exm(SCBR[8].r[CHIP][enq[CHIP]][1], 0);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^80000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^80000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[9].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cex = 3;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[8].r[CHIP][enq[CHIP]][0]:SCM0[9].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[8].r[CHIP][enq[CHIP]][0] : SCM0[9].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (1==1? alud[CHIP][0] : SCBR[8].r[CHIP][enq[CHIP]][0]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[9].enq[CHIP] = 1-SCBR[9].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_inv_x3_10(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit10 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (10 && SCBR[9].enq[CHIP]==SCBR[9].deq[CHIP]) || (10<15 && SCBR[10].enq[CHIP]!=SCBR[10].deq[CHIP])) continue;
SCBR[9].deq[CHIP] = 1-SCBR[9].deq[CHIP];
enq[CHIP] = SCBR[10].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!1||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[9].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[9].r[CHIP][enq[CHIP]][0], 0);
ex3 = exm(SCBR[9].r[CHIP][enq[CHIP]][1], 0);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^80000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^80000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[10].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cex = 3;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[9].r[CHIP][enq[CHIP]][0]:SCM0[10].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[9].r[CHIP][enq[CHIP]][0] : SCM0[10].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (1==1? alud[CHIP][0] : SCBR[9].r[CHIP][enq[CHIP]][0]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[10].enq[CHIP] = 1-SCBR[10].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_inv_x3_11(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit11 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (11 && SCBR[10].enq[CHIP]==SCBR[10].deq[CHIP]) || (11<15 && SCBR[11].enq[CHIP]!=SCBR[11].deq[CHIP])) continue;
SCBR[10].deq[CHIP] = 1-SCBR[10].deq[CHIP];
enq[CHIP] = SCBR[11].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!1||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[10].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[10].r[CHIP][enq[CHIP]][0], 0);
ex3 = exm(SCBR[10].r[CHIP][enq[CHIP]][1], 0);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^80000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^80000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[11].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cex = 3;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[10].r[CHIP][enq[CHIP]][0]:SCM0[11].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[10].r[CHIP][enq[CHIP]][0] : SCM0[11].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (1==1? alud[CHIP][0] : SCBR[10].r[CHIP][enq[CHIP]][0]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[11].enq[CHIP] = 1-SCBR[11].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_inv_x3_12(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit12 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (12 && SCBR[11].enq[CHIP]==SCBR[11].deq[CHIP]) || (12<15 && SCBR[12].enq[CHIP]!=SCBR[12].deq[CHIP])) continue;
SCBR[11].deq[CHIP] = 1-SCBR[11].deq[CHIP];
enq[CHIP] = SCBR[12].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!1||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[11].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[11].r[CHIP][enq[CHIP]][0], 0);
ex3 = exm(SCBR[11].r[CHIP][enq[CHIP]][1], 0);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^80000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^80000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[12].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cex = 3;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[11].r[CHIP][enq[CHIP]][0]:SCM0[12].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[11].r[CHIP][enq[CHIP]][0] : SCM0[12].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (1==1? alud[CHIP][0] : SCBR[11].r[CHIP][enq[CHIP]][0]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[12].enq[CHIP] = 1-SCBR[12].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_inv_x3_13(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit13 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (13 && SCBR[12].enq[CHIP]==SCBR[12].deq[CHIP]) || (13<15 && SCBR[13].enq[CHIP]!=SCBR[13].deq[CHIP])) continue;
SCBR[12].deq[CHIP] = 1-SCBR[12].deq[CHIP];
enq[CHIP] = SCBR[13].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!1||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[12].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[12].r[CHIP][enq[CHIP]][0], 0);
ex3 = exm(SCBR[12].r[CHIP][enq[CHIP]][1], 0);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^80000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^80000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[13].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cex = 3;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[12].r[CHIP][enq[CHIP]][0]:SCM0[13].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[12].r[CHIP][enq[CHIP]][0] : SCM0[13].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (1==1? alud[CHIP][0] : SCBR[12].r[CHIP][enq[CHIP]][0]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[13].enq[CHIP] = 1-SCBR[13].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_inv_x3_14(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit14 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (14 && SCBR[13].enq[CHIP]==SCBR[13].deq[CHIP]) || (14<15 && SCBR[14].enq[CHIP]!=SCBR[14].deq[CHIP])) continue;
SCBR[13].deq[CHIP] = 1-SCBR[13].deq[CHIP];
enq[CHIP] = SCBR[14].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!1||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[13].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[13].r[CHIP][enq[CHIP]][0], 0);
ex3 = exm(SCBR[13].r[CHIP][enq[CHIP]][1], 0);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^80000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^80000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[14].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cex = 3;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[13].r[CHIP][enq[CHIP]][0]:SCM0[14].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[13].r[CHIP][enq[CHIP]][0] : SCM0[14].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (1==1? alud[CHIP][0] : SCBR[13].r[CHIP][enq[CHIP]][0]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[14].enq[CHIP] = 1-SCBR[14].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_inv_x3_15(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<1; CHIP++) { /* unit15 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<1; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==1) break;
for (CHIP=0; CHIP<1; CHIP++) {
if (uLOOP[CHIP]==0 || (15 && SCBR[14].enq[CHIP]==SCBR[14].deq[CHIP]) || (15<15 && SCBR[15].enq[CHIP]!=SCBR[15].deq[CHIP])) continue;
SCBR[14].deq[CHIP] = 1-SCBR[14].deq[CHIP];
enq[CHIP] = SCBR[15].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
}
{
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ Ull base, offs, adr, mexdist, load64;
  static int emax6_unaligned_load_valid;
  static Ull emax6_unaligned_load_high;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!1||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[14].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[14].r[CHIP][enq[CHIP]][0], 0);
ex3 = exm(SCBR[14].r[CHIP][enq[CHIP]][1], 0);
f1.i = (Uint)(ex1>>32);
f2.i = (Uint)(ex2>>32)^80000000;
f3.i = (Uint)(ex3>>32);
f0.f = f1.f + (f2.f * f3.f);
t2 = f0.i;
f1.i = (Uint)(ex1);
f2.i = (Uint)(ex2)^80000000;
f3.i = (Uint)(ex3);
f0.f = f1.f + (f2.f * f3.f);
t0 = f0.i;
ex1_outd = (t2<<32)|(t0);
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cex = 3;
base = (!(0&1)||INIT0[CHIP]) ? ((0&2)?SCBR[14].r[CHIP][enq[CHIP]][0]:SCM0[15].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[14].r[CHIP][enq[CHIP]][0] : SCM0[15].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 0;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0]);
adr = (Ull)(awoo0[CHIP][0] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (1==1? alud[CHIP][0] : SCBR[14].r[CHIP][enq[CHIP]][0]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[15].enq[CHIP] = 1-SCBR[15].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
