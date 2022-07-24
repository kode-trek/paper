from sys import exit
from sys import path
from os import system as s

path.insert(1, 'lib')

from q1 import f1
from q2 import f2
from q3 import f3

try:
	while(True):
		v = f1()
		if	v == 1:
			f2()
		if	v == 2:
			f3()
		if	v == 'q':
			print ''
			print 'bye!'
			exit()
except:
	print ''
	exit()
