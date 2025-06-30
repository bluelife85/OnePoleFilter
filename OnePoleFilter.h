/**
 * @file OnePoleFilter.h
 * @author bluelife85 (bluelife85@naver.com)
 * @brief 1-Pole Noise filter
 *
 * This module implements a simple first-order IIR (Infinite Impulse Response) low-pass filter,
 * commonly known as a 1-pole noise filter. It is designed to reduce high-frequency noise in
 * digital signal processing with a lightweight implementation.
 */
#ifndef __ONE_POLE_NOISE_FILTER_H__
#define __ONE_POLE_NOISE_FILTER_H__

#include <stdint.h>
#if !defined(__STDC_VERSION__) || (__STDC_VERSION__ < 202311L)
#include <stdbool.h>
#endif /* __STDC_VERSION__ */
/**
 * @struct OnePoleFilter
 * @brief Holds internal parameters and state for the one-pole filter.
 *
 * This structure maintains the state required for the filtering process.
 * All values are represented in fixed-point format using integer arithmetic.
 *
 * - `previous` stores the last output value from the filter.
 * - `numerator` is the weight for the previous output in the filter equation.
 * - `denominator` defines the bit-shift divisor (e.g., `1 << denominator`) for scaling.
 */
struct OnePoleFilter
{
    int32_t previous;
    int32_t numerator;
    int32_t denominator;
};

/**
 * @brief Initializes the one-pole filter.
 *
 * This function sets up the filter coefficients and resets the filter state.
 * The numerator must be less than or equal to 2^denominator.
 *
 * @param obj Pointer to the filter instance.
 * @param numerator Coefficient for the previous value.
 * @param denominator Bit shift for scaling (acts as divisor).
 * @retval true Initialization succeeded.
 * @retval false Numerator is out of valid range.
 */
bool OPF_Initialize(struct OnePoleFilter* obj, int32_t numerator, int32_t denominator);
/**
 * @brief Applies the one-pole filter to a new input.
 *
 * Computes the filtered output using:
 * \f[
 * y[n] = \frac{previous \cdot numerator + newData \cdot (2^{denominator} - numerator)}{2^{denominator}}
 * \f]
 * This performs a weighted average between the previous output and new input.
 *
 * @param obj Pointer to the filter instance.
 * @param newData The new input sample.
 * @return The filtered output value.
 */
int32_t OPF_Filterout(struct OnePoleFilter* obj, int32_t newData);
/**
 * @brief Resets the internal state of the filter.
 *
 * This function clears the previous output value, effectively restarting the filter.
 *
 * @param obj Pointer to the filter instance.
 */
static inline void OPF_Reset(struct OnePoleFilter* obj)
{
    obj->previous = 0u;
}

#endif /* __ONE_POLE_NOISE_FILTER_H__ */
