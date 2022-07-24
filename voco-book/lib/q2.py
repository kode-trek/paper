from _file import _load

def f2():
	print ''
	w = raw_input('phrase to FIND: ')
	b = _load('lib/asset/book')
	if	w in b.keys():
		v = b[w]
		c = 0
		for i in v:
			print '1. ' + i
			c += 1
		print ''
		raw_input('press ENTER to continue...')
	else:
		print 'NOT FOUND!'
		print ''
		raw_input('press ENTER to continue...')
