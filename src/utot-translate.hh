/*
 * This file is part of the TChecker Project.
 * 
 * See files AUTHORS and LICENSE for copyright details.
 */

#ifndef UPPAAL_TO_TCHEKER_UTOT_TRANSLATE_HH
# define UPPAAL_TO_TCHEKER_UTOT_TRANSLATE_HH

# include <utap/utap.h>
# include "utot.hh"
# include "utot-contextprefix.hh"
# include "utot-tchecker.hh"

namespace utot
{
    class translation_exception : public exception {
    };

    extern int
    eval_integer_constant (UTAP::instance_t *p, const UTAP::expression_t &expr);

    extern void
    translate_expression (std::ostream &out, UTAP::instance_t *p,
                          UTAP::expression_t &expr, context_prefix_t ctx);

    extern void
    translate_event_expression (std::ostream &out, UTAP::instance_t *p,
                                UTAP::expression_t &expr, context_prefix_t ctx);

    extern std::string
    translate_expression (UTAP::instance_t *p, UTAP::expression_t &expr,
                          context_prefix_t ctx);

    extern void
    translate_assignment (std::ostream &out, UTAP::instance_t *p,
                          UTAP::expression_t &expr, context_prefix_t ctx);

    extern std::string
    translate_assignment (UTAP::instance_t *p, UTAP::expression_t &expr,
                          context_prefix_t ctx);

    extern void
    translate_declarations (tchecker::outputter &out, UTAP::instance_t *p,
                            context_prefix_t ctx, UTAP::declarations_t &decl);

    extern bool
    translate_model (UTAP::TimedAutomataSystem &tas, tchecker::outputter &out);

    template<typename... Args>
    void
    tr_err (Args... args)
    {
      utot::err_ex (translation_exception (), std::forward<Args> (args) ...);
    }
}

#endif /* UPPAAL_TO_TCHEKER_UTOT_TRANSLATE_HH */
