#ifndef OCAML_FOOS
#define OCAML_FOOS

#include <caml/callback.h>
#include <stdint.h>
#include "caml/alloc.h"
#include "caml/mlvalues.h"

static const char *sys_getcwd(void) {
    const value *foo = caml_named_value("sys_getcwd");
    if (!foo) return NULL;

    value res = caml_callback(*foo, Val_unit);
    return String_val(res);
}

static const char *concat(const char *file1, const char *file2) {
    const value *foo = caml_named_value("concat");
    if (!foo) return NULL;

    value res = caml_callback2(*foo,
                               caml_copy_string(file1),
                               caml_copy_string(file2)
                              );
    return String_val(res);
}

// static const char *concat_many(const char **path, uint8_t len) {
//     const value *foo = caml_named_value("concat_many");
//     if (!foo) return NULL;

//     value res = 
// }

#endif // OCAML_FOOS