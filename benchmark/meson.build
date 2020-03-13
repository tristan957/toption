dependencies = [
	libgio_dep,
	toption_dep,
]

c_args = [
	'-DG_LOG_DOMAIN="toption-testing"',
	'-flto',
]

if get_option('buildtype') == 'release'
    c_args += [
        '-DG_DISABLE_CHECKS',
        '-DG_DISABLE_CAST_CHECKS',
    ]
elif get_option('buildtype').startswith('debug')
    c_args += [
        '-DG_ENABLE_DEBUG',
    ]
endif

executable(
	'toption-benchmark',
	'benchmark.c',
	dependencies: dependencies,
	c_args: c_args,
	include_directories: include_directories(join_paths(include_root)),
)
