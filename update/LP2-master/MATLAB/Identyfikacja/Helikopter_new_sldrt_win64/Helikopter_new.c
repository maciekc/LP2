/*
 * Helikopter_new.c
 *
 * Code generation for model "Helikopter_new".
 *
 * Model version              : 1.252
 * Simulink Coder version : 8.8.1 (R2015aSP1) 04-Sep-2015
 * C source code generated on : Tue Nov 28 12:46:16 2017
 *
 * Target selection: rtwin.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Helikopter_new.h"
#include "Helikopter_new_private.h"
#include "Helikopter_new_dt.h"

/* list of Simulink Desktop Real-Time timers */
const int RTWinTimerCount = 1;
const double RTWinTimers[2] = {
  0.001, 0.0,
};

/* Block signals (auto storage) */
B_Helikopter_new_T Helikopter_new_B;

/* Continuous states */
X_Helikopter_new_T Helikopter_new_X;

/* Block states (auto storage) */
DW_Helikopter_new_T Helikopter_new_DW;

/* Real-time model */
RT_MODEL_Helikopter_new_T Helikopter_new_M_;
RT_MODEL_Helikopter_new_T *const Helikopter_new_M = &Helikopter_new_M_;

/* Forward declaration for local functions */
static void Helikopter_new_sqrt(creal_T *x);
static void Helikopter__eml_matlab_zlartg_a(const creal_T f, const creal_T g,
  real_T *cs, creal_T *sn);
static void Helikopter_ne_eml_matlab_zlartg(const creal_T f, const creal_T g,
  real_T *cs, creal_T *sn, creal_T *r);
static void Helikopter_ne_eml_matlab_zhgeqz(const creal_T A_data[], const
  int32_T A_sizes[2], int32_T ilo, int32_T ihi, int32_T *info, creal_T
  alpha1_data[], int32_T *alpha1_sizes, creal_T beta1_data[], int32_T
  *beta1_sizes);
static void Helikopter_new_eml_xgeev(const creal_T A_data[], const int32_T
  A_sizes[2], int32_T *info, creal_T alpha1_data[], int32_T *alpha1_sizes,
  creal_T beta1_data[], int32_T *beta1_sizes);
static void Helikopter_new_roots(const real_T c[6], creal_T r_data[], int32_T
  *r_sizes);

