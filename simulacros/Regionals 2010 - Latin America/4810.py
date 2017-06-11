import sys

l = sys.stdin.readline().split()
while (l != ["*"]):
  s = {r.lower()[0] for r in l}
  if (len(s) == 1):
    print ("Y")
  else:
    print ("N")
  l = sys.stdin.readline().split()
