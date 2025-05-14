#ifndef CUSTOM_ERRORS
#define CUSTOM_ERRORS

#include <vector>
#include <string>


struct custom_errors  {
        // static so I can call them without an object
        // contexpr so it's evaluated at compile time
    static constexpr const char* phasor_error() {
        return "INCORRECT PHASOR FORM.";
    }

    static constexpr const char* choice_error() {
        return "**INVALID CHOICE. Please try again (valid inputs are 0 to 8)**";
    }

    static constexpr const char* choice_error_crmrs() {
        return "**INVALID CHOICE. Please try again (valid inputs are 1 or 2)**";
    }

    static constexpr const char* choice_error_ohm() {
        return "**INVALID CHOICE. Please try again (valid inputs are 1 - 3)**";
    }

    static constexpr const char* form_error() {
        return "**INVALID FORM. Please try again (valid inputs are: r or p)**";
    }

    static constexpr const char* input_error() {
        return "**UNKNOWN. Please make sure your input is a number**";
    }


};


#endif