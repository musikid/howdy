project('pam_howdy', 'cpp', version: '0.1.0', default_options: ['cpp_std=c++14'])

inih_cpp = dependency('INIReader')
libpam = meson.get_compiler('cpp').find_library('pam')
boost = dependency('boost', modules: ['locale'])
threads = dependency('threads')
shared_library('pam_howdy', 'main.cc', dependencies: [boost, libpam, inih_cpp, threads], install: true, install_dir: '/lib/security/', name_prefix: '')
