#ifndef KBRO_IR_CODES_H
#define KBRO_IR_CODES_H

// Define macros for button IDs
#define KBRO_POWER 0
#define KBRO_NUM_1 1
#define KBRO_NUM_2 2
#define KBRO_NUM_3 3
#define KBRO_NUM_4 4
#define KBRO_NUM_5 5
#define KBRO_NUM_6 6
#define KBRO_NUM_7 7
#define KBRO_NUM_8 8
#define KBRO_NUM_9 9
#define KBRO_BILINGUAL 10
#define KBRO_NUM_0 11
#define KBRO_RETURN 12
#define KBRO_INFO 13
#define KBRO_UP 14
#define KBRO_EPG 15
#define KBRO_LEFT 16
#define KBRO_OK 17
#define KBRO_RIGHT 18
#define KBRO_EXIT 19
#define KBRO_DOWN 20
#define KBRO_BACK 21
#define KBRO_VOL_UP 22
#define KBRO_CH_UP 23
#define KBRO_VOL_DOWN 24
#define KBRO_CH_DOWN 25
#define KBRO_MUTE 26
#define KBRO_REC 27
#define KBRO_MOD 28
#define KBRO_STOP 29
#define KBRO_REWIND 30
#define KBRO_PLAY 31
#define KBRO_FAST_FORWARD 32
#define KBRO_PREVIOUS 33
#define KBRO_PAUSE 34
#define KBRO_NEXT 35
#define KBRO_RED 36
#define KBRO_GREEN 37
#define KBRO_YELLOW 38
#define KBRO_BLUE 39

// Array holding the IR data for each button
const uint64_t kbro_ir_codes[] = {
    0x1B0F445810000F00  /* KBRO_POWER */,
    0x1B0F44581E000100  /* KBRO_NUM_1 */,       0x1B0F44581D000200  /* KBRO_NUM_2 */,        0x1B0F44581C000300  /* KBRO_NUM_3 */,
    0x1B0F44581B000400  /* KBRO_NUM_4 */,       0x1B0F44581A000500  /* KBRO_NUM_5 */,        0x1B0F445819000600  /* KBRO_NUM_6 */,
    0x1B0F445818000700  /* KBRO_NUM_7 */,       0x1B0F445817000800  /* KBRO_NUM_8 */,        0x1B0F445816000900  /* KBRO_NUM_9 */,
    0x1B0F44581A005000  /* KBRO_BILINGUAL */,   0x1B0F44581F000000  /* KBRO_NUM_0 */,        0x1B0F445814002900  /* KBRO_RETURN */,

    0x1B0F445813002A00  /* KBRO_INFO */,        0x1B0F44581C002100  /* KBRO_UP */,           0x1B0F445815002800  /* KBRO_EPG */,
    0x1B0F44581A002300  /* KBRO_LEFT */,        0x1B0F445818002500  /* KBRO_OK */,           0x1B0F445819002400  /* KBRO_RIGHT */,
    0x1B0F445817002600  /* KBRO_EXIT */,        0x1B0F44581B002200  /* KBRO_DOWN */,         0x1B0F445816002700  /* KBRO_BACK */,

    0x1B0F445815000A00  /* KBRO_VOL_UP */,                                                   0x1B0F445812000D00  /* KBRO_CH_UP */,
    0x1B0F445814000B00  /* KBRO_VOL_DOWN */,                                                 0x1B0F445811000E00  /* KBRO_CH_DOWN */,

    0x1B0F445813000C00  /* KBRO_MUTE */,

    0x1B0F445815003700  /* KBRO_REC */,          0x1B0F445816005400  /* KBRO_MOD */,         0x1B0F445816003600  /* KBRO_STOP */,
    0x1B0F44581A003200  /* KBRO_REWIND */,       0x1B0F44581C003000  /* KBRO_PLAY */,        0x1B0F445819003300  /* KBRO_FAST_FORWARD */,
    0x1B0F445818003400  /* KBRO_PREVIOUS */,     0x1B0F44581B003100  /* KBRO_PAUSE */,       0x1B0F445817003500  /* KBRO_NEXT */,

    0x1B0F44581B004000  /* KBRO_RED */,          0x1B0F44581A004100  /* KBRO_GREEN */,       0x1B0F445819004200  /* KBRO_YELLOW */,
    0x1B0F445818004300   /* KBRO_BLUE */
};


