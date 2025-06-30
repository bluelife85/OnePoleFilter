/**
 * @file OnePoleFilter.c
 * @author bluelife85 (bluelife85@naver.com)
 * @brief 1-Pole Noise filter
 */
#include "OnePoleFilter.h"

bool OPF_Initialize(struct OnePoleFilter *obj, int32_t numerator, int32_t denominator)
{
    int32_t denom;

    denom = 1 << denominator;
    if(numerator > denom)
        return false;
    obj->previous = 0;
    obj->numerator = numerator;
    obj->denominator = denominator;
    return true;
}

int32_t OPF_Filterout(struct OnePoleFilter *obj, int32_t newData)
{
    int32_t ratio1, ratio2;
    int32_t ret;

    ratio1 = obj->numerator;
    ratio2 = (int32_t) ((1 << obj->denominator) - ratio1);

    ret = ((obj->previous * ratio1) >> obj->denominator)
             + ((newData * ratio2) >> obj->denominator);
    obj->previous = ret;
    return ret;
}
