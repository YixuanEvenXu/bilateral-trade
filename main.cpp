// This file is used to generate the experimental results in the paper.
#include<bits/stdc++.h>
using namespace std;
const int T = 1e6;
const int n[3] = {5, 100, 10000};
const double Eb[3] = {0.6, 0.55, 0.51};
const double Es[3] = {0.4, 0.45, 0.49};

const double Min = 0.0;
const double Max = 1.0;
const double sigma = 0.2;
const double radius = 0.4;

mt19937_64 gen;

// Normal distribution with mean mu and variance sigma^2
double Normal(double mu) {
	normal_distribution <double> normal(0.0, sigma);
	double ret = normal(gen);
	while (fabsl(ret) > radius) {
		ret = normal(gen);
	}
	return ret + mu;
}

// Uniform distribution in [mu - radius, mu + radius]
double Uniform(double mu) {
	uniform_real_distribution<double> uniform(mu - radius, mu + radius);
	return uniform(gen);
}

// Bernoulli distribution with mean mu
double Bernoulli(double mu) {
	bernoulli_distribution bernoulli(mu);
	return bernoulli(gen);
}

// Mixed distribution with mean mu
double Mixed(double mu) {
	uniform_int_distribution<int> dist(1, 3);
	int type = dist(gen);
	if (type == 1) return Normal(mu);
	if (type == 2) return Uniform(mu);
	if (type == 3) return Bernoulli(mu);
	return -1;
}

// Sample collection for mean and variance
struct SampleCollection {
	double sum[3];
	void init() {
		sum[0] = 0;
		sum[1] = 0;
		sum[2] = 0;
	}
	void add(double x) {
		sum[0] += 1;
		sum[1] += x;
		sum[2] += x * x;
	}
	double mean() {
		return sum[1] / sum[0];
	}
	double var() {
		return sum[2] / sum[0] - mean() * mean();
	}
};

// Main experiment
void work(int n, double Eb, double Es) {
	// Print the setting
	double price = (Eb + Es) / 2;
	SampleCollection IR, GFT, FB;
	printf("Setting: n = %d, E[buyer] = %.2lf, E[seller] = %.2lf\n", n, Eb, Es);

	// Normal distribution
	IR.init(); GFT.init(); FB.init();
	for (int t = 1; t <= T; t++) {
		double sb = 0, ss = 0;
		for (int i = 1; i <= n; i++) {
			sb += Normal(Eb);
			ss += Normal(Es);
		}
		IR.add(sb >= price * n && ss <= price * n);
		GFT.add(sb - ss);
		FB.add(max(0.0, sb - ss));
	}
	printf("Normal   : IR: %.6lf ± %.6lf, Efficiency: %.6lf ± %.6lf\n", IR.mean(), sqrt(IR.var() / T), GFT.mean() / FB.mean(), sqrt((GFT.var() / pow(FB.mean(), 2) + FB.var() * pow(GFT.mean(), 2) / pow(FB.mean(), 4)) / T));
	
	// Uniform distribution
	IR.init(); GFT.init(); FB.init();
	for (int t = 1; t <= T; t++) {
		double sb = 0, ss = 0;
		for (int i = 1; i <= n; i++) {
			sb += Uniform(Eb);
			ss += Uniform(Es);
		}
		IR.add(sb >= price * n && ss <= price * n);
		GFT.add(sb - ss);
		FB.add(max(0.0, sb - ss));
	}
	printf("Uniform  : IR: %.6lf ± %.6lf, Efficiency: %.6lf ± %.6lf\n", IR.mean(), sqrt(IR.var() / T), GFT.mean() / FB.mean(), sqrt((GFT.var() / pow(FB.mean(), 2) + FB.var() * pow(GFT.mean(), 2) / pow(FB.mean(), 4)) / T));

	// Bernoulli distribution
	IR.init(); GFT.init(); FB.init();
	for (int t = 1; t <= T; t++) {
		double sb = 0, ss = 0;
		for (int i = 1; i <= n; i++) {
			sb += Bernoulli(Eb);
			ss += Bernoulli(Es);
		}
		IR.add(sb >= price * n && ss <= price * n);
		GFT.add(sb - ss);
		FB.add(max(0.0, sb - ss));
	}
	printf("Bernoulli: IR: %.6lf ± %.6lf, Efficiency: %.6lf ± %.6lf\n", IR.mean(), sqrt(IR.var() / T), GFT.mean() / FB.mean(), sqrt((GFT.var() / pow(FB.mean(), 2) + FB.var() * pow(GFT.mean(), 2) / pow(FB.mean(), 4)) / T));

	// Mixed distribution
	IR.init(); GFT.init(); FB.init();
	for (int t = 1; t <= T; t++) {
		double sb = 0, ss = 0;
		for (int i = 1; i <= n; i++) {
			sb += Mixed(Eb);
			ss += Mixed(Es);
		}
		IR.add(sb >= price * n && ss <= price * n);
		GFT.add(sb - ss);
		FB.add(max(0.0, sb - ss));
	}
	printf("Mixed    : IR: %.6lf ± %.6lf, Efficiency: %.6lf ± %.6lf\n", IR.mean(), sqrt(IR.var() / T), GFT.mean() / FB.mean(), sqrt((GFT.var() / pow(FB.mean(), 2) + FB.var() * pow(GFT.mean(), 2) / pow(FB.mean(), 4)) / T));

	printf("\n");
}

int main() {
	gen.seed(0);
	for (int i = 0; i <= 2; i++)
	for (int j = 0; j <= 2; j++)
		work(n[i], Eb[j], Es[j]);
	return 0;
}