// HTML for the webpage
const char kbro_html_page[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Remote Control Web Interface</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            background-color: #f4f4f4;
            display: flex;
            justify-content: center;
            align-items: center;
            min-height: 120vh;
            margin: 0;
        }

        .remote-control {
            background-color: #333;
            padding: 20px;
            border-radius: 10px;
            display: grid;
            grid-template-columns: repeat(3, 70px);
            gap: 10px;
            color: #fff;
        }

        .spacer {
            height: 1px;
            /* Adjust the height as needed */
            grid-column: span 3;
        }

        .button {
            background-color: #555;
            padding: 15px;
            text-align: center;
            border-radius: 5px;
            cursor: pointer;
            user-select: none;
        }

        .button:hover {
            background-color: #777;
        }

        .color-button {
            gap: 10px;
            display: grid;
            grid-template-columns: repeat(4, 50px);
        }

        .large-button {
            grid-column: span 3;
        }
    </style>
</head>

<body>

    <div class="remote-control">
        <!-- Top Row -->
        <!-- <div class="button" style="background-color: white; color: black;">Power</div>
        <div></div> -->
        <!-- Empty space -->
        <div class="button large-button" data-id="0" style="background-color: red;">Power</div>

        <!-- Numeric Keypad and Function Keys -->
        <div class="button" data-id="1">1</div>
        <div class="button" data-id="2">2</div>
        <div class="button" data-id="3">3</div>
        <div class="button" data-id="4">4</div>
        <div class="button" data-id="5">5</div>
        <div class="button" data-id="6">6</div>
        <div class="button" data-id="7">7</div>
        <div class="button" data-id="8">8</div>
        <div class="button" data-id="9">9</div>
        <div class="button" data-id="10">雙語</div>
        <div class="button" data-id="11">0</div>
        <div class="button" data-id="12">往返</div>

        <div class="spacer"></div>

        <!-- Function Buttons Around OK -->
        <div class="button" data-id="13">i</div>
        <div class="button" data-id="14">⏶︎</div>
        <div class="button" data-id="15">EPG</div>
        <div class="button" data-id="16">⏴︎</div>
        <div class="button" data-id="17">OK</div>
        <div class="button" data-id="18">⏵︎</div>
        <div class="button" data-id="19">EXIT</div>
        <div class="button" data-id="20">⏷︎</div>
        <div class="button" data-id="21">←</div>

        <div class="spacer"></div>

        <!-- Directional and OK Buttons -->
        <div class="button" data-id="22">Vol +</div>
        <div></div>
        <div class="button" data-id="23">Ch +</div>
        <div class="button" data-id="24">Vol -</div>
        <div></div>
        <div class="button" data-id="25">Ch -</div>

        <div class="spacer"></div>

        <!-- Volume and Channel Controls -->
        <div class="button large-button" data-id="26">Mute</div>

        <div class="spacer"></div>

        <!-- Media Control Buttons -->
        <div class="button" data-id="27">⏺︎</div>
        <div class="button" data-id="28">MOD</div>
        <div class="button" data-id="29">⏹︎</div>
        <div class="button" data-id="30">⏪</div>
        <div class="button" data-id="31">▶</div>
        <div class="button" data-id="32">⏩</div>
        <div class="button" data-id="33">⏮︎</div>
        <div class="button" data-id="34">⏸︎</div>
        <div class="button" data-id="35">⏭︎</div>

        <div class="spacer"></div>

        <!-- Color Buttons -->
        <div class="color-button">
            <div class="button" data-id="36" style="background-color: red;"></div>
            <div class="button" data-id="37" style="background-color: green;"></div>
            <div class="button" data-id="38" style="background-color: yellow;"></div>
            <div class="button" data-id="39" style="background-color: blue;"></div>
        </div>

        <script>
            // Add event listeners to all buttons
            document.querySelectorAll('.button').forEach(function(button) {
                button.addEventListener('click', function() {
                    var buttonId = this.getAttribute('data-id');
                    sendButtonPress(buttonId);
                });
            });

            // Function to send button press via AJAX
            function sendButtonPress(buttonId) {
                var xhr = new XMLHttpRequest();
                xhr.open("GET", "/press?button=" + buttonId, true);
                xhr.send();
            }
        </script>
    </div>

</body>

</html>
)rawliteral";

#endif // KBRO_IR_CODES_H
