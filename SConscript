from building import *
import rtconfig

import os

# get current directory
cwd     = GetCurrentDir()

# The set of source files associated with this SConscript file.
src = []
for root, dirs, files in os.walk(cwd + '/libsodium'):
  for file in files:
    if file.endswith('.c'):
      src.append(os.path.join(root, file))

if GetDepend('LIBSODIUM_USING_EXAMPLE_SHA256'):
    src    += Glob('examples/sha256.c')

if GetDepend('LIBSODIUM_USING_TESTING_HASH'):
    src    += Glob('test/default/hash.c')

path    = [cwd + '/libsodium/include']
path   += [cwd + '/libsodium/include/sodium']
path   += [cwd + '/libsodium/include/sodium/private']


LOCAL_CCFLAGS = ''

if rtconfig.CROSS_TOOL == 'gcc':
    LOCAL_CCFLAGS += ' -Wno-unknown-pragmas -Wno-unused-function'

group = DefineGroup('libsodium', src, depend = ['PKG_USING_LIBSODIUM'], CPPPATH = path, CPPDEFINES=['CONFIGURED=1'], LOCAL_CCFLAGS = LOCAL_CCFLAGS)

Return('group')
