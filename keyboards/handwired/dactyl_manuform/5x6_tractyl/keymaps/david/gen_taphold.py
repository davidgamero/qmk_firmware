import chevron

keys = {
    "tapholds": [
        {
            "keycode":"COMMA_MIN",
            "tap": "KC_COMMA",
            "hold": "KC_MINUS",
        },
        {
            "keycode":"E_ESC",
            "tap": "KC_E",
            "hold": "KC_ESC",
        },
        {
            "keycode":"M_BSPC",
            "tap": "KC_M",
            "hold": "KC_BSPC",
        },
        {
            "keycode":"LBRC_ESC",
            "tap": "KC_LBRC",
            "hold": "KC_ESC",
        }
    ]
}

def add_index(tapholdi):
    index,taphold = tapholdi
    taphold["index"] = index;

tapholds_with_indexes = list(map(add_index,enumerate(keys["tapholds"])))

def add_index(tapholdi):
    index,taphold = tapholdi
    taphold["index"] = index;
    return taphold

tapholds_with_indexes = list(map(add_index,enumerate(keys["tapholds"])))

print(keys)
with open('taphold.mustache', 'r') as f:
    rendered = chevron.render(f, keys)
    with open('taphold.c', 'w') as g:
        g.write(rendered)
