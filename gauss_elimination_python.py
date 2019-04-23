import math
import datetime
import random


def ini_array(arr, numel, var, media):

	desv = math.sqrt(var)

	for i in range(numel):
		#print("i value: {}".format(i))
		temp = 0
		for k in range(100):
			temp += random.randint(0, 32767) / 32767.0
		arr[i] = desv * math.sqrt(3/25)*(temp-50.0)  + media	

	return arr

def triang(M, b, numel):
	k = 0
	while k < numel-1:
		i = k + 1
		while i < numel:
			j = k
			while j < numel:
				xmu = M[i * numel + k]/M[k * numel + k]
				M[i * numel + j] = M[i * numel + j] - xmu*M[k * numel + j]
				j += 1
			b[i] = b[i] - xmu * b[k]
			i += 1
		k += 1


def triang_imp(M, b, numel):
	k = 0
	while k < numel-1:
		k += 1
		i = k + 1
		while i < numel:
			xmu = M[i * numel + k]/M[k * numel + k]
			j = k
			while j < numel:
				M[i * numel + j] = M[i * numel + j] - xmu * M[k * numel + j]
				j += 1
			b[i] = b[i] - xmu * b[k]
			i += 1

def backsub(M, b, x, numel):
	x[numel - 1] = b[numel - 1]/M[(numel - 1) * numel + numel - 1]

	i = numel - 2
	while i > -1:
		temp = b[i]
		j = i + 1
		while j < numel:
			temp = temp - x[j] * M[i * numel + j]
			j += 1
		x[i] = temp/M[i * numel + i]
		i -= 1

def main():

	numel = 1024

	M = [0.0] * (numel * numel)
	x = [0.0] * numel
	b = [0.0] * numel

	M = ini_array(M, numel * numel, 1.0, 0.0)
	b = ini_array(b, numel, 1.0, 0.0)

	print("finished initializing arrays")

	start_t = datetime.datetime.now()

	triang(M, b, numel)

	backsub(M, b, x, numel)

	end_t = datetime.datetime.now()

	total_t = end_t - start_t


	print("{} us".format(total_t.microseconds))


if __name__ == "__main__":
	main()

