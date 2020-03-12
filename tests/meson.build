tests = {
	'toption': {}
}

dependencies = [
	libgio_dep,
	toption_dep,
]

test_env = environment()
test_env.set('G_TEST_SRCDIR', meson.current_source_dir())
test_env.set('G_TEST_BUILDDIR', meson.current_build_dir())

c_args = [
	'-DG_LOG_DOMAIN="toption-testing"',
]

if get_option('buildtype').startswith('debug')
    c_args += [
        '-DG_ENABLE_DEBUG',
    ]
endif

include_root = join_paths('..', 'include')

foreach test_name, value : tests
	exe = executable(
		test_name,
		test_name + '.c',
		dependencies: dependencies,
		c_args: c_args,
		include_directories: include_directories(join_paths(include_root)),
	)

	test(test_name, exe, env: test_env)
endforeach
