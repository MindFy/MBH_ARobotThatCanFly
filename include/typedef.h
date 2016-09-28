/*
 * typedef.h
 *
 *  Created on: Mar 4, 2016
 *
 *  四轴飞行控制器  Copyright (C) 2016  李德强
 */

#ifndef _INCLUDE_TYPEDEF_H_
#define _INCLUDE_TYPEDEF_H_

#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <semaphore.h>
#include <dlfcn.h>
#include <dirent.h>

#include <wiringPi.h>
#include <wiringSerial.h>

typedef char s8;
typedef unsigned char u8;

typedef signed short s16;
typedef unsigned short u16;

typedef signed int s32;
typedef unsigned int u32;

typedef signed long long s64;
typedef unsigned long long u64;

//保护最低速度
#define PROCTED_SPEED	(50)

//引擎结构
typedef struct
{
	//电机锁定状态，默认为锁定
	int lock;

	//XYZ欧拉角
	float x;
	float y;
	float z;
	//修正补偿
	float dx;
	float dy;
	float dz;
	//渐进式移动倾斜角
	float mx;
	float my;
	//摇控器移动倾角
	float ctlmx;
	float ctlmy;
	//XYZ轴旋转角速度
	float gx;
	float gy;
	float gz;
	//补偿XYZ轴旋转角速度
	float dgx;
	float dgy;
	float dgz;
	//XYZ轴加速度
	float ax;
	float ay;
	float az;
	//修正加速度补偿
	float dax;
	float day;
	float daz;
	//引擎速度
	float v;
	//速度补偿
	float v_devi[4];
	//电机实际速度
	int speed[4];

	//其它参数
	//显示摇控器读数
	int ctl_fb;
	int ctl_lr;
	int ctl_pw;
	//最低油门,最左，最右
	u32 lock_status;

} s_engine;

//参数
typedef struct
{
	//XY轴欧拉角PID参数
	float kp;
	float ki;
	float kd;
	//旋转角速度PID参数
	float kp_v;
	float ki_v;
	float kd_v;
	//Z轴欧拉角PID参数
	float kp_z;
	float ki_z;
	float kd_z;
	//Z旋转角速度PID参数
	float kp_zv;
	float ki_zv;
	float kd_zv;
	//XY轴加速度PID参数
	float kp_a;
	float ki_a;
	float kd_a;
	//中心校准补偿
	float cx;
	float cy;
	//摇控器3通道起始读数
	int ctl_fb_zero;
	int ctl_lr_zero;
	int ctl_pw_zero;

	int ctl_type;
} s_params;

#endif /* INCLUDE_TYPEDEF_H_ */
