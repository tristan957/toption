project(
	'toption',
	'c',
	version: '1.0.0',
	license: [
		'LGPL-3.0',
	],
	default_options: [
        'c_std=gnu18',
        'buildtype=debugoptimized',
    ],
)

version_components = meson.project_version().split('.')

toption_major_version = version_components[0]
toption_minor_version = version_components[1]
toption_patch_version = version_components[2]

cc = meson.get_compiler('c')

gnome = import('gnome')
pkg = import('pkgconfig')

libgio_dep = dependency('gio-2.0', version: '>= 2.62.1', required: true, fallback: ['gio', 'libgio_dep'])

subdir('include')
subdir('lib')
if get_option('tests')
    subdir('tests')
endif
if get_option('benchmark')
	subdir('benchmark')
endif
