# This file is used to plot the results of the experiments.
import matplotlib.pyplot as plt

# Data to be plotted
x = ["Normal", "Uniform", "Bernoulli", "Mixed"]

ret = [
	[0.804033, 0.992350, 0.539705, 0.899567, 0.302261, 0.359552],
	[1.000000, 1.000000, 0.995614, 0.999999, 0.510591, 0.870741],
	[1.000000, 1.000000, 1.000000, 1.000000, 1.000000, 1.000000],

	[0.684952, 0.972358, 0.464824, 0.823521, 0.288943, 0.290061],
	[0.999992, 1.000000, 0.969823, 0.999900, 0.445284, 0.788148],
	[1.000000, 1.000000, 1.000000, 1.000000, 0.999989, 1.000000],

	[0.465557, 0.809241, 0.351963, 0.558944, 0.268607, 0.150281],
	[0.966587, 0.999779, 0.749410, 0.975987, 0.382188, 0.512118],
	[1.000000, 1.000000, 1.000000, 1.000000, 0.955986, 0.999752],

	[0.566107, 0.909725, 0.401324, 0.694859, 0.277582, 0.208867],
	[0.997254, 0.999999, 0.870417, 0.997094, 0.382296, 0.655883],
	[1.000000, 1.000000, 1.000000, 1.000000, 0.997250, 1.000000],
]

err = [
	[0.000397, 0.000765, 0.000498, 0.001257, 0.000459, 0.002071],
	[0.000000, 0.000176, 0.000066, 0.000352, 0.000500, 0.001334],
	[0.000000, 0.000018, 0.000000, 0.000035, 0.000000, 0.000176],

	[0.000465, 0.000959, 0.000499, 0.001435, 0.000453, 0.002146],
	[0.000003, 0.000231, 0.000171, 0.000462, 0.000497, 0.001507],
	[0.000000, 0.000023, 0.000000, 0.000046, 0.000003, 0.000231],

	[0.000499, 0.001486, 0.000478, 0.001882, 0.000443, 0.002381],
	[0.000180, 0.000490, 0.000433, 0.000929, 0.000486, 0.001900],
	[0.000000, 0.000049, 0.000000, 0.000099, 0.000205, 0.000500],

	[0.000496, 0.001194, 0.000490, 0.001639, 0.000448, 0.002242],
	[0.000052, 0.000329, 0.000336, 0.000657, 0.000486, 0.001711],
	[0.000000, 0.000033, 0.000000, 0.000067, 0.000052, 0.000334]
]

# Figure 1
for i in range(3):
	# Data
	IR = []
	IRerr = []
	Efficiency = []
	Efficiencyerr = []
	for j in range(4):
		IR.append(ret[i + j * 3][2])
		IRerr.append(err[i + j * 3][2])
		Efficiency.append(ret[i + j * 3][3])
		Efficiencyerr.append(err[i + j * 3][3])
	# Plot
	plt.figure(figsize=(6.4, 3.6))
	plt.bar(x, IR, yerr=IRerr, capsize=10, color="#1E90FF", label="IR", width=0.4)
	plt.bar([i + 0.4 for i in range(len(x))], Efficiency, yerr=Efficiencyerr, capsize=10, color="#FF4500", label="Efficiency", width=0.4)
	plt.xlabel("Distribution", fontsize=16)
	plt.xticks([i + 0.2 for i in range(len(x))], x, fontsize=16)
	plt.yticks([0.0, 0.2, 0.4, 0.6, 0.8, 1.0], [0.0, 0.2, 0.4, 0.6, 0.8, 1.0], fontsize=16)
	plt.legend(fontsize=16)
	plt.ylim(0, 1.4)
	plt.show()
	plt.subplots_adjust(top = 0.98, bottom = 0.15, left=0.08, right=0.99)
	plt.savefig(str(i) + '.jpg')
	plt.clf()

# Figure 2
for i in range(3):
	# Data
	IR = []
	IRerr = []
	Efficiency = []
	Efficiencyerr = []
	for j in range(4):
		IR.append(ret[1 + j * 3][0 + i * 2])
		IRerr.append(err[1 + j * 3][0 + i * 2])
		Efficiency.append(ret[1 + j * 3][1 + i * 2])
		Efficiencyerr.append(err[1 + j * 3][1 + i * 2])
	# Plot
	plt.figure(figsize=(6.4, 3.6))
	plt.bar(x, IR, yerr=IRerr, capsize=10, color="#1E90FF", label="IR", width=0.4)
	plt.bar([i + 0.4 for i in range(len(x))], Efficiency, yerr=Efficiencyerr, capsize=10, color="#FF4500", label="Efficiency", width=0.4)
	plt.xlabel("Distribution", fontsize=16)
	plt.xticks([i + 0.2 for i in range(len(x))], x, fontsize=16)
	plt.yticks([0.0, 0.2, 0.4, 0.6, 0.8, 1.0], [0.0, 0.2, 0.4, 0.6, 0.8, 1.0], fontsize=16)
	plt.legend(fontsize=16)
	plt.ylim(0, 1.4)
	plt.show()
	plt.subplots_adjust(top = 0.98, bottom = 0.15, left=0.08, right=0.99)
	plt.savefig(str(i + 3) + '.jpg')
	plt.clf()