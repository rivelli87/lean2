/*
Copyright (c) 2013 Microsoft Corporation. All rights reserved.
Released under Apache 2.0 license as described in the file LICENSE.

Author: Leonardo de Moura
*/
#pragma once
#include "expr.h"
#include "builtin.h"
#include "mpz.h"
#include "mpq.h"

namespace lean {
// =======================================
// Natural numbers
expr mk_nat_type();
extern expr const Nat;

expr mk_nat_value(mpz const & v);
inline expr mk_nat_value(unsigned v) { return mk_nat_value(mpz(v)); }
inline expr nVal(unsigned v) { return mk_nat_value(v); }
bool is_nat_value(expr const & e);
mpz const & nat_value_numeral(expr const & e);

/** \brief Nat::add : Nat -> Nat -> Nat */
expr mk_nat_add_fn();
inline expr nAdd(expr const & e1, expr const & e2) { return mk_app(mk_nat_add_fn(), e1, e2); }

/** \brief Nat::sub : Nat -> Nat -> Int */
expr mk_nat_sub_fn();
inline expr nSub(expr const & e1, expr const & e2) { return mk_app(mk_nat_sub_fn(), e1, e2); }

/** \brief Nat::neg : Nat -> Int */
expr mk_nat_neg_fn();
inline expr nNeg(expr const & e1, expr const & e2) { return mk_app(mk_nat_neg_fn(), e1, e2); }

/** \brief Nat::mul : Nat -> Nat -> Nat */
expr mk_nat_mul_fn();
inline expr nMul(expr const & e1, expr const & e2) { return mk_app(mk_nat_mul_fn(), e1, e2); }

/** \brief Nat::le : Nat -> Nat -> Bool */
expr mk_nat_le_fn();
inline expr nLe(expr const & e1, expr const & e2) { return mk_app(mk_nat_le_fn(), e1, e2); }

/** \brief Nat::ge : Nat -> Nat -> Bool */
expr mk_nat_ge_fn();
inline expr nGe(expr const & e1, expr const & e2) { return mk_app(mk_nat_ge_fn(), e1, e2); }

/** \brief Nat::lt : Nat -> Nat -> Bool */
expr mk_nat_lt_fn();
inline expr nLt(expr const & e1, expr const & e2) { return mk_app(mk_nat_lt_fn(), e1, e2); }

/** \brief Nat::gt : Nat -> Nat -> Bool */
expr mk_nat_gt_fn();
inline expr nGt(expr const & e1, expr const & e2) { return mk_app(mk_nat_gt_fn(), e1, e2); }

inline expr nIf(expr const & c, expr const & t, expr const & e) { return mk_if(Nat, c, t, e); }
// =======================================

// =======================================
// Integers
expr mk_int_type();
extern expr const Int;

expr mk_int_value(mpz const & v);
inline expr mk_int_value(int v) { return mk_int_value(mpz(v)); }
inline expr iVal(int v) { return mk_int_value(v); }
bool is_int_value(expr const & e);
mpz const & int_value_numeral(expr const & e);

expr mk_int_add_fn();
inline expr iAdd(expr const & e1, expr const & e2) { return mk_app(mk_int_add_fn(), e1, e2); }

expr mk_int_sub_fn();
inline expr iSub(expr const & e1, expr const & e2) { return mk_app(mk_int_sub_fn(), e1, e2); }

expr mk_int_neg_fn();
inline expr iNeg(expr const & e) { return mk_app(mk_int_neg_fn(), e); }

expr mk_int_mul_fn();
inline expr iMul(expr const & e1, expr const & e2) { return mk_app(mk_int_mul_fn(), e1, e2); }

expr mk_int_div_fn();
inline expr iDiv(expr const & e1, expr const & e2) { return mk_app(mk_int_div_fn(), e1, e2); }

expr mk_int_mod_fn();
inline expr iMod(expr const & e1, expr const & e2) { return mk_app(mk_int_mod_fn(), e1, e2); }

expr mk_int_divides_fn();
inline expr iDivides(expr const & e1, expr const & e2) { return mk_app(mk_int_divides_fn(), e1, e2); }

expr mk_int_le_fn();
inline expr iLe(expr const & e1, expr const & e2) { return mk_app(mk_int_le_fn(), e1, e2); }

expr mk_int_ge_fn();
inline expr iGe(expr const & e1, expr const & e2) { return mk_app(mk_int_ge_fn(), e1, e2); }

expr mk_int_lt_fn();
inline expr iLt(expr const & e1, expr const & e2) { return mk_app(mk_int_lt_fn(), e1, e2); }

expr mk_int_gt_fn();
inline expr iGt(expr const & e1, expr const & e2) { return mk_app(mk_int_gt_fn(), e1, e2); }

inline expr iIf(expr const & c, expr const & t, expr const & e) { return mk_if(Int, c, t, e); }
// =======================================

// =======================================
// Reals
expr mk_real_type();
extern expr const Real;

expr mk_real_value(mpq const & v);
inline expr mk_real_value(int v) { return mk_real_value(mpq(v)); }
inline expr rVal(int v) { return mk_real_value(v); }
bool is_real_value(expr const & e);
mpq const & real_value_numeral(expr const & e);

expr mk_real_add_fn();
inline expr rAdd(expr const & e1, expr const & e2) { return mk_app(mk_real_add_fn(), e1, e2); }

expr mk_real_sub_fn();
inline expr rSub(expr const & e1, expr const & e2) { return mk_app(mk_real_sub_fn(), e1, e2); }

expr mk_real_neg_fn();
inline expr rNeg(expr const & e) { return mk_app(mk_real_neg_fn(), e); }

expr mk_real_mul_fn();
inline expr rMul(expr const & e1, expr const & e2) { return mk_app(mk_real_mul_fn(), e1, e2); }

expr mk_real_div_fn();
inline expr rDiv(expr const & e1, expr const & e2) { return mk_app(mk_real_div_fn(), e1, e2); }

expr mk_real_le_fn();
inline expr rLe(expr const & e1, expr const & e2) { return mk_app(mk_real_le_fn(), e1, e2); }

expr mk_real_ge_fn();
inline expr rGe(expr const & e1, expr const & e2) { return mk_app(mk_real_ge_fn(), e1, e2); }

expr mk_real_lt_fn();
inline expr rLt(expr const & e1, expr const & e2) { return mk_app(mk_real_lt_fn(), e1, e2); }

expr mk_real_gt_fn();
inline expr rGt(expr const & e1, expr const & e2) { return mk_app(mk_real_gt_fn(), e1, e2); }

inline expr rIf(expr const & c, expr const & t, expr const & e) { return mk_if(Real, c, t, e); }

expr mk_exp_fn();
inline expr Exp(expr const & e) { return mk_app(mk_exp_fn(), e); }

expr mk_log_fn();
inline expr Log(expr const & e) { return mk_app(mk_log_fn(), e); }
// =======================================

// =======================================
// Transcendental and Hyperbolic
expr mk_real_pi();

expr mk_sin_fn();
inline expr Sin(expr const & e) { return mk_app(mk_sin_fn(), e); }

expr mk_cos_fn();
inline expr Cos(expr const & e) { return mk_app(mk_cos_fn(), e); }

expr mk_tan_fn();
inline expr Tan(expr const & e) { return mk_app(mk_tan_fn(), e); }

expr mk_cot_fn();
inline expr Cot(expr const & e) { return mk_app(mk_cot_fn(), e); }

expr mk_sec_fn();
inline expr Sec(expr const & e) { return mk_app(mk_sec_fn(), e); }

expr mk_csc_fn();
inline expr Csc(expr const & e) { return mk_app(mk_csc_fn(), e); }

expr mk_sinh_fn();
inline expr Sinh(expr const & e) { return mk_app(mk_sinh_fn(), e); }

expr mk_cosh_fn();
inline expr Cosh(expr const & e) { return mk_app(mk_cosh_fn(), e); }

expr mk_tanh_fn();
inline expr Tanh(expr const & e) { return mk_app(mk_tanh_fn(), e); }

expr mk_coth_fn();
inline expr Coth(expr const & e) { return mk_app(mk_coth_fn(), e); }

expr mk_sech_fn();
inline expr Sech(expr const & e) { return mk_app(mk_sech_fn(), e); }

expr mk_csch_fn();
inline expr Csch(expr const & e) { return mk_app(mk_csch_fn(), e); }
// =======================================

// =======================================
// Coercions
expr mk_nat_to_int_fn();
inline expr n2i(expr const & e) { return mk_app(mk_nat_to_int_fn(), e); }
expr mk_int_to_real_fn();
inline expr i2r(expr const & e) { return mk_app(mk_int_to_real_fn(), e); }
expr mk_nat_to_real_fn();
inline expr n2r(expr const & e) { return mk_app(mk_nat_to_real_fn(), e); }
// =======================================

class environment;
void add_arith_theory(environment & env);
}
