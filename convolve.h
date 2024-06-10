/*
 * convolve.h
 *
 *  Created on: Jun 5, 2024
 *      Author: zaccko
 */

#ifndef CONVOLVE_H_
#define CONVOLVE_H_

void convolution(double *sig_src_arr,
		double *sig_dest_arr,
		double *imp_resp_arr,
		int sig_source_len,
		int imp_resp_len);

#endif /* CONVOLVE_H_ */
