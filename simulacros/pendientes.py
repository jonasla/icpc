import os, sys

path = os.getcwd()
dirs = os.listdir( path )

for file in sorted(dirs):
  if os.path.isdir(os.path.join(path, file)):
    print file
    f = open(os.path.join(path, file, "pendientes.txt"), 'r')
    print '\t' + '\t'.join(f.read().splitlines(True))
