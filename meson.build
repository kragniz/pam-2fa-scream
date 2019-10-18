project('pam-2fa-scream', 'c',
  version : '0.1.0',
  default_options : ['warning_level=3'])

cc = meson.get_compiler('c')
dep_pam = cc.find_library('pam', required: true)
dep_alsa = dependency('alsa', required: true)

module = shared_module(
  'pam_2fa_scream',
  'pam_2fa_scream.c',
  dependencies: [dep_pam, dep_alsa],
  install: true,
)