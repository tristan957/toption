| Platform | Status                                                                                                                                  |
| -------- | --------------------------------------------------------------------------------------------------------------------------------------- |
| Alpine   | [![builds.sr.ht status](https://builds.sr.ht/~tristan957/toption/alpine.yml.svg)](https://builds.sr.ht/~tristan957/toption/alpine.yml?) |
| Fedora   | [![builds.sr.ht status](https://builds.sr.ht/~tristan957/toption/fedora.yml.svg)](https://builds.sr.ht/~tristan957/toption/fedora.yml?) |

# TOption

GLib lacks a good way to represent an optional type, so this library provides
an optional type to use in conjunction with GLib.

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
