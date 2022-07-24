from _file import _load
from _file import _save

def f3():
	print ''
	b = _load('lib/asset/book')
	w = raw_input('phrase to ADD: ')
	print ''
	if	w in b.keys():
		print '<' + w + '> already exists!'
	else:
		v = []
		flag = 1
		c = 1
		while(flag):
			d = raw_input('[q to (q)uit] def(' + str(c) + '): ')
			if	d == 'q':
				flag = 0
			else:
				v.append(d)
				c += 1
		b[w] = v
		_save(b, 'lib/asset/book')
		print ''
		print '<' + w + '> has been added!'
		raw_input('press ENTER to continue...')
