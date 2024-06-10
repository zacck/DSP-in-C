/*
 * main.c
 *
 *  Created on: Jun 4, 2024
 *      Author: zaccko
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#include "mean.h"
#include "variance.h"
#include "convolve.h"
#include "running_sum.h"

#define SIG_LENGTH 320
#define IMP_RSP_LENGTH 29

extern double InputSignal_f32_1kHz_15kHz[SIG_LENGTH];
extern double Impulse_response[IMP_RSP_LENGTH];
double MEAN;
double DEVIATION;
double VARIANCE;
double calc_standard_deviation(double sig_variance);


int main(){
	MEAN = calc_signal_mean(&InputSignal_f32_1kHz_15kHz[0], SIG_LENGTH);
	VARIANCE = calc_signal_variance(&InputSignal_f32_1kHz_15kHz[0], MEAN, SIG_LENGTH);
	DEVIATION = calc_standard_deviation(VARIANCE);
	double output_arr[SIG_LENGTH + IMP_RSP_LENGTH];
	double running_arr[SIG_LENGTH];

	FILE *input_sig_fptr, *imp_rsp_fptr, *output_sig_fptr, *running_sum_fptr;

	input_sig_fptr = fopen("input_signal.dat", "w");
	imp_rsp_fptr = fopen("impulse_response.dat", "w");
	output_sig_fptr = fopen("output_signal.dat", "w");
	running_sum_fptr = fopen("running_signal.dat", "w");

	for (int i = 0; i < SIG_LENGTH; i++) {
		fprintf(input_sig_fptr, "\n%f", InputSignal_f32_1kHz_15kHz[i]);
		output_arr[i] = 0;
		running_arr[i]= 0;
	}
	fclose(input_sig_fptr);

	for (int i = 0; i < IMP_RSP_LENGTH; i++) {
		fprintf(imp_rsp_fptr, "\n%f", Impulse_response[i]);
	}

	fclose(imp_rsp_fptr);

	convolution(&InputSignal_f32_1kHz_15kHz[0], &output_arr[0], &Impulse_response[0], SIG_LENGTH, IMP_RSP_LENGTH);

	for (int i = 0; i < SIG_LENGTH + IMP_RSP_LENGTH ; i++) {
		fprintf(output_sig_fptr, "\n%f", output_arr[i]);
	}
	fclose(output_sig_fptr);

	calc_running_sum(&InputSignal_f32_1kHz_15kHz[0], &running_arr[0], SIG_LENGTH);

	for (int i = 0; i < SIG_LENGTH; i++) {
		fprintf(running_sum_fptr, "\n%f", running_arr[i]);
	}
	fclose(running_sum_fptr);
	printf("Signal Mean: %f\n", MEAN);
	printf("Signal Deviation: %f\n", DEVIATION);
	printf("Signal Variance: %f\n", VARIANCE);
	return 0;
}


double calc_standard_deviation(double sig_variance){
	double _std = sqrt(sig_variance);

	return _std;
}



