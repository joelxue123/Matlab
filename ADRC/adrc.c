#include <math.h>

/* ADRC参数 */
#define WO 50.0     /* 观测器带宽 */
#define B0 1.0      /* 控制增益 */
#define KP 100.0    /* PD控制器P参数 */
#define KD 20.0     /* PD控制器D参数 */
#define BETA1 (2.0*WO)
#define BETA2 (WO*WO)
#define BETA3 (WO*WO*WO/9.0)

/* ESO状态变量 */
static double z1 = 0.0, z2 = 0.0, z3 = 0.0;

/* 控制输入 */
static double u = 0.0;

/* 系统输出 */
static double y = 0.0;

/* 被控对象模型 */
static void plant_model(double u, double *y)
{
    static double x1 = 0.0, x2 = 0.0;
    double x1_dot, x2_dot;

    x1_dot = x2;
    x2_dot = u - 2.0*x2 - x1;

    x1 += 0.001*x1_dot;
    x2 += 0.001*x2_dot;

    *y = x1;
}

/* 三阶线性ESO */
void eso_update(double r, double y_m)
{
    double z1_dot, z2_dot, z3_dot;

    z1_dot = z2 - BETA1*(z1 - y_m);
    z2_dot = z3 - BETA2*(z1 - y_m) + B0*u;
    z3_dot = -BETA3*(z1 - y_m);

    z1 += 0.001*z1_dot;
    z2 += 0.001*z2_dot;
    z3 += 0.001*z3_dot;
}

/* PD控制律 */
double pd_control(double r, double z1, double z2)
{
    double u0, e;

    e = r - z1;
    u0 = KP*e - KD*z2;

    return u0;
}

/* 控制律 */
double adrc_control(double r, double z1, double z2, double z3)
{
    double u0, u;

    u0 = pd_control(r, z1, z2);
    u = (-z3 + u0)/B0;

    return u;
}

/* 主循环 */
int main()
{
    double r = 1.0; /* 期望轨迹 */
    double t;

    for (t = 0.0; t < 1.0; t += 0.001) {
        plant_model(u, &y);
        eso_update(r, y);
        u = adrc_control(r, z1, z2, z3);
        /* 可在此处添加其他代码 */
    }

    return 0;
}
