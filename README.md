# 自动行驶小车
# Driving-trolleys

2024年电赛H题

本系统基于CCS平台，采用MSPM0G3507作为主控芯片，角度传感器用来保证小车的行进方向，七路灰度循迹模块用来进行弯道循迹处理。同时系统采用串级pid算法，将速度环，角度环，循迹环进行串联，通过反馈能精确的控制小车行驶速度，方向以及循迹，完成了题目要求的路线指标、时间指标。

The system is based on the CCS platform, using the MSPM0G3507 as the main control chip, the angle sensor is used to ensure the direction of travel of the trolley, and the seven-way gray tracking module is used to follow the curve. At the same time, the system adopts the cascade PID algorithm to connect the speed ring, angle ring and tracking ring in series, and can accurately control the speed, direction and tracking of the car through feedback, and complete the route index and time index required by the problem.
