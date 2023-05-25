def main():
	a = 5
	b = 6
	c = None
	d = None
	if a > b:
		c = 7
	elif a < b:
		d = 4
	else:
		e = 5.5

	if c == 7:
		print("a is greater than b!\n")
	elif d == 4:
		print("a is less than b!\n")
	else:
		print("a equals b!\n")

	while a < b:
		a = a + b

	return 0

