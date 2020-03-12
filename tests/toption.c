#include <glib.h>

#include "toption/toption.h"

#define TEST_NUMBER 69
#define TEST_STRING "69"

static void
test_boolean()
{
	gboolean v		 = TRUE;
	TOption *t		 = t_option_from(v);
	const gboolean n = t_option_get_boolean(t);

	g_assert_true(t && n);
}

static void
test_char()
{
	gchar v		= TEST_NUMBER;
	TOption *t	= t_option_from(v);
	const int n = t_option_get_char(t);

	g_assert_true(t && n == v);
}

static void
test_uchar()
{
	guchar v	   = TRUE;
	TOption *t	   = t_option_from(v);
	const guchar n = t_option_get_uchar(t);

	g_assert_true(t && n == v);
}

static void
test_string()
{
	gchararray v	   = TEST_STRING;
	TOption *t		   = t_option_from(v);
	const gchararray n = t_option_get_string(t);

	g_assert_true(t && n == v);
}

static void
test_int()
{
	gint v		 = TEST_NUMBER;
	TOption *t	 = t_option_from(v);
	const gint n = t_option_get_int(t);

	g_assert_true(t && n == v);
}

static void
test_int64()
{
	guint64 v		= TEST_NUMBER;
	TOption *t		= t_option_from(v);
	const guint64 n = t_option_get_uint64(t);

	g_assert_true(t && n == v);
}

static void
test_uint()
{
	guint v		  = TEST_NUMBER;
	TOption *t	  = t_option_from(v);
	const guint n = t_option_get_uint(t);

	g_assert_true(t && n == v);
}

static void
test_uint64()
{
	guint64 v		= TEST_NUMBER;
	TOption *t		= t_option_from(v);
	const guint64 n = t_option_get_uint64(t);

	g_assert_true(t && n == v);
}

static void
test_float()
{
	gfloat v	   = TEST_NUMBER;
	TOption *t	   = t_option_from(v);
	const gfloat n = t_option_get_float(t);

	g_assert_true(t && n == TEST_NUMBER);
}

static void
test_double()
{
	gdouble v		= TEST_NUMBER;
	TOption *t		= t_option_from(v);
	const gdouble n = t_option_get_double(t);

	g_assert_true(t && n == TEST_NUMBER);
}

static void
test_pointer()
{
	gpointer v		= &test_pointer;
	TOption *t		= t_option_from(v);
	gconstpointer n = t_option_get_pointer(t);

	g_assert_true(t && n == test_pointer);
}

int
main(int argc, char **argv)
{
	g_test_init(&argc, &argv, NULL);

	g_test_add_func("/boolean", test_boolean);
	g_test_add_func("/char", test_char);
	g_test_add_func("/uchar", test_uchar);
	g_test_add_func("/string", test_string);
	g_test_add_func("/int", test_int);
	g_test_add_func("/int64", test_int64);
	g_test_add_func("/uint", test_uint);
	g_test_add_func("/uint64", test_uint64);
	g_test_add_func("/float", test_float);
	g_test_add_func("/double", test_double);
	g_test_add_func("/pointer", test_pointer);

	return g_test_run();
}
