#include "config.h"

#include <string.h>

#include <glib-object.h>

#include "toption/toption.h"

struct _TOption
{
	GType type;
	union
	{
		gboolean as_boolean;
		gchar as_char;
		guchar as_uchar;
		gchararray as_string;
		gint as_int;
		gint64 as_int64;
		glong as_long;
		guint as_uint;
		guint64 as_uint64;
		gfloat as_float;
		gdouble as_double;
		gpointer as_pointer;
	} value;

	volatile gint ref_count;
};

G_DEFINE_BOXED_TYPE(TOption, t_option, t_option_ref, t_option_unref)

TOption *
t_option_ref(TOption *self)
{
	g_return_val_if_fail(self, NULL);
	g_return_val_if_fail(self->ref_count > 0, NULL);

	g_atomic_int_inc(&self->ref_count);

	return self;
}

void
t_option_unref(TOption *self)
{
	g_return_if_fail(self != NULL);
	g_return_if_fail(self->ref_count > 0);

	if (g_atomic_int_dec_and_test(&self->ref_count)) {
		g_slice_free(TOption, self);
	}
}

void
t_option_free(TOption *self)
{
	g_return_if_fail(self != NULL);
	g_return_if_fail(self->ref_count > 0);

	switch (self->type) {
	case G_TYPE_CHAR:
	case G_TYPE_STRING:
	case G_TYPE_BOOLEAN:
	case G_TYPE_INT:
	case G_TYPE_INT64:
	case G_TYPE_LONG:
	case G_TYPE_UINT:
	case G_TYPE_UINT64:
	case G_TYPE_ULONG:
	case G_TYPE_DOUBLE:
	case G_TYPE_FLOAT:
	case G_TYPE_POINTER:
		memset(&self->value, 0, sizeof(self->value));
		break;
	default:
		g_warn_if_reached();
	}
}

gboolean
t_option_is_none(TOption *self)
{
	g_return_val_if_fail(self != NULL, TRUE);
	g_return_val_if_fail(self->ref_count > 0, TRUE);

	return self->type == G_TYPE_NONE;
}

gboolean
t_option_contains(TOption *self, const GType type)
{
	g_return_val_if_fail(self != NULL, TRUE);
	g_return_val_if_fail(self->ref_count > 0, TRUE);

	return type == self->type;
}

TOption *
t_option_none()
{
	TOption *self = g_try_new0(TOption, 1);
	if (!self)
		goto out;

	self->type		= G_TYPE_NONE;
	self->ref_count = 1;

out:
	return self;
}

TOption *
t_option_from_boolean(gboolean value)
{
	TOption *self = g_try_new0(TOption, 1);
	if (!self)
		goto out;

	self->type			   = G_TYPE_BOOLEAN;
	self->value.as_boolean = value;
	self->ref_count		   = 1;

out:
	return self;
}

TOption *
t_option_from_char(gchar value)
{
	TOption *self = g_try_new0(TOption, 1);
	if (!self)
		goto out;

	self->type			= G_TYPE_CHAR;
	self->value.as_char = value;
	self->ref_count		= 1;

out:
	return self;
}

TOption *
t_option_from_uchar(guchar value)
{
	TOption *self = g_try_new0(TOption, 1);
	if (!self)
		goto out;

	self->type			 = G_TYPE_UCHAR;
	self->value.as_uchar = value;
	self->ref_count		 = 1;

out:
	return self;
}

TOption *
t_option_from_string(gchararray value)
{
	TOption *self = g_try_new0(TOption, 1);
	if (!self)
		goto out;

	self->type			  = G_TYPE_STRING;
	self->value.as_string = value;
	self->ref_count		  = 1;

out:
	return self;
}

TOption *
t_option_from_int(gint value)
{
	TOption *self = g_try_new0(TOption, 1);
	if (!self)
		goto out;

	self->type		   = G_TYPE_INT;
	self->value.as_int = value;
	self->ref_count	   = 1;

out:
	return self;
}

TOption *
t_option_from_int64(gint64 value)
{
	TOption *self = g_try_new0(TOption, 1);
	if (!self)
		goto out;

	self->type			 = G_TYPE_INT64;
	self->value.as_int64 = value;
	self->ref_count		 = 1;

out:
	return self;
}

