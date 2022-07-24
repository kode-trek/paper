from os import system as s

def f1():
	s('clear')
	while(True):
		print 'welcome to voco-book!'
		print '====================='
		print '1. Find Item'
		print '2. Add Item'
		print ''
		v = raw_input('[q to (q)uit]: ')
		if		v == '1' or v == '2':
			return int(v)
		elif	v == 'q':
			return v
		else:
			s('clear')
