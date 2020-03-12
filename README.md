# TOption

GLib lacks a good way to represent an optional type, so this library provides
an optional type to use in conjunction with GLib.

## Usage

```c
#include <assert.h>

#include <toption/toption.h>

int
main(int argc, const char ** argv)
{
    int my_value = 64;
    TOption *opt = t_option_from(opt);
    const int the_value = t_option_get_int(opt);
    assert(the_value == my_value);

    return 0;
}
```
