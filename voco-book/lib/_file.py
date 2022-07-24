import pickle

def _save(arg1, arg2):
	with open(arg2 + '.pkl', 'wb') as f:
		pickle.dump(arg1, f, pickle.HIGHEST_PROTOCOL)

def _load(arg1):
	with open(arg1 + '.pkl', 'rb') as f:
		return pickle.load(f)
