/*
 * File:   main.c
 * Author: wei
 *
 * Created on 2018年11月1日, 下午 3:21
 */
#include <stdio.h>
#include <stdlib.h>

#include <xc.h>
extern unsigned int mul(unsigned int a,unsigned int b);
void main(void) {
    int m;
    m=mul(240,255);
    return;
}