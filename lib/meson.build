config_h = configuration_data({
    'gettext_package': 'toption',
})

configure_file(
    input: 'config.h.in',
    output: 'config.h',
    configuration: config_h,
)

sources = [
	'toption.c',
]

c_args = [
	'-DG_LOG_DOMAIN="toption"',
]

if get_option('buildtype') == 'release'
    c_args += [
        '-DG_DISABLE_ASSERT',
        '-DG_DISABLE_CHECKS',
        '-DG_DISABLE_CAST_CHECKS',
    ]
elif get_option('buildtype').startswith('debug')
    c_args += [
        '-DG_ENABLE_DEBUG',
    ]
endif

include_root = join_paths('..', 'include')

toption = library(
    'toption',
    sources,
    version: meson.project_version(),
    c_args: c_args,
    dependencies: [
		libgio_dep,
	],
    include_directories: include_directories(include_root),
    install: true,
)

toption_dep = declare_dependency(
    link_with: toption,
    version: meson.project_version(),
    include_directories: include_directories(join_paths(include_root))
)

pkg.generate(
	toption,
	description: 'GLib-based library for interacting with the Harvest API.',
	filebase: 'toption-@0@.@1@'.format(toption_major_version, toption_minor_version),
	name: 'toption',
	version: meson.project_version(),
	url: 'https://git.sr.ht/~tristan957/toption',
)