TOption *
t_option_from_uint(guint value)
{
	TOption *self = g_try_new0(TOption, 1);
	if (!self)
		goto out;

	self->type			= G_TYPE_UINT;
	self->value.as_uint = value;
	self->ref_count		= 1;

out:
	return self;
}

TOption *
t_option_from_uint64(guint64 value)
{
	TOption *self = g_try_new0(TOption, 1);
	if (!self)
		goto out;

	self->type			  = G_TYPE_UINT64;
	self->value.as_uint64 = value;
	self->ref_count		  = 1;

out:
	return self;
}

TOption *
t_option_from_float(gfloat value)
{
	TOption *self = g_try_new0(TOption, 1);
	if (!self)
		goto out;

	self->type			 = G_TYPE_FLOAT;
	self->value.as_float = value;
	self->ref_count		 = 1;

out:
	return self;
}

TOption *
t_option_from_double(gdouble value)
{
	TOption *self = g_try_new0(TOption, 1);
	if (!self)
		goto out;

	self->type			  = G_TYPE_DOUBLE;
	self->value.as_double = value;
	self->ref_count		  = 1;

out:
	return self;
}

TOption *
t_option_from_pointer(gpointer value)
{
	TOption *self = g_try_new0(TOption, 1);
	if (!self)
		goto out;

	self->type			   = G_TYPE_POINTER;
	self->value.as_pointer = value;
	self->ref_count		   = 1;

out:
	return self;
}

gboolean
t_option_get_boolean(TOption *self)
{
	g_return_val_if_fail(self != NULL, 0);
	g_return_val_if_fail(self->ref_count > 0, 0);

	return self->value.as_boolean;
}

gchar
t_option_get_char(TOption *self)
{
	g_return_val_if_fail(self != NULL, 0);
	g_return_val_if_fail(self->ref_count > 0, 0);

	return self->value.as_char;
}

guchar
t_option_get_uchar(TOption *self)
{
	g_return_val_if_fail(self != NULL, 0);
	g_return_val_if_fail(self->ref_count > 0, 0);

	return self->value.as_uchar;
}

gchararray
t_option_get_string(TOption *self)
{
	g_return_val_if_fail(self != NULL, 0);
	g_return_val_if_fail(self->ref_count > 0, 0);

	return self->value.as_string;
}

gint
t_option_get_int(TOption *self)
{
	g_return_val_if_fail(self != NULL, 0);
	g_return_val_if_fail(self->ref_count > 0, 0);

	return self->value.as_int;
}

gint64
t_option_get_int64(TOption *self)
{
	g_return_val_if_fail(self != NULL, 0);
	g_return_val_if_fail(self->ref_count > 0, 0);

	return self->value.as_int64;
}

glong
t_option_get_long(TOption *self)
{
	g_return_val_if_fail(self != NULL, 0);
	g_return_val_if_fail(self->ref_count > 0, 0);

	return self->value.as_long;
}

guint
t_option_get_uint(TOption *self)
{
	g_return_val_if_fail(self != NULL, 0);
	g_return_val_if_fail(self->ref_count > 0, 0);

	return self->value.as_uint;
}

guint64
t_option_get_uint64(TOption *self)
{
	g_return_val_if_fail(self != NULL, 0);
	g_return_val_if_fail(self->ref_count > 0, 0);

	return self->value.as_uint64;
}

gfloat
t_option_get_float(TOption *self)
{
	g_return_val_if_fail(self != NULL, 0);
	g_return_val_if_fail(self->ref_count > 0, 0);

	return self->value.as_float;
}

gdouble
t_option_get_double(TOption *self)
{
	g_return_val_if_fail(self != NULL, 0);
	g_return_val_if_fail(self->ref_count > 0, 0);

	return self->value.as_double;
}

gpointer
t_option_get_pointer(TOption *self)
{
	g_return_val_if_fail(self != NULL, 0);
	g_return_val_if_fail(self->ref_count > 0, 0);

	return self->value.as_pointer;
}
