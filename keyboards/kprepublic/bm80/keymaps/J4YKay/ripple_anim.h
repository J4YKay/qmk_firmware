#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED
#    if !defined(DISABLE_RGB_MATRIX_RIPPLE)

#        ifndef DISABLE_RGB_MATRIX_RIPPLE
RGB_MATRIX_EFFECT(RIPPLE)
#        endif

#        ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

HSV RIPPLE_math(HSV hsv, int16_t dx, int16_t dy, uint8_t dist, uint16_t tick) {
    uint16_t effect = tick - dist;
    if (effect > 255) effect = 255;
    hsv.h += effect;
    hsv.v = qadd8(hsv.v, 255 - effect);
    return hsv;
}

#            ifndef DISABLE_RGB_MATRIX_RIPPLE
bool RIPPLE(effect_params_t* params) { return effect_runner_reactive_ripple(0, params, &RIPPLE_math); }
#            endif

#        endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#    endif      // !defined(DISABLE_RGB_MATRIX_RIPPLE)
#endif          // RGB_MATRIX_KEYREACTIVE_ENABLED
