#pragma once

#include <glib-object.h>

G_BEGIN_DECLS

#define T_TYPE_OPTION (t_option_get_type())

// clang-format off
#define t_option_from(value) _Generic((value), \
	gchar: t_option_from_char, \
	guchar: t_option_from_uchar, \
	gchararray: t_option_from_string, \
	gint: t_option_from_int, \
	gint64: t_option_from_int64, \
	guint: t_option_from_uint, \
	guint64: t_option_from_uint64, \
	gfloat: t_option_from_float, \
	gdouble: t_option_from_double, \
	gpointer: t_option_from_pointer, \
	default: t_option_none \
)(value)
// clang-format on

typedef struct _TOption TOption;

TOption *t_option_ref(TOption *self);
void t_option_unref(TOption *self);
void t_option_free(TOption *self);

gboolean t_option_is_none(TOption *self);
gboolean t_option_contains(TOption *self, const GType type);

TOption *t_option_none();
TOption *t_option_from_boolean(gboolean value);
TOption *t_option_from_char(gchar value);
TOption *t_option_from_uchar(guchar value);
TOption *t_option_from_string(gchararray value);
TOption *t_option_from_int(gint value);
TOption *t_option_from_int64(gint64 value);
TOption *t_option_from_long(glong value);
TOption *t_option_from_uint(guint value);
TOption *t_option_from_uint64(guint64 value);
TOption *t_option_from_float(gfloat value);
TOption *t_option_from_double(gdouble value);
TOption *t_option_from_pointer(gpointer value);

gboolean t_option_get_boolean(TOption *self);
gchar t_option_get_char(TOption *self);
guchar t_option_get_uchar(TOption *self);
gchararray t_option_get_string(TOption *self);
gint t_option_get_int(TOption *self);
gint64 t_option_get_int64(TOption *self);
glong t_option_get_long(TOption *self);
guint t_option_get_uint(TOption *self);
guint64 t_option_get_uint64(TOption *self);
gfloat t_option_get_float(TOption *self);
gdouble t_option_get_double(TOption *self);
gpointer t_option_get_pointer(TOption *self);

G_END_DECLS
