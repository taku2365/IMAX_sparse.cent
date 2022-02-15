/* EMAXSC start */
void emax6sc_pth_gdepth_00(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit0 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (0 && SCBR[63].enq[CHIP]==SCBR[63].deq[CHIP]) || (0<55 && SCBR[0].enq[CHIP]!=SCBR[0].deq[CHIP])) continue;
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
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[0].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
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
SCBR[0].enq[CHIP] = 1-SCBR[0].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_gdepth_01(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit1 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (1 && SCBR[0].enq[CHIP]==SCBR[0].deq[CHIP]) || (1<55 && SCBR[1].enq[CHIP]!=SCBR[1].deq[CHIP])) continue;
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
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[0].r[CHIP][enq[CHIP]][0] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[0].r[CHIP][enq[CHIP]][6], 0);
t2 = (ex1>>32&0x00000000ffffffffLL)-(ex2>>32&0x00000000ffffffffLL);
t2 &= 0x00000000ffffffffLL;
t0 = (ex1    &0x00000000ffffffffLL)-(ex2    &0x00000000ffffffffLL);
t0 &= 0x00000000ffffffffLL;
ex1_outd = (t2<<32)|(t0);
ex4 = 0==0 ? 0x000000000000000fLL : 0==1 ? SCBR[0].r[CHIP][enq[CHIP]][6] : SCBR[0].r[CHIP][enq[CHIP]][0];
ex2_outd = ex1_outd & ex4;
alud[CHIP][0] = ex2_outd;
SCBR[1].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[0].r[CHIP][enq[CHIP]][6] : alud[CHIP][1], 0);
ex1_outd = ex1;
ex4 = 0==0 ? 0x0000000000000000LL : 0==1 ? SCBR[0].r[CHIP][enq[CHIP]][0] : SCBR[0].r[CHIP][enq[CHIP]][0];
ex2_outd = ex1_outd | ex4;
ex5 = 0==0 ? 0x00000004 : SCBR[0].r[CHIP][enq[CHIP]][0];
t1 = (Ull)(ex2_outd>>ex5&0xffffffff00000000LL);
t0 = (Ull)(ex2_outd     &0x00000000ffffffffLL)>>ex5;
alud[CHIP][1] = t1 | t0;
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
void emax6sc_pth_gdepth_02(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit2 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (2 && SCBR[1].enq[CHIP]==SCBR[1].deq[CHIP]) || (2<55 && SCBR[2].enq[CHIP]!=SCBR[2].deq[CHIP])) continue;
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
ex4 = 0==0 ? 0x0000000000000000LL : 0==1 ? SCBR[1].r[CHIP][enq[CHIP]][0] : SCBR[1].r[CHIP][enq[CHIP]][0];
ex2_outd = ex1_outd | ex4;
ex5 = 0==0 ? 0x00000004 : SCBR[1].r[CHIP][enq[CHIP]][0];
t1 = (Ull)(ex2_outd>>ex5&0xffffffff00000000LL);
t0 = (Ull)(ex2_outd     &0x00000000ffffffffLL)>>ex5;
alud[CHIP][0] = t1 | t0;
SCBR[2].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[2].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
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
SCBR[2].enq[CHIP] = 1-SCBR[2].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_gdepth_03(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit3 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (3 && SCBR[2].enq[CHIP]==SCBR[2].deq[CHIP]) || (3<55 && SCBR[3].enq[CHIP]!=SCBR[3].deq[CHIP])) continue;
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
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[2].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[2].r[CHIP][enq[CHIP]][6], 0);
ex3 = exm(SCBR[2].r[CHIP][enq[CHIP]][0], 0);
t2 = (ex1>>32&0x00000000ffffffffLL)+((ex2>>32&0x00000000ffffffffLL)+(ex3>>32&0x00000000ffffffffLL));
t2 &= 0x00000000ffffffffLL;
t0 = (ex1    &0x00000000ffffffffLL)+((ex2    &0x00000000ffffffffLL)+(ex3    &0x00000000ffffffffLL));
t0 &= 0x00000000ffffffffLL;
ex1_outd = (t2<<32)|(t0);
ex4 = 0==0 ? 0x0000000000000000LL : 0==1 ? SCBR[2].r[CHIP][enq[CHIP]][6] : SCBR[2].r[CHIP][enq[CHIP]][0];
ex2_outd = ex1_outd | ex4;
ex5 = 0==0 ? 0x00000002 : SCBR[2].r[CHIP][enq[CHIP]][0];
t1 = (Ull)(ex2_outd     &0xffffffff00000000LL)<<ex5;
t0 = (Ull)(ex2_outd<<ex5&0x00000000ffffffffLL);
alud[CHIP][0] = t1 | t0;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[2].r[CHIP][enq[CHIP]][2] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[2].r[CHIP][enq[CHIP]][6], 0);
t2 = (ex1>>32&0x00000000ffffffffLL)+(ex2>>32&0x00000000ffffffffLL);
t2 &= 0x00000000ffffffffLL;
t0 = (ex1    &0x00000000ffffffffLL)+(ex2    &0x00000000ffffffffLL);
t0 &= 0x00000000ffffffffLL;
ex1_outd = (t2<<32)|(t0);
ex4 = 0==0 ? 0x0000000000000000LL : 0==1 ? SCBR[2].r[CHIP][enq[CHIP]][6] : SCBR[2].r[CHIP][enq[CHIP]][0];
ex2_outd = ex1_outd | ex4;
alud[CHIP][1] = ex2_outd;
SCBR[3].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[3].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[3].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
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
void emax6sc_pth_gdepth_04(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit4 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (4 && SCBR[3].enq[CHIP]==SCBR[3].deq[CHIP]) || (4<55 && SCBR[4].enq[CHIP]!=SCBR[4].deq[CHIP])) continue;
SCBR[3].deq[CHIP] = 1-SCBR[3].deq[CHIP];
enq[CHIP] = SCBR[4].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
SCBR[4].r[CHIP][enq[CHIP]][8] = SCBR[3].r[CHIP][enq[CHIP]][6];
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
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[4].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[4].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[4].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[4].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
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
void emax6sc_pth_gdepth_05(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit5 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (5 && SCBR[4].enq[CHIP]==SCBR[4].deq[CHIP]) || (5<55 && SCBR[5].enq[CHIP]!=SCBR[5].deq[CHIP])) continue;
SCBR[4].deq[CHIP] = 1-SCBR[4].deq[CHIP];
enq[CHIP] = SCBR[5].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
SCBR[5].r[CHIP][enq[CHIP]][11] = SCBR[4].r[CHIP][enq[CHIP]][8];
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
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[5].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[5].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[5].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[5].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
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
void emax6sc_pth_gdepth_06(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit6 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (6 && SCBR[5].enq[CHIP]==SCBR[5].deq[CHIP]) || (6<55 && SCBR[6].enq[CHIP]!=SCBR[6].deq[CHIP])) continue;
SCBR[5].deq[CHIP] = 1-SCBR[5].deq[CHIP];
enq[CHIP] = SCBR[6].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
SCBR[6].r[CHIP][enq[CHIP]][8] = SCBR[5].r[CHIP][enq[CHIP]][11];
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
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[6].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[6].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[6].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[6].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
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
void emax6sc_pth_gdepth_07(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit7 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (7 && SCBR[6].enq[CHIP]==SCBR[6].deq[CHIP]) || (7<55 && SCBR[7].enq[CHIP]!=SCBR[7].deq[CHIP])) continue;
SCBR[6].deq[CHIP] = 1-SCBR[6].deq[CHIP];
enq[CHIP] = SCBR[7].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
SCBR[7].r[CHIP][enq[CHIP]][8] = SCBR[6].r[CHIP][enq[CHIP]][8];
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
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[7].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[7].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[7].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[7].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
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
void emax6sc_pth_gdepth_08(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit8 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (8 && SCBR[7].enq[CHIP]==SCBR[7].deq[CHIP]) || (8<55 && SCBR[8].enq[CHIP]!=SCBR[8].deq[CHIP])) continue;
SCBR[7].deq[CHIP] = 1-SCBR[7].deq[CHIP];
enq[CHIP] = SCBR[8].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
SCBR[8].r[CHIP][enq[CHIP]][11] = SCBR[7].r[CHIP][enq[CHIP]][8];
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
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[8].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[8].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[8].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[8].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
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
void emax6sc_pth_gdepth_09(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit9 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (9 && SCBR[8].enq[CHIP]==SCBR[8].deq[CHIP]) || (9<55 && SCBR[9].enq[CHIP]!=SCBR[9].deq[CHIP])) continue;
SCBR[8].deq[CHIP] = 1-SCBR[8].deq[CHIP];
enq[CHIP] = SCBR[9].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
SCBR[9].r[CHIP][enq[CHIP]][8] = SCBR[8].r[CHIP][enq[CHIP]][11];
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
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[9].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[9].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[9].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[9].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
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
void emax6sc_pth_gdepth_10(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit10 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (10 && SCBR[9].enq[CHIP]==SCBR[9].deq[CHIP]) || (10<55 && SCBR[10].enq[CHIP]!=SCBR[10].deq[CHIP])) continue;
SCBR[9].deq[CHIP] = 1-SCBR[9].deq[CHIP];
enq[CHIP] = SCBR[10].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
SCBR[10].r[CHIP][enq[CHIP]][8] = SCBR[9].r[CHIP][enq[CHIP]][8];
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
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[10].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[10].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[10].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[10].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
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
void emax6sc_pth_gdepth_11(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit11 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (11 && SCBR[10].enq[CHIP]==SCBR[10].deq[CHIP]) || (11<55 && SCBR[11].enq[CHIP]!=SCBR[11].deq[CHIP])) continue;
SCBR[10].deq[CHIP] = 1-SCBR[10].deq[CHIP];
enq[CHIP] = SCBR[11].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
SCBR[11].r[CHIP][enq[CHIP]][5] = SCBR[10].r[CHIP][enq[CHIP]][8];
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
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[11].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[11].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[11].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[11].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
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
void emax6sc_pth_gdepth_12(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit12 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (12 && SCBR[11].enq[CHIP]==SCBR[11].deq[CHIP]) || (12<55 && SCBR[12].enq[CHIP]!=SCBR[12].deq[CHIP])) continue;
SCBR[11].deq[CHIP] = 1-SCBR[11].deq[CHIP];
enq[CHIP] = SCBR[12].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[12].r[CHIP][enq[CHIP]][0] = SCBR[11].r[CHIP][enq[CHIP]][5];
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
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[12].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[12].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[12].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
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
SCBR[12].enq[CHIP] = 1-SCBR[12].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_gdepth_13(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit13 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (13 && SCBR[12].enq[CHIP]==SCBR[12].deq[CHIP]) || (13<55 && SCBR[13].enq[CHIP]!=SCBR[13].deq[CHIP])) continue;
SCBR[12].deq[CHIP] = 1-SCBR[12].deq[CHIP];
enq[CHIP] = SCBR[13].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[13].r[CHIP][enq[CHIP]][0] = SCBR[12].r[CHIP][enq[CHIP]][10];
SCBR[13].r[CHIP][enq[CHIP]][1] = SCBR[12].r[CHIP][enq[CHIP]][0];
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
void emax6sc_pth_gdepth_14(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit14 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (14 && SCBR[13].enq[CHIP]==SCBR[13].deq[CHIP]) || (14<55 && SCBR[14].enq[CHIP]!=SCBR[14].deq[CHIP])) continue;
SCBR[13].deq[CHIP] = 1-SCBR[13].deq[CHIP];
enq[CHIP] = SCBR[14].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
SCBR[14].r[CHIP][enq[CHIP]][5] = SCBR[13].r[CHIP][enq[CHIP]][1];
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
void emax6sc_pth_gdepth_15(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit15 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (15 && SCBR[14].enq[CHIP]==SCBR[14].deq[CHIP]) || (15<55 && SCBR[15].enq[CHIP]!=SCBR[15].deq[CHIP])) continue;
SCBR[14].deq[CHIP] = 1-SCBR[14].deq[CHIP];
enq[CHIP] = SCBR[15].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[15].r[CHIP][enq[CHIP]][1] = SCBR[14].r[CHIP][enq[CHIP]][2];
SCBR[15].r[CHIP][enq[CHIP]][3] = SCBR[14].r[CHIP][enq[CHIP]][5];
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
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[14].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[14].r[CHIP][enq[CHIP]][0], 0);
c1 = (ex1>>32&0x00000000ffffffffLL) < (ex2>>32&0x00000000ffffffffLL);
c0 = (ex1    &0x00000000ffffffffLL) < (ex2    &0x00000000ffffffffLL);
ex1_outd = (c1<<32)|c0;
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[15].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[14].r[CHIP][enq[CHIP]][0] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[14].r[CHIP][enq[CHIP]][1], 0);
c1 = (ex1>>32&0x00000000ffffffffLL) > (ex2>>32&0x00000000ffffffffLL);
c0 = (ex1    &0x00000000ffffffffLL) > (ex2    &0x00000000ffffffffLL);
ex1_outd = (c1<<32)|c0;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[15].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[14].r[CHIP][enq[CHIP]][3] : alud[CHIP][2], 0);
ex1_outd = ex1;
ex4 = 1==0 ? 0x0000000000000000LL : 1==1 ? SCBR[14].r[CHIP][enq[CHIP]][4] : SCBR[14].r[CHIP][enq[CHIP]][0];
ex2_outd = ex1_outd | ex4;
alud[CHIP][2] = ex2_outd;
SCBR[15].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
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
SCBR[15].enq[CHIP] = 1-SCBR[15].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_gdepth_16(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit16 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (16 && SCBR[15].enq[CHIP]==SCBR[15].deq[CHIP]) || (16<55 && SCBR[16].enq[CHIP]!=SCBR[16].deq[CHIP])) continue;
SCBR[15].deq[CHIP] = 1-SCBR[15].deq[CHIP];
enq[CHIP] = SCBR[16].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
SCBR[16].r[CHIP][enq[CHIP]][8] = SCBR[15].r[CHIP][enq[CHIP]][3];
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
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[15].r[CHIP][enq[CHIP]][3] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[15].r[CHIP][enq[CHIP]][4], 0);
t2 = (ex1>>32&0x00000000ffffffffLL)+(ex2>>32&0x00000000ffffffffLL);
t2 &= 0x00000000ffffffffLL;
t0 = (ex1    &0x00000000ffffffffLL)+(ex2    &0x00000000ffffffffLL);
t0 &= 0x00000000ffffffffLL;
ex1_outd = (t2<<32)|(t0);
ex4 = 0==0 ? 0x0000000000000000LL : 0==1 ? SCBR[15].r[CHIP][enq[CHIP]][4] : SCBR[15].r[CHIP][enq[CHIP]][0];
ex2_outd = ex1_outd | ex4;
ex5 = 0==0 ? 0x00000002 : SCBR[15].r[CHIP][enq[CHIP]][0];
t1 = (Ull)(ex2_outd     &0xffffffff00000000LL)<<ex5;
t0 = (Ull)(ex2_outd<<ex5&0x00000000ffffffffLL);
alud[CHIP][1] = t1 | t0;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[16].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[16].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cs0 = SCBR[15].r[CHIP][enq[CHIP]][2];
cs1 = SCBR[15].r[CHIP][enq[CHIP]][6];
cs2 = SCBR[15].r[CHIP][enq[CHIP]][0];
cs3 = SCBR[15].r[CHIP][enq[CHIP]][0];
cex = ((0x8888>>(((cs3>>32&1)<<3)|((cs2>>32&1)<<2)|((cs1>>32&1)<<1)|(cs0>>32&1))&1)?2:0) | ((0x8888>>(((cs3&1)<<3)|((cs2&1)<<2)|((cs1&1)<<1)|(cs0&1))&1)?1:0);
base = (!(1&1)||INIT0[CHIP]) ? ((1&2)?SCBR[15].r[CHIP][enq[CHIP]][0]:SCM0[16].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[15].r[CHIP][enq[CHIP]][0] : SCM0[16].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 4;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0])+(INIT0[CHIP]?0:mexdist);
adr = (Ull)(awoo0[CHIP][0] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (2==1? alud[CHIP][0] : SCBR[15].r[CHIP][enq[CHIP]][10]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cs0 = SCBR[15].r[CHIP][enq[CHIP]][2];
cs1 = SCBR[15].r[CHIP][enq[CHIP]][6];
cs2 = SCBR[15].r[CHIP][enq[CHIP]][0];
cs3 = SCBR[15].r[CHIP][enq[CHIP]][0];
cex = ((0x8888>>(((cs3>>32&1)<<3)|((cs2>>32&1)<<2)|((cs1>>32&1)<<1)|(cs0>>32&1))&1)?2:0) | ((0x8888>>(((cs3&1)<<3)|((cs2&1)<<2)|((cs1&1)<<1)|(cs0&1))&1)?1:0);
base = (!(1&1)||INIT0[CHIP]) ? ((1&2)?SCBR[15].r[CHIP][enq[CHIP]][0]:SCM0[16].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[15].r[CHIP][enq[CHIP]][0] : SCM0[16].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 4;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1])+(INIT0[CHIP]?0:mexdist);
adr = (Ull)(awoo0[CHIP][1] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (2==1? alud[CHIP][1] : SCBR[15].r[CHIP][enq[CHIP]][1]);
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
void emax6sc_pth_gdepth_17(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit17 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (17 && SCBR[16].enq[CHIP]==SCBR[16].deq[CHIP]) || (17<55 && SCBR[17].enq[CHIP]!=SCBR[17].deq[CHIP])) continue;
SCBR[16].deq[CHIP] = 1-SCBR[16].deq[CHIP];
enq[CHIP] = SCBR[17].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
SCBR[17].r[CHIP][enq[CHIP]][8] = SCBR[16].r[CHIP][enq[CHIP]][8];
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
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[17].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[17].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[17].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[17].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
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
void emax6sc_pth_gdepth_18(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit18 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (18 && SCBR[17].enq[CHIP]==SCBR[17].deq[CHIP]) || (18<55 && SCBR[18].enq[CHIP]!=SCBR[18].deq[CHIP])) continue;
SCBR[17].deq[CHIP] = 1-SCBR[17].deq[CHIP];
enq[CHIP] = SCBR[18].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
SCBR[18].r[CHIP][enq[CHIP]][11] = SCBR[17].r[CHIP][enq[CHIP]][8];
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
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[18].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[18].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[18].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[18].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[18].enq[CHIP] = 1-SCBR[18].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_gdepth_19(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit19 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (19 && SCBR[18].enq[CHIP]==SCBR[18].deq[CHIP]) || (19<55 && SCBR[19].enq[CHIP]!=SCBR[19].deq[CHIP])) continue;
SCBR[18].deq[CHIP] = 1-SCBR[18].deq[CHIP];
enq[CHIP] = SCBR[19].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
SCBR[19].r[CHIP][enq[CHIP]][8] = SCBR[18].r[CHIP][enq[CHIP]][11];
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
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[19].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[19].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[19].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[19].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[19].enq[CHIP] = 1-SCBR[19].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_gdepth_20(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit20 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (20 && SCBR[19].enq[CHIP]==SCBR[19].deq[CHIP]) || (20<55 && SCBR[20].enq[CHIP]!=SCBR[20].deq[CHIP])) continue;
SCBR[19].deq[CHIP] = 1-SCBR[19].deq[CHIP];
enq[CHIP] = SCBR[20].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
SCBR[20].r[CHIP][enq[CHIP]][8] = SCBR[19].r[CHIP][enq[CHIP]][8];
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
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[20].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[20].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[20].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[20].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[20].enq[CHIP] = 1-SCBR[20].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_gdepth_21(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit21 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (21 && SCBR[20].enq[CHIP]==SCBR[20].deq[CHIP]) || (21<55 && SCBR[21].enq[CHIP]!=SCBR[21].deq[CHIP])) continue;
SCBR[20].deq[CHIP] = 1-SCBR[20].deq[CHIP];
enq[CHIP] = SCBR[21].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
SCBR[21].r[CHIP][enq[CHIP]][11] = SCBR[20].r[CHIP][enq[CHIP]][8];
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
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[21].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[21].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[21].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[21].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[21].enq[CHIP] = 1-SCBR[21].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_gdepth_22(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit22 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (22 && SCBR[21].enq[CHIP]==SCBR[21].deq[CHIP]) || (22<55 && SCBR[22].enq[CHIP]!=SCBR[22].deq[CHIP])) continue;
SCBR[21].deq[CHIP] = 1-SCBR[21].deq[CHIP];
enq[CHIP] = SCBR[22].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
SCBR[22].r[CHIP][enq[CHIP]][8] = SCBR[21].r[CHIP][enq[CHIP]][11];
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
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[22].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[22].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[22].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[22].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[22].enq[CHIP] = 1-SCBR[22].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_gdepth_23(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit23 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (23 && SCBR[22].enq[CHIP]==SCBR[22].deq[CHIP]) || (23<55 && SCBR[23].enq[CHIP]!=SCBR[23].deq[CHIP])) continue;
SCBR[22].deq[CHIP] = 1-SCBR[22].deq[CHIP];
enq[CHIP] = SCBR[23].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
SCBR[23].r[CHIP][enq[CHIP]][8] = SCBR[22].r[CHIP][enq[CHIP]][8];
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
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[23].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[23].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[23].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[23].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[23].enq[CHIP] = 1-SCBR[23].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_gdepth_24(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit24 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (24 && SCBR[23].enq[CHIP]==SCBR[23].deq[CHIP]) || (24<55 && SCBR[24].enq[CHIP]!=SCBR[24].deq[CHIP])) continue;
SCBR[23].deq[CHIP] = 1-SCBR[23].deq[CHIP];
enq[CHIP] = SCBR[24].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
SCBR[24].r[CHIP][enq[CHIP]][5] = SCBR[23].r[CHIP][enq[CHIP]][8];
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
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[24].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[24].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[24].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[24].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[24].enq[CHIP] = 1-SCBR[24].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_gdepth_25(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit25 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (25 && SCBR[24].enq[CHIP]==SCBR[24].deq[CHIP]) || (25<55 && SCBR[25].enq[CHIP]!=SCBR[25].deq[CHIP])) continue;
SCBR[24].deq[CHIP] = 1-SCBR[24].deq[CHIP];
enq[CHIP] = SCBR[25].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[25].r[CHIP][enq[CHIP]][0] = SCBR[24].r[CHIP][enq[CHIP]][5];
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
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[25].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[25].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[25].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
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
SCBR[25].enq[CHIP] = 1-SCBR[25].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_gdepth_26(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit26 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (26 && SCBR[25].enq[CHIP]==SCBR[25].deq[CHIP]) || (26<55 && SCBR[26].enq[CHIP]!=SCBR[26].deq[CHIP])) continue;
SCBR[25].deq[CHIP] = 1-SCBR[25].deq[CHIP];
enq[CHIP] = SCBR[26].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[26].r[CHIP][enq[CHIP]][0] = SCBR[25].r[CHIP][enq[CHIP]][10];
SCBR[26].r[CHIP][enq[CHIP]][1] = SCBR[25].r[CHIP][enq[CHIP]][0];
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
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[26].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
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
SCBR[26].enq[CHIP] = 1-SCBR[26].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_gdepth_27(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit27 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (27 && SCBR[26].enq[CHIP]==SCBR[26].deq[CHIP]) || (27<55 && SCBR[27].enq[CHIP]!=SCBR[27].deq[CHIP])) continue;
SCBR[26].deq[CHIP] = 1-SCBR[26].deq[CHIP];
enq[CHIP] = SCBR[27].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
SCBR[27].r[CHIP][enq[CHIP]][5] = SCBR[26].r[CHIP][enq[CHIP]][1];
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
alud[CHIP][0] = ex2_outd;
SCBR[27].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
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
SCBR[27].enq[CHIP] = 1-SCBR[27].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_gdepth_28(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit28 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (28 && SCBR[27].enq[CHIP]==SCBR[27].deq[CHIP]) || (28<55 && SCBR[28].enq[CHIP]!=SCBR[28].deq[CHIP])) continue;
SCBR[27].deq[CHIP] = 1-SCBR[27].deq[CHIP];
enq[CHIP] = SCBR[28].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[28].r[CHIP][enq[CHIP]][1] = SCBR[27].r[CHIP][enq[CHIP]][2];
SCBR[28].r[CHIP][enq[CHIP]][3] = SCBR[27].r[CHIP][enq[CHIP]][5];
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
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[27].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[27].r[CHIP][enq[CHIP]][0], 0);
c1 = (ex1>>32&0x00000000ffffffffLL) < (ex2>>32&0x00000000ffffffffLL);
c0 = (ex1    &0x00000000ffffffffLL) < (ex2    &0x00000000ffffffffLL);
ex1_outd = (c1<<32)|c0;
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[28].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[27].r[CHIP][enq[CHIP]][0] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[27].r[CHIP][enq[CHIP]][1], 0);
c1 = (ex1>>32&0x00000000ffffffffLL) > (ex2>>32&0x00000000ffffffffLL);
c0 = (ex1    &0x00000000ffffffffLL) > (ex2    &0x00000000ffffffffLL);
ex1_outd = (c1<<32)|c0;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[28].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[27].r[CHIP][enq[CHIP]][3] : alud[CHIP][2], 0);
ex1_outd = ex1;
ex4 = 1==0 ? 0x0000000000000000LL : 1==1 ? SCBR[27].r[CHIP][enq[CHIP]][4] : SCBR[27].r[CHIP][enq[CHIP]][0];
ex2_outd = ex1_outd | ex4;
alud[CHIP][2] = ex2_outd;
SCBR[28].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
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
SCBR[28].enq[CHIP] = 1-SCBR[28].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_gdepth_29(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit29 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (29 && SCBR[28].enq[CHIP]==SCBR[28].deq[CHIP]) || (29<55 && SCBR[29].enq[CHIP]!=SCBR[29].deq[CHIP])) continue;
SCBR[28].deq[CHIP] = 1-SCBR[28].deq[CHIP];
enq[CHIP] = SCBR[29].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
SCBR[29].r[CHIP][enq[CHIP]][8] = SCBR[28].r[CHIP][enq[CHIP]][3];
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
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[28].r[CHIP][enq[CHIP]][3] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[28].r[CHIP][enq[CHIP]][4], 0);
t2 = (ex1>>32&0x00000000ffffffffLL)+(ex2>>32&0x00000000ffffffffLL);
t2 &= 0x00000000ffffffffLL;
t0 = (ex1    &0x00000000ffffffffLL)+(ex2    &0x00000000ffffffffLL);
t0 &= 0x00000000ffffffffLL;
ex1_outd = (t2<<32)|(t0);
ex4 = 0==0 ? 0x0000000000000000LL : 0==1 ? SCBR[28].r[CHIP][enq[CHIP]][4] : SCBR[28].r[CHIP][enq[CHIP]][0];
ex2_outd = ex1_outd | ex4;
ex5 = 0==0 ? 0x00000002 : SCBR[28].r[CHIP][enq[CHIP]][0];
t1 = (Ull)(ex2_outd     &0xffffffff00000000LL)<<ex5;
t0 = (Ull)(ex2_outd<<ex5&0x00000000ffffffffLL);
alud[CHIP][1] = t1 | t0;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[29].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[29].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cs0 = SCBR[28].r[CHIP][enq[CHIP]][2];
cs1 = SCBR[28].r[CHIP][enq[CHIP]][6];
cs2 = SCBR[28].r[CHIP][enq[CHIP]][0];
cs3 = SCBR[28].r[CHIP][enq[CHIP]][0];
cex = ((0x8888>>(((cs3>>32&1)<<3)|((cs2>>32&1)<<2)|((cs1>>32&1)<<1)|(cs0>>32&1))&1)?2:0) | ((0x8888>>(((cs3&1)<<3)|((cs2&1)<<2)|((cs1&1)<<1)|(cs0&1))&1)?1:0);
base = (!(1&1)||INIT0[CHIP]) ? ((1&2)?SCBR[28].r[CHIP][enq[CHIP]][0]:SCM0[29].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[28].r[CHIP][enq[CHIP]][0] : SCM0[29].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 4;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0])+(INIT0[CHIP]?0:mexdist);
adr = (Ull)(awoo0[CHIP][0] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (2==1? alud[CHIP][0] : SCBR[28].r[CHIP][enq[CHIP]][10]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cs0 = SCBR[28].r[CHIP][enq[CHIP]][2];
cs1 = SCBR[28].r[CHIP][enq[CHIP]][6];
cs2 = SCBR[28].r[CHIP][enq[CHIP]][0];
cs3 = SCBR[28].r[CHIP][enq[CHIP]][0];
cex = ((0x8888>>(((cs3>>32&1)<<3)|((cs2>>32&1)<<2)|((cs1>>32&1)<<1)|(cs0>>32&1))&1)?2:0) | ((0x8888>>(((cs3&1)<<3)|((cs2&1)<<2)|((cs1&1)<<1)|(cs0&1))&1)?1:0);
base = (!(1&1)||INIT0[CHIP]) ? ((1&2)?SCBR[28].r[CHIP][enq[CHIP]][0]:SCM0[29].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[28].r[CHIP][enq[CHIP]][0] : SCM0[29].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 4;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1])+(INIT0[CHIP]?0:mexdist);
adr = (Ull)(awoo0[CHIP][1] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (2==1? alud[CHIP][1] : SCBR[28].r[CHIP][enq[CHIP]][1]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[29].enq[CHIP] = 1-SCBR[29].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_gdepth_30(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit30 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (30 && SCBR[29].enq[CHIP]==SCBR[29].deq[CHIP]) || (30<55 && SCBR[30].enq[CHIP]!=SCBR[30].deq[CHIP])) continue;
SCBR[29].deq[CHIP] = 1-SCBR[29].deq[CHIP];
enq[CHIP] = SCBR[30].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
SCBR[30].r[CHIP][enq[CHIP]][8] = SCBR[29].r[CHIP][enq[CHIP]][8];
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
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[30].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[30].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[30].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[30].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[30].enq[CHIP] = 1-SCBR[30].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_gdepth_31(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit31 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (31 && SCBR[30].enq[CHIP]==SCBR[30].deq[CHIP]) || (31<55 && SCBR[31].enq[CHIP]!=SCBR[31].deq[CHIP])) continue;
SCBR[30].deq[CHIP] = 1-SCBR[30].deq[CHIP];
enq[CHIP] = SCBR[31].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
SCBR[31].r[CHIP][enq[CHIP]][11] = SCBR[30].r[CHIP][enq[CHIP]][8];
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
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[31].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[31].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[31].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[31].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[31].enq[CHIP] = 1-SCBR[31].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_gdepth_32(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit32 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (32 && SCBR[31].enq[CHIP]==SCBR[31].deq[CHIP]) || (32<55 && SCBR[32].enq[CHIP]!=SCBR[32].deq[CHIP])) continue;
SCBR[31].deq[CHIP] = 1-SCBR[31].deq[CHIP];
enq[CHIP] = SCBR[32].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
SCBR[32].r[CHIP][enq[CHIP]][8] = SCBR[31].r[CHIP][enq[CHIP]][11];
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
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[32].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[32].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[32].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[32].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[32].enq[CHIP] = 1-SCBR[32].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_gdepth_33(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit33 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (33 && SCBR[32].enq[CHIP]==SCBR[32].deq[CHIP]) || (33<55 && SCBR[33].enq[CHIP]!=SCBR[33].deq[CHIP])) continue;
SCBR[32].deq[CHIP] = 1-SCBR[32].deq[CHIP];
enq[CHIP] = SCBR[33].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
SCBR[33].r[CHIP][enq[CHIP]][8] = SCBR[32].r[CHIP][enq[CHIP]][8];
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
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[33].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[33].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[33].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[33].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[33].enq[CHIP] = 1-SCBR[33].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_gdepth_34(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit34 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (34 && SCBR[33].enq[CHIP]==SCBR[33].deq[CHIP]) || (34<55 && SCBR[34].enq[CHIP]!=SCBR[34].deq[CHIP])) continue;
SCBR[33].deq[CHIP] = 1-SCBR[33].deq[CHIP];
enq[CHIP] = SCBR[34].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
SCBR[34].r[CHIP][enq[CHIP]][11] = SCBR[33].r[CHIP][enq[CHIP]][8];
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
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[34].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[34].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[34].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[34].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[34].enq[CHIP] = 1-SCBR[34].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_gdepth_35(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit35 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (35 && SCBR[34].enq[CHIP]==SCBR[34].deq[CHIP]) || (35<55 && SCBR[35].enq[CHIP]!=SCBR[35].deq[CHIP])) continue;
SCBR[34].deq[CHIP] = 1-SCBR[34].deq[CHIP];
enq[CHIP] = SCBR[35].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
SCBR[35].r[CHIP][enq[CHIP]][8] = SCBR[34].r[CHIP][enq[CHIP]][11];
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
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[35].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[35].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[35].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[35].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[35].enq[CHIP] = 1-SCBR[35].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_gdepth_36(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit36 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (36 && SCBR[35].enq[CHIP]==SCBR[35].deq[CHIP]) || (36<55 && SCBR[36].enq[CHIP]!=SCBR[36].deq[CHIP])) continue;
SCBR[35].deq[CHIP] = 1-SCBR[35].deq[CHIP];
enq[CHIP] = SCBR[36].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
}
{
SCBR[36].r[CHIP][enq[CHIP]][8] = SCBR[35].r[CHIP][enq[CHIP]][8];
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
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[36].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[36].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[36].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[36].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[36].enq[CHIP] = 1-SCBR[36].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_gdepth_37(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit37 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (37 && SCBR[36].enq[CHIP]==SCBR[36].deq[CHIP]) || (37<55 && SCBR[37].enq[CHIP]!=SCBR[37].deq[CHIP])) continue;
SCBR[36].deq[CHIP] = 1-SCBR[36].deq[CHIP];
enq[CHIP] = SCBR[37].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
SCBR[37].r[CHIP][enq[CHIP]][5] = SCBR[36].r[CHIP][enq[CHIP]][8];
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
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[37].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[37].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[37].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[37].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[37].enq[CHIP] = 1-SCBR[37].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_gdepth_38(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit38 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (38 && SCBR[37].enq[CHIP]==SCBR[37].deq[CHIP]) || (38<55 && SCBR[38].enq[CHIP]!=SCBR[38].deq[CHIP])) continue;
SCBR[37].deq[CHIP] = 1-SCBR[37].deq[CHIP];
enq[CHIP] = SCBR[38].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[38].r[CHIP][enq[CHIP]][0] = SCBR[37].r[CHIP][enq[CHIP]][5];
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
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[38].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[38].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[38].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
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
SCBR[38].enq[CHIP] = 1-SCBR[38].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_gdepth_39(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit39 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (39 && SCBR[38].enq[CHIP]==SCBR[38].deq[CHIP]) || (39<55 && SCBR[39].enq[CHIP]!=SCBR[39].deq[CHIP])) continue;
SCBR[38].deq[CHIP] = 1-SCBR[38].deq[CHIP];
enq[CHIP] = SCBR[39].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[39].r[CHIP][enq[CHIP]][0] = SCBR[38].r[CHIP][enq[CHIP]][10];
SCBR[39].r[CHIP][enq[CHIP]][1] = SCBR[38].r[CHIP][enq[CHIP]][0];
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
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[39].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
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
SCBR[39].enq[CHIP] = 1-SCBR[39].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_gdepth_40(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit40 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (40 && SCBR[39].enq[CHIP]==SCBR[39].deq[CHIP]) || (40<55 && SCBR[40].enq[CHIP]!=SCBR[40].deq[CHIP])) continue;
SCBR[39].deq[CHIP] = 1-SCBR[39].deq[CHIP];
enq[CHIP] = SCBR[40].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
}
{
SCBR[40].r[CHIP][enq[CHIP]][5] = SCBR[39].r[CHIP][enq[CHIP]][1];
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
alud[CHIP][0] = ex2_outd;
SCBR[40].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
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
SCBR[40].enq[CHIP] = 1-SCBR[40].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_gdepth_41(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit41 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (41 && SCBR[40].enq[CHIP]==SCBR[40].deq[CHIP]) || (41<55 && SCBR[41].enq[CHIP]!=SCBR[41].deq[CHIP])) continue;
SCBR[40].deq[CHIP] = 1-SCBR[40].deq[CHIP];
enq[CHIP] = SCBR[41].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[41].r[CHIP][enq[CHIP]][1] = SCBR[40].r[CHIP][enq[CHIP]][2];
SCBR[41].r[CHIP][enq[CHIP]][3] = SCBR[40].r[CHIP][enq[CHIP]][5];
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
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[40].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[40].r[CHIP][enq[CHIP]][0], 0);
c1 = (ex1>>32&0x00000000ffffffffLL) < (ex2>>32&0x00000000ffffffffLL);
c0 = (ex1    &0x00000000ffffffffLL) < (ex2    &0x00000000ffffffffLL);
ex1_outd = (c1<<32)|c0;
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[41].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[40].r[CHIP][enq[CHIP]][0] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[40].r[CHIP][enq[CHIP]][1], 0);
c1 = (ex1>>32&0x00000000ffffffffLL) > (ex2>>32&0x00000000ffffffffLL);
c0 = (ex1    &0x00000000ffffffffLL) > (ex2    &0x00000000ffffffffLL);
ex1_outd = (c1<<32)|c0;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[41].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[40].r[CHIP][enq[CHIP]][3] : alud[CHIP][2], 0);
ex1_outd = ex1;
ex4 = 1==0 ? 0x0000000000000000LL : 1==1 ? SCBR[40].r[CHIP][enq[CHIP]][4] : SCBR[40].r[CHIP][enq[CHIP]][0];
ex2_outd = ex1_outd | ex4;
alud[CHIP][2] = ex2_outd;
SCBR[41].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
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
SCBR[41].enq[CHIP] = 1-SCBR[41].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_gdepth_42(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit42 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (42 && SCBR[41].enq[CHIP]==SCBR[41].deq[CHIP]) || (42<55 && SCBR[42].enq[CHIP]!=SCBR[42].deq[CHIP])) continue;
SCBR[41].deq[CHIP] = 1-SCBR[41].deq[CHIP];
enq[CHIP] = SCBR[42].enq[CHIP];
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
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[41].r[CHIP][enq[CHIP]][3] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[41].r[CHIP][enq[CHIP]][4], 0);
t2 = (ex1>>32&0x00000000ffffffffLL)+(ex2>>32&0x00000000ffffffffLL);
t2 &= 0x00000000ffffffffLL;
t0 = (ex1    &0x00000000ffffffffLL)+(ex2    &0x00000000ffffffffLL);
t0 &= 0x00000000ffffffffLL;
ex1_outd = (t2<<32)|(t0);
ex4 = 0==0 ? 0x0000000000000000LL : 0==1 ? SCBR[41].r[CHIP][enq[CHIP]][4] : SCBR[41].r[CHIP][enq[CHIP]][0];
ex2_outd = ex1_outd | ex4;
ex5 = 0==0 ? 0x00000002 : SCBR[41].r[CHIP][enq[CHIP]][0];
t1 = (Ull)(ex2_outd     &0xffffffff00000000LL)<<ex5;
t0 = (Ull)(ex2_outd<<ex5&0x00000000ffffffffLL);
alud[CHIP][1] = t1 | t0;
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[42].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[42].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cs0 = SCBR[41].r[CHIP][enq[CHIP]][2];
cs1 = SCBR[41].r[CHIP][enq[CHIP]][6];
cs2 = SCBR[41].r[CHIP][enq[CHIP]][0];
cs3 = SCBR[41].r[CHIP][enq[CHIP]][0];
cex = ((0x8888>>(((cs3>>32&1)<<3)|((cs2>>32&1)<<2)|((cs1>>32&1)<<1)|(cs0>>32&1))&1)?2:0) | ((0x8888>>(((cs3&1)<<3)|((cs2&1)<<2)|((cs1&1)<<1)|(cs0&1))&1)?1:0);
base = (!(1&1)||INIT0[CHIP]) ? ((1&2)?SCBR[41].r[CHIP][enq[CHIP]][0]:SCM0[42].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[41].r[CHIP][enq[CHIP]][0] : SCM0[42].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 4;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0])+(INIT0[CHIP]?0:mexdist);
adr = (Ull)(awoo0[CHIP][0] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (2==1? alud[CHIP][0] : SCBR[41].r[CHIP][enq[CHIP]][10]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cs0 = SCBR[41].r[CHIP][enq[CHIP]][2];
cs1 = SCBR[41].r[CHIP][enq[CHIP]][6];
cs2 = SCBR[41].r[CHIP][enq[CHIP]][0];
cs3 = SCBR[41].r[CHIP][enq[CHIP]][0];
cex = ((0x8888>>(((cs3>>32&1)<<3)|((cs2>>32&1)<<2)|((cs1>>32&1)<<1)|(cs0>>32&1))&1)?2:0) | ((0x8888>>(((cs3&1)<<3)|((cs2&1)<<2)|((cs1&1)<<1)|(cs0&1))&1)?1:0);
base = (!(1&1)||INIT0[CHIP]) ? ((1&2)?SCBR[41].r[CHIP][enq[CHIP]][0]:SCM0[42].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[41].r[CHIP][enq[CHIP]][0] : SCM0[42].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 4;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1])+(INIT0[CHIP]?0:mexdist);
adr = (Ull)(awoo0[CHIP][1] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (2==1? alud[CHIP][1] : SCBR[41].r[CHIP][enq[CHIP]][1]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[42].enq[CHIP] = 1-SCBR[42].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_gdepth_43(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit43 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (43 && SCBR[42].enq[CHIP]==SCBR[42].deq[CHIP]) || (43<55 && SCBR[43].enq[CHIP]!=SCBR[43].deq[CHIP])) continue;
SCBR[42].deq[CHIP] = 1-SCBR[42].deq[CHIP];
enq[CHIP] = SCBR[43].enq[CHIP];
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
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[43].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[43].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[43].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[43].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[43].enq[CHIP] = 1-SCBR[43].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_gdepth_44(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit44 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (44 && SCBR[43].enq[CHIP]==SCBR[43].deq[CHIP]) || (44<55 && SCBR[44].enq[CHIP]!=SCBR[44].deq[CHIP])) continue;
SCBR[43].deq[CHIP] = 1-SCBR[43].deq[CHIP];
enq[CHIP] = SCBR[44].enq[CHIP];
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
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[44].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[44].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[44].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[44].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[44].enq[CHIP] = 1-SCBR[44].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_gdepth_45(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit45 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (45 && SCBR[44].enq[CHIP]==SCBR[44].deq[CHIP]) || (45<55 && SCBR[45].enq[CHIP]!=SCBR[45].deq[CHIP])) continue;
SCBR[44].deq[CHIP] = 1-SCBR[44].deq[CHIP];
enq[CHIP] = SCBR[45].enq[CHIP];
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
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[45].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[45].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[45].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[45].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[45].enq[CHIP] = 1-SCBR[45].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_gdepth_46(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit46 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (46 && SCBR[45].enq[CHIP]==SCBR[45].deq[CHIP]) || (46<55 && SCBR[46].enq[CHIP]!=SCBR[46].deq[CHIP])) continue;
SCBR[45].deq[CHIP] = 1-SCBR[45].deq[CHIP];
enq[CHIP] = SCBR[46].enq[CHIP];
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
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[46].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[46].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[46].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[46].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[46].enq[CHIP] = 1-SCBR[46].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_gdepth_47(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit47 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (47 && SCBR[46].enq[CHIP]==SCBR[46].deq[CHIP]) || (47<55 && SCBR[47].enq[CHIP]!=SCBR[47].deq[CHIP])) continue;
SCBR[46].deq[CHIP] = 1-SCBR[46].deq[CHIP];
enq[CHIP] = SCBR[47].enq[CHIP];
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
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[47].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[47].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[47].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[47].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[47].enq[CHIP] = 1-SCBR[47].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_gdepth_48(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit48 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (48 && SCBR[47].enq[CHIP]==SCBR[47].deq[CHIP]) || (48<55 && SCBR[48].enq[CHIP]!=SCBR[48].deq[CHIP])) continue;
SCBR[47].deq[CHIP] = 1-SCBR[47].deq[CHIP];
enq[CHIP] = SCBR[48].enq[CHIP];
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
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[48].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[48].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[48].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[48].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[48].enq[CHIP] = 1-SCBR[48].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_gdepth_49(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit49 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (49 && SCBR[48].enq[CHIP]==SCBR[48].deq[CHIP]) || (49<55 && SCBR[49].enq[CHIP]!=SCBR[49].deq[CHIP])) continue;
SCBR[48].deq[CHIP] = 1-SCBR[48].deq[CHIP];
enq[CHIP] = SCBR[49].enq[CHIP];
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
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[49].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[49].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[49].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[49].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[49].enq[CHIP] = 1-SCBR[49].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_gdepth_50(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit50 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (50 && SCBR[49].enq[CHIP]==SCBR[49].deq[CHIP]) || (50<55 && SCBR[50].enq[CHIP]!=SCBR[50].deq[CHIP])) continue;
SCBR[49].deq[CHIP] = 1-SCBR[49].deq[CHIP];
enq[CHIP] = SCBR[50].enq[CHIP];
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
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[50].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[50].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[50].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][3] = ex2_outd;
SCBR[50].r[CHIP][enq[CHIP]][14] = alud[CHIP][3];
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[50].enq[CHIP] = 1-SCBR[50].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_gdepth_51(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit51 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (51 && SCBR[50].enq[CHIP]==SCBR[50].deq[CHIP]) || (51<55 && SCBR[51].enq[CHIP]!=SCBR[51].deq[CHIP])) continue;
SCBR[50].deq[CHIP] = 1-SCBR[50].deq[CHIP];
enq[CHIP] = SCBR[51].enq[CHIP];
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
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[51].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[51].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex2_outd = ex1_outd;
alud[CHIP][2] = ex2_outd;
SCBR[51].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
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
SCBR[51].enq[CHIP] = 1-SCBR[51].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_gdepth_52(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit52 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (52 && SCBR[51].enq[CHIP]==SCBR[51].deq[CHIP]) || (52<55 && SCBR[52].enq[CHIP]!=SCBR[52].deq[CHIP])) continue;
SCBR[51].deq[CHIP] = 1-SCBR[51].deq[CHIP];
enq[CHIP] = SCBR[52].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[52].r[CHIP][enq[CHIP]][0] = SCBR[51].r[CHIP][enq[CHIP]][10];
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
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[52].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
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
SCBR[52].enq[CHIP] = 1-SCBR[52].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_gdepth_53(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit53 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (53 && SCBR[52].enq[CHIP]==SCBR[52].deq[CHIP]) || (53<55 && SCBR[53].enq[CHIP]!=SCBR[53].deq[CHIP])) continue;
SCBR[52].deq[CHIP] = 1-SCBR[52].deq[CHIP];
enq[CHIP] = SCBR[53].enq[CHIP];
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
alud[CHIP][0] = ex2_outd;
SCBR[53].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
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
SCBR[53].enq[CHIP] = 1-SCBR[53].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_gdepth_54(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit54 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (54 && SCBR[53].enq[CHIP]==SCBR[53].deq[CHIP]) || (54<55 && SCBR[54].enq[CHIP]!=SCBR[54].deq[CHIP])) continue;
SCBR[53].deq[CHIP] = 1-SCBR[53].deq[CHIP];
enq[CHIP] = SCBR[54].enq[CHIP];
INIT1[CHIP]=(uLOOP[CHIP]>LOOP1*LOOP0-LOOP0);
INIT0[CHIP]=(uLOOP[CHIP]==uLOOP[CHIP]/LOOP0*LOOP0);
{
SCBR[54].r[CHIP][enq[CHIP]][1] = SCBR[53].r[CHIP][enq[CHIP]][2];
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
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[53].r[CHIP][enq[CHIP]][2] : alud[CHIP][0], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[53].r[CHIP][enq[CHIP]][0], 0);
c1 = (ex1>>32&0x00000000ffffffffLL) < (ex2>>32&0x00000000ffffffffLL);
c0 = (ex1    &0x00000000ffffffffLL) < (ex2    &0x00000000ffffffffLL);
ex1_outd = (c1<<32)|c0;
ex2_outd = ex1_outd;
alud[CHIP][0] = ex2_outd;
SCBR[54].r[CHIP][enq[CHIP]][2] = alud[CHIP][0];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[53].r[CHIP][enq[CHIP]][0] : alud[CHIP][1], 0);
ex2 = exm(((0&2)&&!INIT0[CHIP]) ? 0 : SCBR[53].r[CHIP][enq[CHIP]][1], 0);
c1 = (ex1>>32&0x00000000ffffffffLL) > (ex2>>32&0x00000000ffffffffLL);
c0 = (ex1    &0x00000000ffffffffLL) > (ex2    &0x00000000ffffffffLL);
ex1_outd = (c1<<32)|c0;
ex2_outd = ex1_outd;
alud[CHIP][1] = ex2_outd;
SCBR[54].r[CHIP][enq[CHIP]][6] = alud[CHIP][1];
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
ex1 = exm(!0||(INIT1[CHIP]&&INIT0[CHIP])||((0&1)&&INIT0[CHIP]) ? SCBR[53].r[CHIP][enq[CHIP]][3] : alud[CHIP][2], 0);
ex1_outd = ex1;
ex4 = 1==0 ? 0x0000000000000000LL : 1==1 ? SCBR[53].r[CHIP][enq[CHIP]][4] : SCBR[53].r[CHIP][enq[CHIP]][0];
ex2_outd = ex1_outd | ex4;
alud[CHIP][2] = ex2_outd;
SCBR[54].r[CHIP][enq[CHIP]][10] = alud[CHIP][2];
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
SCBR[54].enq[CHIP] = 1-SCBR[54].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
/* EMAXSC start */
void emax6sc_pth_gdepth_55(struct sc_param *param) {
Ull  CHIP, LOOP0=param->LOOP0, LOOP1=param->LOOP1;
Ull  INIT1[4], INIT0[4];
Uint uLOOP[4], enq[4];
Ull  awoo1[4][4], awoo0[4][4], mexd1[4][4], mexd0[4][4], alud[4][4];
for (CHIP=0; CHIP<4; CHIP++) { /* unit55 */
LOOP1=1;uLOOP[CHIP]=LOOP0;
}
while (1) {
for (CHIP=0; CHIP<4; CHIP++)
if (uLOOP[CHIP]) break;
if (CHIP==4) break;
for (CHIP=0; CHIP<4; CHIP++) {
if (uLOOP[CHIP]==0 || (55 && SCBR[54].enq[CHIP]==SCBR[54].deq[CHIP]) || (55<55 && SCBR[55].enq[CHIP]!=SCBR[55].deq[CHIP])) continue;
SCBR[54].deq[CHIP] = 1-SCBR[54].deq[CHIP];
enq[CHIP] = SCBR[55].enq[CHIP];
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
}
{ union { Uint i; float f; } f3, f2, f1, f0; Ull t3, t2, t1, t0, ex1, ex2, ex3, ex4, ex5, c1, c0, ex1_outd, ex2_outd;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cs0 = SCBR[54].r[CHIP][enq[CHIP]][2];
cs1 = SCBR[54].r[CHIP][enq[CHIP]][6];
cs2 = SCBR[54].r[CHIP][enq[CHIP]][0];
cs3 = SCBR[54].r[CHIP][enq[CHIP]][0];
cex = ((0x8888>>(((cs3>>32&1)<<3)|((cs2>>32&1)<<2)|((cs1>>32&1)<<1)|(cs0>>32&1))&1)?2:0) | ((0x8888>>(((cs3&1)<<3)|((cs2&1)<<2)|((cs1&1)<<1)|(cs0&1))&1)?1:0);
base = (!(1&1)||INIT0[CHIP]) ? ((1&2)?SCBR[54].r[CHIP][enq[CHIP]][0]:SCM0[55].b[CHIP][0]) : awoo0[CHIP][0];
offs = eam(0 ? SCBR[54].r[CHIP][enq[CHIP]][0] : SCM0[55].o[CHIP][0], 14);
mexdist = INIT0[CHIP] ? 0 : 4;
awoo0[CHIP][0] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][0])+(INIT0[CHIP]?0:mexdist);
adr = (Ull)(awoo0[CHIP][0] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (2==1? alud[CHIP][0] : SCBR[54].r[CHIP][enq[CHIP]][10]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
cs0 = SCBR[54].r[CHIP][enq[CHIP]][2];
cs1 = SCBR[54].r[CHIP][enq[CHIP]][6];
cs2 = SCBR[54].r[CHIP][enq[CHIP]][0];
cs3 = SCBR[54].r[CHIP][enq[CHIP]][0];
cex = ((0x8888>>(((cs3>>32&1)<<3)|((cs2>>32&1)<<2)|((cs1>>32&1)<<1)|(cs0>>32&1))&1)?2:0) | ((0x8888>>(((cs3&1)<<3)|((cs2&1)<<2)|((cs1&1)<<1)|(cs0&1))&1)?1:0);
base = (!(1&1)||INIT0[CHIP]) ? ((1&2)?SCBR[54].r[CHIP][enq[CHIP]][0]:SCM0[55].b[CHIP][1]) : awoo0[CHIP][1];
offs = eam(0 ? SCBR[54].r[CHIP][enq[CHIP]][0] : SCM0[55].o[CHIP][1], 14);
mexdist = INIT0[CHIP] ? 0 : 4;
awoo0[CHIP][1] = (Ull)(INIT0[CHIP]?base:awoo0[CHIP][1])+(INIT0[CHIP]?0:mexdist);
adr = (Ull)(awoo0[CHIP][1] + offs);
if (cex   &1) *(Uint*)(adr&~3LL) = (2==1? alud[CHIP][1] : SCBR[54].r[CHIP][enq[CHIP]][1]);
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
{ Ull cs0, cs1, cs2, cs3, cex, base, offs, adr, mexdist;
}
SCBR[55].enq[CHIP] = 1-SCBR[55].enq[CHIP];
uLOOP[CHIP]--;
}
}
}
/* EMAXSC end */
