/*
 * Utils.h
 *
 *  Created on: Oct 23, 2019
 *      Author: ali zewail
 */

#ifndef UTILS_H_
#define UTILS_H_


#define SET_BIT(x,b) (x |= (1<<b))
#define TOG_BIT(x,b) (x^= (1<<b))
#define CLR_BIT(x,b) (x&= ~(1<<b))
#define GET_BIT(x,b) ((x & (1<<b))>>b)







#endif /* UTILS_H_ */
