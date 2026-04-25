#include <stdio.h>

#define THRESHOLD_1  200
#define THRESHOLD_2  400
#define THRESHOLD_3  600

void stage1_alert();
void stage2_alert();
void stage3_alert();
void reset_system();

int main() {

    int blink_timer = 0;
    int stage = 0;
    int eye_state = 0;

    printf("Alert Driver System Started...\n\n");

    while (1) {

        eye_state = 0;

        if (eye_state == 1) {
            blink_timer = 0;
            stage = 0;
            reset_system();
        }

        else {
            blink_timer = blink_timer + 1;

            printf("Eyes closed... Timer = %d\n", blink_timer);

            if (blink_timer > THRESHOLD_1 && stage < 1) {
                stage = 1;
                stage1_alert();
            }

            else if (blink_timer > THRESHOLD_2 && stage < 2) {
                stage = 2;
                stage2_alert();
            }

            else if (blink_timer > THRESHOLD_3 && stage < 3) {
                stage = 3;
                stage3_alert();
            }
        }
    }

    return 0;
}

void stage1_alert() {
    printf("\n--- STAGE 1 ---\n");
    printf("Buzzer ON  (soft beep)\n");
    printf("Buzzer OFF\n");
    printf("---------------\n\n");
}

void stage2_alert() {
    int i = 0;

    printf("\n--- STAGE 2 ---\n");

    while (i < 3) {
        printf("Buzzer ON  (strong beep %d)\n", i + 1);
        printf("Buzzer OFF\n");
        i = i + 1;
    }

    printf("---------------\n\n");
}

void stage3_alert() {
    printf("\n--- STAGE 3 EMERGENCY ---\n");
    printf("Buzzer ON  (loud alarm)\n");
    printf("Relay  ON  (car slowing down)\n");
    printf("Water Pump ON  (spraying water)\n");
    printf("Water Pump OFF (after 2 seconds)\n");
    printf("Car Stopped.\n");
    printf("-------------------------\n\n");
}

void reset_system() {
    printf("Driver is AWAKE. All systems OFF.\n\n");
}