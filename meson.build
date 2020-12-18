project('howdy', 'cpp', version: '0.1.0',
	default_options: ['cpp_std=c++17'])

cmake = import('cmake')

dlib_options = cmake.subproject_options()
dlib_cuda = get_option('cuda').enabled() ? 'yes' : 'no'
dlib_options.add_cmake_defines({'CMAKE_POSITION_INDEPENDENT_CODE': 1, 'DLIB_USE_CUDA': dlib_cuda})

dlib_subproject = cmake.subproject('dlib', options: dlib_options)
dlib = dlib_subproject.dependency('dlib')

opencv = dependency('opencv4')

include = include_directories('src/include')

# CLI
cli11_subproject = cmake.subproject('cli11')
cli11 = cli11_subproject.dependency('CLI11')

executable('howdy', 'src/cli/main.cc', install: true, dependencies: [opencv, dlib, cli11], include_directories: include)

# PAM Module
cc = meson.get_compiler('c')
libpam = cc.find_library('pam')

shared_library('pam_howdy', install: true, install_dir: '/lib64/security', version: '0.1.0', soversion: '0', dependencies: [opencv, dlib, libpam], include_directories: include)
