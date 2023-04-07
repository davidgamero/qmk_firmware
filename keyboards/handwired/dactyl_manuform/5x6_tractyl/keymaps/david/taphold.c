// Tap Dance Key Codes
enum {
    COMMA_MIN = 0,
    E_ESC = 1,
    M_BSPC = 2,
    LBRC_ESC = 3,
};

// Tap Dance Functions
enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
};

typedef struct {
  bool is_press_action;
  int state;
} tap;

int cur_dance (qk_tap_dance_state_t *state);
int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed)  return SINGLE_TAP;
    //key has not been interrupted, but they key is still held. Means you want to send a 'HOLD'.
    else return SINGLE_HOLD;
  }
  else return 8;
}


// Tap Dance for KC_COMMA
static tap KC_COMMA_tap_state = {
  .is_press_action = true,
  .state = 0
};
void KC_COMMA_finished (qk_tap_dance_state_t *state, void *user_data) {
  KC_COMMA_tap_state.state = cur_dance(state);
  switch (KC_COMMA_tap_state.state) {
    case SINGLE_TAP: register_code(KC_COMMA); break;
    case SINGLE_HOLD: register_code(KC_MINUS); break;
  }
}

void KC_COMMA_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (KC_COMMA_tap_state.state) {
    case SINGLE_TAP: unregister_code(KC_COMMA); break;
    case SINGLE_HOLD: unregister_code(KC_MINUS); break;
  }
  KC_COMMA_tap_state.state = 0;
}
// Tap Dance for KC_E
static tap KC_E_tap_state = {
  .is_press_action = true,
  .state = 0
};
void KC_E_finished (qk_tap_dance_state_t *state, void *user_data) {
  KC_E_tap_state.state = cur_dance(state);
  switch (KC_E_tap_state.state) {
    case SINGLE_TAP: register_code(KC_E); break;
    case SINGLE_HOLD: register_code(KC_ESC); break;
  }
}

void KC_E_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (KC_E_tap_state.state) {
    case SINGLE_TAP: unregister_code(KC_E); break;
    case SINGLE_HOLD: unregister_code(KC_ESC); break;
  }
  KC_E_tap_state.state = 0;
}
// Tap Dance for KC_M
static tap KC_M_tap_state = {
  .is_press_action = true,
  .state = 0
};
void KC_M_finished (qk_tap_dance_state_t *state, void *user_data) {
  KC_M_tap_state.state = cur_dance(state);
  switch (KC_M_tap_state.state) {
    case SINGLE_TAP: register_code(KC_M); break;
    case SINGLE_HOLD: register_code(KC_BSPC); break;
  }
}

void KC_M_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (KC_M_tap_state.state) {
    case SINGLE_TAP: unregister_code(KC_M); break;
    case SINGLE_HOLD: unregister_code(KC_BSPC); break;
  }
  KC_M_tap_state.state = 0;
}
// Tap Dance for KC_LBRC
static tap KC_LBRC_tap_state = {
  .is_press_action = true,
  .state = 0
};
void KC_LBRC_finished (qk_tap_dance_state_t *state, void *user_data) {
  KC_LBRC_tap_state.state = cur_dance(state);
  switch (KC_LBRC_tap_state.state) {
    case SINGLE_TAP: register_code(KC_LBRC); break;
    case SINGLE_HOLD: register_code(KC_ESC); break;
  }
}

void KC_LBRC_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (KC_LBRC_tap_state.state) {
    case SINGLE_TAP: unregister_code(KC_LBRC); break;
    case SINGLE_HOLD: unregister_code(KC_ESC); break;
  }
  KC_LBRC_tap_state.state = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [COMMA_MIN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,KC_COMMA_finished, KC_COMMA_reset),
  [E_ESC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,KC_E_finished, KC_E_reset),
  [M_BSPC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,KC_M_finished, KC_M_reset),
  [LBRC_ESC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,KC_LBRC_finished, KC_LBRC_reset),
};


