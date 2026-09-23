RGB_MATRIX_EFFECT(CHEVRON_BREATHE)
RGB_MATRIX_EFFECT(CHEVRON_BREATHE_DIM)
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static hsv_t CHEVRON_BREATHE_math(hsv_t hsv, uint8_t i, uint8_t time) {
    uint8_t wave = abs8(g_led_config.point[i].y - k_rgb_matrix_center.y)
                 + (g_led_config.point[i].x - time);
    hsv.v = scale8(hsv.v, 128 + sin8(wave) / 2);
    return hsv;
}

bool CHEVRON_BREATHE(effect_params_t* params) {
    return effect_runner_i(params, &CHEVRON_BREATHE_math);
}

static hsv_t CHEVRON_BREATHE_DIM_math(hsv_t hsv, uint8_t i, uint8_t time) {
    uint8_t wave = abs8(g_led_config.point[i].y - k_rgb_matrix_center.y)
                 + (g_led_config.point[i].x - time);
    hsv.v = scale8(hsv.v, sin8(wave) / 2);
    return hsv;
}

bool CHEVRON_BREATHE_DIM(effect_params_t* params) {
    return effect_runner_i(params, &CHEVRON_BREATHE_DIM_math);
}

#endif
