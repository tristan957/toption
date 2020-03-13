| Platform | Status                                                                                                                                  |
| -------- | --------------------------------------------------------------------------------------------------------------------------------------- |
| Alpine   | [![builds.sr.ht status](https://builds.sr.ht/~tristan957/toption/alpine.yml.svg)](https://builds.sr.ht/~tristan957/toption/alpine.yml?) |
| Fedora   | [![builds.sr.ht status](https://builds.sr.ht/~tristan957/toption/fedora.yml.svg)](https://builds.sr.ht/~tristan957/toption/fedora.yml?) |

# TOption

GLib lacks a good way to represent an optional type, so this library provides
an optional type to use in conjunction with GLib.

## Purpose

This library is kind of theoretical. It stemmed from me writing an API wrapper
using GLib. API requests typically have notions of nullability whether it is
request bodies, response bodies, or query parameters. GLib by itself does not
include a good way to have include nullable types. Insert `TOption`. I wanted to
see if this could be a good way to implement an optional type for GLib, but it
isn't at least according to the extremely naiive benchmark I wrote which seems
to report `TOption` as 50% to 60% slower than its raw C alternative.

### The Raw C Alternative

The raw C alternative is opinionated I would think, but I have come to the
conclustion that the closest thing to `TOption` functionality is this:

```c
g_autofree int *x = NULL;
if (the_value_exists) {
    x = g_malloc(sizeof(int));
    memcpy(x, &i, sizeof(int));
    g_assert(i == *x);
} else {
    // Do things with NULLability
}
```

Why I believe that this is equivalent functionally is that, in the case of a
none, you simply wouldn't do the `g_malloc/memcpy`, while in the case of
existence, you simply allocate memory and copy the value to it which is
essentially what `TOption` is doing at a higher-level of abstraction. At the
very least this library served as a testbed for an idea, and helped me come up
with a better alternative.

## Lessons Learned

1. Don't take higher-level type systems for granted (Rust for example)
2. Abstractions can bite you in the butt real quick if not used properly

## Usage

```c
#include <assert.h>

#include <toption/toption.h>

int
main(int argc, const char **argv)
{
    int my_value = 64;
    TOption *opt1 = t_option_from(opt);
    const int the_value = t_option_get_int(opt1);
    assert(the_value == my_value);

    TOption *opt2 = my_func();
    if (t_option_is_none(opt2))
        // stuff
    else
        // other stuff

    return 0;
}
```

`TOption` supports a variety of types:

* `gboolean`
* `gchar`
* `guchar`
* `gchararray`
* `gint`
* `gint64`
* `glong`
* `guint`
* `guint64`
* `gfloat`
* `gdouble`
* `gpointer`
