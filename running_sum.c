/*
 * running_sum.c
 *
 *  Created on: Jun 5, 2024
 *      Author: zaccko
 */


void calc_running_sum(double *sig_src_arr, double *sig_dest_arr, int sig_len){
	for(int i = 0; i < sig_len; i++){
		sig_dest_arr[i] = sig_dest_arr[i - 1] + sig_src_arr[i];
	}
}
