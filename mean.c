/*
 * mean.c
 *
 *  Created on: Jun 4, 2024
 *      Author: zaccko
 */


double calc_signal_mean(double *sig_src_arr, int sig_len){
	double _mean = 0.0;
	for(int i = 0; i < sig_len; i++) {
		_mean = _mean + sig_src_arr[i];
	}

	_mean = _mean/(double)sig_len;
	return _mean;
}
