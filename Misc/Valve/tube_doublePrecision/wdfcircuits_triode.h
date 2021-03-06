#ifndef WDFCIRCUITS_H
#define WDFCIRCUITS_H
#define TOLERANCE 1e-6

typedef double Real;

typedef struct str_triode
{
	Real Kb, Gb, Pb;
	Real Kr, Gr, Pr;

	Real vg, vk, vp;
	Real g, mu, gamma, c, gg, e, cg, ig0;
    Real r8_epsilon;
	int insane;
} Triode;

typedef struct str_TubeStageCircuit
{
    Triode t;
    Real Cia;
    Real Cka;
    Real Coa;
    //R values
    Real I3_3Gamma1;
    Real E250E;
    Real ViE;
    Real P0_3Gamma1;
    Real S0_3Gamma1;
    Real S2_3Gamma1;
    Real S1_3Gamma1;
    Real P2_3Gamma1;
    int on;
} TubeStageCircuit;
Real ffg(Triode *triode, Real VG);
Real fgdash(Triode *triode, Real VG);
Real ffp(Triode *triode, Real VP);
Real ffp_insane(Triode *triode, Real VP);
Real fpdash(Triode *triode, Real VP);
Real ffk(Triode *triode);

Real from_dB(Real gdb);
void TriodeInit(Triode *triode);
void compute(Triode *triode, Real Kbb, Real Gbb, Real Pbb);

//Brent's method
Real zeroffp(Triode *triode, Real a, Real b, Real t);
Real zeroffp_insane(Triode *triode, Real a, Real b, Real t);
Real zeroffg(Triode *triode, Real a, Real b, Real t);
void updateRValues(TubeStageCircuit *ckt, Real C_Ci, Real C_Ck, Real C_Co, Real E_E250, Real E_Vi, Real R_E250, Real R_Rg, Real R_Ri, Real R_Rk, Real R_Ro, Real R_Vi, Real sampleRate, int insane, Triode tube);
Real advanc(TubeStageCircuit *ckt, Real VE);
void warmup_tubes(TubeStageCircuit *ckt, int warmupDuration);
#endif