/*
 * This function updates continuous states using the ODE5 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE5_A[6] = {
    1.0/5.0, 3.0/10.0, 4.0/5.0, 8.0/9.0, 1.0, 1.0
  };

  static const real_T rt_ODE5_B[6][6] = {
    { 1.0/5.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

    { 3.0/40.0, 9.0/40.0, 0.0, 0.0, 0.0, 0.0 },

    { 44.0/45.0, -56.0/15.0, 32.0/9.0, 0.0, 0.0, 0.0 },

    { 19372.0/6561.0, -25360.0/2187.0, 64448.0/6561.0, -212.0/729.0, 0.0, 0.0 },

    { 9017.0/3168.0, -355.0/33.0, 46732.0/5247.0, 49.0/176.0, -5103.0/18656.0,
      0.0 },

    { 35.0/384.0, 0.0, 500.0/1113.0, 125.0/192.0, -2187.0/6784.0, 11.0/84.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE5_IntgData *id = (ODE5_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T *f4 = id->f[4];
  real_T *f5 = id->f[5];
  real_T hB[6];
  int_T i;
  int_T nXc = 3;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  Helikopter_new_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE5_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[0]);
  rtsiSetdX(si, f1);
  Helikopter_new_output();
  Helikopter_new_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE5_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[1]);
  rtsiSetdX(si, f2);
  Helikopter_new_output();
  Helikopter_new_derivatives();

  /* f(:,4) = feval(odefile, t + hA(3), y + f*hB(:,3), args(:)(*)); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE5_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[2]);
  rtsiSetdX(si, f3);
  Helikopter_new_output();
  Helikopter_new_derivatives();

  /* f(:,5) = feval(odefile, t + hA(4), y + f*hB(:,4), args(:)(*)); */
  for (i = 0; i <= 3; i++) {
    hB[i] = h * rt_ODE5_B[3][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[3]);
  rtsiSetdX(si, f4);
  Helikopter_new_output();
  Helikopter_new_derivatives();

  /* f(:,6) = feval(odefile, t + hA(5), y + f*hB(:,5), args(:)(*)); */
  for (i = 0; i <= 4; i++) {
    hB[i] = h * rt_ODE5_B[4][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3] + f4[i]*hB[4]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f5);
  Helikopter_new_output();
  Helikopter_new_derivatives();

  /* tnew = t + hA(6);
     ynew = y + f*hB(:,6); */
  for (i = 0; i <= 5; i++) {
    hB[i] = h * rt_ODE5_B[5][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3] + f4[i]*hB[4] + f5[i]*hB[5]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T a;
  a = fabs(u0);
  y = fabs(u1);
  if (a < y) {
    a /= y;
    y *= sqrt(a * a + 1.0);
  } else if (a > y) {
    y /= a;
    y = sqrt(y * y + 1.0) * a;
  } else {
    if (!rtIsNaN(y)) {
      y = a * 1.4142135623730951;
    }
  }

  return y;
}

/* Function for MATLAB Function: '<Root>/MATLAB Function1' */
static void Helikopter_new_sqrt(creal_T *x)
{
  real_T absxr;
  real_T absxi;
  if (x->im == 0.0) {
    if (x->re < 0.0) {
      absxi = 0.0;
      absxr = sqrt(fabs(x->re));
    } else {
      absxi = sqrt(x->re);
      absxr = 0.0;
    }
  } else if (x->re == 0.0) {
    if (x->im < 0.0) {
      absxi = sqrt(-x->im / 2.0);
      absxr = -absxi;
    } else {
      absxi = sqrt(x->im / 2.0);
      absxr = absxi;
    }
  } else if (rtIsNaN(x->re) || rtIsNaN(x->im)) {
    absxi = (rtNaN);
    absxr = (rtNaN);
  } else if (rtIsInf(x->im)) {
    absxi = (rtInf);
    absxr = x->im;
  } else if (rtIsInf(x->re)) {
    if (x->re < 0.0) {
      absxi = 0.0;
      absxr = (rtInf);
    } else {
      absxi = (rtInf);
      absxr = 0.0;
    }
  } else {
    absxr = fabs(x->re);
    absxi = fabs(x->im);
    if ((absxr > 4.4942328371557893E+307) || (absxi > 4.4942328371557893E+307))
    {
      absxr *= 0.5;
      absxi *= 0.5;
      absxi = rt_hypotd_snf(absxr, absxi);
      if (absxi > absxr) {
        absxi = sqrt(absxr / absxi + 1.0) * sqrt(absxi);
      } else {
        absxi = sqrt(absxi) * 1.4142135623730951;
      }
    } else {
      absxi = sqrt((rt_hypotd_snf(absxr, absxi) + absxr) * 0.5);
    }

    if (x->re > 0.0) {
      absxr = x->im / absxi * 0.5;
    } else {
      if (x->im < 0.0) {
        absxr = -absxi;
      } else {
        absxr = absxi;
      }

      absxi = x->im / absxr * 0.5;
    }
  }

  x->re = absxi;
  x->im = absxr;
}

/* Function for MATLAB Function: '<Root>/MATLAB Function1' */
static void Helikopter__eml_matlab_zlartg_a(const creal_T f, const creal_T g,
  real_T *cs, creal_T *sn)
{
  real_T scale;
  real_T f2;
  real_T f2s;
  real_T g2s;
  boolean_T guard1 = false;
  real_T fs_re;
  real_T fs_im;
  real_T gs_re;
  real_T gs_im;
  scale = fabs(f.re);
  f2s = fabs(f.im);
  if (f2s > scale) {
    scale = f2s;
  }

  f2s = fabs(g.re);
  f2 = fabs(g.im);
  if (f2 > f2s) {
    f2s = f2;
  }

  if (f2s > scale) {
    scale = f2s;
  }

  fs_re = f.re;
  fs_im = f.im;
  gs_re = g.re;
  gs_im = g.im;
  if (scale >= 7.4428285367870146E+137) {
    do {
      fs_re *= 1.3435752215134178E-138;
      fs_im *= 1.3435752215134178E-138;
      gs_re *= 1.3435752215134178E-138;
      gs_im *= 1.3435752215134178E-138;
      scale *= 1.3435752215134178E-138;
    } while (!(scale < 7.4428285367870146E+137));

    guard1 = true;
  } else if (scale <= 1.3435752215134178E-138) {
    if ((g.re == 0.0) && (g.im == 0.0)) {
      *cs = 1.0;
      sn->re = 0.0;
      sn->im = 0.0;
    } else {
      do {
        fs_re *= 7.4428285367870146E+137;
        fs_im *= 7.4428285367870146E+137;
        gs_re *= 7.4428285367870146E+137;
        gs_im *= 7.4428285367870146E+137;
        scale *= 7.4428285367870146E+137;
      } while (!(scale > 1.3435752215134178E-138));

      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    f2 = fs_re * fs_re + fs_im * fs_im;
    scale = gs_re * gs_re + gs_im * gs_im;
    f2s = scale;
    if (1.0 > scale) {
      f2s = 1.0;
    }

    if (f2 <= f2s * 2.0041683600089728E-292) {
      if ((f.re == 0.0) && (f.im == 0.0)) {
        *cs = 0.0;
        f2s = rt_hypotd_snf(gs_re, gs_im);
        sn->re = gs_re / f2s;
        sn->im = -gs_im / f2s;
      } else {
        g2s = sqrt(scale);
        *cs = rt_hypotd_snf(fs_re, fs_im) / g2s;
        f2s = fabs(f.re);
        f2 = fabs(f.im);
        if (f2 > f2s) {
          f2s = f2;
        }

        if (f2s > 1.0) {
          f2s = rt_hypotd_snf(f.re, f.im);
          fs_re = f.re / f2s;
          fs_im = f.im / f2s;
        } else {
          scale = 7.4428285367870146E+137 * f.re;
          f2 = 7.4428285367870146E+137 * f.im;
          f2s = rt_hypotd_snf(scale, f2);
          fs_re = scale / f2s;
          fs_im = f2 / f2s;
        }

        gs_re /= g2s;
        gs_im = -gs_im / g2s;
        sn->re = fs_re * gs_re - fs_im * gs_im;
        sn->im = fs_re * gs_im + fs_im * gs_re;
      }
    } else {
      f2s = sqrt(scale / f2 + 1.0);
      fs_re *= f2s;
      fs_im *= f2s;
      *cs = 1.0 / f2s;
      f2s = f2 + scale;
      fs_re /= f2s;
      fs_im /= f2s;
      sn->re = fs_re * gs_re - fs_im * -gs_im;
      sn->im = fs_re * -gs_im + fs_im * gs_re;
    }
  }
}

/* Function for MATLAB Function: '<Root>/MATLAB Function1' */
static void Helikopter_ne_eml_matlab_zlartg(const creal_T f, const creal_T g,
  real_T *cs, creal_T *sn, creal_T *r)
{
  real_T scale;
  int32_T count;
  int32_T rescaledir;
  real_T f2;
  real_T f2s;
  real_T g2s;
  boolean_T guard1 = false;
  real_T fs_re;
  real_T fs_im;
  real_T gs_re;
  real_T gs_im;
  scale = fabs(f.re);
  f2s = fabs(f.im);
  if (f2s > scale) {
    scale = f2s;
  }

  f2s = fabs(g.re);
  f2 = fabs(g.im);
  if (f2 > f2s) {
    f2s = f2;
  }

  if (f2s > scale) {
    scale = f2s;
  }

  fs_re = f.re;
  fs_im = f.im;
  gs_re = g.re;
  gs_im = g.im;
  count = 0;
  rescaledir = 0;
  if (scale >= 7.4428285367870146E+137) {
    do {
      count++;
      fs_re *= 1.3435752215134178E-138;
      fs_im *= 1.3435752215134178E-138;
      gs_re *= 1.3435752215134178E-138;
      gs_im *= 1.3435752215134178E-138;
      scale *= 1.3435752215134178E-138;
    } while (!(scale < 7.4428285367870146E+137));

    rescaledir = 1;
    guard1 = true;
  } else if (scale <= 1.3435752215134178E-138) {
    if ((g.re == 0.0) && (g.im == 0.0)) {
      *cs = 1.0;
      sn->re = 0.0;
      sn->im = 0.0;
      *r = f;
    } else {
      do {
        count++;
        fs_re *= 7.4428285367870146E+137;
        fs_im *= 7.4428285367870146E+137;
        gs_re *= 7.4428285367870146E+137;
        gs_im *= 7.4428285367870146E+137;
        scale *= 7.4428285367870146E+137;
      } while (!(scale > 1.3435752215134178E-138));

      rescaledir = -1;
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    f2 = fs_re * fs_re + fs_im * fs_im;
    scale = gs_re * gs_re + gs_im * gs_im;
    f2s = scale;
    if (1.0 > scale) {
      f2s = 1.0;
    }

    if (f2 <= f2s * 2.0041683600089728E-292) {
      if ((f.re == 0.0) && (f.im == 0.0)) {
        *cs = 0.0;
        r->re = rt_hypotd_snf(g.re, g.im);
        r->im = 0.0;
        f2s = rt_hypotd_snf(gs_re, gs_im);
        sn->re = gs_re / f2s;
        sn->im = -gs_im / f2s;
      } else {
        g2s = sqrt(scale);
        *cs = rt_hypotd_snf(fs_re, fs_im) / g2s;
        f2s = fabs(f.re);
        f2 = fabs(f.im);
        if (f2 > f2s) {
          f2s = f2;
        }

        if (f2s > 1.0) {
          f2s = rt_hypotd_snf(f.re, f.im);
          fs_re = f.re / f2s;
          fs_im = f.im / f2s;
        } else {
          scale = 7.4428285367870146E+137 * f.re;
          f2 = 7.4428285367870146E+137 * f.im;
          f2s = rt_hypotd_snf(scale, f2);
          fs_re = scale / f2s;
          fs_im = f2 / f2s;
        }

        gs_re /= g2s;
        gs_im = -gs_im / g2s;
        sn->re = fs_re * gs_re - fs_im * gs_im;
        sn->im = fs_re * gs_im + fs_im * gs_re;
        r->re = (sn->re * g.re - sn->im * g.im) + *cs * f.re;
        r->im = (sn->re * g.im + sn->im * g.re) + *cs * f.im;
      }
    } else {
      f2s = sqrt(scale / f2 + 1.0);
      r->re = f2s * fs_re;
      r->im = f2s * fs_im;
      *cs = 1.0 / f2s;
      f2s = f2 + scale;
      f2 = r->re / f2s;
      scale = r->im / f2s;
      sn->re = f2 * gs_re - scale * -gs_im;
      sn->im = f2 * -gs_im + scale * gs_re;
      if (rescaledir > 0) {
        while (rescaledir <= count) {
          r->re *= 7.4428285367870146E+137;
          r->im *= 7.4428285367870146E+137;
          rescaledir++;
        }
      } else {
        if (rescaledir < 0) {
          for (rescaledir = 1; rescaledir <= count; rescaledir++) {
            r->re *= 1.3435752215134178E-138;
            r->im *= 1.3435752215134178E-138;
          }
        }
      }
    }
  }
}

/* Function for MATLAB Function: '<Root>/MATLAB Function1' */
static void Helikopter_ne_eml_matlab_zhgeqz(const creal_T A_data[], const
  int32_T A_sizes[2], int32_T ilo, int32_T ihi, int32_T *info, creal_T
  alpha1_data[], int32_T *alpha1_sizes, creal_T beta1_data[], int32_T
  *beta1_sizes)
{
  creal_T ctemp;
  real_T anorm;
  boolean_T failed;
  int32_T j;
  int32_T ifirst;
  int32_T istart;
  int32_T ilast;
  int32_T ilastm1;
  int32_T ifrstm;
  int32_T ilastm;
  int32_T iiter;
  boolean_T goto60;
  boolean_T goto70;
  boolean_T goto90;
  int32_T jp1;
  int32_T jm1;
  boolean_T ilazro;
  creal_T t1;
  creal_T d;
  int32_T jiter;
  real_T scale;
  real_T sumsq;
  boolean_T firstNonZero;
  real_T reAij;
  real_T imAij;
  int32_T i;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  int32_T exitg1;
  creal_T b_A_data[25];
  int32_T b_A_sizes_idx_0;
  real_T sigma2_re;
  real_T sigma2_im;
  real_T rho_re;
  real_T rho_im;
  real_T eshift_re;
  real_T eshift_im;
  b_A_sizes_idx_0 = A_sizes[0];
  jp1 = A_sizes[0] * A_sizes[1];
  for (jm1 = 0; jm1 < jp1; jm1++) {
    b_A_data[jm1] = A_data[jm1];
  }

  *info = 0;
  if ((A_sizes[0] == 1) && (A_sizes[1] == 1)) {
    ihi = 1;
  }

  *alpha1_sizes = A_sizes[0];
  jp1 = A_sizes[0];
  for (jm1 = 0; jm1 < jp1; jm1++) {
    alpha1_data[jm1].re = 0.0;
    alpha1_data[jm1].im = 0.0;
  }

  *beta1_sizes = A_sizes[0];
  jp1 = A_sizes[0];
  for (jm1 = 0; jm1 < jp1; jm1++) {
    beta1_data[jm1].re = 1.0;
    beta1_data[jm1].im = 0.0;
  }

  eshift_re = 0.0;
  eshift_im = 0.0;
  ctemp.re = 0.0;
  ctemp.im = 0.0;
  rho_re = 0.0;
  rho_im = 0.0;
  anorm = 0.0;
  if (!(ilo > ihi)) {
    scale = 0.0;
    sumsq = 0.0;
    firstNonZero = true;
    for (jp1 = ilo; jp1 <= ihi; jp1++) {
      jm1 = jp1 + 1;
      if (ihi < jp1 + 1) {
        jm1 = ihi;
      }

      for (i = ilo; i <= jm1; i++) {
        reAij = A_data[((jp1 - 1) * A_sizes[0] + i) - 1].re;
        imAij = A_data[((jp1 - 1) * A_sizes[0] + i) - 1].im;
        if (reAij != 0.0) {
          anorm = fabs(reAij);
          if (firstNonZero) {
            sumsq = 1.0;
            scale = anorm;
            firstNonZero = false;
          } else if (scale < anorm) {
            reAij = scale / anorm;
            sumsq = sumsq * reAij * reAij + 1.0;
            scale = anorm;
          } else {
            reAij = anorm / scale;
            sumsq += reAij * reAij;
          }
        }

        if (imAij != 0.0) {
          anorm = fabs(imAij);
          if (firstNonZero) {
            sumsq = 1.0;
            scale = anorm;
            firstNonZero = false;
          } else if (scale < anorm) {
            reAij = scale / anorm;
            sumsq = sumsq * reAij * reAij + 1.0;
            scale = anorm;
          } else {
            reAij = anorm / scale;
            sumsq += reAij * reAij;
          }
        }
      }
    }

    anorm = scale * sqrt(sumsq);
  }

  reAij = 2.2204460492503131E-16 * anorm;
  imAij = 2.2250738585072014E-308;
  if (reAij > 2.2250738585072014E-308) {
    imAij = reAij;
  }

  reAij = 2.2250738585072014E-308;
  if (anorm > 2.2250738585072014E-308) {
    reAij = anorm;
  }

  sumsq = 1.0 / reAij;
  failed = true;
  for (jp1 = ihi; jp1 + 1 <= A_sizes[0]; jp1++) {
    alpha1_data[jp1] = A_data[A_sizes[0] * jp1 + jp1];
  }

  if (ihi >= ilo) {
    ifirst = ilo;
    istart = ilo;
    ilast = ihi - 1;
    ilastm1 = ihi - 2;
    ifrstm = ilo;
    ilastm = ihi;
    iiter = 0;
    goto60 = false;
    goto70 = false;
    goto90 = false;
    jiter = 1;
    do {
      exitg1 = 0;
      if (jiter <= ((ihi - ilo) + 1) * 30) {
        if (ilast + 1 == ilo) {
          goto60 = true;
        } else if (fabs(b_A_data[b_A_sizes_idx_0 * ilastm1 + ilast].re) + fabs
                   (b_A_data[b_A_sizes_idx_0 * ilastm1 + ilast].im) <= imAij) {
          b_A_data[ilast + b_A_sizes_idx_0 * ilastm1].re = 0.0;
          b_A_data[ilast + b_A_sizes_idx_0 * ilastm1].im = 0.0;
          goto60 = true;
        } else {
          j = ilastm1;
          firstNonZero = false;
          while ((!firstNonZero) && (j + 1 >= ilo)) {
            if (j + 1 == ilo) {
              ilazro = true;
            } else if (fabs(b_A_data[(j - 1) * b_A_sizes_idx_0 + j].re) + fabs
                       (b_A_data[(j - 1) * b_A_sizes_idx_0 + j].im) <= imAij) {
              b_A_data[j + b_A_sizes_idx_0 * (j - 1)].re = 0.0;
              b_A_data[j + b_A_sizes_idx_0 * (j - 1)].im = 0.0;
              ilazro = true;
            } else {
              ilazro = false;
            }

            if (ilazro) {
              ifirst = j + 1;
              goto70 = true;
              firstNonZero = true;
            } else {
              j--;
            }
          }
        }

        if (!(goto60 || goto70)) {
          for (jm1 = 0; jm1 < *alpha1_sizes; jm1++) {
            alpha1_data[jm1].re = (rtNaN);
            alpha1_data[jm1].im = 0.0;
          }

          for (jm1 = 0; jm1 < *beta1_sizes; jm1++) {
            beta1_data[jm1].re = (rtNaN);
            beta1_data[jm1].im = 0.0;
          }

          *info = 1;
          exitg1 = 1;
        } else {
          firstNonZero = false;
          if (goto60) {
            goto60 = false;
            alpha1_data[ilast] = b_A_data[b_A_sizes_idx_0 * ilast + ilast];
            ilast = ilastm1;
            ilastm1--;
            if (ilast + 1 < ilo) {
              failed = false;
              guard2 = true;
              exitg1 = 1;
            } else {
              iiter = 0;
              eshift_re = 0.0;
              eshift_im = 0.0;
              ilastm = ilast + 1;
              if (ifrstm > ilast + 1) {
                ifrstm = ilo;
              }

              firstNonZero = true;
            }
          } else {
            if (goto70) {
              goto70 = false;
              iiter++;
              ifrstm = ifirst;
              if (iiter - iiter / 10 * 10 != 0) {
                anorm = -(b_A_data[b_A_sizes_idx_0 * ilast + ilast].re -
                          b_A_data[b_A_sizes_idx_0 * ilastm1 + ilastm1].re);
                scale = -(b_A_data[b_A_sizes_idx_0 * ilast + ilast].im -
                          b_A_data[b_A_sizes_idx_0 * ilastm1 + ilastm1].im);
                if (scale == 0.0) {
                  t1.re = anorm / 2.0;
                  t1.im = 0.0;
                } else if (anorm == 0.0) {
                  t1.re = 0.0;
                  t1.im = scale / 2.0;
                } else {
                  t1.re = anorm / 2.0;
                  t1.im = scale / 2.0;
                }

                d.re = (b_A_data[b_A_sizes_idx_0 * ilast + ilastm1].re *
                        b_A_data[b_A_sizes_idx_0 * ilastm1 + ilast].re -
                        b_A_data[b_A_sizes_idx_0 * ilast + ilastm1].im *
                        b_A_data[b_A_sizes_idx_0 * ilastm1 + ilast].im) + (t1.re
                  * t1.re - t1.im * t1.im);
                d.im = (b_A_data[b_A_sizes_idx_0 * ilast + ilastm1].re *
                        b_A_data[b_A_sizes_idx_0 * ilastm1 + ilast].im +
                        b_A_data[b_A_sizes_idx_0 * ilast + ilastm1].im *
                        b_A_data[b_A_sizes_idx_0 * ilastm1 + ilast].re) + (t1.re
                  * t1.im + t1.im * t1.re);
                Helikopter_new_sqrt(&d);
                rho_re = b_A_data[b_A_sizes_idx_0 * ilastm1 + ilastm1].re -
                  (t1.re - d.re);
                rho_im = b_A_data[b_A_sizes_idx_0 * ilastm1 + ilastm1].im -
                  (t1.im - d.im);
                sigma2_re = b_A_data[b_A_sizes_idx_0 * ilastm1 + ilastm1].re -
                  (t1.re + d.re);
                sigma2_im = b_A_data[b_A_sizes_idx_0 * ilastm1 + ilastm1].im -
                  (t1.im + d.im);
                if (rt_hypotd_snf(rho_re - b_A_data[b_A_sizes_idx_0 * ilast +
                                  ilast].re, rho_im - b_A_data[b_A_sizes_idx_0 *
                                  ilast + ilast].im) <= rt_hypotd_snf(sigma2_re
                     - b_A_data[b_A_sizes_idx_0 * ilast + ilast].re, sigma2_im -
                     b_A_data[b_A_sizes_idx_0 * ilast + ilast].im)) {
                  sigma2_re = rho_re;
                  sigma2_im = rho_im;
                  rho_re = t1.re - d.re;
                  rho_im = t1.im - d.im;
                } else {
                  rho_re = t1.re + d.re;
                  rho_im = t1.im + d.im;
                }
              } else {
                eshift_re += b_A_data[b_A_sizes_idx_0 * ilastm1 + ilast].re;
                eshift_im += b_A_data[b_A_sizes_idx_0 * ilastm1 + ilast].im;
                sigma2_re = eshift_re;
                sigma2_im = eshift_im;
              }

              j = ilastm1;
              jp1 = ilastm1 + 1;
              while ((!firstNonZero) && (j + 1 > ifirst)) {
                istart = j + 1;
                ctemp.re = b_A_data[b_A_sizes_idx_0 * j + j].re - sigma2_re;
                ctemp.im = b_A_data[b_A_sizes_idx_0 * j + j].im - sigma2_im;
                anorm = (fabs(ctemp.re) + fabs(ctemp.im)) * sumsq;
                reAij = (fabs(b_A_data[b_A_sizes_idx_0 * j + jp1].re) + fabs
                         (b_A_data[b_A_sizes_idx_0 * j + jp1].im)) * sumsq;
                scale = anorm;
                if (reAij > anorm) {
                  scale = reAij;
                }

                if ((scale < 1.0) && (scale != 0.0)) {
                  anorm /= scale;
                  reAij /= scale;
                }

                if ((fabs(b_A_data[(j - 1) * b_A_sizes_idx_0 + j].re) + fabs
                     (b_A_data[(j - 1) * b_A_sizes_idx_0 + j].im)) * reAij <=
                    anorm * imAij) {
                  goto90 = true;
                  firstNonZero = true;
                } else {
                  jp1 = j;
                  j--;
                }
              }

              if (!goto90) {
                istart = ifirst;
                if (ilastm1 + 1 == ifirst) {
                  ctemp.re = rho_re;
                  ctemp.im = rho_im;
                } else {
                  ctemp.re = b_A_data[((ifirst - 1) * b_A_sizes_idx_0 + ifirst)
                    - 1].re - sigma2_re;
                  ctemp.im = b_A_data[((ifirst - 1) * b_A_sizes_idx_0 + ifirst)
                    - 1].im - sigma2_im;
                }

                goto90 = true;
              }
            }

            if (goto90) {
              goto90 = false;
              Helikopter__eml_matlab_zlartg_a(ctemp, b_A_data[istart +
                b_A_sizes_idx_0 * (istart - 1)], &reAij, &d);
              j = istart;
              jm1 = istart - 2;
              while (j < ilast + 1) {
                if (j > istart) {
                  Helikopter_ne_eml_matlab_zlartg(b_A_data[(j + b_A_sizes_idx_0 *
                    jm1) - 1], b_A_data[j + b_A_sizes_idx_0 * jm1], &reAij, &d,
                    &t1);
                  b_A_data[(j + b_A_sizes_idx_0 * jm1) - 1] = t1;
                  b_A_data[j + b_A_sizes_idx_0 * jm1].re = 0.0;
                  b_A_data[j + b_A_sizes_idx_0 * jm1].im = 0.0;
                }

                for (i = j - 1; i + 1 <= ilastm; i++) {
                  t1.re = b_A_data[(b_A_sizes_idx_0 * i + j) - 1].re * reAij +
                    (b_A_data[b_A_sizes_idx_0 * i + j].re * d.re -
                     b_A_data[b_A_sizes_idx_0 * i + j].im * d.im);
                  t1.im = b_A_data[(b_A_sizes_idx_0 * i + j) - 1].im * reAij +
                    (b_A_data[b_A_sizes_idx_0 * i + j].im * d.re +
                     b_A_data[b_A_sizes_idx_0 * i + j].re * d.im);
                  anorm = b_A_data[(b_A_sizes_idx_0 * i + j) - 1].im;
                  scale = b_A_data[(b_A_sizes_idx_0 * i + j) - 1].re;
                  b_A_data[j + b_A_sizes_idx_0 * i].re =
                    b_A_data[b_A_sizes_idx_0 * i + j].re * reAij - (b_A_data
                    [(b_A_sizes_idx_0 * i + j) - 1].re * d.re + b_A_data
                    [(b_A_sizes_idx_0 * i + j) - 1].im * d.im);
                  b_A_data[j + b_A_sizes_idx_0 * i].im =
                    b_A_data[b_A_sizes_idx_0 * i + j].im * reAij - (d.re * anorm
                    - d.im * scale);
                  b_A_data[(j + b_A_sizes_idx_0 * i) - 1] = t1;
                }

                d.re = -d.re;
                d.im = -d.im;
                i = j;
                if (ilast + 1 < j + 2) {
                  i = ilast - 1;
                }

                for (jp1 = ifrstm - 1; jp1 + 1 <= i + 2; jp1++) {
                  t1.re = (b_A_data[(j - 1) * b_A_sizes_idx_0 + jp1].re * d.re -
                           b_A_data[(j - 1) * b_A_sizes_idx_0 + jp1].im * d.im)
                    + b_A_data[b_A_sizes_idx_0 * j + jp1].re * reAij;
                  t1.im = (b_A_data[(j - 1) * b_A_sizes_idx_0 + jp1].im * d.re +
                           b_A_data[(j - 1) * b_A_sizes_idx_0 + jp1].re * d.im)
                    + b_A_data[b_A_sizes_idx_0 * j + jp1].im * reAij;
                  anorm = b_A_data[b_A_sizes_idx_0 * j + jp1].im;
                  scale = b_A_data[b_A_sizes_idx_0 * j + jp1].re;
                  b_A_data[jp1 + b_A_sizes_idx_0 * (j - 1)].re = b_A_data[(j - 1)
                    * b_A_sizes_idx_0 + jp1].re * reAij -
                    (b_A_data[b_A_sizes_idx_0 * j + jp1].re * d.re +
                     b_A_data[b_A_sizes_idx_0 * j + jp1].im * d.im);
                  b_A_data[jp1 + b_A_sizes_idx_0 * (j - 1)].im = b_A_data[(j - 1)
                    * b_A_sizes_idx_0 + jp1].im * reAij - (d.re * anorm - d.im *
                    scale);
                  b_A_data[jp1 + b_A_sizes_idx_0 * j] = t1;
                }

                jm1 = j - 1;
                j++;
              }
            }

            firstNonZero = true;
          }

          if (firstNonZero) {
            jiter++;
          }
        }
      } else {
        guard2 = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  } else {
    guard1 = true;
  }

  if (guard2) {
    if (failed) {
      *info = ilast + 1;
      for (jp1 = 0; jp1 + 1 <= ilast + 1; jp1++) {
        alpha1_data[jp1].re = (rtNaN);
        alpha1_data[jp1].im = 0.0;
        beta1_data[jp1].re = (rtNaN);
        beta1_data[jp1].im = 0.0;
      }
    } else {
      guard1 = true;
    }
  }

  if (guard1) {
    for (jp1 = 0; jp1 + 1 < ilo; jp1++) {
      alpha1_data[jp1] = b_A_data[b_A_sizes_idx_0 * jp1 + jp1];
    }
  }
}

/* Function for MATLAB Function: '<Root>/MATLAB Function1' */
static void Helikopter_new_eml_xgeev(const creal_T A_data[], const int32_T
  A_sizes[2], int32_T *info, creal_T alpha1_data[], int32_T *alpha1_sizes,
  creal_T beta1_data[], int32_T *beta1_sizes)
{
  real_T anrm;
  boolean_T ilascl;
  real_T anrmto;
  int32_T ilo;
  int32_T ihi;
  real_T cfromc;
  real_T ctoc;
  boolean_T notdone;
  real_T cto1;
  real_T mul;
  int32_T b_i;
  int32_T b_j;
  int32_T ii;
  int32_T nzcount;
  creal_T atmp;
  int32_T b_nzcount;
  creal_T s;
  real_T b_mul;
  int32_T exitg2;
  boolean_T exitg4;
  boolean_T exitg5;
  boolean_T guard1;
  int32_T i;
  creal_T b_A_data[25];
  int32_T b_A_sizes[2];
  creal_T c_A_data[25];
  creal_T alpha1_data_0;
  b_A_sizes[0] = A_sizes[0];
  b_A_sizes[1] = A_sizes[1];
  ii = A_sizes[0] * A_sizes[1];
  for (i = 0; i < ii; i++) {
    b_A_data[i] = A_data[i];
  }

  *info = 0;
  anrm = 0.0;
  ii = A_sizes[0] * A_sizes[1];
  nzcount = 0;
  notdone = false;
  while ((!notdone) && (nzcount <= ii - 1)) {
    cfromc = rt_hypotd_snf(A_data[nzcount].re, A_data[nzcount].im);
    if (rtIsNaN(cfromc)) {
      anrm = (rtNaN);
      notdone = true;
    } else {
      if (cfromc > anrm) {
        anrm = cfromc;
      }

      nzcount++;
    }
  }

  if (!((!rtIsInf(anrm)) && (!rtIsNaN(anrm)))) {
    *alpha1_sizes = A_sizes[0];
    ii = A_sizes[0];
    for (i = 0; i < ii; i++) {
      alpha1_data[i].re = (rtNaN);
      alpha1_data[i].im = 0.0;
    }

    *beta1_sizes = A_sizes[0];
    ii = A_sizes[0];
    for (i = 0; i < ii; i++) {
      beta1_data[i].re = (rtNaN);
      beta1_data[i].im = 0.0;
    }
  } else {
    ilascl = false;
    anrmto = anrm;
    if ((anrm > 0.0) && (anrm < 6.7178761075670888E-139)) {
      anrmto = 6.7178761075670888E-139;
      ilascl = true;
    } else {
      if (anrm > 1.4885657073574029E+138) {
        anrmto = 1.4885657073574029E+138;
        ilascl = true;
      }
    }

    if (ilascl) {
      cfromc = anrm;
      ctoc = anrmto;
      notdone = true;
      while (notdone) {
        b_mul = cfromc * 2.0041683600089728E-292;
        cto1 = ctoc / 4.9896007738368E+291;
        if ((b_mul > ctoc) && (ctoc != 0.0)) {
          mul = 2.0041683600089728E-292;
          cfromc = b_mul;
        } else if (cto1 > cfromc) {
          mul = 4.9896007738368E+291;
          ctoc = cto1;
        } else {
          mul = ctoc / cfromc;
          notdone = false;
        }

        ii = b_A_sizes[0] * b_A_sizes[1];
        for (i = 0; i < ii; i++) {
          atmp.re = mul * b_A_data[i].re;
          atmp.im = mul * b_A_data[i].im;
          b_A_data[i] = atmp;
        }
      }
    }

    ilo = 0;
    ihi = A_sizes[0];
    if (A_sizes[0] <= 1) {
      ihi = 1;
    } else {
      do {
        exitg2 = 0;
        b_i = 0;
        b_j = 0;
        notdone = false;
        ii = ihi;
        exitg5 = false;
        while ((!exitg5) && (ii > 0)) {
          nzcount = 0;
          b_i = ii;
          b_j = ihi;
          b_nzcount = 1;
          exitg4 = false;
          while ((!exitg4) && (b_nzcount <= ihi)) {
            guard1 = false;
            if ((b_A_data[((b_nzcount - 1) * b_A_sizes[0] + ii) - 1].re != 0.0) ||
                (b_A_data[((b_nzcount - 1) * b_A_sizes[0] + ii) - 1].im != 0.0) ||
                (ii == b_nzcount)) {
              if (nzcount == 0) {
                b_j = b_nzcount;
                nzcount = 1;
                guard1 = true;
              } else {
                nzcount = 2;
                exitg4 = true;
              }
            } else {
              guard1 = true;
            }

            if (guard1) {
              b_nzcount++;
            }
          }

          if (nzcount < 2) {
            notdone = true;
            exitg5 = true;
          } else {
            ii--;
          }
        }

        if (!notdone) {
          exitg2 = 2;
        } else {
          b_nzcount = b_A_sizes[0];
          nzcount = b_A_sizes[1];
          ii = b_A_sizes[0] * b_A_sizes[1];
          for (i = 0; i < ii; i++) {
            c_A_data[i] = b_A_data[i];
          }

          if (b_i != ihi) {
            for (ii = 0; ii + 1 <= b_A_sizes[0]; ii++) {
              atmp = c_A_data[(b_nzcount * ii + b_i) - 1];
              c_A_data[(b_i + b_nzcount * ii) - 1] = c_A_data[(b_nzcount * ii +
                ihi) - 1];
              c_A_data[(ihi + b_nzcount * ii) - 1] = atmp;
            }
          }

          if (b_j != ihi) {
            for (ii = 0; ii + 1 <= ihi; ii++) {
              atmp = c_A_data[(b_j - 1) * b_nzcount + ii];
              c_A_data[ii + b_nzcount * (b_j - 1)] = c_A_data[(ihi - 1) *
                b_nzcount + ii];
              c_A_data[ii + b_nzcount * (ihi - 1)] = atmp;
            }
          }

          ii = b_nzcount * nzcount;
          for (i = 0; i < ii; i++) {
            b_A_data[i] = c_A_data[i];
          }

          ihi--;
          if (ihi == 1) {
            exitg2 = 1;
          }
        }
      } while (exitg2 == 0);

      if (exitg2 != 1) {
        do {
          exitg2 = 0;
          b_i = 0;
          b_j = 0;
          notdone = false;
          nzcount = ilo + 1;
          exitg5 = false;
          while ((!exitg5) && (nzcount <= ihi)) {
            b_nzcount = 0;
            b_i = ihi;
            b_j = nzcount;
            ii = ilo + 1;
            exitg4 = false;
            while ((!exitg4) && (ii <= ihi)) {
              guard1 = false;
              if ((b_A_data[((nzcount - 1) * b_A_sizes[0] + ii) - 1].re != 0.0) ||
                  (b_A_data[((nzcount - 1) * b_A_sizes[0] + ii) - 1].im != 0.0) ||
                  (ii == nzcount)) {
                if (b_nzcount == 0) {
                  b_i = ii;
                  b_nzcount = 1;
                  guard1 = true;
                } else {
                  b_nzcount = 2;
                  exitg4 = true;
                }
              } else {
                guard1 = true;
              }

              if (guard1) {
                ii++;
              }
            }

            if (b_nzcount < 2) {
              notdone = true;
              exitg5 = true;
            } else {
              nzcount++;
            }
          }

          if (!notdone) {
            exitg2 = 1;
          } else {
            b_nzcount = b_A_sizes[0];
            nzcount = b_A_sizes[1];
            ii = b_A_sizes[0] * b_A_sizes[1];
            for (i = 0; i < ii; i++) {
              c_A_data[i] = b_A_data[i];
            }

            if (ilo + 1 != b_i) {
              for (ii = ilo; ii + 1 <= b_A_sizes[0]; ii++) {
                atmp = c_A_data[(b_nzcount * ii + b_i) - 1];
                c_A_data[(b_i + b_nzcount * ii) - 1] = c_A_data[b_nzcount * ii +
                  ilo];
                c_A_data[ilo + b_nzcount * ii] = atmp;
              }
            }

            if (ilo + 1 != b_j) {
              for (ii = 0; ii + 1 <= ihi; ii++) {
                atmp = c_A_data[(b_j - 1) * b_nzcount + ii];
                c_A_data[ii + b_nzcount * (b_j - 1)] = c_A_data[b_nzcount * ilo
                  + ii];
                c_A_data[ii + b_nzcount * ilo] = atmp;
              }
            }

            ii = b_nzcount * nzcount;
            for (i = 0; i < ii; i++) {
              b_A_data[i] = c_A_data[i];
            }

            ilo++;
            if (ilo + 1 == ihi) {
              exitg2 = 1;
            }
          }
        } while (exitg2 == 0);
      }
    }

    if (!((A_sizes[0] <= 1) || (ihi < ilo + 3))) {
      for (nzcount = ilo; nzcount + 1 < ihi - 1; nzcount++) {
        for (b_nzcount = ihi - 1; b_nzcount + 1 > nzcount + 2; b_nzcount--) {
          Helikopter_ne_eml_matlab_zlartg(b_A_data[(b_nzcount + b_A_sizes[0] *
            nzcount) - 1], b_A_data[b_nzcount + b_A_sizes[0] * nzcount], &cfromc,
            &s, &atmp);
          b_A_data[(b_nzcount + b_A_sizes[0] * nzcount) - 1] = atmp;
          b_A_data[b_nzcount + b_A_sizes[0] * nzcount].re = 0.0;
          b_A_data[b_nzcount + b_A_sizes[0] * nzcount].im = 0.0;
          for (ii = nzcount + 1; ii + 1 <= ihi; ii++) {
            atmp.re = b_A_data[(b_A_sizes[0] * ii + b_nzcount) - 1].re * cfromc
              + (b_A_data[b_A_sizes[0] * ii + b_nzcount].re * s.re -
                 b_A_data[b_A_sizes[0] * ii + b_nzcount].im * s.im);
            atmp.im = b_A_data[(b_A_sizes[0] * ii + b_nzcount) - 1].im * cfromc
              + (b_A_data[b_A_sizes[0] * ii + b_nzcount].im * s.re +
                 b_A_data[b_A_sizes[0] * ii + b_nzcount].re * s.im);
            ctoc = b_A_data[(b_A_sizes[0] * ii + b_nzcount) - 1].im;
            b_mul = b_A_data[(b_A_sizes[0] * ii + b_nzcount) - 1].re;
            b_A_data[b_nzcount + b_A_sizes[0] * ii].re = b_A_data[b_A_sizes[0] *
              ii + b_nzcount].re * cfromc - (b_A_data[(b_A_sizes[0] * ii +
              b_nzcount) - 1].re * s.re + b_A_data[(b_A_sizes[0] * ii +
              b_nzcount) - 1].im * s.im);
            b_A_data[b_nzcount + b_A_sizes[0] * ii].im = b_A_data[b_A_sizes[0] *
              ii + b_nzcount].im * cfromc - (s.re * ctoc - s.im * b_mul);
            b_A_data[(b_nzcount + b_A_sizes[0] * ii) - 1] = atmp;
          }

          s.re = -s.re;
          s.im = -s.im;
          for (ii = ilo; ii + 1 <= ihi; ii++) {
            atmp.re = (b_A_data[(b_nzcount - 1) * b_A_sizes[0] + ii].re * s.re -
                       b_A_data[(b_nzcount - 1) * b_A_sizes[0] + ii].im * s.im)
              + b_A_data[b_A_sizes[0] * b_nzcount + ii].re * cfromc;
            atmp.im = (b_A_data[(b_nzcount - 1) * b_A_sizes[0] + ii].im * s.re +
                       b_A_data[(b_nzcount - 1) * b_A_sizes[0] + ii].re * s.im)
              + b_A_data[b_A_sizes[0] * b_nzcount + ii].im * cfromc;
            ctoc = b_A_data[b_A_sizes[0] * b_nzcount + ii].im;
            b_mul = b_A_data[b_A_sizes[0] * b_nzcount + ii].re;
            b_A_data[ii + b_A_sizes[0] * (b_nzcount - 1)].re = b_A_data
              [(b_nzcount - 1) * b_A_sizes[0] + ii].re * cfromc -
              (b_A_data[b_A_sizes[0] * b_nzcount + ii].re * s.re +
               b_A_data[b_A_sizes[0] * b_nzcount + ii].im * s.im);
            b_A_data[ii + b_A_sizes[0] * (b_nzcount - 1)].im = b_A_data
              [(b_nzcount - 1) * b_A_sizes[0] + ii].im * cfromc - (s.re * ctoc -
              s.im * b_mul);
            b_A_data[ii + b_A_sizes[0] * b_nzcount] = atmp;
          }
        }
      }
    }

    Helikopter_ne_eml_matlab_zhgeqz(b_A_data, b_A_sizes, ilo + 1, ihi, info,
      alpha1_data, alpha1_sizes, beta1_data, beta1_sizes);
    if (!((*info != 0) || (!ilascl))) {
      notdone = true;
      while (notdone) {
        cfromc = anrmto * 2.0041683600089728E-292;
        ctoc = anrm / 4.9896007738368E+291;
        if ((cfromc > anrm) && (anrm != 0.0)) {
          b_mul = 2.0041683600089728E-292;
          anrmto = cfromc;
        } else if (ctoc > anrmto) {
          b_mul = 4.9896007738368E+291;
          anrm = ctoc;
        } else {
          b_mul = anrm / anrmto;
          notdone = false;
        }

        for (i = 0; i < *alpha1_sizes; i++) {
          alpha1_data_0.re = b_mul * alpha1_data[i].re;
          alpha1_data_0.im = b_mul * alpha1_data[i].im;
          alpha1_data[i] = alpha1_data_0;
        }
      }
    }
  }
}

/* Function for MATLAB Function: '<Root>/MATLAB Function1' */
static void Helikopter_new_roots(const real_T c[6], creal_T r_data[], int32_T
  *r_sizes)
{
  int32_T k1;
  int32_T k2;
  int32_T companDim;
  real_T ctmp[6];
  int32_T j;
  boolean_T exitg1;
  boolean_T exitg2;
  creal_T a_data[25];
  creal_T eiga_data[5];
  int32_T eiga_sizes;
  creal_T beta1_data[5];
  creal_T a_data_0[25];
  int32_T a_sizes[2];
  real_T brm;
  real_T bim;
  real_T d;
  creal_T eiga_data_0;
  for (k1 = 0; k1 < 5; k1++) {
    r_data[k1].re = 0.0;
    r_data[k1].im = 0.0;
  }

  k1 = 1;
  while ((k1 <= 6) && (!(c[k1 - 1] != 0.0))) {
    k1++;
  }

  k2 = 6;
  while ((k2 >= k1) && (!(c[k2 - 1] != 0.0))) {
    k2--;
  }

  if (k1 < k2) {
    companDim = k2 - k1;
    exitg1 = false;
    while ((!exitg1) && (companDim > 0)) {
      j = 0;
      exitg2 = false;
      while ((!exitg2) && (j + 1 <= companDim)) {
        ctmp[j] = c[k1 + j] / c[k1 - 1];
        if (rtIsInf(fabs(ctmp[j]))) {
          exitg2 = true;
        } else {
          j++;
        }
      }

      if (j + 1 > companDim) {
        exitg1 = true;
      } else {
        k1++;
        companDim--;
      }
    }

    if (companDim < 1) {
      if (1 > 6 - k2) {
        *r_sizes = 0;
      } else {
        *r_sizes = 6 - k2;
      }
    } else {
      j = companDim * companDim;
      for (k1 = 0; k1 < j; k1++) {
        a_data[k1].re = 0.0;
        a_data[k1].im = 0.0;
      }

      for (k1 = 0; k1 + 1 < companDim; k1++) {
        a_data[companDim * k1].re = -ctmp[k1];
        a_data[companDim * k1].im = 0.0;
        a_data[(k1 + companDim * k1) + 1].re = 1.0;
        a_data[(k1 + companDim * k1) + 1].im = 0.0;
      }

      a_data[companDim * (companDim - 1)].re = -ctmp[companDim - 1];
      a_data[companDim * (companDim - 1)].im = 0.0;
      for (k1 = 1; k1 <= 6 - k2; k1++) {
        r_data[k1 - 1].re = 0.0;
        r_data[k1 - 1].im = 0.0;
      }

      a_sizes[0] = companDim;
      a_sizes[1] = companDim;
      j = companDim * companDim;
      for (k1 = 0; k1 < j; k1++) {
        a_data_0[k1] = a_data[k1];
      }

      Helikopter_new_eml_xgeev(a_data_0, a_sizes, &k1, eiga_data, &eiga_sizes,
        beta1_data, &j);
      for (k1 = 0; k1 < eiga_sizes; k1++) {
        if (beta1_data[k1].im == 0.0) {
          if (eiga_data[k1].im == 0.0) {
            eiga_data_0.re = eiga_data[k1].re / beta1_data[k1].re;
            eiga_data_0.im = 0.0;
          } else if (eiga_data[k1].re == 0.0) {
            eiga_data_0.re = 0.0;
            eiga_data_0.im = eiga_data[k1].im / beta1_data[k1].re;
          } else {
            eiga_data_0.re = eiga_data[k1].re / beta1_data[k1].re;
            eiga_data_0.im = eiga_data[k1].im / beta1_data[k1].re;
          }
        } else if (beta1_data[k1].re == 0.0) {
          if (eiga_data[k1].re == 0.0) {
            eiga_data_0.re = eiga_data[k1].im / beta1_data[k1].im;
            eiga_data_0.im = 0.0;
          } else if (eiga_data[k1].im == 0.0) {
            eiga_data_0.re = 0.0;
            eiga_data_0.im = -(eiga_data[k1].re / beta1_data[k1].im);
          } else {
            eiga_data_0.re = eiga_data[k1].im / beta1_data[k1].im;
            eiga_data_0.im = -(eiga_data[k1].re / beta1_data[k1].im);
          }
        } else {
          brm = fabs(beta1_data[k1].re);
          bim = fabs(beta1_data[k1].im);
          if (brm > bim) {
            bim = beta1_data[k1].im / beta1_data[k1].re;
            d = bim * beta1_data[k1].im + beta1_data[k1].re;
            eiga_data_0.re = (bim * eiga_data[k1].im + eiga_data[k1].re) / d;
            eiga_data_0.im = (eiga_data[k1].im - bim * eiga_data[k1].re) / d;
          } else if (bim == brm) {
            bim = beta1_data[k1].re > 0.0 ? 0.5 : -0.5;
            d = beta1_data[k1].im > 0.0 ? 0.5 : -0.5;
            eiga_data_0.re = (eiga_data[k1].re * bim + eiga_data[k1].im * d) /
              brm;
            eiga_data_0.im = (eiga_data[k1].im * bim - eiga_data[k1].re * d) /
              brm;
          } else {
            bim = beta1_data[k1].re / beta1_data[k1].im;
            d = bim * beta1_data[k1].re + beta1_data[k1].im;
            eiga_data_0.re = (bim * eiga_data[k1].re + eiga_data[k1].im) / d;
            eiga_data_0.im = (bim * eiga_data[k1].im - eiga_data[k1].re) / d;
          }
        }

        eiga_data[k1] = eiga_data_0;
      }

      for (k1 = 1; k1 <= companDim; k1++) {
        r_data[(k1 - k2) + 5] = eiga_data[k1 - 1];
      }

      *r_sizes = (companDim - k2) + 6;
    }
  } else if (1 > 6 - k2) {
    *r_sizes = 0;
  } else {
    *r_sizes = 6 - k2;
  }
}

/* Model output function */
void Helikopter_new_output(void)
{
  static const real_T wsp_M_V[6] = { -2.51456949125462E-14, 2.95925329869355E-12,
    8.13117134030781E-9, 5.04070403383922E-7, 0.000115101236471819,
    0.000278330284083194 };

  real_T rtb_Gain1[3];
  real_T rtb_ManualSwitch1;
  real_T rtb_Gain4[3];
  real_T wsp_M_V_0[6];
  real_T tmp[6];
  creal_T unusedOutput_data[5];
  int32_T unusedOutput_sizes;
  if (rtmIsMajorTimeStep(Helikopter_new_M)) {
    /* set solver stop time */
    if (!(Helikopter_new_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Helikopter_new_M->solverInfo,
                            ((Helikopter_new_M->Timing.clockTickH0 + 1) *
        Helikopter_new_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Helikopter_new_M->solverInfo,
                            ((Helikopter_new_M->Timing.clockTick0 + 1) *
        Helikopter_new_M->Timing.stepSize0 +
        Helikopter_new_M->Timing.clockTickH0 *
        Helikopter_new_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Helikopter_new_M)) {
    Helikopter_new_M->Timing.t[0] = rtsiGetT(&Helikopter_new_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(Helikopter_new_M)) {
    /* Level2 S-Function Block: '<S5>/Encoder' (TRAS_Encoder) */
    {
      SimStruct *rts = Helikopter_new_M->childSfunctions[0];
      sfcnOutputs(rts, 1);
    }

    /* Gain: '<S5>/Convert to rad' incorporates:
     *  Gain: '<S5>/Encoder 1024 PPR'
     */
    Helikopter_new_B.Converttorad[0] = Helikopter_new_P.Encoder1024PPR_Gain *
      Helikopter_new_B.Encoder[0] * Helikopter_new_P.Converttorad_Gain;
    Helikopter_new_B.Converttorad[1] = Helikopter_new_P.Encoder1024PPR_Gain *
      Helikopter_new_B.Encoder[1] * Helikopter_new_P.Converttorad_Gain;

    /* Level2 S-Function Block: '<S5>/Analog Input' (TRAS_AnalogInput) */
    {
      SimStruct *rts = Helikopter_new_M->childSfunctions[1];
      sfcnOutputs(rts, 1);
    }

    /* Gain: '<S5>/Convert to RPM1' incorporates:
     *  Polyval: '<S5>/Polynomial'
     */
    Helikopter_new_B.ConverttoRPM1[0] = (Helikopter_new_P.wsp_V[0] *
      Helikopter_new_B.AnalogInput[0] + Helikopter_new_P.wsp_V[1]) *
      Helikopter_new_P.ConverttoRPM1_Gain;
    Helikopter_new_B.ConverttoRPM1[1] = (Helikopter_new_P.wsp_V[0] *
      Helikopter_new_B.AnalogInput[1] + Helikopter_new_P.wsp_V[1]) *
      Helikopter_new_P.ConverttoRPM1_Gain;

    /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
     *  Constant: '<Root>/Constant'
     */
    /* MATLAB Function 'MATLAB Function1': '<S1>:1' */
    /*  const = load('Lin_simulink_test.mat'); */
    /* '<S1>:1:7' */
    /* '<S1>:1:10' */
    for (unusedOutput_sizes = 0; unusedOutput_sizes < 5; unusedOutput_sizes++) {
      tmp[unusedOutput_sizes] = 0.0;
    }

    tmp[5] = sin(Helikopter_new_P.Constant_Value - -0.5223) * -0.3068;
    for (unusedOutput_sizes = 0; unusedOutput_sizes < 6; unusedOutput_sizes++) {
      wsp_M_V_0[unusedOutput_sizes] = wsp_M_V[unusedOutput_sizes] +
        tmp[unusedOutput_sizes];
    }

    Helikopter_new_roots(wsp_M_V_0, unusedOutput_data, &unusedOutput_sizes);

    /* End of MATLAB Function: '<Root>/MATLAB Function1' */

    /* Gain: '<Root>/Gain5' */
    /* '<S1>:1:12' */
    /* '<S1>:1:13' */
    /* '<S1>:1:14' */
    /* '<S1>:1:15' */
    Helikopter_new_B.Gain5 = Helikopter_new_P.Gain5_Gain *
      Helikopter_new_B.Converttorad[1];

    /* Sum: '<Root>/Sum3' incorporates:
     *  Constant: '<Root>/Constant'
     */
    Helikopter_new_B.Sum3 = Helikopter_new_P.Constant_Value -
      Helikopter_new_B.Gain5;

    /* Sum: '<Root>/Sum5' */
    Helikopter_new_B.Sum5 = 0.0;

    /* Sum: '<Root>/Sum4' incorporates:
     *  Constant: '<Root>/Constant10'
     */
    Helikopter_new_B.Sum4 = Helikopter_new_P.lin_w_v -
      Helikopter_new_B.ConverttoRPM1[1];

    /* Sum: '<Root>/Sum14' incorporates:
     *  Constant: '<Root>/Constant'
     *  Constant: '<Root>/Constant4'
     */
    Helikopter_new_B.Sum14 = Helikopter_new_P.Constant_Value -
      Helikopter_new_P.lin_alpha_v;
  }

  /* Integrator: '<Root>/Integrator' */
  Helikopter_new_B.Integrator[0] = Helikopter_new_X.Integrator_CSTATE[0];
  Helikopter_new_B.Integrator[1] = Helikopter_new_X.Integrator_CSTATE[1];
  Helikopter_new_B.Integrator[2] = Helikopter_new_X.Integrator_CSTATE[2];
  if (rtmIsMajorTimeStep(Helikopter_new_M)) {
    /* Sum: '<Root>/Sum15' incorporates:
     *  Constant: '<Root>/Constant10'
     *  Constant: '<Root>/Constant7'
     */
    Helikopter_new_B.Sum15 = Helikopter_new_P.lin_w_v - Helikopter_new_P.lin_w_v;
  }

  /* ManualSwitch: '<Root>/Manual Switch' incorporates:
   *  Gain: '<Root>/Gain6'
   *  Sum: '<Root>/Sum12'
   *  Sum: '<Root>/Sum13'
   */
  if (Helikopter_new_P.ManualSwitch_CurrentSetting == 1) {
    rtb_Gain1[0] = Helikopter_new_B.Sum3;
    rtb_Gain1[1] = Helikopter_new_B.Sum5;
    rtb_Gain1[2] = Helikopter_new_B.Sum4;
  } else {
    rtb_Gain1[0] = (Helikopter_new_B.Sum14 + Helikopter_new_B.Integrator[0]) *
      Helikopter_new_P.Gain6_Gain;
    rtb_Gain1[1] = Helikopter_new_P.Gain6_Gain * Helikopter_new_B.Integrator[1];
    rtb_Gain1[2] = (Helikopter_new_B.Sum15 + Helikopter_new_B.Integrator[2]) *
      Helikopter_new_P.Gain6_Gain;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch' */

  /* Gain: '<Root>/Gain' */
  Helikopter_new_B.Gain = (Helikopter_new_P.K_lqr[0] * rtb_Gain1[0] +
    Helikopter_new_P.K_lqr[1] * rtb_Gain1[1]) + Helikopter_new_P.K_lqr[2] *
    rtb_Gain1[2];
  if (rtmIsMajorTimeStep(Helikopter_new_M)) {
  }

  /* Sum: '<Root>/Sum16' incorporates:
   *  Constant: '<Root>/Constant5'
   */
  Helikopter_new_B.Sum16 = Helikopter_new_P.lin_alpha_v +
    Helikopter_new_B.Integrator[0];
  if (rtmIsMajorTimeStep(Helikopter_new_M)) {
  }

  /* Sum: '<Root>/Sum17' incorporates:
   *  Constant: '<Root>/Constant6'
   */
  Helikopter_new_B.Sum17 = Helikopter_new_B.Integrator[2] +
    Helikopter_new_P.lin_w_v;
  if (rtmIsMajorTimeStep(Helikopter_new_M)) {
  }

  /* Gain: '<Root>/Gain1' incorporates:
   *  Sum: '<Root>/Sum11'
   */
  rtb_Gain1[0] = Helikopter_new_P.lin_B[0] * Helikopter_new_B.Gain;
  rtb_Gain1[1] = Helikopter_new_P.lin_B[1] * Helikopter_new_B.Gain;
  rtb_Gain1[2] = Helikopter_new_P.lin_B[2] * Helikopter_new_B.Gain;
  if (rtmIsMajorTimeStep(Helikopter_new_M)) {
    /* Sum: '<Root>/Sum9' incorporates:
     *  Constant: '<Root>/Constant'
     */
    Helikopter_new_B.Sum9 = Helikopter_new_B.Gain5 -
      Helikopter_new_P.Constant_Value;
  }

  /* Sum: '<Root>/Sum8' incorporates:
   *  Gain: '<Root>/Gain3'
   */
  rtb_ManualSwitch1 = Helikopter_new_B.Sum9 - ((Helikopter_new_P.lin_C[0] *
    Helikopter_new_B.Integrator[0] + Helikopter_new_P.lin_C[1] *
    Helikopter_new_B.Integrator[1]) + Helikopter_new_P.lin_C[2] *
    Helikopter_new_B.Integrator[2]);

  /* Gain: '<Root>/Gain4' */
  rtb_Gain4[0] = Helikopter_new_P.L[0] * rtb_ManualSwitch1;
  rtb_Gain4[1] = Helikopter_new_P.L[1] * rtb_ManualSwitch1;
  rtb_Gain4[2] = Helikopter_new_P.L[2] * rtb_ManualSwitch1;
  if (rtmIsMajorTimeStep(Helikopter_new_M)) {
    /* Gain: '<S4>/Slider Gain' incorporates:
     *  Constant: '<Root>/Pitch Ctrl1'
     */
    Helikopter_new_B.SliderGain = Helikopter_new_P.SliderGain2_gain *
      Helikopter_new_P.PitchCtrl1_Value;
  }

  /* ManualSwitch: '<Root>/Manual Switch1' incorporates:
   *  Constant: '<Root>/Constant11'
   */
  if (Helikopter_new_P.ManualSwitch1_CurrentSetting == 1) {
    rtb_ManualSwitch1 = Helikopter_new_P.Constant11_Value;
  } else {
    /* Sum: '<Root>/Sum6' */
    rtb_ManualSwitch1 = Helikopter_new_B.SliderGain + Helikopter_new_B.Gain;

    /* Saturate: '<Root>/Saturation' */
    if (rtb_ManualSwitch1 > Helikopter_new_P.Saturation_UpperSat) {
      rtb_ManualSwitch1 = Helikopter_new_P.Saturation_UpperSat;
    } else {
      if (rtb_ManualSwitch1 < Helikopter_new_P.Saturation_LowerSat) {
        rtb_ManualSwitch1 = Helikopter_new_P.Saturation_LowerSat;
      }
    }

    /* End of Saturate: '<Root>/Saturation' */
  }

  /* End of ManualSwitch: '<Root>/Manual Switch1' */
  if (rtmIsMajorTimeStep(Helikopter_new_M)) {
    /* ManualSwitch: '<Root>/Reset Encoders' incorporates:
     *  Constant: '<Root>/Normal'
     *  Constant: '<Root>/Reset'
     */
    if (Helikopter_new_P.ResetEncoders_CurrentSetting == 1) {
      Helikopter_new_B.ResetEncoders = Helikopter_new_P.Reset_Value;
    } else {
      Helikopter_new_B.ResetEncoders = Helikopter_new_P.Normal_Value;
    }

    /* End of ManualSwitch: '<Root>/Reset Encoders' */

    /* Gain: '<S2>/Slider Gain' incorporates:
     *  Constant: '<Root>/Azimuth Ctrl'
     */
    Helikopter_new_B.SliderGain_l = Helikopter_new_P.SliderGain_gain *
      Helikopter_new_P.AzimuthCtrl_Value;
  }

  /* Sum: '<Root>/Sum7' incorporates:
   *  Gain: '<Root>/Gain2'
   */
  for (unusedOutput_sizes = 0; unusedOutput_sizes < 3; unusedOutput_sizes++) {
    Helikopter_new_B.Sum7[unusedOutput_sizes] =
      ((Helikopter_new_P.lin_A[unusedOutput_sizes + 3] *
        Helikopter_new_B.Integrator[1] +
        Helikopter_new_P.lin_A[unusedOutput_sizes] *
        Helikopter_new_B.Integrator[0]) +
       Helikopter_new_P.lin_A[unusedOutput_sizes + 6] *
       Helikopter_new_B.Integrator[2]) + (rtb_Gain4[unusedOutput_sizes] +
      rtb_Gain1[unusedOutput_sizes]);
  }

  /* End of Sum: '<Root>/Sum7' */

  /* Saturate: '<S5>/Saturation' */
  if (Helikopter_new_B.SliderGain_l > Helikopter_new_P.Saturation_UpperSat_a) {
    Helikopter_new_B.Saturation[0] = Helikopter_new_P.Saturation_UpperSat_a;
  } else if (Helikopter_new_B.SliderGain_l <
             Helikopter_new_P.Saturation_LowerSat_o) {
    Helikopter_new_B.Saturation[0] = Helikopter_new_P.Saturation_LowerSat_o;
  } else {
    Helikopter_new_B.Saturation[0] = Helikopter_new_B.SliderGain_l;
  }

  if (rtb_ManualSwitch1 > Helikopter_new_P.Saturation_UpperSat_a) {
    Helikopter_new_B.Saturation[1] = Helikopter_new_P.Saturation_UpperSat_a;
  } else if (rtb_ManualSwitch1 < Helikopter_new_P.Saturation_LowerSat_o) {
    Helikopter_new_B.Saturation[1] = Helikopter_new_P.Saturation_LowerSat_o;
  } else {
    Helikopter_new_B.Saturation[1] = rtb_ManualSwitch1;
  }

  /* End of Saturate: '<S5>/Saturation' */
  if (rtmIsMajorTimeStep(Helikopter_new_M)) {
    /* Level2 S-Function Block: '<S5>/PWM' (TRAS_PWM) */
    {
      SimStruct *rts = Helikopter_new_M->childSfunctions[2];
      sfcnOutputs(rts, 1);
    }

    /* Level2 S-Function Block: '<S5>/ResetEncoder' (TRAS_ResetEncoder) */
    {
      SimStruct *rts = Helikopter_new_M->childSfunctions[3];
      sfcnOutputs(rts, 1);
    }

    /* Level2 S-Function Block: '<S5>/Bitstream Version' (TRAS_BitstreamVersion) */
    {
      SimStruct *rts = Helikopter_new_M->childSfunctions[4];
      sfcnOutputs(rts, 1);
    }

    /* Level2 S-Function Block: '<S5>/Therm Status' (TRAS_PWMTherm) */
    {
      SimStruct *rts = Helikopter_new_M->childSfunctions[5];
      sfcnOutputs(rts, 1);
    }

    /* Constant: '<S5>/PWMPrescalerSource' */
    Helikopter_new_B.PWMPrescalerSource[0] =
      Helikopter_new_P.PWMPrescalerSource_Value[0];
    Helikopter_new_B.PWMPrescalerSource[1] =
      Helikopter_new_P.PWMPrescalerSource_Value[1];

    /* Level2 S-Function Block: '<S5>/PWMPrescaler' (TRAS_PWMPrescaler) */
    {
      SimStruct *rts = Helikopter_new_M->childSfunctions[6];
      sfcnOutputs(rts, 1);
    }

    /* Constant: '<S5>/ThermFlagSource' */
    Helikopter_new_B.ThermFlagSource[0] =
      Helikopter_new_P.ThermFlagSource_Value[0];
    Helikopter_new_B.ThermFlagSource[1] =
      Helikopter_new_P.ThermFlagSource_Value[1];

    /* Level2 S-Function Block: '<S5>/ThermFlag ' (TRAS_ThermFlag) */
    {
      SimStruct *rts = Helikopter_new_M->childSfunctions[7];
      sfcnOutputs(rts, 1);
    }
  }
}

/* Model update function */
void Helikopter_new_update(void)
{
  if (rtmIsMajorTimeStep(Helikopter_new_M)) {
    rt_ertODEUpdateContinuousStates(&Helikopter_new_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Helikopter_new_M->Timing.clockTick0)) {
    ++Helikopter_new_M->Timing.clockTickH0;
  }

  Helikopter_new_M->Timing.t[0] = rtsiGetSolverStopTime
    (&Helikopter_new_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Helikopter_new_M->Timing.clockTick1)) {
      ++Helikopter_new_M->Timing.clockTickH1;
    }

    Helikopter_new_M->Timing.t[1] = Helikopter_new_M->Timing.clockTick1 *
      Helikopter_new_M->Timing.stepSize1 + Helikopter_new_M->Timing.clockTickH1 *
      Helikopter_new_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void Helikopter_new_derivatives(void)
{
  XDot_Helikopter_new_T *_rtXdot;
  _rtXdot = ((XDot_Helikopter_new_T *) Helikopter_new_M->ModelData.derivs);

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE[0] = Helikopter_new_B.Sum7[0];
  _rtXdot->Integrator_CSTATE[1] = Helikopter_new_B.Sum7[1];
  _rtXdot->Integrator_CSTATE[2] = Helikopter_new_B.Sum7[2];
}

/* Model initialize function */
void Helikopter_new_initialize(void)
{
  /* Start for Constant: '<S5>/PWMPrescalerSource' */
  Helikopter_new_B.PWMPrescalerSource[0] =
    Helikopter_new_P.PWMPrescalerSource_Value[0];
  Helikopter_new_B.PWMPrescalerSource[1] =
    Helikopter_new_P.PWMPrescalerSource_Value[1];

  /* Start for Constant: '<S5>/ThermFlagSource' */
  Helikopter_new_B.ThermFlagSource[0] = Helikopter_new_P.ThermFlagSource_Value[0];
  Helikopter_new_B.ThermFlagSource[1] = Helikopter_new_P.ThermFlagSource_Value[1];

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  Helikopter_new_X.Integrator_CSTATE[0] = Helikopter_new_P.Integrator_IC[0];
  Helikopter_new_X.Integrator_CSTATE[1] = Helikopter_new_P.Integrator_IC[1];
  Helikopter_new_X.Integrator_CSTATE[2] = Helikopter_new_P.Integrator_IC[2];
}

/* Model terminate function */
void Helikopter_new_terminate(void)
{
  /* Level2 S-Function Block: '<S5>/Encoder' (TRAS_Encoder) */
  {
    SimStruct *rts = Helikopter_new_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S5>/Analog Input' (TRAS_AnalogInput) */
  {
    SimStruct *rts = Helikopter_new_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S5>/PWM' (TRAS_PWM) */
  {
    SimStruct *rts = Helikopter_new_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S5>/ResetEncoder' (TRAS_ResetEncoder) */
  {
    SimStruct *rts = Helikopter_new_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S5>/Bitstream Version' (TRAS_BitstreamVersion) */
  {
    SimStruct *rts = Helikopter_new_M->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S5>/Therm Status' (TRAS_PWMTherm) */
  {
    SimStruct *rts = Helikopter_new_M->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S5>/PWMPrescaler' (TRAS_PWMPrescaler) */
  {
    SimStruct *rts = Helikopter_new_M->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S5>/ThermFlag ' (TRAS_ThermFlag) */
  {
    SimStruct *rts = Helikopter_new_M->childSfunctions[7];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  Helikopter_new_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Helikopter_new_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  Helikopter_new_initialize();
}

void MdlTerminate(void)
{
  Helikopter_new_terminate();
}

/* Registration function */
RT_MODEL_Helikopter_new_T *Helikopter_new(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Helikopter_new_M, 0,
                sizeof(RT_MODEL_Helikopter_new_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Helikopter_new_M->solverInfo,
                          &Helikopter_new_M->Timing.simTimeStep);
    rtsiSetTPtr(&Helikopter_new_M->solverInfo, &rtmGetTPtr(Helikopter_new_M));
    rtsiSetStepSizePtr(&Helikopter_new_M->solverInfo,
                       &Helikopter_new_M->Timing.stepSize0);
    rtsiSetdXPtr(&Helikopter_new_M->solverInfo,
                 &Helikopter_new_M->ModelData.derivs);
    rtsiSetContStatesPtr(&Helikopter_new_M->solverInfo, (real_T **)
                         &Helikopter_new_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&Helikopter_new_M->solverInfo,
      &Helikopter_new_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&Helikopter_new_M->solverInfo, (&rtmGetErrorStatus
      (Helikopter_new_M)));
    rtsiSetRTModelPtr(&Helikopter_new_M->solverInfo, Helikopter_new_M);
  }

  rtsiSetSimTimeStep(&Helikopter_new_M->solverInfo, MAJOR_TIME_STEP);
  Helikopter_new_M->ModelData.intgData.y = Helikopter_new_M->ModelData.odeY;
  Helikopter_new_M->ModelData.intgData.f[0] = Helikopter_new_M->ModelData.odeF[0];
  Helikopter_new_M->ModelData.intgData.f[1] = Helikopter_new_M->ModelData.odeF[1];
  Helikopter_new_M->ModelData.intgData.f[2] = Helikopter_new_M->ModelData.odeF[2];
  Helikopter_new_M->ModelData.intgData.f[3] = Helikopter_new_M->ModelData.odeF[3];
  Helikopter_new_M->ModelData.intgData.f[4] = Helikopter_new_M->ModelData.odeF[4];
  Helikopter_new_M->ModelData.intgData.f[5] = Helikopter_new_M->ModelData.odeF[5];
  Helikopter_new_M->ModelData.contStates = ((real_T *) &Helikopter_new_X);
  rtsiSetSolverData(&Helikopter_new_M->solverInfo, (void *)
                    &Helikopter_new_M->ModelData.intgData);
  rtsiSetSolverName(&Helikopter_new_M->solverInfo,"ode5");
  Helikopter_new_M->solverInfoPtr = (&Helikopter_new_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Helikopter_new_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    Helikopter_new_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Helikopter_new_M->Timing.sampleTimes =
      (&Helikopter_new_M->Timing.sampleTimesArray[0]);
    Helikopter_new_M->Timing.offsetTimes =
      (&Helikopter_new_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Helikopter_new_M->Timing.sampleTimes[0] = (0.0);
    Helikopter_new_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    Helikopter_new_M->Timing.offsetTimes[0] = (0.0);
    Helikopter_new_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Helikopter_new_M, &Helikopter_new_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Helikopter_new_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Helikopter_new_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Helikopter_new_M, -1);
  Helikopter_new_M->Timing.stepSize0 = 0.001;
  Helikopter_new_M->Timing.stepSize1 = 0.001;

  /* External mode info */
  Helikopter_new_M->Sizes.checksums[0] = (1696475679U);
  Helikopter_new_M->Sizes.checksums[1] = (2786502830U);
  Helikopter_new_M->Sizes.checksums[2] = (2461680667U);
  Helikopter_new_M->Sizes.checksums[3] = (1217827392U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[6];
    Helikopter_new_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Helikopter_new_M->extModeInfo,
      &Helikopter_new_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Helikopter_new_M->extModeInfo,
                        Helikopter_new_M->Sizes.checksums);
    rteiSetTPtr(Helikopter_new_M->extModeInfo, rtmGetTPtr(Helikopter_new_M));
  }

  Helikopter_new_M->solverInfoPtr = (&Helikopter_new_M->solverInfo);
  Helikopter_new_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&Helikopter_new_M->solverInfo, 0.001);
  rtsiSetSolverMode(&Helikopter_new_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Helikopter_new_M->ModelData.blockIO = ((void *) &Helikopter_new_B);

  {
    Helikopter_new_B.Encoder[0] = 0.0;
    Helikopter_new_B.Encoder[1] = 0.0;
    Helikopter_new_B.Converttorad[0] = 0.0;
    Helikopter_new_B.Converttorad[1] = 0.0;
    Helikopter_new_B.AnalogInput[0] = 0.0;
    Helikopter_new_B.AnalogInput[1] = 0.0;
    Helikopter_new_B.ConverttoRPM1[0] = 0.0;
    Helikopter_new_B.ConverttoRPM1[1] = 0.0;
    Helikopter_new_B.Gain5 = 0.0;
    Helikopter_new_B.Sum3 = 0.0;
    Helikopter_new_B.Sum5 = 0.0;
    Helikopter_new_B.Sum4 = 0.0;
    Helikopter_new_B.Sum14 = 0.0;
    Helikopter_new_B.Integrator[0] = 0.0;
    Helikopter_new_B.Integrator[1] = 0.0;
    Helikopter_new_B.Integrator[2] = 0.0;
    Helikopter_new_B.Sum15 = 0.0;
    Helikopter_new_B.Gain = 0.0;
    Helikopter_new_B.Sum16 = 0.0;
    Helikopter_new_B.Sum17 = 0.0;
    Helikopter_new_B.Sum9 = 0.0;
    Helikopter_new_B.SliderGain = 0.0;
    Helikopter_new_B.ResetEncoders = 0.0;
    Helikopter_new_B.SliderGain_l = 0.0;
    Helikopter_new_B.Sum7[0] = 0.0;
    Helikopter_new_B.Sum7[1] = 0.0;
    Helikopter_new_B.Sum7[2] = 0.0;
    Helikopter_new_B.Saturation[0] = 0.0;
    Helikopter_new_B.Saturation[1] = 0.0;
    Helikopter_new_B.PWM[0] = 0.0;
    Helikopter_new_B.PWM[1] = 0.0;
    Helikopter_new_B.ResetEncoder[0] = 0.0;
    Helikopter_new_B.ResetEncoder[1] = 0.0;
    Helikopter_new_B.BitstreamVersion = 0.0;
    Helikopter_new_B.ThermStatus[0] = 0.0;
    Helikopter_new_B.ThermStatus[1] = 0.0;
    Helikopter_new_B.PWMPrescalerSource[0] = 0.0;
    Helikopter_new_B.PWMPrescalerSource[1] = 0.0;
    Helikopter_new_B.PWMPrescaler[0] = 0.0;
    Helikopter_new_B.PWMPrescaler[1] = 0.0;
    Helikopter_new_B.ThermFlagSource[0] = 0.0;
    Helikopter_new_B.ThermFlagSource[1] = 0.0;
    Helikopter_new_B.ThermFlag[0] = 0.0;
    Helikopter_new_B.ThermFlag[1] = 0.0;
  }

  /* parameters */
  Helikopter_new_M->ModelData.defaultParam = ((real_T *)&Helikopter_new_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &Helikopter_new_X;
    Helikopter_new_M->ModelData.contStates = (x);
    (void) memset((void *)&Helikopter_new_X, 0,
                  sizeof(X_Helikopter_new_T));
  }

  /* states (dwork) */
  Helikopter_new_M->ModelData.dwork = ((void *) &Helikopter_new_DW);
  (void) memset((void *)&Helikopter_new_DW, 0,
                sizeof(DW_Helikopter_new_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Helikopter_new_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &Helikopter_new_M->NonInlinedSFcns.sfcnInfo;
    Helikopter_new_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(Helikopter_new_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &Helikopter_new_M->Sizes.numSampTimes);
    Helikopter_new_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (Helikopter_new_M)[0]);
    Helikopter_new_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr
      (Helikopter_new_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,Helikopter_new_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(Helikopter_new_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(Helikopter_new_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (Helikopter_new_M));
    rtssSetStepSizePtr(sfcnInfo, &Helikopter_new_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(Helikopter_new_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &Helikopter_new_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &Helikopter_new_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo,
      &Helikopter_new_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &Helikopter_new_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &Helikopter_new_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &Helikopter_new_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &Helikopter_new_M->solverInfoPtr);
  }

  Helikopter_new_M->Sizes.numSFcns = (8);

  /* register each child */
  {
    (void) memset((void *)&Helikopter_new_M->NonInlinedSFcns.childSFunctions[0],
                  0,
                  8*sizeof(SimStruct));
    Helikopter_new_M->childSfunctions =
      (&Helikopter_new_M->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 8; i++) {
        Helikopter_new_M->childSfunctions[i] =
          (&Helikopter_new_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: Helikopter_new/<S5>/Encoder (TRAS_Encoder) */
    {
      SimStruct *rts = Helikopter_new_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = Helikopter_new_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = Helikopter_new_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = Helikopter_new_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Helikopter_new_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, Helikopter_new_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Helikopter_new_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Helikopter_new_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Helikopter_new_M->NonInlinedSFcns.statesInfo2[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Helikopter_new_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) Helikopter_new_B.Encoder));
        }
      }

      /* path info */
      ssSetModelName(rts, "Encoder");
      ssSetPath(rts, "Helikopter_new/TRAS/Encoder");
      ssSetRTModel(rts,Helikopter_new_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Helikopter_new_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Helikopter_new_P.Encoder_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Helikopter_new_P.Encoder_P2_Size);
      }

      /* registration */
      TRAS_Encoder(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Helikopter_new/<S5>/Analog Input (TRAS_AnalogInput) */
    {
      SimStruct *rts = Helikopter_new_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = Helikopter_new_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = Helikopter_new_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = Helikopter_new_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Helikopter_new_M->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, Helikopter_new_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Helikopter_new_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Helikopter_new_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Helikopter_new_M->NonInlinedSFcns.statesInfo2[1]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Helikopter_new_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) Helikopter_new_B.AnalogInput));
        }
      }

      /* path info */
      ssSetModelName(rts, "Analog Input");
      ssSetPath(rts, "Helikopter_new/TRAS/Analog Input");
      ssSetRTModel(rts,Helikopter_new_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Helikopter_new_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Helikopter_new_P.AnalogInput_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Helikopter_new_P.AnalogInput_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)Helikopter_new_P.AnalogInput_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)Helikopter_new_P.AnalogInput_P4_Size);
      }

      /* registration */
      TRAS_AnalogInput(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Helikopter_new/<S5>/PWM (TRAS_PWM) */
    {
      SimStruct *rts = Helikopter_new_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = Helikopter_new_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = Helikopter_new_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = Helikopter_new_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Helikopter_new_M->NonInlinedSFcns.blkInfo2[2]);
      }

      ssSetRTWSfcnInfo(rts, Helikopter_new_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Helikopter_new_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Helikopter_new_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Helikopter_new_M->NonInlinedSFcns.statesInfo2[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Helikopter_new_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Helikopter_new_M->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = Helikopter_new_B.Saturation;
          sfcnUPtrs[1] = &Helikopter_new_B.Saturation[1];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Helikopter_new_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) Helikopter_new_B.PWM));
        }
      }

      /* path info */
      ssSetModelName(rts, "PWM");
      ssSetPath(rts, "Helikopter_new/TRAS/PWM");
      ssSetRTModel(rts,Helikopter_new_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Helikopter_new_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Helikopter_new_P.PWM_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Helikopter_new_P.PWM_P2_Size);
      }

      /* registration */
      TRAS_PWM(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Helikopter_new/<S5>/ResetEncoder (TRAS_ResetEncoder) */
    {
      SimStruct *rts = Helikopter_new_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = Helikopter_new_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = Helikopter_new_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = Helikopter_new_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Helikopter_new_M->NonInlinedSFcns.blkInfo2[3]);
      }

      ssSetRTWSfcnInfo(rts, Helikopter_new_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Helikopter_new_M->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Helikopter_new_M->NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Helikopter_new_M->NonInlinedSFcns.statesInfo2[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Helikopter_new_M->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Helikopter_new_M->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = &Helikopter_new_B.ResetEncoders;
          sfcnUPtrs[1] = &Helikopter_new_B.ResetEncoders;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Helikopter_new_M->NonInlinedSFcns.Sfcn3.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            Helikopter_new_B.ResetEncoder));
        }
      }

      /* path info */
      ssSetModelName(rts, "ResetEncoder");
      ssSetPath(rts, "Helikopter_new/TRAS/ResetEncoder");
      ssSetRTModel(rts,Helikopter_new_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Helikopter_new_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Helikopter_new_P.ResetEncoder_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Helikopter_new_P.ResetEncoder_P2_Size);
      }

      /* registration */
      TRAS_ResetEncoder(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Helikopter_new/<S5>/Bitstream Version (TRAS_BitstreamVersion) */
    {
      SimStruct *rts = Helikopter_new_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = Helikopter_new_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = Helikopter_new_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = Helikopter_new_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Helikopter_new_M->NonInlinedSFcns.blkInfo2[4]);
      }

      ssSetRTWSfcnInfo(rts, Helikopter_new_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Helikopter_new_M->NonInlinedSFcns.methods2[4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Helikopter_new_M->NonInlinedSFcns.methods3[4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Helikopter_new_M->NonInlinedSFcns.statesInfo2[4]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Helikopter_new_M->NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Helikopter_new_B.BitstreamVersion));
        }
      }

      /* path info */
      ssSetModelName(rts, "Bitstream Version");
      ssSetPath(rts, "Helikopter_new/TRAS/Bitstream Version");
      ssSetRTModel(rts,Helikopter_new_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Helikopter_new_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Helikopter_new_P.BitstreamVersion_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Helikopter_new_P.BitstreamVersion_P2_Size);
      }

      /* registration */
      TRAS_BitstreamVersion(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Helikopter_new/<S5>/Therm Status (TRAS_PWMTherm) */
    {
      SimStruct *rts = Helikopter_new_M->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod = Helikopter_new_M->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset = Helikopter_new_M->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap = Helikopter_new_M->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Helikopter_new_M->NonInlinedSFcns.blkInfo2[5]);
      }

      ssSetRTWSfcnInfo(rts, Helikopter_new_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Helikopter_new_M->NonInlinedSFcns.methods2[5]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Helikopter_new_M->NonInlinedSFcns.methods3[5]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Helikopter_new_M->NonInlinedSFcns.statesInfo2[5]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Helikopter_new_M->NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) Helikopter_new_B.ThermStatus));
        }
      }

      /* path info */
      ssSetModelName(rts, "Therm Status");
      ssSetPath(rts, "Helikopter_new/TRAS/Therm Status");
      ssSetRTModel(rts,Helikopter_new_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Helikopter_new_M->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Helikopter_new_P.ThermStatus_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Helikopter_new_P.ThermStatus_P2_Size);
      }

      /* registration */
      TRAS_PWMTherm(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Helikopter_new/<S5>/PWMPrescaler (TRAS_PWMPrescaler) */
    {
      SimStruct *rts = Helikopter_new_M->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod = Helikopter_new_M->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset = Helikopter_new_M->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap = Helikopter_new_M->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Helikopter_new_M->NonInlinedSFcns.blkInfo2[6]);
      }

      ssSetRTWSfcnInfo(rts, Helikopter_new_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Helikopter_new_M->NonInlinedSFcns.methods2[6]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Helikopter_new_M->NonInlinedSFcns.methods3[6]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Helikopter_new_M->NonInlinedSFcns.statesInfo2[6]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Helikopter_new_M->NonInlinedSFcns.Sfcn6.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Helikopter_new_M->NonInlinedSFcns.Sfcn6.UPtrs0;
          sfcnUPtrs[0] = Helikopter_new_B.PWMPrescalerSource;
          sfcnUPtrs[1] = &Helikopter_new_B.PWMPrescalerSource[1];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Helikopter_new_M->NonInlinedSFcns.Sfcn6.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            Helikopter_new_B.PWMPrescaler));
        }
      }

      /* path info */
      ssSetModelName(rts, "PWMPrescaler");
      ssSetPath(rts, "Helikopter_new/TRAS/PWMPrescaler");
      ssSetRTModel(rts,Helikopter_new_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Helikopter_new_M->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Helikopter_new_P.PWMPrescaler_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Helikopter_new_P.PWMPrescaler_P2_Size);
      }

      /* registration */
      TRAS_PWMPrescaler(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: Helikopter_new/<S5>/ThermFlag  (TRAS_ThermFlag) */
    {
      SimStruct *rts = Helikopter_new_M->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod = Helikopter_new_M->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset = Helikopter_new_M->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap = Helikopter_new_M->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Helikopter_new_M->NonInlinedSFcns.blkInfo2[7]);
      }

      ssSetRTWSfcnInfo(rts, Helikopter_new_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Helikopter_new_M->NonInlinedSFcns.methods2[7]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Helikopter_new_M->NonInlinedSFcns.methods3[7]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Helikopter_new_M->NonInlinedSFcns.statesInfo2[7]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Helikopter_new_M->NonInlinedSFcns.Sfcn7.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Helikopter_new_M->NonInlinedSFcns.Sfcn7.UPtrs0;
          sfcnUPtrs[0] = Helikopter_new_B.ThermFlagSource;
          sfcnUPtrs[1] = &Helikopter_new_B.ThermFlagSource[1];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Helikopter_new_M->NonInlinedSFcns.Sfcn7.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) Helikopter_new_B.ThermFlag));
        }
      }

      /* path info */
      ssSetModelName(rts, "ThermFlag ");
      ssSetPath(rts, "Helikopter_new/TRAS/ThermFlag ");
      ssSetRTModel(rts,Helikopter_new_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Helikopter_new_M->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Helikopter_new_P.ThermFlag_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Helikopter_new_P.ThermFlag_P2_Size);
      }

      /* registration */
      TRAS_ThermFlag(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }
  }

  /* Initialize Sizes */
  Helikopter_new_M->Sizes.numContStates = (3);/* Number of continuous states */
  Helikopter_new_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  Helikopter_new_M->Sizes.numY = (0);  /* Number of model outputs */
  Helikopter_new_M->Sizes.numU = (0);  /* Number of model inputs */
  Helikopter_new_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Helikopter_new_M->Sizes.numSampTimes = (2);/* Number of sample times */
  Helikopter_new_M->Sizes.numBlocks = (69);/* Number of blocks */
  Helikopter_new_M->Sizes.numBlockIO = (28);/* Number of block outputs */
  Helikopter_new_M->Sizes.numBlockPrms = (108);/* Sum of parameter "widths" */
  return Helikopter_new_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
