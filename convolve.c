/*
 * convolve.c
 *
 *  Created on: Jun 5, 2024
 *      Author: zaccko
 */



void convolution(double *sig_src_arr,
		double *sig_dest_arr,
		double *imp_resp_arr,
		int sig_source_len,
		int imp_resp_len){

	int i = 0;
	int j = 0;

	for (i = 0; i < (sig_source_len + imp_resp_len); i++){
		sig_dest_arr[i] = 0;
	}

	for(i = 0; i < sig_source_len; i++){
		for(j = 0; j < imp_resp_len; j++){
			sig_dest_arr[i+j] = sig_dest_arr[i+j] + (sig_src_arr[i] * imp_resp_arr[j]);
		}
	}

}
