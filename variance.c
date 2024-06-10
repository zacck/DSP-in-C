/*
 * deviation.c
 *
 *  Created on: Jun 4, 2024
 *      Author: zaccko
 */
#include <math.h>

#define SIG_LENGTH 320



extern double InputSignal_f32_1kHz_15kHz[SIG_LENGTH];

double calc_signal_variance(double * sig_src_arr, double sig_mu, int sig_len){
	double _variance = 0.0;

	for(int i = 0; i < sig_len; i++){
		_variance = _variance + pow((sig_src_arr[i] - sig_mu), 2);
	}

	_variance = _variance / (sig_len - 1);

	return _variance;
}



